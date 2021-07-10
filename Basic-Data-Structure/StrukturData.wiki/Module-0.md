# Introduction to Data Structures

## What are Data Structures?

Data Structure is a way of organizing and managing data in such a way that efficient access and modifications can be achieved. It is about a collection of values (data), how they are connected, and operations that can be implemented on them.

## Getting to Know Abstract Data Types (ADT)

_**Abstract Data type**_, (ADT) is a type for objects whose behavior is defined by a set of value and a set of operations. ADT is an abstract interface of data that doesn't specify how it is implemented to the user.

Suppose an integer. Integer is an ADT that can be assigned the values ..., -2, -1, 0, 1, 2, ... and is associated with operations like addition, subtraction, multiplication, division, etc. be implemented. User doesn't have to know how an integer value is implemented by the computer. The only thing a user needs to know is that **there exist integers**.


### ADT vs Data Structures

- ADT is a logical description of what the data structure of a set of values is.
- Data Structure is the concrete implementation of an ADT.


**Analogy**

A _vehicle_ is an ADT. A _vehicle_ can be of many forms (_data structures_); a car, a train, a bus, etc.


### Common ADTs

**Abstract Data Type**|**DS Implementations**
-----|-----
List|Dynamic Array/Linked List
Stack|Linked List/Dynamic Array
Queue|Linked List/Dynamic Array
Bitset|Dynamic/Static Array
Priority Queue|Linked List
Set and Map|Balanced Binary Search Tree (AVL Tree)
(Unordered) Set and Map|Hash Table
Graph|Directed/Undirected Graph

## Data Structure Types

In general, data structures are categorized based on how they store values/data. There are two types: Linear Data Structures and Non-linear Data Structures.

- ### Linear Data Structures

A linear data structure stores data in a sequential order (one after another). An example often encountered is **arrays**. Other examples are **linked lists**, **stacks**, and **queues**.

- ### Non-Linear Data Structures

On the contrary, a non-linear data structure organizes data in a hierarchical structure based on certain rules. Examples of non-linear data structure usage are **trees** and **graphs**.

# "Big-O" Notation

The complexity of an algorithm is determined by multiple factors. For now, we're going to discuss on scaling algorithm complexity based on runtime. The common notation for this is called **Big-O**. In a big-O notation, the determinant variable is notated as _N_.

## Examples

**Complexity**|**Term**|**Example**
-----|-----|-----
O(1)|Constant Time|Running time is constant no matter how big the data size is. Example: accessing an array element.
O(N)|Linear Time|Running time is proportional to the amount of data. Example: performing linear search.
O(log N)|Logarithmic Time|Usually happens to algorithms that partition a problem into sub-problems. Example: binary search.
O(N log N)|Linearithmic Time|Example: performing Merge Sort.
O(N<sup>2</sup>)|Quadratic Time|Example: performiing Bubble Sort.
O(2<sup>N</sup>)|Exponential Time|Example: finding all subsets of a set requires a running time of 2<sup>N</sup>.
O(N!)|Factorial Time|Example: finding all permutations of a string of length N.

[**To Dynamic Array >**](https://github.com/AlproITS/StrukturData/wiki/Module-0-(Dynamic-Array))