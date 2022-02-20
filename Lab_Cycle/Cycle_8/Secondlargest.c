#include <stdio.h>

void bubble(int a[], int n) // function to implement

{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void main()
{
    int i, j, temp;
    int a[5] = {10, 35, 32, 13, 26};
    int n = sizeof(a) / sizeof(a[0]);
  
    bubble(a, n);
   printf("second largest element is: %d",a[3]);
}