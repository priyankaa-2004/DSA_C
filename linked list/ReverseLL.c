// Code to reverse a linked list

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

struct Node* head=NULL;

// Function to reverse a linked list
struct Node* reverseLinkedList(struct Node* head) {
    struct Node* prev = NULL;//'prev' is initialized to NULL because there is no previous node to the head node initially.
    struct Node* current = head; //current is set to the head of the original linked list. This pointer will traverse the list from the head to the tail.
    struct Node* next = NULL;//next is initialized to NULL. It will temporarily hold the next node in the original list.

    while (current != NULL) { //The loop continues until current becomes NULL, which means we have iterated through the entire original list.
        next = current->next;  // This line saves the next node (current->next) in the variable next. This is necessary because once we modify the current->next pointer to point to the previous node (prev), we'll lose the reference to the next node in the original list.
        current->next = prev; // This line reverses the direction of the next pointer of the current node. It makes current point to the prev node, effectively reversing the link between current and the next node.

        // Move pointers one position ahead
        prev = current; //The prev pointer is moved one step forward to the current node. This prepares prev for the next iteration, as it becomes the new previous node.
        current = next; //The current pointer is moved one step forward to the next node. This prepares current for the next iteration by moving it to the next node in the original list.
    }

    // After the loop completes, the prev pointer will be pointing to the last node of the original list, which is the new head of the reversed list. So, we update the head pointer to point to prev.
    head = prev;

    return head;
}

// Function to insert a new node at the beginning of the linked list
void InsertAtBeginning(int data){
    struct Node* new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->next=head;
    new_node->data=data;
    head=new_node;
}

// Function to print the linked list
void print(struct Node *ptr)  
{ 
    //printf("elements in linked list:");
    while (ptr != NULL) 
    { 
        printf("%d -> ", ptr->data);
        ptr = ptr->next; 
    }
}

int main() {
    //head = NULL;

    // Insert elements at the beginning
    InsertAtBeginning(5);
    InsertAtBeginning(4);
    InsertAtBeginning(3);
    InsertAtBeginning(2);
    InsertAtBeginning(1);

    printf("Original Linked List: ");
    print(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    printf("\n");
    printf("Reversed Linked List: ");
    print(head);

    return 0;
}
