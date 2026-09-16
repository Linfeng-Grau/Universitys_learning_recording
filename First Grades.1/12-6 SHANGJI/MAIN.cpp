#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <limits>
using namespace std;

const int SIZE = 18;  //工资项的数量为18

struct TechInfo 
{
    int id;
    string num;
    string name;
    string title;
    int workage;
    double dSalary[SIZE];
    double dTax;
    double lastSalary;
};

static int count = 0;

void inputSalaryInfo(TechInfo& info) 
{
    cout << "请输入序号 " << ++::count << "的职工信息:";
    cout << "\n工号:";
    cin >> info.num;
    cout << "姓名:";
    cin >> info.name;
    cout << "职称:";
    cin >> info.title;
    cout << "工龄:";
    cin >> info.workage;
    cout << "请输入以下工资项(共" << SIZE << "项,依次为[0]岗位工资、[1]薪级工资、[2]岗位津贴、[3]生活补贴、[4]奖励绩效、[5]公积金贴、[6]逐月房贴、[7]交通贴、[8]总应发、[9]应缴公积金、[10]失业险、[11]养老险、[12]职业年金、[13]医疗险、[14]工会费、[15]医互金)、[16]个调税、[17]实发工资:\n";
    for (int i = 0; i < SIZE; ++i) 
    {
        cout << "第[" << i << "]工资项:";
        cin >> info.dSalary[i];
    }
}

//计算第n年的应发工资(递归函数)
double calculateSalaryNthYear(const TechInfo& info, int n) 
{
    if (n == 1) return info.lastSalary;
    return info.dSalary[0] * pow(1 + info.dSalary[1] / 100, n - 1);
}

// 补发上浮工资
void BUFA(TechInfo& info, int nMonths) 
{
    double SFGZ = 0;
    if (info.title == "教授") 
    {
        SFGZ = 2500 * nMonths;
    } 
    else if (info.title == "副教授") 
    {
        SFGZ = 2000 * nMonths;
    } 
    else if (info.title == "讲师") 
    {
        SFGZ = 1500 * nMonths;
    } 
    else if (info.title == "初级") 
    {
        SFGZ = 1000 * nMonths;
    }
    info.lastSalary += SFGZ;
}

// 计算并显示最大值、最小值、平均值
void calculateAndDisplayStats(const vector<TechInfo>& employees) 
{
    if (employees.empty()) 
    {
        cout << "没有员工数据。" ;
        return;
    }

    double maxSalary = 0, minSalary = numeric_limits<double>::max(), sumSalary = 0;
    string maxNum, minNum;

    for (const auto& employee : employees) 
    {
        if (employee.lastSalary > maxSalary) 
        {
            maxSalary = employee.lastSalary;
            maxNum = employee.num;
        }
        if (employee.lastSalary < minSalary) 
        {
            minSalary = employee.lastSalary;
            minNum = employee.num;
        }
        sumSalary += employee.lastSalary;
    }

    double averageSalary = sumSalary / employees.size();
    cout << "实发工资最大值: " << maxSalary << ", 工号: " << maxNum << "\n";
    cout << "实发工资最小值: " << minSalary << ", 工号: " << minNum << "\n";
    cout << "实发工资平均值: " << averageSalary << "\n";
}



// 统计实发工资低于平均值的人数
int countEmployeesBelowAverage(const vector<TechInfo>& employees, double averageSalary) 
{
    int count = 0;
    for (const auto& employee : employees) 
    {
        if (employee.lastSalary < averageSalary) 
        {
            count++;
        }
    }
    return count;
}

double calculateTax(double income) 
{
    if (income <= 3500) return 0;
    double tax = 0;
    if (income <= 5000) tax = (income - 3500) * 0.03;
    else if (income <= 8000) tax = 45 + (income - 5000) * 0.1;
    else if (income <= 17000) tax = 345 + (income - 8000) * 0.2;
    else if (income <= 30000) tax = 1005 + (income - 17000) * 0.25;
    else if (income <= 40000) tax = 2755 + (income - 30000) * 0.3;
    else if (income <= 60000) tax = 5505 + (income - 40000) * 0.35;
    else tax = 13505 + (income - 60000) * 0.45;
    return tax;
}

void calculateSalary(TechInfo& info) 
{
    double totalIncome = 0;
    for (int i = 0; i < SIZE; ++i) 
    {
        totalIncome += info.dSalary[i];
    }
    info.dTax = calculateTax(totalIncome);
    double totalDeductions = 0;
    for (int i = 9; i < SIZE; ++i) 
    {  
        totalDeductions += info.dSalary[i];
    }
    info.lastSalary = totalIncome - info.dTax - totalDeductions; 
}


void displaySalaryInfo(const TechInfo& info) 
{
    cout << "序号:" << info.id << "\n工号:" << info.num << "\n姓名:" << info.name
              << "\n职称:" << info.title << "\n工龄:" << info.workage << "年";
    cout << "\n岗位工资:" << info.dSalary[0] << "\n薪级工资:" << info.dSalary[1]
              << "\n岗位津贴:" << info.dSalary[2] << "\n生活补贴:" << info.dSalary[3];
    cout << "\n奖励绩效:" << info.dSalary[4] << "\n公积金贴:" << info.dSalary[5]
              << "\n逐月房贴:" << info.dSalary[6] << "\n交通贴:" << info.dSalary[7];
    cout << "\n总应发:" << info.dSalary[8] << "\n应缴公积金:" << info.dSalary[9]
              << "\n失业险:" << info.dSalary[10] << "\n养老险:" << info.dSalary[11];
    cout << "\n职业年金:" << info.dSalary[12] << "\n医疗险:" << info.dSalary[13]
              << "\n工会费:" << info.dSalary[14] << "\n医互金:" << info.dSalary[15];
    cout << "\n个调税:" << info.dTax << "\n实发工资:" << info.lastSalary;
}

double calculateAverageSalary(const vector<TechInfo>& employees) 
{
    double totalSalary = 0;
    for (const auto& employee : employees) 
    {
        totalSalary += employee.lastSalary;
    }
    return totalSalary / employees.size();
}

int main() 
{
    vector<TechInfo> employees;
    TechInfo info;
    int count = 0;

    while (1) 
    {
        inputSalaryInfo(info);
        calculateSalary(info);
        displaySalaryInfo(info);
        employees.push_back(info);

        char cont = 'n';
        cout << "\n是否继续输入?(y/n): ";
        cin >> cont;
        if (cont != 'y') break;
    }

    double averageSalary = calculateAverageSalary(employees);
    cout << "实发工资的平均值为:" << averageSalary <<"\n";

    int countBelowAverage = countEmployeesBelowAverage(employees, averageSalary);
    cout << "实发工资低于平均值的人数为:" << countBelowAverage <<"人\n";

    // 计算并显示最大值、最小值、平均值
    calculateAndDisplayStats(employees);

    // 补发上浮工资
    for (auto& emp : employees) 
    {
        if (emp.title == "教授") emp.lastSalary += 2500 * 12;  // 假设每年补发
        else if (emp.title == "副教授") emp.lastSalary += 2000 * 12;
        else if (emp.title == "讲师") emp.lastSalary += 1500 * 12;
        else if (emp.title == "初级") emp.lastSalary += 1000 * 12;
    }

    // 重新计算平均工资和低于平均的人数
    averageSalary = calculateAverageSalary(employees);
    countBelowAverage = countEmployeesBelowAverage(employees, averageSalary);
    cout << "补发上浮工资后实发工资平均值: " << averageSalary << "\n";
    cout << "补发上浮工资后实发工资低于平均值的人数: " << countBelowAverage << "\n";

    return 0;
}