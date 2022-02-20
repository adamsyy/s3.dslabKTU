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
   
int sum=0;
   for(int i=0;i<n;i++){
     sum+=a[i];  
   }
   int mean=sum/n;
    printf("mean is %d",mean);
    //find mode of array
    int freq[101]={};
    for(int i=0;i<n;i++){
        freq[a[i]]++;
    }
    int max=0;
    int mode=0;
    for(int i=0;i<n;i++){
        if(freq[a[i]]>max){
            max=freq[a[i]];
            mode=a[i];
        }
    }
    printf("mode is %d",mode);
    //find median of array
    int median=0;
    if(n%2==0){
        median=(a[n/2]+a[n/2-1])/2;
    }
    else{
        median=a[n/2];
    }
    printf("median is %d",median);
    //find range of array
    int range=a[n-1]-a[0];
    printf("range is %d",range);
    
}