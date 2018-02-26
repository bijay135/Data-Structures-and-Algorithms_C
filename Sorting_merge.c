#include <stdio.h>
#define SIZE 20
int a[SIZE];
void mergeArray(int low, int mid, int high){
    int temp[SIZE];
    int i = low;
    int j = mid+1;
    int k = low;
    while((i<=mid)&&(j<=high)){
        if(a[i]<=a[j]){
            temp[k++]=a[i++];
        }
        else{
            temp[k++] = a[j++];
        }
    }
    while(i<=mid){
        temp[k++] = a[i++];
    }
    while(j<=high){
            temp[k++] = a[j++];
    }
    for(i=low;i<=high;i++){
        a[i] = temp[i];
    }
}
void merge_sort(int low, int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        merge_sort(low,mid);
        merge_sort(mid+1,high);
        mergeArray(low,mid,high);
    }
}
int main(){
    int n,i,low,high;
    printf("\nEnter the size of array\n");
    scanf("%d",&n);
    printf("\nEnter elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\n\nUnsorted array is\n");
    for(i=0;i<n;i++){
        printf("%3d",a[i]);
    }
    low = 0;
    high = n-1;
    merge_sort(low,high);
    printf("\n\nSorted Array is\n");
    for(i=0;i<n;i++){
        printf("%3d",a[i]);
    }
    return 0;
}

