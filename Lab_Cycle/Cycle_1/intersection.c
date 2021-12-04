#include<stdio.h>
#include<string.h>
int main(){
    int n,i,j,k;
    char str[50],str1[50];
    printf("Enter the string: ");
    gets(str);
    n=strlen(str);
    strcpy(str1,str);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(str1[i]==str1[j]){
                for(k=j;k<n;k++){
                    str1[k]=str1[k+1];
                }
                j--;
                n--;
            }
        }
    }//removed the duplicate elements from str1
    for(i=0;i<n;i++){
        char ch=str1[i];
        int sum=0;
        for(j=0;j<n;j++){
            if(ch==str[j]){
                sum++;
            }
        }
        printf("%c - %d  ",ch,sum);
    }
    
    
    
    return 0;
}