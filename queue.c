#include<stdio.h>
#define SIZE 5

int queue[SIZE];
int front= -1,rear=-1;
void enq(int value){
    if(rear==SIZE-1){
        printf("queue is full!\n");
    }else{
        if(front==-1)
        front=0;
        rear++;
        queue[rear]=value;
        printf("inserted %d\n",value);
    }
}
void deq(){
    if(front==-1||front>rear){
        printf("queue is empty!\n");
    }else{
        printf("deleted %d\n",queue[front]);
        front++;
    }
}
void display(){
    if(front==-1||front>rear){
        printf("queue is empty!\n");
    }else{
        printf("queue elements are: ");
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
int main(){
    enq(10);
    enq(20);
    enq(30);
    enq(40);
    display();
    deq();
    deq();
    display();
    return 0;

}