#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

using namespace std;

int high=0;

typedef struct AVLNode_t
{
    int data;
    struct AVLNode_t *left,*right;
}AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
    unsigned int _size;
}AVL;

void avl_init(AVL *avl) {
    avl->_root=NULL;
    avl->_size = 0u;
}

AVLNode* _avl_createNode(int value) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

AVLNode* _search(AVLNode *root, int value) {
    while (root != NULL) {
        if (value < root->data)
            root = root->left;
        else if (value > root->data)
            root = root->right;
        else
            return root;
    }
    return root;
}


AVLNode* _insert_AVL(AVL *avl,AVLNode* node,int value) {

    if(node==NULL) // udah mencapai leaf
        return _avl_createNode(value);
    if(value < node->data)
        node->left = _insert_AVL(avl,node->left,value);
    else if(value > node->data)
    	node->right = _insert_AVL(avl,node->right,value);

    return node;
}

bool avl_isEmpty(AVL *avl) {
    return avl->_root == NULL;
}

bool avl_find(AVL *avl, int value) {
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;

    if (temp->data == value)
        return true;
    else
        return false;
}

void avl_insert(AVL *avl,int value){
    if(!avl_find(avl,value)){
        avl->_root=_insert_AVL(avl,avl->_root,value);
        avl->_size++;
    }
}

bool f1Possibility(AVLNode *root, int num)
{
    if(root->right != NULL)
    {
        if(root->right->left != NULL)
        {
            if(root->data + root->right->data + root->right->left->data == num)
                return true;
        }
    }
    return false;
}

bool s2Possibility(AVLNode *root, int num)
{
    if(root->right != NULL)
    {
        if(root->right->right != NULL)
        {
            if(root->data + root->right->data + root->right->right->data == num)
                return true;
        }
    }
    return false;
}

bool t3Possibility(AVLNode *root, int num)
{
    if(root->right != NULL)
    {
        if(root->left != NULL)
        {
            if(root->data + root->right->data + root->left->data == num)
                return true;
        }
    }
    return false;
}

bool f4Possibility(AVLNode *root, int num)
{
    if(root->left != NULL)
    {
        if(root->left->right != NULL)
        {
            if(root->data + root->left->data + root->left->right->data == num)
                return true;
        }
    }
    return false;
}

bool f5Possibility(AVLNode *root, int num)
{
    if(root->left != NULL)
    {
        if(root->left->left != NULL)
        {
            if(root->data + root->left->data + root->left->left->data == num)
                return true;
        }
    }
    return false;
}

bool isYes=false;
void __inorder(AVLNode *root, int num) {
    if (root) {
        if(f1Possibility(root, num))
            isYes=true;
        if(s2Possibility(root, num))
            isYes=true;
        if(t3Possibility(root, num))
            isYes=true;
        if(f4Possibility(root, num))
            isYes=true;
        if(f5Possibility(root, num))
            isYes=true;
    
        __inorder(root->left, num);

        __inorder(root->right, num);
        
    }
}

int main()
{
    AVL avlku;
    avl_init(&avlku);
    
    int n, NODE;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>NODE;
        avl_insert(&avlku, NODE);
    }
    int num;
    cin>>num;
   __inorder(avlku._root, num);
    
    if (isYes)
        cout<<"Penjumlahan angka di tree yang menghasilkan "<<num<<" ditemukan\n";
    else
        cout<<"Tidak ditemukan penjumlahan angka di tree yang menghasilkan "<<num<<endl;

    return 0;
}