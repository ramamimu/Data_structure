# Kata-Kata
## Verdict
AC praktikum
## Bukti
![acA](https://user-images.githubusercontent.com/81814981/116678864-09f2cc80-a9d4-11eb-9f46-d2ed38aa99b3.png)

## Penjelasan Soal
Mencari keberadaan suatu kata pada tree yang telah diinputkan sebelumnya. Apabila ada outputkan ```1```, jika tidak outputkan ```0```.
## Visualisasi Solusi
**Input**
```
3
soalnya
mudah
dipahami
3
dan
soalnya
singkat
```

**Output**
```
0
1
0
```
Program akan melakukan inserting menggunakan algoritma ``trie`` seperti berikut.

![trie](https://user-images.githubusercontent.com/81814981/116768382-669bc900-aa60-11eb-8218-5077cc0071cf.png)

Untuk mengecek apakah sebuah kata terdapat pada tree, tiap akhir prefix inputan diberikan sebuah tanda variabel bool atau int yang apabila bernilai true maka menandakan huruf tersebut merupakan sebuah prefix serta jika dan hanya jika kata yang dicari memiliki huruf dengan nilai variabel true. maka dipastikan kata tersebut merupakan prefix dari tree. 

## Penjelasan Program
sumber kode: https://www.geeksforgeeks.org/trie-insert-and-search/
```
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

...

int main()
{
    struct TrieNode *root = getNode();    
    int n;
    cin>>n;
    char keys[100];
    for(int i=0; i<n; i++)
    {
        cin>>keys;
        insert(root, keys);
    }
    
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>keys;
        search(root, keys)? cout << "1\n" :
                            cout << "0\n";
    }
    return 0;
}
```
Program akan menyimpan suatu data pada structure ```TrieNode``` yang berisi ```children[26]``` yang merepresentasikan alphabet `a` - `z` (huruf dijamin lower case). Selain itu juga berisi variabel `isEndOfWord` yang dijadikan acuan apakah suatu huruf merupakan prefix dari suatu kata yang pernah diinputkan sebelumnya.

Pertama, program akan menyimpan data pada variabel ```n``` untuk mengetahui berapa kali insert akan dilakukan pada fungsi ```insert()``` dengan mempassing variabel ```keys```. kemudian program akan menyimpan data perulangan lagi untuk perintah pencarian kata sejumlah data variabel ```n``` yang baru pada data variabel ```keys``` yang baru pula. Pencarian kata dilakukan pada fungsi ```search()```.

# Malur Nguli
## Verdict
AC praktikum
## Bukti
![acB](https://user-images.githubusercontent.com/81814981/116678894-15de8e80-a9d4-11eb-9dfe-e801f674c6f0.png)

## Penjelasan Soal
Setiap program mendapatkan perintah ```print```, program harus menampilakn jumlah nilai per-kolom pada tree.

## Visualisasi Solusi
**Input**
```
9
insert 20
insert 10
insert 15
insert 9
insert 6
insert 25
insert 24
insert 26
print
```

**Output**
```
6 9 45 24 25 26 
```

![soal_2](https://user-images.githubusercontent.com/81814981/116768391-74514e80-aa60-11eb-9e26-99423d7b3a24.png)

Gambar di atas merupakan representasi dari inputan pada contoh sebelumnya. Untuk mendapatkan nilai tiap kolom. Program akan mencari berapa jumlah kolom terlebih dahulu dengan menelusuri tiap data pada AVL. apabila ke kiri direpresentasikan dengan pengurangan dan apabila ke kanan dengan penjumahan. Kemudian data banyaknya kolom akan disimpan pada sebuah variabel dengan cara menambahkan jumlahan mutlak kolom kanan root dan kiri root ditambah satu (|kolom kanan| + |kolom kiri| + 1). kemudian data tersebut akan direpresentasikan pada sebuah array dengan ukuran yang sama. Selanjutnya program akan menjelajaji tree kembali dan memasukkan tiap data pada array dengan algoritma  ```array[|kolom kiri| + kolom yang dijelajahi saat ini] += data```.

## Penjelasan Program
```
void order(AVLNode *root, int col, int arr[]) {
    if (root) {
        arr[abs(Left)+col]+=root->data;           
        order(root->left, col-1, arr);
        order(root->right, col+1, arr);
    }
}
```
Fungsi ```order()``` digunakan untuk mencari data tiap kolom dengan cara merekursi secara preorder. Tiap data yang dikunjungi sudah mempunyai data kolom ke berapa pada variabel ```col``` dan jumlah total kolom di kiri root pada variabel ```Left```. data pada kolom tersebut disimpan pada variabel ```root->data``` yang selanjutnya akan ditambahkan pada array dengan ketentuan yang telah dijelaskan sebelumnya.

# Cayo Niat
## Verdict
AC praktikum
## Bukti
![acC](https://user-images.githubusercontent.com/81814981/116678913-1b3bd900-a9d4-11eb-9f98-a18d13482f72.png)

## Penjelasan Soal
Diberikan sebuah kata secara tidak terformat lalu mengeluarkan kata tersebut dengan cara setiap string dicetak dalam satu baris diawali penomoran dimulai dari 1. Lalu baris terakhir adalah bentuk format string pada problem statement.

## Visualisasi Solusi
**Input**
```
Mas      Erki  Guanteng    Poll
 
      Mas     Rifki        Baik Poll
  
 Mba                 Inez  Makan   Cintaku   
 
        Aku    Benci   Soal Banyu
  
CANDA        Mas Daniel    Saranghae Asdos SDH
```

**Output**
```
1. Aku
2. Asdos
3. Baik
4. Banyu
5. Benci
6. CANDA
7. Cintaku
8. Daniel
9. Erki
10. Guanteng
11. Inez
12. Makan
13. Mas
14. Mba
15. Poll
16. Rifki
17. SDH
18. Saranghae
19. Soal
Aku--<3--Asdos--<3--Baik--<3--Banyu--<3--Benci--<3--CANDA--<3--Cintaku--<3--Daniel--<3--Erki--<3--Guanteng--<3--Inez--<3--Makan--<3--Mas--<3--Mba--<3--Poll--<3--Rifki--<3--SDH--<3--Saranghae--<3--Soal
```
Program akan menyimpan input menggunakan indikator ```EOF```. Apabila ```EOF```tercapai, barulah program akan mengoutputkan data seperti ketentuan di atas. Algoritma yang digunakan adalah algoritma ```Trie``` dengan child yang terdiri dari 52 data yang meliputi huruf UPPER CASE dan lower case. Prioritas penyimpanan sesuai dengan urutan kode ASCII.

## Penjelasan Program
```
#define CHAR_TO_INDEX(c) (26+(int)c - (int)'a')
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

...

int main()
{
    struct TrieNode *root = getNode();    
    char keys[1001];
 
    while(scanf("%s", keys) != EOF)
    {
        if(strcmp(keys," ")==0)
            continue;
        else
            insert(root, keys);
    }

    int level = 0;
    char str[10001];
    display(root, str, level, 0);
    display(root, str, level, 1);
    return 0;
}
```
Program akan menyimpan data pada structure ```TrieNode``` yang berisi ```children[56]``` untuk menyimpan data huruf selanjutnya sekaligus representasi dari huruf yang disimpan dan variabel ```isEndOfWord``` yang merepresentasikan apakah sebuah data merupakan prefix.

Pertama program akan menyimpan data pada variabel ```keys``` yang diulangi secara ```EOF```. tiap inputan ```" "``` akan diabaikan. Kata yang didapat akan dimasukkan pada trie melalui variabel ```insert()```. Selanjutnya program akan melakukan output yang sesuai dengan ketentuan pada fungsi ```display()```.

# Part Time
## Verdict
AC praktikum
## Bukti
![acD](https://user-images.githubusercontent.com/81814981/116678948-2262e700-a9d4-11eb-9994-1c035cd65ae3.png)

## Penjelasan Soal
Mengeluarkan total transaksi yang diminta dengan meninjau data yang telah dimasukkan berikutnya. Dalam penginputan, data harus terurut. Apabila tidak, maka program akan mengeluarkan ```ID harus urut``` dan program otonmatis berhenti. Apabila barang yang diminta tidak tersedia, maka program akan mengeluarkan ```Maaf barang tidak tersedia```.

## Visualisasi Solusi
**Input**
```
10 7
1 65000
2 13700
4 37800
```

**Output**
```
ID harus urut
```
Ketika ID tidak urut maka akan langsung keluar dari program

**Input**
```
5 5
1 13000
2 5500
3 8750
4 21900
5 30000
4 4
2 3
2 1
1 7
3 2
```
**Output**
```
Maaf barang tidak tersedia
147600
```
Tidak ada barang dengan ID 7

Program akan menyimpan data inputan pada sebuah array static karena data dijamin terurut dengan jumlah inputan yang pasti.

## Penjelasan Program
***Penjelasan program ada di dalam source code-nya.***
```
#include <stdio.h>

int main()
{
    int M, N;
    scanf("%d %d", &M, &N); // menyimpan banyaknya kali perulangan
    int arr[M+1][2];  // deklarasi variabel sebanyak M+1
    for(int i=1; i<=M; i++)
    {
        scanf("%d %d", &arr[i][0], &arr[i][1]); // kolom pertama digunakan untuk menyimpan keterurutan data, kolom kedua untuk menyimpan harga
        if(arr[i][0]!=i)
        {
            printf("ID harus urut\n");
            return 0; // memberhentikan program secara paksa
        }
    }

    int sum, id, total=0;
    for(int i=0; i<N; i++)
    {
        scanf("%d %d", &sum, &id);  //menyimpan data yang akan diambil dan harga
        if( id<1 || id>M) // apabila data tidak ada dengan acuan data id yang diinputkan tidak pada range array
        {
            printf("Maaf barang tidak tersedia\n"); 
        }
        else
        {
            total+=(sum*arr[id][1]);
        }
    }
    printf("%d\n", total);
    return 0;
}
```

# Bucin
## Verdict
AC praktikum
## Bukti
![acE](https://user-images.githubusercontent.com/81814981/116678973-2a228b80-a9d4-11eb-87b9-39cf077f0b2c.png)

## Penjelasan Soal
Apabila Command hanya berupa "Taro" yang berarti menaruh kedalam tumpukan dan "Cari" yang berarti mencari kaset berada di tumpukan/urutan keberapa dengan Output berupa "Kasetnya ada di tumpukan ke - n" yang dimana n adalah posisi n dalam tumpukan kaset tersebut. Jika ditemukan sebuah command selain "Taro" dan "Cari", maka keluarkan "AKU TUH GATAU HARUS NGAPAIN!".

## Visualisasi Solusi
**Input**
```
11
Taro 100
Taro 74
Cari 100
Cari 70
Taro 152
Taro 21
Taro 33
Cari 100
Cari 21
Cari 1 
Liatin 2
```

**Output**
```
Kasetnya ada di tumpukan ke - 2
Kasetnya gak ada!
Kasetnya ada di tumpukan ke - 4
Kasetnya ada di tumpukan ke - 1
Kasetnya gak ada!
AKU TUH GATAU HARUS NGAPAIN!
```
Program akan melakukan inserting ke BST apabila command ```Taro```. Apabila command berupa ```Cari```, maka program akan melakukan pencarian secara inorder, inorder dipilih lantaran data yang dicek pasti akan terurut mulai dari terkecil sampai terbesar. 
![inorder](https://user-images.githubusercontent.com/81814981/116768432-ad89be80-aa60-11eb-98b0-36094022cace.gif)

## Penjelasan Program
***penjelasan program terdapat pada source codenya***
```
void __bst__inorder(BSTNode *root, int data) {  // menjelajahi tree secara inorder
    if (root) {
        __bst__inorder(root->left, data);
        if(root->key==data) //apabila data yang dijelajahi sama dengan data yang dicari, maka akan memasuki kemungkinan ini
        {
            cari++; // menambahkan jumlahan urutan data yang dijelajahi saat ini
            finded=true;  // menandakan data telah ditemukan pada BST
            cout<<"Kasetnya ada di tumpukan ke - "<<cari<<endl;
            return; //memberhentikan rekursi
        }
        cari++; // menambahkan jumlahan urutan data yang dijelajahi saat ini
        __bst__inorder(root->right, data);
    }
}
```
Fungsi di atas digunakan untuk menjelajahi node secara in-order untuk mendapatkan urutan data.

# Nadut Belajar
## Verdict
AC praktikum
## Bukti
![acF](https://user-images.githubusercontent.com/81814981/116678988-30b10300-a9d4-11eb-9718-83126406f9ef.png)

## Penjelasan Soal
Membuat program yang mampu menghitung bilangan selisih antara parent sebuah node dengan siblingnya.
## Visualisasi Solusi
**Input**
```
6 3
7 10 21 45 30 29
7
30
29
```

**Output**
```
20
21
20
```

<img width="410" alt="soal_6" src="https://user-images.githubusercontent.com/81814981/116768435-b4b0cc80-aa60-11eb-985c-0e9ecfb27d11.png">

Parent dari node 6 adalah 10, sibling node 10 adalah 30 sehingga selisih nya 20 Parent dari node 30 adalah 21, karena 21 adalah root maka tidak memiliki sibling.

Program akan melakukan pencarian pada tiap node yang diminta dengan menjelajahi parent-parent dari node yang akan dicari serta selalu menyimpan dan mengupdate (baca: dengan sekaligus) sibling dari node tersebut sampai node yang dicari ditemukan.

## Penjelasan Program
***penjelasan program terdapat pada source codenya***
```
int res;// variabel yang digunakan untuk menyimpan hasil penjumlahan sibling
void _searchA(AVLNode *root, int value) {
    while (root != NULL) {
        if (value < root->data) // apabila data yang dicari lebih kecil dari data yang dijelajahi
        {   
            if(root->left!=NULL && root->left->data!=value ) //apabila data child di kiri ada dan data di kiri tidak sama dengan data yang dicari
            {
                    res=root->left->data;   // variabel diupdate
                    if(root->right != NULL) // apabila data child di kanan ada
                        res=abs(res-root->right->data); // variabel dijumlahkan
            }
            root = root->left;
        }
        else if (value > root->data) // Ketentuan sama dengan halnya program di atas, hanya saja algoritma ini mengecek child kanannya.
        {
            if(root->right!=NULL && root->right->data!=value )
            {
                res=root->right->data;
                if(root->left != NULL)
                    res=abs(res-root->left->data);
            }
            root = root->right;
        }
        else
            return;
    }
}

```
Fungsi di atas akan mencari dan menyimpan jumlahan node parent dan siblingnya.
