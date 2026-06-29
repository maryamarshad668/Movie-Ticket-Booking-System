#include "Movie.h"

using namespace std;

Movie::Movie(int id, string title, string genre, int duration) {
    this->id = id;
    this->title = title;
    this->genre = genre;
    this->duration = duration;
}

int Movie::getId() {
    return id;
}

string Movie::getTitle() {
    return title;
}

void Movie::display() {
    cout << id << ". " << title << " (" << genre << ", " << duration << " mins)" << endl;
}