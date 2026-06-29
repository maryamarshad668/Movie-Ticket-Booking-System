#ifndef CINEMASYSTEM_H
#define CINEMASYSTEM_H

#include <vector>
#include "User.h"
#include "Movie.h"
#include "Show.h"
#include "Ticket.h"

class CinemaSystem {
private:
    std::vector<User*> users;
    std::vector<Movie*> movies;
    std::vector<Show*> shows;
    std::vector<Ticket*> tickets;
    void registerUser();
    User* currentUser;

public:
    CinemaSystem();
    void run();

private:
    void handleLogin();
    void addMovie();
    void addShow();
    void viewAllTickets();
    void viewMovies();
    void bookTicket();
    void viewMyTickets();
};

#endif