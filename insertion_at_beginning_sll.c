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

//Function to insert a node at the beginning
struct Node * insert(struct Node * head, int new_data)
{
    struct Node * new_node = CreateNode(new_data);

    new_node -> next = head;

    return new_node;
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

    head = insert(head, 3);
    head = insert(head, 2);
    head = insert(head, 1);

    print_list(head);

}