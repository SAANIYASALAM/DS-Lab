#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *front , *rear;

void enqueue(int x)
{
    struct node *new;
    new = (struct node*)malloc (sizeof (struct node));
    new ->data = x;
    new ->next =NULL;
    if (front == NULL)
    {
        front = rear = new;
    }
    else
    {
        rear->next = new;
        rear = new;
    }
}

void dequeue()
{
    struct node* temp;
    if (front == NULL)
    {
        printf("queue is empty");
    }
    else if (front == rear )
    {
        temp = front ;
        printf("the removed element is :%d\n",front -> data);
        front = rear =NULL;
        free(temp);
    }
    else 
    {
        temp = front ;
        printf("the removed element is :%d\n",front -> data);
        front = front->next;
        free (temp);
    }
}

void display()
{
    struct node* ptr;
    if (front == NULL)
    {
        printf("the queue is empty");
    }
    else 
    {
        ptr = front ;
        printf("\nthe elements in the queue are:\n");
        while(ptr != NULL)
        {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
    }
}

void main()
{
    printf("QUEUE\n");
    int opt;
    printf("choose any option\n1.enqueue\n2.dequeue\n3.display\n4.exit");
    do
    {
        printf("enter the option");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: int x;
                    printf("\nenter the element to add\n");
                    scanf("%d",&x);
                    enqueue(x);
                    display();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
        }
    }
    while (opt!=4);
}