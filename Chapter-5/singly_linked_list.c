#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node NodeType;

NodeType *first = NULL;
NodeType *last = NULL;

void insert_at_first(int);
void insert_at_given_position(int);
void insert_at_end(int);
void delete_first();
void delete_end();
void delete_nth_node();
void info_sum();
void count_nodes();
void display();

int main() {
    int choice, element;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at first\n");
        printf("2. Insert at given position\n");
        printf("3. Insert at end\n");
        printf("4. Delete first\n");
        printf("5. Delete last\n");
        printf("6. Delete nth node\n");
        printf("7. Info sum\n");
        printf("8. Count nodes\n");
        printf("9. Display\n");
        printf("10. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item: ");
                scanf("%d", &element);
                insert_at_first(element);
                break;

            case 2:
                printf("Enter item: ");
                scanf("%d", &element);
                insert_at_given_position(element);
                break;

            case 3:
                printf("Enter item: ");
                scanf("%d", &element);
                insert_at_end(element);
                break;

            case 4:
                delete_first();
                break;

            case 5:
                delete_end();
                break;

            case 6:
                delete_nth_node();
                break;

            case 7:
                info_sum();
                break;

            case 8:
                count_nodes();
                break;

            case 9:
                display();
                break;

            case 10:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 10);

    return 0;
}

void insert_at_first(int item) {
    NodeType *new_node = (NodeType *)malloc(sizeof(NodeType));
    new_node->data = item;
    new_node->next = first;
    first = new_node;
}

void insert_at_given_position(int item) {
    int pos, i;
    NodeType *new_node, *temp;

    printf("Enter position: ");
    scanf("%d", &pos);

    new_node = (NodeType *)malloc(sizeof(NodeType));
    new_node->data = item;

    if (pos == 1) {
        new_node->next = first;
        first = new_node;
        return;
    }

    temp = first;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

void insert_at_end(int item) {
    NodeType *new_node = (NodeType *)malloc(sizeof(NodeType));
    NodeType *temp = first;

    new_node->data = item;
    new_node->next = NULL;

    if (first == NULL) {
        first = new_node;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void delete_first() {
    NodeType *temp;
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = first;
    first = first->next;
    free(temp);
}

void delete_end() {
    NodeType *temp, *prev;

    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    if (first->next == NULL) {
        free(first);
        first = NULL;
        return;
    }

    temp = first;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void delete_nth_node() {
    NodeType *temp, *hold;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        delete_first();
        return;
    }

    temp = first;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    hold = temp->next;
    temp->next = hold->next;
    free(hold);
}

void display() {
    NodeType *temp = first;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void count_nodes() {
    int count = 0;
    NodeType *temp = first;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total nodes: %d\n", count);
}

void info_sum() {
    NodeType *temp = first;
    int sum = 0;
    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }
    printf("Sum of nodes: %d\n", sum);
}

