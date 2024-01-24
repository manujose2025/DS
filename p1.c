#include <stdio.h>
#define max 20
int size = 0;

void insert(int a[], int val, int pos)
{
	int i;
	if((pos <= size+1) && (pos > 0))
	{
		if(size+1 <= max)
		{
			for(i=size;i>=pos-1;i--)
			{
				if(i==pos-1)
				{
					a[i] = val;
					size++;
					break;
				}
				else
					a[i] = a[i-1];
			}
			printf("\nThe item %d has been inserted at position %dand the size of the array has increasedto %d.", val, pos, size);
			return;
		}
		else
		{
			printf("\nArray overflow! Please delete an item to insert the value.");
			return;
		}
	}
	else
	{
		printf("\nInvalid position!");
		return;
	}  
}

void delete(int a[], int pos)
{
	int i;
	if((pos <= size) && (pos > 0))
	{
		if(size-1 >= 0)
		{
			printf("\nThe item %d has been deleted from position %d of the array", a[pos-1], pos);
			
			for(i=pos-1;i<size-1;i++)
			{
				a[i] = a[i+1];
			}
			
			size--;
		}
		else
		{
			printf("\nThe array is empty!");
			return;
		}
	}
	else
	{
		printf("\nInvalid position!");
		return;
	}
}

void sort(int a[])
{
	int i, j, temp;
	
	if(size == 0)
	{
		printf("\narray is empty!");
		return;
	}
	else if(size == 1)
	{
		return;
	}
	else
	{
		for(i=0;i<size-1;i++)
		{
			for(j=i+1;j<size;j++)
			{
				if(a[i] > a[j])
				{
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
		printf("\nThe array hs been sorted.");
		return;
	}
}

void merge(int a[], int b[], int n)
{
	int i, j;
	if(size+n <= max)
	{
		for(i=size,j=0;i<size+n;i++,j++)
		{
			a[i] = b[j];
		}
		size += n;
	}
	else
	{
		printf("Array merge is not possible as the sie of the merged array will be greater than the limit.");
		return;
	}
}

void traverse(int a[])
{
	int i;
	
	if(size==0)
	{
		printf("\nThe array is empty!");
	}
	else
	{
		printf("\nThe values of the array are : \n");
	
		for(i=0;i<size;i++)
			printf("%d\t", a[i]);
	}
	return;
}

void main()
{
	int option, a[max], b[max], n, i, value, pos;
	
	printf("\nEnter the size of array : ");
	scanf("%d", &size);
	
	if(size <= max)
	{
		printf("\nEnter the values of array : \n");
		for(i=0;i<size;i++)
			scanf("%d", &a[i]);
	}
	else
	{
		printf("\nThe size entered for the array is more that the limit. Please try again.\n");
		return;
	}
	
	while(option != 6)
	{
		printf("\nEnter the number adjacent to array opearation that you like to perform.\n1.Insert\t2.Delete\t3.Sort\t4.Merge\t5.traverse\t6.Exit\n");
		scanf("%d", &option);
		
		switch(option)
		{
			case 1:
				printf("\nEnter the value to be inserted : ");
				scanf("%d", &value);
				
				printf("\nEnter the position in which the value needs to be entered : ");
				scanf("%d", &pos);
				
				insert(a, value, pos);
				
				break;
				
			case 2:
				printf("\nEnter the position from where the value needs to be deleted : ");
				scanf("%d", &pos);
				
				delete(a, pos);	
				
				break;
				
			case 3:
				sort(a);
				break;
				
			case 4:
				printf("\nEnter the size of 2nd array : ");
				scanf("%d", &n);
	
				if(n <= max)
				{
					printf("\nEnter the values of 2nd array : \n");
					for(i=0;i<n;i++)
						scanf("%d", &b[i]);
					
					merge(a, b, n);
				}
				else
				{
					printf("\nThe size entered for the array is more that the limit. Please try again.\n");
				}
					
				
			case 5:
				traverse(a);
				break;
				
			case 6:
				break;
			
			default:
				printf("Invalid Entry! please try again.");
		}
	}
}
