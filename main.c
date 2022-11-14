#include<stdio.h>
#include<stdlib.h>


//using int main as return can be used to break the flow in case of invalid input
int main(){
    //getting the vertices
    int i, number_of_vertices, number_of_edges;
    printf("Enter the number of vertices : ");
    scanf("%d", &number_of_vertices);
    int *vertices = malloc(number_of_vertices*sizeof(int));
    for(i=0;i<number_of_vertices;i++){
        printf("Enter the %dth vertix : ", i+1);
        scanf("%d", &vertices[i]);
    }

    //getting the edges
    printf("\n\nEnter the number of edges : ");
    scanf("%d", &number_of_edges);
    int **edges = malloc(number_of_edges*sizeof(int*));
    for(i=0;i<number_of_edges;i++){
        edges[i] = malloc(2*sizeof(int));
    }
    for(i=0;i<number_of_edges;i++){
        printf("Enter the %dth vertix : ", i+1);
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }
    for(i=0;i<number_of_edges;i++){
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
            return 0;
        }
    }
    /*
    //show all the edges
    for(int i=0;i<number_of_edges;i++){
        printf("\n%dth vertix is : %d-%d", i+1, edges[i][0], edges[i][1]);
    }
    */
   for(int v=0;v<number_of_vertices;v++){
        for(int e=0;e<number_of_edges;e++){
            // check_separability(v, e);
        }
   }
}