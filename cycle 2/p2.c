#include <stdio.h>

#define max 5

int C_Queue[max];
int front = -1;
int rear = -1;

int isEmpty()
{
	if(((front==-1)&&(rear==-1)) || (rear > front))
		return 1;
	else
		return 0;
}

int isFull()
{
	if(((front+1)%max)==(rear%max))
		return 1;
	else
		return 0;
}

void insert(int data)
{
	if(!isFull())
	{
		if(front==-1)
			rear = rear + 1;
		front = front + 1;
		C_Queue[front%max] = data;
		printf("\nThe data %d has been inserted to the Queue at location %d", C_Queue[front%max], (front%max)+1);
		return;
	}
	else
	{
		printf("\nThe Circular Queue is full!");
		return;
	}
}

void delete()
{
	if(!isEmpty())
	{
		printf("\nThe data %d has been deleted from the Queue at location %d", C_Queue[rear%max], (rear%max)+1);
		rear = rear + 1;
		return;
	}
	else
	{
		printf("\nThe Circular Queue is Empty!");
		return;	
	}
}

void traverse()
{
    int i;
	if(!isEmpty())
	{
	    printf("\nThe data in the Circular Queue are : ");
		for(i=rear;i<=front;i++)
			printf("%d\t", C_Queue[i%max]);
		return;
	}
	else
	{
		printf("\nThe Circular Queue is Empty!");
		return;	
	}
}

void main()
{
	int option, data;
	while(option!=6)
	{	
		printf("\nEnter the number besides the Circular Queue operation you want to perform:\n1.insert\t2.Delete\t3.Traverse\t4.Front value\t5.Rear value\t6.Exit\n");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				{
					printf("\nEnter the data to be inserted: ");
					scanf("%d", &data);
					insert(data);
					break;
				}
			case 2:
				{
					delete();
					break;
				}
			case 3:
				{
					traverse();
					break;
				}
			case 4:
				{	
					if(!isEmpty())
						printf("\nThe front points at %d which has value %d.\n", (front%max)+1, C_Queue[front%max]);
					else
						printf("\nThe Circular Queue is empty!");
					break;
				}
			case 5:
				{
					if(!isEmpty())
						printf("\nThe rear points at %d which has value %d.\n", (rear%max)+1, C_Queue[rear%max]);
					else
						printf("\nThe Circular Queue is empty!");
					break;
				}
			case 6:
				break;
				
			default:
				{
					printf("\nInvalid data. Please try again.\n");
					break;
				}
		}
	}
}
