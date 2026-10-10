This project is for CSCE 2110 Milestone 1 and Milestone 2.

The program is a campus resource reservation system. It allows users to view resources, create reservations, cancel reservations, use a waiting list, restore cancelled reservations, search for resources and reservations, sort reservations, and generate reports.

The project uses a linked list, queue, stack, and vector.

Milestone 2 adds searching, sorting, reporting, and system integration.

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

The linked list is also used when searching for reservations and counting active reservations.

Waiting list

The waiting list uses a queue.

If a resource is unavailable, the reservation can be added to the waiting list.

The program can also process the waiting list and display everyone waiting.

The waiting list is also used to generate waiting-list statistics.

Cancellation history

Cancellation history uses a stack.

Cancelled reservations are stored in the stack.

The program can restore the most recently cancelled reservation and display the cancellation history.

Searching

Milestone 2 adds Linear Search.

Linear Search is used to search for resources by resource ID and reservations by reservation ID.

The algorithm checks each resource or reservation until it finds a matching ID.

If the ID is not found, the program displays a message.

Linear Search was implemented manually without using library searching functions.

The time complexity of Linear Search is O(n).

Sorting

Milestone 2 adds Merge Sort.

Merge Sort is used to sort active reservations by date.

The algorithm divides the reservations into smaller groups, sorts them, and merges them back together in order.

The reservations are copied into a vector before sorting.

The sorted reservations are then displayed to the user.

Dates should be entered in YYYY-MM-DD format so they are sorted correctly.

Merge Sort was implemented manually without using library sorting functions.

The time complexity of Merge Sort is O(n log n).

Reporting

Milestone 2 adds four reporting features.

Active reservations report

Displays all active reservations currently stored in the linked list.

Resource utilization report

Displays each resource and the number of active reservations associated with it.

Most requested resources report

Displays the resources with the highest number of active reservations.

This report currently uses active reservations rather than total historical requests.

Waiting-list statistics report

Displays each resource and the number of students currently waiting for it.

It also displays the total number of students waiting.

The reports use the data stored in the system.

System integration

All project components are connected through the main menu.

The program allows users to access resource management, reservation management, searching, sorting, and reporting in one system.

The program also handles invalid menu choices and some invalid user inputs.

Files

main.cpp handles the menu and user choices.

project.c++ handles resources, creating reservations, cancelling reservations, restoring reservations, resource searching, and reporting.

ComplexityTest.cpp contains the linked list, queue, reservation searching, Merge Sort, and waiting-list statistics code.

Resource.h and Resource.cpp contain the Resource class.

Reservation.h and Reservation.cpp contain the Reservation class.

resources.txt contains the resource information.

ComplexityAnalysis.md contains the Big O analysis.

README.md contains the project overview and instructions.

UserDocumentation.md contains instructions for using the program.

TestingReport.md contains the testing results.

GroupContributionReport.md contains the contributions made by each group member.

Compile

Use this command to compile the project:

g++ -std=c++11 main.cpp project.c++ ComplexityTest.cpp Resource.cpp Reservation.cpp -o project

Then run:

./project

Make sure resources.txt is in the same directory when running the program.

The final project must also be compiled and tested on the UNT CSE CELL machines.

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

Testing

The program was tested during development by running the menu and checking the main features.

Testing includes creating reservations, cancelling reservations, adding reservations to the waiting list, processing the waiting list, restoring cancelled reservations, and entering invalid input.

Milestone 2 testing also includes searching for resources, searching for reservations, sorting reservations by date, and generating reports.

Additional testing should include searching for IDs that do not exist, sorting multiple reservations, checking resource utilization counts, and checking waiting-list statistics.

The program should also be tested with duplicate reservation IDs, empty lists, and unavailable resources.

The final testing results are documented in TestingReport.md.

GitHub

The project was worked on using GitHub.

We used branches, commits, pull requests, and merges to work on the project together.

Milestone 2 updates include searching, sorting, reporting, and integration with the existing system.

The final source code, header files, and README should match the files in the GitHub repository.
