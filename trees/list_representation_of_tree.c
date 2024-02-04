//representation of binary tree in linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data){
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
};

int main(){

    /*//creating root node
    struct node *p=(struct node *)malloc(sizeof(struct node));
    p->data=2;
    p->left=NULL;
    p->right=NULL;

    //creating second node
    struct node *p1=(struct node *)malloc(sizeof(struct node));
    p1->data=1;
    p1->left=NULL;
    p1->right=NULL;

    //creating third node
    struct node *p2=(struct node *)malloc(sizeof(struct node));
    p2->data=4;
    p2->left=NULL;
    p2->right=NULL;

    
    -->DOING THIS INCREASES CODE REPETATION. RATHER WE CAN CREATE A FUNCTION FR THIS 
    */

   //creating nodes using function
   struct node *p=createnode(2);
   struct node *p1=createnode(1);
   struct node *p2=createnode(4);

    //linking root node with second and third node
    p->left=p1;
    p->right=p2;

    return 0;
}