# 2210-Project-1
Project Overview

This project is for CSCE 2110 Milestone 1.

The program is a campus resource reservation system. It allows users to view resources, create reservations, cancel reservations, use a waiting list, and restore cancelled reservations.

The project uses a linked list, queue, and stack.

Features

Resource management

Loads resources from resources.txt

Displays all resources

Displays whether a resource is available or unavailable

Reservation management

Creates reservations

Cancels reservations

Displays active reservations

Checks if a resource ID is valid

Checks if a resource is available

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

Files

main.cpp handles the menu and user choices.

project.c++ handles resources, creating reservations, cancelling reservations, and restoring reservations.

ComplexityTest.cpp contains the linked list and queue code.

Resource.h and Resource.cpp contain the Resource class.

Reservation.h and Reservation.cpp contain the Reservation class.

resources.txt contains the resource information.

ComplexityAnalysis.md contains the Big O analysis.

Compile

Use this command to compile the project:

g++ main.cpp project.c++ ComplexityTest.cpp Resource.cpp Reservation.cpp -o project

Then run:

./project
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

10 waiting list removal

11 Exit

Testing

The program was tested by creating reservations, cancelling reservations, adding reservations to the waiting list, processing the waiting list, restoring cancelled reservations, and entering invalid input.

GitHub

The project was worked on using GitHub.

We used branches, commits, pull requests, and merges to work on the project together.
