#include "Ticket.h"

using namespace std;

Ticket::Ticket(int id, string cName, string mTitle, string time, int seat) {
    this->ticketId = id;
    this->customerName = cName;
    this->movieTitle = mTitle;
    this->time = time;
    this->seatNumber = seat;
}

void Ticket::display() {
    cout << "TICKET #" << ticketId << " | " << customerName
        << " | " << movieTitle << " @ " << time
        << " | Seat: " << seatNumber << endl;
}

string Ticket::getCustomerName() {
    return customerName;
}