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
 
 SAMPLE OUTPUTS<br><br>
![image](https://user-images.githubusercontent.com/84980036/204102005-baa43b03-31b7-4a44-b656-829665617fde.png)
<br><br>
![image](https://user-images.githubusercontent.com/84980036/204102043-0ba81c00-ae84-44d7-a862-37fc111d5441.png)
