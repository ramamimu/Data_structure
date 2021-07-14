#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct
{
    int f1Node;
    int s2Node;
    int pBatang;
} Node;

/* Struktur Node */

typedef struct queueNode_t {
    int data;
    int pathWay;
    struct queueNode_t *next;
} QueueNode;

/* Struktur ADT Queue */

typedef struct queue_t {
    QueueNode   *_front, 
                *_rear;
    unsigned _size;
} Queue;

void queue_init(Queue *queue)
{
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, int value, int path)
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        newNode->data = value;
        newNode->pathWay = path;
        newNode->next = NULL;
        
        if (queue_isEmpty(queue))                 
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

void queue_pop(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);
        
        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}

int queue_front(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        return (queue->_front->data);
    }
    return (int)0;
}

int queue_size(Queue *queue) {
    return queue->_size;
}
// BATAS QUEUE

int **arr, maxi=0;
int titik, batang;

Queue choice, isiNode;

void cariDaun(int cari, Node input[], int index, Queue *daun)
{
    int jumlah =0;
    //input 1
    for(int i=0; i<index; i++)
    {
        if(cari==input[i].f1Node)
            jumlah++;
        if(cari==input[i].s2Node)
            jumlah++;
    }

    if(jumlah==1 && cari!=0)
        queue_push(daun, cari, 0);
}

bool find_leaf(Queue *daun, int cari)
{
    QueueNode *temp=daun->_front;
    while(temp != NULL)
    {
        if(temp->data == cari)
            return true;
        temp=temp->next;
    }
    return false;
}

void simple_Q(Queue *last, int root, int path)
{
    if(queue_isEmpty(last))
        queue_push(last, root, path);
    else
    {
        if(last->_front->pathWay >= path)
        {
            if(last->_front->pathWay == path)
            {
                if(last->_front->data > root)
                    last->_front->data = root;
            }
            else
            {
                last->_front->data=root;
                last->_front->pathWay=path;
            }
        }
    }
}

bool available(int root)
{
    for(int i=0; i<maxi; i++)
    {
        if(arr[root][i]!=0)
        {    
            return true;
        }
    }
    return false;
}

int get_min(int root)
{
    int maximum=INT_MAX;
    for(int i=0; i<maxi; i++)
    {
        if(arr[root][i]!=0 && arr[root][i]<maximum)
        {    
            maximum=arr[root][i];
        }
    }
    return maximum;
}

int get_index(int root, int path)
{
    for(int i=0; i<maxi; i++)
    {
        if(arr[root][i]==path)
        {    
            return i;
        }
    }
    return 0;
}


void push_kusus(Queue *queue, int value, int path)
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    queue->_size++;
    newNode->data = value;
    newNode->pathWay = path;
    newNode->next = NULL;
    
    if (queue_isEmpty(queue))                 
        queue->_front = queue->_rear = newNode;
    else {
        if(queue->_front->data == value)
        {
            if(queue->_front->pathWay > path)
                queue->_front->pathWay=path;
            return;
        }
        else
        {
            QueueNode *temp = queue->_front;
            while(temp->next != NULL)
            {
                if(temp->data == value)
                {
                    if(temp->pathWay > path)
                        temp->pathWay = path;
                    return;
                }
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
}

void  process(Queue *daun, int cari, int res)
{
    if(!queue_isEmpty(&isiNode))
    {
        while(available(cari))
        {
            int numb_path=get_min(cari);
            int index=get_index(cari, numb_path);
            if(find_leaf(daun, index))
            {
                simple_Q(&choice, index, numb_path+res);
            }
            else
            {
                push_kusus(&isiNode, index, res+numb_path);
            }
            arr[cari][index]=0;
            arr[index][cari]=0;
        }
        queue_pop(&isiNode);
        if(!queue_isEmpty(&isiNode))
        {
            process(daun, isiNode._front->data ,isiNode._front->pathWay);
        }
    }
}

void recover (Node redefinite[])
{
    for(int i=0; i<batang; i++)
    {
        arr[redefinite[i].f1Node][redefinite[i].s2Node]=redefinite[i].pBatang;
        arr[redefinite[i].s2Node][redefinite[i].f1Node]=redefinite[i].pBatang;
    }
}

int main()
{
    scanf("%d %d", &titik, &batang);
    Node input[batang];

    for(int i=0; i<batang; i++)
    {
        scanf("%d %d %d", &input[i].f1Node, &input[i].s2Node, &input[i].pBatang);
        if(maxi<input[i].f1Node)
            maxi=input[i].f1Node;
            
        if(maxi<input[i].s2Node)
            maxi=input[i].s2Node;
    }
    
    maxi+=1;
    arr=(int**) calloc (maxi, sizeof(int*));
    for(int i=0; i<maxi; i++)
    {
        arr[i]=(int*)calloc(maxi, sizeof(int));
    }

    //SUCCESS CARI DAUN
    Queue daun;
    queue_init(&daun);
    for(int i=0; i<batang; i++)
    {
        cariDaun(input[i].f1Node, input, batang, &daun);
        cariDaun(input[i].s2Node, input, batang, &daun);
    }
    //BATAS SUCCES  


    int q;
    scanf("%d", &q);
    for(int i=0; i<q; i++)
    {
        int cari;
        scanf("%d", &cari);

        recover(input);
 
        queue_init(&choice);
        queue_init(&isiNode);

        if(find_leaf(&daun, cari))
        {
            printf("%d\n", cari);
            continue;
        }

        queue_push(&isiNode, cari, 0);
        process(&daun, isiNode._front->data, isiNode._front->pathWay);

        printf("%d\n", choice._front->data);
    }
    return 0;
}