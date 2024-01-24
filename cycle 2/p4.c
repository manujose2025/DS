#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next, *prev;
};

struct node *start = NULL;

struct node* createNode()
{
	struct node *list = malloc(sizeof(struct node));
	return list;
}

void insHead(int data)
{
	struct node *ptr = createNode();
	ptr->data = data;
	ptr->next = start;
	ptr->prev = NULL;
	start = ptr;
	printf("The data %d has been added to the head of the list.\n", start->data);
}

void delHead()
{
	if(start == NULL)
	{
		printf("The list is empty!\n");
		return;
	}
	else
	{
		struct node *temp = start;

		start = temp->next;
		if(start != NULL)
		    start->prev = NULL;
		temp->next = NULL;

		printf("The data %d has been removed from the head of the list.\n", temp->data);
		return;
	}
}

void insTail(int data)
{
	if(start == NULL)
	{
		insHead(data);
		return;
	} 
	else
	{
		struct node *temp;
		temp = start;
	
		while(temp->next != NULL)
			temp = temp->next;
		
		struct node *ptr = createNode();
		
		ptr->data = data;
        ptr->prev = temp;
		ptr->next = NULL;
		temp->next = ptr;
		
		printf("The data %d has been added to the tail of the list.\n", ptr->data);
	}
}

void delTail()
{
	if(start == NULL)
	{
		printf("The list is empty!\n");
		return;
	}
	else if(start->next == NULL)
	{
		delHead();
		return;
	}
	else
	{
		struct node *temp = start;

		while(temp->next->next != NULL)
			temp = temp->next;

		printf("The data %d has been removed from the Tail of the list.\n", temp->next->data);

        temp->next->prev = NULL;
		temp->next = NULL;

		return;
	}
}

void insPos(int data, int pos)
{
	if((start == NULL) || (pos == 1))
	{
		insHead(data);
		return;
	}
	else if(pos > 1)
	{
	    
		struct node *temp = start;
		
		if(temp->next != NULL)
		{
		    int count = 2;
		
		    while(temp->next != NULL)
		    {
			    if(count == pos)
			    {
				    struct node *ptr = createNode();
				    ptr->data = data;
                    ptr->prev = temp;
				    ptr->next = temp->next;
				    temp->next->prev = ptr;
				    temp->next = ptr;
				    printf("The data %d has been added to the position %d of the list.\n", ptr->data, pos);
				    return;
			    }

			    count = count + 1;
			    temp = temp->next;
		    }

		    insTail(data);
		    return;
    	}
    	else
    	{
    	    insTail(data);
		    return;
    	}
	}
	else
	{
	   printf("Invalid Position! Please try again.\n");
	   return;
	}
}

void delPos(int pos)
{
	if(start == NULL)
	{
		printf("The list is empty!\n");
		return;
	}
	else if(pos < 1)
	{
		printf("Invalid Position! Please try again.\n");
	   return;
	}
	else
	{
		if(pos == 1)
		{
			delHead();
			return;
		}
		else
		{
			struct node *temp = start->next;
			struct node *temp1 = start;
			int count = 2;

			while(temp != NULL)
			{
				if(count == pos)
				{
					temp1->next = temp->next;
					if(temp->next != NULL)
					{
                        temp->next->prev = temp1;
					    temp->next = NULL;
					}
                    temp->prev = NULL;
					printf("The data %d has been deleted from the position %d of the list.\n", temp->data, pos);
					return;
				}
				temp1 = temp;
				temp = temp->next;
				count = count + 1;
			}

			if(count-1 < pos)
			{
				printf("No such position exist.\n");
				return;
			}
		}
	}
}

void search(int element)
{
	if(start == NULL)
	{
		printf("The list is empty!\n");
		return;
	}
	else
	{
		struct node *temp = start;
		int pos = 1;

		while(temp != NULL)
		{
			if(temp->data == element)
			{
				printf("The data %d is present in the list at position %d.\n", temp->data, pos);
				return;
			}

			pos = pos + 1;
			temp = temp->next;
		}

		printf("The data %d is not present in the list.\n", element);
		return;
	}
}

void traverse()
{
	if(start == NULL)
	{
		printf("The list is empty!\n");
		return;
	}
	else
	{
		struct node *temp = start;

		printf("The nodes in the list are:\n");
		while(temp != NULL)
		{
			printf("%d->",temp->data);
			temp = temp->next;
		}
		printf("X\n");
	}
}

void main()
{
	int option, data, pos;
	do
	{	
		printf("1. Insert At Head\n2. Insert At Position\n3. Insert At Tail\n4. Delete At Head\n5. Delete At Position\n6. Delete At Tail\n7. Search\n8. Traverse\n9. Exit\n");
		printf("Enter the Doubly Linked List operation that you would like to perform : ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
					printf("\nEnter the data to be inserted at the head : ");
					scanf("%d", &data);
					insHead(data);
					break;
			case 2:
					printf("Enter the position to which the data needs to be inserted : ");
					scanf("%d", &pos);
					printf("\nEnter the data to be inserted at the position %d : ", pos);
					scanf("%d", &data);
					insPos(data, pos);
					break;
			case 3:
					printf("\nEnter the data to be inserted at the tail : ");
					scanf("%d", &data);
					insTail(data);
					break;
			case 4:
					delHead();
					break;
			case 5:
					printf("Enter the position from which the data needs to be deleted : ");
					scanf("%d", &pos);
					delPos(pos);
					break;
			case 6:
					delTail();
					break;
			case 7:
					printf("Enter the data to be serached : ");
					scanf("%d", &data);
					search(data);
					break;
			case 8:
					traverse();
					break;
			case 9:
					break;
			default:
					printf("\nInvalid data. Please try again.\n");
					break;
		}
	}
	while(option!=9);
	printf("\nThe program has been terminated!...");
}
