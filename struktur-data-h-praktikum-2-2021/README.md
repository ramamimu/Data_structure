[link Soal](https://www.hackerrank.com/contests/sdh-m2/challenges)
# Banyu
## Verdict
AC REVISI
## Bukti
![acA](https://user-images.githubusercontent.com/81814981/115115575-724ab280-9fbf-11eb-9d53-d3566e781b86.png)

## Penjelasan Soal
Sebuah pohon memiliki n titik yang diberi nomor 0 sampai n-1.itik dalam pohon dapat memiliki cabang lebih dari dua. Daun dari pohon adalah titik yang berada di ujung pohon dan bukan titik 0 (akar).

Program harus mencari daun terdekat dari titik sumber air yang diberikan. Jika daun terdekat lebih dari satu, maka ambil daun dengan nomor terkecil.

## Visualisasi Solusi
Solusi yang diterapkan pada problem kali ini adalah menggunakan BFS (Breadth First Search). Penggunaan BFS pada program dimulai dengan menjelajahi secara rekursif titik/node sumber air terlebih dahulu, lalu program akan berhenti ketika sudah mencapai titik daun/leaf. Berikut adalah visualisasinya.

![banyu BFS](https://user-images.githubusercontent.com/81814981/115115802-98248700-9fc0-11eb-8289-61d1c6866aa3.gif)

Titik paling atas divisualisasikan sebagai sumber air dan titik terbawah adalah daun. Program akan menjelajahi tiap node secara bersamaan pada tiap-tiap ketinggian. Ketika menjelajahi tiap ketinggian, prioritass node yang pertama kali dijelajahi adalah node dengan nilai path terkecil. Untuk membatasi gerak rekursi, tiap node yang terhubung direpresentasikan dalam array dua dimensi. Misal node 3 dan 5 terhubung dengan path yang bernilai 9, maka dalam array direpresentasikan array[3][5] dan array[5][3] bernilai 9. Tiap array yang tidak terdapat node/sudah dikunjungi akan bernilai nol, sedangkan yang lain != nol. Berikut adalah contoh penerapan array dua dimensi pada tree yang memiliki lebih dari dua anak/cabang.

![banyu representasi graph ke array](https://user-images.githubusercontent.com/81814981/115116069-f56d0800-9fc1-11eb-8dd2-35e3e58c782e.png)

Selain array dua dimensi, program juga menggunakan queue sebagai tempat untuk menyimpan daftar node yang akan dikunjungi. Queue nantinya akan selalu diupdate nilainya/bersifat dinamis karena akan mengepop node yang sudah dikunjungi dan mengepush node yang akan dikunjungi.

Ketika program sudah mencapai daun, maka program akan memasukkannya ke dalam sebuah queue kusus yang menyimpan nilai node dan nilai path. Nantinya data di dalam queue kusus ini (apabila sudah terisi) akan dibandingkan dengan node leaf terbaru apakah pathnya lebih kecil atau tidak, jika lebih kecil maka akan data akan diupdate dengan leaf terbaru, jika sama dengan maka diambil node yang memiliki nilai node terkecil, dan jika lebih besar, maka node leaf terbaru akan diabaikan. 

Contoh penerapan konsep BFS pada soal adalah sebagai berikut.

**INPUT**

```
7 6
0 1 5
0 3 1
1 2 8
1 4 1
3 6 1
4 5 10
3
0
4
5
```

**OUTPUT**

```
6
6
5
```

**Representasi ke dalam graph**
![banyu soal](https://user-images.githubusercontent.com/81814981/115117224-b3df5b80-9fc7-11eb-9f7f-5a3fff625d99.png)

**Representasi ke dalam array**
![banyu arr mula-mula](https://user-images.githubusercontent.com/81814981/115118118-fe62d700-9fcb-11eb-81dd-d4fb9bf6dff2.png)

Berikutnya adalah contoh program ketika diminta untuk mencari titik daun terdekat dari titik sumber air 4.

Berikut adalah beberapa proses algoritma yang berjalan.

![banyuProses1](https://user-images.githubusercontent.com/81814981/115117600-a0cd8b00-9fc9-11eb-9fbf-968a8ac479af.png)

Karena titik sumber air yang diminta adalah node 4, maka program akan menuju baris array 4. Kemudian program akan meengecek tiap kolom dalam baris 4 dan mengambil node dengan nilai terkecil guna dimasukkan ke queue. Setelah didapatkan nilai terkecil selain 0, maka array yang memiliki nilai tersebut akan diganti dengan 0 (artinya node sudah tidak bisa dikunjungi lagi). Dalam setiap path yang menghubungkan node, akan memenuhi dua array, pada contoh di atas adalah array [4][1], array [1][4] dan arr[4][5], arr[5][4]. 

![banyuProses2](https://user-images.githubusercontent.com/81814981/115117797-8942d200-9fca-11eb-8c88-3e0e9aa92581.png)

Setelah node 4 selesai menyimpan node childnya pada queue, node 4 akan dipop. Dengan demikian program tidak akan mengunjungi/mengecek node tersebut lagi. Lalu program akan mengecek node selanjutnya pada queue, node 1, yang mana direpresentasikan pada array sebagai baris dan kolom 1. Lalu program akan mencari nilai minimum pada baris/ kolom tersebut. Pada program di atas node 2 yg menjadi pasangan path node 1 adalah leaf. maka node 2 akan dipush pada queue kusus untuk menyimpan data node dan nilai path yang sudah ditambah nilai path node parentnya. Setelah itu array akan ditandai dengan merubah isi dari arr[1][2] dan arr[2][1]menjadi 0.

![banyuProses3](https://user-images.githubusercontent.com/81814981/115117960-3cabc680-9fcb-11eb-8145-8c3292eff98b.png)

Kemudian node 4 akan dipop karena semua data anaknya sudah disimpan di dalam queue. Program akan melakukan hal ini secara terus menerus sampai semua leaf telah dijelajahi dan isi dari stack yang berisi kumpulan node yang akan dikunjungi kosong.

## Penjelasan Program
### Main Function
```

typedef struct
{
    int f1Node;
    int s2Node;
    int pBatang;
} Node;

...

int **arr, maxi=0;
int titik, batang;

...

int main()
{
    scanf("%d %d", &titik, &batang);
    Node input[batang];

    for(int i=0; i<batang; i++)
    {
        scanf("%d %d %d", &input[i].f1Node, &input[i].s2Node, &input[i].pBatang);
        if(maxi<input[i].f1Node)
            maxi=input[i].f1Node;
            
        if(maxi<input[i].s2Node)
            maxi=input[i].s2Node;
    }
    
    maxi+=1;
    arr=(int**) calloc (maxi, sizeof(int*));
    for(int i=0; i<maxi; i++)
    {
        arr[i]=(int*)calloc(maxi, sizeof(int));
    }

    Queue daun;
    queue_init(&daun);
    for(int i=0; i<batang; i++)
    {
        cariDaun(input[i].f1Node, input, batang, &daun);
        cariDaun(input[i].s2Node, input, batang, &daun);
    }

    int q;
    scanf("%d", &q);
    for(int i=0; i<q; i++)
    {
        int cari;
        scanf("%d", &cari);

        recover(input);
 
        queue_init(&choice);
        queue_init(&isiNode);

        if(find_leaf(&daun, cari))
        {
            printf("%d\n", cari);
            continue;
        }

        queue_push(&isiNode, cari, 0);
        process(&daun, isiNode._front->data, isiNode._front->pathWay);

        printf("%d\n", choice._front->data);
    }
    return 0;
}
```
Pertama program akan meminta data titik(jumlah node) dan batang(jumlah batang yang menghubungkan dua titik node). Data node dan path yang menghubungkan di simpan di dalam variabel ```Node input[]```. Kemudian program akan melakukan iterasi sebanyak batang. Di dalam iterasi, program akan menyimpan data dua node yang saling terhubung serta nilai pathnya. Selain itu, program juga mencari nilai terbesar dari node-node tersebut untuk keperluan berikutnya pada variabel ```maxi```. Selanjutnya adalah pendeklarasian array dua dimensi menggunakan calloc supaya array yang sudah diinisiasi otomatis bernilai 0. 

Baris berikutnya, program akan mencari leaf/daun pada daftar node tadi dengan mengecek apakah node pada ```Node input[]``` hanya muncul satu kali, apabila iya berarti node tersebut merupakan leaf. Proses ini dilakukan pada fungsi ```cariDaun()```.

Selanjutnya adalah proses iterasi untuk menanyakan titik mana yang dijadikan sumber air. Pertama program akan meyimpan nilai banyak kali perulangan pada variabel ```i```. Di dalam iterasi, program menyimpan node sumber air pada variabel ```cari```.

Fungsi ```recover()``` pada program berguna untuk mendeklarasikan tiap nilai node dan path yang ada pada variabel ```Node input[]``` pada array dua dimensi. 
Berikutnya, apabila ada kondisi kusus dimana titik sumber air sama dengan leafnya, maka akan dikeluarkan nilai node leafnya guna mempersingkat waktu.

Selanjutnya, program akan melakukan push node sumber air dengan nilai path 0 yang kemudian akan dipassing untuk dicari tiap-tiap leafnya dengan metode BFS pada fungsi ```process()```. Terakhir, karena queue leaf yang memiliki nilai path minimum hanya memiliki satu anggota, maka untuk mencetak hanya perlu frontnya saja pada program.

### Fungsi ```recover()```
```
void recover (Node redefinite[])
{
    for(int i=0; i<batang; i++)
    {
        arr[redefinite[i].f1Node][redefinite[i].s2Node]=redefinite[i].pBatang;
        arr[redefinite[i].s2Node][redefinite[i].f1Node]=redefinite[i].pBatang;
    }
}

...
recover(input);
...
```
_Pemanggil fungsi ini terletak pada ```main()``` function._

Fungsi recover akan melakukan iterasu sebanyak jumlah batang yang menghubungkan node. tiap iterasi akan mengisi nilai array yang telah disebutkan sebelumnya.

### Fungsi ```process()```
```
void  process(Queue *daun, int cari, int res)
{
    if(!queue_isEmpty(&isiNode))
    {
        while(available(cari))
        {
            int numb_path=get_min(cari);
            int index=get_index(cari, numb_path);
            if(find_leaf(daun, index))
            {
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
            process(daun, isiNode._front->data ,isiNode._front->pathWay);
        }
    }
}

...
process(&daun, isiNode._front->data, isiNode._front->pathWay);
...
```
_Pemanggil fungsi ini terletak pada ```main()``` function serta fungsi itu sendiri secara rekursif._

Pertama program akan mengecek apakah queue ```isinode``` kosong atau tidak. Apabila kosong maka rekursif berhenti, apabila masih ada isinya, maka program akan tetap berjalan. Kemudian program akan mengecek nilai-nilai di array sesuai dengan node yang dikunjungi saat itu yang pada program disimpan pada variabel ```cari``` dengan bantuan fungsi ```available()```.

Setelah itu, program akan mengambil nilai terkecil terlebih dahulu untuk dimasukkan ke queue. Untuk mengakses nilai dari path terkecil, program akan  mengakses fungsi ```get_min()```. Kemudian untuk mengakses index atau node yang akan dimasukkan ke queue, program akan mengakses fungsi ```get_index()```.

Selanjutnya program akan mengecek apakah node akan dimasukkan ke queue tadi terdapat pada queue yang berisi list daun-daun. apabila iya, maka akan dimasukkan ke queue kusus. Apabila tidak, maka akan dimasukkan ke dalam queue ```isiNode```. Berikutnya array arr[cari][index] dan arr[index][cari] yangs semula bernilai >0 akan diganti dengan 0. Kemudian program akan melakukan iterasi rekursif selama queue ```isiNode``` tidak kosong.

# Roni Suka Merah
## Verdict
AC PRAKTIKUM
## Bukti
![acB](https://user-images.githubusercontent.com/81814981/115115580-7aa2ed80-9fbf-11eb-8b19-bb6574f441d3.png)

## Penjelasan Soal
Soal meminta mencetak data secara terurut dari yang terkecil sampai yang terbesar.
## Visualisasi Solusi
Pertama, program akan memasukkan data input ke dalam tree, lalu akan melakukan transversal secara rekursif seperti visualisasi berikut.

![roni suka merah inorder](https://user-images.githubusercontent.com/81814981/115129362-5969ed80-a00f-11eb-8649-426b0889da71.gif)

Program akan mengecek child kiri terlebih dahulu, setelah itu mencetak node lalu menhjelajahi node kanan.

## Penjelasan Program
### Fungsi ```main()```
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
	__inorder(avlku._root);
}
```
Program menyimpan banyaknya node yang akan dimasukkan pada variabel n, kemudian kan memasukkan data node pada tiap iterasi dan mengunsertkannya pada tree di fungsi ```avl_inser()```. Setelah iterasi berakhir, program akan melakukan transversal secara inorder pada fungsi ```__inorder()```. 

### Fungsi ```__inorder()```
```
void __inorder(AVLNode *root) {
    if (root) {
        __inorder(root->left);
        printf("%d ", root->data);
        __inorder(root->right);
    }
}
```
Pada fungsi ini, program akan menjelajahi node sebelah kiri terlebih dahulu, lalu mencetak dan menjelajahi node sebelah kanan.

# Genjil Ganap V2
## Verdict
AC REVISI
## Bukti
![acC](https://user-images.githubusercontent.com/81814981/115115589-85f61900-9fbf-11eb-929a-406415967c61.png)

## Penjelasan Soal
Diminta untuk mengeluarkan output dengan ketentuan program berupa tree yang isinya angka genap semua, tapi jika dia memasukkan angka ganjil, angka genap yang terakhir dimasukkan akan di remove dari tree, setelah menginputkan angka pada tree. Output berisi tree yang diurutkan dari angka terkecil hingga terbesar, jika tree kosong maka keluarkan "Tree Kosong!"

## Visualisasi Solusi
Pada problem kali ini, Apabila input berupa genap, program akan menyimpan pada stack terlebih dahulu. Namun, apabila input ganjil dan stack != NULL, maka stack akan dipop front.

Setelah semua inputan sudah selesai dijalankan, program akan membuat tree yang berisi nilai yang ada pada stack, kemudian akan dioutputkan secara in-order. 

![roni suka merah inorder](https://user-images.githubusercontent.com/81814981/115151794-aa71f400-a098-11eb-9541-cc33fb8fa977.gif)

## Penjelasan Program
### Main Function
```
int main()
{
    AVL avlku;
    avl_init(&avlku);

    Stack myStack;
    stack_init(&myStack);

    int n;
    cin>>n;
    int NODE;
    for(int i=0; i<n; i++)
    {
        cin>>NODE;
        if(NODE%2==1)
        {
            if(!stack_isEmpty(&myStack))
                stack_pop(&myStack);
        }
        else
            stack_push(&myStack, NODE);
    }

    if(stack_isEmpty(&myStack))
    {
        cout<<"Tree Kosong!";
    }
    else
    {
        StackNode *temp=myStack._top;
        while(temp!=NULL)
        {
            avl_insert(&avlku, temp->data);
            temp=temp->next;
        }
        __inorder(avlku._root);
    }
    return 0;
}
```

Pertama, program akan menginisiasi tree dan stack pada variabel ```AVL avlku``` dan ```Stack myStack```. Kemudian program akan menyimpan banyaknya inputan yang akan diterima program pada variabel ```n```. Lalu program akan melakukan iterasi sebanyak ```n```. 

Di dalam iterasi, program akan mengecek apakah input yang disimpan di variabel ```NODE``` bernilai ganjil atau genap. Apabila ganjil dan stack tidak kosong, maka stack akan dipop. Sedangkan apabila genap, stack akan dipush.

Selanjutnya, apabila stack kosong, maka program akan langsung mengeluarkan ```Tree Kosong!```. Apabila stack ada maka program akan memasukkan tiap isi stack ke dalam tree yang kemudian akan dioutputkan secara inorder pada fungsi ```__inorder()```. 

# Malur Terhubung
## Verdict
AC PRAKTIKUM
## Bukti
![acD](https://user-images.githubusercontent.com/81814981/115115604-8e4e5400-9fbf-11eb-9c78-2e729e3f47ec.png)

## Penjelasan Soal
Mencari node ancestor yang menghubungkan kedua node yang diminta. Apabila ditemukan, program mengeluarkan total dari child node ancestor tersebut. Apabila node yang diminta tidak terdapat pada tree, keluarkan ```-1```.

## Visualisasi Solusi
Pertama program akan memasukkan setiap Node pada tree. Berikut adalah contoh inputan program.

**INPUT**

```
8 3
8 3 10 1 6 14 4 7 
1 4 
3 7 
4 9 
```

**OUTPUT**

```
21
21
-1
```

Tree dan node yang diminta adalah 1 4, maka akan terbentuk tree dan lingkup ancestor-child seperti berikut. 

![malur terhubung visualisasi](https://user-images.githubusercontent.com/81814981/115151615-df317b80-a097-11eb-8a9a-ff145eebed1f.jpg)

Untuk mengetahui apakah node ancestor memiliki node yang diminta, maka program harus mengakses dari bawah. Untuk melakukan hal demikian, program akan melakukan transversal secara level order dengan bantuan queue dan menyimpan alamat setiap node dari bawah sampai atas dengan menggunakan stack. Berikut adalah visualisasinya.

![malur terhubung proses](https://user-images.githubusercontent.com/81814981/115151774-94643380-a098-11eb-9190-948fe750398a.png)

Setelah mendapatkan data berupa list alamat node, selanjutya program akan mengecek dari front sampai tail dan dimisalkan tiap node tersebut adalah sebuah ancestor yang apabila childnya terdapat seperti yang diminta soal, maka ancestor tersebut memenuhi.

## Penjelasan Program
### Main Function
```
AVLNode *first, *second;
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
```
Pertama program akan melakukan inisiasi variabel ```AVL avlku``` untuk menyimpan tree. Kemudian program akan menyimpan banyaknya node yang akan diinput dan permintaan.

Kemudian program akan melakukan iterasi sebanyak ```n``` lalu menyimpan dan menginsert node pada tree ```avlku```. lalu program akan melakukan transversal secara level order pada fungsi ```level()```. Di dalam fungsi itu, program juga akan menyimpan urutan-urutan alamat node dari ketinggian terbawah dalam stack.

Selanjutnya, program akan melakukan iterasi sebanyak ```q```. pada tiap iterasi, program akan melakukan penginisiasian ulang variabel yang sebelumnya sudah diberi nilai, seperti variabel ```sum```, ```first```, dan ```second```. Lalu program akan mencari dan menyimpan alamat dari dua node yang diminta input pada fungsi ```peekOrder()```. Pada fungsi ```cari()```. Program akan mencari ancestor node dari stack yang berisi list node dari bawah hingga atas. Apabila pada ancestor node tersebut ditemukan kedua node yann diminta inputan, maka program akan melakukan return lalu menghitung jumlah dari nilai node pada fungsi ```jalanJalan()```.

### Fungsi ```peekOrder()```
```
AVLNode *first, *second;
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
```
Fungsi ini akan mencari dan menyimpan data alamat node yang diminta. Program ini diiterasi secara rekursif, apabila kedua node sudah ketemu, Program fungsi ini akan otomatis berhenti.

### Fungsi ```cari()```
```
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
```

Fungsi ini digunakan untuk menyimpan node ancestor dengan cara mengiterasi isi stack dari front lalu mengecek data satu persatu yang apabila ditemukan kedua node yang diminta, maka ancestor node akan disimpan pada variabel ```jagoanNeon```.

### Fungsi ```jalanJalan()```
```
int sum=0;
AVLNode *jagoanNeon;
void jalanJalan(AVLNode *root) {
    if (root) {
        sum+=root->data;
        jalanJalan(root->left);
        jalanJalan(root->right);
    }
}
```
Fungsi ini akan mengecek mulai dari ancestor node, lalu akan melakukan iterasi secara rekursif. Tiap iteasi yang dilakukan, variabel sum akan slalu ditambahkan dengan nilai node yang dijelajahi saat itu.

# Nadut Gabut
## Verdict
AC REVISI
## Bukti
![acE](https://user-images.githubusercontent.com/81814981/115115611-96a68f00-9fbf-11eb-8dac-de0c18b92fcb.png)

## Penjelasan Soal
Cetak "Penjumlahan angka di tree yang menghasilkan N ditemukan" apabila N ditemukan di tree, jika tidak ditemukan di tree cetak "Tidak ditemukan penjumlahan angka di tree yang menghasilkan N" dengan ketentuan menjumlahkan 3 bilangan pada tree yang mana ketiga bilangan tersebut bertetangga..

## Visualisasi Solusi
Pada problem kali ini, setelah semua data diinputkan lalu dimasukkan ke dalam tree, selanjutnya dicek apakah memenuhi kelima kemungkinan ini.

![nadut gabut data](https://user-images.githubusercontent.com/81814981/115154088-41dc4480-a0a3-11eb-9867-49f568f5d15b.png)

Tiap blok mewakili satu kemungkinan. tiap-tiap node yang dijelajahi memenuhi kemungkinan di atas, maka akan dijumlahkan dan dicocokkan dengan data yang diminta.

## Penjelasan Program
### Fungsi Main
```
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
```

Pertama program akan melakukan inisiasi variabel yang akan dijadikan tree, yaitu ```AVL avlku```. selanjutnya program akan menyimpan banyaknya iterasi yang akan dilakukan pada variabel ```n```. tiap iterasi, program akan menerima data node dan memasukkannya ke dalam tree pada fungsi ```avl_insert()```. Setelah itu, program akan menerima data yang diminta untuk dicek pada tree pada variabel ```num```. 

Pada fungsi ```__inorder()```. Program akan melakukan iterasi secara rekursif pada tiap node. Tiap iterasi, program akan mengecek apakah node yang dikunjungi memenuhi kondisi-kondisi yang telah disebutkan sebelumnya. Apabila memenuhi maka node akan dijumlahkan lalu dicocokkan dengan variabel ```num```.

Variabel ```isYess``` merupakan variabek bertipe boolean yang apabila pada tree terdapat jumlahan nilai yang diminta akan bernilai true dan sebaliknya.

### Fungsi ```__inorde()```
```
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
```
Seperti yang telah disebutkan sebelumnya, fungsi ini digunakan untuk mengecek apakah suatu node memenuhi lima kondisi yang telah disebutkan sebelumnya serta berfungsi juga untuk melakukan iteratif secara rekursif.

# Penomoran Garasi Saha
## Verdict
AC PRAKTIKUM
## Bukti
![acF](https://user-images.githubusercontent.com/81814981/115115614-9c03d980-9fbf-11eb-842d-9d9276beb35d.png)

## Penjelasan Soal
Mndata nomor ruangan pada tingkat terbawah sampai tingkat teratas dengan pola nilai minimal, maksimal, minimal, dst. Saha hanya akan mendata satu ruangan per tingkatnya.

## Visualisasi Solusi
Untuk mencapai setiap ketinggian, program harus menggunakan algoritma level-order. Pada tiap ketinggian, program akan menyimpan dua nilai pada dua stack yang berbeda, yaitu nilai minimal dan maksimal. Setelah itu program akan melakukan output sesuai dengan ketentuan yang diminta.

Lebih jelasnya, berikut adalah contoh visualisasi input dari problem soal kali ini.

**INPUT**
```
7
500
250
750
125
375
625
875
```

**OUTPUT**
```
125 750 500
```
Apabila data divisualisasikan sebagai tree, maka akan terbentuk tree seperti berikut.

<img width="410" alt="penomoran garasi saha" src="https://user-images.githubusercontent.com/81814981/115154575-c334d680-a0a5-11eb-95f7-b28c26d36ada.png">

Pada tiap ketinggian, program akan menyimpan nilai minimal dan maksimal seperti pada gambar berikut.

![penomoran garasi saha visualisasi](https://user-images.githubusercontent.com/81814981/115154606-ff683700-a0a5-11eb-8e01-5f4acbd120da.png)

## Penjelasan Program
### Fungsi ```main()```
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
	level(avlku._root);

    minStack._top=minStack._top->next;
    maxStack._top=maxStack._top->next;

    int index=0;
    while(minStack._top != NULL)
        callStack(++index);
}
```
Pertama, program akan melakukan inisiasi pada variabel ```AVL avlku``` yang akan digunakan untuk menyimpan tree nantinya. Selanjutnya program akan menyimpan data banyaknya iterasi dan node pada tiap iterasinya serta melakukan insert pada fungsi ```avl_insert()```. Setelah itu, program akan melakukan transversal secara inorder serta menyimpan nilai minimum dan maksimum pada tiap ketinggiannya pada fungsi ```level()```.

setelah itu program akan mencetak nilai sesuai ketentuan pada perulangan sampai stack bernilai NULL dengan menggunakan fungsi ```callStack()```.

### Fungsi ```level()```
```
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
```
Fungsi ini digunakan untuk melakukan transversal secara level order dengan bantuan queue. Selain itu, program juga akan mencari nilai maksimal dan minimal dengan menggunakan fungsi ```findMax()``` dan ```findMin()```.

### Fungsi ```callStack()```
```
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
```

Fungsi ini digunakan untuk mengeprint data sesuai dengan ketentuan. Apabila ```tanda``` bernilai ganjil, maka nilai maksimal akan dikeluarkan dan sebaliknya.
