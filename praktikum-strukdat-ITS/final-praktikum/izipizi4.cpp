#include <bits/stdc++.h>

using namespace std;

#define BUGG(n) cout<<"masuk "<<n<<endl;

struct Edge
{
    int row=0, col=0, cost=0;
    bool operator>(const Edge &edge) const
    {
        return this->cost > edge.cost;
    }
};

int C[] = {-1, 0, 1, 0};
int R[] = {0, 1, 0, -1};


void passing(int row, int col)
{
    vector <vector <int>> point (row, vector<int> (col));
    vector <vector <int>> cost (row, vector<int> (col, -1));
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cin >> point [i][j];
        }
    }

//    BUGG(100);    
//    for(int i=0; i<row; i++)
//    {
//        for(int j=0; j<col; j++)
//        {
//            cout << point [i][j]<<" ";
//        }
//        cout<<endl;
//    }

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    Edge node;
    node.cost=point[0][0];
    cost[0][0] = point [0][0];
    pq.push(node);
    while(!pq.empty())
    {
//        BUGG(11);
        Edge temp=pq.top();
        pq.pop();

        for(int i=0; i<4; i++)
        {
            int rowT = temp.row + R[i];
            int colT = temp.col + C[i];
            
            // out of range
            if (rowT < 0 || rowT >= row || colT < 0 || colT >= col) 
                continue;
                
            if (cost[rowT][colT] == -1|| cost[temp.row][temp.col]+point[rowT][colT] < cost[rowT][colT])
            {    
                cost[rowT][colT] = cost[temp.row][temp.col]+point[rowT][colT];
                node.col=colT;
                node.row=rowT;
                node.cost=cost[rowT][colT];
                pq.push(node);
            }
        }
    }
//    for(int i=0; i<row; i++)
//    {
//        for(int j=0; j<col; j++)
//        {
//            cout << cost [i][j]<<" ";
//        }
//        cout<<endl;
//    }
    
    cout<< cost[row-1][col-1]<<endl;    
}

int main()
{
    int n;
    cin >>n;
    while(n--)
    {
        int row, col;
        cin >> row 
            >> col;
        passing(row, col);
    }
    return 0;
}