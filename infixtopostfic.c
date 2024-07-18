#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char A[20], P[20];
char S[20];
int S1[20];
int top = -1, top1 = -1;

int precedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
}

void infixtopostfix()
{
    int i = 0, j = 0;
    char x, y;
    while (A[i] != '\0')
    {
        if (isdigit(A[i]))
        {
            P[j++] = A[i];
        }
        else if (A[i] == '(')
        {
            S[++top] = A[i];
        }
        else if (A[i] == ')')
        {
            while (S[top] != '(')
            {
                P[j++] = S[top--];
            }
            top--; 
        }
        else
        {
            while (top != -1 && S[top] != '(' && precedence(A[i]) <= precedence(S[top]))
            {
                P[j++] = S[top--];
            }
            S[++top] = A[i];
        }
        i++;
    }
    while (top != -1)
    {
        P[j++] = S[top--];
    }
    P[j] = '\0';
    printf("Postfix expression is: %s\n", P);
}

int main()
{
    printf("Enter the infix expression: ");
    fgets(A, sizeof(A), stdin);
    infixtopostfix();

    return 0;
}
