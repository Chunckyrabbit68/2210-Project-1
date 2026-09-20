# 2210-Project-1

Resource Management

The Resource Management portion of the system handles campus resource information.

Features implemented include:

Loading resource information from resources.txt
Storing resource information in the program
Displaying all resources
Displaying resource availability
Searching for a resource using its resource ID
Updating resource status when a reservation is created or cancelled

Resources are stored using the Resource class.

The resource file uses the following format:

ResourceID|ResourceName|ResourceType|Status

Example:

R101|Study Room 101|Study Room|Available

Reservation Management

The Reservation Management portion handles the creation and validation of reservations.

Features implemented include:

Creating new reservations
Validating resource IDs
Checking whether a resource is available before creating a reservation
Storing reservation information
Displaying active reservations
Updating resource availability after a reservation is created
Providing reservation information for cancellation and restoration features

Reservations use the Reservation class and contain:

Reservation ID
Student ID
Student name
Resource ID
Reservation date
Reservation time

When a reservation is created, the system verifies that the requested resource exists and is available. After a successful reservation, the resource status is changed to Unavailable.

Files Used

Resource.h - Defines the Resource class
Resource.cpp - Implements Resource functions
Reservation.h - Defines the Reservation class
Reservation.cpp - Implements Reservation functions
resources.txt - Stores resource data
reservations.txt - Stores reservation data
