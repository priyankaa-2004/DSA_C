#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the circular linked list
struct Node {
    int data;
    struct Node *next;
};

struct Node* head = NULL;

// Function to insert a node at the head of a circular linked list
struct Node* insertAtHead(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) { // If the list is empty, make the new node point to itself
        newNode->next = newNode;
        head = newNode;
    } else {
        // Make the new node point to the current head
        newNode->next = head->next;
        // Update the head's next pointer to the new node
        head->next = newNode;
    }
    return head; // Return the updated head pointer
}

// Function to display the circular linked list
void displayList() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* current = head->next; // Start from the head
    printf("elements of circular linked list: ", current->data);
    do {
        printf("%d,", current->data);
        current = current->next;
    } while (current != head->next);
    printf("\n");
}

int main() {
    // Insert nodes at the head
    insertAtHead(3);
    insertAtHead(2);
    insertAtHead(1);

    // Display the circular linked list
    displayList();

    return 0;
}