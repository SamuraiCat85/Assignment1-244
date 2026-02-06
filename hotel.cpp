#include "HOTEL.H"
#include <iostream>
#include<string.h>
#include<string>

using namespace std;

/* DATE class */

Date::Date() : month(0), day(0), year(0){}; // Default constructor
Date::Date(int m, int d, int y) : month(m), day(d), year(y){}; // Parametrized constructor

// Getter functions
int Date::get_month() const { return month; }
int Date::get_day() const { return day; }
int Date::get_year() const { return year; }

// Setter functions
void Date::set_month(int m) { month = m; }
void Date::set_day(int d) { day = d; }
void Date::set_year(int y) { year = y; }

// Print DATE function
void Date::print_date() const{
    cout << month << "/" << day << "/" << year << endl;
} 

// Convert DATE to string function
string Date::DateToString() const{
    string str = (to_string(month)) + "/" + (to_string(day)) + "/" + (to_string(year));
    return str;
}

/* INFOMRATION class */

// Default constructor
Information::Information() {
    strcpy(fname , "");
    strcpy(lname , "");
    Date DOB();
} 

// Parametrized constructor
Information::Information(char* fn ,char* ln ,int d, int m, int y){
    strcpy(fname , fn);
    strcpy(lname , ln);
    Date DOB(d,m,y);
}

// Print INFORMATION function
void Information::print_info() const{
    cout << fname << " " << lname << endl;
    DOB.print_date();
};

// Getter functions
Date Information::get_DOB() const { return DOB; }
char* Information::get_fname() const { return fname; }
char* Information::get_lname() const { return lname; }

// Setter function
void Information::set_DOB(int m, int d, int y){
    DOB.set_month(m);
    DOB.set_day(d);
    DOB.set_year(y);
}

void Information::set_fname(char* fn){
    strcpy(fname , fn);
} 

void Information::set_lname(char* ln){
    strcpy(lname , ln);
}

// Convert INFORMATION to string function
string Information::InfoToString() const {
    string str = string(fname) + " " + string(lname) + " " + DOB.DateToString();

    return str;

}

/* GUESTS member functions */ 

// Default Constructor
Guests::Guests() : checkIn(Date()), checkOut(Date()), roomNumber(0), roomGuests(new Information[4]) {
    // roomNumber = 0; just to show it in the body, added in the member initialization list
    // Room number --> if static room number counter < 20 then ????? ASKKKK IN PODDD SESSSIIONN
}

// Parametrized constructor
Guests::Guests(int m1, int d1, int y1, int m2, int d2, int y2, int rm)
: checkIn(m1, d1, y1), checkOut(m2, d2, y2), roomNumber(rm), roomGuests(new Information[4]) {}

// Adding guest function
void Guests::AddGuest(const Information& newGuest){
    if(NumGuests < 4){
        roomGuests[NumGuests] = newGuest;
        NumGuests++;
    }
    else{
        cout << "Could not add more guests. Maximum number of guests reached." << endl;
        // Should do exception handling instead. Can be adjusted later
    }
}

// Convert GUESTS list information to string function
string Guests::GuestsToString() const{
    string str = "Room number " + to_string(roomNumber) + ": \n";
    for (int i = 0; i < NumGuests; i++){
        str = str + (roomGuests[i].InfoToString()) + "\n";
    }

    str = str + "Check in Date:" + checkIn.DateToString() + "\n";
    str = str + "Check out Date:" + checkOut.DateToString() + "\n";
            
    return str; 
}

// Getter funtions 
Date Guests::get_checkIn() const{
    return checkIn;
}

Date Guests::get_checkOut() const{
    return checkOut;
}

Information Guests::get_GuestInfo(int guestNumber){
    if (guestNumber < 0 || guestNumber >= NumGuests){
        cout << "Invalid input."; // Should do exception handling instead. Can be adjusted later
    }
    return roomGuests[guestNumber];
}

int Guests::get_numberGuests() const{
    return NumGuests;
}

int Guests::get_roomNumber() const{ 
    return roomNumber;
}

// Setter functions
void Guests::set_checkIn(const Date& DOB){
    checkIn = DOB;
}

void Guests::set_checkOut(const Date& DOB){
    checkOut = DOB;
}

void Guests::set_numGuests(int& ng){
    NumGuests = ng;
}

void Guests::set_roomNumber(int& rm){
    roomNumber = rm;
}

/* GUESTS RES REQUEST class */

// Guests objects should be created DYNAMICALLY

Guests_Res_Request::Guests_Res_Request() : guest(Guests()), resID(0), numNights(0) { resNumGen++; }; // Default constructor
Guests_Res_Request::Guests_Res_Request(Guests g, int rN, int nN) : guest(g), resID(rN), numNights(nN) { resNumGen++; }; // Parametrized constructor  

// Getter functions
Guests Guests_Res_Request::get_Guests() const{
    return guest;
}

int Guests_Res_Request::get_resID() const{
    return resID;
}

int Guests_Res_Request::get_numNights() const{
    return numNights;
}

// Setter functions

void Guests_Res_Request::set_FullGuestInfo(Guests g){
    guest = g;
}

void Guests_Res_Request::set_resID(int rN){
    resID = rN;
}

void Guests_Res_Request::set_numNights(int nN){
    numNights = nN;
}

/* RESERVATION MANAGER class */

// Default constructor

// Parametrized constructor

// Getter functions

// Setter functions


