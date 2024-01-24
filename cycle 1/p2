#include <stdio.h>

void linear(char str1[], char src)
{
	int i=0, count=0, flag=0;
	while(str1[i]!='\0')
	{
	    i++;
	    count++;
	    
	}
	for(i=0;i<count;i++)
	{
		if(str1[i] == src)
		{
    			printf("\n%c exists in %s at location %d", src, str1, i+1);
			flag=1;
		}
	}
	
	if(flag==0)
	    printf("\n%c does not exists in %s", src, str1);
}

void binary(char str1[], char src)
{
    int i=0, j, count=0, flag=0;
    char temp;
	while(str1[i]!='\0')
	{
	    i++;
	    count++;
	    
	}
    for(i=0;i<count-1;i++)
    {
        for(j=i+1;j<count;j++)
        {
            if(((int)(str1[i])) > ((int)(str1[j])))
            {
                temp = str1[i];
                str1[i] = str1[j];
                str1[j] = temp;
            }
        }
    }
    printf("%s", str1);
    
    if(((int)(str1[(count / 2)-1])) > ((int)(src)))
    {
        for(i=0;i<(count/2)-1;i++)
        {
            if(((int)(str1[i]))==((int)(src)))
            {
                printf("\n%c exists in %s at location %d", src, str1, i+1);
                flag = 1;
            }
        }
    }
    else if(((int)(str1[(count / 2)-1])) < ((int)(src)))
    {
        for(i=(count/2)-1;i<count;i++)
        {
            if(((int)(str1[i]))==((int)(src)))
            {
                printf("\n%c exists in %s at location %d", src, str1, i+1);
                flag = 1;
            }
        }
    }
    else
    {
        printf("\n%c exists in %s at location %d", src, str1, (count / 2)+1);
        flag = 1;
    }
    
    if(flag==0)
	    printf("\n%c does not exists in %s", src, str1);
    
}


void main()
{
	char str1[50];
	char src;
	int option;
	
	printf("Enter the string : ");
	scanf("%s", str1);
	
	while(option!=3)
	{
		printf("\nEnter your choice:\n1.Linear Serach\t2.Binary Search\t3.Exit\n");
		scanf("%d", &option);
		
		switch(option)
		{
			case 1:
				printf("\nEnter the character to be searched via linear search : ");
				scanf(" %c", &src);
				
				linear(str1, src);
				
				break;
			case 2:
				printf("\nEnter the character to be searched via linear search : ");
				scanf(" %c", &src);
				
				binary(str1, src);
				
				break;
				
			case 3:
				break;
				
			default:
				printf("\nInvalid option!");
		}
	}
}
