// belmannford algorithm in c
#include<stdio.h>
#include <stdbool.h> 
int graph[10][10],edges[10][10],dist[10],parent[10];
void bellmanFord(int ,int ,int );
int main(){
    int n,k=0;
    printf("Enter no of vertices : ");
    scanf("%d",&n);
    printf("Enter the graph in Matrix form : \n");
    for(int i= 0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
            if(graph[i][j]!=0){
                edges[k][0]=i;
                edges[k++][1]=j;
            }
        }
    }
    int src;
    printf("Enter Source value : ");
    scanf("%d",&src);
    bellmanFord(n,k,src);
    return 0;
}
void bellmanFord(int V,int E,int src){
    for(int i=0;i<V;i++){
        dist[i]=1e9;
        parent[i]=-1;
    }
    dist[src-1]=0;
    // checking for every nodes
    for(int i=0;i<V-1;i++){
        for(int j=0;j<E;j++){
            int u = edges[j][0];
            int v = edges[j][1];
            printf("\n{{ %d, %d }}\n",dist[u],graph[u][v]);
            if(dist[v]>(dist[u]+graph[u][v])){
                 dist[v] = dist[u]+graph[u][v];
                 parent[v]=u;
                 
            }
        }
        for(int i=0;i<V;i++) printf("Vertex %d -> cost = %d, parent = %d\n",i+1,dist[i],parent[i]+1); 
            printf("\n\n (%d) step ^ ----------------------\n",i+1);
    }
    bool flag = false;
    for(int j=0;j<E;j++){
        int u = edges[j][0];
        int v = edges[j][1];
        if(dist[v]>(dist[u]+graph[u][v])) flag=true;
    }
    if(!flag){
        for(int i=0;i<V;i++) printf("Vertex %d -> cost = %d, parent = %d\n",i+1,dist[i],parent[i]+1); 
        printf("\nThere is no negative cycle \n");
        return;
    }
    printf("\nThere present negative cycle \n");
}
