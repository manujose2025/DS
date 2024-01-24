#include  <stdio.h>

#define max 5
int Queue[max];
int front = -1;
int rear = -1;

int isEmpty()
{
	if(((rear==-1) && (front==-1)) || (rear > front))
		return 1;
	else
		return 0;
}

int isFull()
{
	if(front == (max - 1))
		return 1;
	else
		return 0;
}

void insertion(int data)
{
	if(!isFull())
	{	
		if(front==-1)
			rear = rear + 1;
		front = front + 1;
		Queue[front] = data;
		printf("\nThe item %d has been inserted in %d", Queue[front], front+1);
		return;
	}
	else
	{
		printf("\nThe insertion cannot happen as the Queue is Full!");
		return;
	}
}

void deletion()
{
	if(!isEmpty())
	{
		rear = rear + 1;
		printf("\nThe item %d has been removed from %d", Queue[rear - 1], rear - 1);
		return;
	}
	else
	{
		printf("\nThe deletion cannot happen as the Queue is empty!");
		return;
	}
}

void traverse()
{
	int i;
	if(!isEmpty())
	{
		if(rear==-1)
		{
			for(i=rear+1;i<=front;i++)
			{
				printf("%d\t", Queue[i]);
			}
		}
		else
		{
			for(i=rear;i<=front;i++)
			{
				printf("%d\t", Queue[i]);
			}
		}
	}
	else
	{
		printf("\nThe Queue is empty!");
		return;
	}
}

void main()
{
	int option, data;
	while(option!=6)
	{	
		printf("\nEnter the number besides the Queue operation you want to perform:\n1.insert\t2.Delete\t3.Traverse\t4.Front value\t5.Rear value\t6.Exit\n");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				{
					printf("\nEnter the data to be pushed: ");
					scanf("%d", &data);
					insertion(data);
					break;
				}
			case 2:
				{
					deletion();
					break;
				}
			case 3:
				{
					printf("\nThe data in the Queue are:\n");
					traverse();
					break;
				}
			case 4:
				{	
					if(!isEmpty())
						printf("\nThe front points at %d which has value %d.\n", rear+1, Queue[rear]);
					else
						printf("\nThe Queue is empty!");
					break;
				}
			case 5:
				{
					if(!isEmpty())
						printf("\nThe rear points at %d which has value %d.\n", front+1, Queue[front]);
					else
						printf("\nThe Queue is empty!");
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
