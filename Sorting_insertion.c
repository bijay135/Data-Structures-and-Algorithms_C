#include<stdio.h>
#include<conio.h>
#define maxSize 50
void exchange(int a[],int n){
    int i,j,temp,key;
    for(i=0;i<n-1;i++){
        key=a[i+1];
        j=i;
        while(key<a[j]&&j>=0){
            temp=a[j];
            a[j+1]=temp;
            a[j]=key;
            j--;
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
