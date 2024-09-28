// *****************************************************************
// * Function Name: Name_Of_Function *
// * Description: converts a range of numbers to their binary forms.
// * Date: May 31, 2023
// * Author: Anna Rakhmanov
// * COP 3014 Summer 2023
// * References: n/a
// *****************************************************************

#include <iostream>
#include<bitset>
using namespace std;

void generateBinary(int);
int checkValue(int);

int main() {
    int minimum;
    int maximum;
    cout << "This program will convert a range of integers to their binary forms. ";
    cout << "The range must be within 0 and 255." << endl;

    //loops when user prompts to go again
   for(char answer ='y'; answer=='y'||answer=='Y';)
   {
       do {
           cout << "Please enter the starting number." << endl;
           cin >> minimum;
           minimum=checkValue(minimum);

           cout << "Please enter the ending number." << endl;
           cin >> maximum;
           maximum=checkValue(maximum);

           if (minimum > maximum) {
               cout << "The starting number must be smaller than the ending number. ";
               cout << "Please reenter the numbers." << endl;
           }
       } while (minimum > maximum);

       for (int number = minimum; number <= maximum; number++)
       {
           cout<<number<<" is equivalent to ";
           generateBinary(number);
           cout<< endl;
       }
       cout<<endl;
       cout << "Would you like to go again? (Y/N)" << endl;
       cin >> answer;
   }

    cout<<"Goodbye!";

    return 0;
}

//checks validity of input; loops if input is invalid
int checkValue(int input)
{
    while (input<0 || input> 255)
        {
        cout << "The number must be between 0 and 255. ";
        cout << "Please reenter the number." <<endl;
        cin >>input;
        }
    return input;
}

//gives binary value for a base ten number
 void generateBinary(int input)
 {
    bitset<8> binaryEquivalent;
    binaryEquivalent=input;
    cout<<binaryEquivalent;
}