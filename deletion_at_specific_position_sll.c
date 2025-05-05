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

//Function to insert a node at the beginning
struct Node * insert(struct Node * head, int data)
{
    struct Node * new_node = CreateNode(data);

    new_node -> next = head;

    return new_node;
}

//Function to delete a node at a specific position
struct Node * delete(struct Node * head, int position)
{
    if(head == NULL)
    {
        printf("List is Empty!\n");

        return NULL;
    }

    if(position == 0)
    {
        struct Node * temp = head;

        head = head -> next;

        printf("Deleted Node : %d\n", temp -> data);

        free(temp);

        return head;
    }

    struct Node * current = head;

    for(int i = 0; current != NULL && i < position - 1; i++)
    {
        current = current -> next;
    }

    if(current == NULL || current -> next == NULL)
    {
        printf("Position is Out Of Bound.\n", position);

        return head;
    }

    struct Node * temp = current -> next;

    current -> next = temp -> next;

    printf("Deleted Node : %d\n", position, temp -> data);

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

    head = insert(head, 4);
    head = insert(head, 3);
    head = insert(head, 2);
    head = insert(head, 1);

    printf("Original List : ");

    print_list(head);

    head = delete(head, 2);

    printf("After Deleting Node : ");

    print_list(head);

    return 0;
}