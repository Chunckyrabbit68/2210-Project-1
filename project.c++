#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include "Resource.h"
#include "Reservation.h"
using namespace std;

// Note: To cancel reservations you'll need the reservation ID
void cancelReservation(int reservationID) {
  for(auto currReservation = reservations.begin(); currReservation != reservations.end(); ++currReservation){
    if(currReservation->reservationID == reservationID){
      cancellationHistory.push(*currReservation); //stores the cancelled reservation
      reservations.erase(currReservation);        // removes the reservation from active reservations 

      cout << "Reservation " << reservationID << " has been cancelled successfully.\n";
      
      return;
    }
  }

  cout << "Reservation not found.\n";             // if reservation isnt found in active reservations
}

void restoreCancellation() {
  if (cancellationHistory.empty()){
    cout << "No cancelled reservation(s) to restore.\n";
    return;
  }
  Reservation restored = cancellationHistory.top();    // gets the most recent cancelled reservation
  cancellationHistory.pop();                      // removes it from cancellation history
  reservations.push_back(restored);                // adds it back to active reservations
  
  cout << "Reservation " << reservationID << " restored successfully.\n";
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

