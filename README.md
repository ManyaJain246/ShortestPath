# ShortestPath

# Graph Route Optimizer using Dijkstra's Algorithm

## Overview

Graph Route Optimizer is a C++ console application that calculates the shortest path between two cities using **Dijkstra's Algorithm**. The application reads graph data from a text file, constructs an adjacency matrix, and uses a custom **Min Heap** implementation to efficiently compute the shortest route between any two vertices.

The project demonstrates the implementation of graph algorithms and custom data structures without using the C++ STL priority queue.

---

## Features

- Read graph data from an input file
- Construct and display an adjacency matrix
- Find the shortest path between two cities
- Display the complete path and total distance
- Custom Min Heap implementation for efficient priority management
- Menu-driven console interface

---

## Technologies Used

- C++
- File Handling
- Graphs
- Dijkstra's Algorithm
- Adjacency Matrix
- Custom Min Heap
- Dynamic Memory Allocation

---

## Data Structures Used

- Adjacency Matrix
- Arrays
- Custom Min Heap
- Parent Array for Path Reconstruction

---

## Algorithm

The application uses **Dijkstra's Shortest Path Algorithm** to calculate the minimum distance from the source vertex to the destination vertex.

### Steps

1. Read graph data from a text file.
2. Create an adjacency matrix.
3. Initialize all distances as infinity.
4. Insert the source node into the Min Heap.
5. Extract the minimum-distance node.
6. Relax all adjacent vertices.
7. Repeat until all reachable vertices are processed.
8. Reconstruct the shortest path using the parent array.

---

## Project Structure

```
Graph-Route-Optimizer/
│
├── main.cpp          # Complete source code
├── input.txt         # Sample graph input
└── README.md
```

---

## Input File Format

The input file should contain one edge per line in the following format:

```
A,B,4
A,C,2
B,D,5
C,D,8
C,E,10
D,E,2
```

Where:

- First character = Source city
- Second character = Destination city
- Third value = Distance between cities

The graph is considered **undirected**, so each edge is automatically stored in both directions.

---

## Sample Execution

```
Menu
--------------------------------------
1 - Read File
2 - Show Adjacency Matrix
3 - Find Shortest Path
4 - Exit

Enter your choice: 3

Enter the source vertex: A
Enter the destination vertex: E

The shortest path from A to E:
A -> C -> D -> E

The length of this path: 12
```

---

## Concepts Demonstrated

- Graph Representation
- Dijkstra's Algorithm
- Min Heap
- File Handling
- Dynamic Memory Allocation
- Path Reconstruction
- Algorithm Optimization

---

## Future Improvements

- Replace adjacency matrix with adjacency list for better scalability.
- Support directed graphs.
- Add graphical visualization of routes.
- Allow dynamic addition and deletion of vertices.
- Export shortest path reports.
- Implement A* Search Algorithm for comparison.

---

## Learning Outcomes

Through this project, I gained hands-on experience with:

- Implementing Dijkstra's Algorithm from scratch.
- Designing and implementing a custom Min Heap.
- Working with graph data structures.
- Reading structured data using file handling.
- Optimizing shortest path computation.
- Building menu-driven C++ applications.

---

## Author

**Manya Jain**

B.Tech Electronics & Communication Engineering
