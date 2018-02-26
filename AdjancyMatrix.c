#include<stdio.h>
#include<conio.h>
#define max 20
int adj[max][max];
int n;
int main(){
	int max_edges,i,j,origin,dest;
	char type;
	printf("\nEnter number of nodes on graph\n");
	scanf("%d",&n);
	printf("\nEnter type of graph,directed or undirected (d/u)\n: ");
	scanf(" %c",&type);
    if(type=='u')
		max_edges = n*(n-1)/2;
	else
		max_edges = n*(n-1);
    for(i=1;i<=max_edges;i++){
		printf("\nEnter edge %d (0 0 to quit )\n:",i);
		scanf("%d%d",&origin,&dest);
        if(origin==0 && dest == 0)
            //i--;
            break;
        if(origin>n || dest> n||origin<=0||dest<=0){
            printf("\nInvalid choice!!!!");
            i--;
        }
        else{
            adj[origin][dest] =  1;
            if(type == 'u'){
                adj[dest][origin] = 1;
            }
        }
	}
	printf("\nThe adjacency matrix of graph is\n");
	for(i = 1;i<=n;i++){
		for(j = 1;j<=n;j++)
			printf("%4d",adj[i][j]);
		printf("\n");
	}
	return 0;
}
