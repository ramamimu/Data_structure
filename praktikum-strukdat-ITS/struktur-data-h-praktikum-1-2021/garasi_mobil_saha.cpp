#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int in;
    int out;
    node *next;
}linked;

linked *head;
int sizeCar;

void init()
{
    head=NULL;
    sizeCar=0;
}

void push(int yo, int ot)
{
    linked *newNode = (linked*) malloc(sizeof(linked));
    sizeCar++;
    newNode->in=yo;
    newNode->out=ot;
    newNode->next=NULL;
    head=newNode;
}

void pQueue(int in, int out)
{
    linked *newNode = (linked*) malloc(sizeof(linked));
    (sizeCar)++;
    newNode->in = in;
    newNode->out = out;
    newNode->next = NULL;

    linked *temp = head;    
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

bool isAcc(int in, int out)
{
    if(in==out)
        return false;
    else if((in < head->in) && (out<=head->in))
        return false;
    else if((in < head->in) && (out>head->out))
        return false;
    else if((in > head->in) && (out < head->out))
        return false;
    else if((in >= head->out) && (out > head->out))
        return false;
    else
        return true;
}

bool checkIn(int arr[], int index, int val)
{
    for(int i=0; i<index; i++)
        if(arr[i]==val)
            return true;
    return false;
}

bool checkOut(int arr[], int index, int val)
{
    for(int i=0; i<index; i++)
        if(arr[i]==val)
            return true;
    return false;
}


int main()
{
    int n;
    cin>>n;
    
    int p, q;
    for(int i=0; i<n; i++)
    {
        init();
        cin>>p>>q;
        int timeIn, timeOut;
        int checkInn[p]={}, checkOutt[p]={};
        int pernah=0;
        for(int j=0; j<p; j++)
        {
            cin>>timeIn>>timeOut;
            checkInn[j]=timeIn;
            checkOutt[j]=timeOut;
            
            if(j==0)
                push(timeIn, timeOut);
            else if(isAcc(timeIn, timeOut))
                pQueue(timeIn, timeOut);
            
            if((timeIn==timeOut))
            { 
                pernah++;
            }
            else if ((checkIn(checkInn, j, timeIn) || checkOut(checkOutt, j, timeOut)))
            {
                pernah++;
            }
        }
        if(pernah)
            cout<<"Hmm harus renovasi garasi nich\n";
        else
        {
            if(sizeCar < q)
                cout<<"Hore gausah renov garasi\n";
            else
                cout<<"Hmm harus renovasi garasi nich\n";
        }
    }
    return 0;
}
