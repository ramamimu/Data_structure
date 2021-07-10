# Priority Queue
## Terminology
* **Top** - is a node with the highest priority within the queue.

## Definition
Priority Queue is a unique variation of the Queue data structure, as it will sort the stored data by default. Data stored within a Priority Queue will be sorted based on their priority, which means the first data to come out is the one with the highest priority, regardless of when they got inserted. Knowing this, we can utilize Priority Queues to solve problems where different priorities exist.
> "pqueue" might be used to shorten "Priority Queue" for the duration of this module.

## Basic Operation
* **isEmpty** - to check whether the pqueue is empty or not.
* **push** - to insert new data.
* **pop** - to remove data with the highest priority.
* **top** - to get the data with the highest priority/located at the top.

## Priority Queue's Use Cases
Pqeues could be used to solved the following problems:
  1. CPU program scheduling.
  2. Implementation of Dijkstra Shortest Path and Prim's Minimum Spanning Tree algorithms.
  3. Problems where the data have different priority levels.

## ADT Implementation: `Priority Queue`
[**A complete implementation of `Priority Queue` can be accessed here.**](https://github.com/AlproITS/StrukturData/)

In this module, the Min-Priority Queue will be implemented, where nodes with the smaller numbers will be prioritized. 

![min-priority queue](https://raw.githubusercontent.com/wiki/AlproITS/StrukturData/img/m1-4.png)

The simplest way to implement such pqueue is by modifying the **Singly Linked List** data structure, where the `top` pointer is used to refer to the node with the highest priority.
> Sidenote: Implementing a Priority Queue data structure by using Linked List is not the most efficient implementation. One way to achieve higher efficiency is by implementing it with the **Heap Tree** data structure.

* ### Node Representation
  Nodes of a pqueue can be represented by a struct named `pqueueNode` that stores an `int` variable and a pointer to refer to the next node.
  ```c
  typedef struct pqueueNode_t {
      int data;
      struct pqueueNode_t *next;
  } PQueueNode;
  ```
* ### Pqueue Structure
  A pqueue has one pointer `top` to refer the node with the highest priority within its structure.
  ```c
  typedef struct pqueue_t {
      PQueueNode *_top;
      unsigned _size;
  } PriorityQueue;
  ```
* ### isEmpty
  To check whether a pqueue is empty or not, simply check whether its `top` refers to `NULL` or not.
  ```c
  bool pqueue_isEmpty(PriorityQueue *pqueue) {
      return (pqueue->_top == NULL);
  }
  ```
* ### push
  To do a push, kindly follow these steps:
  * store the current `top` node within a temporary variable
  * make a new node.
  * if the pqueue is empty, make the new node as the `top`.
  * if it is not empty, there can be two cases.

  **First case, the new node contains smaller data than the one stored at the `top` (higher priority)**
  * make the next of the new node refer to the current `top`.
  * make the `top` refer to the new node.

  ![case 1 visualization](https://raw.githubusercontent.com/wiki/AlproITS/StrukturData/img/m1-5.png)
  
  **Second case, the new node contains bigger data than the one stored at the `top` (lower priority)**
  * iterate through the queue until the data within new node isn't bigger.
  * or iterate until the end of pqeueu, where next is `NULL`.
  * make the next of the new node refer to the next of the temp node.
  * make the next of the temp node to the new node.

  ![case 2 visualization](https://raw.githubusercontent.com/wiki/AlproITS/StrukturData/img/m1-6.png)

  ```c
  void pqueue_push(PriorityQueue *pqueue, int value)
  {
      PQueueNode *temp = pqueue->_top;
      PQueueNode *newNode = \
          (PQueueNode*) malloc (sizeof(PQueueNode));
      newNode->data = value;
      newNode->next = NULL;

      if (pqueue_isEmpty(pqueue)) {
          pqueue->_top = newNode;
          return;
      }

      if (value < pqueue->_top->data) {
          newNode->next = pqueue->_top;
          pqueue->_top = newNode;
      }
      else {
          while ( temp->next != NULL && 
                  temp->next->data < value)
              temp = temp->next;
          newNode->next = temp->next;
          temp->next = newNode;
      }
  }
* ### pop
  To do the **pop**, follow these steps:
  * make sure that the pqueue is not empty.
  * make a `temp` (temporary) node that points to the `top` node.
  * make the `top` to point to the current `top`'s next node.
  * remove the `temp` node.
  ```c
  void pqueue_pop(PriorityQueue *pqueue)
  {
      if (!pqueue_isEmpty(pqueue)) {
          PQueueNode *temp = pqueue->_top;
          pqueue->_top = pqueue->_top->next;
          free(temp);
      }
  }
* ### top
  ```c
  int pqueue_top(PriorityQueue *pqueue) {
      if (!pqueue_isEmpty(pqueue))
          return pqueue->_top->data;
      else return 0;
  }
  ```