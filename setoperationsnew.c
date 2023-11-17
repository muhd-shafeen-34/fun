//set operations using bit vector
#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
char alphabets[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char set1[26],set2[26];
int bitset1[26], bitset2[26], buni[26],binter[26],comp1[26],comp2[26],setdiffer[26];
//TO FIND BIT VECTOR OF SET 1
int bitvector1(char set[26], int size)
{	
	int n,i,j;
	for(i=0;i<26;i++)
	{
		bitset1[i] = 0;		
	}
	for(i=0;i<size;i++)
	{
		for(j=0;j<26;j++)
		{
			if(set[i] == alphabets[j])
			{
				bitset1[j]=1;
			}
		}
	}	
}
//TO FIND BIT VECTOR OF SET 2
int bitvector2(char setr[26], int size)
{	
	int n,i,j;
	for(i=0;i<26;i++)
	{
		bitset2[i] = 0;		
	}
	for(i=0;i<size;i++)
	{
		for(j=0;j<26;j++)
		{
			if(setr[i] == alphabets[j])
			{
				bitset2[j]=1;
			}
		}
	}	
}
//TO FIND UNION OF SET1 AND SET2
void unio()
{
	int i;
	for(i=0;i<26;i++)
	{
		buni[i]=0;
	}
	for(i=0;i<26;i++)
	{
		buni[i]=bitset1[i]|bitset2[i];
	}
}
//TO FIND INTERSECTION OF SET 1 AND SET 2
void intersection(int bitset1[26],int bitset2[26])
{

	int i;
	for(i=0;i<26;i++)
	{
			
		binter[i]=0;

	}

	for(i=0;i<26;i++)
	{		
		binter[i]=bitset1[i]&bitset2[i];
	}	
}
// TO FIND COMPLEMENT OF SET 1
 int complement(int bs[26],int comp1[26])
{
	int i;
	for(i=0;i<26;i++)
	{
          		 if(bs[i]==1)
         		  {
             			  comp1[i]=0;
         		  } 
         		  else
           		{
              			 comp1[i]=1;
         		  }
		

	}
}
// TO FIND SET DIFFERENCE
int setdiff(int bitset1[26],int comp2[26])
{
	int i;
	for(i=0;i<26;i++)
	{
			
		setdiffer[i]=0;

	}

	for(i=0;i<26;i++)
	{		
		setdiffer[i]=bitset1[i]&comp2[i];
		
	
	}	
}
//TO DISPLAY ALL THE OPERATIONS
 int display(int arr[26])
{
	int i;
	for(i=0;i<26;i++)
	{
		printf("-%d",arr[i]);
	}
}
//TO DISPLAY CHARECTERS OF OPERATIONS FROM UNIVERSAL SET
int set(int arr1[26], char alp[26])
{
	int i;
	printf("\nSet rep = { ");
	for(i =0;i<26;i++)
	{
		if(arr1[i]==1)
		{
			printf("%c",alp[i]);
		}
	}
	printf(" }");					
}
//TO GET ELEMENTS INTO SET 1 AND SET 2
int getele()
{
	int m,n,i;
	printf("enter the size for set 1: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter elements: ");
		scanf("%s",&set1[i]);
	}
	for(i=0;i<26;i++)
	{
		set1[i]=toupper(set1[i]);
	}
	bitvector1(set1,n);  //Calling bitvector function to get bit vector of set 1
	display(bitset1);
	printf("\nenter the size for set 2: ");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		printf("enter elements");
		scanf("%s",&set2[i]);
	}
	for(i=0;i<26;i++)
	{
		set2[i]=toupper(set2[i]);
	}
	bitvector2(set2,m);  //Calling bitvector function to get bit vector of set 2
	display(bitset2);
}

int main()
{
	getele();
	int c;
	printf("\n------------------SET OPERATIONS USING BIT VECTOR------------------\n");
	while(1)   
    	{  
        
        		printf("\n1.UNION\n2.INTERSECTION\n3.COMPLEMENT OF SET 1\n4.COMPLEMENT OF SET 2\n5.SET 		DIFFERENCE\n6.GET ELEMENTS FOR BOTH SET\n7.Exit");  
      		  printf("\nSelect the options\n");         
        		  scanf("%d",&c); 	 
		  switch(c)  
        {  
            case 1: 
		 printf("\nUNION OPERATION\n");
		unio();
		printf("BIT REP OF SET 1 ");
		printf("\n",display(bitset1));
		printf("BIT REP OF SET 2 ");
		printf("\n",display(bitset2));
		printf("BIT REP OF UNION ");
		printf(" \n",display(buni));
		printf("\n",set(buni,alphabets));
             		 break;

            case 2:  
		printf("\nINTERSECTION OPERATION\n");
		intersection(bitset1,bitset2);  
		printf("BIT REP OF SET 1 ");
		printf("\n",display(bitset1));
		printf("BIT REP OF SET 2 ");
		printf("\n",display(bitset2));
		printf("BIT REP OF INTERSECTION ");
		printf("\n",display(binter));
		printf("\n",set(binter,alphabets));
                 		break;

            case 3: 
                  		  printf("\nCOMPLEMENT OPERATION OF SET 1\n");
		 complement(bitset1,comp1); 
		printf("BIT REP OF SET 1 ");
		printf("\n",display(bitset1));
		printf("BIT REP OF COMPLEMENT SET 1 ");
		printf("\n",display(comp1));  
		printf("\n",set(comp1,alphabets));
                    		break;

            case 4: 
                    		printf("\nCOMPLEMENT OPERATION OF SET 2\n");
                    		complement(bitset2,comp2);
		printf("BIT REP OF SET 2 ");
		printf("\n",display(bitset2));
		printf("BIT REP OF COMPLEMENT SET 2 ");
		printf("\n",display(comp2));  
		printf("\n",set(comp2,alphabets));
                    		break;  
            
            case 5:
                    		printf("\nSET DIFFERENCE OPERATION OF SET 1\n");
		complement(bitset2,comp2);
                    		setdiff(bitset1,comp2);
		printf("BIT REP OF SET 1 ");
		printf("\n",display(bitset1));
		printf("BIT REP OF SET 2");
		printf("\n",display(comp1));  
		printf("BIT REP OF SET DIFFERENCE ");
		printf("\n",display(setdiffer));
		printf("\n",set(setdiffer,alphabets));
                    		break;
          case 6:
		getele();
                    		break;

            case 7: 	printf("\nbye bye..\n");
                    		exit(0);  
                   		break;
			 
            default:	printf("\nwrong input..\n");  
        }  
    }  	
return 0;
}


