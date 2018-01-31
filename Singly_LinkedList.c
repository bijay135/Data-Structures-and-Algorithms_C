#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct node{
    int data;
    struct node *next;
}Node;
Node *list=NULL;
int size=0;
int getsize(){
    return size;
}
void insert_at_start(int x){
    Node *n;
    n=(Node*)malloc(sizeof(Node));
    size++;
    if(list==NULL){
        list=n;
        list->data = x;
        list->next = NULL;
    }
    else{
        n->data=x;
        n->next=list;
        list=n;
        printf("\nInserted at start successfully!!!\n");
    }
}
void insert_at_end(int x){
    Node *n,*temp;
    n=(Node*)malloc(sizeof(Node));
    size++;
    if(list==NULL){
        list=n;
        list->data=x;
        list->next=NULL;
    }
    else{
        temp=list;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        n->data=x;
        n->next=NULL;
        temp->next=n;
        printf("\nInserted at end successfully\n");
    }
}
void insert_at_pos(int x){
    int pos;
    Node *temp,*y,*n;
    n = (Node*)malloc(sizeof(Node));
    printf("\nEnter position!\n");
    scanf("%d",&pos);
    n->data=x;
    temp=list;
    pos=pos-1;
    int i;
    for(i=1;i<size;i++){
        if(i==pos){
            y=temp->next;
            temp->next=n;
            n->next=y;
            break;
        }
        temp=temp->next;
    }
    size++;
    printf("\nData Inserted at position %d successfully\n",(pos+1));
}
void insert_after(int afterData,int x){
    Node *n,*temp,*y;
    int z;
    n = (Node*)malloc(sizeof(Node));
    temp=list;
    while(temp->data!=afterData){
        temp=temp->next;
    }
    z=temp->data;
    y = temp->next;
    n->data = x;
    temp->next = n;
    n->next = y;
    size++;
    printf("\nSuccessfully inserted data after %d after data %d\n",z,afterData);
}
void delete_at_start(){
    Node *y;
    int z;
    if(list == NULL){
        printf("\nLinked list is already empty\n");
        return;
    }
    z= list->data;
    y= list->next;
    free(list);
    list = y;
    size--;
    printf("\n%d deleted from beginning successfully\n",z);
}
void delete_at_end(){
    Node *temp,*y;
    int z;
    if(list==NULL){
        printf("\nLinked list is already empty\n");
        return;
    }
    temp = list;
    while(temp->next!=NULL){
        y = temp;
        temp = temp->next;
    }
    z = temp->data;
    y->next=NULL;
    free(temp);
    size--;
    printf("\n%d deleted from end successfully\n",z);
}
void delete_at_pos(){
    Node *temp,*y;
    int pos;
    int z,i;
    if(list == NULL){
        printf("\nNo node to delete!!!");
    }
    else{
        printf("\nEnter the position you want to delete\n");
        scanf("%d",&pos);
        temp = list;
        if(pos==1){
            list = temp->next;
            printf("\nElement Deleted!!!");
        }
        else{
            if(pos>0 && pos<size){
                temp = list;
                for(i=1;i<pos;i++){
                    y=temp;
                    temp=temp->next;
                    z=temp->data;
                }
                y->next=temp->next;
            }
            else{
                printf("\nPosition of of Range!!!");
            }
            free(temp);
            size--;
            printf("\nElement Deleted!!! = %d from position %d\n",z,pos);
        }
    }
}
void delete_data(int x){
    Node *temp,*y;
    int z;
    temp=list;
    while(temp->data!=x){
        y=temp;
        temp=temp->next;
    }
    z= temp->data;
    y->next = temp->next;
    free(temp);
    size--;
    printf("\nDeleted data = %d\n",z);
}
void delete_after(int afterData){
    Node *temp,*y;
    int z;
    temp = list;
    while(temp->data!=afterData){
        temp=temp->next;
    }
    z = temp->data;
    y = temp;
    temp = temp->next;
    y->next = temp->next;
    free(temp);
    size--;
    printf("\nDeleted item = %d after data %d\n",z,afterData);
}
void display(){
    struct node *temp;
    temp = list;
    while(temp->next!=NULL){
        printf("\%d-->",temp->data);
        temp=temp->next;
    }
    printf("%d\n\n",temp->data);
}
void main(){
    int data,afterdata,choice=1;
    while(choice!=0){
        printf("\nLinked List");
        printf("\n1.Insert at start\n2.Insert at end\n3.Insert at position\n4.Insert after data");
        printf("\n5.Delete at start\n6.Delete at end\n7.Delete at position\n8.Delete entered data\n9.Delete after entered data");
        printf("\n10.Size of Linked list\n11.Display\n0.Exit");
        printf("\nEnter your choice!!!\n");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                exit(0);
            case 1:
                printf("\nEnter data to insert at beginning\n");
                scanf("%d",&data);
                insert_at_start(data);
                display();
            break;
            case 2:
                printf("\nEnter data to insert at last\n");
                scanf("%d",&data);
                insert_at_end(data);
                display();
            break;
            case 3:
                printf("\nEnter data\n");
                scanf("%d",&data);
                insert_at_pos(data);
                display();
            break;
            case 4:
                printf("\nAfter which data you want to insert new data?\n");
                scanf("%d",&afterdata);
                printf("\nEnter new data\n");
                scanf("%d",&data);
                insert_after(afterdata,data);
                display();
            break;
            case 5:
                delete_at_start();
                display();
            break;
            case 6:
                delete_at_end();
                display();
            break;
            case 7:
                delete_at_pos();
                display();
            break;
            case 8:
                printf("\nwhich data do you want to delete?\n");
                scanf("%d",&data);
                delete_data(data);
                display();
            break;
            case 9:
                printf("\nAfter which data do you want deletion\n");
                scanf("%d",&data);
                delete_after(data);
                display();
            break;
            case 10:
                printf("\n\nSize of linked list = %d\n\n",getsize());
            break;
            case 11:
                display();
        }
    }
}
