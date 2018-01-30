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
void main(){
    printf("\nEnter your value");
    char *input;
    scanf("%s",&*input);
    for(i=0;i<input.length();i++){
        push(input.charAt(i));
    }
    String reverse = "";
    while(isEmpty()){
        reverse = reverse+T.pop();
    }
    if(input.equals(reverse))
        printf("\nPalindrome");
    else
        printf("\nNot Palindrome");
}
