#include <bits/stdc++.h>

using namespace std;
double **city;

int minnode(int n, int keyval[], bool mstset[]) {
  int mini = numeric_limits<int>::max();
  int mini_index;
 
  for (int i = 0; i < n; i++) {
    if (mstset[i] == false && keyval[i] < mini) {
      mini = keyval[i], mini_index = i;
    }
  }
  return mini_index;
}
 
void findcost(int n) {
  int parent[n]; 
  int keyval[n];
  bool mstset[n];
 
  for (int i = 0; i < n; i++) {
    keyval[i] = numeric_limits<int>::max();
    mstset[i] = false;
  }
  parent[0] = -1;
  keyval[0] = 0;
 
  for (int i = 0; i < n - 1; i++) {
    int u = minnode(n, keyval, mstset); 
    mstset[u] = true;
 
    for (int v = 0; v < n; v++) {
 
      if (city[u][v] && mstset[v] == false &&
          city[u][v] < keyval[v]) {
        keyval[v] = city[u][v];
        parent[v] = u;
      }
    }
  }
 
  double cost = 0;
  for (int i = 1; i < n; i++)
    cost += city[parent[i]][i];
    printf("%lf\n", cost);
}

int main()
{
    int n;
    cin >> n;
    city = (double**) malloc (n*sizeof(double*));
    for(int i=0; i<n; i++)
        city[i] = (double*) malloc (n*sizeof(double));        
    double input[n][3];
    for(int i=0; i<n; i++)
    {
        cin >> input[i][0]
            >> input[i][1]
            >> input[i][2];
            for(int j=0; j<=i; j++)
            {
                if(i==j)
                {
                    city[i][j]=0;
                    continue;
                }
                city[i][j]=sqrt(pow((input[i][0]-input[j][0]),2)+pow((input[i][1]-input[j][1]),2))*abs(input[i][2]-(input[j][2]));
                city[j][i]=city[i][j];
        }
    }
        findcost(n);
    return 0;
}
