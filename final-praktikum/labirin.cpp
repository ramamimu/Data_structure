#include <bits/stdc++.h>

using namespace std;
/**
 * Node structure and
 * uniqueBST structure
 */

 #define BUGG(n) cout<<"masuk "<<n<<endl;
 
int **arr;
// vector <int> leaf;
int *leaf;
int maxArrNumb=0;

//BFS
typedef struct
{
    int f1Node;
    int s2Node;
    int pBatang;
} Node;

/* Struktur Node */

typedef struct queueNode_t {
    int data;
    int pathWay;
    struct queueNode_t *next;
} QueueNode;

/* Struktur ADT Queue */

typedef struct queue_t {
    QueueNode   *_front, 
                *_rear;
    unsigned _size;
} Queue;

void queue_init(Queue *queue)
{
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, int value, int path)
{
    // BUGG(2);
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
    // BUGG(3);
        queue->_size++;
        newNode->data = value;
        newNode->pathWay = path;
        newNode->next = NULL;
    // BUGG(4);
        
        if (queue_isEmpty(queue))                 
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
    // BUGG(5);
}

void queue_pop(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);
        
        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}

int queue_front(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        return (queue->_front->data);
    }
    return (int)0;
}

int queue_size(Queue *queue) {
    return queue->_size;
}
// BATAS QUEUE

int titik, batang;

Queue choice, isiNode;

void cariDaun(int cari, Node input[], int index, Queue *daun)
{
    int jumlah =0;
    //input 1
    for(int i=0; i<index; i++)
    {
        if(cari==input[i].f1Node)
            jumlah++;
        if(cari==input[i].s2Node)
            jumlah++;
    }

    if(jumlah==1 && cari!=0)
        queue_push(daun, cari, 0);
}

bool find_leaf(Queue *daun, int cari)
{
    QueueNode *temp=daun->_front;
    while(temp != NULL)
    {
        if(temp->data == cari)
            return true;
        temp=temp->next;
    }
    return false;
}

void simple_Q(Queue *last, int root, int path)
{
    if(queue_isEmpty(last))
        queue_push(last, root, path);
    else
    {
        if(last->_front->pathWay >= path)
        {
            if(last->_front->pathWay == path)
            {
                if(last->_front->data > root)
                    last->_front->data = root;
            }
            else
            {
                last->_front->data=root;
                last->_front->pathWay=path;
            }
        }
    }
}

bool available(int root)
{
    // BUGG(11);
    // cout<<root<<endl;
    // cout<<maxArrNumb<<endl;
    for(int i=0; i<maxArrNumb; i++)
    {
    // BUGG(12);
        if(arr[root][i]!=0)
        {    
            return true;
        }
    }
    return false;
}

int get_min(int root)
{
    int maximum=INT_MAX;
    for(int i=0; i<maxArrNumb; i++)
    {
        if(arr[root][i]!=0 && arr[root][i]<maximum)
        {    
            maximum=arr[root][i];
        }
    }
    return maximum;
}

int get_index(int root, int path)
{
    for(int i=0; i<maxArrNumb; i++)
    {
        if(arr[root][i]==path)
        {    
            return i;
        }
    }
    return 0;
}


void push_kusus(Queue *queue, int value, int path)
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    queue->_size++;
    newNode->data = value;
    newNode->pathWay = path;
    newNode->next = NULL;
    
    if (queue_isEmpty(queue))                 
        queue->_front = queue->_rear = newNode;
    else {
        if(queue->_front->data == value)
        {
            if(queue->_front->pathWay > path)
                queue->_front->pathWay=path;
            return;
        }
        else
        {
            QueueNode *temp = queue->_front;
            while(temp->next != NULL)
            {
                if(temp->data == value)
                {
                    if(temp->pathWay > path)
                        temp->pathWay = path;
                    return;
                }
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
}

void  process( int cari, int res)
{
    if(!queue_isEmpty(&isiNode))
    {
        // BUGG(1);
        while(available(cari))
        {
        // BUGG(2);
            int numb_path=get_min(cari);
            int index=get_index(cari, numb_path);
            // BUGG(index);
            // BUGG(leaf[index]);
            // cout<<"batas\n";
            if(leaf[index])
            {
                // BUGG(100);
                simple_Q(&choice, index, numb_path+res);
            }
            else
            {
                push_kusus(&isiNode, index, res+numb_path);
            }
            arr[cari][index]=0;
            arr[index][cari]=0;
        }
        queue_pop(&isiNode);
        if(!queue_isEmpty(&isiNode))
        {
            process(isiNode._front->data ,isiNode._front->pathWay);
        }
    }
}

void recover (Node redefinite[])
{
    for(int i=0; i<batang; i++)
    {
        arr[redefinite[i].f1Node][redefinite[i].s2Node]=redefinite[i].pBatang;
        arr[redefinite[i].s2Node][redefinite[i].f1Node]=redefinite[i].pBatang;
    }
}

//

typedef struct bstnode_t {
    int key;
    int value=0;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

/**
 * !!! WARNING UTILITY FUNCTION !!!
 * Recognized by prefix "__bst__"
 * ---------------------------------------------
 * Note that you better never access these functions, 
 * unless you need to modify or you know how these functions work.
 */

BSTNode* __bst__createNode(int value, int numb) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->value = numb;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value, int numb) {
    if (root == NULL) 
        return __bst__createNode(value, numb);

    if (value < root->key)
        root->left = __bst__insert(root->left, value, numb);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value, numb);
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
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

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

BSTNode* __bst__remove(BSTNode *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key) 
        root->right = __bst__remove(root->right, value);
    else if (value < root->key) 
        root->left = __bst__remove(root->left, value);
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

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key     = temp->key;
        root->right   = __bst__remove(root->right, temp->key);
    }
    return root;
}

int indd=0;
void __bst__inorder(BSTNode *root, Node *input) {
    if (root) {
        if(root->left!=NULL)
        {
//            arr[root->key][root->left->key]=root->left->value;
//            arr[root->left->key][root->key]=root->left->value;
           input[indd].f1Node = root->key;
           input[indd].s2Node = root->left->key;
           input[indd].pBatang = root->left->value; 
           indd++;
        }
        if(root->right!=NULL)
        {
//            arr[root->key][root->right->key]=root->right->value;
//            arr[root->right->key][root->key]=root->right->value;            
           input[indd].f1Node = root->key;
           input[indd].s2Node = root->right->key;
           input[indd].pBatang = root->right->value; 
           indd++;
        }
        if(root->left == NULL&& root->right == NULL)
            leaf[root->key]=1;
        __bst__inorder(root->left, input);
//        printf("%d ", root->key);
        __bst__inorder(root->right, input);
    }
}

//void __bst__postorder(BSTNode *root) {
//    if (root) {
//        __bst__postorder(root->left);
//        __bst__postorder(root->right);
//        printf("%d ", root->key);
//    }
//}
//
//void __bst__preorder(BSTNode *root) {
//    if (root) {
//        printf("%d ", root->key);
//        __bst__preorder(root->left);
//        __bst__preorder(root->right);
//    }
//}

/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value, int numb) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value, numb);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value) {
    if (bst_find(bst, value)) {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

/**
 * Binary search tree traversal
 * - Inorder
 * - Postorder
 * - Preorder
 */

void bst_inorder(BST *bst, Node input[]) {
    __bst__inorder(bst->_root, input);
}

// void bst_postorder(BST *bst) {
//     __bst__postorder(bst->_root);
// }

// void bst_preorder(BST *bst) {
//     __bst__preorder(bst->_root);
// }
 
// FOR BFS

void recover (Node redefinite[], int batang)
{
    for(int i=0; i<batang; i++)
    {
//        cout<<redefinite[i].f1Node<<" "<<redefinite[i].s2Node
//            <<" "<<redefinite[i].pBatang<<endl;
        arr[redefinite[i].f1Node][redefinite[i].s2Node]=redefinite[i].pBatang;
        arr[redefinite[i].s2Node][redefinite[i].f1Node]=redefinite[i].pBatang;
    }
}

int main()
{
    BST set;
    bst_init(&set);

    int n;
    cin >> n;
    int temp=n;
    Node input[n];
    int node, value, peak;
    maxArrNumb=INT_MIN;
    while(n--)
    {
        if(n==temp-1)
        {
            cin >> node;
            value=0;
        }
        else
        {
            cin >> node
                >> value;
        }
        // cout << node <<" "
        //      << value
        //      << endl;
        bst_insert(&set, node, value);
        if(maxArrNumb<node)
            maxArrNumb=node;
//        bst_insert(&set, node, value);
    }
    maxArrNumb+=1;
    // bst_insert(&set, 6);
    arr=(int**) calloc (maxArrNumb, sizeof(int*));
    for(int i=0; i<maxArrNumb; i++)
        arr[i]=(int*) calloc (maxArrNumb, sizeof(int));
    leaf=(int*) calloc (maxArrNumb, sizeof(int));
    bst_inorder(&set, input);
    
    // for(int i=0; i<maxArrNumb; i++)
    //     cout<<leaf[i]<<" ";
    //     cout<<endl;
    // for(int i=0; i<temp-1; i++)
    // {
    //     cout<<input[i].f1Node<<" "
    //         <<input[i].s2Node<<" "
    //         <<input[i].pBatang<<endl;
    // }
    int q;
    scanf("%d", &q);
    for(int i=0; i<q; i++)
    {
        int cari;
        scanf("%d", &cari);
        recover(input, temp-1);

//    cout<<endl;
//    for(int j=0; j<maxArrNumb; j++)
//    {    
//        for(int k=0; k<maxArrNumb; k++)
//        {
//            cout<<arr[j][k]<<" ";
//        }
//        cout <<endl;
//    }

        queue_init(&choice);
        queue_init(&isiNode);
        if(!bst_find(&set, cari) || leaf[cari] )
        {
            printf("0\n");
            continue;
        }
        queue_push(&isiNode, cari, 0);
        process(isiNode._front->data, isiNode._front->pathWay);
//        BUGG(1);
        printf("%d\n", choice._front->pathWay);
    }
    return 0;
}