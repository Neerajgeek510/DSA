#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node*prev;
    struct Node*next;
}node;
node*head=NULL;
node*createNode(int val){
    node*newNode=(node*)malloc(sizeof(node));
    newNode->data=val;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}
void insertAt(int pos,int value){
    node*newNode=createNode(value);
    if (pos==0){
        newNode->next=head;
        if(head!=NULL)
        head->prev=newNode;
    head=newNode;
        return ;
    }
    node*temp=head;
    for(int i=0;temp!=NULL && i<pos-1; i++){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("invalid postion\n");
        // temp=head;
        return;
        while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newNode;
    newNode->prev=temp;
    return ;
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    if(temp->next!=NULL)
    temp->next->prev=newNode;
temp->next=newNode; 
}
void display(){
    node*temp=head;
    printf("NUll<->");
    while(temp!=NULL){
        printf("%d<-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    insertAt(0,10);
    insertAt(1,20);
    insertAt(1,30);
    insertAt(0,60);
    insertAt(2,29);
    insertAt(3,89);
    insertAt(4,76);
    insertAt(5,43);
    // insertAt(20,999);

    display();
    return 0;
}