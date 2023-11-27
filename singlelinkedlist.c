#include<stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *link;
};

struct node *header = NULL;

void insert_at_front(int item)
{
	// for the first node 
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node)); 
	if(header == NULL)
	{
		newnode -> data = item;
		newnode -> link = NULL;
		
	}
	else
	{	// for the subsequent nodes
		newnode -> data = item;
		newnode->link = header;
	}
	header = newnode;
	printf("inserted %d at position 1 ",item);
	
	
}

void traversal()
{
	struct node *ptr;
	ptr = header;
	printf("elements are : \n");
	while(ptr != 	NULL)
	{
		printf("%d ",ptr->data);
		ptr = ptr->link;
	}
	
}

void insert_at_end(int item)
{
	int count =0;
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node)); 
	struct node *ptr;
	ptr = header;
	while(ptr ->link != NULL)
	{
		ptr=ptr->link;
		count ++;
	}
	ptr -> link = newnode;
	newnode->link = NULL;
	newnode->data = item;
	printf("inserted at position %d ",count+2);	
}
void insert_at_anypos(int item,int key)
{
	int count = 0;
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node)); 
	newnode->data=item;
	struct node*temp;
	temp=header;
	while(temp->data!=key && temp->link!=NULL)
	{
		temp = temp->link;
		count++;
	}
	if((temp->link==NULL)&&(temp->data==key))
	{
		newnode->link=NULL;
		temp->link=newnode;
		printf("inserted at position %d ",count+2);
		
	}
	else if((temp->link==NULL)&&(temp->data!=key))
	{
		printf("key not found");
	}	
	else
	{
		newnode->link=temp->link;
		temp->link=newnode;
		printf("inserted at position %d ",count+2);
	}
}
void delete_at_front()
{
	if (header==NULL)
	{
		printf("list is empty");
	}
	else
	{
	struct node *temp=header;
	printf("deleted element is %d ",temp->data);
	header = temp->link;
	
	free(temp);
	}
}
void delete_at_end()
{
	if (header==NULL)
	{
		printf("list is empty");
	}
	else if(header->link == NULL)
	{
		header=NULL;
	}
	else
	{
		struct node  *temp1=header;
		struct node 	*temp2=header;
		while(temp1->link != NULL)
		{
			temp2=temp1;
			temp1=temp1->link;
		}
		printf("deleted element is %d ",temp1->data);
		temp2->link=NULL;
		free(temp1);
		
	}
}
void delete_at_anypos(int key)
{
	if(header==NULL)
	{
		printf("List is empty");
	}
	else
	{
		struct node *temp1=header;
		struct node *temp2=header;
		while((temp1 != NULL) && (temp1->data != key))
		{
			temp2=temp1;
			temp1=temp1->link;
		}
		if(temp1 == NULL)
		{
			printf("key not found");
		}
		else
		{
			if(temp2->link == NULL)
			{
				free(temp2);
				header = NULL;
			}
			else
			{
				if(temp1 == header)
				{
					header=temp1->link;
				}
				else
				{
					temp2->link = temp1->link;
					printf("deleted element is %d ",temp1->data);
				}
				free(temp1);
				
			}
		}
	}
}
void search(int key)
{
	int count=0;
	if(header == NULL)
	{
		printf("list is empty");
	}
	else
	{
		struct node *temp1 = header;
		while((temp1->data!=key)&&(temp1->link != NULL))
		{
			temp1 = temp1->link;
			count ++;
		}
		if((temp1->link = NULL)&&(temp1->data != key))
		{
			printf("key not found");
		}
		else
		{
			printf("key found at position %d\n",count+1);
		}
	
	
	}
	
		
}	
			
int main()
{
	//insert_at_front(10);
	//insert_at_front(20);
	//insert_at_end(30);
	//insert_at_end(40);
	//insert_at_anypos(50,20);
	//delete_at_front();
	//delete_at_end();
	//delete_at_anypos(30);
	//search(10);
	//traversal();	
		
	int z,k,c;	
	printf("------------------LINKED LIST OPERATIONS------------------\n");
	while(1)   
    {  
        
        printf("\n1.Insert at front\n2.Insert at end\n3.Insert after position\n4.Delete at front\n5.Delete at end\n6.Delete node at any position\n7.Display Elements\n8.Search position of Element\n9.Exit");  
        printf("\nSelect the options");         
        scanf("%d",&c);  
        switch(c)  
        {  
            case 1:  
                    printf("\nenter the data to insert at front : ");
                    scanf("%d",&z);
                    insert_at_front(z);
              
                    break;
            case 2:  
                    printf("\nenter the data to insert at end \n");
                    scanf("%d",&z);
                    insert_at_end(z);
	
                    break;
            case 3: 
	if(header==NULL)
	{
		printf("list is empty");
	}
	else
                     { 
            
                    printf("\n---select the key---\n");
                    scanf("%d",&k);
                    printf("\nenter the data to insert after the key \n");
                    scanf("%d",&z);
                    insert_at_anypos(z,k);
	}
                    break;
            case 4:  
                    delete_at_front();       
                    break;  
            case 5:  
                    delete_at_end();        
                    break;  
            case 6:
      	
	if(header==NULL)
	{
		printf("list is empty");
	}
	else
                     {
                    printf("\n---select the key---\n");
                    scanf("%d",&k);  
                    delete_at_anypos(k);    
	}      
                    break;  
            case 7:   
                    traversal();        
                    break;  
            case 8: printf("\n---enter the key---\n");
                    scanf("%d",&k);  
                    search(k);          
                    break;  
                    
	    case 9: printf("\nbye bye..");
                    exit(0);  
                    break;
			 
            default:  
                    printf("wrong input..");  
        }  
    }  
		
	return 0;

}
