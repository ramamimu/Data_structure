# Binary Search Tree

**Binary Search Tree (BST)** is a node based Binary Tree data structure with properties such as: 

- The left subtree of a node contains only nodes with keys lesser than the node’s key.
- The right subtree of a node contains only nodes with keys greater than the node’s key.
- The left and right subtree each must also be a binary search tree.

![](img/bst-vs-not-bst.jpg)

> source: https://cdn.programiz.com/sites/tutorial2program/files/bst-vs-not-bst.jpg

## binary Search Tree Implementation

[**Complete implementation of `Binary Seach Tree` can be seen here**](https://github.com/AlproITS/StrukturData/)

### Node Representation

**A node** on a Binary Search Tree essentially has these properties: 

- Data or _key_ to store,
- Reference to the left node, and
- Reference to the right node.

```c
typedef struct bstnode_t {
    int key;
    struct bstnode_t \
        *left, *right;
} BSTNode;
```

### BST structure

```c
typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;
```

- ### Find

    There are two ways to check for a key on a BST: by recursive or iterative. The implementation mentioned uses the iterative method. 
    **Utility Function**
    ```c
    BSTNode* __search(BSTNode *root, int value) {
        while (root != NULL) {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }
    ```

    **Primary Function**
    ```c
    bool bst_find(BST *bst, int value) {
        BSTNode *temp = __search(bst->_root, value);
        if (temp == NULL)
            return false;
        
        if (temp->key == value)
            return true;
        else
            return false;
    }
    ```
    **Exampleh**

    ![](img/bst-search.jpg)
    > Source: https://cdn.programiz.com/sites/tutorial2program/files/bst-search-downward-recursion-step.jpg

- ### Insert

    New key always gets added underneath a leaf node. We need to check each keys from the root node until we can identify the node leaf. Once this node leaf is found, the new node can be added as a child to the previously said node leaf. 
    **Utility Function**
    ```c
    BSTNode* __insert(BSTNode *root, int value) {
        if (root == NULL) 
            return __createNode(value);

        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);
        
        return root;
    }
    ```

    **Primary Function**
    ```c
    void bst_insert(BST *bst, int value) {
        if (!bst_find(bst, value)) {
            bst->_root = __bst__insert(bst->_root, value);
            bst->_size++;
        }
    }
    ```
    **Example**

    ![](img/bst-insert.jpg)
    > Source: https://cdn.programiz.com/sites/tutorial2program/files/bst-downward-recursion-step.jpg

- ### Remove

    **Utility Function**

    FindMinNode :

    ```c
    BSTNode* __findMinNode(BSTNode *node) {
        BSTNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        
        return currNode;
    }
    ```

    Remove :

    ```c
    BSTNode* __remove(BSTNode *root, int value) {
        if (root == NULL) return NULL;

        if (value > root->key) 
            root->right = __remove(root->right, value);
        else if (value < root->key) 
            root->left = __remove(root->left, value);
        else {
            
            if (root->left == NULL) {
                BSTNode *rightChild = root->right;
                free(root);
                return rightChild;
            }
            else if (root->right == NULL) {
                BSTNode *leftChild = root->left;
                free(root);
                return leftChild;
            }

            BSTNode *temp = __findMinNode(root->right);
            root->key     = temp->key;
            root->right   = __remove(root->right, temp->key);
        }
        return root;
    }
    ```

    **Primary Function**

    ```c
    void bst_remove(BST *bst, int value) {
        if (bst_find(bst, value)) {
            bst->_root = __bst__remove(bst->_root, value);
            bst->_size--;
        }
    }
    ```

## Skewed Tree

If the order of the insertion is 1 2 3 4 5 6 7, the form of the tree will look like the picture below. This kind of tree is called a **Skewed Tree**. 
![](img/m2-1.png)

> Binary Search Tree will become _skewed_ if the insertion order is already a sorted sequence (ascending or descending). Skewed BST is the most unbalanced type of BST. 

The insertion order on a BST will affect the tree's form/shape. For example, if the insertion order is 5 2 1 4 3 6 7, the tree shape will become like the picture below:
![](img/m2-2.png)



