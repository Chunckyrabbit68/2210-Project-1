#include <iostream>
#include <string>

using namespace std;

// Resource and reservation functions from project.c++
void loadResources(const string& filename);
void displayResources();
void displayAvailability();
void createReservation();

// Linked list and waiting list functions from ComplexityTest.cpp
void displayReservations();
void displayWaitingList();
void processWaitingList();

// Cancellation functions
void cancelReservation(int reservationID);
void restoreCancellation();
void displayCancellationHistory();

int main() {

  loadResources("resources.txt");

  int choice;

  do {

    cout << "\nCampus Resource Reservation System" << endl;
    cout << "1. Display all resources" << endl;
    cout << "2. Display resource availability" << endl;
    cout << "3. Create reservation" << endl;
    cout << "4. Display active reservations" << endl;
    cout << "5. Display waiting list" << endl;
    cout << "6. Process waiting list" << endl;
    cout << "7. Cancel reservation" << endl;
    cout << "8. Restore cancelled reservation" << endl;
    cout << "9. Display cancellation history" << endl;
    cout << "10. Exit" << endl;

    cout << "Enter choice: ";
    cin >> choice;

    switch(choice){

      case 1:
        displayResources();
        break;

      case 2:
        displayAvailability();
        break;

      case 3:
        createReservation();
        break;

      case 4:
        displayReservations();
        break;

      case 5:
        displayWaitingList();
        break;

      case 6:
        processWaitingList();
        break;

      case 7: {
        int reservationID;

        cout << "Enter reservation ID to cancel: ";
        cin >> reservationID;

        cancelReservation(reservationID);
        break;
      }

      case 8:
        restoreCancellation();
        break;

      case 9:
        displayCancellationHistory();
        break;

      case 10:
        cout << "Exiting program." << endl;
        break;

      default:
        cout << "Invalid choice. Try again." << endl;
    }

  } while(choice != 10);

  return 0;
}
