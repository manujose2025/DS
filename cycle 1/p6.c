#include <stdio.h>
#include <string.h>

void main()
{
	char string1[100], string2[100];
	int option;
	
	printf("\nEnter the 1st string : ");
	scanf("%s", string1);
		
	while(option!=4)
	{
		printf("\nChoose your option:\n1.search\t2.Concatenate\t3.Substring\t4.Exit\n");
		scanf("%d", &option);
		
		switch(option)
		{
			case 1:
				printf("\nEnter the string to be searched : ");
				scanf("%s", string2);
				
				if(strstr(string1, string2)!=NULL)
					printf("\n%s exist in %s", string2, string1);
				else
					printf("\n%s does not exist in %s", string2, string1);
					
				break;
				
			case 2:
				printf("\nEnter the string to concatenate : ");
				scanf("%s", string2);
				
				printf("\n%s concatenated with %s becomes ", string1, string2);
				printf("%s", strcat(string1, string2));
				
				break;
				
			case 3:
				printf("\nEnter the sub-string to be searched : ");
				scanf("%s", string2);
				
				if(strstr(string1, string2)!=NULL)
					printf("\n%s is a sub-string of %s", string2, string1);
				else
					printf("\n%s is not a sub-string of %s", string2, string1);
					
				break;
				
			case 4:
				break;
				
			default:
				printf("\nInvalid option!");
		}
	}
}
