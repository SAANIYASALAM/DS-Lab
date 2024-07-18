#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node*next;
    struct node*prev;
};
struct node *head;

void insertatfront(int key)
{
    struct node* new;
    new = (struct node*)malloc (sizeof(struct node));
    new->data = key;
    
    if (head == NULL)
    {
        new->next = NULL;
        new->prev = NULL;
        head = new;
    }
    else
    {
        new->next = head;
        new->prev = NULL;
        head ->prev = new;
        head = new;
    }
}

void display()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("list empty");
    }
    else
    {
        ptr = head;
        printf("the elements in the list is:\n");
        while (ptr != NULL)
        {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
    }
}

void insertend(int key)
{
    struct node* new,*ptr;
    new = (struct node*)malloc (sizeof(struct node));
    new->data = key; 
    
    if (head == NULL)
    {
        new->next = NULL;
        new->prev = NULL;
        head = new;
    }
    else
    {
        ptr = head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next = new;
        new->prev = ptr;
        new->next =NULL;
    }
}
//pos is the element that nodes after our new node will be inseted
void insertany(int key,int pos)
{
    struct node* new,*ptr;
    new = (struct node*)malloc (sizeof(struct node));
    new->data = key; 
    
    if(head ==NULL)
    {
        new->next = NULL;
        new->prev = NULL;
        head = new;
    }
    else
    {
        ptr = head;
        while(ptr->data !=pos && ptr->next!=NULL)
        {
            ptr= ptr->next;
        }
        if(ptr->data!=pos)
        {
            printf("data not found");
        }
        else
        {
            new->next = ptr->next;
            new->prev = ptr;
            ptr->next = new;
        }
    }
}

void deletefront()
{
    struct node*ptr;
    if (head == NULL)
    {
        printf("the list is empty");
    }
    else if (head->next == NULL)
    {
        ptr = head;
        head ->next = NULL;
        head -> prev = NULL;
        free (ptr);
    }
    else
    {
        ptr = head;
        head = head->next ;
        head ->prev = NULL;
        free (ptr);
    }
}

void deleteend()
{
    struct node*ptr;
    if (head == NULL)
    {
        printf("the list is empty");
    }
    else if (head->next == NULL)
    {
        ptr = head;
        head ->next = NULL;
        head -> prev = NULL;
        free (ptr);
    }
    else
    {
        ptr = head;
        while(ptr->next!=NULL)
        {
            ptr= ptr->next;
        }
        ptr->prev->next =NULL;
        free (ptr);
        
    }
}

void deleteany(int key)
{
    struct node*ptr;
    ptr = head;
    while(ptr!=NULL && ptr->data != key)
    {
        ptr = ptr->next;
    }
    if(ptr == NULL)
    {
        printf("no such element");
    }
    else
    {
        if (ptr->prev!=NULL)
        {
            ptr->prev->next= ptr->next;
        }
        if (ptr ->next!=NULL)
        {
            ptr->next->prev= ptr->prev;
        }
        free(ptr);
        
        if(ptr==head)
        {
            head == NULL;
        }
    }
}

void search(int key)
{
    struct node *ptr;
    ptr = head;
    while (ptr !=NULL && ptr->data !=key)
    {
        ptr = ptr->next;
    }
    if (ptr->data = key)
    {
        printf("the data %d is found\n",ptr->data);
    }
    else
    {
        printf("the data not found");
    }
}

void main()
{
    int opt,key,pos;
    printf("\nenter the option\n1.insert at front\n2.insert at end\n3.insert at any\n4.delete at front\n5.delete at end\n6.delete at any\n7.display\n8.search\n");
    do
    {
        printf("\nenter the option");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: printf("\nenter the element to insert");
                    scanf("%d",&key);
                    insertatfront(key);
                    display();
                    break;
            case 2: printf("\nenter the element to insert");
                    scanf("%d",&key);
                    insertend(key);
                    display();
                    break;
            case 3: printf("\nenter the element to inset");
                    scanf("%d",&key);
                    printf("enter the data after the element to insert");
                    scanf("%d",&pos);
                    insertany(key,pos);
                    display();
                    break;
            case 4: deletefront();
                    display();
                    break;
            case 5: deleteend();
                    display();
                    break;
            case 6: printf("\nenter the element to delete\n");
                    scanf("%d",&key);
                    deleteany(key);
                    display();
                    break;
            case 7 :display();
                    break;
            case 8: printf("enter the element to search");
                    scanf("%d",&key);
                    search(key);
                    break;
        }
    }
    while (opt!=9);
    
}