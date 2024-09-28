// ********************************************************
// * Name: Assignment 4
// * Description:  Takes user input into an array, sorts by
// * element size, and computes average.
// * Author:  Anna Rakhmanov
// * Date: June 21, 2023
// * COP 3014 Summer 2023
// * References: Bubble Sort algorithm given on canvas
// ********************************************************
#include <iostream>
#include <iomanip>      //setprecision()
using namespace std;

void BubbleSort(float[], int);
int gatherInput();
float computeAverage(float[], int);

const int MAXARRAY = 99;
float userNumbers[MAXARRAY];

int main() {
    cout<<"Please enter between 2 and 100 positive numbers." << endl;
    cout<<"To finish, please enter '-1'."<< endl;

    int arraySize=gatherInput();

    BubbleSort(userNumbers, arraySize);

    cout<<"Here are your numbers sorted from least to greatest:"<<endl;
    for(int count=0; count <=arraySize; count++)
    {
        cout<<userNumbers[count]<<endl;
    }

    cout<<"The average of your numbers is: "<<endl;
    cout<<setprecision(4)<<fixed<<showpoint<<computeAverage(userNumbers, arraySize);
}

//creates array from user input elements and outputs # of non-zero elements
int gatherInput() {
    int userInput=0;
    int count;
    int arraySize=100;
    for(count=0; count<=99 && userInput>=0; count++)
    {
        cin>>userInput;
        if (userInput>=0)
        {
            userNumbers[count]=userInput;
        }
        else
        {
            //designates how many elements have non-zero values
            arraySize = count - 1;
        }
    }
    return arraySize;
}

// ********************************************************
// * Name: BubbleSort                                     *
// * Description:  Accepts an array as a parameter of     *
// *   type integer and sorts the array using the         *
// *   standard Bubble Sort algorithm.  Compares          *
// *   adjacent values on a pass through the array.       *
// *   if an exchange is made it goes through the array   *
// *   again.                                             *
// * Author:  Dr. David A. Gaitros                        *
// * Date: November 25th, 2022                            *
// * Copyright: For use for educational purposes only.    *
// *   Students must include these comments in the code   *
// *   when using this routine.                           *
// ********************************************************
void BubbleSort(float a[MAXARRAY], const int size)
{
    bool swapped= true;
    int holder;
    while(swapped)
    {
        swapped=false;
        for (int index=0; index<size-1; index++)
        {
            if(a[index] > a[index+1])
            {
                holder=a[index];
                a[index]=a[index+1];
                a[index+1] = holder;
                swapped=true;
            }
        }
    }
}

float computeAverage(float inputArray[MAXARRAY],int arraySize){
    float total=0;
    //sums non-zero array elements
    for(int count=0; count<=arraySize; count++)
    {
        total += inputArray[count];
    }
    float average = total/(arraySize+1);
    return average;
}
