//Creating a linked list with user input data 
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    int size;
    printf("Enter the size of list: ");
    scanf("%d", &size);
    struct node *head = malloc(sizeof(struct node));
    printf("Enter list items: \n");
    scanf("%d", &(head->data));
    head->next = NULL;
    int i;
    struct node *pointer;
    pointer = head;
    for (i = 1; i < size; i++)
    {
        struct node *newnode = malloc(sizeof(struct node));
        scanf("%d", &(newnode -> data));
        newnode -> next =NULL;
        pointer-> next= newnode;
        pointer = newnode;
    }
    linkedListTraversal(head);
    return 0;
}