#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int prio;
    struct node *next;
};
struct node*head = NULL;

void insert(int key, int priority)
{
    struct node* ptr;
    struct node* new = (struct node *)malloc(sizeof(struct node));
    new->data = key;
    new->prio = priority;
    if (head == NULL||priority<head->prio)
    {
        new->next = head;
        head = new;
    }
    else
    {
        ptr = head;
        while(ptr->next!=NULL && ptr->next->prio<=priority)
        {
            ptr = ptr->next;
        }
        new -> next = ptr->next;
        ptr->next = new;
    }
}

void delete()
{
    if (head == NULL)
    {
        printf("the queue is empty\n");
    }
    else 
    {
        struct node * temp;
        temp = head;
        printf("the deleted item is %d", temp->data);
        head = head ->next;
        free(temp);
    }
}

void display()
{
    if (head == NULL)
    {
        printf("queue is empty\n");
    }
    else
    {
        struct node *ptr = head;
        printf("the elements are :\n");
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
    }
}

void main()
{
    int key,priority,opt;
    printf("choose an option\n1.insert\n2.delete\n3.display\4.exit\n");
    do
    {
        printf("enter an option:\n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: printf("enter the data and its priority:\n");
                    scanf("%d%d",&key,&priority);
                    insert(key,priority);
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: printf("exitting....");
                    break;
        }
    }
    while(opt!=4);
}
