#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;
static int sumofallele = 0;
/*
 
 * Create a binary tree with the following elements

 * int nums[] = {7, 3, 11, 1, 5, 9, 22, 0, 2, 4, 6, 8, 10, 18, 36}

 * Tree will look like:
                          7

              3                               11

          1           5               9               22

      0       2   4       6       8    10         18      36

 * Print the tree elements (in any order)

 * Return the sum of all elements of the tree
 */

Node *createNode(int val){
    Node *new = (Node *)malloc(sizeof(Node));
    if(NULL == new){
        printf("mem allocation failed ");
        exit(1);
    }
    new->left = new->right = NULL;
    new->data = val;
    return new;
}
void addnode(Node **root, int val){
    Node *new = createNode(val);
    Node *r=*root;
    if(*root == NULL){
        *root = new;
    }else{
        if(r->data >= val){
            addnode(&r->left, val);
        }else if (r->data < val){
            addnode(&r->right, val);
        }
    }
}

int printtree(Node *root, int *sumofallele){
    if(root == NULL){
        return NULL;
    }
    printf("%d ", root->data);
    *sumofallele += root->data;
    printtree(root->right, sumofallele);
    printtree(root->left, sumofallele);
}
int main() {

    /* 1. Create binary tree with above values */
    int nums[] = {7, 3, 11, 1, 5, 9, 22, 0, 2, 4, 6, 8, 10, 18, 36};
    int len = sizeof(nums)/sizeof(nums[0]);
    Node *root = NULL;
    for(int i=0;i<len;i++)
        addnode(&root, nums[i]);
    printtree(root, &sumofallele);
    printf("sum of all the elements %d\n", sumofallele);
    /* 2. Print the tree elements (in any order) */
    
    /* 3. Return the sum of all elements in the binary tree */

    return 0;
}
