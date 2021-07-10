# Deque
## Terminology
* **Head** - the first node/located in the front of the deque.
* **Tail** - the last node/located at the back of the deque.

## Definition
**Deque (Double-ended Queue)** is a linear data structure that is similar with the **Doubly Linked List** data structure as well as a variation of the **Queue**. One thing that differentiates a Deque with a Queue is the way how a data is added or removed. Unlike Queues, that can only add a data at the back and remove the data in the front of the queue, Deques can add/remove data at the back or in the front.

## Basic Operation
* **isEmpty** - to check whether a Deque is empty or not.
* **pushFront** - to add a new data at the front.
* **pushBack** - to add new data at the back.
* **front** - to get the data located at the front.
* **back** - to get the data located at the back.
* **popFront** - to remove the data located at the front.
* **popBack** - to remove a data located at the back.

The **Time Complexity** for the above operations are constant O(1).

## Deque's Use Cases
Deques are commonly used to solve problems with a **Sliding Window** characteristic. On such problems, we need to remove both data located at the front and at the back. An example of a Sliding Window problem is to search the maximum value within a subarray with a certain size.

## ADT Implementation: `Deque`
[**A complete implementation of `Deque` can be accessed here.**](https://github.com/AlproITS/StrukturData/)

![Deque Visualization](https://raw.githubusercontent.com/wiki/AlproITS/StrukturData/img/m1-3.png)

As mentioned earlier, Deques can be implemented by modifying the **Doubly Linked List** data structure where two pointers, **`tail/rear`** is used to refer to the node located at the back and **`head/front`** to refer to the node located at the front.

* ### Node Representation
  Nodes within a Deque can be represented by a struct named `DListNode` that stores an `int` and a referenced to the next and previous nodes.
  ```c
  typedef struct dnode_t {
      int data;
      struct dnode_t      \
          *next,
          *prev;
  } DListNode;
  ```
* ### Deque Structure
  Deques have two pointers within their structures, that is `head` and `tail`.
  ```c
  typedef struct deque_t {
      DListNode           \
          *_head, 
          *_tail;
      unsigned _size;
  } Deque;
  ```
* ### isEmpty
  To check whether a Deque is empty or not, check whether both the `head` and `tail` are pointing to `NULL` or not.
  ```c
  bool deq_isEmpty(Deque *deque) {
      return (deque->_head == NULL && \
              deque->_tail == NULL);
  }
  ```
* ### pushFront
  to do a pushFront, do the following steps:
  * make a new node
  * if the Deque is empty, make that new node as the `head` and the `tail`.
  * if it is not, make the next of the new node points to the current `head` and the prev of the current `head` to the new node.
  * make the `head` points to the new node.
  ```c
  void deq_pushFront(Deque *deque, int value)
  {
      DListNode *newNode = __dlist_createNode(value);
      if (newNode) {
          deque->_size++;
          if (deq_isEmpty(deque)) {
              deque->_head = newNode;
              deque->_tail = newNode;
              return;
          }

          newNode->next = deque->_head;
          deque->_head->prev = newNode;
          deque->_head = newNode;
      }
  }
  ```
* ### pushBack
  Follow the following steps to do a pushBack.
  * make a new node.
  * if the Deque is empty, make the new node as both the `head` and the `tail`.
  * if it is not empty, make the prev of the new node to point at the current `tail` node, and the next of the current `tail` to point at the new node.
  * make the `tail` node to point at the new node.
  ```c
  void deq_pushBack(Deque *deque, int value)
  {
      DListNode *newNode = __dlist_createNode(value);
      if (newNode) {
          deque->_size++;
          if (deq_isEmpty(deque)) {
              deque->_head = newNode;
              deque->_tail = newNode;
              return;
          }

          deque->_tail->next = newNode;
          newNode->prev = deque->_tail;
          deque->_tail = newNode;
      }
  }
  ```
* ### front
  ```c
  int deq_front(Deque *deque) {
      if (!deq_isEmpty(deque)) {
          return (deque->_head->data);
      }
      return 0;
  }
  ```
* ### rear
  ```c
  int deq_back(Deque *deque) {
      if (!deq_isEmpty(deque)) {
          return (deque->_tail->data);
      }
      return 0;
  }
  ```
* ### popFront
  To do a popFront, follow these steps:
  * store the current `head` node within a temporary variable
  * make the 'head' to refer to the next of the current 'head'
  * remove the node within the temporary variable
  * if the `head` is empty, the the `tail` should be too.
  ```c
  void deq_popFront(Deque *deque)
  {
      if (!deq_isEmpty(deque)) {
          DListNode *temp = deque->_head;
          if (deque->_head == deque->_tail) {
              deque->_head = NULL;
              deque->_tail = NULL;
              free(temp);
          }
          else {
              deque->_head = deque->_head->next;
              deque->_head->prev = NULL;
              free(temp);
          }
          deque->_size--;
      }
  }
  ```
* ### popBack
  To do a popBack, follow these steps:
  * store the current `tail` within a temporary variable.
  * make the `tail` to refer to the prev of the current `tail`.
  * remove the node within the temporary variable
  * if the `tail` is empty, then the `head` should be too.
  ```c
  void deq_popBack(Deque *deque)
  {
      if (!deq_isEmpty(deque)) {
          DListNode *temp;
          if (deque->_head == deque->_tail) {
              temp = deque->_head;
              deque->_head = NULL;
              deque->_tail = NULL;
              free(temp);
          }
          else {
              temp = deque->_tail;
              deque->_tail = deque->_tail->prev;
              deque->_tail->next = NULL;
              free(temp);
          }
          deque->_size--;
      }
  }