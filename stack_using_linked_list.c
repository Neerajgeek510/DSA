#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node*next;
}node;
 node *top=NULL;
void traversal(node*p){
    while(p!=NULL){
        printf("Element:%d\n",p->data);
        p=p->next;
    }
}
int isempty(node*ptr){
    if (ptr==NULL){
       return 1;
    }
    else{
        return 0;
    }
}
int isfull(){
    node*p=(node*)malloc(sizeof(node));
    if (p==NULL){
       return 1;
    }
    else{
        free(p);
        return 0;
    }
}
node* push(node*ptr,int x){
    if (isfull()){
        printf("stack is overflow\n");
    }
    else{
        node*p=(node*)malloc(sizeof(node));
        p->data=x;
        p->next=ptr;
        ptr=p;
        return ptr;
    }
}

int  pop(node*ptr){
    if (isempty(ptr)){
        printf("stack is underflow\n");
        return -1;
    }
    else{
        node*p=ptr;
        int x =p->data;
        top=top->next;
        free(p);
        return x;
       
    }

}
int main(){
   top = push(top,78);
   top = push(top, 45);
   top = push(top, 99);
   traversal(top);
   int element = pop(top);
   printf("Poped element id :%d\n",element);
traversal(top);
return 0;
}
