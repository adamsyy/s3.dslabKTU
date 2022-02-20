#include <stdio.h>

void main(){
    int a[5] = {10,2,4,2,10,6};
    int n = sizeof(a) / sizeof(a[0]);
    int freq[101]={};
for(int i=0;i<n;i++){
    freq[a[i]]++;
}
for(int i=0;i<n;i++){
    if(freq[a[i]]>1){
        printf("%d occurs more than one time",a[i]);
    }
}
//print occurance of each element
for(int i=0;i<n;i++){
    printf("%d occurs %d times",a[i],freq[a[i]]);
}

}