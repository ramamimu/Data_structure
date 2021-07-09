#include <stdio.h>
#include <stdlib.h>

// Linked list
typedef struct node
{
    int data;
    node* next;
}List;

List* head;

void dlist_init(List *initHead)
{
    head = NULL;
}

void pushBackandInsert(List* hello, int val)
{
    List *newNode = (List*) malloc(sizeof(List));
    //1
//    printf("1\n");
    //2
//    printf("2\n");
    newNode->data = val;
    newNode->next = NULL;
    if(head == NULL)
    {
        head = newNode;
//        if (head!=NULL)
//            printf("headnya full\n");
//        printf("12\n");
//        printf("nomer = %d\n", newNode->data);
    }
    else
    {
        List *temp = head;    
        //3
//        printf("3\n");
        while (temp->next != NULL)
        {
//        printf("123\n");
//            printf("nomer = %d\n", temp->data);
            temp = temp->next;
        }
//        printf("4\n");
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
    List* temp=head;
    int nasi;
    if(temp != NULL)
//        printf("KOK BISAA\n");
//    printf("%d\n", temp->data);
    while( temp != NULL )
    {
//        printf("tes\n");
        nasi=temp->data;
//        printf("ini nasi %d\n");
        apaYa(&nasi);
        temp=temp->next;
    }

    printf("\n");
}


int main()
{
    List myList;
    dlist_init(&myList);

    // Anggap isi linked list adalah [1,2,3,4,5]
    pushBackandInsert(&myList, 1);
//    printf("masuk 1\n");
    pushBackandInsert(&myList, 2);
//    printf("masuk 2\n");
    pushBackandInsert(&myList, 3);
//    printf("masuk 3\n");
    pushBackandInsert(&myList, 4);
//    printf("masuk 4\n");
    pushBackandInsert(&myList, 5);
//    printf("masuk 5\n");

    // contoh fungsi forEachElement untuk mencetak data pada list

    forEachElement(&myList, printElement);

    // contoh fungsi forEachElement untuk mengalikan setiap elemen
    // dengan 2

    forEachElement(&myList, multiply2);

    // isi list menjadi [2,4,6,8,10]
    return 0;
}