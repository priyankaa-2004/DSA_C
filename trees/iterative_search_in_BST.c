// searching an node in a BST
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

struct node *iterative_search(struct node *root, int value)
{
    while (root != NULL)
    {
        if (value == root->data)
        {
            return root;
        }
        else if (value < root->data)//
        {
            root = root->left;//jo root abhi root par point kar raha tha vo left subtree ki root par point kare,i.e,root 5 pr tha abb 3 par aa jayega
        }
        else
        {
            root = root->right;//similarly for right
        }
    }
    return NULL;
}

int main()
{
    struct node *p = createnode(5);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(4);
    /*          5
               / \
              3   6
             / \
            1   4
    */
    // linking root node with second and third node
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    struct node *n = iterative_search(p, 4);
    if (n != NULL)
    {
        printf("found: %d", n->data);
    }
    else
    {
        printf("not found");
    }
    return 0;
}