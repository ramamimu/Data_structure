#include <bits/stdc++.h>

using namespace std;

#define BUGG(n) cout<<"masuk "<<n<<endl;

double process(int n)
{
  double arr[n][2];
  for(int i=0; i<n; i++)
  {
    cin >> arr[i][0]
        >> arr[i][1];
  }
  // BUGG(1);
  vector <int> pernah;
  pernah.push_back(0); 
  int visited[n]={}, next;
  visited[0]=1;  
  double res=0, cost;
  // BUGG(1);
  while(pernah.size()<n)
  {
    // BUGG(1);
    cost=DBL_MAX;
    double pointX, pointY;
    for(int i=0; i<pernah.size(); i++)
    {
      pointX=arr[pernah[i]][0];
      pointY=arr[pernah[i]][1];
      for(int j=0; j<n; j++)
      {
        if(!visited[j])
        {
          double euclid=(sqrt(pow((pointX-arr[j][0]),2)+pow((pointY-arr[j][1]),2)));
          if(cost>euclid)
          {
            cost=euclid;
            // cout<<i<<" || "<<j <<" ## "<<cost<<endl;
            next=j;
          }
        }
      }
    }
    // BUGG(cost);
    res+=cost;
    visited[next] =1;
    pernah.push_back(next);
  }
  return res;
}

int main()
{
  int input;
  cin >> input;
  while(input--)
  {
    int n;
    cin >>n;
    printf("%.2lf\n\n", process(n));
  }
  return 0;
}