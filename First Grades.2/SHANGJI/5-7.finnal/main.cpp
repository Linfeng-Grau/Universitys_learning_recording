#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <sstream>
using namespace std;
#define MAX 100

class menu 
{
public:
    int number;
    string name;
    double price;
    double discount;

    menu(int a = 0, string b = " ", double c = 0, double d = 0) : number(a), name(b), price(c), discount(d) {}

    ~menu() {
        cout << "menu class" << endl;
    }

    void outfile(string filename) {
        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << number << " " << name << "," << price << " " << discount << endl;
            file.close();
        }
    }

    void coutmenu() {
        cout << "number\tname\tprice\tdiscount" << endl;
        cout << number << "\t" << name << "\t" << price << "\t" << discount << endl;
    }

    bool operator<(const menu& a) const {
        return number < a.number;
    }
};

class order {
public:
    string orderID;
    string customerPhone;
    string itemsInfo;
    double totalAmount;
    string additionalInfo;

    order(string id = "", string phone = "", string items = "", double total = 0.0, string info = "") :
        orderID(id), customerPhone(phone), itemsInfo(items), totalAmount(total), additionalInfo(info) {}

    void saveToFile(string filename) {
        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << orderID << " " << customerPhone << " " << itemsInfo << " " << totalAmount << " " << additionalInfo << endl;
            file.close();
        }
    }

    void displayOrder() {
        cout << "Order ID: " << orderID << endl;
        cout << "Customer Phone: " << customerPhone << endl;
        cout << "Items: " << itemsInfo << endl;
        cout << "Total Amount: " << totalAmount << endl;
        cout << "Additional Info: " << additionalInfo << endl;
        cout << "---------------------" << endl;
    }
};

class Rsystem {
private:
    menu menus[MAX];
    order orders[MAX];
    int dishcount;
    int ordercount;
    string username = "admin";
    string password = "123456";

    void loadMenus() {
        ifstream file("menus.txt");
        dishcount = 0;

        if (file.is_open()) {
            while (file >> menus[dishcount].number >> ws && getline(file, menus[dishcount].name, ',') && file >> menus[dishcount].price >> menus[dishcount].discount) {
                dishcount++;
                if (dishcount >= MAX) {
                    break;
                }
            }
            file.close();
        }
    }

    void saveMenus() {
        ofstream file("menus.txt");
        if (file.is_open()) {
            for (int i = 0; i < dishcount; i++) {
                file << menus[i].number << " " << menus[i].name << "," << menus[i].price << " " << menus[i].discount << endl;
            }
            file.close();
        }
    }

    void loadOrders() {
        ifstream file("menuorder.txt");
        ordercount = 0;

        if (file.is_open()) {
            while (getline(file, orders[ordercount].orderID) && 
                   getline(file, orders[ordercount].customerPhone) && 
                   getline(file, orders[ordercount].itemsInfo) && 
                   file >> orders[ordercount].totalAmount && 
                   getline(file, orders[ordercount].additionalInfo)) {
                ordercount++;
                if (ordercount >= MAX) {
                    break;
                }
            }
            file.close();
        }
    }

    void saveOrders() {
        ofstream file("menuorder.txt");
        if (file.is_open()) {
            for (int i = 0; i < ordercount; i++) {
                file << orders[i].orderID << " " << orders[i].customerPhone << " " << orders[i].itemsInfo << " " << orders[i].totalAmount << " " << orders[i].additionalInfo << endl;
            }
            file.close();
        }
    }

    bool login() {
        string pass, user;
        cout << "请输入管理员账号: ";
        cin >> user;
        if (user == username) {
            cout << "请输入管理员密码: ";
            cin >> pass;
            if (pass == password) {
                return true;
            } else {
                cout << "密码错误！" << endl;
                return false;
            }
        } else {
            cout << "不存在该账号！" << endl;
            return false;
        }
    }

public:
    Rsystem() : dishcount(0), ordercount(0) {
        loadMenus();
        loadOrders();
    }

    ~Rsystem() {
        saveMenus();
        saveOrders();
    }

    int findMenu(int num) {
        for (int i = 0; i < dishcount; i++) {
            if (menus[i].number == num) {
                return i;
            }
        }
        return -1;
    }

    void sortMenus() {
        for (int i = 0; i < dishcount - 1; i++) {
            for (int j = 0; j < dishcount - i - 1; j++) {
                if (!(menus[j] < menus[j + 1])) {
                    menu temp = menus[j];
                    menus[j] = menus[j + 1];
                    menus[j + 1] = temp;
                }
            }
        }
    }

    void displayAllDishes() {
        if (dishcount == 0) {
            cout << "菜单中没有菜品！" << endl;
            return;
        }
        sortMenus();
        cout << "============菜单============" << endl;
        for (int i = 0; i < dishcount; i++) {
            menus[i].coutmenu();
        }
    }

    void addDish() {
        int count;
        cout << "请输入要增加的菜品信息数量: ";
        cin >> count;

        if ((count + dishcount) > MAX) {
            cout << "超出最大限制！添加失败！" << endl;
            return;
        }

        for (int j = 0; j < count; j++) {
            cout << "请输入第" << j + 1 << "个菜品的信息: " << endl;
            int n;
            string nm;
            double p;
            double d;
            cout << "编号: ";
            cin >> n;
            cout << "菜名: ";
            cin.ignore();
            getline(cin, nm);
            cout << "价格: ";
            cin >> p;
            cout << "折扣: ";
            cin >> d;

            menus[dishcount++] = menu(n, nm, p, d);
            menus[dishcount - 1].outfile("menus.txt");
        }

        cout << "录入完成!" << endl;
        displayAllDishes();
    }

    void changeDish() {
        int n;
        cout << "请输入要修改的菜品的编号：";
        cin >> n;
        int i = findMenu(n);

        if (findMenu(n) == -1) {
            cout << "不存在此菜品！" << endl;
            return;
        }

        cout << "当前菜品信息：";
        menus[i].coutmenu();

        cout << "请输入新的菜品信息" << endl;
        cout << "菜品名：";
        cin.ignore();
        getline(cin, menus[i].name);
        cout << "价格：";
        cin >> menus[i].price;
        cout << "折扣：";
        cin >> menus[i].discount;

        cout << "修改成功" << endl;
        saveMenus();
    }

    void deleteDish() {
        int n, confirm;
        cout << "请输入要删除的菜品的编号：";
        cin >> n;

        if (findMenu(n) == -1) {
            cout << "不存在此菜品！" << endl;
            return;
        }
        int i = findMenu(n);
        cout << "将要删除菜品的信息：";
        menus[i].coutmenu();

        cout << "确认删除？(按1确认,其他键取消)" << endl;
        cin >> confirm;
        if (confirm == 1) {
            for (int j = i; j < dishcount - 1; j++) {
                menus[j] = menus[j + 1];
            }
            dishcount--;
            cout << "删除成功" << endl;
            saveMenus();
        } else {
            cout << "已取消操作" << endl;
            return;
        }
    }

    void searchDish() {
        int choice;
        bool r = 1;
        while (r) {
            cout << "请选择查询方式:" << endl;
            cout << "1. 按编号查询" << endl;
            cout << "2. 按名称查询" << endl;
            cout << "3. 按价格范围查询" << endl;
            cout << "4. 按折扣范围查询" << endl;
            cout << "0. 返回上一级" << endl;
            cout << "请选择(0-4): ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    int n;
                    cout << "请输入菜品编号: ";
                    cin >> n;
                    if (findMenu(n) == -1) {
                        cout << "没有你要找的菜品！" << endl;
                        return;
                    } else {
                        int i = findMenu(n);
                        menus[i].coutmenu();
                    }
                    break;
                }
                case 2: {
                    string nm;
                    cout << "请输入菜品名称: ";
                    cin >> nm;
                    cin.ignore();
                    getline(cin, nm);
                    for (int i = 0; i < dishcount; i++) {
                        if (menus[i].name.find(nm) != string::npos) {
                            menus[i].coutmenu();
                        }
                    }
                    break;
                }
                case 3: {
                    double maxprice, minprice;
                    cout << "请输入最大价格: ";
                    cin >> maxprice;
                    cout << "请输入最小价格: ";
                    cin >> minprice;

                    for (int i = 0; i < dishcount; i++) {
                        if (menus[i].price <= maxprice && menus[i].price >= minprice) {
                            menus[i].coutmenu();
                        }
                    }
                    break;
                }
                case 4: {
                    double maxdiscount, mindiscount;
                    cout << "请输入最大折扣: ";
                    cin >> maxdiscount;
                    cout << "请输入最小折扣: ";
                    cin >> mindiscount;

                    for (int j = 0; j < dishcount; j++) {
                        if (menus[j].discount <= maxdiscount && menus[j].discount >= mindiscount) {
                            menus[j].coutmenu();
                        }
                    }
                    break;
                }
                case 0: {
                    r = 0;
                    break;
                }
                default: {
                    cout << "无效的选择！" << endl;
                    break;
                }
            }
        }
    }

    void userSelect() {
        bool r = 1;
        int role;
        while (r) {
            cout << "------------\n请选择您的身份(按其他任意键退出):" << endl;
            cout << "1.管理员" << endl;
            cout << "2.顾客\n------------" << endl;
            cin >> role;

            if (role == 1) {
                if (login()) {
                    cout << "您已进入管理员界面！" << endl;
                    admin();
                } else {
                    userSelect();
                }
            } else if (role == 2) {
                cout << "您已进入顾客界面，欢迎光临！" << endl;
                customer();
            } else {
                r = 0;
                break;
            }
        }
    }

    void admin() {
        bool r = 1;
        int choice;

        while (r) {
            cout << "------------\n请选择操作:" << endl;
            cout << "1.查找订单" << endl;
            cout << "2.修改订单" << endl;
            cout << "3.删除订单" << endl;
            cout << "4.菜品增加" << endl;
            cout << "5.菜品修改" << endl;
            cout << "6.菜品删除" << endl;
            cout << "7.菜品查找" << endl;
            cout << "8.销售情况统计" << endl;
            cout << "9.菜单信息全部展示" << endl;
            cout << "0.退出\n------------" << endl;
            cin >> choice;
            switch (choice) {
                case 1: {
                    searchOrder();
                    break;
                }
                case 2: {
                    modifyOrder();
                    break;
                }
                case 3: {
                    deleteOrder();
                    break;
                }
                case 4: {
                    addDish();
                    break;
                }
                case 5: {
                    changeDish();
                    break;
                }
                case 6: {
                    deleteDish();
                    break;
                }
                case 7: {
                    searchDish();
                    break;
                }
                case 8: {
                    salesStatistics();
                    break;
                }
                case 9: {
                    displayAllDishes();
                    break;
                }
                case 0: {
                    r = 0;
                    break;
                }
                default: {
                    cout << "无效选择!" << endl;
                    break;
                }
            }
        }
    }

    void customer() {
        bool r = 1;
        int choice;
        while (r) {
            cout << "请看菜单点餐~" << endl;
            displayAllDishes();

            cout << "请选择消费方式:" << endl;
            cout << "1.堂食" << endl;
            cout << "2.外卖" << endl;
            cout << "3.返回上级" << endl;
            cin >> choice;
            switch (choice) {
                case 1: {
                    dineInOrder();
                    break;
                }
                case 2: {
                    takeOutOrder();
                    break;
                }
                case 3: {
                    r = 0;
                    break;
                }
                default: {
                    cout << "无效选择！" << endl;
                    break;
                }
            }
        }
    }

    void dineInOrder() {
        string tableNumber, isPrivateRoom, privateRoomFee;
        double totalAmount = 0.0;
        string itemsInfo;
        string orderID = generateOrderID();

        cout << "请输入餐桌号: ";
        cin >> tableNumber;
        cout << "是否有包厢费 (是/否): ";
        cin >> isPrivateRoom;
        if (isPrivateRoom == "是") {
            privateRoomFee = "100";
            totalAmount += 100;
        } else {
            privateRoomFee = "0";
        }

        cout << "请输入点菜信息 (格式: 菜品编号 数量): ";
        cin.ignore();
        getline(cin, itemsInfo);

        // Calculate total amount
        stringstream ss(itemsInfo);
        int dishNumber, quantity;
        while (ss >> dishNumber >> quantity) {
            int index = findMenu(dishNumber);
            if (index != -1) {
                totalAmount += menus[index].price * menus[index].discount * quantity;
            }
        }

        orders[ordercount++] = order(orderID, "", itemsInfo, totalAmount, "餐桌号: " + tableNumber + ", 包厢费: " + privateRoomFee);
        orders[ordercount - 1].saveToFile("menuorder.txt");
        orders[ordercount - 1].displayOrder();
    }

    void takeOutOrder() {
        string deliveryTime, deliveryAddress, customerPhone;
        double totalAmount = 0.0;
        string itemsInfo;
        string orderID = generateOrderID();

        cout << "请输入送餐时间: ";
        cin >> deliveryTime;
        cout << "请输入送餐地点: ";
        cin.ignore();
        getline(cin, deliveryAddress);
        cout << "请输入手机号: ";
        cin >> customerPhone;

        cout << "请输入点菜信息 (格式: 菜品编号 数量): ";
        cin.ignore();
        getline(cin, itemsInfo);

        // Calculate total amount
        stringstream ss(itemsInfo);
        int dishNumber, quantity;
        while (ss >> dishNumber >> quantity) {
            int index = findMenu(dishNumber);
            if (index != -1) {
                totalAmount += menus[index].price * menus[index].discount * quantity;
            }
        }
        totalAmount += 20; // Delivery fee

        orders[ordercount++] = order(orderID, customerPhone, itemsInfo, totalAmount, "送餐时间: " + deliveryTime + ", 送餐地点: " + deliveryAddress);
        orders[ordercount - 1].saveToFile("menuorder.txt");
        orders[ordercount - 1].displayOrder();
    }

    void searchOrder() {
        string searchID, searchPhone;
        cout << "请输入订单号或手机号: ";
        cin >> searchID;

        for (int i = 0; i < ordercount; i++) {
            if (orders[i].orderID == searchID || orders[i].customerPhone == searchID) {
                orders[i].displayOrder();
                return;
            }
        }
        cout << "未找到订单！" << endl;
    }

    void modifyOrder() {
        string searchID;
        cout << "请输入订单号: ";
        cin >> searchID;

        for (int i = 0; i < ordercount; i++) {
            if (orders[i].orderID == searchID) {
                cout << "当前订单信息: " << endl;
                orders[i].displayOrder();

                cout << "请输入新的点菜信息 (格式: 菜品编号 数量): ";
                cin.ignore();
                getline(cin, orders[i].itemsInfo);

                // Recalculate total amount
                double totalAmount = 0.0;
                stringstream ss(orders[i].itemsInfo);
                int dishNumber, quantity;
                while (ss >> dishNumber >> quantity) {
                    int index = findMenu(dishNumber);
                    if (index != -1) {
                        totalAmount += menus[index].price * menus[index].discount * quantity;
                    }
                }

                orders[i].totalAmount = totalAmount;
                saveOrders();
                cout << "订单修改成功！" << endl;
                return;
            }
        }
        cout << "未找到订单！" << endl;
    }

    void deleteOrder() {
        string searchID;
        cout << "请输入订单号或手机号: ";
        cin >> searchID;

        for (int i = 0; i < ordercount; i++) {
            if (orders[i].orderID == searchID || orders[i].customerPhone == searchID) {
                for (int j = i; j < ordercount - 1; j++) {
                    orders[j] = orders[j + 1];
                }
                ordercount--;
                saveOrders();
                cout << "订单删除成功！" << endl;
                return;
            }
        }
        cout << "未找到订单！" << endl;
    }

    void salesStatistics() {
        int dishSales[MAX] = {0};
        for (int i = 0; i < ordercount; i++) {
            stringstream ss(orders[i].itemsInfo);
            int dishNumber, quantity;
            while (ss >> dishNumber >> quantity) {
                dishSales[dishNumber]++;
            }
        }

        // Sort dishes by sales count
        for (int i = 0; i < dishcount - 1; i++) {
            for (int j = 0; j < dishcount - i - 1; j++) {
                if (dishSales[j] < dishSales[j + 1]) {
                    swap(dishSales[j], dishSales[j + 1]);
                    swap(menus[j], menus[j + 1]);
                }
            }
        }

        cout << "销售情况统计（前5名）:" << endl;
        for (int i = 0; i < min(5, dishcount); i++) {
            cout << menus[i].name << ": " << dishSales[i] << " *" << endl;
        }
    }

    string generateOrderID() {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        stringstream ss;
        ss << ltm->tm_year + 1900 << setfill('0') << setw(2) << ltm->tm_mon + 1 << setw(2) << ltm->tm_mday;
        ss << setw(3) << ordercount + 1;
        return ss.str();
    }
};

int main() 
{
    Rsystem a;
    a.userSelect();
    return 0;
}