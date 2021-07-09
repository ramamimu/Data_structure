#include <bits/stdc++.h>
using namespace std;

typedef struct AVLNode_t
{
    int data;
    struct AVLNode_t *left,*right;
    int height;
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
    newNode->height=1;
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

AVLNode *first, *second;
int pernah=0;
void peekOrder(AVLNode *root, int l, int r) {
    if (root) 
    { 
        int numb=root->data;
        if((numb == l) || (numb == r))
        {
            if(first==NULL)
                first=root;
            else
            {
                second=root;
            return;
            }
        }
        peekOrder(root->left, l, r);
        peekOrder(root->right, l, r);
    }
}


// stack process

typedef struct stackNode_t {
    AVLNode *alamat;
    struct stackNode_t *next;
} StackNode;

typedef struct {
    StackNode *_top;
    unsigned _size;
} Stack;

Stack path;

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, AVLNode *value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->alamat = value;

        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

AVLNode* stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->alamat;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}
// batas stack

// queue process

typedef struct node
{
    AVLNode *qi;
    node *next;
}Queue;

Queue *head;

void initQue()
{
    head=NULL;
}

void popFront()
{
    if(head != NULL)
    {
        Queue *temp=head;
        head=head->next;
        free(temp);
    }
}

void queue_push(AVLNode *data)
{
    Queue *newNode = (Queue*) malloc(sizeof(Queue));
    if (newNode) {
        newNode->qi = data;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else {
            Queue *temp = head;
            while(temp->next != NULL)
            {
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
}

void level(AVLNode *root)
{
    if(root){
        initQue();
        stack_init(&path);
        queue_push(root);
        stack_push(&path, root);
        while(head != NULL)
        {
            if(head->qi->right != NULL)
            {
                queue_push(head->qi->right);
                stack_push(&path, head->qi->right);
            }
            if(head->qi->left != NULL)
            {
                queue_push(head->qi->left);
                stack_push(&path, head->qi->left);
            }
            popFront();
        }
    }
}

//BATAS QUEUE

int sum=0;
AVLNode *jagoanNeon;
void jalanJalan(AVLNode *root) {
    if (root) {
        sum+=root->data;
        jalanJalan(root->left);
        jalanJalan(root->right);
    }
}

void redefine ()
{
    first=NULL;
    second=NULL;
    jagoanNeon=NULL;
    sum=0;
}

void printStack(Stack *haha)
{
    StackNode *temp=haha->_top;
    while(temp!=NULL)
    {
        temp=temp->next;
    }
}

AVLNode* eh(AVLNode *avl, int comparison)
{    
    while (avl != NULL) {
        if (comparison < avl->data)
            avl = avl->left;
        else if (comparison > avl->data)
            avl = avl->right;
        else
            return avl;
    }
    return avl;
}

bool avl_findDewe(AVLNode *avl, AVLNode *value) {
    AVLNode *temp = eh(avl, value->data);

    if (temp == NULL)
        return false;
    
    if (temp->data == value->data)
        return true;
    else
        return false;
}

void cari(Stack *haha)
{

    StackNode *temp=haha->_top;
    while(temp!=NULL)
    {
        if(avl_findDewe(temp->alamat, first) && avl_findDewe(temp->alamat, second))
        {
            jagoanNeon=temp->alamat;
            return;
        }
        temp=temp->next;
    }
}

int main(){
    AVL avlku;
    avl_init(&avlku);

    int n, q;
    cin>>n>>q;
    
    int node;
    for(int i=0; i<n; i++)
    {
        cin>>node;
        avl_insert(&avlku,node);
    }
    level(avlku._root);
    int l, r;
    for(int i=0; i<q; i++)
    {
        cin>>l>>r;
        if(avl_find(&avlku, l) && avl_find(&avlku, r))
        {
            redefine();
            peekOrder(avlku._root, l, r);
            cari(&path);
            jalanJalan(jagoanNeon);
            cout<<sum<<endl;
        }
        else
            cout<<"-1"<<endl;
    }
}