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

//Function to print the list forward (circular)
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

    printf("(Back to Head)\n");
}

//Function to print the list backward (circular)
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

    printf("(Back to Tail)\n");
}

int main() 
{
    struct Node * head = CreateNode(10);
    struct Node * second = CreateNode(20);
    struct Node * third = CreateNode(30);

    head -> next = second;
    second -> next = third;
    third -> next = head;

    third -> prev = second;
    second -> prev = head;
    head -> prev = third; 

    print_forward(head);
    print_backward(third);

    return 0;
}