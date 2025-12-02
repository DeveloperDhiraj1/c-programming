#include <stdio.h>
#define MAX 10
int main()
{
int n, i, a, low, high, mid;

/*printf("Enter the number of elements:  ");
scanf("%d", &n);*/
int array[MAX];
printf("Enter the elements in a sorted manner: \n");
for(i=0; i<MAX; i++)
    scanf("%d", &array[i]);
printf("Enter the value to find:  ");
scanf("%d", &a);
low=0;
high=MAX-1;
mid=(low+high)/2;
while(low<=high && array[mid]!=a)
{
    if(array[mid]<a)
        low=mid+1;
    else
        high=mid-1;
        mid=(low+high)/2;
}


if (array[mid]==a)
    {
    printf("%d found at the location %d." ,a,mid+1);
    }
else
    printf("%d not found any location.", a);
getch();
}