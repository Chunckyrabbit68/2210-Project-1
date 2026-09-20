#include "Reservation.h"
#include <iostream>
using namespace std;

Reservation::Reservation() {
    reservationID = 0;
    studentID = 0;
    studentName = "";
    resource = "";
    date = "";
    time = "";
}

Reservation::Reservation(int reservationID, int studentID, string studentName, string resource, string date, string time) {
    this->reservationID = reservationID;
    this->studentID = studentID;
    this->studentName = studentName;
    this->resource = resource;
    this->date = date;
    this->time = time;
}

void Reservation::display() const {
    cout << reservationID << " | "
         << studentID << " | "
         << studentName << " | "
         << resource << " | "
         << date;

    if (!time.empty()) {
        cout << " | " << time;
    }

    cout << endl;
}
