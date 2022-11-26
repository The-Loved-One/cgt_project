#include<stdio.h>
#include<stdlib.h>

int *visited;
int number_of_vertices, number_of_edges;
int *vertices;
int **edges;
int seperable=0;
int **adj_matrix;


void DFS(int v){
    visited[v] = 1;
    // printf("%d ", v+1);
    for(int i=1;i<number_of_vertices;i++){
        if(adj_matrix[v][i]==1 && visited[i]==0){
            DFS(i);
        }
    }
}

int main(){

    // getting the vertices
    printf("Enter the number of vertices : ");
    scanf("%d", &number_of_vertices);
    vertices = (int*)malloc(sizeof(int)*number_of_vertices);
    for(int i=0;i<number_of_vertices;i++){
        vertices[i] = i+1;
    }
    visited = (int*)malloc(sizeof(int)*number_of_vertices);

    // getting the edges
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
        // returning 0 if invalid vertex number is given
        if(v1>number_of_vertices || v2>number_of_vertices){
            printf("invalid vertice number detected");
            return 0;
        }
        edges[i][0] = v1;
        edges[i][1] = v2;
    }

    // creating adjacency matrix
    adj_matrix = (int**)malloc(sizeof(int*)*number_of_vertices);
    for(int i=0;i<number_of_vertices;i++){
        adj_matrix[i] = (int*)malloc(sizeof(int)*number_of_vertices);
    }
    // updating value in adjacency matrix
    for (int i = 0; i < number_of_edges; i++){
        adj_matrix[edges[i][1]][edges[i][0]] = 1;
        adj_matrix[edges[i][0]][edges[i][1]] = 1;
    }
    // printing the adjacency matrix
    printf("\nADJACENCY MATRIX\n");
    for (int i = 0; i < number_of_vertices; i++){
        for (int j = 0; j < number_of_vertices; j++){
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }


    // using DFS and checking connectivity
    int *changed = malloc(sizeof(int)*number_of_vertices);
    for (int i = 0; i < number_of_vertices; i++){
        for (int j = 0; j < number_of_vertices; j++){
            if (adj_matrix[i][j]==1){
                changed[j] = 1;
            }
            adj_matrix[i][j] = 0;
            adj_matrix[j][i] = 0;
        }
        visited[i] = 1;
        if(i==0){
            printf("\n");
            DFS(1);
        }else{
            printf("\n");
            DFS(0);
        }
        for (int j = 0; j < number_of_vertices; j++){
            // printf("\nvisited[%d] = %d", j, visited[j]);
            if (visited[j] == 0){
                seperable = 1;
                printf("\n%d is a cut vertex", j);
                break;
            }
        }
        for (int j = 0; j < number_of_vertices; j++){
            visited[j] = 0;
            if (changed[j] == 1){
                adj_matrix[i][j] = 1;
                adj_matrix[j][i] = 1;
            }
        }
    }
    if (seperable){
        printf("\n\nit is a seperable graph\n");
    }else{
        printf("\n\nit is a non-seperable graph\n");
    }
}
