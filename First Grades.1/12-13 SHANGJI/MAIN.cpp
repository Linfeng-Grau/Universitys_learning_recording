#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <cmath>
#include <iomanip>
#include <limits>
#include <algorithm>
using namespace std;

const int SIZE = 15;  //工资项为15

struct techinf
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

bool isValidTitle(const string& title) 
{
    vector<string> validTitles = {"教授", "副教授", "讲师", "助教"};
    return find(validTitles.begin(), validTitles.end(), title) != validTitles.end();
}

void inputSalaryInfo(techinf& info, int& count, const vector<techinf>& employees) {
    cout << "请输入第" << ++count << "个职工信息(工号,姓名,职称):";
    info.id = count;
    while (1) 
    {
        cin >> info.num;
        if (find_if(employees.begin(), employees.end(), [&info](const techinf& emp) { return emp.num == info.num; }) != employees.end()) {
            cout << "工号已存在，请重新输入工号: ";
        } 
        else 
        {
            break;
        }
    }
    cin >> info.name;
    while (1) 
    {
        cin >> info.title;
        if (isValidTitle(info.title)) 
        {
            break;
        } else 
        {
            cout << "职称输入错误，请输入有效的职称（教授、副教授、讲师、助教）: ";
        }
    }

    cout << "请输入职工的" << SIZE << "项工资明细:";
    int i = 0;
    while (i < SIZE) 
    {
        if (cin >> info.dSalary[i]) 
        {
            i++;
        } 
        else 
        {
            cout << "输入错误，请输入数字！";
            cin.clear();
            cin.ignore(1024, '\n');
        }
    }
}
//-------------------------------------------------------------------------------//
// 计算个人所得税
double calculateTax(double totalIncome)
{
    double tax = 0;
    if (totalIncome <= 36000)
    {
        tax = totalIncome * 0.03;
    }
    else if (totalIncome <= 144000)
    {
        tax = 36000 * 0.03 + (totalIncome - 36000) * 0.1;
    }
    else if (totalIncome <= 300000)
    {
        tax = 36000 * 0.03 + (144000 - 36000) * 0.1 + (totalIncome - 144000) * 0.2;
    }
    else
    {
        tax = 36000 * 0.03 + (144000 - 36000) * 0.1 + (300000 - 144000) * 0.2 + (totalIncome - 300000) * 0.25;
    }
    return tax;
}

//计算第n年的应发工资(递归函数)
double calculateSalaryNthYear(const techinf& info, int n)
{
    if (n == 1) return info.lastSalary;
    return info.dSalary[0] * pow(1 + info.dSalary[1] / 100, n - 1);
}


// 补发上浮工资
void BUFA(techinf& info, int nMonths)
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
void calculateAndDisplayStats(const vector<techinf>& employees)
{
    double totalSalary = 0;
    double maxSalary = employees[0].lastSalary;
    double minSalary = employees[0].lastSalary;
    for (const auto& employee : employees)
    {
        totalSalary += employee.lastSalary;
        if (employee.lastSalary > maxSalary) maxSalary = employee.lastSalary;
        if (employee.lastSalary < minSalary) minSalary = employee.lastSalary;
    }
    double averageSalary = totalSalary / employees.size();
    cout << "最大值:" << maxSalary << "\n最小值:" << minSalary << "\n平均值:" << averageSalary;
}

void calculateSalary(techinf& info)
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

void displaySalaryInfo(const techinf& info)
{
    cout << "序号:" << info.id << "\n工号:" << info.num << "\n姓名:" << info.name
               << "\n职称:" << info.title << "\n工龄:" << info.workage << "年";
    cout << "\n岗位工资:" << info.dSalary[0] << "\n薪级工资:" << info.dSalary[1]
               << "\n岗位津贴:" << info.dSalary[2] << "\n生活补贴:" << info.dSalary[3];
    cout << "\n奖励绩效:" << info.dSalary[4] << "\n公积金贴:" << info.dSalary[5]
               << "\n逐月房贴:" << info.dSalary[6] << "\n交通贴:" << info.dSalary[7];
    cout << "\n总应发:" << info.dSalary[8] << "\n应缴公积金:" << info.dSalary[9]
               << "\n失业险:" << info.dSalary[10] << "\n养老险:" << info.dSalary[11];
    cout << "\n个调税:" << info.dTax << "\n实发工资:" << info.lastSalary;
}

double calculateAverageSalary(const vector<techinf>& employees)
{
    double totalSalary = 0;
    for (const auto& employee : employees)
    {
        totalSalary += employee.lastSalary;
    }
    return totalSalary / employees.size();
}

//-------------------------------------------------------------------------------//

int main() 
{
    vector<techinf> employees;
    techinf info;
    int count2 = 0;
    int choice;
    string a;

    while(1)
    {
    cout<<"\t\t   工资管理系统\n***********************菜单***********************\n  1.录入工资(批量)\t\t2.删除工资记录\n  3.查询工资记录\t\t4.修改工资记录\n";
    cout<<"  5.插入工资(单条)\t\t6.统计分析\n  7.工资记录排序\t\t8.调整工资\n  9.显示工资记录\t\t0.退出管理系统\n**************************************************\n";
    cout<<"\t\t ***请选择0-9:***\n";
    cin>>choice;

    bool found = 0;

    switch (choice)
    {
    case 1:
        cout<<"请输入录入人数:";
        cin>>count2;
        cout<<"请输入"<<count2<<"个教工的工资信息:\n";
        while(1)
        {
            inputSalaryInfo(info,::count,employees);
            if (count2==::count)
            { 
                employees.push_back(info); 
                break;
            }
        }
        break;

    case 2:
        cout<<"2.删除工资记录\n";
        cout<<"请输入要删除的工号:";
        cin>>a;
        for (auto it = employees.begin(); it != employees.end(); ++it)
        {
        if (it->num == a)
        {
            employees.erase(it);
            break;
        }
        else
        {
            cout<<"没有该工号!\n";
        }
        }
        break;

    case 3:
        cout << "查询工资记录\n";
        cout << "请输入要查询的工号:";
        cin >> a;
        for (auto it = employees.begin(); it != employees.end(); ++it)
        {
        if (it->num == a)
        {
            cout << "序号:" << it->id << "\n工号:" << it->num << "\n姓名:" << it->name
                << "\n职称:" << it->title << "\n工龄:" << it->workage << "年";
            found = 1;
            break;
        }
        }
        if (!found)
        {
        cout << "没有找到该工号的工资记录！\n";
        }
        break;

    case 4:
        cout<<"4.修改工资记录\n";
        cout<<"请输入要修改的工号:";
        cin>>a;
                for (auto it = employees.begin(); it!= employees.end(); ++it)
        {
            if (it->num == a)
            {
                inputSalaryInfo(*it,::count,employees); // 修改工资信息
                employees[it - employees.begin()] = *it; // 将修改后的信息保存回 employees 容器中
                break; // 找到并修改后，跳出循环
            }
        }
        break;

    case 5:
        cout<<"插入工资(单条)\n";
        cout<<"请输入职工的工资信息:\n";
        inputSalaryInfo(info,::count,employees);
        employees.push_back(info); 
        cout << "工资记录插入成功！\n";
        break;

    case 6:
        cout << "6.统计分析\n";
        if (employees.empty()) 
        {
            cout << "没有工资记录可供分析。\n";
        }
        else 
        {
            calculateAndDisplayStats(employees);
        }
        break;

    case 7:
        cout<<"工资记录排序（顺序/逆序）\n";
        cout<<"请选择排序方式（1.顺序/2.逆序）:";
        int choice2;
        cin>>choice2;
        if (choice2==1)
        {
            // 顺序排序
            sort(employees.begin(), employees.end(), [](const techinf& a, const techinf& b) {
                return a.lastSalary < b.lastSalary;
            });
        }
        else if (choice2==2)
        {
            // 逆序排序
            sort(employees.begin(), employees.end(), [](const techinf& a, const techinf& b) {
                return a.lastSalary > b.lastSalary;
            });
        }
        else
        {
            cout<<"输入错误!";
            break;
        }

        cout << "工资记录排序成功！\n";
        break;

    case 8:
        cout<<"调整工资\n";
        cout<<"请输入要调整工资的工号:";
        cin>>a;
        for (auto it = employees.begin(); it!= employees.end(); ++it)
        {
            if (it->num == a)
            {
                int nMonths;
                cout<<"请输入要调整的月数:";
                cin>>nMonths;
                BUFA(*it, nMonths);
                cout<<"工资调整成功!";
                found = 1;
                break;
            }
        }
        if (!found)
        {
            cout << "没有找到该工号的工资记录！\n";
        }
        break;

    case 9:
        cout<<"显示工资记录\n";
        if (employees.empty()) 
        {
            cout << "没有工资记录可供显示.\n";
        } 
        else 
        {
            for (const auto& employee : employees)
            {
                displaySalaryInfo(employee);
            }
        }
        break;
    case 0:
        cout<<"退出管理系统!";
        return 0;
        break;

    default:
        cout<<"输入错误!";
        break;
    }
    }
}
