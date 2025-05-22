#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

//Function to create a new node
struct Node * CreateNode(int new_data)
{
    struct Node * new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node -> data = new_data;
    new_node -> prev = NULL;
    new_node -> next = NULL;

    return new_node;
}

//Function to insert a node at the beginning of circular doubly linked list
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
    head -> prev = new_node;
    tail -> next = new_node;

    return new_node;
}

//Function to delete a node at the beginning of circular doubly linked list
struct Node * delete(struct Node* head)
{
    if(head == NULL)
    {
        printf("List is Empty!\n");

        return NULL;
    }

    if(head -> next == head)
    {
        printf("Deleted Node : %d\n", head -> data);

        free(head);

        return NULL;
    }

    struct Node * tail = head -> prev;
    struct Node * new_head = head -> next;

    tail -> next = new_head;
    new_head -> prev = tail;

    printf("Deleted Node : %d\n", head -> data);

    free(head);

    return new_head;
}

//Function to print the circular doubly linked list
void print_list(struct Node * head)
{
    if(head == NULL)
    {
        printf("List is Empty!\n");

        return;
    }

    struct Node * current = head;

    do
    {
        printf("%d -> ", current -> data);

        current = current -> next;

    }while(current != head);

    printf("(back to head)\n");
}

int main()
{
    struct Node * head = NULL;

    head = insert(head, 3);
    head = insert(head, 2);
    head = insert(head, 1);

    printf("Original List : ");
    print_list(head);

    head = delete(head);

    printf("After Deleting Node : ");
    print_list(head);

    return 0;
}