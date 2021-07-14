#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    long long numb;
    set <long long> arr;
    while(n--)
    {
        cin >> numb;
        if(arr.count(numb))
        {    
            cout<<"G\n";
            return 0;
        }
        arr.insert(numb);
    }
    cout<<"Y\n";

    return 0;
}