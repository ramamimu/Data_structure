//#include <iostream>
#include <stdio.h>
//using namespace std;

#define MOD 1000000007

int n=1000005;
int arr[1000005];

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    
    arr[0]=11;
    arr[1]=15;
    for(int i=2; i<n; i++)
    {
        if(i>=2 && i<11)
        {
            arr[i]=arr[i-1]+arr[i-2];
            if(arr[i]>MOD)
                arr[i]%=MOD;
        }
        else if(i>=11 && i<15)
        {
            arr[i]=arr[i-11]+arr[i-2];
            if(arr[i]>MOD)
                arr[i]%=MOD;
        }
        else
        {
            arr[i]=arr[i-11]+arr[i-15];
            if(arr[i]>MOD)
                
                arr[i]%=MOD;
        }
    }

//    for(int i=0; i<n; i++)
//        cout<<arr[i]<<"||"<<i<<" ";
    int numb;
//    cin >> numb;
    scanf("%d", &numb);
    int index;
    for(int i=0; i<numb; i++)
    {
//        cin >> index;
        scanf("%d", &index);
//        cout<<arr[index]<<endl;
        printf("%d\n", arr[index]);
    }
    return 0;
}