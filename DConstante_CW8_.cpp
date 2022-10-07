/*Instructor: Professor Kayed
Classwork 8
Description: This program will let the user enter up to 50 numbers and sort those numbers,find the minimum,
find the maximum, and find the average of those numbers and display the results.
Due Date : August 8, 2022
I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here : Damaris Constante
*/

#include <iostream>
#include <iomanip>
using namespace std;
//Function prototypes
void displayArray(int[],int); //Displays contents of array
void selectionSort(int array[],int size); //sorts array in decending order
void swap(int &a,int &b);//Function for for selection sort
int findMax (int array[],int size);//finds and returns hghest element in array
int findMin(int array[],int size);//finds and returns lowest element in array
double findAvg(int array[],int size);//finds and returns avergae of elements in array

//GLOBAL VARIABLES
const int MAX_ELEMENTS=50;

int main(){
    //Varibales used
    int scores;
    int numberCount=1;
    int array[MAX_ELEMENTS];
    //Get array elements from user
    cout<<"How many scores do you want to enter?: ";
    cin>>scores;
    int size=scores;
    for (int a=0;a<scores;a++){
        cout<<"Enter score #"<<numberCount<<":";
        cin>>array[a];
        numberCount++; //increase number count
    }
    //Call function to display original array
    displayArray(array,size);
    //Call function to display array in order
    selectionSort(array,size);
    cout<<endl<<"Scores ordered high to low: ";
    for (int a=0;a<size;a++){
        cout<<array[a]<<" ";
    }
    //Show max
    cout<<endl<<"Highest score is: "<<findMax(array,size);
    //Show min
    cout<<endl<<"Lowest score is: "<<findMin(array,size);
    //Show average
    cout<<endl<<"Average of scores is: "<<setprecision(1)<<fixed<<findAvg(array,size)<<endl;
    //End function
    return 0;
}
//Function that displays the orginal order of array + the size of the array they entered
void displayArray(int array[],int size){
    cout<<endl<<"Original order of your "<<size<<" scores are: ";
    for(int b=0;b<size;b++){
        cout<<array[b]<<"  ";
    }
}
//Function that sorts array using selection sort algorithm in descending order
void selectionSort(int array[],int size){
    int minIndex, minValue;
    for (int start=0;start<(size-1);start++){
        minIndex=start;
        minValue=array[start];
        for(int index=start+1;index<size;index++){
            if (array[index]>=minValue){
                minValue=array[index];
                minIndex=index;
            }
        }
        swap(array[minIndex], array[start]);
    }
    
}
//Function for selectionSort to swap values
void swap(int &b, int&a){
    int temp=b;
    b=a;
    a=temp;
}
//Function that finds the max of the array and returns the int
int findMax(int array[],int size){
    int max=array[0];
    for(int a=1;a<size;a++){
        if (array[a]>max){
            max=array[a];
        }
    }
    return max;
}
//Function that finds the min of the array and returns the int
int findMin(int array[],int size){
    int min=array[0];
    for(int a=1;a<size;a++){
        if (array[a]<min){
            min=array[a];
        }
    }
    return min;
}

//Function that finds the average of the array and returns the double
double findAvg(int array[],int size){
    double acc=0;//accumulator
    for(int a=0;a<size;a++){
        acc+=array[a];
    }
    double avg=acc/size;
    return avg;
}
