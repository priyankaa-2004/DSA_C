//traversal in binary trees:

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
};

void preorder(struct node * root){
    if(root!=NULL){
        printf("%d  ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
};

void postorder(struct node * root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d  ",root->data);
    }
}

void inorder(struct node * root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d  ",root->data);
        inorder(root->right);
    }
}


int main()
{
    struct node *p = createnode(4);
    struct node *p1 = createnode(1);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(5);
    struct node *p4 = createnode(2);
    /*          4
               / \
              1   6
             / \
            5   2
    */

    // linking root node with second and third node
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("Preorder: ");
    preorder(p);
    printf("\n");
    printf("Postorder: ");
    postorder(p);
    printf("\n");
    printf("Inorder: ");
    inorder(p);

    return 0;
}