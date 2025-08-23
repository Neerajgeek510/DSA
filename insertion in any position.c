#include<stdio.h>
#include<stdlib.h>
typedef int listentry;
 typedef struct node{
    listentry e;
    struct node *next;
}node;
typedef struct{
    node *head;
    int count;
}list;
void createlist(list *l){
    l->head=NULL;
    l->count=0;
}
void insert(int pos, listentry x, list *l){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->e=x; // ne node ke data ki value hmne x liya hai
    newNode->next = NULL;
    // insert at starting 
    if (pos==1){
        newNode->next=l->head;
        l->head=newNode;
    }
    // insert at ending
    else if (pos==l->count+1){
        node *temp= l->head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
// insert in between
else{
    node *temp= l->head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
l->count++;
}
void display(list *l){
    node *temp= l->head;
    while(temp->next!=NULL){
        printf("%d->",temp->e);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    list n;
    createlist(&n);
    insert(1,10,&n);
    insert(2,20,&n);
    insert(3,30,&n);
    insert(4,50,&n);
    insert(5,60,&n);
    insert(6,100,&n);

    display(&n);
    return 0;
}
