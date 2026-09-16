#include <iostream>
#include <iomanip>
using namespace std;

double calculateCharges(double hours) 
{
    double charge = 0.0;
    int Ahours = (hours - 3);
    if(hours < 0)
    {
        charge = 0.0;
    }
    else if (0 < hours <= 3) 
    {
        charge = 2.00;
    } 
    else if (3 < hours <= 24) 
    {
        charge = 2.00 + (Ahours+1) * 0.50;
    } 
    else if(hours > 24) 
    {
        charge = 10.00;
    }
    return charge;
}

int main() 
{
    double hours[3];
    double charges[3];
    double totalCharge = 0.0;
    double totalhours = 0.0;


    for (int i = 0; i < 3; ++i) 
    {
        cout << "请输入第 " << i + 1 << " 辆车的停车时间（小时）: ";
        cin >> hours[i];
        charges[i] = calculateCharges(hours[i]);
        totalCharge += charges[i];
        totalhours += hours[i];
    }
    
    cout << fixed << setprecision(2);

    cout << "Car\tHours\tCharge\n";
    for (int i = 0; i < 3; ++i) 
    {
        cout << i + 1 << "\t" << hours[i] << "\t" << charges[i] <<"\n";
    }
    cout << "TOTAL\t" << totalhours << "\t" << totalCharge << "\n";

    return 0;
}