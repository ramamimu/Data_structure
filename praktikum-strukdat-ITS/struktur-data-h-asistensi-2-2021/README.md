# struktur-data-h-asistensi-2-2021

## Problem
Membuat program traversal tree secara pre-order, in-order, post-order, dan level-order

## Visualisasi Program
Tree merupakan salah satu bentuk struktur data non-linear yang menggambarkan hubungan yang bersifat hirarkis (hubungan one to many) antara elemen-elemen.

Untuk membuat sebuah tree, kita perlu memerhatikan apakah suatu data memiliki nilai kuantitas lebih besar daripada data lainnya yang terdapat pada tree. Ketika menginputkan data, pertama program akan mengecek apakah data lebih besar atau lebih kecil daripada parent, apabila lebih kecil maka program akan menuju ke child kiri dari parent, begitu pula sebaliknya dan seterusnya.

Berikut adalah contoh visualisasi tree dengan inputan data N (banyaknya masukan) dan DATA[i] (data ke i).

**INPUT**
```
12
55 43 49 22 33 19 7 71 63 88 89 79
```

**OUTPUT**
```
in order        : 7 19 22 33 43 49 55 63 71 79 88 89
post order      : 7 19 33 22 49 43 63 79 89 88 71 55
pre order       : 55 43 22 19 7 33 49 71 63 88 79 89
level order     : 55 43 71 22 49 63 88 19 33 79 89 7
```

![tree](https://user-images.githubusercontent.com/81814981/114299436-5c338280-9ae5-11eb-9c7b-d0492149e412.png)

Sebuah program tree traversal secara pre-order, in-order, dan post-order sebenarnya adalah sama, yang membedakan hanyalah letak pemrosesan program pada rekursi, seperti pada kode berikut.

**pre-order**
```
void preorder(AVLNode *root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
```
_(algoritma program untuk memproses data ada di atas)_

**in-order**
```
void __inorder(AVLNode *root) {
    if (root) {
        __inorder(root->left);
        printf("%d ", root->data);
        __inorder(root->right);
    }
}
```
_(algoritma program untuk memproses data ada di tengah)_

**post-order**
```
void __postorder(AVLNode *root) {
    if (root) {
        __postorder(root->left);
        __postorder(root->right);
        printf("%d ", root->data);
    }
}
```
_(algoritma program untuk memproses data ada di bawah)_

Sedangkan, level order memiliki proses algoritma yang berbeda dari tiga jenis order di atas. level order mengharuskan program memproses data sesuai dengan ketinggiannya. Akan tetapi tiap ketinggian pada tree tidak dapat dihubungkan antara satu dengan yang lainnya. Oleh karena itu program menggunakan bantuan ```queue``` untuk menyimpan alamat dari child sebelah kiri dan sebelah kanan. Berikut adalah visualisasi program queue pada level order dengan inputan yang telah disebutkan di atas.

![level order](https://user-images.githubusercontent.com/81814981/114299732-2099b800-9ae7-11eb-8b6d-4a8719e3f45a.png)

Pertama program akan menyimpan alamat memori dari parents, setelah itu akan mengeprint atau memproses data tersebut. Kemudian program akan mengecek apakah node saat ini memiliki child di kiri dan/atau kanan. Apabila mempunyai maka data memori akan di push pada ``queue`` dan apabila tidak punya, maka akan diabaikan. Setelah mengecek dan mempush child, parent kemudian dipop. Setelah parent di pop, alamat memori yang mulanya adalah child sekarang dianggap sebagai parent dan dengan demikian, secara otomatis program masuk ke tree dengan ketinggian yang lebih dalam dari sebelumnya. Lalu, Alamat memori dari parents akan diproses selayaknya parents sebelumnya. Program akan berhenti ketika semua parents tidak mempunyai child baik di kiri maupun di kanan.

## Penjelasan Solusi
```
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
```

Pertama program menyimpan banyaknya data yang akan diinput pada variabel n. Kemudian program akan mengiterasi sebanyak n. Pada tiap iterasi, program akan menyimpan data yang akan di insert lalu memprosesnya pada fungsi ```avl_insert()```. Setelah iterasi selesai, program akan mengeluarkan output berupa traversal tree secara in-order pada fungsi ```__inorder()```, post-order pada fungsi ```__postorder();```, pre-order pada fungsi ```preorder()``` dan level-order pada fungsi ```level()```.

## Penjelasan Program
### ```avl_insert()``` Function
Fungsi ini digunakan untuk memasukkan data baru ke dalam tree. Berikut adalah programnya.
```
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
```
Pertama, Program akan mengecek apakah ada node yg bernilai sama dengan inputan menggunakan fungsi ```avl_find()```. Apabila tidak ada, maka program akan dilanjutkan. Program akan memasuki fungsi baru bernama ```_insert_AVL()```. Pada fungsi ini program
akan melakukan iterasi sampai node ditemukan adalah ```NULL```. Apabila data inputan lebih kecil, maka program akan bergerak ke kiri tree apabila sebaliknya, program akan bergerak ke arah kanan.

### ```level()``` Function
Fungsi ini digunakan untuk mengakses tree sesuai dengan kedalaman atau ketinggian. Berikut adalah fungsinya
```
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
```
Seperti yang disebutkan sebelumnya pada subbab di atas. Untuk mengakses level order program memerlukan queue untuk menyimpan child node. Proses pembuatan queue ada pada fungsi ```queue_push()```. Selanjutnya isi dari queue akan diupdate dan front (yang terdiri dari parent) akan di pop pada fungsi ```popFront()``` seperti penjelasan sebelumnya.
