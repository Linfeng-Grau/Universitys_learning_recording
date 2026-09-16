#include <iostream>
using namespace std;

int secondsFromMidnight(int hours, int minutes, int seconds) 
{
    return hours * 3600 + minutes * 60 + seconds;
}

int main() 
{
    
    int hours1 = 3; 
    int minutes1 = 45; 
    int seconds1 = 30;

    int hours2 = 15;
    int minutes2 = 30; 
    int seconds2 = 45;

    int totalSeconds1 = secondsFromMidnight(hours1, minutes1, seconds1);
    int totalSeconds2 = secondsFromMidnight(hours2, minutes2, seconds2);

    int differenceInSeconds = totalSeconds2 - totalSeconds1;

    cout << "之间的秒数为" << differenceInSeconds;

    return 0;
}