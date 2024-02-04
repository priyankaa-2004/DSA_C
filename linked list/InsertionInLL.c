#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

void print(struct Node *ptr)  
{ 
    printf("elements in linked list:");
    while (ptr != NULL) 
    { 
        printf("%d,", ptr->data);
        ptr = ptr->next; 
    }
}
//case1
void InsertAtBeginning(int data){
    struct Node* new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->next=head;
    new_node->data=data;
    head=new_node;
}
//case2
void InsertAtIndex(int index,int data){
    struct Node* new_node=(struct Node *)malloc(sizeof(struct Node));
    struct Node* p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    new_node->data=data;
    new_node->next=p->next;
    p->next=new_node;
}
//case3
void InsertAtEnd(int data){
    struct Node* new_node=(struct Node *)malloc(sizeof(struct Node));
    struct Node* p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    new_node->data=data;
    p->next=new_node;
    new_node->next=NULL;
}
//case4
void InsertAfterNode(struct Node* prev_node,int data){
    struct Node* new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=data;

    new_node->next=prev_node->next;
    prev_node->next=new_node;

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

    //InsertAtBeginning(55);
    InsertAtIndex(3,40);
    //InsertAtEnd(12);
    //InsertAfterNode(second,46);
    print(head);

    return 0;
}