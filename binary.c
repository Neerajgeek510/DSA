#include<stdio.h>
#include<stdlib.h>

typedef struct Treenode{
    int data;
    struct Treenode*left;
    struct Treenode*right;
}tree;
 tree* createnode(int value){
    tree*newnode=(tree*)malloc(sizeof(tree));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
 }
 // manually tree ko bna rhe hai...
 int main(){
    tree* root=createnode(1);
    root->left=createnode(2);
    root->right=createnode(3);
    root->left->left=createnode(8);
    root->left->right=createnode(9);
    printf("Tree Root:%d\n",root->data);
    printf("Left child of Root:%d\n",root->left->data);
    printf("Right child of Root:%d\n",root->right->data);
    printf("Left child of Roots left child:%d\n",root->left->left->data);
    printf("Right child of Roots left child:%d\n",root->left->left->data);
    return 0;

 }