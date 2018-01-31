#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct binaryTree{
    int data;
    struct binaryTree *left;
    struct binaryTree *right;
}node;
void insert(node *root, node *n){
    if(n -> data > root -> data){
		if(root -> right == NULL){
			root -> right = n;
		} else {
			insert(root -> right, n);
		}
	} else {
		if(root -> left == NULL){
			root -> left = n;
		} else {
			insert(root -> left, n);
		}
	}
}
node *findMin(node *tree){
    if(tree!=NULL){
        while(tree->left!=NULL){
            tree=tree->left;
        }
    }
    return tree;
}
node *findMax(node *tree){
    if(tree!=NULL){
        while(tree->right!=NULL){
            tree=tree->right;
        }
    }
    return tree;
}
node *get_node(){
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
int main(){
    int choice;
    char ans;
    node *n,*root,*value;
    root=NULL;
    printf("\nProgram for implementing a Binary Search Tree");
    printf("\n***********************************************");
    do{
        n=get_node();
        printf("\nEnter the element\n");
        scanf("%d",&n->data);
        if(root==NULL)
            root=n;
        else
            insert(root,n);
        printf("\nDo you want to enter more elements?(y/n)\n");
        ans=getch();
    }while(ans=='y'||ans=='Y');
    while(choice != 0){
        printf("\n1.Find Min Value");
        printf("\n2.Find Max Value");
        printf("\n0.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                exit(1);
            break;
            case 1:
                value=findMin(root);
                printf("\nThe minimum value is:%d\n",value->data);
            break;
            case 2:
                value=findMax(root);
                printf("\nThe maximum value is:%d\n",value->data);
            break;
        }
	}
    return 0;
}
