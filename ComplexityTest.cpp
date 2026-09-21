#include <iostream>
#include <queue>
#include <string>
#include "Resource.h"
#include "Reservation.h"

using namespace std;

Resource* findResource(const string& resourceID);

struct ReservationNode {
  Reservation data;
  ReservationNode* next;

  ReservationNode(Reservation reservation){
    data = reservation;
    next = nullptr;
  }
};

ReservationNode* head = nullptr;

queue<Reservation> waitingList;


// Check for duplicate reservation ID
// O(n)
bool reservationExists(int reservationID){
  ReservationNode* current = head;

  while(current != nullptr){

    if(current->data.reservationID == reservationID){
      return true;
    }

    current = current->next;
  }

  return false;
}


// Check resource for date and time conflict
// O(n)
bool isResourceReserved(const string& resourceID, const string& date, const string& time){
  ReservationNode* current = head;

  while(current != nullptr){

    if(current->data.resource == resourceID &&
       current->data.date == date &&
       current->data.time == time){
      return true;
    }

    current = current->next;
  }

  return false;
}


// Reservation insertion
// O(n)
bool insertReservation(Reservation reservation){

  if(reservationExists(reservation.reservationID)){
    cout << "Reservation ID " << reservation.reservationID << " is already in use.\n";
    return false;
  }

  ReservationNode* newNode = new ReservationNode(reservation);

  newNode->next = head;
  head = newNode;

  return true;
}


// Reservation removal
// O(n)
bool removeReservation(int reservationID, Reservation& removedReservation){
  ReservationNode* current = head;
  ReservationNode* previous = nullptr;

  while(current != nullptr){

    if(current->data.reservationID == reservationID){

      removedReservation = current->data;

      if(previous == nullptr){
        head = current->next;
      }
      else{
        previous->next = current->next;
      }

      delete current;
      return true;
    }

    previous = current;
    current = current->next;
  }

  return false;
}


// Display active reservations
// O(n)
void displayReservations(){
  if(head == nullptr){
    cout << "No active reservations.\n";
    return;
  }

  ReservationNode* current = head;

  cout << "----- Active Reservations -----\n";

  while(current != nullptr){
    current->data.display();
    current = current->next;
  }
}


// Add reservation to waiting list
// O(1)
void addToWaitingList(Reservation reservation){
  waitingList.push(reservation);

  cout << "Reservation added to waiting list.\n";
}


// Process waiting list
// Queue operation O(1), resource and conflict search O(n)
void processWaitingList(){
  if(waitingList.empty()){
    cout << "Waiting list is empty.\n";
    return;
  }

  Reservation nextReservation = waitingList.front();

  Resource* resource = findResource(nextReservation.resource);

  if(resource == nullptr){
    cout << "Resource not found.\n";
    return;
  }

  if(!resource->isAvailable() ||
     isResourceReserved(nextReservation.resource, nextReservation.date, nextReservation.time)){
    cout << "Resource is still unavailable.\n";
    return;
  }

  waitingList.pop();

  insertReservation(nextReservation);

  cout << "Reservation "
       << nextReservation.reservationID
       << " added to active reservations.\n";
}


// Remove reservation from waiting list
// O(n)
bool removeFromWaitingList(int reservationID){
  int waiting = waitingList.size();
  bool removed = false;

  queue<Reservation> remaining;

  for(int i = 0; i < waiting; i++){

    Reservation current = waitingList.front();
    waitingList.pop();

    if(!removed && current.reservationID == reservationID){
      removed = true;
      continue;
    }

    remaining.push(current);
  }

  waitingList = remaining;

  return removed;
}


// Display waiting list
// O(n)
void displayWaitingList(){
  if(waitingList.empty()){
    cout << "Waiting list is empty.\n";
    return;
  }

  queue<Reservation> temp = waitingList;

  cout << "----- Waiting List -----\n";

  while(!temp.empty()){
    Reservation r = temp.front();

    cout << "Reservation ID: " << r.reservationID << endl;
    cout << "Student: " << r.studentName << endl;
    cout << "Resource: " << r.resource << endl;
    cout << "Date: " << r.date << endl;
    cout << "Time: " << r.time << endl;

    temp.pop();
  }
}
