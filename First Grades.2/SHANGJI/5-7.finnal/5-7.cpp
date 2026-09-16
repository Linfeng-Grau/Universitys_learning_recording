#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <chrono>
#include <ctime>
using namespace std;
#define MAX 100

class menu//编号，菜名，价格，折扣
{
    public:
        int number;
        string name;
        double price;
        double discount;

        menu(int a=0,string b=" ",double c=0,double d=0):number(a),name(b),price(c),discount(d){}

        ~menu()
        {
            cout<<"menu class"<<endl;
        }

        void outfile(string filename)
        {
            ofstream file(filename,ios::app);
            if(file.is_open())
            {
                file<<number<<" "<<name<<","<<price<<" "<<discount<<endl;
                file.close();
            }
        }

        void coutmenu()
        {
            cout<<"number\tname\tprice\tdiscount"<<endl;
            cout<<number<<"\t"<<name<<"\t"<<price<<"\t"<< discount<<endl; 
        }
        
        bool operator < (const menu& a) const
        {
            return number<a.number;
        }
};
//===============================================================================
class order:public menu
{
    public:
        int amount;//菜品数量
        order() : amount(0) {}
        order(const menu& m, int a) : menu(m), amount(a) {}
        void coutorder() const
        { 
            cout<<number<<"\t"<<name<<"\t"<<price<<"\t"<<discount
            <<"\t"<<amount<<"\t"<<price*discount*amount<<endl;
            cout << "---------------------" << endl;
        }
};

class Torder:public order//堂食
{
     
};

class Worder:public order//外卖
{

};
//===============================================================================
class Rsystem
{
    private:
        menu menus[MAX];
        order orders[MAX];
        int dishcount;
        int ordercount;
        string username="admin";
        string password="123456";

        void load()
        {
            ifstream file("menusss.txt");
            dishcount=0;

            if(file.is_open())
            {
                while(file>>menus[dishcount].number>>ws&&getline(file,menus[dishcount].name,',')&&file>>menus[dishcount].price>>menus[dishcount].discount)
                {
                    dishcount++;
                    if(dishcount>=MAX)
                    {
                        break;
                    }
                }
                file.close();
            }
        }

        void save()
        {
            ofstream file("menusss.txt");
            if(file.is_open())
            {
                for(int i=0;i<dishcount;i++)
                {
                    file<<menus[i].number<<" "<<menus[i].name<<","<<menus[i].price<<" "<<menus[i].discount<<endl;
                }
                file.close();
            } 
        }
        
        bool login()
        {
            string pass,user;
            cout<<"请输入管理员账号:";
            cin>>user;
            if(user==username)
            {
                cout<<"请输入管理员密码:";
                cin>>pass;
                if(pass==password)
                {
                    return true;
                }
                else
                {
                    cout<<"密码错误！"<<endl;
                    return false;
                }
            }
            else
            {
                cout<<"不存在该账号！"<<endl;
                return false;
            }
        }

    public:
        Rsystem():dishcount(0),ordercount(0)
        {
            load();
        }

        ~Rsystem()
        {
            save();
        }

        int find(int num)
        {
            for(int i=0;i<dishcount;i++)
            {
                if(menus[i].number==num)
                {
                    return i;
                }
            }
            return -1;
        }

        void sort() 
        {
        for (int i = 0; i < dishcount - 1; i++) 
        {
            for (int j = 0; j < dishcount - i - 1; j++) 
            {
                if (!(menus[j] < menus[j + 1])) 
                {
                    menu temp = menus[j];
                    menus[j] = menus[j + 1];
                    menus[j + 1] = temp;
                }
            }
        }
        }
//---------------------------------------------------------------------------------------
        void displayalldish()//展示菜单全部
        {
            if(dishcount==0)
            {
                cout<<"菜单中没有菜品！"<<endl;
                return;
            }
            sort();
            cout<<"============菜单============"<<endl;
            for(int i=0;i<dishcount;i++)
            {
                menus[i].coutmenu();
            }
        }
        
        void adddish()//增加菜品信息
        {
            int count;
            cout<<"请输入要增加的菜品信息数量:"<<endl;
            cin>>count;
            
            if((count+dishcount)>MAX)
            {
                cout<<"超出最大限制！添加失败！"<<endl;
                return;
            }

            for(int j=0;j<count;j++)
            {
                cout<<"请输入第"<<j+1<<"个菜品的信息:"<<endl;
                int n;string nm;double p;double d;
                cout<<"编号:";
                cin>>n;
                cout<<"菜名:";
                cin.ignore();
                getline(cin,nm);
                cout<<"价格:";
                cin>>p;
                cout<<"折扣:";
                cin>>d;

                menus[dishcount++]=menu(n,nm,p,d);
                menus[dishcount-1].outfile("menusss.txt");
            }

            cout<<"录入完成!"<<endl;
            displayalldish();
        }
        
        void changedish()//菜品修改
        {
            int n;
            cout<<"请输入要修改的菜品的编号："<<endl;
            cin>>n;
            int i=find(n);

            if(find(n)==-1)
            {
                cout<<"不存在此菜品！"<<endl;
                return;
            }

            cout<<"当前菜品信息："<<endl;
            menus[i].coutmenu();
            
            cout<<"请输入新的菜品信息"<<endl;
            cout<<"菜品名：";
            cin.ignore();
            getline(cin,menus[i].name);
            cout<<"价格：";
            cin>>menus[i].price;
            cout<<"折扣：";
            cin>>menus[i].discount;

            cout<<"修改成功"<<endl;
            save();
        }

        void deletedish()//菜品删除
        {
            int n,confirm;
            cout<<"请输入要删除的菜品的编号：";
            cin>>n;
            
            if(find(n)==-1)
            {
                cout<<"不存在此菜品！"<<endl;
                return;
            }
            int i=find(n);
            cout<<"将要删除菜品的信息："<<endl;
            menus[i].coutmenu();

            cout<<"确认删除？(按1确认,其他键取消)"<<endl;
            cin>>confirm;
            if(confirm==1)
            {
                for(int j=i;j<dishcount-1;j++)
                {
                    menus[i]=menus[i+1];
                }
                dishcount--;
                cout<<"删除成功"<<endl;
                save();
            }
            else
            {
                cout<<"已取消操作"<<endl;
                return;
            }
        }
   
        void searchdish()//菜品查找
        {
            int choice;
            bool r=1;
            while(r)
            {
            cout << "请选择查询方式:"<<endl;
            cout << "1. 按编号查询"<<endl;
            cout << "2. 按名称查询"<<endl;
            cout << "3. 按价格范围查询"<<endl;
            cout << "4. 按折扣范围查询"<<endl;
            cout << "0. 返回上一级"<<endl;
            cout << "请选择(0-4): ";
            cin>>choice;

            switch(choice)
            {
                case 1:
                {
                    int n;
                    cout<<"请输入菜品编号:";
                    cin>>n;
                    if(find(n)==-1)
                    {
                        cout<<"没有你要找的菜品！"<<endl;
                        return;
                    }
                    else
                    {
                        int i=find(n);
                        menus[i].coutmenu();
                    }
                    break;
                }
                case 2:
                {
                    string nm;
                    cout<<"请输入菜品名称:";
                    cin>>nm;
                    cin.ignore();
                    getline(cin,nm);
                    for (int i = 0; i < dishcount; i++) 
                    {
                    if (menus[i].name.find(nm) != string::npos) 
                    {
                        menus[i].coutmenu();
                    }
                    }
                    break;                    
                }
                case 3:
                {
                    double maxprice,minprice;
                    cout<<"请输入最大价格:";
                    cin>>maxprice;
                    cout<<"请输入最小价格:";
                    cin>>minprice;

                    for(int i=0;i<dishcount;i++)
                    {
                        if(menus[i].price<=maxprice&&menus[i].price>=minprice)
                        {
                            menus[i].coutmenu();
                        }
                    }
                    break;
                }
                case 4:
                {
                    double maxdiscount,mindiscount;
                    cout<<"请输入最大折扣:";
                    cin>>maxdiscount;
                    cout<<"请输入最小折扣:";
                    cin>>mindiscount;
                    
                    for(int j=0;j<dishcount;j++)
                    {
                        if(menus[j].discount<=maxdiscount&&menus[j].discount>=mindiscount)
                        {
                            menus[j].coutmenu();
                        }
                    }
                }
                case 0:
                {
                    r=0;
                    break;
                }
                default:
                {
                    cout<<"无效的选择！"<<endl;
                    break;
                }
            }                
            }
        }

        void userselect()//选择身份
        {
            bool r=1;
            int role;
            while(r)
            {
            cout<<"------------\n请选择您的身份(按其他任意键退出):"<<endl;
            cout<<"1.管理员"<<endl;
            cout<<"2.顾客\n------------"<<endl;
            cin>>role;

            if(role==1)
            {
                if(login()==1)
                {
                    cout<<"您已进入管理员界面！"<<endl;
                    admin();
                }
                else
                {
                    userselect();
                }
            }
            else if(role==2)
            {
                cout<<"您已进入顾客界面，欢迎光临！"<<endl;
                customer();
            }
            else
            {
                r=0;
                break;
            }                 
            }
        }

        void admin()//管理员
        {
            bool r=1;
            int choice;

            while(r)
            {
            cout<<"------------\n请选择操作:"<<endl;
            cout<<"1.查找订单"<<endl;
            cout<<"2.修改订单"<<endl;
            cout<<"3.删除订单"<<endl;
            cout<<"4.菜品增加"<<endl;
            cout<<"5.菜品修改"<<endl;
            cout<<"6.菜品删除"<<endl;
            cout<<"7.菜品查找"<<endl;
            cout<<"8.销售情况统计"<<endl;
            cout<<"9.菜单信息全部展示"<<endl;
            cout<<"0.退出\n------------"<<endl;
            cin>>choice;
            switch(choice)
            {
                case 1:
                {

                }
                case 2:
                {

                }
                case 3:
                {

                }
                case 4:
                {
                adddish();
                break;
                }
                case 5:
                {
                changedish();
                break;
                }
                case 6:
                {
                deletedish();
                break;
                }
                case 7:
                {
                searchdish();
                break;
                }
                case 8:
                {

                }
                case 9:
                {
                displayalldish();
                break;
                }
                case 0:
                {
                    r=0;
                    break;
                }
                default:
                {
                    cout<<"无效选择!"<<endl;
                    break;
                }                 
            }
            }             
        }
            
        void customer()//顾客
        {
            bool r=1;
            int choice;
            while(r)
            {
                cout<<"请看菜单点餐~"<<endl;
                displayalldish();
                //----

                //----                
                cout<<"请选择消费方式:"<<endl;            
                cout<<"1.堂食\n2.外卖\n3.返回上级"<<endl;
                cin>>choice;
                switch(choice)
                {
                    case 1:
                    {

                    }
                    case 2:
                    {
                    
                    }
                    case 3:
                    {
                        r=0;
                        break;
                    }
                    default:
                    {
                        cout<<"无效选择！"<<endl;
                        break;
                    }                
                }
            }  
        }
};


int main()
{
    Rsystem a;
    a.userselect();
    return 0;
}
