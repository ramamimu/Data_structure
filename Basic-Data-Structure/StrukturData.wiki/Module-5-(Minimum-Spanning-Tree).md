# Minimum Spanning Tree

## Spanning Tree

Suppose there is a graph G which is an undirected weighted graph, then the Spanning Tree is a subgraph of G where all vertices can be visited and there are no cycles in the graph.

## Minimum Spanning Tree

**Minimum Spanning Tree is the Spanning Tree that has the minimum cost among all Spanning Trees.** The cost in question is the total weight of all the edges in the tree. It is possible to have more than 1 Minimum Spanning Tree.

<img src="img/m5-18.jpg" width="500">

There are 2 well-known implementations for implementing Minimum Spanning Tree, namely *Kruskal's Algorithm* and *Prim's Algorithm*. But what we will discuss now is *Kruskal's Algorithm*.

## Kruskal's Algorithm

**Kruskal's algorithm adds edges one by one so that it becomes a Spanning Tree.** Kruskal's algorithm is a greedy approach in which each iteration looks for the edge with the smallest weight to add so that it can form a Spanning Tree.

In Kruskal's Algorithm, to get the Minimum Spanning Tree, here are 3 steps taken:
1. Sort non-descendingly (not decreasing) all edges based on their weight
2. Add the edge with the smallest weight. If there is a cycle in the Spanning Tree, then delete the edge. If not, add that edge to the Spanning Tree.
3. Perform step 2 until a V – 1 edge is formed on the Spanning Tree.

- ## Contoh:

<img src="img/m5-19.png" width="350">
MST = 0
<img src="img/m5-20.png" width="350">
MST = 1
<img src="img/m5-21.png" width="350">
MST = 3
<img src="img/m5-22.png" width="350">
MST = 5
<img src="img/m5-23.png" width="350">
MST = 9
<img src="img/m5-24.png" width="350">
MST = 13
<img src="img/m5-25.png" width="350">
MST = 20
<img src="img/m5-26.png" width="350">
MST = 28
<img src="img/m5-27.png" width="350">
MST = 37

***

**To determine whether adding an edge causes a cycle, a disjoint set union (DSU) can be performed.** The DSU will have an operation to join two sets, and it will be able to determine a specific set of elements. By finding the parent of the 2 sets that will be checked. If the 2 sets have the same parent, then adding an edge will result in a cycle. Therefore, edges are not added to the Spanning Tree.

- ### Find
    To search for the parent of a vertex, we can do it iteratively or recursively. This implementation uses recursive.

    ```C
    int find(int x) {
        if(par[x] != x) {
            return par[x] = find(par[x]);
        }
    return x;
    }    
    ```

- ### Kruskal

    ```C
    void Kruskal() {
        int res = 0;
        for(int i = 0; i < edge.size(); i++) {
            int src = edge[i].src;
            int dst = edge[i].dst;
            int w = edge[i].w;
            int parSrc = find(src);
            int parDst = find(dst);

            // Disjoint Set
            if(parSrc != parDst) {
                res += w;
                par[parSrc] = par[parDst];
            }
        }
        cout << res << endl;
        return;
    }
    ```