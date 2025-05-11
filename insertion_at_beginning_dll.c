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

    new_node -> next = head;

    if(head != NULL) 
    {
        head -> prev = new_node;
    }

    return new_node;
}

// Function to print the list forward
void print_list(struct Node * head) 
{
    struct Node * current = head;

    printf("After Inserting Nodes : ");

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

    head = insert(head, 30);
    head = insert(head, 20);
    head = insert(head, 10);

    print_list(head);

    return 0;
}