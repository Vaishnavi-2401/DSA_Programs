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

//Function to delete a node at the end
struct Node * delete(struct Node* head)
{
    if(head == NULL)
    {
        printf("List is Empty!\n");

        return NULL;
    }

    if(head -> next == NULL)
    {
        printf("Deleted Node : %d\n", head-> data);

        free(head);

        return NULL;
    }

    struct Node * current = head;

    while(current -> next -> next != NULL)
    {
        current = current -> next;
    }

    printf("Deleted Node : %d\n", current -> next -> data);

    free(current -> next);

    current->next = NULL;

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