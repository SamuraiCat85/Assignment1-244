#ifndef HOTEL_H_
#define HOTEL_H_

#include <array>
#include <string>

using std::string; ///
using std::array;//// did this to help solve the string-returning functions issue


class Date{
    private:
        int month, day, year;

    public:
        int get_month() const;
        int get_day() const;
        int get_year() const ;

        void set_month(int);
        void set_day(int);
        void set_year(int);

        void print_date() const;
        string DateToString() const;

        Date();
        Date(const Date&);
        Date(int,int,int); 
        
}; 


class Information{
    private:
        char fname[50]; // array of characters, not array of pointers to characters
        char lname[50];
        Date DOB;

    public:
        Information();
        Information(char*,char*,int,int,int);
       
        void print_info() const;
        string InfoToString() const;
        
        const char* get_fname() const;
        const char* get_lname() const;
        Date get_DOB() const;

        void set_fname(char*);
        void set_lname(char*);
        void set_DOB(int,int,int);

};

class Guests{
    private:
        Date checkIn;
        Date checkOut;
        Information* roomGuests; 
        int NumGuests;
        int roomNumber;

    public:
        Guests(); // Default constructor
        ~Guests(); // Destructor
        Guests(int,int,int,int,int,int,int, int); // Parametrized constructor
        string GuestsToString()const; // Convert guest info to string and return it
        void AddGuest(const Information&); // Add guest to room
        
        Date get_checkIn() const;
        Date get_checkOut() const;
        Information get_GuestInfo(int);//
        int get_numberGuests() const;
        int get_roomNumber() const;

        void set_checkIn(const Date&);
        void set_checkOut(const Date&);
        void set_numGuests(int&);
        void set_roomNumber(int&);

};

class Guests_Res_Request{
    private:
        Guests occupants;
        static int resNumGen; // reservation number generator/counter
        int resID; // Reservation number
        int numNights;

    public:
        Guests_Res_Request();
        Guests_Res_Request(const Guests&, int, int);

        Guests get_occupants() const;
        int get_resID() const;
        int get_numNights() const;

        void set_FullGuestInfo(Guests);
        void set_resID(int);
        void set_numNights(int);

};

class Reservation_Manager{
    private:
        static const int max_no_of_nights = 7; // Don't understand why it has to be static...
        static const int no_of_rooms = 20;
        Guests_Res_Request** reservations; // array of pointers... 
        // Guest_Res_Request* is for a pointer POITING to an array of objects (but we want an array of POINTERS)
        array <array<int, no_of_rooms>, max_no_of_nights> reservationArr = {}; // Setting array to zero
        // I get an error when I put max_no_of_nights and no_of_rooms...
        
        int reservationCount;

    public:
        Reservation_Manager(); 
        ~Reservation_Manager();
        // Reservation_Manager(int, int); 
        // Parametrized constructor... is it necessary? 
        // I don't think so, since the max number of nights and rooms are constants.
        
        int get_numReservations () const;

        void printReservations() const;
        // Check if roomNumber is available first, function used for processing reservation
        bool checkReservationAvailibility(int, int, int) const;
        int processReservationRequest(Guests_Res_Request&);
        Guests_Res_Request get_DetailsOfReservation(int) const;
        void cancelReservation(int);

};

#endif
