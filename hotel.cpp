#include "HOTEL.H"
#include <iostream>
#include <string.h>
#include <string>
#include <array>
#include <iomanip>

using namespace std;


int Guests_Res_Request::resNumGen = 0; //For the static variable in Guests_Res_Request functions


/* DATE class */

Date::Date() : month(0), day(0), year(0){}; // Default constructor
Date::Date(const Date& other) : month(other.month), day(other.day), year(other.year){};//copy constructor
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



/* INFORMATION class */

// Default constructor
Information::Information() {
    strcpy(fname , "");
    strcpy(lname , "");
    DOB = Date();
} 

// Parametrized constructor
Information::Information(const char* fn ,const char* ln ,int m, int d, int y) : DOB(m,d,y){
    strcpy(fname , fn);
    strcpy(lname , ln);
}

// Print INFORMATION function
void Information::print_info() const {
    cout << fname << " " << lname << endl;
    DOB.print_date();
};

// Getter functions
Date Information::get_DOB()const { return DOB; }
const char* Information::get_fname()const { return fname; }
const char* Information::get_lname()const { return lname; }

// Setter function
void Information::set_DOB(int m, int d, int y){
    DOB.set_month(m);
    DOB.set_day(d);
    DOB.set_year(y);
}

void Information::set_fname(char* fn){ strcpy(fname , fn); } 
void Information::set_lname(char* ln){ strcpy(lname , ln); }

// Convert INFORMATION to string function
string Information::InfoToString() const {
    string str = string(fname) + " " + string(lname) + " " + DOB.DateToString();

    return str;

}

/* GUESTS member functions */ 

// Default Constructor
Guests::Guests() : checkIn(Date()), checkOut(Date()), roomGuests(new Information[4]), NumGuests(0), roomNumber(0) {
    
}
// Destructor
Guests::~Guests(){ delete[] roomGuests; }

//copy constructor
Guests::Guests(const Guests& other)
    : checkIn(other.checkIn),
      checkOut(other.checkOut),
      NumGuests(other.NumGuests),
      roomNumber(other.roomNumber)
    {
    roomGuests = new Information[4];
    for (int i = 0; i < other.NumGuests; i++) {
        roomGuests[i] = other.roomGuests[i];
    }
}


// Parametrized constructor
Guests::Guests(int m1, int d1, int y1, int m2, int d2, int y2, int ng, int rm)
: checkIn(m1, d1, y1), checkOut(m2, d2, y2), roomGuests(new Information[4]), NumGuests(ng), roomNumber(rm) {}

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
string Guests::GuestsToString()const{
    string str = "Room number " + to_string(roomNumber) + ": \n";
    for (int i = 0; i < NumGuests; i++){
        str = str + (roomGuests[i].InfoToString()) + "\n";
    }

    str = str + "Check in Date:" + checkIn.DateToString() + "\n";
    str = str + "Check out Date:" + checkOut.DateToString() + "\n";
            
    return str; 
}

// Getter funtions 
Date Guests::get_checkIn() const{ return checkIn; }
Date Guests::get_checkOut() const{ return checkOut; }

Information Guests::get_GuestInfo(int guestNumber){
    if (guestNumber < 0 || guestNumber >= NumGuests){
        cout << "Invalid input."; // Should do exception handling instead. Can be adjusted later
    }
    return roomGuests[guestNumber];
}

int Guests::get_numberGuests() const{ return NumGuests; }
int Guests::get_roomNumber() const{ return roomNumber; }

// Setter functions
void Guests::set_checkIn(const Date& DOB){ checkIn = DOB; }
void Guests::set_checkOut(const Date& DOB){ checkOut = DOB; }
void Guests::set_numGuests(int& ng){ NumGuests = ng; }
void Guests::set_roomNumber(int& rm){ roomNumber = rm; }


/* GUESTS RES REQUEST class */

// 

Guests_Res_Request::Guests_Res_Request() : occupants(Guests()), resID(0), numNights(0) { resNumGen++; }; // Default constructor
Guests_Res_Request::Guests_Res_Request(const Guests& g, int rN, int nN) : occupants(g), resID(rN), numNights(nN) { resNumGen++; }; // Parametrized constructor  

// Getter functions
Guests Guests_Res_Request::get_occupants() const{ return occupants; }
int Guests_Res_Request::get_resID() const{ return resID; }
int Guests_Res_Request::get_numNights() const{ return numNights; }

// Setter functions
void Guests_Res_Request::set_FullGuestInfo(Guests g){ occupants = g; }
void Guests_Res_Request::set_resID(int rN){ resID = rN; }
void Guests_Res_Request::set_numNights(int nN){ numNights = nN; }



/* RESERVATION MANAGER class */

// Default constructor
Reservation_Manager::Reservation_Manager() : reservations(new Guests_Res_Request*[100]), reservationCount(0) {
    // Set the pointers to nullptr so they don't start dangling
    for (int i = 0; i < 100; i++){
        reservations[i] = nullptr;
    }
}

// Destructor
Reservation_Manager::~Reservation_Manager(){
    for(int i=0;i<100;i++)
        delete reservations[i];

    delete[] reservations;
}

// Parametrized constructor...
// Reservation_Manager::Reservation_Manager(int maxNights, int noRooms) : reservations(new Guests_Res_Request[100]), reservationArr() {}

int Reservation_Manager::get_numReservations () const{
    return reservationCount;
}

void Reservation_Manager::printReservations() const{ // use iomanip to make it look like an actual table
    cout << "Reservations: " << endl;
    for (int i = 0; i < max_no_of_nights; i++){
        cout << "March " << to_string(i + 1) << ": ";
        for (int j = 0; j < no_of_rooms; j++){
            cout << reservationArr[i][j] << " ";
        }
        cout << endl;
    }
}

bool Reservation_Manager::checkReservationAvailibility(int roomIndex,int startNight, int numOfNights) const{

    // Check bounds first
    if (roomIndex < 0 || roomIndex >= no_of_rooms) return false;
    if (startNight < 0 || startNight >= max_no_of_nights) return false;
    if (numOfNights <= 0) return false;
    if (startNight + numOfNights > max_no_of_nights) return false;

    for (int i = startNight; i < startNight + numOfNights; i++){
        if (reservationArr[i][roomIndex] != 0)
            return false;
    }
    return true;
}

// Essentially adding a reservation
int Reservation_Manager::processReservationRequest(Guests_Res_Request& request){

    Guests g = request.get_occupants();
    int roomIndex = g.get_roomNumber() - 1; // room number to index because array starts at 0, not 1
    Date checkInDate = g.get_checkIn();
    int startNight = checkInDate.get_day() - 1; // date to night index for same reaseon ^^^
    int numOfNights = request.get_numNights();
    
    if (checkReservationAvailibility(roomIndex, startNight, numOfNights)) /* check if room is available*/ {
        // Writing the reservation ID into each night slot in the reservation array
        for (int i = startNight; i < startNight + numOfNights; i++){
            reservationArr[i][roomIndex] = request.get_resID();
        }
        // Adding the actual object of data (Guest_Res_Request) into the reservations database which is the array of pointers
        reservations[reservationCount] = new Guests_Res_Request(request);
        reservationCount++;
        return request.get_resID(); // Returns reservation ID if the process was a success
    }
    else{
        return -1; // Returns -1 if the process was a failure/invalid
    }
}

Guests_Res_Request Reservation_Manager::get_DetailsOfReservation(int resID) const{
    for (int i = 0; i < reservationCount; i++){
        if (reservations[i] != nullptr && reservations[i]->get_resID() == resID){
            return *reservations[i];
        }
    }
    // Return a default Guests_Res_Request if not found...
    return Guests_Res_Request();
}

void Reservation_Manager::cancelReservation(int resID){
    for (int i = 0; i < reservationCount; i++){
        if (reservations[i] != nullptr && reservations[i]->get_resID() == resID){   
            for (int n = 0; n < max_no_of_nights; n++)
                for (int r = 0; r < no_of_rooms; r++)
                    if (reservationArr[n][r] == resID)
                        reservationArr[n][r] = 0;

            delete reservations[i];

            // Shift remaining reservations to fill the gap
            for (int j = i; j < reservationCount - 1; j++)
                reservations[j] = reservations[j + 1];

            reservations[reservationCount - 1] = nullptr;
            reservationCount--;
            return;
        }
    }
}
