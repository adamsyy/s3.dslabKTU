#include<stdio.h>
int main(void)
{
    int array[5], i, j, temp,n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter %d numbers : ",n);
    for (i = 0; i < n; i++)
    {
        scanf("%d",&array[i]);
    }
    for(i = 0; i < (n -1); i++)
    {
        for (j=(i + 1); j < n; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    printf("Sorted array is : ");
    for (i = 0; i < n; i++)
    {
        printf(" %d ",array[i]);
    }
    return 0;
}