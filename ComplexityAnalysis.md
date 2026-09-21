Complexity Analysis
This document explains the time complexity of the main data structure operations used in the Campus Resource Reservation System.

Reservation Insertion - O(n)

Active reservations are stored in a linked list. The node is linked in at the beginning of the list - constant time operation.

newNode->next = head;
head = newNode;

insertReservation() calls reservationExists() before linking the node this is used to confirm that the reservation ID is not already being used. 

Link step: O(1)
Duplicate ID check: O(n)
Time Complexity: O(n)
Reservation Removal - O(n)

Removing a reservation requires searching through the linked list until the matching reservation ID is found.

while(current != nullptr){

In the worst case, the reservation could be the last node in the list or may not exist. This means every reservation may need to be checked.

Link step: O(1) Duplicate ID check: O(n) Time complexity: O(n)

Waiting List Processing - O(n) Overall

The waiting list uses a queue. Accessing and removing the first reservation from the queue takes constant time.

Reservation nextReservation = waitingList.front();
waitingList.pop();

These queue operations are O(1).
However, the program also calls findResource() before activating the reservation. The resources are stored in a vector, so the program may have to search through all resources to find a matching resource ID.

processWaitingList() calls isResourceReserved() it traverses the linked list and confirms the date and time is still free.

Because of these searches, the complete processWaitingList() function has a worst-case complexity of O(n).

Queue Operations: O(1)
Overall Waiting List Processing: O(n)

Undo Cancellation - O(n) Overall

Cancellation history is stored using a stack. Retrieving and removing the most recently cancelled reservation uses:

cancellationHistory.top();
cancellationHistory.pop();

Both stack operations take constant time.

restoreCancellation() does three steps findResource() does the searching the resource vector, isResourceReserved() traverses the linked list and it confirms if the original time slot is free still then insertReservation() traverses the list again to check for duplicate IDs.

Each step is O(n), so the function is O(n).

Stack Operations: O(1)
Resource Lookup: O(n)
Time Slot Conflict Check: O(n)
Linked List Insertion: O(n)
Overall Undo Cancellation: O(n)

Additional Operations

Displaying active reservations requires traversing the entire linked list.
Display Active Reservations: O(n)

Checking if a resource is already booked for a date and time needs traversing the linked list of active reservations.
Time Slot Conflict Check: O(n)

Adding a reservation to the waiting list uses the queue push() operation.

Add to Waiting List: O(1)

Getting rid of a specific student's request from waiting list requires moving each entry out the queue and back since a queue only allows access to its front element.

Remove From Waiting List: O(n)

Displaying the waiting list requires processing each reservation in the queue.

Display Waiting List: O(n)

Displaying cancellation history requires processing each reservation stored in the stack.

Display Cancellation History: O(n)
