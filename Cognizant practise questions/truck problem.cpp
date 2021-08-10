#include<iostream>
#include<stdio.h>
using namespace std;


int main()
{
    float fuel,kms;
    cout<<"Enter the no of liters to fill the tank : ";
    cin>>fuel;
    cout<<endl<<"Enter the distance covered : ";
    cin>>kms;
    if(fuel<0 || kms<0)
    cout<<endl<<"Invalid Output"<<endl;
    else
    {
        float lphundredkm = (fuel/kms)*100;
        float miles = kms*0.6214;
        float gallon = fuel*0.2642;
        float milespergallon = miles/gallon;
        //  Considered printing 4 decimal places
        printf("%0.4f Litres/100 KM",lphundredkm);
        cout<<endl;
        printf("%0.4f Miles/Gallons",milespergallon);
    }

    return 0;
}