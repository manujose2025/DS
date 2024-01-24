#include <stdio.h>

void bubble(int arr[], int n)
{
	int i, j, temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(arr[j] > arr[j+1])
    			{
                		temp = arr[j];
               			arr[j] = arr[j+1];
                		arr[j+1] = temp;
            		}
		}
	}
	printf("The bubble sorted array is : ");
	for(i=0;i<n;i++)
	{	
		printf("%d\t", arr[i]);
	}
}

void selection(int arr[], int n)
{
    int i, j, temp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
               	arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    	printf("The selection sorted array is : ");
	for(i=0;i<n;i++)
	{	
		printf("%d\t", arr[i]);
	}
    
}

void insertion(int arr[], int n)
{
    int i, j, temp;
    for(i=0;i<n-1;i++)
    {
        if(arr[i] > arr[i+1])
        {
                temp = arr[i];
               	arr[i] = arr[i+1];
                arr[i+1] = temp;
        }
	j=i;
	while((arr[j] < arr[j-1]) && j>0)
	{
		temp = arr[j];
               	arr[j] = arr[j-1];
                arr[j-1] = temp;
		j--;
	}
    }
    	printf("The insertion sorted array is : ");
	for(i=0;i<n;i++)
	{	
		printf("%d\t", arr[i]);
	}
    
}

void main()
{
	int arr[50], option, n, i;
	
	printf("Enter the size of the array : ");
	scanf("%d", &n);
	
	printf("Enter the array : ");
	for(i=0;i<n;i++)
	{	
		scanf("%d", &arr[i]);
	}
	
	printf("The array is : ");
	for(i=0;i<n;i++)
	{	
		printf("%d\t", arr[i]);
	}
	
	while(option!=4)
	{
		printf("\nEnter your choice:\n1.Bubble Sort\t2.Selection Sort\t3.Insertion Sort.\t4Exit\n");
		scanf("%d", &option);
		
		switch(option)
		{
			case 1:				
				bubble(arr, n);
				
				break;
			case 2:
				selection(arr, n);
				
				break;
				
			case 3:
				insertion(arr, n);
				
				break;
			
			case 4:
				break;
				
			default:
				printf("\nInvalid option!");
		}
	}
}
