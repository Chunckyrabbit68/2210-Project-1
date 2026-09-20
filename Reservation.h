#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
using namespace std;

class Reservation {
public:
    int reservationID;
    int studentID;
    string studentName;
    string resource;
    string date;
    string time;

    Reservation();

    Reservation(int reservationID,
                int studentID,
                string studentName,
                string resource,
                string date,
                string time = "");

    void display() const;
};

#endif
