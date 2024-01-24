#include<stdio.h>
#include<stdlib.h>

int* init(int n)
{
    int i, *arr = malloc(sizeof(n));
    
    for(i = 0; i < n; i++)
        arr[i] = i;
   
    display(arr, n);
        
    return arr; 
}

void unionD(int *ary, int n, int sub1, int sub2)
{
    int i, temp = ary[sub1];
    
    for(i = 0; i < n; i++)
    {
        if(ary[i] == temp)
            ary[i] = ary[sub2];
    }
    
    display(ary, n);
}

void display(int *ary, int n)
{
    int i;
    
    printf("Subset : ");
                    
    for(i = 0; i < n; i++)
        printf("%d\t", ary[i]);
    
    printf("\n");
                    
    printf("Index  : ");

    for(i = 0; i < n; i++)
        printf("%d\t", i);
}

void main()
{
    int n, i, choice, sub1, sub2, *arr;
    printf("Starting Program...\n");
    printf("Enter the number of subsets : ");
    scanf("%d", &n);
    printf("Initializing the subset...\n");
    arr = init(n);
    
    do
    {
        printf("\n1. Union(element1, element2) Operation\n2. Find(element1, element2) Operation\n3. Exit\n");
        printf("Enter your choice of operation : ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("Select a subset for connection and a subset to be connected to: ");
                scanf("%d %d", &sub1, &sub2);
                if((sub1 < n) && (sub2 < n)) //&& (sub1 != sub2))
                    unionD(arr, n, sub1, sub2);
                else
                    printf("Invalid subset");
                break;
            case 2:
                printf("Select two subset to check connection between them: ");
                scanf("%d %d", &sub1, &sub2);
                if((sub1 < n) && (sub2 < n)) //&& (sub1 != sub2))
                {
                    if(arr[sub1] == arr[sub2])
                        printf("\nThere is a connection.");
                    else
                        printf("\nThere is no connection.");
                }
                else
                    printf("Invalid subset");
                break;
            case 3:
                break;
            default:
                printf("Invalid option. Please try again!\n");
        }
    }
    while(choice != 3);
    printf("The program has been terminated!...");
}
