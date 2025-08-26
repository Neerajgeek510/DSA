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
int stacktop(stack*ptr){
return ptr->arr[ptr->top];
}
int stackbottom(stack*ptr){
return ptr->arr[0];
}
 int push(stack *ptr,int value){
    if(isfull(ptr)){
        printf("stack is full");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=value;
        printf("%d pushed in stack\n", value);
    }
}
int pop(stack *ptr){
    if(isempty(ptr)){
        printf("stack is empty!");
        return -1;
    }
    else{
        int value=ptr->arr[ptr->top];
        ptr->top=ptr->top-1;
        return value;
        
    }
}
int peek(stack*ptr, int i){
if(ptr->top-i+1<0){
        printf("not a valid postion\n");
        return -1;
    }
    else{
        return ptr->arr[ptr->top-i+1];
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
    push(s,11);
    push(s,38);
    printf("Here u can see Last in first out (LIFO)!\n");
    printf("%d pop out from stcak\n",pop(s));
    printf("%d pop out from stcak\n",pop(s));
   for (int j=1;j<=s->top+1;j++){
         printf("the value of postion %d  is %d\n",j,peek(s,j));
    }
    printf("The topest value of stack is:%d\n",stacktop(s));
    printf("The bottom value of stack is:%d\n",stackbottom(s));

    printf("Thank uhh!");
        return 0;
 
}





