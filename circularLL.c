#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node * head;

void insertfront(int x)
{
    struct node *new, *ptr;
    new = (struct node*)malloc(sizeof(struct node));
    new->data = x;
    
    if (head == NULL)
    {
        new->next = new;
        head = new;
    }
    
    else
    {
        ptr= head;
        while(ptr->next!=head)
        {
            ptr= ptr->next;
        }
        new->next = head;
        head= new;
        ptr ->next = head;
    }
}

void insertend(int x)
{
    
    struct node *new, *ptr;
    new = (struct node*)malloc(sizeof(struct node));
    new->data = x;
    
    if (head == NULL)
    {
        new->next = new;
        head = new;
    }
    else 
    {
        ptr = head;
        while (ptr->next!=head)
        {
            ptr = ptr->next;
        }
        ptr->next = new;
        new->next = head;
    }
}

void insertatany(int key, int x)
{
    struct node *new, *ptr;
    new = (struct node*)malloc(sizeof(struct node));
    new->data = x;
    
    if (head==NULL)
    {
        printf("search key not found!");
    }
    else
    {
        ptr = head;
        while(ptr->data!=key)
        {
            ptr = ptr->next;
            if (ptr==head)
            {
                break;
            }
            if (ptr->data = key)
            {
                new->next = ptr->next;
                ptr->next = new;
            }
        }
    }
}

void deletefront()
{
    struct node *ptr,*temp;
    if (head == NULL)
    {
        printf("deletion not possible");
    }
    else if(head->next == head)
    {
        temp = head;
        head = NULL;
        free(head);
    }
    else
    {
        temp = ptr = head;
        while (ptr ->next!= head)
        {
            ptr = ptr->next;
        }
        head = head->next;
        ptr->next = head;
        free(temp);
    }
}

void deleteend()
{
    struct node *temp,*prev,*curr;
    if (head==NULL)
    {
        printf("deletion not possible");
    }
    else if(head ->next ==head)
    {
        temp = head;
        head=NULL;
        free(temp);
    }
    else
    {
        curr = head;
        while(curr ->next!= head)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = head;
        free(curr);
    }
}

void deleteany(int key)
{
    struct node *temp,*ptr,*curr;
    if (head == NULL)
    {
        printf("search not found");
    }
    else if(head ->next == head)
    {
        if(head->data == key)
        {
            temp = head;
            head= NULL;
            free(temp);
        }
        else
        {
            printf("search data not found");
        }
    }
    else if (head->data == key)
    {
        temp = ptr = head;
        while(ptr->next !=head)
        {
            ptr = ptr->next;
        }
        head = head->next;
        ptr->next = head;
        free(temp);
    }
    else
    {
        temp = ptr = curr = head;
        while( ptr->data != key)
        {
            curr = ptr;
            ptr= ptr->next;
        }
        temp = ptr;
        curr->next = ptr->next;
        free(temp);
    }
}

void display()
{
    if (head == NULL)
    {
        printf("the list is empty\n");
    }
    else
    {
        struct node* ptr;
        ptr = head;
        while(ptr->next!= head)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}

void main()
{
    printf("CIRCULAR QUEUE\n");
    int opt;
    printf("choose any option\n1.enqueue at front\n2.enqueue at end\n3.enqueue at any\n4.dequeue from front\n5.dequeue from end\n6.dequeue at any\n7.traverse\n8.exit\n");
    int x, key;
    do
    {
        printf("enter the option");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: 
                    printf("\nenter the element to add\n");
                    scanf("%d",&x);
                    insertfront(x);
                    display();
                    break;
            case 3: 
                    printf("\nenter the element to add\n");
                    scanf("%d",&x);
                    insertend(x);
                    display();
                    break;
            case 4: 
                    printf("\nenter the element to add\n");
                    scanf("%d",&x);
                    printf("adter which element need to add?\n");
                    scanf("%d",&key);
                    insertatany(key,x);
                    display();
                    break;
            case 5: deletefront();
                    break;
            case 6: deleteend();
                    break;
            case 7: 
                    printf("enter the data need to delete:\n");
                    scanf("%d",&key);
                    deleteany(key);
                    break;
            case 8: display();
                    break;
        }
    }
    while (opt!=9);
}