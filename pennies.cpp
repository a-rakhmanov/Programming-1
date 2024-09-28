// *****************************************************************
// * Function Name: Assignment 2
// * Description: Converts pennies to most efficient use of larger
// *      denominations, up to $100 bills.
// * Date: May 29, 2023
// * Author: Anna Rakhmanov
// * COP 3014 Summer 2023
// * References: n/a
// *****************************************************************

#include <iostream>
#include <iomanip>
using namespace std;

//global constants: pennies per unit.
const int pp100d=10000;
const int pp50d=5000;
const int pp20d=2000;
const int pp10d=1000;
const int pp5d=500;
const int pp1d=100;
const int ppQuarter=25;
const int ppDime=10;
const int ppNickel=5;

int main() {
    cout<<"How many pennies do you have?"<<endl;
    cout<<"Please do not use commas."<<endl;
    int cents;
    cin>>cents;

    while (cents>1000000 || cents<1)
    {
        cout << "Please enter a number from 1 to 1,000,000." << endl;
        cin>>cents;
    }

    cout<<"Your pennies are equivalent to:"<<endl;

    //gives # of $100 bills that can be made from # of pennies
    if(cents/pp100d>0)
        cout<<left<<setw(4)<<cents/pp100d<<" 100 dollar bill(s)"<<endl;
    //gives # of pennies left over after exchange for max # of bills
    int remainder = cents-(cents/pp100d)*pp100d;

    //repeated for each unit

    if(remainder/pp50d>0)
        cout<<left<<setw(4)<<remainder/pp50d<<" 50 dollar bill(s)"<<endl;
    remainder = remainder-(remainder/pp50d)*pp50d;

    if(remainder/pp20d>0)
        cout<<left<<setw(4)<<remainder/pp20d<<" 20 dollar bill(s)"<<endl;
    remainder = remainder-(remainder/pp20d)*pp20d;

    if(remainder/pp10d>0)
        cout<<left<<setw(4)<<remainder/pp10d<<" 10 dollar bill(s)"<<endl;
    remainder = remainder-(remainder/pp10d)*pp10d;

    if(remainder/pp5d>0)
        cout<<left<<setw(4)<<remainder/pp5d<<" 5 dollar bill(s)"<<endl;
    remainder = remainder-(remainder/pp5d)*pp5d;

    if(remainder/pp1d>0)
        cout<<left<<setw(4)<<remainder/pp1d<<" 1 dollar bill(s)"<<endl;
    remainder = remainder-(remainder/pp1d)*pp1d;

    if(remainder/ppQuarter>0)
        cout<<left<<setw(4)<<remainder/ppQuarter<<" quarter(s)"<<endl;
    remainder = remainder-(remainder/ppQuarter)*ppQuarter;

    if(remainder/ppDime>0)
        cout<<left<<setw(4)<<remainder/ppDime<<" dime(s)"<<endl;
    remainder = remainder-(remainder/ppDime)*ppDime;

    if(remainder/ppNickel>0)
        cout<<left<<setw(4)<<remainder/ppNickel<<" nickel(s)"<<endl;
    remainder = remainder-(remainder/ppNickel)*ppNickel;

    if(remainder>0)
        cout<<left<<setw(4)<<remainder<<" penny(s)"<<endl;

    return 0;
}
