//checking if it is a binary search tree or not
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

int isBST(struct node * root){ //if this func return
    static struct node * prev=NULL; //this variable is to check the parent is null or not,,just to check for the root node bcz other elements won't have their parent as null
    if(root!=NULL){ //root null nahi hona chhaiye agar hua toh uss tree mein kuch hai hi nahi,,still use BST naam ke chalo
        if(!isBST(root->left)){ //call same func recursively for the left side and check whether the left subtree is a BST or not-->agar left wala subtree BST nahi hai toh yahin 0 return kar do
            return 0;
        }
        if(prev!=NULL && root->data<=prev->data){ /*since prev element is not null then it has some value  that is prev->data
                                                      prev!=null-->should not be first node
                                                       naya data<=pichla data */  
            return 0;
        }
        prev=root;  //sets the current node e.g, 5 to prev
        return isBST(root->right);  //call recursively for right subtree
    }
    else{
        return 1;
    }
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

    if(isBST(p)){//if ans=1-->BST, else if ans=0-->not BST
        printf("this is a binary search tree");
    }
    return 0;
}

