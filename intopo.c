#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char A[20], P[20];
char S[20];
int S1[20];
int top=-1,top1=-1;

int precedence(char c)
{
    switch (c)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
}

void infixtopostfix()
{
    int i=0,j=0;
    char x,y;
    while(A[i]!='\0')
    {
        if (isdigit(A[i]))
        {
            P[j++]=A[i];
        }
        else if (A[i]=='(')
        {
            S[++top]=A[i];
        }
        else if(A[i]==')')
        {
            while(S[top]!='(')
            {
                P[j++]=S[top--];
            }
            top--;
        }
        else
        {
            x = A[i];
            y = S[top];
            if (top==-1 || y=='('|| precedence(x)<precedence(y))
            {
                P[j++]= S[top--];
                y = S[top];
            }
        }
        i++;
    }
    while(top!=-1)
    {
        P[j++]=S[top--];
    }
    P[j]='\0';
    printf("postfix expression is: %s ",P);
}

void postfixeval()
{
    int i,op1,op2,result;
    char str[10];
    for (int i=0; i<strlen(P); i++)
    {
        if (isdigit(P[i]))
        {
            str[0]=P[i];
            str [1]='\0';
            S1[++top]=atoi(str);
        }
        else
        {
            op2 = S1[top--];
            op1 = S1[top--];
            switch(P[i])
            {
                case '+': result = op1+op2; break;
                case '-': result = op1-op2; break;
                case '*': result = op1*op2; break;
                case '/': result = op1/op2; break;
            }
            S1[++top1]=result;
        }
    }
    printf("\nResult = %d",S1[0]);
}

int main()
{
    printf("enter the infix expression");
    fgets(A, sizeof(A), stdin);
    infixtopostfix();
    postfixeval();
    
    return 0;
}
