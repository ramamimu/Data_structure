// https://www.tutorialspoint.com/Detect-Cycle-in-a-an-Undirected-Graph
#include<bits/stdc++.h>
using namespace std;

int **graph;
int NODE;

bool dfs(int vertex, set<int>&visited, int parent) {
   visited.insert(vertex);
   for(int v = 0; v<NODE; v++) {
      if(graph[vertex][v]) {
         if(v == parent)    //if v is the parent not move that direction
            continue;
         if(visited.find(v) != visited.end())    //if v is already visited
            return true;
         if(dfs(v, visited, vertex))
            return true;
      }
   }
   return false;
}

bool hasCycle() {
   set<int> visited;       //visited set
   for(int v = 0; v<NODE; v++) {
      if(visited.find(v) != visited.end())    //when visited holds v, jump to next iteration
         continue;
      if(dfs(v, visited, -1)) {    //-1 as no parent of starting vertex
         return true;
      }
   }
   return false;
}

int main() {
    int n;
    cin >> n;
    int arr[n][2];
    int maxi=INT_MIN;
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i][0]
            >> arr[i][1];

        if (arr[i][0]>maxi)
            maxi=arr[i][0];
        if (arr[i][1]>maxi)
            maxi=arr[i][1];
    }
    maxi+=1;
    NODE = maxi;
    
    graph = new int*[maxi];
    for(int i = 0; i < maxi; ++i)
    {    
        graph[i] = new int[maxi];
        for(int j=0; j<maxi; j++)
            graph[i][j]=0;
    }

    for(int i = 0; i < n; ++i)
    {
        graph[arr[i][0]][arr[i][1]]=1;
        graph[arr[i][1]][arr[i][0]]=1;
    }

   bool res;
   res = hasCycle();
   if(res)
      cout << "Ada Cycle!" << endl;
   else
      cout << "Tidak Ada Cycle!" << endl;
}
