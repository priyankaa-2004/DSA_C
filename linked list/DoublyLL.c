#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head;

int main(){
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    head->data=10;
    head->prev=NULL;
    head->next=second;

    second->data=9;
    second->prev=head;
    second->next=third;

    third->data=2;
    third->prev=second;
    third->next=fourth;

    fourth->data=5;
    fourth->prev=third;
    fourth->next=NULL;

    return 0;
}