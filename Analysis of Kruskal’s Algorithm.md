A. Kruskal’s Algorithm

Sort All Edges: Sort all the edges in non-decreasing order of their weight.

Initialize: Create a set for each vertex.

Construct MST: Pick the smallest edge, check if it forms a cycle with the spanning tree formed so far. If it doesn't, include it in the MST.

B. Analysis of Algorithms

Sorting: Time Complexity is O(E log E), where E is the number of edges.

Union-Find Operations: The find and union operations take nearly constant time, O(E log V) using path compression and union by rank, where V is the number of vertices.

Overall Time Complexity: O(E log E + E log V) ~ O(E log V), as E can be at most V^2.
