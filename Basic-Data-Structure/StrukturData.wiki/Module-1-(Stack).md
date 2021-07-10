# Stack

## Terminology
* **Top** - the top node within a stack.

## Definition
Stack is a dynamic data structure that follows the **Last In First Out (LIFO)** principle. Under this principle, the last element to be inserted into a Stack will be the first element to be deleted when a function to delete a node is called. One way to visualize a Stack is by using a stack of plates, where every time a new plate is going to be placed, it will be located on the top of the stack.
![Visualization of a stack](https://raw.githubusercontent.com/wiki/AlproITS/StrukturData/img/m1-1.png)

## Basic Operation
* **isEmpty** - to check whether the given Stack is empty or not.
* **size** - to get the size data of the Stack.
* **push** - to add new data at the top.
* **pop** - to remove a data at the top.
* **top/peek** - to get the data at the top.

## Stack's Use Cases
One example of a Stack implementation is to convert an **infix** notation to a **postfix** one. **Infix** notation is a mathematical expression commonly used by human to solve mathematical problems, for example: **x + y / (10 + z)**. But, computers are not able to correctly understand such notation easily. In order to work around it, computers will convert such expression into a **postfix** notation, for example **x y + 10 z + /**. Where such conversion can happen thanks to the implementation of Stack data structure.

## ADT Implementation: `Stack` (Linked List Based)
[The full implementation of `Stack` can be accessed here.](https://github.com/AlproITS/StrukturData/)

Stack can be implemented by utilizing a **Singly Linked List** by treating the **head** on the Linked List as the **Top** of the Stack.

The **Time Complexity** of all operation on a Stack is done constantly O(1).

* ### Node Representation
  Nodes can be represented by a `struct` named StackNode that stores an `int` data and a reference to the next node `next`.
  ```c
  typedef struct stackNode_t {
      int data;
      struct stackNode_t *next;
  } StackNode;
  ```
* ### Stack Structure
  ```c
  typedef struct stack_t {
      StackNode *_top;
      unsigned _size;
  } Stack;
  ```
* ### isEmpty
  Checking whether a stack is empty or not can be done by checking whether the `top` of the stack is `NULL` or not.
  ```c
  bool stack_isEmpty(Stack *stack) {
      return (stack->_top == NULL);
  }
  ```
* ### push
  * make a new node
  * if the stack is empty, make that new node as the `top` of the stack
  * if the stack is not empty, set the previous stack's `top` as the new node's `next` and then make the new node as the new `top`.
  ```c
  void stack_push(Stack *stack, int value) 
  {
      StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
      if (newNode) {
          stack->_size++;
          newNode->data = value;
        
          if (stack_isEmpty(stack)) newNode->next = NULL;
          else newNode->next = stack->_top;

          stack->_top = newNode;
      }
  }
  ```
* ### pop
  to do a **pop**, in other words to remove the `top` of the stack, do the following steps:
  * Temporarily store the current `top` within a temporary node.
  * Refer to the next of the current `top` as the new `top`.
  * Free the memory of the temporary node to delete it.
  ```c
  void stack_pop(Stack *stack) 
  {
      if (!stack_isEmpty(stack)) {
          StackNode *temp = stack->_top;
          stack->_top = stack->_top->next;
          free(temp);
          stack->_size--;
      }
  }
  ```
* ### top
  ```c
  int stack_top(Stack *stack) 
  {
      if (!stack_isEmpty(stack)) 
          return stack->_top->data;
      return 0;
  }
  ```