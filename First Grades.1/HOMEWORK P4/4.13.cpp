#include <iostream>
using namespace std;

int main() 
{
    double milesDriven, gallonsUsed, totalMiles = 0, totalGallons = 0, mpg, overallMpg = 0;

    cout << "Enter miles driven and gallons used (-1 to quit): \n";

    while (1) 
    {
        cout<<"Enter milesDriven:";
        cin >> milesDriven;

        if (milesDriven== -1) 
        {
            break;
        }
        
        cout<<"Enter gallonsUsed:";
        cin >> gallonsUsed;

        if (gallonsUsed == 0) 
        {
            cout << "Gallons used cannot be zero. Please try again.";
            continue;
        }

        mpg = milesDriven / gallonsUsed;
        totalMiles += milesDriven;
        totalGallons += gallonsUsed;

        cout << "MPG for this trip: " << mpg<<"\n";

        if (totalGallons > 0) 
        {
            overallMpg = totalMiles / totalGallons;
            cout << "Total MPG: " << overallMpg<<"\n";
        } else 
        {
            cout << "Overall MPG: Not available yet.";
        }

        cout << "Enter miles driven and gallons used (-1 to quit)\n ";
    }

    cout<<"Finished";
    return 0;
}