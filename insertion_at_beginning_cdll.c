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

//Function to insert a node at the beginning
struct Node * insert(struct Node * head, int new_data) 
{
    struct Node * new_node = CreateNode(new_data);

    if(head == NULL) 
    {
        new_node -> next = new_node;
        new_node -> prev = new_node;

        return new_node;
    }

    struct Node * tail = head -> prev;

    new_node -> next = head;
    new_node -> prev = tail;

    tail -> next = new_node;
    head -> prev = new_node;

    return new_node;
}

//Function to print the list forward
void print_forward(struct Node * head) 
{
    if(head == NULL) 
    {
        printf("List is empty!\n");

        return;
    }

    struct Node * current = head;

    printf("Forward List : ");

    do 
    {
        printf("%d -> ", current -> data);

        current = current -> next;

    }
    while(current != head);

    printf("(back to head)\n");
}

//Function to print the list backward
void print_backward(struct Node * tail) 
{
    if(tail == NULL) 
    {
        printf("List is empty!\n");

        return;
    }

    struct Node * current = tail;

    printf("Backward List : ");

    do 
    {
        printf("%d <- ", current -> data);

        current = current -> prev;

    }
    while(current != tail);

    printf("(back to tail)\n");
}

int main() 
{
    struct Node * head = NULL;

    head = insert(head, 30);
    head = insert(head, 20);
    head = insert(head, 10);

    struct Node * tail = head -> prev;

    print_forward(head);
    print_backward(tail);

    return 0;
}