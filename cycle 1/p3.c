#include <stdio.h>


void add(int m, int n, int p, int q)
{
	int i, j, a[100][100], b[100][100];
	if((m==p)&&(n==q))
	{
		printf("\nEnter the values of the 1st array: \n");
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		
		printf("\nEnter the values of the 2nd array: \n");
		for(i=0;i<p;i++)
		{
			for(j=0;j<q;j++)
			{
				scanf("%d", &b[i][j]);
			}
		}
	
		printf("The added matrix is...\n");
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%d\t", a[i][j] + b[i][j]);
			}
			printf("\n");
		}
	}
	else
		printf("matrix addition not possible as rows and columns are different.");
	return;
}

void multi(int m, int n, int p, int q)
{	
	int i, j, k, a[100][100], b[100][100], multi[100][100];
	if(n==p)
	{
		printf("\nEnter the values of the 1st array: \n");
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		
		printf("\nEnter the values of the 2nd array: \n");
		for(i=0;i<p;i++)
		{
			for(j=0;j<q;j++)
			{
				scanf("%d", &b[i][j]);
			}
		}

		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<p;k++)
				{
					multi[i][j] += a[i][k] * b[k][j];
				}
			}
		}
		
		printf("\nThe multiplied matrix is: \n");
		
		for(i=0;i<m;i++)
		{
			for(j=0;j<q;j++)
			{
				printf("%d\t", multi[i][j]);
			}
			printf("\n");
		}
	}
	else
		printf("\nThe column of 1st Matrix and the row of 2nd matrix doesn't match. Please try again!\n");
}

void transpose(int a[100][100], int m, int n)
{
	int i, j, trans[100][100];
	printf("\nThe transpose of the given array is: \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			trans[j][i] = a[i][j];
		}
		printf("\n");	
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d\t", trans[i][j]);
		}
		printf("\n");	
	}
}

void main()
{
	int choice=0, m, n, p, q, i, j, a[100][100];
	
	while(choice!=4)
	{
		printf("\nEnter your choice of matrix operation:\n1.Addition\t2.Multiplication\t3.Transpose\t4.Exit\n");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				{
					printf("\nEnter the number of rows and columns for the 1st matrix to be added: \n");
					scanf("%d %d", &m, &n);
					
					printf("\nEnter the number of rows and columns for the 2nd matrix to be added: \n");
					scanf("%d %d", &p, &q);
					
					add(m, n, p, q);
					break;
				}
			
			case 2:
				{
					printf("\nYou have selected matrix addition.");
					
					printf("\nEnter the number of rows and columns for the 1st matrix to be added: \n");
					scanf("%d %d", &m, &n);
					
					printf("\nEnter the number of rows and columns for the 2nd matrix to be added: \n");
					scanf("%d %d", &p, &q);
					
					multi(m, n, p, q);
					break;
				}
				
			case 3:
				{
					printf("\nEnter the number of rows and columns for the 1st matrix to be added: \n");
					scanf("%d %d", &m, &n);
					
					printf("\nEnter the values of the 1st array: \n");
					for(i=0;i<m;i++)
					{
						for(j=0;j<n;j++)
						{
							scanf("%d", &a[i][j]);
						}
					}
					
					printf("\nThe giver array is: \n");
					for(i=0;i<m;i++)
					{
						for(j=0;j<n;j++)
						{
							printf("%d\t", a[i][j]);
						}
						printf("\n");	
					}
					
					transpose(a, m, n);
					break;
				}
					
			case 4:
				break;
			
			default :
				printf("\nInvalid Operation. Please try again.");
		}
	}
}
