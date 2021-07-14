#include <bits/stdc++.h>

using namespace std;

#define BUGG(n) cout<<"masuk "<<n;

void process(int input)
{
    if(input>=150)
        cout<<"YES\n";
    else
    {
        long long temp=input%11;
        temp=15*((3*temp)%11);
        // temp*=15;
        if(input>=temp)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    while(n--)
    {
        long long input;
        cin >> input;
        process(input);
    }   
    return 0;
}