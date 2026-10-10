Project Overview

This project is for CSCE 2110 Milestone 1 and Milestone 2.

The program is a campus resource reservation system. It allows users to view resources, create reservations, cancel reservations, use a waiting list, restore cancelled reservations, search for resources and reservations, sort reservations, and generate reports.

The project uses a linked list, queue, stack, and vector.

Features

Resource management

Loads resources from resources.txt

Displays all resources

Displays whether a resource is available or unavailable

Searches for resources using their resource ID

Reservation management

Creates reservations

Cancels reservations

Displays active reservations

Checks if a resource ID is valid

Checks if a resource is available

Searches for reservations using their reservation ID

Sorts reservations by date

Linked list

The linked list stores active reservations.

It can insert reservations, remove reservations, and display all active reservations.

Waiting list

The waiting list uses a queue.

If a resource is unavailable, the reservation can be added to the waiting list.

The program can also process the waiting list and display everyone waiting.

Cancellation history

Cancellation history uses a stack.

Cancelled reservations are stored in the stack.

The program can restore the most recently cancelled reservation and display the cancellation history.

Searching

Milestone 2 adds Linear Search.

Linear Search is used to search for resources by resource ID and reservations by reservation ID.

The program checks each resource or reservation until it finds a matching ID.

The time complexity of Linear Search is O(n).

Sorting

Milestone 2 adds Merge Sort.

Merge Sort is used to sort active reservations by date.

The program divides the reservations into smaller sections and merges them back together in sorted order.

The time complexity of Merge Sort is O(n log n).

Reports

Milestone 2 adds four reports.

Active reservations report

Displays all active reservations.

Resource utilization report

Displays each resource and the number of active reservations associated with it.

Most requested resources report

Displays the resources with the highest number of active reservations.

Waiting-list statistics report

Displays the number of students waiting for each resource.

Files

main.cpp handles the menu and user choices.

project.c++ handles resources, creating reservations, cancelling reservations, restoring reservations, resource searching, and reporting.

ComplexityTest.cpp contains the linked list, queue, reservation searching, sorting, and waiting-list statistics code.

Resource.h and Resource.cpp contain the Resource class.

Reservation.h and Reservation.cpp contain the Reservation class.

resources.txt contains the resource information.

ComplexityAnalysis.md contains the Big O analysis.

README.md contains the project overview and user documentation.

Compile

Use this command to compile the project:

g++ main.cpp project.c++ ComplexityTest.cpp Resource.cpp Reservation.cpp -o project

Then run:

./project

Make sure resources.txt is in the same folder when running the program.

Menu

1 Display all resources

2 Display resource availability

3 Create reservation

4 Display active reservations

5 Display waiting list

6 Process waiting list

7 Cancel reservation

8 Restore cancelled reservation

9 Display cancellation history

10 Search resource by ID

11 Search reservation by ID

12 Sort reservations by date

13 Active reservations report

14 Resource utilization report

15 Most requested resources report

16 Waiting-list statistics report

17 Exit

User Documentation

Starting the program

Compile and run the program using the commands above.

The main menu will appear with 17 options.

Enter the number of the option you want to use.

Viewing resources

Option 1 displays all resources.

Option 2 displays whether each resource is available or unavailable.

Creating reservations

Option 3 allows the user to create a reservation.

The program asks for a reservation ID, student ID, student name, resource ID, date, and time.

Dates should be entered in YYYY-MM-DD format.

If the resource is available, the reservation is created.

If the resource is unavailable, the reservation is added to the waiting list.

Viewing and cancelling reservations

Option 4 displays all active reservations.

Option 7 cancels a reservation using its reservation ID.

Option 8 restores the most recently cancelled reservation if the resource is available.

Option 9 displays the cancellation history.

Waiting list

Option 5 displays the waiting list.

Option 6 processes the next reservation in the waiting list if its resource is available.

Searching

Option 10 searches for a resource using its resource ID.

Option 11 searches for an active reservation using its reservation ID.

If the ID does not exist, the program displays a message.

Sorting

Option 12 sorts active reservations by date using Merge Sort.

The sorted reservations are displayed in date order.

Reports

Option 13 displays the active reservations report.

Option 14 displays the resource utilization report.

Option 15 displays the most requested resources report based on active reservation counts.

Option 16 displays the waiting-list statistics report.

Exiting

Option 17 exits the program.

Testing

The program was tested during development by creating reservations, cancelling reservations, adding reservations to the waiting list, processing the waiting list, restoring cancelled reservations, and entering invalid input.

Milestone 2 adds testing for searching resources, searching reservations, sorting reservations by date, and generating reports.

Additional testing should include invalid IDs, empty lists, duplicate reservation IDs, and unavailable resources.
