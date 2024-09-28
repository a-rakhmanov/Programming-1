// ******************************************
// ******************************************
// * *
// * Function Name: Assignment 5 *
// * Author: Anna Rakhmanov *
// * Date: July 13, 2023 *
// * Function Parameters: input.dat *
// * Description: takes in information from a file*
// * reads it to an array and prints and analyzes data*
// * References: roster structure given on canvas,*
// * bubble sort algorithm in textbook*
// ******************************************
// ******************************************

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Roster {
    string LName;
    string FName;
    int age;
    char gender;  // M=Male, F=Female, N=Non Specified
    char opinion; // Y=Yes, N=No
};

string fileValidity();
int checkSize(fstream &);
void assignData(Roster*, fstream &, int);
void printData(Roster*, int);
void summary(Roster*, int);

int main()
{
    string fileName;
    int size;
    Roster *MyRoster;

    //opens file for input and output
    fileName=fileValidity();
    fstream userFile(fileName, ios::in);
    //sets size to number of lines in the file
    size=checkSize(userFile);
    userFile.close();
    //clears file and sets to beginning
    userFile.clear();
    userFile.seekg(0, ios::beg);

    userFile.open(fileName);
    MyRoster = new Roster[size];
    assignData(MyRoster,userFile, size);
    userFile.close();
    printData(MyRoster, size);
    summary(MyRoster, size);
    return 0;
}

//checks if selected file opens
string fileValidity()
{
    string fileName;
    ifstream fileCheck;
    bool success=false;
    while(success==false)
    {
        cout << "What file would you like to open?" << endl;
        cin>>fileName;
        //checks if file opens
        fileCheck.open(fileName);
        //if file opens, ends program, if file does not, prompts user for a new file
        if (fileCheck.fail())
        {
            cout<<"Please enter a valid file name"<<endl;
        }
        else
        {
            success=true;
        }
        fileCheck.close();
    }
    return fileName;
}

//determines number of lines in selected file
int checkSize(fstream &input){
    int count=0;
    string data;
    while(getline(input,data))
    {
        count++;
    }
    return count;
}

//reads data into array, organizes array alphabetically by last name
void assignData(Roster *Array, fstream &data, int size) {
    bool swap;
    Roster temp;
    //reads data into each roster
    for(int count = 0; count < size; count++){
        data >> Array[count].LName;
        data >> Array[count].FName;
        data >> Array[count].age;
        data >> Array[count].gender;
        data >> Array[count].opinion;
    }
    //alphabetizes array by last name
    do {
        swap = false;
        for (int count = 0; count < (size-1); count++) {
            if (Array[count].LName > Array[count + 1].LName) {
                temp = Array[count];
                Array[count] = Array[count + 1];
                Array[count + 1] = temp;
                swap = true;
            }
        }
    }
    while (swap);
}

//prints data and headers
void printData(Roster *data, int size){
    //prints information in grid style
    cout<<left<<setw(12)<<"LAST NAME"<<setw(13)<<"FIRST NAME"<<setw(5)<<"AGE";
    cout<<left<<setw(8)<<"GENDER"<<setw(9)<<"OPINION"<<endl;
    cout<<left<<setw(12)<<"---------"<<setw(13)<<"----------"<<setw(5)<<"---";
    cout<<left<<setw(8)<<"------"<<setw(9)<<"-------"<<endl;
    for(int count=0; count<size; count++){
        cout<<left<<setw(12)<<data[count].LName;
        cout<<left<<setw(13)<<data[count].FName;

        cout<<left<<setw(5)<<data[count].age;
        if(data[count].gender=='M')
        {
            cout << left << setw(8) << "Male";
        }
        else
        {
            cout << left << setw(8) << "Female";
        }
        if(data[count].opinion=='Y')
        {
            cout<<left<<setw(9)<<"Yes";
        }
        else
        {
            cout<<left<<setw(9)<<"No";
        }
        cout<<endl;
    }
}

//prints summary of data
void summary(Roster*data, int size){
    int participants=size, men=0, women=0, yeses=0;
    double avgAge=0;
    //sums ages
    for(int count=0;count<size;count++){
        avgAge+=data[count].age;
    }
    //averages ages
    avgAge=avgAge/size;
    for(int count=0;count<size;count++){
        //sums number of men
        if(data[count].gender=='M'){
            men+=1;
        }
        //sums number of women
        if(data[count].gender=='F'){
            women+=1;
        }
    }
    for(int count=0;count<size;count++){
        //sums number of yeses
        if(data[count].opinion=='Y'){
            yeses+=1;
        }
    }
    //prints summary
        cout << "There were " << participants << " participants in this survey." << endl;
        cout << "The average age of participants was " << avgAge << endl;
        cout << men << " men and " << women << " women took this survey. " << size - men - women << " participants";
        cout << " did not specify their gender." << endl;
        cout << yeses << " said yes, there was room for Jack, while " << size - yeses << " said there was not." << endl;


}