#include "Show.h"
#include <iostream>

using namespace std;

Show::Show(int id, Movie* m, string time) {
    this->showId = id;
    this->movie = m;
    this->time = time;
    for (int i = 0; i < 10; i++) {
        seats.push_back(false);
    }
}

void Show::displayShowInfo() {
    cout << "Show ID: " << showId << " | Movie: " << movie->getTitle() << " | Time: " << time << endl;
}

void Show::displaySeats() {
    cout << "Seats [0-9]: ";
    for (size_t i = 0; i < seats.size(); i++) {
        if (seats[i]) cout << "[X] ";
        else cout << "[" << i << "] ";
    }
    cout << endl;
}

bool Show::bookSeat(int seatNumber) {
    if (seatNumber < 0 || seatNumber >= 10) return false;
    if (seats[seatNumber]) return false;

    seats[seatNumber] = true;
    return true;
}

int Show::getShowId() { return showId; }
string Show::getMovieTitle() { return movie->getTitle(); }