/*Instructor: Professor Kayed
Project 3
Description: This program will ask the user to input a hotel chain location. It will than ask for the number of
 floors, and the number of rooms in each floor. Next it will show the user the total income of the hotel,total # of
 rooms, # of occupied, unoccupied rooms, occupancy rate, what floor has the least number of rooms and finally whether
 or not the hotel needs to improve occupancy if it is below 60%.
Due Date : July 22, 2022
I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here : Damaris Constante
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
//Constants for rooms and floor numbers.
    const int MIN_ROOM=1;
    const int MAX_ROOM=30;
    const int MIN_FLOOR=1;
    const int MAX_FLOOR=5;
//Constants for different type of room rates.
    const int SINGLE_ROOM=60;
    const int DOUBLE_ROOM=75;
    const int KING_ROOM=100;
    const int SUITE_ROOM=150;
//Hotel header.
    cout<<"--------------------------------------------------------------"<<endl
    <<"                            Lux hotel"<<endl
    <<"--------------------------------------------------------------"<<endl;
//Ask user for location.
    string hotelChain;
    cout<<"Enter the location of this hotel chain: ";
    getline (cin, hotelChain);
//Ask user for total number of floors of the hotel if less than 1 or greater than 5 print error message.
    int totalNumOfFloors;
    cout<<"Enter the total number of floors of the hotel: ";
    cin>>totalNumOfFloors;
    while (totalNumOfFloors>MAX_FLOOR || totalNumOfFloors<MIN_FLOOR){
    cout<<endl<<"The total number of floors has to be in between 1-5."<<endl
        <<"Renter the total number of floors of the hotel: ";
        cin>>totalNumOfFloors;
    }
//Number of occupied singles, doubles,kings,and suites. + number of overall rooms per floor
    int c=0;
    int sum;
    int numOfSingles;
    int numOfDoubles;
    int numOfKings;
    int numOfSuites;
    int numOfRoomsPerFlr;
//Accumulators
    int totNumOfSingles=0;
    int totNumOfDoubles=0;
    int totNumOfKings=0;
    int totNumOfSuites=0;
    double totNumOfRooms=0;
    
do {
//Ask user to enter the total # of rooms in the floor.
      cout<<"Enter the total number of rooms in this floor: ";
      cin>>numOfRoomsPerFlr;
    totNumOfRooms+=numOfRoomsPerFlr;
//Ask user to re-enter # of rooms if the number is more less than 1 or more than 30.
    while (numOfRoomsPerFlr>MAX_ROOM||numOfRoomsPerFlr<MIN_ROOM){
      cout<<endl<<"The total number of rooms has to be in between 1-30"<<endl
        <<"Renter the total number of rooms: ";
        totNumOfRooms=0;
        cin>>numOfRoomsPerFlr;
        if (numOfRoomsPerFlr>MIN_ROOM||numOfRoomsPerFlr<MAX_FLOOR){
            totNumOfRooms+=numOfRoomsPerFlr;
        }
    }
//counter for do while loop
    c++;
//Ask user to enter the # of occupied single rooms.
    cout<<endl<<"How many single rooms are occupied in the #"<<c<<" floor?: ";
      cin>>numOfSingles;
    totNumOfSingles+=numOfSingles;
//Ask user to enter the # of occupied double rooms.
      cout<<"How many double rooms are occupied in this floor?: ";
      cin>>numOfDoubles;
    totNumOfDoubles+=numOfDoubles;
//Ask user to enter the # of occupied king rooms.
    cout<<"How many king rooms are occupied in this floor?: ";
    cin>>numOfKings;
    totNumOfKings+=numOfKings;
//Ask user to enter the # of occupied suite rooms.
    cout<<"How many suite rooms are occupied in this floor?: ";
    cin>>numOfSuites;
    totNumOfSuites+=numOfSuites;
    cout<<endl;
//Repeat process of asking what kind of rooms are occupied if the occupied # of rooms entered is greater than total # of rooms.
    sum= numOfSingles+numOfDoubles+numOfKings+numOfSuites;
    if (sum>numOfRoomsPerFlr){
        cout<<"The total number of rooms you entered is greater than the total number of rooms on the floor."<<
        "Please re-enter the number of rooms and occupied rooms."<<endl;
        c--; //subtract 1 from counter to re-ask questions
    }
    }
    while (c<totalNumOfFloors);
//Luxe hotel header and todays room rates
    cout<<endl<<"---------------------------------------------------------------------------------------------"<<endl
    <<"                              Lux hotel located in: "<<hotelChain<<endl
    <<"                                TODAY'S ROOM RATES(US$/NIGHT)"<<endl
    <<"Single room: $60          Double room: $75           King room: $100          Suite room: $150"<<endl<<
    "---------------------------------------------------------------------------------------------"<<endl;
//Hotel income
    int hotelIncome;
    hotelIncome=(totNumOfSingles*SINGLE_ROOM)+(totNumOfDoubles*DOUBLE_ROOM)+(totNumOfKings*KING_ROOM)+
    (totNumOfSuites*SUITE_ROOM);
    cout<<"Hotel income:"<<setw(15)<<"$"<<hotelIncome<<endl;
//total # of rooms
    cout<<"Total # of rooms:"<<setw(12)<<totNumOfRooms<<endl;
//Total # of occupied rooms
    double occupiedRooms;
    occupiedRooms= totNumOfSingles+totNumOfDoubles+totNumOfKings+totNumOfSuites;
    cout<<"Total # of occupied rooms:"<<setw(5)<<occupiedRooms<<endl;
//Total # of unoccupied rooms
    int unoccupiedRooms;
    unoccupiedRooms=totNumOfRooms-occupiedRooms;
    cout<<"Total # of unoccupied rooms:"<<setw(3)<<unoccupiedRooms<<endl;
//Occupancy rate
    double occupancyRate;
    occupancyRate=(occupiedRooms/totNumOfRooms)*100;
    cout<<"Occupancy rate:"<<setw(16)<<setprecision(2)<<fixed<<occupancyRate<<"%"<<endl;
//what floor has the least number of floors
    cout<<"Floor "<<c<<" has the least number of rooms in it."<<endl;
//improve occupancy rate if less than 60
    if (occupancyRate<60){
        cout<<"Need to impove occupancy!!"<<endl;
    }
//Ending message of program
    cout<<endl<<"Thank you for using my program!"<<endl<<"PROGRAMMER: Damaris Constante."<<endl<<"CMSC 140 Project: 3"
    <<endl<<"Due date: July 22, 2022."<<endl;
    return 0;
    
}
