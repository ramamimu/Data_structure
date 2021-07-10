# Linked List

## Terminology

Before going into the definition, there are some terms that are frequently used in describing a linked list. 

- **Node** – A node represents one data element that can contain a value and/or other information needed, as well as its relations/reference to another node. 
- **Head** – is the first node of a linked list. 
- **Tail** – is the last node of a linked list. 

## Definisi

**Linked List** is a data structure that can store data linearly, in which these datas are represented by a collection of nodes that are sequential. Fundamentally, a node in a linked list consists of: 

- Data to be stored
- Reference (link) to the next node

Illustration of a node in a linked list. 

![](img/m0-3.png)

**Characteristics**

Linked list is a dynamic data structure, meaning that the size of one can change accordingly to the number of data that are being added, unlike Static Array. However, the data in a linked list cannot be accessed randomly like accessing an index of an array. To access the data, the linked list needs to go through a traversing process first. 

## Illustration

Linked list can be illustrated as a collection of nodes that are linked to each other sequentially, creating a chain of sequence. For example, a list 𝐴 with a set of data such as 𝐴 = [2,3,6,11,13].

![](img/m0-4.png)

## Basic Operation

- **isEmpty** - to check whether a list is empty or not.
- **pushBack** - to insert new data from the back of the list. 

    ![](img/m0-5.png)

- **pushFront** - to insert new data from the front of the list. 

    ![](img/m0-6.png)

- **insertAt** - to insert new data at the desired position. 

    ![](img/m0-7.png)

- **back** - to retrieve data from the back of the list. 

- **front** - to retrieve data from the front of the list. 

- **getAt** - to retrieve data from a certain position. 

- **popBack** - to remove data from the back of the list. 

    ![](img/m0-8.png)

- **popFront** - to remove data from the front of the list. 

    ![](img/m0-9.png)

- **remove(x)** - to remove data x that shows up first in the list. 

    ![](img/m0-10.png)


## Linked List Variations

- ### Singly-Linked List

    Node in a **Singly-Linked List** can only store a reference/link to the next node. Usually this reference is represented by the variable **`next`**.

    ![](img/m0-13.png)

- ### Doubly-Linked List

    In a **Doubly-Linked List**, each node has two references/link, which are a link that points towards the next node, and one towards to previous node. These two references/links usually are called as **`next`** and **`prev`** (previous)

    ![](img/m0-12.png)

![](img/memelist.jpg)

## ADT Implementation: **`SinglyList`**

[**Complete implementation of `SinglyList` can be accessed here**](https://github.com/AlproITS/StrukturData/)

This a representation and implementation of a **Singly Linked List** that stores the int data type. This representation will be brought in the shape of an Abstract Data Type (ADT) that will become a new data type called SinglyList. 

![](img/m0-11.png)

Here is the list of time complexity in this implementation:

**Operation**|**Function**|**Time complexity**
-----|-----|-----
pushBack|Inserting new data from the back.|O(N)
pushFront|Inserting new data from the front.|O(1)
insertAt|Inserting new data at a certain position.|O(N) (Worst-case)
popBack|Removing node from the back.|O(N)
popFront|Removing node from the front.|O(1)
remove(x)|Removing first data with the value x.|O(N) (Worst-case)
front|Retrieving value of the first node.|O(1)
back|Retrieving value of the last node.|O(N)
getAt|Retrieving value of a node at a certain position|O(N) (Worst-case)
isEmpty|Checking whether the list is empty or not.|O(1)

- ### Node Representation

    Nodes can be represented by a **`struct`** named `SListNode` that stores the `data` variable (with an `int` data type), and is referenced to the next node, that is `next`. 
    
    ![](img/m0-13.png)

    ```c
    typedef struct snode_t {
        int data;
        struct snode_t *next;
    } SListNode;
    ```

- ### SinglyList Structure

    ```c
    typedef struct slist_t {
        unsigned _size;
        SListNode *_head;
    } SinglyList;
    ```

- ### isEmpty

    To check if the list is empty or not, check whether the **`head``** of the list has a `NULL` value or not. 

    ```c
    bool slist_isEmpty(SinglyList *list) {
        return (list->_head == NULL);
    }
    ```

- ### pushBack

    Generally, the steps to do a **pushBack** are as follows: 

    + Create a new node
    + If it's an empty list, then it's clear that the **`head`** is the new node. 
    + If the list is not empty, search through the entire list until the end, and point the last node to the new node. This process of searching can be done with the help of a temporary variable which is **`temp`**.

    ```c
    void slist_pushBack(SinglyList *list, int value)
    {
        SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
        if (newNode) {
            list->_size++;
            newNode->data = value;
            newNode->next = NULL;
            
            if (slist_isEmpty(list)) 
                list->_head = newNode;
            else {
                SListNode *temp = list->_head;
                while (temp->next != NULL) 
                    temp = temp->next;
                temp->next = newNode;
            }
        }
    }
    ```

- ### pushFront

    To do a **pushFront**, the steps are as follows. 

    + Create a new node.
    + If the list is empty, make the new node as **`head`**. 
    + If the list is not empty, then it's clear that **`next`** from the new node is **`head`**. 

    ```c
    void slist_pushFront(SinglyList *list, int value) 
    {
        SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
        if (newNode) {
            list->_size++;
            newNode->data = value;
            
            if (slist_isEmpty(list)) newNode->next = NULL;
            else newNode->next = list->_head;
            list->_head = newNode;
        }
    }
    ```

- ### insertAt

    The **insertAt** operation has a pretty complicated process. There are some cases that needs to be examined. 

    **Case 1: index is 0**

    + Simply do a **pushFront** and done. 

    **Case 2: index is at the end**

    + Simply do a **pushBack** and done. 

    **Case 3: index is at the middle**

    + Create a new node.
    + With the help of **`temp`** variable, do a traversal until it reaches the position of node at `index`-1. 
    + Point **`next`** from the new node towards the next node from the last node of the search result.
    + Connect the node from the traversal result with the new node.  

    ```c
    void slist_insertAt(SinglyList *list, int index, int value)
    {
        if (slist_isEmpty(list) || index >= list->_size) {
            slist_pushBack(list, value);
            return;    
        }
        else if (index == 0) {
            slist_pushFront(list, value);
            return;
        }
        
        SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
        if (newNode) {
            SListNode *temp = list->_head;
            int _i = 0;
            
            while (temp->next != NULL && _i < index-1) {
                temp = temp->next;
                _i++;
            }
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
            list->_size++;
        }
    }
    ```

- ### back

    Simply traverse until the end and return the value. 

    ```c
    int slist_back(SinglyList *list)
    {
        if (!slist_isEmpty(list)) {
            SListNode *temp = list->_head;
            while (temp->next != NULL) 
                temp = temp->next;
            return temp->data;
        }
        return 0;
    }
    ```

- ### front

    Use the value from **`head`**. 

    ```c
    int slist_front(SinglyList *list)
    {
        if (!slist_isEmpty(list)) {
            return list->_head->data;
        }
        return 0;
    }
    ```

- ### getAt

    These are some steps to do a **getAt**:

    + Do a traversal and take record of the indexes. 
    + When the traversal reaches the desired index, return the node value. 

    ```c
    int slist_getAt(SinglyList *list, int index)
    {
        if (!slist_isEmpty(list)) {
            SListNode *temp = list->_head;
            int _i = 0;
            while (temp->next != NULL && _i < index) {
                temp = temp->next;
                _i++;
            }
            return temp->data;
        }
        return 0;
    }
    ```

- ### popBack

    These are some steps to do a **popBack**:

    + Do a traversal with the help of two nodes - **`nextNode`** (next node) and **`currNode`** (current node).
    + If `next` from **`currNode`** is empty, then there is only one data. The node will be erased immediately. 
    + Do a traversal until the end. 
    + When it reaches the end, remove the reference from current node (`currNode`).
    + Erase the next node (`nextNode`)

    ```c
    void slist_popBack(SinglyList *list)
    {
        if (!slist_isEmpty(list)) {
            SListNode *nextNode = list->_head->next;
            SListNode *currNode = list->_head;

            if (currNode->next == NULL) {
                free(currNode);
                list->_head = NULL;
                return;
            }

            while (nextNode->next != NULL) {
                currNode = nextNode;
                nextNode = nextNode->next;
            }
            currNode->next = NULL;
            free(nextNode);
            list->_size--;
        }
    }
    ```

- ### popFront

    These are some steps to do a **popFront**:

    + Store `head` in `temp` (a temporary variable).
    + Change **`head`** with reference/next from `head`
    + Erase the `temp` node. 

    ```c
    void slist_popFront(SinglyList *list)
    {
        if (!slist_isEmpty(list)) {
            SListNode *temp = list->_head;
            list->_head = list->_head->next;
            free(temp);
            list->_size--;
        }
    }
    ```

- ### remove(x)

    To do a **remove(x)**, which is essentially erasing data x that is found first, do the steps as follows. 

    **Case 1: Data being erased is found at the front**

    + Simply do a **popFront** and then it's done. 

    **Case 2: Data being erased is not found at the front**

    + Do a traversal to check whether the data in the search node is the same as the one to be erased. During the search, take record of the previous node (**`prev`**) and current node (**`temp`**). 
    + When the date is found, stop the traversal. 
    + Connect the **`prev`** node with the `next` from the current node. 
    + Remove current node (`temp`)

    **Case 3: Data is not found**

    + When the traversal is stopped, check whether the node has a **`NULL`** value or not. If it has a `NULL` value, it can be determined that the data is not found. 

    ```c
    void slist_remove(SinglyList *list, int value)
    {
        if (!slist_isEmpty(list)) {
            SListNode *temp, *prev;
            temp = list->_head;

            if (temp->data == value) {
                slist_popFront(list);
                return;
            }
            while (temp != NULL && temp->data != value) {
                prev = temp;
                temp = temp->next;
            }

            if (temp == NULL) return;
            prev->next = temp->next;
            free(temp);
            list->_size--;
        }
    }
    ```

