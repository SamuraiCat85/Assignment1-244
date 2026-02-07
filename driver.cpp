#include <iostream>
#include "HOTEL.H"
using namespace std;

int main(){

    // Create guest info
    Information guest1("Prisca", "Wong", 4, 4, 2005);
    Information guest1("Noor", "Musallam", 1, 1, 2000);

    // Create a reservation info
    Guests roomGuest(3, 1, 2026, 3, 10, 2026, 15, 2);

    // Actually let's say I want two other guests
    roomGuest.AddGuest("Noor", "Wong", 2, 2, 2002);
    roomGuest.AddGuest("Prisca", "Musallam", 3, 3, 2003);

    // Create reservation request
    Guests_Res_Request request1(roomGuest, 15, 9);

    // Process it in the reservation manager
    Reservation_Manager();
    manager.Reservation_Manager(request1);

    // Print grid
    manager.printReservations();

    // Cancel reservation
    manager.cancelReservation(request1);

    return 0;
}