#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at the end
void insertEnd(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        newNode->next = newNode->prev = head; // circular link
        return;
    }
    struct Node *last = head->prev; // last node
    last->next = newNode;
    newNode->prev = last;
    newNode->next = head;
    head->prev = newNode;
}

// Display forward
void displayForward() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    printf("Forward: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Display backward
void displayBackward() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head->prev; // start from last
    printf("Backward: ");
    struct Node *last = temp;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    } while (temp != last);
    printf("(head)\n");
}

// Delete beginning node
void deleteBeginning() {
    if (head == NULL) return;

    struct Node *last = head->prev;
    struct Node *temp = head;

    if (head->next == head) { // only one node
        head = NULL;
        free(temp);
        return;
    }

    head = head->next;
    head->prev = last;
    last->next = head;
    free(temp);
}

// Main function
int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    displayForward();
    displayBackward();

    printf("After deleting first node:\n");
    deleteBeginning();
    displayForward();
    displayBackward();

    return 0;
}
