#include <iostream>
#include <string>
#include <limits>

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

// Milestone 2 searching functions
void searchResource(const string& resourceID);
void searchReservation(int reservationID);

// Milestone 2 sorting function
void sortReservationsByDate();

// Milestone 2 reporting functions
void activeReservationsReport();
void resourceUtilizationReport();
void mostRequestedResourcesReport();
void waitingListStatisticsReport();

int main() {

    loadResources("resources.txt");

    int choice = 0;

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

        cout << "10. Search resource by ID" << endl;
        cout << "11. Search reservation by ID" << endl;
        cout << "12. Sort reservations by date" << endl;

        cout << "13. Active reservations report" << endl;
        cout << "14. Resource utilization report" << endl;
        cout << "15. Most requested resources report" << endl;
        cout << "16. Waiting list statistics report" << endl;

        cout << "17. Exit" << endl;

        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Please enter a number from 1 to 17." << endl;
            continue;
        }

        switch(choice) {

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

                if (!(cin >> reservationID)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Invalid reservation ID." << endl;
                    break;
                }

                cancelReservation(reservationID);
                break;
            }

            case 8:
                restoreCancellation();
                break;

            case 9:
                displayCancellationHistory();
                break;

            case 10: {
                string resourceID;

                cout << "Enter resource ID to search: ";
                cin >> resourceID;

                searchResource(resourceID);
                break;
            }

            case 11: {
                int reservationID;

                cout << "Enter reservation ID to search: ";

                if (!(cin >> reservationID)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Invalid reservation ID." << endl;
                    break;
                }

                searchReservation(reservationID);
                break;
            }

            case 12:
                sortReservationsByDate();
                break;

            case 13:
                activeReservationsReport();
                break;

            case 14:
                resourceUtilizationReport();
                break;

            case 15:
                mostRequestedResourcesReport();
                break;

            case 16:
                waitingListStatisticsReport();
                break;

            case 17:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while(choice != 17);

    return 0;
}
