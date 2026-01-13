#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char* stack[MAX];
int top = -1;

// Push string to stack
void push(char* str) {
    stack[++top] = str;
}

// Pop string from stack
char* pop() {
    if (top == -1) return NULL;
    return stack[top--];
}

// Check if operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int main() {
    char prefix[MAX];
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    int len = strlen(prefix);

    // Scan from right to left
    for (int i = len - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isalnum(c)) { // Operand
            char *op = (char*)malloc(2);
            op[0] = c;
            op[1] = '\0';
            push(op);
        }
        else if (isOperator(c)) { // Operator
            char *op1 = pop();
            char *op2 = pop();
            char *expr = (char*)malloc(strlen(op1) + strlen(op2) + 4);
            sprintf(expr, "(%s%c%s)", op1, c, op2); // combine as infix
            push(expr);
        }
    }

    printf("Infix expression: %s\n", pop());

    return 0;
}
