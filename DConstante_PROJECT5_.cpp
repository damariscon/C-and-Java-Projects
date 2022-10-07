/*Instructor: Professor Kayed
Project 5
Description: This program will allow the user to input 9 numbers and will
tell the user if the numbers inputted make a magic square or not
Due Date : August 7, 2022
I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here : Damaris Constante
*/

#include<iostream>
using namespace std;

// Global constants
const int ROWS = 3;  // The number of rows in the array
const int COLS = 3;  // The number of columns in the array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

// Function prototypes
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int[], int[], int[], int);
bool checkUnique(int[], int[], int[], int);
bool checkRowSum(int [], int[], int[], int);
bool checkColSum(int[], int[], int[], int);
bool checkDiagSum(int[], int[], int[], int);
void showArray(int [], int[], int[], int);

int main()
{
    //intro
    cout<<"This program will tell you if you have a Lo Shu magic square when you enter 9 numbers."<<endl<<endl;
    //Ask user to enter row 1,2, and 3. insert numbers into array
    //Row1
    int size=3;
    int arrayRow1[size];
    for (int a=0; a<size; a++){
        cout<<"Enter number "<<a<<" for row 1: ";
        cin>>arrayRow1[a];
    }
    cout<<endl;
    //Row 2
    int arrayRow2[size];
    for (int b=0; b<size; b++){
        cout<<"Enter number "<<b<<" for row 2: ";
        cin>>arrayRow2[b];
    }
    cout<<endl;
    //Row 3
    int arrayRow3[size];
    for (int c=0; c<size; c++){
        cout<<"Enter number "<<c<<" for row 3: ";
        cin>>arrayRow3[c];
    }
//Call functions
    showArray(arrayRow1,arrayRow2,arrayRow3,size); //working
    checkRange(arrayRow1,arrayRow2,arrayRow3,size); //working
    checkUnique(arrayRow1,arrayRow2,arrayRow3,size); //working
    checkRowSum(arrayRow1,arrayRow2,arrayRow3,size); //working
    checkColSum(arrayRow1,arrayRow2,arrayRow3,size); //working
    checkDiagSum(arrayRow1,arrayRow2,arrayRow3,size);//working
    isMagicSquare(arrayRow1,arrayRow2,arrayRow3,size);//working
//Tell user if the numbers entered is magic square
    if (isMagicSquare(arrayRow1,arrayRow2,arrayRow3,size)==true){
        cout<<endl<<"This is a Lo Shu magic square.";
    }
    else if (isMagicSquare(arrayRow1,arrayRow2,arrayRow3,size)==false){
        cout<<endl<<endl<<"This is not a Lo Shu magic square.";
    }
//Ending message with programmer name, due date, and project #
    cout<<endl<<endl<<"PROGRAMMER NAME: Damaris Constante"<<endl
    <<"Due date: August 8, 2022"<<endl<<"Project #: 5"<<endl;
//End program
        return 0;
}
//Function to show magic square
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size){
    cout<<endl;
    //print row 1
    for (int d=0;d<size;d++){
        cout<<arrayRow1[d]<<" ";
    }
    //go to next line
    cout<<endl;
    //print row 2
    for (int e=0;e<size;e++){
        cout<<arrayRow2[e]<<" ";
    }
    //go to next line
    cout<<endl;
    //print row 3
    for (int f=0;f<size;f++){
        cout<<arrayRow3[f]<<" ";
    }
}
//Check the range of integers entered for array 1, 2, and 3. Make sure the numbers arew within 1-9 if yes return true if not return false.
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size){
    bool status=true;
    for (int a=0;a<size;a++){
        if (arrayRow1[a]>=MIN && arrayRow1[a]<=MAX){
            status= true;
        }
        else
            status= false;
    }
    for (int b=0;b<size;b++){
        if (arrayRow2[b]>=MIN && arrayRow2[b]<=MAX){
            status= true;
        }
        else
            status=false;
    }
    for (int c=0;c<COLS;c++){
        if (arrayRow3[c]>=MIN && arrayRow3[c]<=MAX){
            status= true;
        }
        else
            status= false;
    }
    //return true or false
    return status;
}
//check if numbers only occure once return true if yes return false is they occur more than once
bool checkUnique(int arrayRow1[],int arrayRow2[],int arrayRow3[],int size){
    for (int a=0;a<size;a++){
        if (arrayRow1[a]==arrayRow2[a]|| arrayRow1[a]==arrayRow3[a] || arrayRow2[a]==arrayRow3[a]){
            return false;
        }
    }
    return true;
}
//Function to check the sum of the rows
bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size){
    int sum1=0;
    int sum2=0;
    int sum3=0;
    int allSum=0;
    for (int a=0; a<ROWS; a++){
        sum1+=arrayrow1[a];
        sum2+=arrayrow2[a];
        sum3+=arrayrow3[a];
    }
    if (sum1!=sum2 || sum1!=sum3 || sum2!=sum3){
        allSum=false;
    }
    else if (sum1==sum2 || sum1==sum3 || sum2==sum3){
        allSum=true;
    }
    return allSum;
}
//Function to check the sum of the coloumns
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size){
    bool result;
    int sum1;
    int sum2;
    int sum3;
    sum1=arrayrow1[0]+arrayrow2[0]+arrayrow3[0];
    sum2=arrayrow1[1]+arrayrow2[1]+arrayrow3[1];
    sum3=arrayrow1[2]+arrayrow2[2]+arrayrow3[2];
    if (sum1==sum2 && sum2==sum3 && sum1==sum3){
        result= true;
    }
    else
        result= false;
    return result;
}
//Function to check the sum of the diagnal
bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size){
    int result;
    int sum1;
    int sum2;
    sum1=arrayrow1[0]+arrayrow2[1]+arrayrow3[2];
    sum2=arrayrow1[2]+arrayrow2[1]+arrayrow3[0];
    if(sum1==sum2){
        result=true;
    }
    else
        result=false;
    return result;
}
//Function returns true if all other functions return true
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size){
    if (checkColSum(arrayRow1,arrayRow2,arrayRow3,size)==true && checkRowSum(arrayRow1,arrayRow2,arrayRow3,size)==true && checkUnique(arrayRow1,arrayRow2,arrayRow3,size)==true && checkDiagSum(arrayRow1,arrayRow2,arrayRow3,size)==true && checkRange(arrayRow1,arrayRow2,arrayRow3,size)==true){
        return true;
    }
    else
    return false;
}
