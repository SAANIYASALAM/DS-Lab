#include <stdio.h>
#include <stdlib.h>

int source,V,E,visited[20],G[20][20],Q[20],front=-1,rear=-1;

void enqueue(int item);
int dequeue();

void enqueue(int item)
{
    if (front==-1 && rear==-1)
    {
        front=rear=0;
        Q[rear]=item;
    }
    else
    {
        rear++;
        Q[rear]=item;
    }
}

int dequeue()
{
    int item;
    if (front ==-1&& rear==-1)
    {
        return -1;
    }
    else if (front == rear)
    {
        item = Q[front];
        front=rear=-1;
        return item;
    }
    else
    {
        item = Q[front ];
        front++;
        return item;
    }
}


void DFS(int i)
{
    visited[i]=1;
    printf("%d ",i);
    for(int j=0;j<V;j++)
    {
        if(G[i][j]==1 && visited[j]==0)
        {
            DFS (j);
        }
    }
}

void BFS(int s)
{
    visited[s]=1;
    printf("%d ",s);
    enqueue(s);
    
    while(front!=-1)
    {
        s = dequeue() ;
        for(int i=0;i<V;i++)
        {
            if (G[s][i]==1 && visited[i]==0)
            {
                printf("%d ",i);
                visited[i]=1;
                enqueue(i);
            }
        }
    }
}


void main ()
{
    int v1,v2,opt;
    
    printf("enter the number of vertices in the graph");
    scanf("%d",&V);
    for(int i=0;i<V;i++)
    {
        for (int j=0;j<V;j++)
        {
            G[i][j]=0;
        }
    }
    
    printf("enter the number of edges in the graph:");
    scanf("%d",&E);
    
    for (int i=0;i<E;i++)
    {
        printf("the number of edges in the format (a,b):");
        scanf("%d%d",&v1,&v2);
        G[v1][v2]=1;
        G[v2][v1]=1;
    }
    
    printf("the adjesency matrix is:");
    for (int i=0;i<V;i++)
    {
        for (int j=0;j<V;j++)
        {
            printf("%d ",G[i][j]);
        }
        printf("\n");
    }
    
    for (int i=0;i<V;i++)
    {
        visited[i]=0;
    }
    
    
    printf("enter the source");
    scanf("%d",&source);
    
    printf("\nDFS\n");
    DFS(source);
    
    for (int i=0;i<V;i++)
    {
        visited[i]=0;
    }
    
    printf("\nBFS\n");
    BFS(source);
    
}