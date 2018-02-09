#include<stdio.h>
#include<conio.h>
void main(){
    int a[25],start,end,mid,search,n,i;
    char ch='y';
    printf("\nEnter number of array elements\n");
    scanf("%d",&n);
    printf("\nEnter array\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    do{
        printf("\nEnter array elements to search\n");
        scanf("%d",&search);
        start=0;
        end=n-1;
        mid=(start+end)/2;
        while(search!=a[mid]&&start<=end){
            if(search>a[mid]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
            mid=(start+end)/2;
        }
        if(search==a[mid]){
            printf("\n%d element found at %d",search,mid+1);
        }
        if(start>end){
            printf("\n%d not found",search);
        }
        printf("\nDo you want to continue Y/N\n");
        scanf(" %c",&ch);
    }while(ch=='y'||ch=='Y');
}
