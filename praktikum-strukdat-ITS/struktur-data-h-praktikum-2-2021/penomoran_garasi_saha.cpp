#include <bits/stdc++.h>
using namespace std;

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

int high=0;

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

// stack process

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

typedef struct {
    StackNode *_top;
    unsigned _size;
} Stack;

Stack minStack;
Stack maxStack;

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

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

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
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

int findMax()
{
    Queue *temp=head;
    int maximum=0;
    while(temp!=NULL)
    {
        maximum=max(maximum, temp->qi->data);
        temp=temp->next;
    }
    return maximum;
}

int findMin()
{
    Queue *temp=head;
    int minimum=100005;
    while(temp!=NULL)
    {
        minimum=min(minimum, temp->qi->data);
        temp=temp->next;
    }
    return minimum;
}

void level(AVLNode *root)
{
    if(root){
        initQue();
        stack_init(&minStack);
        stack_init(&maxStack);

        int tanda1=0;
        int tanda2=0;
        queue_push(root);
        stack_push(&minStack, root->data);
        stack_push(&maxStack, root->data);
        while(head != NULL)
        {
            if(head->qi->left != NULL)
            {
                tanda2++;
                queue_push(head->qi->left);
            }
            if(head->qi->right != NULL)
            {
                tanda2++;
                queue_push(head->qi->right);
            }
            popFront();
            if(tanda1==0)
            {
                int purple=findMax();
                int pineapple=findMin();
                stack_push(&minStack, purple);
                stack_push(&maxStack, pineapple);
                tanda1=tanda2;
                tanda2=0;
                high++;
            }
            tanda1--;
        }
    }
}

void callStack(int tanda)
{
    StackNode *temp1 = minStack._top;
    StackNode *temp2 = maxStack._top;

    if(tanda%2==0)
        cout<<temp1->data<<' ';
    else
        cout<<temp2->data<<' ';

    minStack._top=minStack._top->next;
    maxStack._top=maxStack._top->next;
    free(temp1);
    free(temp2);

}


int main(){
    AVL avlku;
    avl_init(&avlku);

    int n, node;
    cin>>n;
    for(int i=0; i<n; i++)
	{
		cin>>node;
		avl_insert(&avlku,node);
	}
	level(avlku._root);

    minStack._top=minStack._top->next;
    maxStack._top=maxStack._top->next;

    int index=0;
    while(minStack._top != NULL)
        callStack(++index);
}
