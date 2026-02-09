#include <iostream>
#include "HOTEL.H"

using namespace std;

int main() {
    Reservation_Manager manager;
    
    Guests group1(3, 1, 2026, 3, 4, 2026, 0, 5);
    
    group1.AddGuest(Information("Noor", "Musallam", 1, 1, 2000));
    group1.AddGuest(Information("Prisca", "Wong", 4, 4, 2005));

    Guests group2(3, 1, 2026, 3, 4, 2026, 0, 6);
    
    group2.AddGuest(Information("stacy", "smith", 2, 1, 2006));
    group2.AddGuest(Information("rachel", "tomney", 6, 4, 1999));

    Guests_Res_Request req1(group1, 1, 3);
    int id1 = manager.processReservationRequest(req1);
    cout<<id1<<endl;
    
    Guests_Res_Request req2(group2, 2, 3);
    int id2 = manager.processReservationRequest(req2);
    cout<<id2<<endl;

    manager.printReservations();

    return 0;
}
