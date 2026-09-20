#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include "Resource.h"
#include "Reservation.h"
using namespace std;

stack<Reservation> cancellationHistory;

// Note: To cancel reservations you'll need the reservation ID
void cancelReservation(int reservationID) {
  Reservation removedReservation;
  if(removeReservation(reservationID, removedReservation)){

  cancellationHistory.push(removedReservation); //stores the cancelled reservation
  Resource* resource = findResource(removedReservation.resource);

    if(resource != nullptr){
      resource->setStatus("Available");
    }

    cout << "Reservation " << reservationID << " has been cancelled successfully.\n";
    return;
  }
    cout << "Reservation not found.\n"; // if reservation isnt found in active reservations
}

void restoreCancellation() {
  if (cancellationHistory.empty()){
    cout << "No cancelled reservation(s) to restore.\n";
    return;
  }

  Reservation restored = cancellationHistory.top(); // gets the most recent cancelled reservation
  Resource* resource = findResource(restored.resource);

  if(resource == nullptr){
    cout << "Resource not found.\n";
    return;
  }

  if(!resource->isAvailable()){
    cout << "Resource is unavailable.\n";
    return;
  }

  cancellationHistory.pop(); // removes it from cancellation history
  insertReservation(restored); // adds it back to active reservations

  resource->setStatus("Unavailable");
   cout << "Reservation " << restored.reservationID << " restored successfully.\n";
}

void displayCancellationHistory() {
  if (cancellationHistory.empty()){
    cout << "No cancelled history.\n";
    return;
  }

  stack<Reservation> temp = cancellationHistory;
  cout << "----- Cancellation History -----\n";

  while (!temp.empty()){
    Reservation r = temp.top();

    cout << "Reservation ID: " << r.reservationID << endl;
    cout << "Student: " << r.studentName << endl;
    cout << "Resource: " << r.resource << endl;
    cout << "Date: " << r.date << endl;
    cout << "Time: " << r.time << endl;

    temp.pop();
  }
}
