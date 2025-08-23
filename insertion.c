#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* head = NULL;

void create() {
    int n;
    char ch;
    printf("Enter the data  of nodes: ");
    scanf("%d", &n);
    head = (struct node*)malloc(sizeof(struct node));
    head->data=n;
    head->next = NULL;
    struct node* temp = head;
    printf("if u want to add more nodes press y else n: ");
    scanf(" %c", &ch);
    while (ch == 'y' || ch == 'Y') {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data for the new node: ");
        scanf("%d", &new_node->data);
        new_node->next = NULL;
        temp->next = new_node;
        temp = new_node;
        printf("if u want to add more nodes press y else n: ");
        scanf(" %c", &ch);
    }
    
} 
struct node* insert_beg(struct node* head, int data){
   struct node* new1;
   new1=(struct node*)malloc(sizeof(struct node));
   new1->data = data; 
   new1->next = head;
   
return new1;

}
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    printf("Linked List Program\n");
    create();
    int new1_data;
    printf("enter the data beg");
    scanf("%d",&new1_data);
    printf("created linked list \n ");
    head = insert_beg(head, new1_data);
    display();

    return 0;
}