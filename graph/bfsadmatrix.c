#include<stdio.h>
int front = -1,rear = -1,q[20];
int graph[5] [5]; //{{0,1,0,1,0},{1,0,1,0,0},{0,1,0,1,1},{1,0,1,0,1},{0,0,1,1,0}};
int visit[5]={0,0,0,0,0};
int V;
void getMatrix(int v)
{
	int i,j;
	for(i=0 ;i<v ;i++)
	{
		for(j=0;j<v;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
}
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
       printf("Enter the number of vertices ");
	scanf("%d",&V);
	getMatrix(V);
          //display_graph();
          printf("BFS traversal is :");
          bfs(4);
          display();
}
