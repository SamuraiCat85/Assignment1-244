#ifndef HOTEL_H_
#define HOTEL_H_

#include <array>

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
         

        Date(); // member initialization list
        Date(const Date&); //copy constructor
        Date(int,int,int); //parameterized constructor 
        


}; ///why is it called time in the member variables


class Information{
    private:
        char* fname;
        char* lname;
        Date DOB;

    public:
        Information();
        Information(char*,char*,int,int,int);
        void print_info() const;
        string InfoToString() const;
        
        char* get_fname() const;
        char* get_lname() const;
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
        Guests(); //Default constructor
        Guests(int,int,int,int,int,int,int); // Parametrized constructor
        string GuestsToString() const; // Convert guest info to string and return it
        void AddGuest(const Information&); // Add guest to room
        
        Date get_checkIn() const;
        Date get_checkOut() const;
        Information get_GuestInfo(int);
        int get_numberGuests() const;
        int get_roomNumber() const;

        void set_checkIn(const Date&);
        void set_checkOut(const Date&);
        void set_numGuests(int&);
        void set_roomNumber(int&);

};

class Guests_Res_Request{
    private:
        Guests guest;
        static int resNumGen; // reservation number generator/counter
        int resID; // Reservation number
        int numNights;

    public:
        Guests_Res_Request();
        Guests_Res_Request(Guests, int, int);

        Guests get_Guests() const;
        int get_resID() const;
        int get_numNights() const;

        void set_FullGuestInfo(Guests);
        void set_resID(int);
        void set_numNights(int);

};

class Reservation_Manager{
    private:
        const int max_no_of_nights = 7;
        const int no_of_rooms = 20;
        Guests_Res_Request* reservations; 
        array <array<int, 7>, 20> arr; // I get an error when I put max_no_of_nights and no_of_rooms...
        // all empty spots of array must be filled with zeroes
    public:
        Reservation_Manager();
        Reservation_Manager(); // Parametrized constructor...        
        
        void printReservations() const;
        int processReservationRequest(Guests_Res_Request&);
        Guests_Res_Request get_DetailsOfReservation(int) const;
        void cancelReservation(int);

        // Getters
        // Setters


};

#endif
