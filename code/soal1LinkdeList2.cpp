#include <stdio.h>
#include <stdlib.h>

// Linked list
typedef struct node
{
    int data;
    node* next;
}forNode;

typedef struct memorize
{
    int size;
    forNode* head;
}List;

void dlist_init(List *initHead)
{
    initHead->size = 0;
    initHead->head = NULL;
}

void pushBackandInsert(List* hello, int val)
{
    forNode *newNode = (forNode*) malloc(sizeof(forNode));
    (hello->size)++;
    newNode->data = val;
    newNode->next = NULL;
    if(hello->head == NULL)
    {
        hello->head = newNode;
    }
    else
    {
        forNode *temp = hello->head;    
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
} 

void printElement(int *elem) {
    printf("%d ", *elem);
}

void multiply2(int *elem) {
    printf("%d ", (*elem)*2);
}

void forEachElement(List *terlupakan, void (apaYa)(int*))
{
    forNode *temp = terlupakan->head;
//    int nasi;
    while( temp != NULL )
    {
        printf("%d ", apaYa(terlupakan));
//        nasi=temp->data;
//        apaYa(&nasi);
        temp=temp->next;
    }
    printf("\n");
}


int main()
{
    List myList;
    dlist_init(&myList);

    pushBackandInsert(&myList, 1);
    pushBackandInsert(&myList, 2);
    pushBackandInsert(&myList, 3);
    pushBackandInsert(&myList, 4);
    pushBackandInsert(&myList, 5);

    // contoh fungsi forEachElement untuk mencetak data pada list

    forEachElement(&myList, printElement);

    // contoh fungsi forEachElement untuk mengalikan setiap elemen
    // dengan 2

    forEachElement(&myList, multiply2);

    // isi list menjadi [2,4,6,8,10]
    return 0;
}