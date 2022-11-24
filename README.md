# cgt_assignment


## Problem Statement
- PROBLEM 6 => Implementation of cut vertices and separability

## Algorithim
- get the vertices
- get the edges
- loop through the vertices, remove the ith vertix and using DFS, check if the resulted graph is connected
    - if not connected => the ith vertix is a cut vertix and graph is called seperable
