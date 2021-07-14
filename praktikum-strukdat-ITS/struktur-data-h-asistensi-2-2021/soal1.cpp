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
    avl->_root = NULL;
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

void __inorder(AVLNode *root) {
    if (root) {
        __inorder(root->left);
        printf("%d ", root->data);
        __inorder(root->right);
    }
}

void __postorder(AVLNode *root) {
    if (root) {
        __postorder(root->left);
        __postorder(root->right);
        printf("%d ", root->data);
    }
}

void preorder(AVLNode *root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

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
        queue_push(root);
        while(head != NULL)
        {
            cout<<head->qi->data<<' ';            
            if(head->qi->left != NULL)
            {
                queue_push(head->qi->left);
            }
            if(head->qi->right != NULL)
            {
                queue_push(head->qi->right);
            }
            popFront();
        }
    }
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

	cout<<"in order \t: ";
	__inorder(avlku._root);

	cout<<endl<<"post order \t: ";
	__postorder(avlku._root);

	cout<<endl<<"pre order \t: ";
	preorder(avlku._root);

	cout<<endl<<"level order \t: ";
	level(avlku._root);
}
