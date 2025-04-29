#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

//Function to create a new node
struct Node* CreateNode(int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node -> data = new_data;
    new_node -> next = NULL;

    return new_node;
}

//Function to print the linked list
void Print_list(struct Node * head) 
{
    struct Node * current = head;

    while(current != NULL) 
    {
        printf("%d ", current -> data);

        current = current -> next;
    }
    printf("\n");
}

int main()
{
    struct Node * head = CreateNode(10);
    head -> next = CreateNode(20);
    head -> next -> next = CreateNode(30);

    struct Node * current = head;

    printf("Singly Linked List : ");

    Print_list(head);

    return 0;
}