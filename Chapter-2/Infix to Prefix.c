#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Stack operations
void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return -1;  // empty stack
    return stack[top--];
}

char peek() {
    if (top == -1) return -1;
    return stack[top];
}

// Precedence of operators
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

// Check if operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Reverse a string
void reverse(char *exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

// Infix to Prefix conversion
void infixToPrefix(char infix[], char prefix[]) {
    char revInfix[MAX], temp[MAX];
    strcpy(revInfix, infix);
    reverse(revInfix);

    int j = 0; // index for prefix
    for (int i = 0; revInfix[i]; i++) {
        char c = revInfix[i];

        if (isalnum(c)) {
            prefix[j++] = c;  // operand goes to prefix
        }
        else if (c == ')') {
            push(c);
        }
        else if (c == '(') {
            while (peek() != ')' && top != -1) {
                prefix[j++] = pop();
            }
            pop(); // remove ')'
        }
        else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) > precedence(c)) {
                prefix[j++] = pop();
            }
            push(c);
        }
    }

    while (top != -1) {
        prefix[j++] = pop();
    }
    prefix[j] = '\0';
    reverse(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
