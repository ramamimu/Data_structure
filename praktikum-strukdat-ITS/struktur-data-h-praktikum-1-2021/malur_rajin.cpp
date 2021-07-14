#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

typedef struct node 
{
    int soal;
    char nama[16];
    node *next;
}linked;

typedef struct hmm
{
    linked* head;
    unsigned Size;
}buku;

void init (buku *belajar)
{
    belajar->head=NULL;
    belajar->Size=0;
}

void pQueue(buku *belajar, int page, char title[])
{
    linked *newNode=(linked*) malloc (sizeof(linked));
    belajar->Size++;

    strcpy(newNode->nama, title);
    newNode->soal=page;
    newNode->next=NULL;

    if(belajar->head==NULL)
        belajar->head=newNode;
    else
    {
        linked *temp=belajar->head;
        if(page < temp->soal )
        {
            belajar->head=newNode;
            newNode->next=temp;
        }
        else
        {
            while(temp->next != NULL && temp->next->soal < page)
            {
                temp=temp->next;
            }
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }
}

void pushAndPop(buku *urut, buku *notUrut)
{
    int running=0;
    if(notUrut->head != NULL)
    {
        linked *temp = notUrut->head;
        // int _i = 0;
        if ((urut->head->soal == temp->soal)) 
        {
            notUrut->head=notUrut->head->next;
            cout<<running<<' '<<temp->nama<<endl;
            notUrut->Size=notUrut->Size-1;
            free(temp);
        }
        else
        {
            while ((temp->next != NULL) &&  (temp->next->soal != urut->head->soal)) {
                temp = temp->next;
                running++;
            }
            notUrut->head=temp->next;
            cout<<running+1<<' '<<notUrut->head->nama<<endl;

            // free(temp->next);            
            // temp->next = nextTo;
            notUrut->head=notUrut->head->next;
            notUrut->Size=notUrut->Size-(running+2);
        }
    }

    //output

    if(urut->head!=NULL)
    {
        //pop2
        linked *temp=urut->head;
        urut->head=temp->next;
        urut->Size--;
        free(temp);
    }
}

void Stack(buku *asli, int urut, char judul[])
{
    linked *newNode =(linked*)malloc(sizeof(linked));
    asli->Size++;
    strcpy(newNode->nama, judul);
    newNode->soal=urut;
    newNode->next=NULL;

    if(asli->head==NULL)
    {    
        asli->head=newNode;
    }
    else
    {
        newNode->next=asli->head;
        asli->head=newNode;
    }
}

void update(buku *urut, buku *notUrut, int val)
{
    urut->head=NULL;
    urut->Size=0;
    if(notUrut->head!=NULL)
    {
        linked *temp=notUrut->head;
        while(temp!=NULL)
        {
            pQueue(urut, temp->soal, temp->nama);
            temp=temp->next;
        }
    }
}

int main()
{
    buku belajar,cadangan;
    init(&belajar);
    init(&cadangan);

    int n;
    cin>>n;
    int page; 
    char book[16];
    for(int i=0; i<n; i++)
    {
        cin>>page;
        if(page==-1)
        {
            pushAndPop(&belajar, &cadangan);
            update(&belajar, &cadangan, cadangan.Size);
        }
        else
        {
            cin>>book;
            if(page==0)
                continue;
            else
            {
                pQueue(&belajar, page, book);
                Stack(&cadangan, page, book);
            }
        }
    }

   return 0;
}
