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
node *searchItem(int key, node *root){
	if(root == NULL){
		return NULL;
	}
    else {
        if(key > root -> data){
			searchItem(key, root -> right);
		}
        else if(key < root -> data){
            searchItem(key, root -> left);
        }
        else{
            return root;
        }
	}
}
node *get_node(){
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
int main(){
    int key;
    char ans;
    node *n,*root;
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
    while(key != 0){
		printf("\n\nEnter an item to search, Enter 0 if you want to Exit\n");
		scanf("%d",&key);
        (searchItem(key, root))?printf("\nFound the item") : printf("\nNot Found");
	}
    return 0;
}
