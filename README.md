# CGT_Project


## Problem Statement
- PROBLEM 6 => Implementation of separability and cut vertices.

## Algorithim
- Get the vertices of the graph.
- Get the edges of the graph.
- Create adjacency matrix for the graph.
- Loop through the vertices
    - Mark the corresponding row and column in the adjacency matrix as 0 (removing the incident edges)
        - Check if the graph is connected using DFS Traversal.
        - If connected:
            - Mark that the graph is seperable
            - Print the vertex number, indicating that that vertex is the cut vertex of the given graph.
 
 SAMPLE OUTPUTS<br><br>
![image](https://user-images.githubusercontent.com/84980036/204102005-baa43b03-31b7-4a44-b656-829665617fde.png)
<br><br>
![image](https://user-images.githubusercontent.com/84980036/204102043-0ba81c00-ae84-44d7-a862-37fc111d5441.png)
<br><br>
![image](https://user-images.githubusercontent.com/84980036/204102082-d871c498-9af3-425a-8051-0934322ac63c.png)
