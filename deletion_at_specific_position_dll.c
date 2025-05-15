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

//Function to delete a node at a specific position
struct Node * delete(struct Node * head, int pos)
{
    if(head == NULL)
    {
        printf("List is Empty!\n");

        return NULL;
    }

    if(pos <= 0)
    {
        printf("Invalid position!\n");

        return head;
    }

    struct Node * temp = head;

    for(int i = 1; i < pos && temp != NULL; i++)
    {
        temp = temp -> next;
    }

    if(temp == NULL)
    {
        printf("Position Out of Range!\n");

        return head;
    }

    if(temp == head)
    {
        head = temp -> next;

        if(head != NULL)
        {
            head -> prev = NULL;
        }
    }

    else
    {
        if(temp -> prev != NULL)
        {
            temp -> prev -> next = temp -> next;

        }

        if(temp -> next != NULL)
        {
            temp -> next -> prev = temp -> prev;
        }
    }

    printf("Deleted Node : %d\n", pos, temp -> data);

    free(temp);

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

    head = insert(head, 5);
    head = insert(head, 4);
    head = insert(head, 3);
    head = insert(head, 2);
    head = insert(head, 1);

    printf("Original List : ");

    print_list(head);

    head = delete(head, 3);

    printf("After Deleting Node : ");

    print_list(head);

    return 0;
}