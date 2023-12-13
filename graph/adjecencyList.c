#include<stdio.h>
#include<stdlib.h>

int V,type,E;
struct AdjList
{
	int key;
	struct AdjList *next;
};
struct AdjList *vtx[5];
int front = -1,rear = -1,q[20];
int graph[5] [5]; //{{0,1,0,1,0},{1,0,1,0,0},{0,1,0,1,1},{1,0,1,0,1},{0,0,1,1,0}};
int visit[5]={0,0,0,0,0};

//void getMatrix(int v)
//{
//	int i,j;
//	for(i=0 ;i<v ;i++)
//	{
//		for(j=0;j<v;j++)
//		{
//			scanf("%d",&graph[i][j]);
//		}
//	}
//}
void createList(int V, int E)
{
	int i;
	struct AdjList *newnode, *ptr;
	for(i=0;i<V;i++)
	{
		vtx[i] = NULL;
	}
	
	newnode = (struct AdjList *)malloc(sizeof(struct AdjList));
	newnode->key = E;
	newnode->next = NULL;
	if(vtx[V]== NULL)
	{
		vtx[V]=newnode;
	}
	else
	{
		ptr = vtx[V];
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = newnode;
}	
//void createMatrix(int v, int e ,int type)
//{
//	int i,j,E1,E2;
//	for(i=0;i<v;i++)
//	{
//		for(j=0;j<v;j++)
//		{
//			graph[i][j]=0;
//		}
//	}
//	for(i<0;i<e;i++)
//	{
//		scanf("%d %d",&E1,&E2);
//		graph[E1][E2] = 1;
//		if (type == 2)
//		{
//			graph[E2][E1]=1;
//		}
//	}
}//
void enq(int item)
{   
    
    if(rear>=20){
        printf("Queue is full\n");
    }
    else if(rear==-1 && front==-1)
    {
    
    front=rear=0;
    q[rear]=item;

    }
    else{
        
        rear++;
        q[rear]=item;

    }
}
int  deq()
{
int del;
    if(front==-1){
        printf("Queue is empty\n");
    }
    else 
    {
          del=q[front];
          if(front==rear){
                    front=rear=-1;
          }
          else{
                    front++;
          }
    }
    return(del);
}
int isVisited(int vtx)
{
          return(visit[vtx]);
}
int bfs(int s)
{
                    int vtx;
                   enq(s);
          while((front !=-1) && (rear!=-1))
          {
                    vtx =deq();
                    if(! isVisited(vtx))
                    {
                              visit [vtx]=1;
                              printf("%d ",vtx);
                              for(int i=0;i<5;i++)
                              {
                                        if(graph[vtx][i]==1)
                                        enq(i);
                              }
                              
                    }
          }
}
void display_graph()
{
          int i,j;
          for(i=0;i<5;i++)
          {
                    for(j=0;j<5;j++)
                    {
                              printf("%d",graph[i] [j]);
                    }
               printf("\n");
          }
}
void display()
{
          int i;
          for(i=0;i<5;i++)
          {
                    printf("\n %d ",visit[i]);
          }
          printf("\n");
}
int main()
{
	int E1,E2;
       printf("Enter the number of vertices ");
	scanf("%d",&V);
	//getMatrix();
	printf("Enter the tyoe of graph (enter 1 for directed and 2 for undirected:- ");
	scanf("%d",&type);
	printf("Enter the number of edges:- ");
	scanf("%d",&E);
	//createMatrix(V,E,type);
	printf("enter the edges: ");
	for(int i=0;i<E;i++)
	{
		scanf("%d %d",&E1,&E2);
		createList(E1,E2);
		if(type == 2)
		{
			createList(E2,E1);
		}
	}	


	
          //display_graph();
          printf("BFS traversal is :");
          bfs(4);
          display();
	
}