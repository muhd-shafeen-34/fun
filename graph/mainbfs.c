#include<stdio.h>
#include<stdlib.h>

int front=-1,rear=-1,q[25];

int graph[5][5];//={{0,1,1,0,0},{1,0,0,1,1},{1,0,0,1,0},{0,1,1,0,1},{0,1,0,1,0}};
int visit[5]={0,0,0,0,0};
int V, E, type;
int E1, E2;

struct adjlist
{
	int key;
	struct adjlist *next;
};
struct adjlist *vx[10];


void createlist(int v, int e)
{
	int i;
	struct adjlist *newnode;
	struct adjlist *ptr;
	
	newnode = (struct adjlist *)malloc(sizeof(struct adjlist));
	newnode->key = e;
	newnode->next = NULL;
	if(vx[v] == NULL)
	{
		vx[v] = newnode;
	}
	else
	{
		ptr = vx[v];
		while(ptr->next != NULL)
		{
			ptr = ptr->next;			
		}
		ptr->next = newnode;
	}
}

void creatematrix(int E, int V, int type)
{
	//initialize 
	int i, j;
	int E1, E2;
	
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			graph[i][j]	= 0;
		}
	}
	for (i=0; i<E; i++)
	{
		scanf("%d %d", &E1, &E2);
		graph[E1][E2] = 1;
		
		if (type == 2)
		{
			graph[E2][E1] = 1;
		}
	}
}

void getmatrix(int V)
{
	int i, j;
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
}


void enq(int item)
{   
    
	if(rear==24)
	{
	        printf("Queue is full\n");
	}
    	else if(rear==-1 && front==-1)
    	{
    		front=rear=0;
    		q[rear]=item;
    	}
    	else
	{
        	rear++;
        	q[rear]=item;
    	}
}

int deq()
{
	int item=0;
    	if(front==-1)
	{
	 	printf("Queue is empty\n");
 	}
    	else if(front==rear)
	{
		item=q[front];
	        front=rear=-1;
	}
    	else
	{
		item=q[front];
        	front++;
        }
	return item;
}

void bfs(int s)
{
	int V,i;
	enq(s);
	while((front!=-1)&&(rear!=-1))
	{
		V=deq();
		
		if(visit[V]!=1)
		{
			visit[V]=1;
			printf("%d ",V);
			for(i=0;i<5;i++)
			{
				if(graph[V][i]==1)	
					enq(i);

			}

		}
	}

}

void bfsList(int s)
{
	int X;
	struct adjlist *ptr;
	enq(s);
	while((front!=-1)&&(rear!=-1))
	{
		X=deq();
		
		if(!visit[X])
		{
			visit[X]=1;
			printf("%d ",X);
			ptr = vx[X];
			while(ptr != NULL)
			{
				enq(ptr->key);
				ptr = ptr->next;
			}

		}
	}

}

void disp_graph()
{
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		 printf("%d ",graph[i][j]);
	
		printf("\n");	
	}


}

void display_list()
{
	int i;
	struct adjlist *ptr;
	printf("adjecency list are ");
	for(i=0;i<V;i++)
	{
		ptr=vx[i];
		while(ptr != NULL)
		{
			printf("%d ",ptr->key);
			ptr = ptr->next;
		}
	printf("\n");
	}
	
}



int main()
{  
	int i;

	printf("Enter the number of vertices: \n");
	scanf("%d", &V);
//	getmatrix(V);

	printf("Enter the type of graph (enter 1 for directed graph 2 for undirected graph)\n");
	scanf("%d", &type);

	printf("Enter the no of edges: \n");
	scanf("%d", &E);
	//creatematrix(E,V,type);


	//printf("\nTHE MATRIX OF GRAPH: \n");
	//disp_graph();
		
	
	//Initialization of pointer array
	for(i=0;i<V;i++)
	{
		vx[i] = NULL;
	}
	printf("Enter the edges :");
	for (i=0; i<E; i++)
		{
			scanf("%d %d", &E1, &E2);
			createlist(E1, E2);
			if(type == 2)
			{
				createlist(E2,E1);
			}
		}
display_list();
printf("\nTHE BFS TRAVERSAL OF VERTICES ARE: \n");
bfsList(0);
		
	

    return 0;

}	
