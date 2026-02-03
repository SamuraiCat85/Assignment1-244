#ifndef HOTEL_H_
#define HOTEL_H_

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
        Date get_DOB() const;
        void print_info() const;
        
        void set_fname(char*);
        void set_lname(char*);
        void set_DOB(int,int,int)

};

class Guests{
    private:
        Date checkIn;
        Date checkOut;
        Information roomGuests[4];
        int roomNumber;

    public:
        Guests();
        Guests(int,int,int,int,int,int,Information arr[4],int);
        string toString();

};

class Guests_Res_Request{
    private:
        Guests guest;
        static int resNumGen; //reservation number generator/counter
        int resNum;
    //reservation number

    public:
        Guests_Res_Request();
        Guests_Res_Request() : resNum(){};

};

class Reservation_Manager{



};

#endif 