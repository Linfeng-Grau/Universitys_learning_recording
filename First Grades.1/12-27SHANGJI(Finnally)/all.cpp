#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <limits>
#include <algorithm>
using namespace std;

const int SIZE = 15;  //工资项数目为15个

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

int count = 0;

bool isValidTitle(const string& title) 
{
    vector<string> validTitles ={"professor","associate-professor","lecturer","teaching-assistant"};
    return find(validTitles.begin(), validTitles.end(), title) != validTitles.end();
}

void inputSalaryInfo(techinf& info, vector<techinf>& employees) 
{
    cout << "请输入第" << ++::count << "个职工信息(工号,姓名,职称)\n(输入职称应为英文,教授>professor,副教授>associate-professor,讲师>lecturer,助教>teaching-assistant):\n";
    info.id = ::count;

    while (1) 
    {
        cin >> info.num;
        if (find_if(employees.begin(), employees.end(), [&info](const techinf& emp) { return emp.num == info.num; }) != employees.end()) 
        {
            cout << "工号已存在，请重新输入工号: ";
            cin.clear();
            cin.ignore(1024,'\n');
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
        } 
        else 
        {
            cout << "职称输入错误，请输入有效的职称（教授professor、副教授associate-professor、讲师lecturer、助教teaching-assistant）:\n";
        }
    }
    cout << "请输入职工的工龄:";
    cin >> info.workage;

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
            cout << "输入错误！";
            cin.clear();
            cin.ignore(1024,'\n');
        }
    }
}


double calculateTax(double totalIncome) 
{
    double tax = 0;
    if (totalIncome <= 36000) {
        tax = totalIncome * 0.03;
    } else if (totalIncome <= 144000) {
        tax = 36000 * 0.03 + (totalIncome - 36000) * 0.1;
    } else if (totalIncome <= 300000) {
        tax = 36000 * 0.03 + (144000 - 36000) * 0.1 + (totalIncome - 144000) * 0.2;
    } else {
        tax = 36000 * 0.03 + (144000 - 36000) * 0.1 + (300000 - 144000) * 0.2 + (totalIncome - 300000) * 0.25;
    }
    return tax;
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

void calculateAndDisplaySalaryStats(const vector<techinf>& employees) 
{
    double totalSalary = 0;
    vector<double> salarySum(SIZE, 0);
    int employeeCount = employees.size();

    for (const auto& employee : employees) 
    {
        totalSalary += employee.lastSalary;
        for (int i = 0; i < SIZE; ++i) {
            salarySum[i] += employee.dSalary[i];
        }
    }

    cout << "各项工资和平均工资:\n";

    for (int i = 0; i < SIZE; ++i) 
    {
        cout << "工资项 " << i + 1 << ": " << salarySum[i] / employeeCount << "\n";
    }
    cout << "总工资: " << totalSalary << "\n";
    cout << "平均工资: " << totalSalary / employeeCount << "\n";
}

void calculateAndDisplayTitleStats(const vector<techinf>& employees) 
{
    int count[4] = {0};
    for (const auto& employee : employees) 
    {
        if (employee.title == "teaching-assistant") ++count[0];
        else if (employee.title == "lecturer") ++count[1];
        else if (employee.title == "associate-professor") ++count[2];
        else if (employee.title == "professor") ++count[3];
    }
 
    int maxCount = *max_element(count, count + 4);
    cout << "正高级\t副高级\t中级\t初级\n";
    for (int i = 0; i < maxCount; ++i) {
        cout << (count[3] > i ? "*" : " ") << "\t"; //正高
        cout << (count[2] > i ? "*" : " ") << "\t"; //副高
        cout << (count[1] > i ? "*" : " ") << "\t"; //中
        cout << (count[0] > i ? "*" : " ") << "\n"; //初
    }
}



int main() 
{
    vector<techinf> employees;
    techinf info;
    int choice;
    string num;
    bool found;
    int count2 = 0;
    auto it = employees.begin();

    while (1) 
    {
        cout << "\t\t   工资管理系统\n***********************菜单***********************\n";
        cout << "  1.录入工资(批量)\t\t2.删除工资记录\n";
        cout << "  3.查询工资记录\t\t4.修改工资记录\n";
        cout << "  5.插入工资(单条)\t\t6.统计分析\n";
        cout << "  7.工资记录排序\t\t8.调整工资\n";
        cout << "  9.显示工资记录\t\t0.退出管理系统\n**************************************************\n";
        cout << "\t\t ***请选择0-9:***\n";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "请输入录入人数:";
                cin >> count2;
                cout << "请输入" << count2 << "个教工的工资信息:\n";
                while (count2>0) 
                {
                    inputSalaryInfo(info, employees);
                    calculateSalary(info);
                    employees.push_back(info);
                    count2--;
                }
                break;
            case 2:
                cout << "2.删除工资记录\n";
                cout << "请输入要删除的工号:";
                cin >> num;
                it = remove_if(employees.begin(), employees.end(), [&num](const techinf& emp) { return emp.num == num; });
                if (it == employees.end()) 
                {
                    cout << "没有该工号的工资记录可删除！\n";
                } 
                else 
                {
                    employees.erase(it, employees.end());
                    cout << "工资记录删除成功！\n";
                }
                break;
            case 3:
                cout << "查询工资记录\n";
                cout << "请输入要查询的工号:";
                cin >> num;

                found = 0;
                for (const auto& employee : employees) 
                {
                if (employee.num == num) 
                {
                    displaySalaryInfo(employee);
                    found = 1;          
                }
                }
                if (found == 0)
                {
                    cout << "没有找到该工号的工资记录！\n";
                }                   
                break;
            case 4:
                cout << "4.修改工资记录\n";
                cout << "请输入要修改的工号:";
                cin >> num;
                for (auto& employee : employees) 
                {
                    if (employee.num == num) 
                    {
                        inputSalaryInfo(employee, employees);
                        calculateSalary(employee);
                        break;
                    }
                }
                break;
            case 5:
                cout << "插入工资(单条)\n";
                cout << "请输入职工的工资信息:\n";
                inputSalaryInfo(info, employees);
                calculateSalary(info);
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
                    calculateAndDisplaySalaryStats(employees);
                    calculateAndDisplayTitleStats(employees);
                }
                break;
            case 7:
                cout << "工资记录排序（顺序/逆序）\n";
                cout << "请选择排序方式（1.顺序/2.逆序）:";
                int sortChoice;
                cin >> sortChoice;
                if (sortChoice == 1) 
                {
                    sort(employees.begin(), employees.end(), [](const techinf& a, const techinf& b) 
                    {
                        return a.lastSalary < b.lastSalary;
                    });
                } 
                else if (sortChoice == 2) 
                {
                    sort(employees.begin(), employees.end(), [](const techinf& a, const techinf& b) 
                    {
                        return a.lastSalary > b.lastSalary;
                    });
                } 
                else 
                {
                    cout << "输入错误!";
                }
                cout << "工资记录排序成功！\n";
                break;
            case 8:
                cout << "调整工资\n";
                cout << "请输入要调整的工号:";
                cin >> num;
                for (auto& employee : employees) 
                {
                    if (employee.num == num) 
                    {
                        cout << "请输入调整后的工资明细:";
                        int i = 0;
                        while (i < SIZE) 
                        {
                            if (cin >> employee.dSalary[i]) 
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
                        calculateSalary(employee);
                        break;
                    }
                }
                break;
            case 9:
                cout << "显示工资记录\n";
                for (const auto& employee : employees) 
                {
                    displaySalaryInfo(employee);
                    cout << "\n";
                }
                break;
            case 0:
                cout << "退出管理系统\n";
                return 0;
            default:
                cout << "输入错误，请选择0-9之间的数字。\n";
                cin.clear();
                cin.ignore(1024,'\n');
                break;
        }
    }
    return 0;
}