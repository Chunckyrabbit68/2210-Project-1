int main() {
    loadResources("resources.txt");

    int choice;

    do {
        cout << "\nCampus Resource Reservation System" << endl;
        cout << "1. Display all resources" << endl;
        cout << "2. Display resource availability" << endl;
        cout << "3. Create reservation" << endl;
        cout << "4. Display active reservations" << endl;
        cout << "5. Cancel reservation" << endl;
        cout << "6. Restore cancelled reservation" << endl;
        cout << "7. Display cancellation history" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
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

            case 5: {
                int reservationID;

                cout << "Enter reservation ID to cancel: ";
                cin >> reservationID;

                cancelReservation(reservationID);
                break;
            }

            case 6:
                restoreCancellation();
                break;

            case 7:
                displayCancellationHistory();
                break;

            case 8:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 8);

    return 0;
}
