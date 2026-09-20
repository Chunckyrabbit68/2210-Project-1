#include <queue>

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


// Reservation insertion
// O(1)
void insertReservation(Reservation reservation){
ReservationNode* newNode = new ReservationNode(reservation);

  newNode->next = head;
  head = newNode;
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

  if(!resource->isAvailable()){
  cout << "Resource is still unavailable.\n";
  return;
  }

  waitingList.pop();

  insertReservation(nextReservation);

  resource->setStatus("Unavailable");

  cout << "Reservation "
  << nextReservation.reservationID
  << " added to active reservations.\n";
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
