#include <stdio.h>
#include <conio.h>
#include <stdlib.h>     // for malloc() and exit()

#define SIZE 10

typedef struct Queue {
    int rear, front;
    int queue[SIZE];
} qe;

void insertItem(qe *);
void deleteItem(qe *);
void displayItem(qe *);

int main() {
    int choose;
    qe *q = (qe *)malloc(sizeof(qe));

    if (q == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    q->rear = -1;
    q->front = 0;

    printf("\nMenu for program:\n");
    printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");

    do {
        printf("\nEnter the choice: ");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                insertItem(q);
                break;
            case 2:
                deleteItem(q);
                break;
            case 3:
                displayItem(q);
                break;
            case 4:
                printf("Program exited\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choose != 4);

    return 0;
}

void insertItem(qe *q) {
    int ele;
    printf("Enter the data to be inserted: ");
    scanf("%d", &ele);

    if (q->rear == SIZE - 1) {
        printf("Queue is Full\n");
    } else {
        q->rear++;
        q->queue[q->rear] = ele;
    }
}

void deleteItem(qe *q) {
    int ele;

    if (q->rear < q->front) {
        printf("Queue is Empty\n");
    } else {
        ele = q->queue[q->front];
        q->front++;
        printf("Deleted item is %d\n", ele);
    }
}

void displayItem(qe *q) {
    int i;

    if (q->rear < q->front) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue elements:\n");
        for (i = q->front; i <= q->rear; i++) {
            printf("%d ", q->queue[i]);
        }
        printf("\n");
    }
}
