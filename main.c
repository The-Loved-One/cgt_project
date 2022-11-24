#include<stdio.h>
#include<stdlib.h>


// struct node{
    // int data;
    // struct node *next;
// };
// 
// struct edges{
    // int from, to;
    // struct node *next;
// };
// 
// void check_seperablity(int vertices[], int number_of_vertices, int edges[], int number_of_edges, int removed){
    // int found = 0;
    // number_of_vertices--;
    // for(int i=0;i<number_of_vertices;i++){
        // if (vertices[i] == removed){
            // found=1;
        // }
        // if (found == 1){
            // vertices[i] = vertices[i+1];
        // }
    // }
    // struct node *edges = NULL;
    // for(int i=0;i<number_of_edges;i++){
        // if (edges[i][0]!=removed || edges[i][1]!=removed){
// 
        // }
    // }
// }

int adj_matrix[30][30], visited[30];
int number_of_vertices;

void dfs(int v){
    int i;
    visited[v] = 1;
    for (i = 1; i <= number_of_vertices; i++){
        if (adj_matrix[v][i] && !visited[i]){
            printf("\n %d->%d", v, i);
            dfs(i);
        }
    }
}

//using int main as return can be used to break the flow in case of invalid input
int main(){
    //getting the vertices
    int number_of_edges;
    printf("Enter the number of vertices : ");
    scanf("%d", &number_of_vertices);
    int *vertices = malloc(number_of_vertices*sizeof(int));
    for(int i=0;i<number_of_vertices;i++){
        printf("Enter the %dth vertix : ", i+1);
        scanf("%d", &vertices[i]);
    }

    //getting the edges
    printf("\n\nEnter the number of edges : ");
    scanf("%d", &number_of_edges);
    int **edges = malloc(number_of_edges*sizeof(int*));
    for(int i=0;i<number_of_edges;i++){
        edges[i] = malloc(2*sizeof(int));
    }
    for(int i=0;i<number_of_edges;i++){
        printf("Enter the %dth vertix : ", i+1);
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }
    for(int i=0;i<number_of_edges;i++){
        int value[2] = {0, 0};
        for(int j=0;j<number_of_vertices;j++){
            if(edges[i][0] == vertices[j]){
                value[0] = 1;
            }
            if(edges[i][1] == vertices[j]){
                value[1] = 1;
            }
        }
        if (value[0] == 0 || value[1] == 0){
            // exiting the run if the edges have a vertix that does not exist
            return 0;
        }
    }
    for (int i = 0; i < number_of_edges; i++){
        adj_matrix[edges[i][0]][edges[i][1]] = 1;
        adj_matrix[edges[i][1]][edges[i][0]] = 1;
    }
    /*
    //show all the edges
    for(int i=0;i<number_of_edges;i++){
        printf("\n%dth vertix is : %d-%d", i+1, edges[i][0], edges[i][1]);
    }
    */

    /*
    loop i : vertix
        loop j, k: vertix
            check path from j to k
    */
    dfs(1);
    printf("\n");
    int count = 0;
    for (int i = 1; i <= number_of_vertices; i++) {
        if (visited[i])
            count++;
    }
    if (count == number_of_vertices)
        printf("\n Graph is connected");
    else
        printf("\n Graph is not connected");
    return 0;
}