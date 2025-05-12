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

//Function to insert a node at the end of the doubly linked list
struct Node * insert(struct Node * head, int new_data) 
{
    struct Node * new_node = CreateNode(new_data);

    if(head == NULL) 
    {
        return new_node;
    }

    struct Node * current = head;

    while(current -> next != NULL) 
    {
        current = current -> next;
    }

    current -> next = new_node;
    new_node -> prev = current;

    return head;
}

//Function to print the linked list
void print_list(struct Node* head) 
{
    struct Node * current = head;

    while(current != NULL) 
    {
        printf("%d -> ", current -> data);

        current = current -> next;
    }

    printf("NULL\n");
}

int main() 
{
    struct Node * head = NULL;

    printf("After Inserting Nodes : ");

    head = insert(head, 30);  
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 40); 

    print_list(head);

    return 0;
}