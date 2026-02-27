#include <stdio.h>
#define MAX 5

int pq[MAX];
int size = -1;

// Insert element
void enqueue(int value)
{
    if (size == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    size++;
    pq[size] = value;
}

// Delete highest priority element
void dequeue()
{
    if (size == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    int maxIndex = 0;
    for (int i = 1; i <= size; i++)
    {
        if (pq[i] > pq[maxIndex])
            maxIndex = i;
    }

    printf("Deleted: %d\n", pq[maxIndex]);

    for (int i = maxIndex; i < size; i++)
        pq[i] = pq[i + 1];

    size--;
}

// Display queue
void display()
{
    if (size == -1)
    {
        printf("Empty Queue\n");
        return;
    }

    for (int i = 0; i <= size; i++)
        printf("%d ", pq[i]);
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(30);
    enqueue(20);

    display();
    dequeue();
    display();

    return 0;
}
