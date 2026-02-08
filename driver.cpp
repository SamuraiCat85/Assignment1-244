
#include "HOTEL.H"
#include <iostream>

using namespace std;



int main(){
    Date date1(2,3,2016);
    date1.print_date();

    return 0;

}

/*    

    // Create info for two people
    Information guest1("Prisca", "Wong", 4, 4, 2005);
    Information guest2("Noor", "Musallam", 1, 1, 2000);

    // 
    Guests group1 (3, 1, 2026, 3, 10, 2026, 1444 , 0);

    // Actually let's say I want to now add the two people as guests of this room 
    group1.AddGuest(guest2);
    group1.AddGuest(guest1);



// Create reservation request
    Guests_Res_Request request1(group1, 15, 9);

    // Process it in the reservation manager
    Reservation_Manager();
    manager.Reservation_Manager(request1);

    // Print grid
    manager.printReservations();

    // Cancel reservation
    manager.cancelReservation(request1);

    return 0;*/