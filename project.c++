#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

#include "Resource.h"
#include "Reservation.h"

using namespace std;

vector<Resource> resources;
stack<Reservation> cancellationHistory;

// These functions are in ComplexityTest.cpp
void insertReservation(Reservation reservation);
bool removeReservation(int reservationID, Reservation& removedReservation);
void displayReservations();
void addToWaitingList(Reservation reservation);
void displayWaitingList();
void processWaitingList();

// Load resources from resources.txt
void loadResources(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error opening resource file." << endl;
        return;
    }

    string line;

    while (getline(file, line)) {
        stringstream ss(line);

        string id;
        string name;
        string type;
        string status;

        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, type, '|');
        getline(ss, status);

        Resource resource(id, name, type, status);
        resources.push_back(resource);
    }

    file.close();
}

// Display every resource
void displayResources() {
    cout << "\n--- All Resources ---" << endl;

    for (const Resource& resource : resources) {
        resource.display();
    }
}

// Display availability
void displayAvailability() {
    cout << "\n--- Resource Availability ---" << endl;

    for (const Resource& resource : resources) {
        cout << resource.getResourceID()
             << " - "
             << resource.getResourceName()
             << ": "
             << resource.getStatus()
             << endl;
    }
}

// Find resource by ID
Resource* findResource(const string& resourceID) {
    for (Resource& resource : resources) {
        if (resource.getResourceID() == resourceID) {
            return &resource;
        }
    }

    return nullptr;
}

// Check whether a reservation can be made
bool validateReservation(const string& resourceID) {
    Resource* resource = findResource(resourceID);

    if (resource == nullptr) {
        cout << "Invalid resource ID." << endl;
        return false;
    }

    if (!resource->isAvailable()) {
        cout << "Resource is unavailable." << endl;
        return false;
    }

    return true;
}

// Create reservation
void createReservation() {
    int reservationID;
    int studentID;

    string studentName;
    string resourceID;
    string date;
    string time;

    cout << "Enter reservation ID: ";
    cin >> reservationID;

    cout << "Enter student ID: ";
    cin >> studentID;

    cin.ignore();

    cout << "Enter student name: ";
    getline(cin, studentName);

    cout << "Enter resource ID: ";
    cin >> resourceID;

    cout << "Enter reservation date: ";
    cin >> date;

    cout << "Enter reservation time: ";
    cin >> time;

    Resource* resource = findResource(resourceID);

    if (resource == nullptr) {
        cout << "Invalid resource ID." << endl;
        return;
    }

    Reservation newReservation(
        reservationID,
        studentID,
        studentName,
        resourceID,
        date,
        time
    );

    if (!resource->isAvailable()) {
        cout << "Resource is unavailable." << endl;

        addToWaitingList(newReservation);

        return;
    }

    insertReservation(newReservation);

    resource->setStatus("Unavailable");

    cout << "\nReservation created:" << endl;
    newReservation.display();

    cout << "Reservation created successfully." << endl;
}

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
