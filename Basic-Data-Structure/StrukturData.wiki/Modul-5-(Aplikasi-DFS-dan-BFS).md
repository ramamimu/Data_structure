# BFS (*Breadth First Search*) dan DFS (*Depth First Search*)

## Breadth First Search

BFS adalah algoritma *traversing* di mana Anda harus mulai traverse dari node yang dipilih (sumber atau node mulai) dan melintasi graph secara melebar hingga menjelajahi node tetangga (node yang langsung terhubung ke node sumber), kemudian bergerak menuju node tetangga di layer berikutnya. BFS menggunakan queue dalam penggunaannya. Dengan BFS, kita dapat memiliki banyak kegunaan seperti kita dapat melakukan pencarian maupun mencari shortest path dari suatu graph.

![](img/m5-0.png)

- ## Pseudocode

![](img/m5-2.png)

- ## Ilustrasi

![](img/m5-3.png)
![](img/m5-4.png)
![](img/m5-5.png)
![](img/m5-6.png)
![](img/m5-7.png)

- ## Implementasi BFS

    ```C
    void Graph::BFS(int s) 
    { 
        // Mark all the vertices as not visited 
        bool *visited = new bool[V]; 
        for(int i = 0; i < V; i++) 
            visited[i] = false; 
    
        // Create a queue for BFS 
        list<int> queue; 
    
        // Mark the current node as visited and enqueue it 
        visited[s] = true; 
        queue.push_back(s); 
    
        // 'i' will be used to get all adjacent 
        // vertices of a vertex 
        list<int>::iterator i; 
    
        while(!queue.empty()) 
        { 
            // Dequeue a vertex from queue and print it 
            s = queue.front(); 
            cout << s << " "; 
            queue.pop_front(); 

    
            // Get all adjacent vertices of the dequeued 
            // vertex s. If an adjacent has not been visited,  
            // then mark it visited and enqueue it 
            for (i = adj[s].begin(); i != adj[s].end(); ++i) 
            { 
                if (!visited[*i]) 
                { 
                    visited[*i] = true; 
                    queue.push_back(*i); 
                } 
            } 
        } 
    } 
    ```
    Untuk implementasi menggunakan *adjacency list*, silakan dibuat sendiri, gunakan C++ STL.
    BFS menghasilkan jarak terpendek dari *source* ke *destination* jika diterapkan pada *unweighted graph*.


## Depth First Search

Algoritma DFS adalah algoritma rekursif yang menggunakan gagasan backtracking. Di sini, kata backtrack berarti bahwa ketika Anda bergerak maju dan tidak ada lagi node di sepanjang jalur saat ini, maka Anda akan  bergerak mundur di jalur yang sama untuk menemukan node untuk dilintasi. Semua node akan dikunjungi di jalur saat ini sampai semua node yang belum dikunjungi telah dilalui setelah jalur berikutnya akan dipilih. DFS menggunakan stack / rekursif dalam penggunaannya.

![](img/m5-1.png)

- ## Pseudocode

![](img/m5-8.png)

- ## Ilustrasi

<img src="img/m5-9.png" width="350">
<img src="img/m5-10.png" width="350">
<img src="img/m5-11.png" width="350">
<img src="img/m5-12.png" width="350">
<img src="img/m5-13.png" width="350">
<img src="img/m5-14.png" width="350">
<img src="img/m5-15.png" width="350">
<img src="img/m5-16.png" width="350">
<img src="img/m5-17.png" width="350">

- ## Implementasi BFS

    ```C
    void Graph::DFSUtil(int v, bool visited[]) 
    { 
        // Mark the current node as visited and 
        // print it 
        visited[v] = true; 
        cout << v << " "; 
    
        // Recur for all the vertices adjacent 
        // to this vertex 
        list<int>::iterator i; 
        for (i = adj[v].begin(); i != adj[v].end(); ++i) 
            if (!visited[*i]) 
                DFSUtil(*i, visited); 
    } 
    
    // DFS traversal of the vertices reachable from v. 
    // It uses recursive DFSUtil() 
    void Graph::DFS(int v) 
    { 
        // Mark all the vertices as not visited 
        bool *visited = new bool[V]; 
        for (int i = 0; i < V; i++) 
            visited[i] = false; 
        
        // Call the recursive helper function 
        // to print DFS traversal 
        DFSUtil(v, visited); 
    } 
    ```
    Untuk implementasi menggunakan *adjacency list*, silakan dibuat sendiri, gunakan C++ STL.
    DFS tidak selalu menghasilkan jarak terpendek dari *source* ke *destination* jika diterapkan pada *graph*.