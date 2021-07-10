# Shortest Path

## Shortest Path Problem

**In graph problems, the Shortest Path Problem is a path finding of 2 vertices in a graph that has the minimum sum of weights.** This problem can be solved easily using BFS if all edges have a weight of 1. However, in this problem, weight can be of any value. There are many implementations for solving the Shortest Path Problem, but what we will discuss now is *Dijkstra's Algorithm*.

## Djikstra's Algorithm

Dijkstra's algorithm itself has many variations, but the most common is to find the shortest path from the source vertex to all other vertices.

- ### Steps:
1. Set all vertex distances to infinity (can be replaced with very large values or values that will not be used) except the distance from the source which will be set to 0.
2. Push vertex source to min-priority queue (priority queue with the order from small to large) with format (distance, vertex), for comparison of min-priority queue will use distance from vertex.
3. Pop the vertex with the minimum distance from the priority queue
4. Update the distance of the connected vertex to the popped vertex (the vertex from the result of step 3) with the case “current vertex distance + edge weight < next vertex distance”, then push the vertex.
5. If the results of the pop vertex have been visited previously, then do continue.
6. Perform steps 3 to 5 until the priority queue is empty.

- ### Example:
Find the shortest path from vertex A to all other vertices.

<img src="img/m5-28.png" width="350">

***

Inisial:\
<img src="img/m5-29.png" width="550">

Step 1:\
<img src="img/m5-30.png" width="550">

Step 2:\
<img src="img/m5-31.png" width="550">

Step 3:\
<img src="img/m5-32.png" width="550">

Step 4:\
<img src="img/m5-33.png" width="550">

Step 5:\
<img src="img/m5-34.png" width="550">

- ### Dijkstra's implementation:

    ```C
    // pii pair of integer, integer
    typedef pair <int, int> pii;
    int dist[10];
    vector <pii> v[10];

    void dijkstra(int s, int n) {
        priority_queue <pii, vector <pii>, greater <pii> > pq;
        set <int> seen;
        memset(dist, -1, sizeof(dist));
        dist[s] = 0;
        pq.push({0, s});
        while(!pq.empty()) {
            pii now = pq.top();
            pq.pop();
            if(seen.find(now.second) != seen.end()) continue;
            seen.insert(now.second);
            for(int i = 0; i < v[now.second].size(); i++) {
                int next = v[now.second][i].second;
                int cost = v[now.second][i].first;

                if(now.first + cost < dist[next] || dist[next] == -1) {
                    dist[next] = now.first + cost;
                    pq.push({dist[next], next});
                }
            }
        }
        for(int i = 0; i < n; i++) {
            cout << "from " << s << " to " << i << " : " << dist[i] << endl;
        }
        return;
    }
    ```