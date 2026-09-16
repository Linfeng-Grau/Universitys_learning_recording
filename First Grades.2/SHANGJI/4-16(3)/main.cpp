#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

#define MAX_ITEMS 100
#define MAX_ORDERS 100
#define ADMIN_USER "admin"
#define ADMIN_PASS "123456"

class Menu
{
public:
    string number;
    string name;
    double price;
    double discount;

    Menu() : number(""), name(""), price(0), discount(0) {}

    Menu(string a, string b, double c, double d)
        : number(a), name(b), price(c), discount(d) {}

    bool operator<(const Menu& other) const
    {
        return number < other.number;
    }

    void cout_menu() const
    {
        cout << "编号: " << number << endl;
        cout << "名称: " << name << endl;
        cout << "价格: " << price << endl;
        cout << "折扣: " << discount << endl;
        cout << "---------------------" << endl;
    }
};

class Base_orders
{
public:
    string order_number;
    string dish_number;
    string dish_name;
    double dish_price;
    double dish_discount;
    int amount;
    double total_price;

    Base_orders() : order_number(""), dish_number(""), dish_name(""),
        dish_price(0), dish_discount(0), amount(0), total_price(0) {}

    void out_file_eachDish(const string& file_name) const
    {
        ofstream file(file_name, ios::app);
        if (file.is_open())
        {
            file << order_number << " " << dish_number << " " << dish_name << " "
                 << dish_price << " " << dish_discount << " " << amount << " "
                 << total_price << endl;
        }
    }

    void cout_orders() const
    {
        cout << "订单号: " << order_number << endl;
        cout << "菜品编号: " << dish_number << endl;
        cout << "菜品名称: " << dish_name << endl;
        cout << "单价: " << dish_price << endl;
        cout << "折扣: " << dish_discount << endl;
        cout << "数量: " << amount << endl;
        cout << "总价: " << total_price << endl;
        cout << "---------------------" << endl;
    }
};

class RestaurantSystem
{
private:
    Menu menuItems[MAX_ITEMS];
    Base_orders orders[MAX_ORDERS];
    int menuCount;
    int orderCount;

    void loadMenu()
    {
        ifstream file("menu.txt");
        menuCount = 0;

        if (file.is_open())
        {
            while (file >> menuItems[menuCount].number >> ws
                   && getline(file, menuItems[menuCount].name, ',')
                   && file >> menuItems[menuCount].price
                   && file >> menuItems[menuCount].discount)
            {
                menuCount++;
                if (menuCount >= MAX_ITEMS) break;
            }
        }
    }

    void saveMenu() const
    {
        ofstream file("menu.txt");
        if (file.is_open())
        {
            for (int i = 0; i < menuCount; i++)
            {
                file << menuItems[i].number << " " << menuItems[i].name << ","
                     << menuItems[i].price << " " << menuItems[i].discount << endl;
            }
        }
    }

    int findMenuItemIndex(const string& number) const
    {
        for (int i = 0; i < menuCount; i++)
        {
            if (menuItems[i].number == number)
                return i;
        }
        return -1;
    }

    void sortMenuItems()
    {
        sort(menuItems, menuItems + menuCount);
    }

    bool adminLogin() const
    {
        string username, password;
        cout << "请输入管理员账号: ";
        cin >> username;
        cout << "请输入密码: ";
        cin >> password;
        return (username == ADMIN_USER && password == ADMIN_PASS);
    }

public:
    RestaurantSystem() : menuCount(0), orderCount(0)
    {
        loadMenu();
    }

    ~RestaurantSystem()
    {
        saveMenu();
    }

    // 1. 修改菜品信息
    void modifyMenuItem()
    {
        string number;
        while (true)
        {
            cout << "请输入要修改的菜品编号: ";
            cin >> number;

            int index = findMenuItemIndex(number);
            if (index == -1)
            {
                cout << "未找到编号为 " << number << " 的菜品。" << endl;
                cout << "1. 重新输入编号\n2. 返回主菜单\n请选择: ";
                int choice;
                cin >> choice;
                if (choice == 2) return;
                continue;
            }

            cout << "当前菜品信息: " << endl;
            menuItems[index].cout_menu();

            cout << "请输入新的菜品名称: ";
            cin.ignore();
            getline(cin, menuItems[index].name);
            cout << "请输入新的价格: ";
            cin >> menuItems[index].price;
            cout << "请输入新的折扣: ";
            cin >> menuItems[index].discount;

            cout << "菜品信息修改成功!" << endl;
            saveMenu();
            break;
        }
    }

    // 2. 删除菜品信息
    void deleteMenuItem()
    {
        string number;
        cout << "请输入要删除的菜品编号: ";
        cin >> number;

        int index = findMenuItemIndex(number);
        if (index == -1)
        {
            cout << "无可删菜品" << endl;
            return;
        }

        cout << "将删除以下菜品: " << endl;
        menuItems[index].cout_menu();

        cout << "确认删除吗? (1-确认, 0-取消): ";
        int confirm;
        cin >> confirm;
        if (confirm == 1)
        {
            for (int i = index; i < menuCount - 1; i++)
            {
                menuItems[i] = menuItems[i + 1];
            }
            menuCount--;
            cout << "菜品删除成功!" << endl;
            saveMenu();
        }
        else
        {
            cout << "已取消删除操作。" << endl;
        }
    }

    // 3. 查询菜品信息
    void searchMenuItems()
    {
        while (true)
        {
            cout << "请选择查询方式:\n";
            cout << "1. 按编号查询\n";
            cout << "2. 按名称查询\n";
            cout << "3. 按价格范围查询\n";
            cout << "4. 按折扣范围查询\n";
            cout << "5. 返回\n";
            cout << "请选择(1-5): ";

            int choice;
            cin >> choice;

            if (choice == 5) return;

            bool found = false;

            switch (choice)
            {
                case 1:
                {
                    string number;
                    cout << "请输入菜品编号: ";
                    cin >> number;

                    int index = findMenuItemIndex(number);
                    if (index != -1)
                    {
                        menuItems[index].cout_menu();
                        found = true;
                    }
                    break;
                }
                case 2:
                {
                    string name;
                    cout << "请输入菜品名称(或部分名称): ";
                    cin.ignore();
                    getline(cin, name);

                    for (int i = 0; i < menuCount; i++)
                    {
                        if (menuItems[i].name.find(name) != string::npos)
                        {
                            menuItems[i].cout_menu();
                            found = true;
                        }
                    }
                    break;
                }
                case 3:
                {
                    double minPrice, maxPrice;
                    cout << "请输入最低价格: ";
                    cin >> minPrice;
                    cout << "请输入最高价格: ";
                    cin >> maxPrice;

                    for (int i = 0; i < menuCount; i++)
                    {
                        if (menuItems[i].price >= minPrice && menuItems[i].price <= maxPrice)
                        {
                            menuItems[i].cout_menu();
                            found = true;
                        }
                    }
                    break;
                }
                case 4:
                {
                    double minDiscount, maxDiscount;
                    cout << "请输入最低折扣: ";
                    cin >> minDiscount;
                    cout << "请输入最高折扣: ";
                    cin >> maxDiscount;

                    for (int i = 0; i < menuCount; i++)
                    {
                        if (menuItems[i].discount >= minDiscount && menuItems[i].discount <= maxDiscount)
                        {
                            menuItems[i].cout_menu();
                            found = true;
                        }
                    }
                    break;
                }
                default:
                    cout << "无效的选择!" << endl;
                    continue;
            }

            if (!found)
            {
                cout << "没有你要查找的菜品" << endl;
            }
        }
    }

    // 用户身份选择
    void userRoleSelection()
    {
        while (true)
        {
            cout << "===== 欢迎使用自助点餐系统 =====" << endl;
            cout << "1. 管理员" << endl;
            cout << "2. 顾客" << endl;
            cout << "3. 退出" << endl;
            cout << "请选择您的身份: ";

            int role;
            cin >> role;

            switch (role)
            {
                case 1:
                    if (adminLogin())
                        adminMenu();
                    else
                        cout << "账号或密码错误!" << endl;
                    break;
                case 2:
                    customerMenu();
                    break;
                case 3:
                    return;
                default:
                    cout << "无效的选择!" << endl;
            }
        }
    }

    // 录入菜单
    void inputMenuItems()
    {
        cout << "请输入要添加的菜品数量: ";
        int count;
        cin >> count;

        if (menuCount + count > MAX_ITEMS)
        {
            cout << "超出最大菜品数量限制!" << endl;
            return;
        }

        for (int i = 0; i < count; i++)
        {
            cout << "请输入第 " << i + 1 << " 个菜品信息:" << endl;
            string number, name;
            double price, discount;

            cout << "编号: ";
            cin >> number;
            cout << "名称: ";
            cin.ignore();
            getline(cin, name);
            cout << "价格: ";
            cin >> price;
            cout << "折扣: ";
            cin >> discount;

            menuItems[menuCount++] = Menu(number, name, price, discount);
        }

        cout << "菜单录入完成!" << endl;
        saveMenu();
        displayAllMenuItems();
    }

    void displayAllMenuItems() const
    {
        if (menuCount == 0)
        {
            cout << "菜单中没有菜品。" << endl;
            return;
        }

        // 排序显示（不修改原数组顺序，使用临时数组）
        Menu sorted[MAX_ITEMS];
        for (int i = 0; i < menuCount; i++)
            sorted[i] = menuItems[i];
        sort(sorted, sorted + menuCount);

        cout << "============ 菜单 ============" << endl;
        for (int i = 0; i < menuCount; i++)
        {
            sorted[i].cout_menu();
        }
    }

    void adminMenu()
    {
        while (true)
        {
            cout << "===== 管理员菜单 =====" << endl;
            cout << "1. 添加菜品" << endl;
            cout << "2. 修改菜品" << endl;
            cout << "3. 删除菜品" << endl;
            cout << "4. 查询菜品" << endl;
            cout << "5. 显示所有菜品" << endl;
            cout << "6. 返回上级" << endl;
            cout << "请选择操作(1-6): ";

            int choice;
            cin >> choice;

            switch (choice)
            {
                case 1: inputMenuItems(); break;
                case 2: modifyMenuItem(); break;
                case 3: deleteMenuItem(); break;
                case 4: searchMenuItems(); break;
                case 5: displayAllMenuItems(); break;
                case 6: return;
                default: cout << "无效的选择!" << endl;
            }
        }
    }

    void customerMenu()
    {
        while (true)
        {
            cout << "===== 顾客菜单 =====" << endl;
            cout << "1. 查看菜单" << endl;
            cout << "2. 查询菜品" << endl;
            cout << "3. 下单" << endl;
            cout << "4. 返回" << endl;
            cout << "请选择操作(1-4): ";

            int choice;
            cin >> choice;

            switch (choice)
            {
                case 1: displayAllMenuItems(); break;
                case 2: searchMenuItems(); break;
                case 3: placeOrder(); break;
                case 4: return;
                default: cout << "无效的选择!" << endl;
            }
        }
    }

    void placeOrder() const
    {
        cout << "下单功能待实现^^" << endl;
    }
};

int main()
{
    RestaurantSystem system;
    system.userRoleSelection();
    return 0;
}