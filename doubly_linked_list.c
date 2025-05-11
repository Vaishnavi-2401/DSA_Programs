#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
    struct Node* prev;
};

//Function to create a new node
struct Node * CreateNode(int new_data) 
{
    struct Node * new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node -> data = new_data;
    new_node -> next = NULL;
    new_node -> prev = NULL;

    return new_node;
}

//Function to print the list forward
void print_forward(struct Node * head) 
{
    struct Node * current = head;

    printf("Forward List : ");

    while(current != NULL) 
    {
        printf("%d -> ", current -> data);

        current = current -> next;
    }

    printf("NULL\n");
}

//Function to print the list backward
void print_backward(struct Node * tail) 
{
    struct Node * current = tail;

    printf("Backward List : ");

    while(current != NULL) 
    {
        printf("%d <- ", current -> data);

        current = current -> prev;
    }

    printf("NULL\n");
}

int main() 
{
    struct Node * head = CreateNode(10);
    struct Node * second = CreateNode(20);
    struct Node * third = CreateNode(30);

    head -> next = second;
    second -> prev = head;
    second -> next = third;
    third -> prev = second;

    print_forward(head);
    print_backward(third);

    return 0;
}