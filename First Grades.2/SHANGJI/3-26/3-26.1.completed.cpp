#include <iostream>
#include <string>
using namespace std;

//学号，姓名，各门成绩(假定三门)，总分，排序(假定从大到小)，统计不及格和优秀的人数，各分数段(假定平均分数)分别统计；

class stu
{
    private:
    int id;
    string name;
    int sc[3];
    int totalsc=0;
    int averagesc=0;

    public:
    stu(int id,string name,int sc1,int sc2,int sc3)
    {
        this->id=id;
        this->name=name;
        sc[0]=sc1;
        sc[1]=sc2;
        sc[2]=sc3;
    }
    void calculate()  //平均数&总数计算
    {
        
        for(int i=0;i<3;i++)
        {
            
            totalsc+=sc[i];
        }
        averagesc=(totalsc/3);
    }
    int getid() const//返回学号
    {
        return id;
    }
    string getname() const//返回名字
    {
        return name;
    }
    int getsc(int num) const//返回三门的分数
    {
        return sc[num];
    }
    int gettotalsc() const//返回总数
    {
        return totalsc;
    }
    int getaveragesc() const//返回平均数
    {
        return averagesc;
    }

    void point()
    {
        cout<<"学号:"<<id<<"   ";
        cout<<"姓名:"<<name<<"   ";
        cout<<"三门成绩:";
        for(int i=0;i<3;i++)
        {
            cout<<sc[i]<<"   ";
        }
        cout<<"总分:"<<totalsc<<"   ";
        cout<<"平均分"<<averagesc<<endl;
    }
};

//-----------------------------------------------------------------------

class stusystem//类系统/类组
{
    private:
    stu** stus;
    int stucount;
    int n;

    public:
    stusystem()
    {
        stus=nullptr;
        stucount=0;
    }
    ~stusystem()
    {
        for(int i=0;i<stucount;i++)
        {
            delete stus[i];
        }
        delete[] stus;
    }
    void addstu(const stu& stu1)//添加学生信息
    {
        stu** newstus=new stu*[stucount+1];
        for(int i=0;i<stucount;i++)
        {
            newstus[i]=stus[i];
        }
        newstus[stucount]=new stu(stu1);

        delete[] stus;

        stus=newstus;
        stucount++;
    }


    void sorts()//从大到小排序
    {
        for(int i=0;i<stucount-1;i++)
        {
            for(int j=0;j<stucount-i-1;j++)
            {
                if(stus[j]->gettotalsc()<stus[j+1]->gettotalsc())
                {
                    stu* temp=stus[j];
                    stus[j]=stus[j+1];
                    stus[j+1]=temp;
                }
            }
        }
        cout<<"排序成功!"<<endl;
    }

    int countfall()//计算不及格(如有一科及以上小于60分)
    {
        int count=0;
        for(int i=0;i<stucount;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(stus[i]->getsc(j)<60)
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }

    int countexce()//计算优秀(每科均90分以上)
    {
        int count=0;
        for(int i=0;i<stucount;i++)
        {
            bool is=1;
            for(int j=0;j<3;j++)
            {
                if(stus[i]->getsc(j)<90)
                {
                    is=0;
                    break;
                }
            }
            if(is)
            {
                count++;
            }
        }
        return count;
    }

    void countranges()//各个分数段统计(每人均分排序)
    {
        int range[5]={0};
        for(int i=0;i<stucount;i++)
        {
            int averagesc=stus[i]->getaveragesc();
            if(averagesc>=90)
            {
                range[0]++;
            }
            else if(90>averagesc&&averagesc>=80)
            {
                range[1]++;
            }
            else if(70<=averagesc&&averagesc<80)
            {
                range[2]++;
            }
            else if(60<=averagesc&&averagesc<70)
            {
                range[3]++;
            }
            else if(averagesc<60)
            {
                range[4]++;
            }
        }
        for(int j=0;j<5;j++)
        {
            cout<<(9-j)*10<<"-"<<(10-j)*10<<"分:"<<range[j]<<"人"<<endl;
        }
    }

    void showallstu()//显示所有学生信息
    {
        for(int i=0;i<stucount;i++)
        {
            stus[i]->point();
        }
    }

    int getstucount()const//获取输入的总学生数量
    {
        return stucount;
    }
};

int main()
{
    stusystem stusystem;
    int choice;

    while(1)
    {
        cout<<"请选择功能:"<<endl;
        cout<<"1.添加学生信息"<<endl;
        cout<<"2.从大到小排序"<<endl;
        cout<<"3.不及格(有一科小于60分)"<<endl;
        cout<<"4.优秀(每科均90分以上)"<<endl;
        cout<<"5.各个分数段统计(每人均分排序)"<<endl;
        cout<<"6.显示所有学生信息"<<endl;
        cout<<"0.退出"<<endl;
        cout<<"请输入你的选择:";
        cin>>choice;
        
        if(choice==0)
        {
            return 0;
        }
        else if(stusystem.getstucount()==0&&choice!=1)
        {
            cout<<"检测到无学生信息,自动跳到录入学生信息功能."<<endl;
            choice=1;
        }

        switch(choice)
        {
            case 1:
            {
                int id;
                string name;
                int sc1,sc2,sc3;
                cout<<"请输入学生学号:";
                cin>>id;
                cout<<"请输入学生姓名:";
                cin>>name;
                cout<<"请输入学生三门成绩:";
                cin>>sc1>>sc2>>sc3;
                stu stu1(id,name,sc1,sc2,sc3);
                stu1.calculate();
                stusystem.addstu(stu1);
                break; 
            }
            case 2:
            {
                stusystem.sorts();
                break;
            }
            case 3:
            {
                cout<<"不及格人数:"<<stusystem.countfall()<<endl;
                break;
            }
            case 4:
            {
                cout<<"优秀人数:"<<stusystem.countexce()<<endl;
                break;
            }
            case 5:
            {
                stusystem.countranges();
                break;
            }
            case 6:
            {
                stusystem.showallstu();
                break; 
            }
            default:
            {
                cout<<"ERROR!"<<endl;
                break;
            }
        }
    }
}

