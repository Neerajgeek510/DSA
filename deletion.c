#include<stdio.h>
#include<stdlib.h>
typedef int data;
typedef struct node{
    data value;
    struct node *next;
}node;
typedef struct list{
    node *head;
    int count;
}list;
void createlist(list *l){
    l->head=NULL;
    l->count=0;
}
void insert(int pos, data n,list *l){
    if(pos<1||pos>l->count+1){
        printf("invalid postion\n");
        return;
    }
    node *newNode=(node*)malloc(sizeof(node));
    newNode->value = n;
    newNode->next= NULL;
    if (pos==1){
        newNode->next = l->head;
        l->head = newNode;
    }
    else{
        node *ptr =l->head;
        for(int i=1; i<pos-1; i++){
            ptr=ptr->next;
        }
        newNode->next=ptr->next;
        ptr->next=newNode;
    }
    l->count++;
}
void delete(list *l,int pos){
    if(pos<1||pos>l->count){
        printf("invalid position\n");
        return;
    }
    node *ptr,*prev;
    if(pos==1){
        ptr=l->head;
        l->head=l->head->next;
        free(ptr);
    }
    else{
        prev=l->head;
        for (int i =1; i<pos-1;i++){
            prev=prev->next;
        }
        ptr=prev->next;
    prev->next=ptr->next;
    free(ptr);
    }
    l->count--;
}
void display(list *l){
    node *current = l->head;
    while(current!=NULL){
printf("%d->",current->value);
current= current->next;
    }
    printf("Null\n");
}
int main(){
    list l;
    createlist(&l);
    insert(1,56,&l);
    insert(1,50,&l);
    insert(2,5,&l);
    insert(3,66,&l);
    display(&l);
    printf("Here is deleted list\n");
    delete(&l,2);
    display(&l);
    return 0;
}