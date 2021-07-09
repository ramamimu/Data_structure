// C++ program to check if a given instance of 8 puzzle is solvable or not
#include <bits/stdc++.h>
using namespace std;

#define N 3
 
int ketinggian;
// state space tree nodes
struct Node
{
    // stores the parent node of the current node
    // helps in tracing path when the answer is found
    Node* parent;
 
    // stores matrix
    int mat[N][N];
 
    // stores blank tile coordinates
    int x, y;
 
    // stores the number of misplaced tiles
    int cost;
 
    // stores the number of moves so far
    int level;
};
 
// Function to print N x N matrix
void printMatrix(int mat[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d", mat[i][j]);
        printf("\n");
    }
}
 
// Function to allocate a new node
Node* newNode(int mat[N][N], int x, int y, int newX,
              int newY, int level, Node* parent)
{
    Node* node = new Node;
 
    // set pointer for path to root
    node->parent = parent;
 
    // copy data from parent node to current node
    memcpy(node->mat, mat, sizeof node->mat);
 
    // move tile by 1 position
    swap(node->mat[x][y], node->mat[newX][newY]);
 
    // set number of misplaced tiles
    node->cost = INT_MAX;
 
    // set number of moves so far
    node->level = level;
    ketinggian=level;
    // update new blank tile cordinates
    node->x = newX;
    node->y = newY;
 
    return node;
}
 
// bottom, left, top, right
int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };
 
// Function to calculate the number of misplaced tiles
// ie. number of non-blank tiles not in their goal position
int calculateCost(int initial[N][N], int final[N][N])
{
    int count = 0;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        if (initial[i][j] && initial[i][j] != final[i][j])
           count++;
    return count;
}
 
// Function to check if (x, y) is a valid matrix cordinate
int isSafe(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N);
}
 
// print path from root node to destination node
int cek=0;
void printPath(Node* root)
{
    if (root == NULL)
        return;
    printPath(root->parent);
    if(!(cek==0))
        printMatrix(root->mat);
    if(!(cek==0 || cek == ketinggian))
    printf("\n");
    cek++;
}
 
// Comparison object to be used to order the heap
struct comp
{
    bool operator()(const Node* lhs, const Node* rhs) const
    {
        return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
    }
};
 
// Function to solve N*N - 1 puzzle algorithm using
// Branch and Bound. x and y are blank tile coordinates
// in initial state
void solve(int initial[N][N], int x, int y,
           int final[N][N])
{
    // Create a priority queue to store live nodes of
    // search tree;
    priority_queue<Node*, std::vector<Node*>, comp> pq;
 
    // create a root node and calculate its cost
    Node* root = newNode(initial, x, y, x, y, 0, NULL);
    root->cost = calculateCost(initial, final);
 
    // Add root to list of live nodes;
    pq.push(root);
 
    // Finds a live node with least cost,
    // add its childrens to list of live nodes and
    // finally deletes it from the list.
//    int cek=0;
    while (!pq.empty())
    {
        // Find a live node with least estimated cost
        Node* min = pq.top();
 
        // The found node is deleted from the list of
        // live nodes
        pq.pop();
 
        // if min is an answer node
        if (min->cost == 0)
        {
//            cek++;
//            cout<<cek<<endl;
            // print the path from root to destination;
    cout<<"Langkah minimum = "<<ketinggian<<endl; 
            
            printPath(min);
            return;
        }
 
        // do for each child of min
        // max 4 children for a node
        for (int i = 0; i < 4; i++)
        {
            if (isSafe(min->x + row[i], min->y + col[i]))
            {
                // create a child node and calculate
                // its cost
                Node* child = newNode(min->mat, min->x,
                              min->y, min->x + row[i],
                              min->y + col[i],
                              min->level + 1, min);
                child->cost = calculateCost(child->mat, final);
 
                // Add child to list of live nodes
                pq.push(child);
            }
        }
    }
}
 
// A utility function to count inversions in given array 'arr[]'
int getInvCount(int arr[])
{
    int inv_count = 0;
    for (int i = 0; i < 9 - 1; i++)
        for (int j = i+1; j < 9; j++)
             // Value 0 is used for empty space
             if (arr[j] && arr[i] &&  arr[i] > arr[j])
                  inv_count++;
    return inv_count;
}
 
// This function returns true if given 8 puzzle is solvable.
bool isSolvable(int puzzle[3][3])
{
    // Count inversions in given 8 puzzle
    int invCount = getInvCount((int *)puzzle);
 
    // return true if inversion count is even.
    return (invCount%2 == 0);
}
 
/* Driver program to test above functions */
int main(int argv, char** args)
{
  int x=0,y=0;
  char input[3][3];
  while(scanf("%s", input[0]) != EOF)
  {
    int initial[3][3];
    scanf("%s", input[1]);
    scanf("%s", input[2]);
    ketinggian = 0, cek =0;
    for(int i=0; i<3; i++)
    {
      for(int j=0; j<3; j++)
      {
        initial[i][j]=input[i][j]-'0';
        if(initial[i][j]==0)
        {
          x=i; y=j;
        }
      }    
    }
    int final[N][N] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };

    if(isSolvable(initial))
        solve(initial, x, y, final);
    else
      cout<<"Problem tidak dapat diselesaikan"<<endl;
  }
  return 0;
}
