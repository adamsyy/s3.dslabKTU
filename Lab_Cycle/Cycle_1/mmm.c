
int main(void){
    int n,a[20],i,sum=0,mid,j;
    float mean,median,mode;
    printf("Enter the size: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        sum+=a[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    mean=sum/n;
    if(n%2==0){
        median=a[n/2]+a[n/2+1];
    }
    else if(n%2==1){
        median=a[n/2];
    }
    mode=(3*median)-(2*mean);

    printf("Mean : %f\n",mean);
    printf("Median: %f\n",median);
    printf("Mode: %f",mode);
    return 0;


}