#include "HOTEL.H"
#include <iostream>
using namespace std;

int main() {

    // Create guest info
    Information g1((char*)"Noor", (char*)"Musallam", 1, 1, 2000);
    Information g2((char*)"Prisca", (char*)"Wong", 4, 4, 2005);

    // Create a Guests object
    Guests group(3, 1, 2026, 3, 8, 2026, 5, 0); // room 5, 0 guests initially
    group.AddGuest(g1);
    group.AddGuest(g2);

    // Create reservation request
    Guests_Res_Request req(group, 1, 7); // resID=1, 7 nights

    // Create manager
    Reservation_Manager manager;

    // Process reservation
    int result = manager.processReservationRequest(req);

    if (result != -1) {
        cout << "Reservation successful! ID = " << result << endl;
    } else {
        cout << "Reservation failed." << endl;
    }

    // Print reservation grid
    manager.printReservations();

    // Print details of reservation
    Guests_Res_Request details = manager.get_DetailsOfReservation(result);
    cout << details.get_occupants().GuestsToString();

    // Cancel reservation
    manager.cancelReservation(result);

    cout << "\nAfter cancellation:\n";
    manager.printReservations();

    return 0;
}
