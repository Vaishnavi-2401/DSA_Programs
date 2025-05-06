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
struct Node * insert(struct Node * head, int new_data)
{
    struct Node * new_node = CreateNode(new_data);

    new_node -> next = head;

    return new_node;
}

//Function to delete a node at the beginning
struct Node * delete(struct Node* head)
{
    if(head == NULL)
    {
        printf("List is Empty!\n");

        return NULL;
    }

    struct Node * temp = head;

    head = head -> next;

    printf("Deleted Node : %d\n", temp -> data);

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