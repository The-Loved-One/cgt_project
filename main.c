#include<stdio.h>
#include<stdlib.h>

int *visited;
int number_of_vertices, number_of_edges;
int *vertices;
int **edges;
int seperable=0;
int **adj_matrix;


void DFS(int v){
    printf("%d ", v+1);
    visited[v] = 1;
    for(int i=1;i<number_of_vertices;i++){
        if(adj_matrix[v][i]==1 && visited[i]==0){
            DFS(i);
        }
    }
}

int main(){
    //getting the vertices
    printf("Enter the number of vertices : ");
    scanf("%d", &number_of_vertices);
    vertices = (int*)malloc(sizeof(int)*number_of_vertices);
    for(int i=0;i<number_of_vertices;i++){
        // printf("Enter the %dth vertix : ", i+1);
        // scanf("%d", &vertices[i]);
        vertices[i] = i+1;
    }
    visited = (int*)malloc(sizeof(int)*number_of_vertices);
    //getting the edges
    printf("\n\nEnter the number of edges : ");
    scanf("%d", &number_of_edges);
    edges = malloc(sizeof(int*)*number_of_edges);
    for(int i=0;i<number_of_edges;i++){
        edges[i] = malloc(sizeof(int)*2);
        printf("Enter the edge : ");
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        v1--;
        v2--;
        if(v1>number_of_vertices || v2>number_of_vertices){
            printf("invalid vertice number detected");
            return 0;
        }
        edges[i][0] = v1;
        edges[i][1] = v2;
    }
    adj_matrix = (int**)malloc(sizeof(int*)*number_of_vertices);
    for(int i=0;i<number_of_vertices;i++){
        adj_matrix[i] = (int*)malloc(sizeof(int)*number_of_vertices);
    }
    for (int i = 0; i < number_of_edges; i++){
        adj_matrix[edges[i][1]][edges[i][0]] = 1;
        adj_matrix[edges[i][0]][edges[i][1]] = 1;
    }
    for (int i = 0; i < number_of_vertices; i++){
        for (int j = 0; j < number_of_vertices; j++){
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    DFS(0);
}
