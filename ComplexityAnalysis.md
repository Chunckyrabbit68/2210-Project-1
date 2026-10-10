This document explains the time complexity of the main data structure operations used in the Campus Resource Reservation System.

Reservation Insertion - O(1)

Active reservations are stored in a linked list. The node is linked in at the beginning of the list - constant time operation.

newNode->next = head;
head = newNode;

insertReservation() inserts the reservation directly into the linked list. However, createReservation() calls reservationExists() before inserting to confirm that the reservation ID is not already being used.

Link step: O(1)

Duplicate ID check: O(n)

Time Complexity for insertion: O(1)

Overall Reservation Creation: O(n)

Reservation Removal - O(n)

Removing a reservation requires searching through the linked list until the matching reservation ID is found.

while(current != nullptr){

In the worst case, the reservation could be the last node in the list or may not exist. This means every reservation may need to be checked.

Search step: O(n)

Removal step: O(1)

Time Complexity: O(n)

Waiting List Processing - O(n) Overall

The waiting list uses a queue. Accessing and removing the first reservation from the queue takes constant time.

Reservation nextReservation = waitingList.front();
waitingList.pop();

These queue operations are O(1).

However, the program also calls findResource() before activating the reservation. The resources are stored in a vector, so the program may have to search through all resources to find a matching resource ID.

Because of this search, the complete processWaitingList() function has a worst-case complexity of O(n).

Queue Operations: O(1)

Resource Search: O(n)

Overall Waiting List Processing: O(n)

Undo Cancellation - O(n) Overall

Cancellation history is stored using a stack. Retrieving and removing the most recently cancelled reservation uses:

cancellationHistory.top();
cancellationHistory.pop();

Both stack operations take constant time.

restoreCancellation() searches the resource vector using findResource() to confirm that the resource exists and is available.

The reservation is then inserted back into the linked list.

Resource Lookup: O(n)

Stack Operations: O(1)

Linked List Insertion: O(1)

Overall Undo Cancellation: O(n)

Linear Search - O(n)

Milestone 2 adds Linear Search to search for resources and reservations using their IDs.

The program checks each resource or reservation until the matching ID is found.

For resources, the program searches through the vector.

for (Resource& resource : resources) {
    if (resource.getResourceID() == resourceID) {
        return &resource;
    }
}

For reservations, the program searches through the linked list.

while (current != nullptr) {
    if (current->data.reservationID == reservationID) {
        current->data.display();
        return;
    }
    current = current->next;
}

In the worst case, the resource or reservation could be the last element or may not exist.

The algorithm was implemented manually without using library searching functions.

Resource Search: O(n)

Reservation Search: O(n)

Time Complexity: O(n)

Space Complexity: O(1)

Merge Sort - O(n log n)

Milestone 2 adds Merge Sort to sort active reservations by date.

The program copies reservations from the linked list into a vector.

Merge Sort divides the vector into smaller sections and then merges them back together in sorted order.

mergeSortReservations(reservations, left, middle);
mergeSortReservations(reservations, middle + 1, right);
mergeReservations(reservations, left, middle, right);

The algorithm divides the reservations into halves until each section contains one element.

The sections are then compared and merged back together in order.

Merge Sort has O(log n) levels and performs O(n) work at each level.

The algorithm was implemented manually without using library sorting functions.

Time Complexity: O(n log n)

Space Complexity: O(n)

Active Reservations Report - O(n)

The active reservations report displays all reservations currently stored in the linked list.

The program uses displayReservations() to traverse the list and display each reservation.

In the worst case, every reservation must be visited.

Time Complexity: O(n)

Resource Utilization Report - O(r * n)

The resource utilization report displays each resource and the number of active reservations associated with it.

The program calls countReservationsForResource() for each resource.

This function searches through the linked list and counts reservations matching the resource ID.

Because the program checks all reservations for each resource, the time complexity depends on the number of resources and reservations.

Resource Traversal: O(r)

Reservation Counting: O(n)

Overall Time Complexity: O(r * n)

Most Requested Resources Report - O(r * n)

The most requested resources report finds the resources with the highest number of active reservations.

The program counts active reservations for each resource and stores the results in a vector.

It then searches the counts to find the highest value and displays the matching resources.

The current report uses active reservations rather than all historical requests.

Reservation Counting: O(r * n)

Finding Highest Count: O(r)

Overall Time Complexity: O(r * n)

Waiting List Statistics - O(r * w)

The waiting-list statistics report displays the number of students waiting for each resource.

The program uses countWaitingForResource() to check the waiting-list queue and count matching resource IDs.

For each resource, the program checks the waiting list.

The program also displays the total number of students currently waiting.

Resource Traversal: O(r)

Waiting List Counting: O(w)

Overall Time Complexity: O(r * w)

Additional Operations

Displaying active reservations requires traversing the entire linked list.

Display Active Reservations: O(n)

Checking if a reservation ID already exists requires searching through the linked list.

Reservation ID Check: O(n)

Adding a reservation to the waiting list uses the queue push() operation.

Add to Waiting List: O(1)

Displaying the waiting list requires processing each reservation in the queue.

Display Waiting List: O(n)

Displaying cancellation history requires processing each reservation stored in the stack.

Display Cancellation History: O(n)

Displaying all resources requires traversing the resource vector.

Display Resources: O(r)

Displaying resource availability requires traversing the resource vector.

Display Resource Availability: O(r)
