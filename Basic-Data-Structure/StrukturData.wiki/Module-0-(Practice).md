# Practice

## Problem 1 (Linked List)

Implement a new function named **`forEachElement`** for **Linked List** (it can be applied on Singly Linked List or Doubly Linked List). The **`forEachElement`** function can act as an iterator for each element from the beginning until the end inside a **`Linked List`**, in which each element will be subjected to another operation/function for certain purposes.  

For example, the **`forEachElement`** function is used to print every element inside a linked list. 

**Example of the Implementation:**

```c
#include <stdio.h>
#include <stdlib.h>

/*
Linked list
.
.
*/

void printElement(int *elem) {
    .
    .
}

void multiply2(int *elem) {
    .
    .
}

int main()
{
    List myList;
    dlist_init(&myList);

    // Suppose that the values inside the linked list is [1,2,3,4,5]
    // .
    // .
    // .

    // example of the forEachElement function that prints data from the list

    forEachElement(&myList, printElement);

    // example of the forEachElement function that multiplies each element
    // with 2

    forEachElement(&myList, multiply2);

    // values contained in the list are now [2,4,6,8,10]
    return 0;
}
```

Then, test the **`forEachElement`** that you have made with these functions: 

- reverseEach -- to reverse a number. 
- sumDigit -- to replace an element with the sums of all digits of each number. 

## Problem 2 (DynamicArray)

> This implementation needs to refer to the implementation on the Github. 

Create function implementations of **`dArray_insertAt`** and **`dArray_removeAt`** that will be used to insert new elements at the desired position and to remove elements at the desired position. The function prototype is as follows: 

```c
void dArray_insertAt(DynamicArray *darray, unsigned index, int value);
void dArray_removeAt(Dynamic *darray, unsigned index);
```

- **`index`** is the desired position/index. 
- **`value`** is the new value that is going to be inserted. 

## Problem 3 (Linked List/Dynamic Array)

Modify the Dynamic Array and Linked List (SinglyList) codes on this github to be able to save **string** type (assume that the length of a string is at most 100 characters) 



