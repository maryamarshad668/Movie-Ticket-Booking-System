#ifndef TICKET_H
#define TICKET_H

#include <string>
#include <iostream>

class Ticket {
private:
    int ticketId;
    std::string customerName;
    std::string movieTitle;
    std::string time;
    int seatNumber;

public:
    Ticket(int id, std::string cName, std::string mTitle, std::string time, int seat);
    void display();
    std::string getCustomerName();
};

#endif