#include<stdio.h>
#include<conio.h>
#define maxSize 50
void exchange(int a[],int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(a[i]>a[j]){
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
}
void main(){
    int a[maxSize],i,n;
    printf("\nEnter number of elements\n");
    scanf("%d",&n);
    printf("\nEnter array elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\nUnsorted array = \n");
    for(i=0;i<n;i++){
        printf("%5d",a[i]);
    }
    exchange(a,n);
    printf("\nSorted array = \n");
    for(i=0;i<n;i++){
        printf("%5d",a[i]);
    }
}
