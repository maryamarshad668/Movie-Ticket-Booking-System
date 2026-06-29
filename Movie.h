#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>

class Movie {
private:
    int id;
    std::string title;
    std::string genre;
    int duration;

public:
    Movie(int id, std::string title, std::string genre, int duration);
    int getId();
    std::string getTitle();
    void display();
};

#endif
