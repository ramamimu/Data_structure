#include<bits/stdc++.h>
using namespace std;
 
struct AVLNode {
    int data;
    AVLNode *left, *right,*parents;
    int height;
};
 
struct AVL
{
private:
    AVLNode *_root;
    unsigned _size;
 
    AVLNode* _avl_createNode(int value) {
        AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
        newNode->data = value;
        newNode->height =1;
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
 
    int _getHeight(AVLNode* node){
        if(node==NULL)
            return 0; 
        return node->height;
    }
 
    int _max(int a,int b){
        return (a > b)? a : b;
    }
 
    AVLNode* _rightRotate(AVLNode* pivotNode){
        AVLNode* newParrent=pivotNode->left;
        pivotNode->left=newParrent->right;
        newParrent->right=pivotNode;
 
        pivotNode->height=_max(_getHeight(pivotNode->left),
                        _getHeight(pivotNode->right))+1;
        newParrent->height=_max(_getHeight(newParrent->left),
                        _getHeight(newParrent->right))+1;
        
        return newParrent;
    }
 
    AVLNode* _leftRotate(AVLNode* pivotNode) {
        AVLNode* newParrent=pivotNode->right;
        pivotNode->right=newParrent->left;
        newParrent->left=pivotNode;
 
        pivotNode->height=_max(_getHeight(pivotNode->left),
                        _getHeight(pivotNode->right))+1;
        newParrent->height=_max(_getHeight(newParrent->left),
                        _getHeight(newParrent->right))+1;
        
        return newParrent;
    }
 
    AVLNode* _leftCaseRotate(AVLNode* node){
        return _rightRotate(node);
    }
 
    AVLNode* _rightCaseRotate(AVLNode* node){
        return _leftRotate(node);
    }
 
    AVLNode* _leftRightCaseRotate(AVLNode* node){
        node->left=_leftRotate(node->left);
        return _rightRotate(node);
    }
 
    AVLNode* _rightLeftCaseRotate(AVLNode* node){
        node->right=_rightRotate(node->right);
        return _leftRotate(node);
    }
 
    int _getBalanceFactor(AVLNode* node){
        if(node==NULL)
            return 0;
        return _getHeight(node->left)-_getHeight(node->right);
    }
 
    AVLNode* _insert_AVL(AVLNode* node,int value) {
        
        if(node==NULL)
            return _avl_createNode(value);
        if(value < node->data)
            node->left = _insert_AVL(node->left,value);
        else if(value > node->data)
            node->right = _insert_AVL(node->right,value);
        
        node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 
 
        int balanceFactor=_getBalanceFactor(node);
        
        if(balanceFactor > 1 && value < node->left->data)
            return _leftCaseRotate(node);
        if(balanceFactor > 1 && value > node->left->data)
            return _leftRightCaseRotate(node);
        if(balanceFactor < -1 && value > node->right->data)
            return _rightCaseRotate(node);
        if(balanceFactor < -1 && value < node->right->data)
            return _rightLeftCaseRotate(node);
        
        return node;
    }
 
    AVLNode* _findMinNode(AVLNode *node) {
        AVLNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        return currNode;
    }
 
    AVLNode* _remove_AVL(AVLNode* node,int value){
        if(node==NULL)
            return node;
        if(value > node->data)
            node->right=_remove_AVL(node->right,value);
        else if(value < node->data)
            node->left=_remove_AVL(node->left,value);
        else{
            AVLNode *temp;
            if((node->left==NULL)||(node->right==NULL)){
                temp=NULL;
                if(node->left==NULL) temp=node->right;  
                else if(node->right==NULL) temp=node->left;
                
                if(temp==NULL){
                    temp=node;
                    node=NULL;
                }
                else
                    *node=*temp;   
                
                free(temp);
            }
            else{
                temp = _findMinNode(node->right);
                node->data=temp->data;
                node->right=_remove_AVL(node->right,temp->data);
            }    
        }
 
        if(node==NULL) return node;
        
        node->height=_max(_getHeight(node->left),_getHeight(node->right))+1;
 
        int balanceFactor= _getBalanceFactor(node);
        
        if(balanceFactor>1 && _getBalanceFactor(node->left)>=0) 
            return _leftCaseRotate(node);
 
        if(balanceFactor>1 && _getBalanceFactor(node->left)<0) 
            return _leftRightCaseRotate(node);
    
        if(balanceFactor<-1 && _getBalanceFactor(node->right)<=0) 
            return _rightCaseRotate(node);
 
        if(balanceFactor<-1 && _getBalanceFactor(node->right)>0) 
            return _rightLeftCaseRotate(node);
        
        return node;
    }
    
    void cari_parent(AVLNode *root){
        if(root){
            if(root->left != NULL)root->left->parents = root;
            if(root->right != NULL)root->right->parents = root;
            cari_parent(root->left);
            cari_parent(root->right);
        }
    }
    void _inorder(AVLNode *node) {
        if (node) {
            _inorder(node->left);
            printf("%d ", node->data);
            _inorder(node->right);
        }
    }
public:
    void init() {
        _root = NULL;
        _size = 0U;
    }
 
    bool isEmpty() {
        return _root == NULL;
    }
 
    bool find(int value) {
        AVLNode *temp = _search(_root, value);
        if (temp == NULL)
            return false;
        
        if (temp->data == value) return true;
        else return false;
    }
 
    void insert(int value) {
        if (!find(value)) {
            _root = _insert_AVL(_root, value);
            _size++;
        }
    }
 
    void remove(int value) {
        if (find(value)) {
            _root = _remove_AVL(_root, value);
            _size--;
        }
    }
    void cari(){
        cari_parent(_root);
    }
    int ans(int x){
        AVLNode *temp = _search(_root,x);
        if(temp == NULL) return 0;
        else{
            if(temp->parents == NULL) return 0;
            if (temp->parents ->parents == NULL) return temp->parents->data;
            if(temp->parents->parents->left != NULL && temp->parents->parents->right != NULL) return temp->parents->parents->left->data-temp->parents->parents->right->data;
            if(temp->parents->parents->left == NULL && temp->parents->parents->right != NULL)return temp->parents->parents->right->data;
            if(temp->parents->parents->left != NULL && temp->parents->parents->right == NULL) return temp->parents->parents->left->data;
        }
        return 0;
    }
    void inorder() {
        this->_inorder(_root);
    }
};
 
int main()
{
    AVL set;
    set.init();
    int n,q;
    cin >> n >> q;
    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        set.insert(x);
    }
    set.cari();
    while(q--){
        int z;
        cin>> z;
        int ans = set.ans(z);
        if(ans < 0){
            ans *= -1;
        }
        cout << ans << endl;
    }
 
    return 0;
}