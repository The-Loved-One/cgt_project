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
![image](https://user-images.githubusercontent.com/84980036/204101961-c77b891f-3df8-45ae-9be5-984198cf9347.png)
