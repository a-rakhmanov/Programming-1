//
// Created by Anna Rakhmanov on 7/23/23.
//
#include "dice.h"
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void dieFace(int);

// ********************************************************************
// Sets throws to DEFAULTTHROWS, clears the dice values, sets sum to  *
// zero, seeds the random number generator with time(0)               *
// ********************************************************************
Dice::Dice()
{
    throws=DEFAULTTHROWS;
    unsigned int mySeed=time(0);
    srand(mySeed);
    ClearDice();
}

// ********************************************************************
// Calls SetThrows(const int t), clears the dice values, sets sum to  *
// zero, seeds the random number generator with time(0)               *
// ********************************************************************
Dice::Dice(const int t)
{
    SetThrows(t);
    unsigned int mySeed=time(0);
    srand(mySeed);
    ClearDice();
}

// ********************************************************************
// Rolls the dice the number of throws and fills the dice_values      *
// array with the numbers from a random number generator.             *
// ********************************************************************
void Dice::Roll(){
    sum=0;
    for(int count=0; count<throws; count++)
    {
        dice_values[count]=rand()%6+1;
        sum+=dice_values[count];
    }
}

// ********************************************************************
// Prints out the dice that were rolled in order.                     *
// ********************************************************************
void Dice::PrintDice()
{
    for(int count=0; count<throws; count++)
    {
        dieFace(dice_values[count]);
        cout<<endl;
    }
    cout<<"Sum is : "<<sum<<endl;
}

// ********************************************************************
//  Set the number of dice or throws.   Checks for min and max and    *
//  rolls the dice before leaving.                                    *
// ********************************************************************
void Dice::SetThrows(const int t)
{
    throws=t;
    while(throws<MINIMUMTHROWS||throws>MAXIMUMTHROWS)
    {
        cout<<"There must be between 2 and 9 dice."<<endl;
        cout<<"The number of dice has been set to the default, "
        <<DEFAULTTHROWS<<"."<<endl;
    }
}

// ********************************************************************
// Returns the number of throws or number of dice.                    *
// ********************************************************************
int Dice::GetThrows()
{
    return throws;
}

// ********************************************************************
// Returns the current sum.                                           *
// ********************************************************************
int Dice::GetSum()
{
    return sum;
}

// ********************************************************************
// Clears dice values.                                                *
// ********************************************************************
void Dice::ClearDice()
{
    for(int count=0;count<MAXIMUMTHROWS;count++)
    {
        dice_values[count]=0;
    }
    sum=0;
}

void dieFace(int value)
{
    if(value==1)
    {
        cout<<"-------"<<endl;
        cout<<"|"<<setw(6)<<right<<"|"<<endl;
        cout<<"|"<<setw(3)<<right<<"0"<<setw(3)<<right<<"|"<<" "<<value<<" "<<endl;
        cout<<"|"<<setw(6)<<"|"<<endl;
        cout<<"-------"<<endl;
    }
    else if (value==2)
    {
        cout<<"-------"<<endl;
        cout<<"|"<<setw(5)<<left<<"0"<<"|"<<endl;
        cout<<"|"<<setw(6)<<right<<"|"<<" "<<value<<" "<<endl;
        cout<<"|"<<setw(5)<<right<<"0"<<"|"<<endl;
        cout<<"-------"<<endl;
    }
    else if (value==3)
    {
        cout<<"-------"<<endl;
        cout<<"|"<<setw(5)<<left<<"0"<<"|"<<endl;
        cout<<"|"<<setw(3)<<right<<"0"<<setw(3)<<"|"<<" "<<value<<" "<<endl;
        cout<<"|"<<setw(5)<<right<<"0"<<"|"<<endl;
        cout<<"-------"<<endl;
    }
    else if (value==4)
    {
        cout<<"-------"<<endl;
        cout<<"|"<<setw(4)<<left<<"0"<<"0"<<"|"<<endl;
        cout<<"|"<<setw(6)<<right<<"|"<<" "<<value<<" "<<endl;
        cout<<"|"<<setw(4)<<left<<"0"<<"0"<<"|"<<endl;
        cout<<"-------"<<endl;
    }
    else if (value==5)
    {
        cout<<"-------"<<endl;
        cout<<"|"<<setw(4)<<left<<"0"<<"0"<<"|"<<endl;
        cout<<"|"<<setw(3)<<right<<"0"<<setw(3)<<right<<"|"<<" "<<value<<" "<<endl;
        cout<<"|"<<setw(4)<<left<<"0"<<"0"<<"|"<<endl;
        cout<<"-------"<<endl;
    }
    else
    {
        cout<<"-------"<<endl;
        cout<<"|"<<"0"<<setw(4)<<right<<"0"<<"|"<<endl;
        cout<<"|"<<"0"<<setw(4)<<right<<"0"<<"|"<<" "<<value<<" "<<endl;
        cout<<"|"<<"0"<<setw(4)<<right<<"0"<<"|"<<endl;
        cout<<"-------"<<endl;
    }
}