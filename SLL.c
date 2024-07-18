#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node*head;

void display()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("the list is empty");
    }
    else
    {
        ptr = head;
        printf("the list elements are");
        while (ptr->next!= NULL)
        {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
    }
}

void insertfront(int x)
{
    struct node* new;
    new = (struct node *)malloc (sizeof(struct node));
    new -> data = x;
    new -> next = head;
    head = new;
    display();
}

void insertend(int x)
{
    struct node* new, *ptr;
    new = (struct node *)malloc (sizeof(struct node));
    new -> data = x;
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        ptr = head;
        while (ptr ->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr ->next = new;
    }
    display();
}

void insertany(int key,int x)
{
    struct node* ptr;
    if (head == NULL)
    {
        printf("key not found");
    }
    else
    {
        ptr = head;
        while (ptr ->data!= key && ptr->next !=NULL)
        {
            ptr = ptr->next;
        }
        if(ptr->data != key)
        {
            printf("data not found");
        }
        else
        {
            struct node* new;
            new = (struct node *)malloc (sizeof(struct node));
            new -> data = x;
            new ->next = ptr->next;
            ptr -> next = new;
        }
    }
    display();
}

void deletefront()
{
    struct node*temp ;
    if (head == NULL)
    {
        printf("list enpty\n");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    display();
}

void deleteend()
{
    struct node *prev, *curr, *temp;
    if (head == NULL)
    {
        printf("list empty");
    }
    else if (head ->next == NULL)
    {
        temp = head ;
        head= NULL;
        free (temp);
    }
    else 
    {
        prev = head;
        curr = head -> next;
        while (curr -> next!=NULL)
        {
           prev= curr;
           curr = curr-> next;
        }
        prev->next = NULL;
        free (curr);
    }
}

void deleteany(int key)
{
    struct node*prev,*curr,*temp;
    if(head == NULL)
    {
        printf("list empty");
    }
    else if (head -> data = key)
    {
        temp = head;
        head = head -> next;
        free (temp);
    }
    else
    {
        prev = head ;
        curr = head;
        while (curr ->data != key && curr-> next != NULL)
        {
            prev = curr;
            curr = curr-> next;
        }
        if (curr ->data!= key)
        {
            printf("no data");
        }
        else 
        {
            prev ->next = curr-> next;
            free (curr);
        }
    }
}


void main()
{
    int opt,key,x;
    do
    {
        printf("enter the option:\n1.insert at front\n2.inset at end\n3.inset at any\n4.delete from front\n5.delete from end\n6.delete from any\n7.dispaly\n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: printf("enter the new data");
                    scanf("%d",&x);
                    insertfront(x);
                    break;
            case 2: printf("enter the new data");
                    scanf("%d",&x);
                    insertend(x);
                    break;
            case 3: printf("enter the search key");
                    scanf("%d",&key);
                    printf("enter the new data");
                    scanf("%d",&x);
                    insertany(key,x);
                    break;
            case 4: deletefront();
                    break;
            case 5: deleteend();
                    break;
            case 6: printf("enter the node to be deleted\n");
                    scanf("%d",&key);
                    deleteany(key);
                    break;
            case 7: display();
                    break;
            
        }
    }
    while(opt!=8);
}