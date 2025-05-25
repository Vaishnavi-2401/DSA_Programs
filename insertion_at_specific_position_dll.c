#include <stdio.h>
#include <stdlib.h>

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

//Function to insert a node at the specific position
struct Node * insert(struct Node * head, int new_data, int pos) 
{
    struct Node * new_node = CreateNode(new_data);

    if(pos == 1) 
    {
        new_node -> next = head;

        if(head != NULL)
        {
            head -> prev = new_node;
        }
    
        return new_node;
    }

    struct Node * current = head;

    int i = 1;

    while(current != NULL && i < pos - 1) 
    {
        current = current -> next;

        i++;
    }

    if(current == NULL) 
    {
        printf("Invalid Position!\n");

        free(new_node);

        return head;
    }

    new_node -> next = current -> next;
    new_node -> prev = current;

    if(current -> next != NULL)
    {
        current -> next -> prev = new_node;
    }

    current -> next = new_node;

    return head;
}

//Function to print the linked list
void print_list(struct Node * head) 
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
    struct Node* head = NULL;

    printf("After Inserting Nodes : ");

    head = insert(head, 30, 1);  
    head = insert(head, 10, 1);
    head = insert(head, 20, 2);
    head = insert(head, 40, 4); 

    print_list(head);

    return 0;
}