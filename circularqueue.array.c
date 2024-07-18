#include <stdio.h>
int q[100],front, rear, size;

void enqueue(int key)
{
    if ((rear+1)%size== front)
    {
        printf("the queue is full\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        q[rear]= key;
    }
    else
    {
        rear = (rear+1)%size;
        q[rear]= key;        
    }
}

void dequeue()
{
    if (front == -1 )
    {
        printf("queue is empty\n");
    }
    else if (front == rear)
    {
        printf("the deleted item is %d\n",q[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("the deleted item is %d\n",q[front]);
        front = (front+1)%size;
    }
}

void display()
{
    if (front == -1)
    {
        printf("queue is empty\n");
    }
    else if (front < rear)
    {
        for ( int i=front;i<=rear;i++)
        {
            printf("%d ",q[i]);
        }
    }
    else
    {
        for(int i=front ; i<=(size-1); i++)
        {
            printf("%d ",q[i]);
        }
        for (int i=0;i<=rear;i++)
        {
            printf("%d ",q[i]);
        }
    }
}

void search(int key)
{
    if (front == -1)
    {
        printf("queue is empty\n");
    }
    else if (front < rear)
    {
        for ( int i=front;i<rear;i++)
        {
            if(q[i]==key)
            {
                printf("the key is found in the queue\n");
            }
        }
    }
    else
    {
        for(int i=front ; i<(size-1); i++)
        {
            if(q[i]==key)
            {
                printf("the key is found in the queue\n");
            }
        }
        for (int i=0;i<rear;i++)
        {
            if(q[i]==key)
            {
                printf("the key is found in the queue\n");
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
    int key;
    do
    {
        printf("enter an option:\n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: printf("enter the element to insert:\n");
                    scanf("%d",&key);
                    enqueue(key);
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