#include<bits/stdc++.h>

using namespace std;

typedef struct bstnode_t {
    int key;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* _bst_createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* _bst_insert(BSTNode *root, int value){
    if (root == NULL)
        return _bst_createNode(value);

    if (value < root->key)
        root->left = _bst_insert(root->left, value);
    else if (value > root->key)
        root->right = _bst_insert(root->right, value);

    return root;
}

BSTNode* _bst_search(BSTNode *root, int value){
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

BSTNode* _bst_findMinNode(BSTNode *node){
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;

    return currNode;
}

BSTNode* _bst_remove(BSTNode *root, int value){
    if (root == NULL) return NULL;

    if (value > root->key)
        root->right = _bst_remove(root->right, value);
    else if (value < root->key)
        root->left = _bst_remove(root->left, value);
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

        BSTNode *temp = _bst_findMinNode(root->right);
        root->key     = temp->key;
        root->right   = _bst_remove(root->right, temp->key);
    }
    return root;
}

void _bst_inorder(BSTNode *root){
    if (root) {
        _bst_inorder(root->left);
        printf("%d ", root->key);
        _bst_inorder(root->right);
    }
}

void _bst_postorder(BSTNode *root){
    if (root) {
        _bst_postorder(root->left);
        _bst_postorder(root->right);
        printf("%d ", root->key);
    }
}

void _bst_preorder(BSTNode *root){
    if (root) {
        printf("%d ", root->key);
        _bst_preorder(root->left);
        _bst_preorder(root->right);
    }
}

void bst_init(BST *bst){
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst){
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value){
    BSTNode *temp = _bst_search(bst->_root, value);
    if (temp == NULL)
        return false;

    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value){
    if (!bst_find(bst, value)) {
        bst->_root = _bst_insert(bst->_root, value);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value){
    if (bst_find(bst, value)) {
        bst->_root = _bst_remove(bst->_root, value);
        bst->_size--;
    }
}

void bst_inorder(BST *bst){
    _bst_inorder(bst->_root);
}

void bst_postorder(BST *bst){
    _bst_postorder(bst->_root);
}

void bst_preorder(BST *bst){
    _bst_preorder(bst->_root);
}


int _get_height(BSTNode *root){
    if (root == NULL)
        return 0;
    return 1 + max(_get_height(root->left), _get_height(root->right));
}

int height(BST *bst){
    return _get_height(bst->_root);
}

void check_node(BSTNode *root, BST *list, int currentLevel, int find, deque<int> *row)
{
    if(root == NULL)
        return;
    check_node(root->left, list, currentLevel+1, find, row);
    if(currentLevel == find)
        row->push_back(root->key);
    check_node(root->right, list, currentLevel+1, find, row);
}

void __level_check(BST *bst, BST *list, int height){
    int i;
    for (i=1; i<=height; i++){
        deque<int> row;
        check_node(bst->_root, 0, i, height+1, &row);
        bst_insert(list, row.front());
        if(!row.empty())
            bst_insert(list, row.back());
    }
}

void __bottom_check(BSTNode *root, BST *list){
    if (root){
        __bottom_check(root->left, list);
        if(root->left == NULL && root->right == NULL)
            bst_insert(list, root->key);
        __bottom_check(root->right, list);
    }
}

void __remove(BSTNode *root, BST *bst){
    if (root){
        __remove(root->left, bst);
        bst_remove(bst, root->key);
        __remove(root->right, bst);
    }
}

int main(){
    BST mytree, list_remove;
    bst_init(&mytree);
    bst_init(&list_remove);
    int n;
    cin >> n;
    while(n--)
    {
        int  input;
        cin >> input;
        bst_insert(&mytree, input);
    }
    bst_insert(&list_remove, mytree._root->key);
    __bottom_check(mytree._root, &list_remove);
    __level_check(&mytree, &list_remove, height(&mytree)+1);
    __remove(list_remove._root, &mytree);
    if(bst_isEmpty(&mytree)){
        cout << "Yah, gk ada posisi yang aman :(" << endl ;
    }
    else{
        bst_inorder(&mytree);
    }
    return 0;
}
