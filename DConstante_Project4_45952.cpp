/*Instructor: Professor Kayed
Project 4 (including functions, loops, if/else)
Description: This program will ask  user for their name, # of employees
# of days each employee missed, the average of days all the employees missed and store that data in a
file. After that it will display the values of employee id's along with the days they missed and the
average from the file.
Due Date : July 31, 2022
I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here : Damaris Constante
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//Global variables
double numEmployees;
int employeeID;
int daysMissed;
double totalDaysMissed=0;
//protoypes
void numOfEmployees();
void totDaysAbsent();
double averageAbsent(double totalDaysMissed,double numEmployees);
//Global file variable
ofstream employeeAbsencesTxt ("employeeAbsences.txt.");

//first main function
int main(){
    string employer;
    cout<<"Please enter your name: ";
    getline(cin, employer);
//call other functions
    numOfEmployees();
//File header
    employeeAbsencesTxt<<"    EMPLOYEE ABSENCE REPORT"<<endl<<
    "Employee ID       Days Absent "<<endl;
//Function to input employee id info and days missed then write into employeeAbsences.txt file.
    totDaysAbsent();
//Write total number of days missed and average days missed into employeeAbsences.txt file.
    double average;
    average = averageAbsent(totalDaysMissed, numEmployees);
    employeeAbsencesTxt<<endl<<"Employeer:"<<employer<<endl<<"The "<<numEmployees<<" employees were absent a total of "
    <<totalDaysMissed<<" days."<<endl<<"The average number of days absent is "<<setprecision(2)<<fixed<<average<<" days.";
 //Ending message: info was saved, programmer name, due date, and project number.
    cout<<endl<<"Your information was saved to employeeAbsences.txt file."<<endl;
    const string PROGRAMMER="Damaris Constante";
    cout<<endl<<"PROGRAMMER: "<<PROGRAMMER<<endl<<"Due date: July 31, 2022"<<endl<<"Project 4"<<endl;
    return 0;
}
//second function
void numOfEmployees(){
    cout<<"How many employees do you have: ";
    cin>>numEmployees;
//input validation: num of employees can't be less than one ask to input again.
    while (numEmployees<1){
        cout<<endl<<"The number of Employees can not be less than 1."<<endl<< "Please enter the number of employees again:";
        cin>>numEmployees;
    }
}
//Third function
void totDaysAbsent(){
    int count=0;
    do{
        cout<<endl<<"What is the employee ID: ";
        cin>>employeeID;
        //read in employee id into file
        employeeAbsencesTxt<<"   "<<employeeID<<"                ";
        cout<<"How many days did this employee miss this year?: ";
        cin>>daysMissed;
        //writes days missed into file only if it is greater than or equal to 0.
        if (daysMissed>=0){
        employeeAbsencesTxt<<daysMissed<<endl;
        totalDaysMissed+=daysMissed;//accumulator
        }
        
        //input validation: days missed can not be negative ask to input again.
        while (daysMissed<0){
            cout<<endl<<"Days missed can not be negative number."<<endl<< "Please enter days missed again: ";
            cin>>daysMissed;
            employeeAbsencesTxt<<daysMissed<<endl;
            totalDaysMissed+=daysMissed;//accumulator
        }
        count++;
    }
    while (numEmployees>count);
}
//Forth function
double averageAbsent(double totalDaysMissed,double numEmployees){
    return totalDaysMissed/numEmployees;
}
    
