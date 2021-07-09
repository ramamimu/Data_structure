#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    // int arr[n]={};
    vector <int> vec;
    // int arrT[t]={};
    int numb;
    for(int i=0; i<n; i++)
    {
        // cin >> arr[i];
        cin >> numb;
        vec.push_back(numb);
    }
    sort( vec.begin(), vec.end(), greater<int>());
    vec.erase( unique( vec.begin(), vec.end() ), vec.end() );    // sort(arr, arr+n);
    // for(auto i=0; i<n-1; i++)
    // {
    //     // cout<<arr[i]<<" ";
    //     cout<<vec[i]<<" ";
    // }
    // cout<<endl;
    cout<<vec[t-1];
    // cout<<arr[t];
    return 0;
}