#include <iostream>
#include "dice.h"
using namespace std;
void PrintMenu();
char GetOption();
int GetNumberofDice();
const int DEFAULTDICE=4;
const int MINIMUDICE=2;
const int MAXIMUMDICE=9;

// ********************************************************************
// * Project: Object Oriented Programming Assignment *
// * Description: Use the Dice class to roll dice for any number of *
// * dice games. Allows you to throw or roll dice, reset the *
// * number of dice from 2 to 9. Review or print the last throw *
// * and show the summary of the last throw. *
// * Author: Dr. David A. Gaitros *
// * Last Modified: April 10th, 2023 *
// * Copyright: For the use by students at FSU in the COP3014 course *
// ********************************************************************
int main() {
    Dice mydice(DEFAULTDICE);
    char option;
    PrintMenu();
    option=GetOption();
    while(option !='E'&& option !='e')
    {
        switch (option)
        {
            case 'T': case 't': mydice.Roll(); mydice.PrintDice();break;
            case 'R': case 'r': mydice.SetThrows(GetNumberofDice()); mydice.Roll();
            break;
            case 'P': case 'p': mydice.PrintDice(); break;
            case 'S': case 's': cout<<"Sum is: "<< mydice.GetSum()<<endl;
            cout<<"Number of Dice is " <<
            mydice.GetThrows()<<endl<<endl<<endl; break;
            case 'E': case 'e': break;
        };
        PrintMenu();
        option=GetOption();
    }
    cout <<" Good Bye and thanks for playing"<<endl;
    return 0;
}

// ********************************************************************
// * Name: PrintMenu() *
// * Description: Print the menu for the GRADER game *
// * Author: Dr. David A. Gaitros *
// * Last Modified: April 10th, 2023 *
// * Copyright: For the use by students at FSU in the COP3014 course *
// ********************************************************************
void PrintMenu()
{
    cout <<" Generic RAndom Dice Egame Routine (GRADER)"<<endl;
    cout <<" Enter one of the options below: "<<endl;
    cout <<" -------------------------------------"<<endl;
    cout <<" | T - Throw Dice |"<<endl;
    cout <<" | R - Reset/Set number of Dice |"<<endl;
    cout <<" | P - Print the last throw again |"<<endl;
    cout <<" | S - Show Summary Data |"<<endl;
    cout <<" | E - Exit Game |"<<endl;
    cout <<" -------------------------------------"<<endl;
    cout <<endl;
    cout <<" Option: ";
}

// ********************************************************************
// * Name: GetOption() *
// * Description: Get the option T, R, P, S, or E *
// * Author: Dr. David A. Gaitros *
// * Last Modified: April 10th, 2023 *
// * Copyright: For the use by students at FSU in the COP3014 course *
// ********************************************************************
char GetOption()
{
    char option;
    cin>>option;
    while(option !='T'&& option!='t' &&option !='R' && option !='r' && option !='P'
    && option !='p' && option != 'S' && option !='s' && option !='E' && option !='e')
    {
        cout <<" | Invalid Option, Re-Enter |"<<endl;
        cout <<" -------------------------------------"<<endl;
        cout <<endl;
        cout <<" Option: ";
        cin>>option;
    }
    return option;
}

// ********************************************************************
// * Name: GetNumberofDice() *
// * Description: Return the number between 2 and 9 *
// * Author: Dr. David A. Gaitros *
// * Last Modified: April 10th, 2023 *
// * Copyright: For the use by students at FSU in the COP3014 course *
// ********************************************************************
int GetNumberofDice()
{
    int dice;
    cout <<"Enter a number between "<<MINIMUDICE<<" and "<<MAXIMUMDICE<<": ";
    cin >>dice;
    while (dice <MINIMUDICE || dice > MAXIMUMDICE)
    {
        cout <<"Invalid entry, please re-enter: ";
        cin>>dice;
    }
    return dice;
}
