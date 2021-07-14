// C++ implementation
#include <bits/stdc++.h>
using namespace std;
 
// Function to return the
// maximum xor
int max_xor(int arr[], int n)
{
 
    int maxXor = INT_MIN;
    // Calculating xor of each pair
    for (int i = 0; i < n; i++) {
        int peak = arr[i];
        int stamina = arr[i];
        for (int j = i + 1; j < n; j++) {
            if(peak < arr[j])
            {
                peak = arr[j];
                // maxXor = max(maxXor,
                //          arr[i] ^ arr[j]);
                stamina ^=arr[j];
            }
        }
        maxXor = max(maxXor, stamina);
    }
    return maxXor;
}
 
// Driver Code
int main()
{
    int n;
    cin >> n;
    int arr[n]={};
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        // int arr[] = { 1, 2, 3, 8, 6 };
        // int n = sizeof(arr) / sizeof(arr[0]);
    }
    cout << max_xor(arr, n) << endl;
    return 0;
}