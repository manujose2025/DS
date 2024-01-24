#include<stdio.h>
#include<stdlib.h>

int* setUnion(int *set1, int size1, int *set2, int size2)
{
    int i, j, k, flag;
    int  *setU = malloc(sizeof(size1+size2));
    
    for(i = 0; i < size1+size2; i++)
        setU[i] = NULL;
    
    for(i = 0; i < size1; i++)
        setU[i] = set1[i];
     
    for(j = 0; j < size2; j++)
    {
        flag = 0;
        for(k = 0; k < size1; k++)
        {
            if(setU[k] == set2[j])
            {
                flag = 1;
                break;
            }
        }
         
        if(flag == 0)
        {
            setU[i] = set2[j];
            i += 1;
        }
    }
    
    return setU;
}

int* setInter(int *set1, int size1, int *set2, int size2)
{
    int i, j, k = 0, flag;
    int *setInt = malloc(sizeof(size1));
    
    for(j = 0; j < size2; j++)
    {
        flag = 0;
        for(i = 0; i < size1; i++)
        {
            if(set1[i] == set2[j])
            {
                flag = 1;
                break;
            }
        }
         
        if(flag == 1)
        {
            setInt[k] = set2[j];
            k += 1;
        }
    }
    
    return setInt;
}

int* setDiff(int *set1, int size1, int *set2, int size2)
{
    int i, j, k = 0, flag;
    int *setD = malloc(sizeof(size1));    
    for(i = 0; i < size1; i++)
    {
        flag = 0;
        for(j = 0; j < size2; j++)
        {
            if(set1[i] == set2[j])
            {
                flag = 1;
                break;
            }
        }
         
        if(flag == 0)
        {
            setD[k] = set1[i];
            k += 1;
        }
    }
    
    return setD;
}

int* createSet(int size)
{
    int i;
    int *arr = malloc(sizeof(size));
    
    for(i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    
    //ptr = arr;
        
    return arr;
}

void displaySet(int *arr)
{
    int i=0;

    for(i = 0; arr[i] != '\0'; i++)
    {
        printf("%d\t", arr[i]);
    }
    
    printf("\n");
}

void main()
{
    int size1, size2, choice=0;
    int *set, *set1, *set2;
    
    printf("Enter the size of the 1st set : ");
    scanf("%d", &size1);
    
    set1 = createSet(size1);
    
    printf("Enter the size of the 2nd set : ");
    scanf("%d", &size2);
    
    set2 = createSet(size2);
    
    do
    {
        printf("\n1. Union Operation\n2. Intersection Operation\n3. Difference Operation\n4. Exit\n");
        printf("Enter your choice of operation : ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                set = setUnion(set1, size1, set2, size2);
                displaySet(set);
                break;
            case 2:
                set = setInter(set1, size1, set2, size2);
                displaySet(set);
                break;
            case 3:
                set = setDiff(set1, size1, set2, size2);
                displaySet(set);
                break;
            case 4:
                break;
            default:
                printf("Invalid option. Please try again!\n");
        }
    }
    while(choice != 4);
    printf("The program has been terminated!...");
}
