#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list.
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the nth position.
int insertAtNthPosition(struct Node** head, int data, int position) {
    // Allocate memory for the new node.
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }
    newNode->data = data;
    newNode->next = NULL;

    // If the linked list is empty or inserting at the beginning (position 1).
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return 0;
    }

    // Traverse to the (position-1)th node.
    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If the position is invalid (i.e., position > list length + 1).
    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return -1;
    }

    // Insert the new node into the list.
    newNode->next = temp->next;
    temp->next = newNode;
    return 0;
}

// Function to print the linked list.
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;  // Start with an empty linked list.
    int numInsertions, data, position;

    // Read the number of insertions.
    if (scanf("%d", &numInsertions) != 1) {
        printf("Error reading the number of insertions.\n");
        return 1;
    }

    // Process each insertion.
    for (int i = 0; i < numInsertions; i++) {
        if (scanf("%d %d", &data, &position) != 2) {
            printf("Error reading data and position.\n");
            return 1;
        }
        if (insertAtNthPosition(&head, data, position) != 0) {
            printf("Error inserting %d at position %d.\n", data, position);
        }
    }

    // Print the final linked list.
    printList(head);

    return 0;
}