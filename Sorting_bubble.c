#include<stdio.h>
#include<conio.h>
#define maxSize 50
void bubble(int a[],int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
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
    bubble(a,n);
    printf("\nSorted array = \n");
    for(i=0;i<n;i++){
        printf("%5d",a[i]);
    }
}
