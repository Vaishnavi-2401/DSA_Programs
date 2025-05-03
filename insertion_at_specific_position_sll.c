#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

//Function to create a new node
struct Node * CreateNode(int new_data)
{
    struct Node * new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node -> data = new_data;
    new_node -> next = NULL;

    return new_node;
}

//Function to insert a node at the specific position
struct Node * insert(struct Node * head, int data, int pos) 
{
    struct Node * new_node = CreateNode(data);

    if(pos == 1) 
    {
        new_node -> next = head;

        return new_node;
    }

    struct Node * current = head;

    for(int i = 1; i < pos - 1 && current != NULL; i++) 
    {
        current = current -> next;
    }

    if(current == NULL) 
    {
        printf("Invalid Position!\n");

        free(new_node);

        return head;
    }

    new_node -> next = current -> next;
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
    struct Node * head = NULL;

    printf("After Inserting Nodes : ");

    head = insert(head, 10, 1);
    head = insert(head, 20, 2);
    head = insert(head, 15, 2);

    print_list(head);

    return 0;
}