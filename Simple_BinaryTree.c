#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct binaryTree{
    int data;
    struct binaryTree *left;
    struct binaryTree *right;
}node;
void insert(node *root, node *n){
    char ch;
    printf("\nWhere to insert left/right of %d:\n",root->data);
    ch=getch();
    if(ch=='R'||ch=='r'){
        if(root->right==NULL){
            root->right=n;
        }
        else
            insert(root->right,n);
    }
    else{
        if(root->left==NULL){
            root->left=n;
        }
        else{
            insert(root->left,n);
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
void inTrav(node *root){
	if(root -> left != NULL){
		inTrav(root -> left);
	}
	printf(" %d ", root -> data);
	if( root -> right != NULL){
		inTrav(root -> right);
	}
}
void preTrav(node *root){
	printf(" %d ", root -> data);
	if(root -> left != NULL){
		preTrav(root -> left);
	}
	if(root -> right != NULL){
		preTrav(root -> right);
	}
}
void postTrav(node *root){
	if(root -> left != NULL){
		postTrav(root -> left);
	}
	if(root -> right != NULL){
		postTrav(root -> right);
	}
	printf(" %d ", root -> data);
}
int main(){
    int trav;
    char ans;
    node *n,*root;
    root=NULL;
    printf("\nProgram for implementing a simple binary tree");
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
    printf("\nTraverse Tree?");
	printf("\n1.In-order\n2.Pre-order\n3.Post-order\n");
	scanf("%d",&trav);
	printf("\n");
	if(trav == 1){
		inTrav(root);
	}
	else if(trav == 2){
		preTrav(root);
	}
	else if (trav == 3){
		postTrav(root);
	}
    return 0;
}
