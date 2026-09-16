#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define SIZE 12

struct techinf {
    string num;          // 工号
    string name;         // 姓名
    string title;        // 职称
    int workage;         // 工龄
    double dSalary[SIZE]; // 12个月的薪资
    double fiveInsurances; // 五险一金
    double dTax;         // 年总税务
    double lastsalary;   // 税后工资
    struct techinf *next;
};

typedef struct techinf TECHER;

// 辅助函数：计算总工资、五险一金、总税务和税后工资
void calculateSalary(TECHER* node) {
    double totalSalary = 0;
    for (int i = 0; i < SIZE; i++) {
        totalSalary += node->dSalary[i];
    }
    node->fiveInsurances = totalSalary * 0.1; 
    node->dTax = totalSalary * 0.15;          
    node->lastsalary = totalSalary - node->dTax - node->fiveInsurances;
}

// 1. 创建工资表
TECHER* createPayroll(TECHER* head) {
    cout << "请输入职工信息（输入-1结束）：" << endl;
    while (true) {
        TECHER* newNode = new TECHER;
        if (newNode == NULL) {
            cout << "内存分配失败！" << endl;
            exit(1);
        }

        cout << "工号：";
        cin >> newNode->num;
        if (newNode->num == "-1") break;

        cout << "姓名：";
        cin >> newNode->name;
        cout << "职称：";
        cin >> newNode->title;
        cout << "工龄：";
        cin >> newNode->workage;

        cout << "请输入12个月的薪资：";
        for (int i = 0; i < SIZE; i++) {
            cin >> newNode->dSalary[i];
        }

        calculateSalary(newNode); // 计算工资信息

        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            TECHER* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    return head;
}

// 2. 输出所有职工信息
void displayAll(TECHER* head) {
    cout << setw(10) << "工号" << setw(10) << "姓名" << setw(10) << "职称" << setw(10) << "工龄"
         << setw(20) << "总工资" << setw(20) << "五险一金" << setw(20) << "总税务" << setw(20) << "税后工资" << endl;
    TECHER* current = head;
    while (current != NULL) {
        cout << setw(10) << current->num << setw(10) << current->name << setw(10) << current->title
             << setw(10) << current->workage << setw(20) << fixed << setprecision(2) << (current->dSalary[0] + current->dSalary[1] + current->dSalary[2] + current->dSalary[3] + current->dSalary[4] + current->dSalary[5] + current->dSalary[6] + current->dSalary[7] + current->dSalary[8] + current->dSalary[9] + current->dSalary[10] + current->dSalary[11])
             << setw(20) << current->fiveInsurances << setw(20) << current->dTax << setw(20) << current->lastsalary << endl;
        current = current->next;
    }
}

// 3. 修改职工信息
TECHER* modifyInfo(TECHER* head) {
    string num;
    cout << "请输入要修改的职工工号：";
    cin >> num;

    TECHER* current = head;
    while (current != NULL && current->num != num) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "未找到该职工！" << endl;
        return head;
    }

    cout << "当前职工信息：" << endl;
    cout << "工号：" << current->num << ", 姓名：" << current->name << ", 职称：" << current->title
         << ", 工龄：" << current->workage << endl;

    cout << "请输入新的姓名：";
    cin >> current->name;
    cout << "请输入新的职称：";
    cin >> current->title;
    cout << "请输入新的工龄：";
    cin >> current->workage;
    cout << "请输入新的12个月薪资：";
    for (int i = 0; i < SIZE; i++) {
        cin >> current->dSalary[i];
    }

    calculateSalary(current); // 重新计算工资信息
    cout << "职工信息修改成功！" << endl;
    return head;
}

// 4. 插入职工信息
TECHER* insertInfo(TECHER* head) {
    TECHER* newNode = (TECHER*)malloc(sizeof(TECHER));
    if (newNode == NULL) 
    {
        cout << "内存分配失败！" << endl;
        exit(1);
    }
    cout << "请输入新职工信息：" << endl;
    cout << "工号：";
    cin >> newNode->num;
    cout << "姓名：";
    cin >> newNode->name;
    cout << "职称：";
    cin >> newNode->title;
    cout << "工龄：";
    cin >> newNode->workage;
    cout << "请输入12个月的薪资：";
    for (int i = 0; i < SIZE; i++) {
        cin >> newNode->dSalary[i];
    }

    calculateSalary(newNode); // 计算工资信息

    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        TECHER* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "职工信息插入成功！" << endl;
    return head;
}

// 5. 查询职工信息
TECHER* searchInfo(TECHER* head) {
    string num;
    cout << "请输入要查询的职工工号：";
    cin >> num;

    TECHER* current = head;
    while (current != NULL && current->num != num) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "未找到该职工！" << endl;
        return head;
    }

    cout << "职工信息：" << endl;
    cout << "工号：" << current->num << ", 姓名：" << current->name << ", 职称：" << current->title
         << ", 工龄：" << current->workage << ", 总工资：" << fixed << setprecision(2) << (current->dSalary[0] + current->dSalary[1] + current->dSalary[2] + current->dSalary[3] + current->dSalary[4] + current->dSalary[5] + current->dSalary[6] + current->dSalary[7] + current->dSalary[8] + current->dSalary[9] + current->dSalary[10] + current->dSalary[11])
         << ", 五险一金：" << current->fiveInsurances << ", 总税务：" << current->dTax
         << ", 税后工资：" << current->lastsalary << endl;
    return head;
}

// 6. 删除职工信息
TECHER* deleteInfo(TECHER* head) {
    string num;
    cout << "请输入要删除的职工工号：";
    cin >> num;

    TECHER* current = head;
    TECHER* prev = NULL;

    while (current != NULL && current->num != num) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "未找到该职工！" << endl;
        return head;
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    cout << "职工信息删除成功！" << endl;
    return head;
}

// 7. 排序职工信息
TECHER* sortInfo(TECHER* head, bool ascending = true) {
    vector<TECHER*> nodes;
    TECHER* current = head;
    while (current != NULL) {
        nodes.push_back(current);
        current = current->next;
    }

    sort(nodes.begin(), nodes.end(), [ascending](TECHER* a, TECHER* b) {
        return ascending ? a->num < b->num : a->num > b->num;
    });

    for (size_t i = 0; i < nodes.size(); i++) {
        if (i == 0) {
            head = nodes[i];
        } else {
            nodes[i - 1]->next = nodes[i];
        }
    }
    if (!nodes.empty()) {
        nodes.back()->next = NULL;
    }
    return head;
}

// 8. 分类统计
void statistics(TECHER* head) {
    vector<double> totalSalaries;
    TECHER* current = head;
    while (current != NULL) {
        double totalSalary = 0;
        for (int i = 0; i < SIZE; i++) {
            totalSalary += current->dSalary[i];
        }
        totalSalaries.push_back(totalSalary);
        current = current->next;
    }

    double totalSum = 0;
    for (double salary : totalSalaries) {
        totalSum += salary;
    }

    double avgSalary = totalSum / totalSalaries.size();
    cout << "所有职工工资平均值：" << fixed << setprecision(2) << avgSalary << endl;
    cout << "总工资：" << totalSum << endl;

    int countHigh = 0, countMid = 0, countLow = 0;
    for (double salary : totalSalaries) {
        if (salary > 4500) {
            countHigh++;
        } else if (salary >= 2500) {
            countMid++;
        } else {
            countLow++;
        }
    }

    cout << "工资在4500元以上的职工人数：" << countHigh << "，占比：" << fixed << setprecision(2) << (countHigh * 100.0 / totalSalaries.size()) << "%" << endl;
    cout << "工资在2500到4500元之间的职工人数：" << countMid << "，占比：" << fixed << setprecision(2) << (countMid * 100.0 / totalSalaries.size()) << "%" << endl;
    cout << "工资在2500元以下的职工人数：" << countLow << "，占比：" << fixed << setprecision(2) << (countLow * 100.0 / totalSalaries.size()) << "%" << endl;
}

// 9. 个人整年工资发放明细
void individualSalaryDetail(TECHER* head) {
    string num;
    cout << "请输入要查询的职工工号：";
    cin >> num;

    TECHER* current = head;
    while (current != NULL && current->num != num) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "未找到该职工！" << endl;
        return;
    }

    cout << "职工：" << current->name << "（工号：" << current->num << "）的工资明细：" << endl;
    cout << setw(10) << "月份" << setw(20) << "应发工资" << setw(20) << "五险一金" << setw(20) << "税务" << setw(20) << "实发工资" << endl;

    double totalGross = 0, totalInsurance = 0, totalTax = 0, totalNet = 0;
    for (int i = 0; i < SIZE; i++) {
        double gross = current->dSalary[i];
        double insurance = gross * 0.1;
        double tax = gross * 0.15;
        double net = gross - insurance - tax;

        totalGross += gross;
        totalInsurance += insurance;
        totalTax += tax;
        totalNet += net;

        cout << setw(10) << i + 1 << setw(20) << fixed << setprecision(2) << gross
             << setw(20) << insurance << setw(20) << tax << setw(20) << net << endl;
    }

    cout << setw(10) << "总计" << setw(20) << totalGross << setw(20) << totalInsurance
         << setw(20) << totalTax << setw(20) << totalNet << endl;
}

// 主函数
int main() 
{
    TECHER* head = NULL;

    while (true) {
        cout << "\n高校教职工工资管理系统\n";
        cout << "1. 创建工资表\n";
        cout << "2. 输出所有职工信息\n";
        cout << "3. 修改职工信息\n";
        cout << "4. 插入职工信息\n";
        cout << "5. 查询职工信息\n";
        cout << "6. 删除职工信息\n";
        cout << "7. 排序职工信息\n";
        cout << "8. 分类统计\n";
        cout << "9. 个人整年工资发放明细\n";
        cout << "10. 退出系统\n";
        cout << "请选择操作：";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                head = createPayroll(head);
                break;
            case 2:
                displayAll(head);
                break;
            case 3:
                head = modifyInfo(head);
                break;
            case 4:
                head = insertInfo(head);
                break;
            case 5:
                head = searchInfo(head);
                break;
            case 6:
                head = deleteInfo(head);
                break;
            case 7:
                cout << "选择排序方式：\n";
                cout << "1. 正序（按工号升序）\n";
                cout << "2. 倒序（按工号降序）\n";
                int sortChoice;
                cin >> sortChoice;
                if (sortChoice == 1) {
                    head = sortInfo(head, true);
                } else if (sortChoice == 2) {
                    head = sortInfo(head, false);
                } else {
                    cout << "无效选择！\n";
                }
                break;
            case 8:
                statistics(head);
                break;
            case 9:
                individualSalaryDetail(head);
                break;
            case 10:
                cout << "退出系统，感谢使用！\n";
                return 0;
            default:
                cout << "无效选择，请重新输入！\n";
        }
    }
    return 0;
}