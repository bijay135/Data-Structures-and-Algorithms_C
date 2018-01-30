#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
int top = -1;
int size = 5;
int a[5];
int i;
bool isFull(){
    return (top==size-1?true:false);
}
bool isEmpty(){
    return (top==-1?true:false);
}
void push(int item){
    top++;
    a[top]=item;
}
void pop(){
    int pItem = a[top];
    top--;
    printf("\nPopped Item=%d",pItem);
}
void display(){
    for(i=top;i>=0;i--){
        printf("\n%d",a[i]);
    }
}
void main(){
    int choice=1;
    while(choice!=0){
        printf("\n\nMain Menu");
        printf("\n 1. push \n 2.pop \n 3.IsFull \n 4.IsEmpty \n 0.Exit");
        printf("\nEnter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                exit(0);
            break;
            case 1:
                if(!isFull()){
                    printf("\nEnter your number\n");
                    int n;
                    scanf("%d",&n);
                    push(n);
                    printf("\n");
                    display();
                }
                else
                        printf("\nStack Overflow");
                break;
            case 2:
                if(!isEmpty()){
                        pop();
                    printf("\n");
                    display();
                }
                else
                    printf("\nStack Underflow");
                break;
            case 3:
                if(isFull())
                    printf("\nFull");
                else
                    printf("\nNot Full");
            break;
            case 4:
                if(isEmpty())
                    printf("\nEmpty");
                else
                    printf("\nNot Empty");
            break;
        }
    }
}
