#include "User.h"

using namespace std;

User::User(int id, string name, string password) {
    this->id = id;
    this->name = name;
    this->password = password;
}

bool User::login(string pass) {
    return this->password == pass;
}

string User::getName() {
    return name;
}

Admin::Admin(int id, string name, string password) : User(id, name, password) {}

void Admin::displayMenu() {
    cout << "\n--- ADMIN MENU (" << name << ") ---\n";
    cout << "1. Add Movie\n";
    cout << "2. Add Show\n";
    cout << "3. View All Tickets\n";
    cout << "4. Logout\n";
}

string Admin::getType() { return "Admin"; }

Customer::Customer(int id, string name, string password) : User(id, name, password) {}

void Customer::displayMenu() {
    cout << "\n--- CUSTOMER MENU (" << name << ") ---\n";
    cout << "1. View Movies\n";
    cout << "2. View Shows & Book Ticket\n";
    cout << "3. My Tickets\n";
    cout << "4. Logout\n";
}

string Customer::getType() { return "Customer"; }