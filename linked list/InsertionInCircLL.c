//insertion in circular linked list

#include<stdio.h>
#include<stdlib.h>
 
struct Node
{
    int data;
    struct Node *next;
};

struct Node* head;
 
void linkedListTraversal(struct Node *head){
    struct Node *ptr = head;
    do{
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
}
 
void insertAtFirst(int data){
    struct Node * new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = data;
 
    struct Node * p = head;
    while(p->next != head){
        p = p->next;
    }
    // At this point p points to the last node of this circular linked list
    p->next = new_node;
    new_node->next = head;
    head = new_node;
}

void insertAtIndex(int index,int data){
    struct Node * new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = data;
    struct Node * p = head;
    int i=0;
    while(i!= index-1){
        p = p->next;
        i++;
    }
    new_node->next=p->next;
    p->next=new_node;
}

void insertAtEnd(int data){
    struct Node * new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = data;
    struct Node * p = head;
    while(p->next!=head){
        p=p->next;
    }
    p->next=new_node;
    new_node->next=head;
}
 
int main(){
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
 
    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
 
    // Link first and second nodes
    head->data = 4;
    head->next = second;
 
    // Link second and third nodes
    second->data = 3;
    second->next = third;
 
    // Link third and fourth nodes
    third->data = 6;
    third->next = fourth;
 
    // Terminate the list at the third node
    fourth->data = 1;
    fourth->next = head;

    insertAtFirst(7);
    insertAtFirst(56);
    insertAtIndex(2,88);
    insertAtEnd(9);
    linkedListTraversal(head);
 
    return 0;
}
