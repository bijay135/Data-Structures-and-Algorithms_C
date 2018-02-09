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
void inTrav(node *root){
	if(root -> left != NULL){
		inTrav(root -> left);
	}
	printf(" %d ", root -> data);
	if( root -> right != NULL){
		inTrav(root -> right);
	}
}
node *deleteV(int value, node *tree){
    node *temp;
    if(tree==NULL){
        return NULL;
    }
    else if(value<tree->data){
        tree->left=deleteV(value,tree->left);
    }
    else if(value>tree->data){
        tree->right=deleteV(value,tree->right);
    }
    else if(tree->left!=NULL&&tree->right!=NULL){
        temp=findMin(tree->right);
        tree->data=temp->data;
        tree->right=deleteV(tree->data,tree->right);
    }
    else
    {
        temp= tree;
        if(tree->left=NULL){
        tree=tree->right;
        }
        else if(tree->right=NULL){
            tree=tree->left;
        }
        free(temp);
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
    int value=1;
    char ans;
    node *n,*root,*temp1;
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
    do{
        printf("\n");
        inTrav(root);
        printf("\nWhich value do you want to delete, press 0 to exit\n");
        scanf("%d",&value);
        if(value==0)
            break;
        deleteV(value,root);
	}while(value!=0);
    return 0;
}
