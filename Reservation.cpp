#include "Reservation.h"
#include <iostream>
using namespace std;

Reservation::Reservation() {
  reservationID = 0;
  studentID = 0;
  studentName = "";
  resourceID = "";
  date = "";
  
}

Reservation::Reservation(int reservationID, int studentID, string studentName, string resourceID, string date) {
    this->reservationID = reservationID;
    this->studentID = studentID;
    this->studentName = studentName;
    this->resourceID = resourceID;
    this->date = date;
}

int Reservation::getReservationID() const {
    return reservationID;
}

int Reservation::getStudentID() const {
    return studentID;
}

string Reservation::getStudentName() const {
    return studentName;
}

string Reservation::getResourceID() const {
    return resourceID;
}

string Reservation::getDate() const {
    return date;
}

void Reservation::display() const {
    cout << reservationID << " | "
         << studentID << " | "
         << studentName << " | "
         << resourceID << " | "
         << date << endl;
}
