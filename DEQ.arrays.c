#include <stdio.h>

int q[100],size,front,rear,i;

void insertfront(int key)
{
    if (front == 0&&rear == size-1)
    {
        printf("the queue is full\n");
    }
    else if (rear == -1)
    {
        front = 0;
        rear= 0;
        q[front]=key;
    }
    else if(front>0)
    {
        front--;
        q[front]=key;
    }
    else
    {
        for (int i= rear;i>=front ;i--)
        {
            q[i+1]=q[i];
        }
        q[front]=key;
        rear++;
    }
}

void insertrear(int key)
{
    if (front == 0&&rear == size-1)
    {
        printf("the queue is full\n");
    }
    else if(rear == -1)
    {
        front = 0;
        rear =  0;
        q[rear] = key;
    }
    else if (rear <size-1)
    {
        rear++;
        q[rear]= key;
    }
    else
    {
        for (int i= front;i<=rear;i++)
        {
            q[i-1]=q[i];
        }
        q[rear]= key;
        front --;
    }
}

void dequeuefront()
{
    if(front == -1)
    {
        printf("queue is empty\n");
    }
    else if (front == rear)
    {
        printf("the deleted item is %d",q[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("the deleted item is %d",q[front]);
        front ++;
    }
}

void dequeuerear()
{
    if (front == -1)
    {
        printf("the queue is empty\n");
    }
    else if (front == rear)
    {
        printf("the deleted item is %d",q[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("the deleted item is %d",q[rear]);
        rear --;
    }
}

void display()
{
    if (front == -1)
    {
        printf("the queue is empty\n");
    }
    else
    {
        for (int i = front ;i<=rear ; i++)
        {
            printf("%d ",q[i]);
        }
    }
}

void search(int key)
{
    if (front == -1)
    {
        printf("the queue is empty\n");
    }
    else
    {
        for (int i = front ;i<=rear ; i++)
        {
            if (q[i]==key)
            {
                printf("the key is found\n");
            }
        }
    }
}

void main()
{
    front = rear = -1;
    int opt;
    printf("enter the size of the queue:\n");
    scanf("%d",&size);
    printf("choose any option\n1.enqueue at front\n2.enqueue at rear\n3.dequeue at front\n4.dequeue at rear\n5.display\n6.search\n7.exit\n");
    int key;
    do
    {
        printf("enter an option:\n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: printf("enter the element to insert:\n");
                    scanf("%d",&key);
                    insertfront(key);
                    break;
            case 2: printf("enter the element to insert:\n");
                    scanf("%d",&key);
                    insertrear(key);
                    break;
            case 3: dequeuefront();
                    break;
            case 4: dequeuerear();
                    break;
            case 5: display();
                    break;
            case 6: printf("enter the element to search:\n");
                    scanf("%d",&key);
                    search(key);
                    break;
            case 7: printf("exiting the program.....");
                    break;
        }
    }
    while (opt!=7);
}