Complexity Analysis
This document explains the time complexity of the main data structure operations used in the Campus Resource Reservation System.

Reservation Insertion - O(1)

Active reservations are stored in a linked list. New reservations are inserted at the beginning of the linked list.
The new node points to the current head, and then the head is changed to point to the new node.

newNode->next = head;
head = newNode;

Because the program does not need to search through the linked list, reservation insertion takes constant time.

Time Complexity: O(1)
Reservation Removal - O(n)

Removing a reservation requires searching through the linked list until the matching reservation ID is found.

while(current != nullptr){

In the worst case, the reservation could be the last node in the list or may not exist. This means every reservation may need to be checked.

Time Complexity: O(n)

Waiting List Processing - O(n) Overall

The waiting list uses a queue. Accessing and removing the first reservation from the queue takes constant time.

Reservation nextReservation = waitingList.front();
waitingList.pop();

These queue operations are O(1).
However, the program also calls findResource() before activating the reservation. The resources are stored in a vector, so the program may have to search through all resources to find a matching resource ID.

Because of this search, the complete processWaitingList() function has a worst-case complexity of O(n).

Queue Operations: O(1)
Overall Waiting List Processing: O(n)

Undo Cancellation - O(n) Overall

Cancellation history is stored using a stack. Retrieving and removing the most recently cancelled reservation uses:

cancellationHistory.top();
cancellationHistory.pop();

Both stack operations take constant time.
The restored reservation is also inserted at the beginning of the linked list using insertReservation(), which is O(1).

However restoreCancellation() also calls findResource() to locate the resource being restored. Because resources are stored in a vector, this search can take linear time.

Stack Operations: O(1)
Linked List Insertion: O(1)
Overall Undo Cancellation: O(n)

Additional Operations

Displaying active reservations requires traversing the entire linked list.
Display Active Reservations: O(n)

Adding a reservation to the waiting list uses the queue push() operation.

Add to Waiting List: O(1)

Displaying the waiting list requires processing each reservation in the queue.

Display Waiting List: O(n)

Displaying cancellation history requires processing each reservation stored in the stack.

Display Cancellation History: O(n)
