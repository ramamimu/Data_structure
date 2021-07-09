#include <bits/stdc++.h>
using namespace std;

char **arr;
int *check;
int n,x,p,l;
int COUNT=0;
int MAXCOUNT=0;
int *sudah;
int maxToday=0;

void init()
{
    check=(int*)calloc(l, sizeof(int));
    MAXCOUNT=0;
}

void initBool()
{
    sudah=(int*)calloc(l, sizeof(int));    
}

bool isEmpty(int* Stack)
{
    if(Stack==NULL)
        return true;
    else
        return false;
}


void checkArr(int r)
{
    for(int i=0; i<l; i++)
    {
        if(arr[r][i]=='0')
        {
            if(check[i] != 0)
                (check[i])++;
            else 
                (check[i])=1;
        }
        else
            check[i]=0;
    }
}

bool pernah(int c)
{
    if(sudah[c])
        return true;
    else
        return false;
}

int res=0;
void autoCount(int c, int number)
{
    if(check[c]>0 && !pernah(c))
    {
        sudah[c]++;
        res+=number;
        if(check[c-1]>=number && c!=0)
            autoCount(c-1, number);
        if(check[c+1]>=number & c!=l-1)
            autoCount(c+1, number);
    }
}

void revitalize()
{
    for(int i=0; i<l; i++)
        sudah[i]=0;
}

void recursive()
{
    COUNT=0;
    for(int i=0; i<l; i++)
    {
        autoCount(i, check[i]);
        COUNT=max(res, COUNT);
        res=0;
        revitalize();
    }
}

int main()
{
    
    cin>>n>>x;    
    for(int i=0; i<n; i++)
    {
        MAXCOUNT=0;
        cin>>p>>l;
        
        arr=(char**)malloc(sizeof(char*)*p);
        for(int j=0; j<p; j++)
            arr[j]=(char*)malloc(sizeof(char)*l);
        
        for(int j=0; j<p; j++)
        {
            for(int k=0; k<l; k++)
                cin>>arr[j][k];
        }
                
        int maxNum;
        init();
        for(int j=0; j<p; j++)
        {
            initBool();
            checkArr(j);
            recursive();
            MAXCOUNT=max(MAXCOUNT, COUNT);
        }
        if(MAXCOUNT>=x)
            cout<<"IYA\n";
        else
            cout<<"TIDAK\n";
    }
    return 0;
}
