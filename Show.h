#ifndef SHOW_H
#define SHOW_H

#include "Movie.h"
#include <vector>
#include <string>

class Show {
private:
    int showId;
    Movie* movie;
    std::string time;
    std::vector<bool> seats;

public:
    Show(int id, Movie* m, std::string time);
    void displayShowInfo();
    void displaySeats();
    bool bookSeat(int seatNumber);
    int getShowId();
    std::string getMovieTitle();
};

#endif