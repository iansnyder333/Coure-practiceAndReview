#include <stdio.h>
#include <stdlib.h>

// Define the structure for a single node
struct Node
{
    int data;
    struct Node *next;
};

// Function prototypes
void insert_beginning(struct Node **head, int new_data);
void insert_end(struct Node **head, int new_data);
void display(struct Node *node);
void delete_beginning(struct Node **head);
void delete_end(struct Node **head);

// Main function
int main()
{
    struct Node *head = NULL; // Initialize empty list

    // Insert nodes at the beginning
    insert_beginning(&head, 20);
    insert_beginning(&head, 10);

    // Insert nodes at the end
    insert_end(&head, 30);
    insert_end(&head, 40);

    // Display the list
    printf("Linked list after inserting nodes:\n");
    display(head);

    // Delete nodes from the beginning and end
    delete_beginning(&head);
    delete_end(&head);

    // Display the updated list
    printf("\nLinked list after deleting nodes:\n");
    display(head);

    return 0;
}

// Function to insert a new node at the beginning
void insert_beginning(struct Node **head, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a new node at the end
void insert_end(struct Node **head, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
}

// Function to display the list
void display(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to delete a node from the beginning
void delete_beginning(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end
void delete_end(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node *temp = *head, *prev;
    if (temp->next == NULL)
    {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}
