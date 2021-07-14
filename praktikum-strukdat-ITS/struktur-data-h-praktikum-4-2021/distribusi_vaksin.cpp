// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
  
typedef pair<int, int> iPair;

int n, m, q;
int *source;
int nextClc, total=0;
  
void addEdge(vector <pair<int, int> > adj[], int u,
                                     int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}   
  
void shortestPath(vector<pair<int,int> > adj[], int V, int src)
{
    int ever=0;
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
  
    vector<int> dist(V, INF);
    vector<int> tanda;
    pq.push(make_pair(0, src));
    dist[src] = 0;
  
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
  
        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;
  
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
                tanda.push_back(v);
            }
        }
    }
    for(auto it: tanda)
    {
        if(it==nextClc && !ever)
        {
            total+=dist[it];
            ever=1;
        }
    }
}
  
int main()
{
    cin >> n
        >> m
        >> q;
    int V = m;
    vector<iPair > adj[V];
  
    int node1, node2, weight;
    for(int i=0; i<m; i++)
    {
        cin >> node1
            >> node2
            >> weight;
        addEdge(adj, node1, node2, weight);
    }
    
    if(q==1)
    {
        cout<<'0'<<endl;
    }
    else
    {
        source = new int[q];
        for(int i=0; i<q; i++)
            cin >> source[i];

        for(int i=0; i<q-1; i++)
        {
            nextClc=source[i+1];
            shortestPath(adj, V, source[i]);
        }
        cout<<total<<endl;
    }
  
    return 0;
}
