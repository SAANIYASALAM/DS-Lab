#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};
struct node * top;

void display()
{
    struct node *ptr;
    if(top == NULL)
    {
        printf("stack empty\n");
    }
    else
    {
        ptr= top;
        printf("the stack elements are:\n");
        while(ptr!= NULL)
        {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
    }
}

void push(int x)
{
    struct node *new;
    new = (struct node*)malloc (sizeof (struct node));
    new ->data = x;
    new->next = top;
    top = new;
}

void pop()
{
    struct node *temp;
    if (top== NULL)
    {
        printf("the stack is empty\n");
    }
    else
    {
        temp = top;
        printf("the popped element is:%d",top->data);
        top = top->next;
        free(temp);
    }
}

void main()
{
    printf("STACK\n");
    int opt;
    printf("choose any option\n1.push\n2.pop\n3.display\n4.exit");
    do
    {
        printf("enter the option");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: int x;
                    printf("\nenter the element to push\n");
                    scanf("%d",&x);
                    push(x);
                    display();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
        }
    }
    while (opt!=4);
}