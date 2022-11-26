# cgt_assignment


## Problem Statement
- PROBLEM 6 => Implementation of cut vertices and separability

## Algorithim
- Get the vertices
- Get the edges
- Form adjacency matrix
- Loop through the vertixes
    - mark the corresponding row and column in the adjacency matrix as 0 (removing the incident edges)
        - Use DFS and check if the graph is connected
        - if connected
            - mark that the graph is seperable
            - print the vertex name
 
 SAMPLE OUTPUTS
 ![image](https://user-images.githubusercontent.com/84980036/204101761-61a7946e-1d2e-4bbf-97c8-6eadb90c4c18.png)

![image](https://user-images.githubusercontent.com/84980036/204101394-39063978-4c52-4f23-8e37-92d6fc70dfe9.png)


