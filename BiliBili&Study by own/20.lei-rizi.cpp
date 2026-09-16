#include <iostream>
using namespace std;

//以下是使用 类 的一个实例，用类编写一个日志用于报错、警告和信息.

class log//定义日志类
{
public:
    const int LogLevelError=0;//定义了三个常量，分别是Error、Warning、Info，并分别赋值为0、1、2。
    const int LogLevelWarning=1;
    const int LogLevelInfo=2;
private:
    int m_LogLevel=LogLevelInfo;
public:
    void SetLevel(int level)//设置日志级别，保证只会输出比当前级别高的日志。
    {
        m_LogLevel=level;
    }
    void Error(const char* message)
    {
        if(m_LogLevel>=LogLevelError)//如果当前日志级别大于等于Error，则输出Error，以下同理。
            cout<<"[ERROR]: "<<message<<"\n";
    }
    void Warn(const char* message)
    {
        if(m_LogLevel>=LogLevelWarning)
            cout<<"[WARNING]: "<<message<<"\n";
    }
    void Info(const char* message)
    {
        if(m_LogLevel>=LogLevelInfo)
            cout<<"[INFO]: "<<message<<"\n";
    }
};

int main()
{
    log log;
    log.SetLevel(log.LogLevelError);//设置日志级别为Error(则只输出Error)。如果级别为warning，则只输出Warning和Error。
    log.Error("ERROR!");            //顺序为Info>Warning>Error。（由它们的赋值大小决定的）
    log.Warn("WARNING!");
    log.Info("INFO!");
    return 0;
}

// 类

// *在专业中不建议如此使用.  