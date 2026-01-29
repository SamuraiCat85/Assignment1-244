#ifndef HOTEL_H_
#define HOTEL_H_

class Date{
    private:
        int month, day, year;

    public:
        void get_month(int m);
        void get_day(int d);
        void get_year(int y);

        Date(); // member initialization list
        Date(const Date&);       


}; ///why is it called time in the member variables


class Information{
    private:
        char fname[20];
        char lname[20];
        Date DOB;

    public:
        Information();
        Information(char[],char[],int,int,int);



};

class Guests{



};

class Guests_Res_Request{



};

class Reservation_Manager{



};

#endif 