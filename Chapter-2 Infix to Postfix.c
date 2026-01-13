#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

int precedency(char ch);

int main()
{
    int i, otos = -1, ptos = -1;
    char infix[100], poststack[100], opstack[100];

    printf("Enter a valid infix expression:\n");
    gets(infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
        {
            opstack[++otos] = infix[i];
        }
        else if (isalpha(infix[i]))
        {
            poststack[++ptos] = infix[i];
        }
        else if (infix[i] == ')')
        {
            while (opstack[otos] != '(')
            {
                poststack[++ptos] = opstack[otos--];
            }
            otos--;   // pop '('
        }
        else   // operator
        {
            while (otos != -1 &&
                   precedency(opstack[otos]) >= precedency(infix[i]))
            {
                poststack[++ptos] = opstack[otos--];
            }
            opstack[++otos] = infix[i];
        }
    }

    while (otos != -1)
    {
        poststack[++ptos] = opstack[otos--];
    }

    poststack[++ptos] = '\0';

    printf("Postfix expression:\n%s", poststack);

    getch();
    return 0;
}

int precedency(char ch)
{
    switch (ch)
    {
        case '$':
            return 4;
        case '*':
        case '/':
            return 3;
        case '+':
        case '-':
            return 2;
        default:
            return 1;
    }
}
