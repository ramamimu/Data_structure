#include <bits/stdc++.h>

using namespace std;

#define BUGG(n) cout<<"masuk "<<n;

bool compare(int a, int b)
{
    return a>b;
}

int main()
{
    int a=5;
    int b=2;
    if(compare(a, b))
        BUGG("oke\n");

    if(compare(b, a))
    {    BUGG("lain\n");}
    else{
        BUGG("salah\n");
    }
    return 0;
}