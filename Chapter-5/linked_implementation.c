#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = top;
    top = n;
}

void pop() {
    if (top == NULL)
        printf("Underflow\n");
    else {
        struct Node* temp = top;
        top = top->next;
        free(temp);
    }
}

int main() {
    push(10);
    push(20);
    pop();
    return 0;
}
