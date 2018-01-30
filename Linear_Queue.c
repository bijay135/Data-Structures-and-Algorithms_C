#include <stdio.h>
#include <conio.h>
int a[5];
int front = 0;
int rear = -1;
int i;
void enQueue(int item){
    rear++;
    a[rear]=item;
}
void deQueue(){
    int dItem = a[front];
    rear--;
    for(i=0;i<=rear;i++){
        a[i]=a[i+1];
    }
    printf("\nDeleted Item=%d",dItem);
}
void display(){
    for(i=0;i<=rear;i++){
        printf("\n%d",a[i]);
    }
}
void main(){
    int choice=1;
    while(choice!=0){
        printf("\nMain Menu");
        printf("\n1.Insert 2.Delete 3.Display 0.Exit");
        printf("\nEnter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                exit(0);
            break;
            case 1:
                if(rear<5-1){
                    printf("\nEnter your number\n");
                    int n;
                    scanf("%d",&n);
                    enQueue(n);
                    printf("\n");
                    display();
                }
                else
                        printf("\nQueue Full");
                break;
            case 2:
                if(rear>front-1){
                    deQueue();
                    printf("\n");
                    display();
                }
                else
                    printf("\nQueue Empty");
            break;
            case 3:
                display();
            break;
        }
    }
}
