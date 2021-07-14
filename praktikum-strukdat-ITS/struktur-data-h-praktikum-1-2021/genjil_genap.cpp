#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct node{
    int arr;
    node *next;
}pNode;
pNode *head;

void init()
{
    head=NULL;
}

void pushBack(int numb)
{
    pNode *newNode=(pNode*) malloc (sizeof(pNode));
    newNode->arr=numb;
    newNode->next=NULL;
    if(head==NULL)
        head=newNode;
    else
    {
        pNode *temp = head;
        if((numb % 2)==0 )
        {
            newNode->next = temp;
            head=newNode;
        }
        else
        {
            while(temp->next != NULL )
            {
                temp=temp->next;
            }
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }
    
}

void printOut()
{
    pNode *temp=head;
    cout<<"Urutan Mobil Roy : ";
    while( temp != NULL )
    {
        cout<<temp->arr<<' ';
        temp=temp->next;
    }
}

int main()
{
    init();
    int n, input;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input;
        pushBack(input);
    }
    printOut();
    return 0;
}
