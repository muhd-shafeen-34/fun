#include<stdio.h>
int front,rear,q[25],size;
int graph[5][5] = {{0,1,1,0,0},{1,0,0,1,1},{1,0,0,1,0},{0,1,1,0,1},{0,1,0,1,0}};
int visit[5] = {0,0,0,0,0};

void enq(int item)
{   
    
    if(rear==size-1){
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
int deq()
{
  int del;
    if(front==-1){
        printf("Queue is empty\n");
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
	del = q[front];
        front++;
     return(del);
        

    }
}

void bfs(int s)
{
	int vtx;
	enq(s);
	while((front != -1) && (rear != -1))
	{
		vtx = deq();
		if(visit[vtx]!= 1)
		{
			visit[vtx]=1;
			printf("%d ",vtx);
			for(int i =0;i<5;i++)
			{
				if(graph[vtx][i]==1)
				{
					enq(i);
				}
			}
		}	
	}
}
void display()
{
	int i;
	for(i=0;i<=5;i++)
	{
		printf("\n%d ",visit[i]);
	}
}




void display_graph()
{
	int i,j;
	for(i = 0; i<5; i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
}
int main()
{
display_graph();
bfs(0);
display();
}
