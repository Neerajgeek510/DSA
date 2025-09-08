#include<stdio.h>
#include<stdlib.h>

typedef struct Treenode{
    int data;
    struct Treenode*left,*right;

}tree;
tree* createnode(int value){
    tree*n=(tree*)malloc(sizeof(tree)); 
    n->data=value;
    n->left=NULL;
    n->right=NULL;
    return n;
}
tree*insert(tree*root,int value){
    if(root==NULL)
    return createnode(value);
    if(value < root->data)
    root->left = insert(root->left,value);
    if(value > root->data)
    root->right = insert(root->right,value);
    return root;

}
tree* reverse(tree*root){
   
    if(root==NULL)
    return NULL;
    tree*t=root->left;
    root->left=root->right;
    root->right=t;
    reverse(root->left);
    reverse(root->right);
    return root; 
}
void pre(tree* root){
    if(root!=NULL){
        printf("%d ",root->data);
        pre(root->left);
        pre(root->right);
    }
}
void post(tree* root){
    if(root!=NULL){
        post(root->left);
        post(root->right);
        printf("%d ",root->data);
    }
}
tree*del(tree*root,int key){
    if(root==NULL) return NULL;
    if (key<root->data) 
     root->left=del(root->left,key);
   else if (key>root->data) 
   root->right=del(root->right,key);
   else{
    // case 1: no child..
    if(root->left==NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    else if(root->left==NULL){
        tree*temp=root->right;
        free(root);
        return temp;
    }
    else if(root->right==NULL){
        tree*temp=root->left;
        free(root);
        return temp;
    }
   tree*temp=root->right;
   while(temp->left!=NULL) temp=temp->left;
    
    root->data=temp->data;
    root->right=del(root->right,temp->data);
   }
   
    
    return root;
}
void inorder(tree*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
tree* search(tree*root,int key){
    if(root==NULL||root->data==key)
    return root;
    if(key<root->data)
    return search(root->left,key);
    else 
    return search(root->right,key);
}
int main(){
    tree* root= NULL;
    root=insert(root,50);
    insert(root,5);
    insert(root,51);
    insert(root,28);
    insert(root,65);
    insert(root,45);
    insert(root,40);
int key;
printf("Enter the key u want to delete: ");
scanf("%d",&key);
    printf("BST Tree in Inorder before deletion.... ");
    inorder(root);
   root= del(root,key);
    printf("\nBST Tree in Inorder after deletion.... ");
    inorder(root);
    // printf("\nBST Tree in Preorder..");
    // pre(root);
    // printf("\nBST Tree in Postorder..");
    // post(root);
    // printf("\n");
    // int key;
    // printf("enter your key which are u found:");
    // scanf("%d",&key);
    // tree* found=search(root,key);
    // if(found!=NULL)
    // printf("Element %d found in BST:\n",key);
    // else
    // printf("Element %d not found in BST:\n",key);    
}