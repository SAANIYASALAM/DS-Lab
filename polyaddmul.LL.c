#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff,expo;
    struct node*next;
};
struct node *phead, *qhead, *rhead ,*shead;

struct node *readpoly()
{
    struct node*new ,*ptr ,*head=NULL;
    int n,i;
    
    printf("enter the total number of terms in the polynomial:\n");
    scanf("%d",&n);
    printf("enter the coeffecients and exponents of the polynomial:\n");
    for (int i=0;i<n;i++)
    {
        new = (struct node*)malloc(sizeof(struct node));
        scanf("%d%d",&new->coeff,&new->expo);
        new->next = NULL;
        if (head == NULL)
        {
            head = new;
            ptr = head;
        }
        else
        {
            ptr->next = new;
            ptr=new;
        }
    }
    return (head);
}

void displaypoly(struct node*head)
{
    struct node*ptr;
    if (head==NULL)
    {
        printf("polynomial is empty\n");
    }
    else
    {
        ptr = head;
        while(ptr->next!=NULL)
        {
            printf("%dx^%d + ",ptr->coeff,ptr->expo);
            ptr=ptr->next;
        }
        printf("%dx^%d",ptr->coeff,ptr->expo);
    }
}

struct node *addpoly()
{
    struct node *new, *p, *q, *r, *head = NULL;
    p = phead;
    q = qhead;
    while(p!=NULL && q!=NULL)
    {
        if (p->expo==q->expo)
        {
            new = (struct node*)malloc(sizeof(struct node));
            new->coeff = p->coeff+q->coeff;
            new->expo = p->expo;
            new->next = NULL;
            p = p->next;
            q = q->next;
        }
        else if (p->expo>q->expo)
        {
            new = (struct node*)malloc(sizeof(struct node));
            new->coeff = p->coeff;
            new->expo = p->expo;
            p=p->next;
        }
        else
        {
            new = (struct node*)malloc(sizeof(struct node));
            new->coeff = q->coeff;
            new->expo = q->expo;
            q=q->next;
        }
        if (head == NULL)
        {
            head = new;
            r = head;
        }
        else
        {
            r->next = new;
            r = new;
        }
    }
    while (p!=NULL)
    {
        new = (struct node*)malloc(sizeof(struct node));
        new->coeff = p->coeff;
        new->expo = p->expo;
        new->next = NULL;
        if (head == NULL)
        {
            head = new;
            r = head;
        }
        else
        {
            r->next = new;
            r = new;
        }
        q = q->next;
    }
    return(head);
}

struct node * mulpoly()
{
    struct node * new, *p ,*q, *s, *head = NULL;
    p = phead;
    while (p!=NULL)
    {
        q=qhead;
        while(q!=NULL)
        {
            new = (struct node *)malloc(sizeof(struct node));
            new->coeff = p->coeff * q->coeff;
            new-> expo = p->expo + q->expo;
            new->next = NULL;
            if (head == NULL)
            {
                head = new;
                s = head;
            }
            else
            {
                s->next = new;
                s = new;
            }
            q = q->next;
        }
        p = p->next;
    }
    return (head);
}


void main()
{
    printf("enter the details of the first polynomial:\n");
    phead=readpoly();
    printf("enter the details of the second polynomial:\n");
    qhead=readpoly();
    
    printf("first polynomial:\n");
    displaypoly(phead);
    printf("second polynomial:\n");
    displaypoly(qhead);
    
    rhead=addpoly();
    printf("the resultant polynomial:\n");
    displaypoly(rhead);
    
    shead = mulpoly();
    printf ("the multiplied polnomial is :\n");
    displaypoly(shead);
}