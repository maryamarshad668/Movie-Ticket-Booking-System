#include "CinemaSystem.h"
#include <iostream>

using namespace std;

CinemaSystem::CinemaSystem() {
    currentUser = nullptr;
    users.push_back(new Admin(1, "admin", "admin123"));
    users.push_back(new Customer(2, "abdullah", "1234"));
    users.push_back(new Customer(3, "maryam", "1234"));
    movies.push_back(new Movie(101, "Inception", "Sci-Fi", 148));
    movies.push_back(new Movie(102, "Frozen", "Animation", 102));
}

void CinemaSystem::run() {
    cout << "Welcome to Movie Ticket System\n";
    while (true) {
        if (currentUser == nullptr) {
            handleLogin();
        }
        else {
            currentUser->displayMenu();
            int choice;
            cout << "Enter Choice: ";
            cin >> choice;

            if (currentUser->getType() == "Admin") {
                if (choice == 1) addMovie();
                else if (choice == 2) addShow();
                else if (choice == 3) viewAllTickets();
                else if (choice == 4) currentUser = nullptr;
            }
            else {
                if (choice == 1) viewMovies();
                else if (choice == 2) bookTicket();
                else if (choice == 3) viewMyTickets();
                else if (choice == 4) currentUser = nullptr;
            }
        }
    }
}

void CinemaSystem::handleLogin() {
    string name, pass;
    cout << "\n--- LOGIN ---\nUsername: ";
    cin >> name;
    cout << "Password: ";
    cin >> pass;

    for (User* u : users) {
        if (u->getName() == name && u->login(pass)) {
            currentUser = u;
            cout << "Login Successful!\n";
            return;
        }
    }
    cout << "Invalid Credentials.\n";
}

void CinemaSystem::registerUser() {
    string name, pass;
    cout << "\n--- REGISTER ---\n";
    cout << "Enter Username: "; cin >> name;
    cout << "Enter Password: "; cin >> pass;

    int newId = users.size() + 1;
    users.push_back(new Customer(newId, name, pass));
    cout << "Registration Successful! Please Login.\n";
}

void CinemaSystem::addMovie() {
    int id, dur;
    string title, genre;
    cout << "Enter Movie ID: "; cin >> id;
    cout << "Enter Title: "; cin >> title;
    cout << "Enter Genre: "; cin >> genre;
    cout << "Enter Duration (mins): "; cin >> dur;
    movies.push_back(new Movie(id, title, genre, dur));
    cout << "Movie Added!\n";
}

void CinemaSystem::addShow() {
    int showId, movieId;
    string time;

    viewMovies();
    cout << "Enter Movie ID to schedule: "; cin >> movieId;

    Movie* selectedMovie = nullptr;
    for (Movie* m : movies) {
        if (m->getId() == movieId) selectedMovie = m;
    }

    if (selectedMovie) {
        cout << "Enter Show ID: "; cin >> showId;
        cout << "Enter Time (e.g. 18:00): "; cin >> time;
        shows.push_back(new Show(showId, selectedMovie, time));
        cout << "Show Scheduled!\n";
    }
    else {
        cout << "Movie not found.\n";
    }
}

void CinemaSystem::viewMovies() {
    cout << "\n--- AVAILABLE MOVIES ---\n";
    for (Movie* m : movies) {
        m->display();
    }
}

void CinemaSystem::bookTicket() {
    int showId, seatNum;
    cout << "\n--- AVAILABLE SHOWS ---\n";
    if (shows.empty()) { cout << "No shows available.\n"; return; }

    for (Show* s : shows) {
        s->displayShowInfo();
    }

    cout << "Enter Show ID to book: "; cin >> showId;

    Show* selectedShow = nullptr;
    for (Show* s : shows) {
        if (s->getShowId() == showId) selectedShow = s;
    }

    if (selectedShow) {
        selectedShow->displaySeats();
        cout << "Enter Seat Number (0-9): "; cin >> seatNum;

        if (selectedShow->bookSeat(seatNum)) {
            int ticketId = tickets.size() + 1;
            tickets.push_back(new Ticket(ticketId, currentUser->getName(), selectedShow->getMovieTitle(), "18:00", seatNum));
            cout << "Booking Confirmed! Ticket #" << ticketId << " generated.\n";
        }
        else {
            cout << "Booking Failed. Seat invalid or taken.\n";
        }
    }
    else {
        cout << "Show not found.\n";
    }
}

void CinemaSystem::viewAllTickets() {
    cout << "\n--- ALL ISSUED TICKETS ---\n";
    for (Ticket* t : tickets) {
        t->display();
    }
}

void CinemaSystem::viewMyTickets() {
    cout << "\n--- MY TICKETS ---\n";
    bool found = false;
    for (Ticket* t : tickets) {
        if (t->getCustomerName() == currentUser->getName()) {
            t->display();
            found = true;
        }
    }
    if (!found) cout << "No tickets found.\n";
}