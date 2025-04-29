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

int main()
{
    struct Node* head = CreateNode(10);
    head -> next = CreateNode(20);
    head -> next -> next = CreateNode(30);

    struct Node* temp = head;

    printf("Singly Linked List : ");

    return 0;
}