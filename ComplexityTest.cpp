#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "Resource.h"
#include "Reservation.h"

using namespace std;

Resource* findResource(const string& resourceID);

struct ReservationNode {
    Reservation data;
    ReservationNode* next;

    ReservationNode(Reservation reservation) {
        data = reservation;
        next = nullptr;
    }
};

ReservationNode* head = nullptr;

queue<Reservation> waitingList;


// Check if reservation ID already exists
// O(n)
bool reservationExists(int reservationID) {
    ReservationNode* current = head;

    while (current != nullptr) {

        if (current->data.reservationID == reservationID) {
            return true;
        }

        current = current->next;
    }

    return false;
}


// Reservation insertion
// O(1)
void insertReservation(Reservation reservation) {
    ReservationNode* newNode = new ReservationNode(reservation);

    newNode->next = head;
    head = newNode;
}


// Reservation removal
// O(n)
bool removeReservation(
    int reservationID,
    Reservation& removedReservation
) {
    ReservationNode* current = head;
    ReservationNode* previous = nullptr;

    while (current != nullptr) {

        if (current->data.reservationID == reservationID) {

            removedReservation = current->data;

            if (previous == nullptr) {
                head = current->next;
            }
            else {
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
void displayReservations() {
    if (head == nullptr) {
        cout << "No active reservations.\n";
        return;
    }

    ReservationNode* current = head;

    cout << "----- Active Reservations -----\n";

    while (current != nullptr) {
        current->data.display();
        current = current->next;
    }
}


// Add reservation to waiting list
// O(1)
void addToWaitingList(Reservation reservation) {
    waitingList.push(reservation);

    cout << "Reservation added to waiting list.\n";
}


// Process waiting list
// Queue operation O(1), resource search O(n)
void processWaitingList() {
    if (waitingList.empty()) {
        cout << "Waiting list is empty.\n";
        return;
    }

    Reservation nextReservation = waitingList.front();

    Resource* resource = findResource(nextReservation.resource);

    if (resource == nullptr) {
        cout << "Resource not found.\n";
        return;
    }

    if (!resource->isAvailable()) {
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
void displayWaitingList() {
    if (waitingList.empty()) {
        cout << "Waiting list is empty.\n";
        return;
    }

    queue<Reservation> temp = waitingList;

    cout << "----- Waiting List -----\n";

    while (!temp.empty()) {
        Reservation r = temp.front();

        cout << "Reservation ID: " << r.reservationID << endl;
        cout << "Student: " << r.studentName << endl;
        cout << "Resource: " << r.resource << endl;
        cout << "Date: " << r.date << endl;
        cout << "Time: " << r.time << endl;

        temp.pop();
    }
}


// Milestone 2 - Search reservation by ID
// Linear Search O(n)
void searchReservation(int reservationID) {

    ReservationNode* current = head;

    while (current != nullptr) {

        if (current->data.reservationID == reservationID) {

            cout << "\n--- Reservation Found ---" << endl;
            current->data.display();
            return;
        }

        current = current->next;
    }

    cout << "Reservation not found." << endl;
}


// Milestone 2 - Count active reservations for a resource
// O(n)
int countReservationsForResource(const string& resourceID) {

    int count = 0;

    ReservationNode* current = head;

    while (current != nullptr) {

        if (current->data.resource == resourceID) {
            count++;
        }

        current = current->next;
    }

    return count;
}


// Milestone 2 - Merge two sorted portions
// O(n) for the combined portions
void mergeReservations(
    vector<Reservation>& reservations,
    int left,
    int middle,
    int right
) {

    vector<Reservation> leftSide;
    vector<Reservation> rightSide;

    for (int i = left; i <= middle; i++) {
        leftSide.push_back(reservations[i]);
    }

    for (int i = middle + 1; i <= right; i++) {
        rightSide.push_back(reservations[i]);
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < static_cast<int>(leftSide.size()) &&
           j < static_cast<int>(rightSide.size())) {

        if (leftSide[i].date <= rightSide[j].date) {
            reservations[k] = leftSide[i];
            i++;
        }
        else {
            reservations[k] = rightSide[j];
            j++;
        }

        k++;
    }

    while (i < static_cast<int>(leftSide.size())) {
        reservations[k] = leftSide[i];
        i++;
        k++;
    }

    while (j < static_cast<int>(rightSide.size())) {
        reservations[k] = rightSide[j];
        j++;
        k++;
    }
}


// Milestone 2 - Merge Sort
// O(n log n)
void mergeSortReservations(
    vector<Reservation>& reservations,
    int left,
    int right
) {

    if (left >= right) {
        return;
    }

    int middle = left + (right - left) / 2;

    mergeSortReservations(reservations, left, middle);
    mergeSortReservations(reservations, middle + 1, right);

    mergeReservations(reservations, left, middle, right);
}


// Milestone 2 - Sort reservations by date
// O(n log n)
void sortReservationsByDate() {

    if (head == nullptr) {
        cout << "No active reservations to sort." << endl;
        return;
    }

    vector<Reservation> reservations;

    ReservationNode* current = head;

    while (current != nullptr) {
        reservations.push_back(current->data);
        current = current->next;
    }

    mergeSortReservations(
        reservations,
        0,
        static_cast<int>(reservations.size()) - 1
    );

    cout << "\n===== Reservations Sorted by Date =====" << endl;

    for (const Reservation& reservation : reservations) {
        reservation.display();
    }
}


// Milestone 2 - Count students waiting for a resource
// O(n)
int countWaitingForResource(const string& resourceID) {

    int count = 0;

    queue<Reservation> temp = waitingList;

    while (!temp.empty()) {

        Reservation reservation = temp.front();

        if (reservation.resource == resourceID) {
            count++;
        }

        temp.pop();
    }

    return count;
}


// Milestone 2 - Waiting-list statistics report
// O(r * w), where r is resources and w is waiting entries
void waitingListStatisticsReport() {

    extern vector<Resource> resources;

    cout << "\n===== Waiting List Statistics =====" << endl;

    if (resources.empty()) {
        cout << "No resources available." << endl;
        return;
    }

    int totalWaiting = 0;

    for (const Resource& resource : resources) {

        int count = countWaitingForResource(
            resource.getResourceID()
        );

        cout << "Resource: "
             << resource.getResourceName()
             << endl;

        cout << "Resource ID: "
             << resource.getResourceID()
             << endl;

        cout << "Students Waiting: "
             << count
             << endl;

        cout << "------------------------" << endl;

        totalWaiting += count;
    }

    cout << "Total Students Waiting: "
         << totalWaiting
         << endl;
}
