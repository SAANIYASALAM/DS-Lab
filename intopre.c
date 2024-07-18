#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
char p[100],s[100];
int top=-1;
int prec(char c)
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

void infixtoprefix(char d[100])
{
    int j=0,i=0;
    char x,y,t[100];
    while (d[i]!='\0')
    {
        if (isalnum(d[i]))
        {
            j++;
            p[j]=d[i];
        }
        else if (d[i]==')')
        {
            top++;
            s[top]=d[i];
        }
        else if (d[i]=='(')
        {
            while ( top!=-1 && s[top]!=')')
            {
                j++;
                p[j]=s[top];
                top--;
            }
            top--;
        }
        else 
        {
            x=d[i];
            y=s[top];
            if (top==-1||prec(x)<=prec(y))
            {
                j++;
                p[j]=s[top];
                top--;
                y = s[top];
            }
            top++;
            s[top]=x;
        }
        i++;
    }
    while(top!=-1)
    {
        j++;
        p[j]=s[top];
        top--;
    }
    p[j]='\0';
    int f=0;
    for (int i=strlen(p)-1;i>=0;i--)
    {
        t[f]=p[i];
        f++;
    }
    t[f]='\0';
    printf("the infix expression is : %s ",t);
}

void main()
{
    char c[100],d[100],k=0;
    printf("enter the infix expression: ");
    fgets(c,sizeof(c),stdin);
    for(int i=strlen(c)-1;i>=0;i--)
    {
        d[k]=c[i];
        k++;
    }
    d[k]='\0';
    printf("the reversed string is:\n");
    for(int i=0;i<strlen(d);i++)
    {
        printf("%c",d[i]);
    }
    infixtoprefix(d);
    
}