#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

void traverse_circular_LL(struct Node* ptr)   // ek aisa pointer(ptr) chahiye jo struct Node type ka ho aur head ko point karta ho
{ 
    /*struct Node* ptr=head;
    printf("elements in linked list: %d\n",ptr->data);  // giving the LL a head start other wise it will never enter the while loop
    ptr = ptr->next; // update pointer
    while (ptr != head)   // print untill ptr is head, but ptr is head from the start, so to make the loop run, we need a headstart 
    { 
        printf("elements in linked list:");
        printf("%d,", ptr->data);
        ptr = ptr->next; // update pointer
    }*/
    //OR
    printf("elements in linked list:");
    do{
        printf("%d,", ptr->data);
        ptr=ptr->next;
    }
    while(ptr!=head);
}

struct Node* insert_at_head(int data){
    struct Node* new_node;
    new_node->data=data;

     if (head == NULL) {
        // If the list is empty, make the new node point to itself
        new_node->next = new_node;
        head = new_node;
    } else {
        // Make the new node point to the current head
        new_node->next = head->next;
        // Update the tail's next pointer to the new node
        head->next = new_node;
    }
    return head;
}

int main(){
struct Node *second; 
    struct Node *third;  

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

    insert_at_head(3);
    traverse_circular_LL(head);
    return 0;
}