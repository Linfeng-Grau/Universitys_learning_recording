cout<<"您已进入预扣纳税方案模式\n"<<"请计算您的本月的收入总额（元）\n"<<"请输入您的月度收入：";
cin>>YSR;

while(1)
{
    if(YSR<=0)
    {
        cout<<"输入非法！请重新输入：";
        cin>>YSR;
    }
    else
    {
        break;
    }
}


cout<<"请输入您的专项扣除总额：";
cin>>ZXKC;

YNSE=YSR-5000-ZXKC;

if(YNSE<=0)
{
    cout<<"根据相关法律法规，您不满足纳税条件，本月不需要纳税。\n"; 
    NS=0.00;   
}
else if(YSR<5000)
{
    NS=0.00;
}
else if(5000<YSR<=8000)
{
    NS=YNSE*0.03;
}
else if(8000<YSR<=17000)
{
    NS=YNSE*0.10;
}
else if(17000<YSR<=30000)
{
    NS=YNSE*0.20;
}
else if(30000<YSR<=40000)
{
    NS=YNSE*0.25;
}
else if(40000<YSR<=60000)
{
    NS=YNSE*0.30;
}
else if(60000<YSR<=85000)
{
    NS=YNSE*0.35;
}
else if(85000<YSR)
{
    NS=YNSE*0.40;
}

YSHSR=(YSR-NS-ZXKC);

