#include <bits/stdc++.h>

using namespace std;

typedef struct Snode{
    int data;
    Snode *next;
}linked;

typedef struct inData
{
    linked* head;
    unsigned Size;
}so;

void init(so *ray, so *kakak)
{
    ray->head=kakak->head=NULL;
    ray->Size=kakak->Size=0;
}

bool isEmpty(so *Stack)
{
    return(Stack->head==NULL);
}

void pushBack(so *who, int val)
{
    linked *newNode =(linked*)malloc(sizeof(linked));
    who->Size++;
    newNode->data=val;
    newNode->next=NULL;

    if(isEmpty(who))
        who->head=newNode;
    else
    {
        linked *temp=who->head;
        who->head=newNode;
        newNode->next=temp;
    }
}

void pushAndPop(so *PUSH, so *POP)
{
    if(POP->head!=NULL)
    {
        //push
        pushBack(PUSH, POP->head->data);

        //pop
        POP->Size--;
        linked *temp = POP->head;
        POP->head = POP->head->next;
        free(temp);
    }
}

void pop(so *POP)
{
    if(POP->Size>0)
    {
        POP->Size--;
        linked* temp=POP->head;
        POP->head=temp->next;
        free(temp);
    }
}

int main()
{
    so ray;
    so kakak;
    init(&ray, &kakak);
    int n;
    cin>>n;
    if(n==0)
    {
        cout<<"Ray SangaT MaraH!"<<endl;
    }

    for(int i=n; i>=1; i--)
        pushBack(&ray, i);

    int t;
    cin>>t;
    int x, y;
    for(int i=0; i<t; i++)
    {
        cin>>x>>y;
        if(x==1)
        {
            for(int j=0; j<y; j++)
                pushAndPop(&kakak, &ray);
        }
        else if(x==2)
        {
            for(int j=0; j<y; j++)
                pushAndPop(&ray, &kakak);
        }
        else
        {
            cout<<"TumpukAnnya saLah! :("<<endl;
            return 0;
        }
    }

    int index=max(ray.Size, kakak.Size);
    int ever=0;
    for(int i=0; i<index; i++)
    {
        if(ray.Size>0)
        {
            cout<<ray.head->data<<' ';
            pop(&ray);
        }
        else
        {
            if(ray.Size<=0 && !ever)
            {
                cout<<"- ";
                ever++;
            }
            else
                cout<<" ";
        }
        if(kakak.Size>0)
        {
            cout<<kakak.head->data<<endl;
            pop(&kakak);
        }
        else
        {
            if(kakak.Size<=0 && !ever)
            {
                cout<<":("<<endl;
                ever++;
            }
            else
                cout<<endl;
        }
    }
    return 0;
}
