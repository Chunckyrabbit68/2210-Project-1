# Testing Report

This document explains the testing performed on the Campus Resource Reservation System for CSCE 2110 Milestone 2.

Testing

The program was run to check that the main menu displays all 17 options.

Resource Management

Test 1: Display all resources

Expected Result: The program displays the resources loaded from resources.txt.

Test 2: Display resource availability

Expected Result: The program displays whether each resource is available or unavailable.

Reservation Management

Test 3: Create a reservation

Expected Result: The program creates a reservation when the resource is available.

Test 4: Cancel a reservation

Expected Result: The reservation is removed from the linked list and added to cancellation history.

Test 5: Restore a cancelled reservation

Expected Result: The most recently cancelled reservation is restored if its resource is available.

Waiting List

Test 6: Add a reservation to the waiting list

Expected Result: The reservation is added to the queue when its resource is unavailable.

Test 7: Process the waiting list

Expected Result: The first waiting reservation is processed if its resource becomes available.

Searching

Test 8: Search for an existing resource

Expected Result: The matching resource is displayed.

Test 9: Search for an invalid resource ID

Expected Result: The program displays a message that the resource was not found.

Test 10: Search for an existing reservation

Expected Result: The matching reservation is displayed.

Test 11: Search for an invalid reservation ID

Expected Result: The program displays a message that the reservation was not found.

Sorting

Test 12: Sort reservations by date

Expected Result: The program displays active reservations in date order.

Reporting

Test 13: Active reservations report

Expected Result: The program displays all active reservations.

Test 14: Resource utilization report

Expected Result: The program displays the number of active reservations for each resource.

Test 15: Most requested resources report

Expected Result: The program displays the resources with the highest active reservation counts.

Test 16: Waiting-list statistics report

Expected Result: The program displays the number of waiting reservations for each resource.

Invalid Input

Test 17: Enter an invalid menu option

Expected Result: The program displays an invalid choice message.

Test 18: Enter a duplicate active reservation ID

Expected Result: The program rejects the duplicate reservation ID.

Final Testing

Each test should be marked Pass or Fail after running it and comparing the actual result with the expected result.

The program must also be compiled and tested on the UNT CSE CELL machines before submission.
