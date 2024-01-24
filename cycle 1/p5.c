#include <stdio.h>

#define max 5
int stack[max];
int top = -1;
int count = -1;

int isFull()
{
	if(top==max-1)
		return 1;
	else
		return 0;
}

int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

void push(int data)
{
	if(!isFull())
	{
		top = top + 1;
		stack[top] = data;
		count = count + 1;
		printf("\nThe item %d has been added to the stack in pos %d.", data, top+1);
		return;
	}
	else
		printf("\nStack is full.");
}

void pop()
{
	if(!isEmpty())
	{
		printf("\nThe item %d has been removed from stack fro pos %d.", stack[top], top+1);
		top = top - 1;
		count = count - 1;
	}
	else
		printf("\nStack is empty.");
}

void traverse()
{
    int i;
	if(!isEmpty())
	{
		for(i=count;i>=0;i--)
			printf("\n%d", stack[i]);
	}
	else
		printf("\nStack is empty.");
}

void peek()
{
	printf("\nThe top is pointing at %d of stack with data %d", top+1, stack[top]);
}

void main()
{
	int select, data;
	while(select!=5)
	{	
		printf("Enter the number besides the stack operation you want to perform:\n1.Push\t\t2.Pop\t\t3.Traverse\t\t4.Peek\t\t5.Exit");
		scanf("%d", &select);
		switch(select)
		{
			case 1:
				{
					printf("Enter the data to be pushed: ");
					scanf("%d", &data);
					push(data);
					break;
				}
			case 2:
				{
					pop();
					break;
				}
			case 3:
				{
					printf("\nThe data in the stack are:\n");
					traverse();
					break;
				}
			case 4:
				{
					peek();
					break;
				}
			case 5:
				break;
			default:
				{
					printf("Invalid data. Please try again.");
					break;
				}
		}
	}
}
