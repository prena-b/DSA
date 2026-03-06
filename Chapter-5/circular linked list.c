#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at the end
void insertEnd(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        newNode->next = head; // circular link
    } else {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head; // maintain circular link
    }
}

// Display the list
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Delete a node from the beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    if (head->next == head) { // only one node
        free(head);
        head = NULL;
    } else {
        struct Node *last = head;
        while (last->next != head)
            last = last->next;
        head = head->next;
        last->next = head;
        free(temp);
    }
}

// Main function
int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    printf("Circular Linked List: ");
    display();

    printf("After deleting beginning node:\n");
    deleteBeginning();
    display();

    return 0;
}
