#include <stdio.h>

struct dist
{
	int inch;
	int feet; 
};

void main()
{
	struct dist v1;
	struct dist v2;
	
	int sum_feet, sum_inch; 
	
	printf("Enter the inch and feet of 1st item : ");
	scanf("%d %d", &v1.feet, &v1.inch);
	
	printf("Enter the inch and feet of 2nd item : ");
	scanf("%d %d", &v2.feet, &v2.inch);
	
	sum_inch = v1.inch+v2.inch;
	sum_feet = v1.feet+v2.feet;
	
	if(sum_inch >= 12)
	{
		sum_feet = sum_feet + (sum_inch / 12);
		sum_inch = sum_inch % 12;
	}
	
	printf("\nThe sum of %d feet %d inch and %d feet %d inch is %d feet %d inch.", v1.feet, v1.inch, v2.feet, v2.inch, sum_feet, sum_inch);
}
