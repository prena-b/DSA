#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct CircularQueue {
    int item[SIZE];
    int rear;
    int front;
};

typedef struct CircularQueue cQueue;

void insertQueue(cQueue *);
void deleteQueue(cQueue *);
void displayQueue(cQueue *);

int main() {
    int choose;
    cQueue *q;

    q = (cQueue *)malloc(sizeof(cQueue));

    q->rear  = SIZE - 1;
    q->front = SIZE - 1;

    printf("Enter the Number for the Operation :\n");
    printf("1: Enqueue\n2: Dequeue\n3: Display\n");

    do {
        printf("\nEnter Your Choice: ");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                insertQueue(q);
                break;
            case 2:
                deleteQueue(q);
                break;
            case 3:
                displayQueue(q);
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while (choose < 100);

    return 0;
}

void insertQueue(cQueue *q) {
    int ele;

    if ((q->rear + 1) % SIZE == q->front) {
        printf("Queue is Full\n");
    } else {
        q->rear = (q->rear + 1) % SIZE;
        printf("Enter the Element to insert: ");
        scanf("%d", &ele);
        q->item[q->rear] = ele;
    }
}

void deleteQueue(cQueue *q) {
    if (q->rear == q->front) {
        printf("Queue is Empty\n");
    } else {
        q->front = (q->front + 1) % SIZE;
        printf("%d is deleted\n", q->item[q->front]);
    }
}

void displayQueue(cQueue *q) {
    int i;

    if (q->rear == q->front) {
        printf("Queue is Empty\n");
    } else {
        printf("item of Queue are\n");
        for (i = (q->front + 1) % SIZE; i != q->rear; i = (i + 1) % SIZE) {
            printf("%d \t", q->item[i]);
        }
        printf("%d \t", q->item[q->rear]);
    }
}
