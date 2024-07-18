#include <stdio.h>
int front, rear, size;

struct queue
{
    int priority;
    int item;
};
struct queue q[100];

void enqueue(int key, int prio)
{
    int loc,i;
    if (front ==0 && rear ==size-1)
    {
        printf("queue is full\n");
    }
    else if (front == -1)
    {
        front = 0;
        rear = 0;
        q[rear].item = key;
        q[rear].priority = prio;
    }
    else
    {
        if(rear==size-1)
        {
            for (int i = front ; i<=rear; i++)
            {
                q[i-1]=q[i];
                front--;
                rear--;
            }
        }
        for (int i= rear;i>=front;i--)
        {
            if (q[i].priority<prio)
            {
                break;
            }
        }
        loc = i+1;
        for (int i = rear; i>= loc; i--)
        {
            q[i+1]=q[i];
        }
        q[loc].item = key;
        q[loc].priority= prio;
        rear++;
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("queue is empty\n");
    }
    else if(front = rear)
    {
        printf("the deleted iem is %d",q[front].item);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("the deleted item is %d",q[front].item);
        front++;
    }
}

void display()
{
    if (front == -1)
    {
        printf("queue is empty\n");
    }
    else
    {
        for(int i= front ; i<rear; i++)
        {
            printf("%d ",q[i].item);
        }
    }
}

void search(int key)
{
    if (front == -1)
    {
        printf("queue is empty\n");
    }
    else
    {
        for(int i= front ; i<rear; i++)
        {
            if (q[i].item == key)
            {
                printf("the element is found");
            }
        }
    }
}


void main()
{
    front= rear= -1;
    int opt;
    printf("enter the size of the queue:\n");
    scanf("%d",&size);
    printf("choose any option\n1.enqueue\n2.dequeue\n3.display\n4.search\n5.exit\n");
    int key,prio;
    do
    {
        printf("enter an option:\n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: printf("enter the element and the pririty to insert:\n");
                    scanf("%d%d",&key,&prio);
                    enqueue(key,prio);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: printf("enter the element to search:\n");
                    scanf("%d",&key);
                    search(key);
                    break;
            case 5: printf("exiting the program.....");
                    break;
        }
    }
    while (opt!=5);
}