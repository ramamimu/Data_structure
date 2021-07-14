#include <iostream>

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
        pNode *temp=head;
        if(temp->arr < numb)
        {
            head=newNode;
        }
        else
        {
            while(temp->next != NULL && temp->next->arr >= numb)
            {
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
}

void printOut()
{
    pNode *temp=head;
    cout<<"Susunan blok yang disusun Nadut dan Cayo adalah : ";
    while( temp != NULL )
    {
        cout<<temp->arr<<' ';
        temp=temp->next;
    }
    cout<<endl;
}

void pop()
{
    if(head!=NULL)
    {
        pNode *temp= head;
        head=head->next;
        free(temp);
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        init();
        int num;
        cin>>num;
        if (num==0)
        {
            printOut();
            return 0;
        }
        int arr;
        for(int j=0; j<num; j++)
        {
            cin>>arr;
            pushBack(arr);
        }
        printOut();
        pop();
    }
}
