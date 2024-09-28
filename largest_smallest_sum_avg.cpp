// *****************************************************************
// * Function Name: Assignment 1
// * Description: finds largest value, smallest value, sum, and
// *    average of three numbers.
// * Date: May 25, 2023
// * Author: Anna Rakhmanov
// * COP 3014 Summer 2023
// * References: n/a
// *****************************************************************

#include <iostream>
using namespace std;
int main()
{
    float number1, number2, number3;

    cout<<"Please enter three numbers separated by a space."<<endl;
    cin>>number1>>number2>>number3;

    float smallestNumber;
    float largestNumber;
    //assigns largestNumber and smallestNumber for all possible permutations a>=b>=c
    //with a, b, c are the input values
    if(number1>=number2)
    {
        if(number1>=number3)
        {
            largestNumber=number1;
                    //number1>=number2>=number3
                    if(number2>=number3)
                        smallestNumber=number3;
                    //number1>=number3>=number2
                    else
                        smallestNumber=number2;
        }
        //number3>=number1>=number2
        else
        {
            largestNumber=number3;
            smallestNumber=number2;
        }
    }
    else
    {
        if(number2>=number3)
        {
            largestNumber=number2;
            //number2>=number1>=number3
            if(number1>=number3)
                smallestNumber=number3;
            //number2>=number3>=number1
            else
                smallestNumber=number1;
        }
        //number3>=number2>=number1
        else
        {
            largestNumber=number3;
            smallestNumber=number1;
        }
    }

    float sumOfNumbers;
    sumOfNumbers=number1+number2+number3;

    float averageOfNumbers;
    averageOfNumbers=(number1+number2+number3)/3;

    cout << "The largest number is " << largestNumber << "." << endl;
    cout << "The smallest number is " << smallestNumber << "." << endl;
    cout << "The sum of the numbers is " << sumOfNumbers << "." << endl;
    cout << "The average of the numbers is " << averageOfNumbers << "." << endl;
    return 0;
}
