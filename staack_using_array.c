#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
    int size,top,*arr;
}stack;
int isfull(stack*ptr){
    if(ptr->top==ptr->size-1){
       return 1;
    }
    else{
       return 0;
    }
}    
int isempty(stack *ptr){
    if(ptr->top == -1){
       return 1;
    }
    else{
       
        return 0;
    }
}
 void push(stack *ptr,int value){
    if(isfull(ptr)){
        printf("stack is full");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=value;
        printf("%d pushed in stack\n", value);
    }
}
int pop(stack *ptr, int value){
    if(isempty(ptr)){
        printf("stack is empty!");
        return -1;
    }
    else{
        value=ptr->arr[ptr->top];
        ptr->top=ptr->top-1;
        printf("%d stack pop out\n",value);
        
    }
}

int main(){
    stack *s = (stack *)malloc(sizeof(stack));
    s->size=10;
    s->top=-1;
    s->arr=(int *)malloc(s->size*sizeof(int));
    printf("stack is created successfully!");
    push(s,19);
    push(s,20);
    push(s,29);
    push(s,79);
    push(s,18);
    pop(s,20);
 
}
