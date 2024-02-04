#include <stdio.h>
#include <stdlib.h> //since we are using malloc

struct Node   // node using structure created 
{ 
    int data;
    struct Node *next; // struct node type ka pointer
};

struct Node *head;

//traversal 
void traverse_linkedlist(struct Node *ptr)   // ek aisa pointer(ptr) chahiye jo struct Node type ka ho aur head ko point karta ho
{ 
    while (ptr != NULL)   // print the elements of list untill ptr=null
    { 
        printf("elements in linked list:");
        printf("%d,", ptr->data);
        ptr = ptr->next; // update pointer
    }
}

int main()
{
    struct Node *second; // second node
    struct Node *third;  // third node

    // memory allocation of the 3 nodes created in a linked list in heap(not in stack)
    // dynamic allocation of memory
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // linking first and second list
    head->data = 10;
    head->next = second;

    // linking second and third list
    second->data = 23;
    second->next = third;

    // terminating list and third node
    third->data = 42;
    third->next = NULL;

    traverse_linkedlist(head); // head ek pointer hai struct node* type ka
    return 0;
}