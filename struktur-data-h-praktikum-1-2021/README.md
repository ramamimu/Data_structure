# Genjil Ganap
## Verdict
AC saat praktikum

## Bukti
![acD](https://user-images.githubusercontent.com/81814981/113518019-d035ce00-95ad-11eb-8e7d-f66c0bf58d61.png)

**Mengerjakan sewaktu praktikum, AC waktu revisi**

(_Kompensasi_ dari Mas Rifki karena murni kesalahan Testcase penguji)

## Penjelasan Soal
Menentukan urutan mobil Roy dengan ketentuan mobil plat genap berada di tumpukan depan, sedangkan plat ganjil di tumpukan belakang.

## Visualisasi Solusi
![dVisualSolving](https://user-images.githubusercontent.com/81814981/113475585-cbcfbf00-94a0-11eb-8a4d-ece52d2a3597.png)

Apabila plat nomer bernilai ganjil dengan program uji plat nomor dimodulo 2, maka akan masuk kondisi pertama, yaitu dengan melakukan ```push front```. Namun apabila tidak memenuhi, maka akan masuk ke kondisi kedua dengan melakukan ```push back``` yang berarti plat nomor bernilai ganjil.

## Penjelasan Solusi
Berikut adalah program pada main function.
```
int main()
{
    init();
    int n, input;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input;
        pushBack(input);
    }
    printOut();
    return 0;
}
```

Pertama program melakukan inisiasi head melalui fungsi ```init()```. Kemudian program akan menerima jumlah mobil senilai ```n```. Setelah itu program akan melakukan iterasi sebanyak ```n```. Ketika proses iterasi berlangsung, program akan menerima nomor plat mobil pada variabel ```input```. Selain itu, program akan melakukan push back dengan mempassing variabel ```input``` untuk dijadikan list. Program ini akan dijalankan oleh fungsi ```pushBack()```.

Setelah melewati serangkaian program di ```pushBack()``` function. program akan kembali lagi ke ```main()``` function. Jika iterasi pada main function masih memenuhi, maka program akan melakukan serangkaian proses ini kembali sampai iterasi berakhir. Setelah iterasi berakhir, barulah program mencetak list melalui fungsi ```printOut()```.


Setelah program pada fungsi ```printOut()``` selesai, program akan kembali ke main function dan perjalanan program pun telah selesai dengan hasil kembalian ```main()``` function ```return 0```.

## Penjelasan Program
### Fungsi ```pushBack()```
Berikut adalah isi dari fungsi ```pushBack()```.
```
/*
>>>> Fungsi pemanggil berada di main() function <<<<
pushBack(input);
*/

void pushBack(int numb)
{
    pNode *newNode=(pNode*) malloc (sizeof(pNode));
    newNode->arr=numb;
    newNode->next=NULL;
    if(head==NULL)
        head=newNode;
    else
    {
        pNode *temp = head;
        if((numb % 2)==0 )
        {
            newNode->next = temp;
            head=newNode;
        }
        else
        {
            while(temp->next != NULL )
            {
                temp=temp->next;
            }
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }
    
}
```
Algoritma pada fungsi di atas, utamanya pada proses casting dan malloc, bertujuan untuk membuat sebuah memori khusus pada _heap_ sehingga memori komputer dapat mengingat memori  variable meskipun berada bukan pada main function. Setelah itu program mendeklarasikan variabel ```newNode``` yang merupakan struct pointer dari ```pNode```. Plat mobil di simpan pada variable ```newNode->arr``` sedangkan variabel pointer yang berguna untuk menyambungkan list satu dengan lainnya ada pada ```newNode->next``` yang dideklarasikan sebagai ```NULL```. Selanjutnya program akan menerima dua kondisi apabila ```head==NULL``` maka ```head==newNode```. Pada kondisi kedua, berisi dua kondisi lagi untuk menentukan letak-letak plat nomor apakah akan berada di ```front``` atau ```back```.

### Fungsi ```printOut()```
Berikut adalah code program fungsi ```printOut()```.
```
void printOut()
{
    pNode *temp=head;
    cout<<"Urutan Mobil Roy : ";
    while( temp != NULL )
    {
        cout<<temp->arr<<' ';
        temp=temp->next;
    }
}
```
Pada fungsi ```printOut```, variable ```temp``` yang merupakan pointer dari ```pNode struct``` diinisiasi dengan variabel ```head```. Selanjutnya program akan mengeluarkan output string berupa ```"Urutan Mobil Roy : "```. Selanjutnya program akan melakukan pengulangan sampai kondisi temp memenuhi ```NULL```. pada saat pengulangan, program akan mencetak plat nomor yang sebelumnya disusun dan disimpan pada list. setelah itu variabel ```temp``` akan selalu diupdate menjadi ```temp=temp->next```, yaitu alamat memori dari variabel setelahnya. Kondisi ini terus berulang hingga kondisi perulangan menjadi ```false```.


# Cari Tanah
## Verdict
AC saat revisi

## Bukti
![acA](https://user-images.githubusercontent.com/81814981/113518052-05dab700-95ae-11eb-882a-264de6136c59.png)


## Penjelasan Soal
Menentukan apakah terdapat luas lahan berbentuk kotak yang belum ditempati pada suatu array berdimensi ```p x l``` dengan luas sekurang-kurangnya ```x meter^2```, yang mana nilai tiap ```p``` dan ```l``` bernilai 1 meter.

## Penjelasan dan Visualisasi Solusi
misal inputan bernilai
```
1 5
6 3
001
010
000
000
011
000
```

Pada kasus ini, model algoritma yang digunakan untuk memecahkan masalah adalah konsep histogram. disediakan array dua dimensi dan array satu dimensi pada program. array dua dimensi digunakan untuk menampung inputan, sedangkan array satu dimensi digunakan untuk merepresentasikan histogram yang terbentuk dari inputan. array satu dimensi yang menampung histogram akan selalu diupdate pada tiap iterasi/perulangan baris untuk diambil nilai maksimumnya. Berikut adalah visualisasi algoritmanya.
![aKonversiInputan](https://user-images.githubusercontent.com/81814981/113479469-7fdd4400-94b9-11eb-9787-d47607853ecf.png)

Kolom sebelah kiri adalah contoh inputan dengan array 6 x 3. Kolom sebelah kanan adalah contoh array satu dimensi untuk menampung nilai histogram berukuran 3 (sesuai dengan kolom **array inputan**/lebar dari array dua dimensi )yang nilainya akan selalu diupdate pada iterasi tiap baris. Proses memasukkan nilai pada _array histogram_ adalah sebagai berikut.
1. Apabila _array histogram_ berada pada iterasi pertama, apabila nilai **array inputan** pada baris ke-1 serta terletak pada suaru kolom, bernilai nol maka isi dari _array histogram_ bernilai 1 dan berlaku sebaliknya (nol pada **array inputan** menandakan wilayah yang belum terisi, sedangkan satu pada **array inputan** menandakan wlayah yang sudah terisi. nilai yang berjumlah >=1 pada _array histogram_ memiliki arti nilai wilayah yang tersedia pada area tersebut sedangkan nilai nolnya berarti wilayah tersebut tidak dapat ditempati).

2. Pada iterasi berikutnya untuk tiap baris, apabila **array inputan** bernilai nol, maka nilai _array histogram_ saat ini ialah nilai sebelumnya ditambah dengan satu ```arrayHistogram = arrayHistogram + 1```. Apabila **array inputan** bernilai satu, maka _array histogram_ bernilai nol. contohnya tabel sebelah kanan. Pada kolom pertama, jumlahan _array histogram_ selalu dijumlahkan dengan nilai sebelumnya + 1.

3. Apabila **array inputan** bernilai satu, maka otomatis array histogram pada kolom itu bernilai nol karena wilayahnya dianggap sudah terisi.

Selanjutnya, Tiap iterasi pada baris array **array inputan** akan dicari nilai maksimum melalui  _array histogram_. Setelah nilainya didapatkan, nilai itu dibandingkan lagi dengan baris lainnya supaya mendapatkan nilai yang benar-benar maksimum. Berikut adalah visualisasinya.
![aRepresentasiHologramPerBaris](https://user-images.githubusercontent.com/81814981/113480602-48719600-94bf-11eb-8d33-f512bfc57830.png)

histogram yang ditandai dengan kotak berwarna hitam adalah nilai maksimum yang diperoleh pada tiap baris. Untuk mendapatkan nilai maksimum dari suatu array dua dimensi, nilai maksimum yang didapat pada tiap baris dibandingkan dengan nilai maksimum baris lainnya. Apabila dirinci lebih lanjut, berikut perolehan datanya.

- Baris ke-1    : 2
- Baris ke-2    : 2
- Baris ke-3    : 3
- Baris ke-4    : 6
- Baris ke-5    : 5
- Baris ke-6    : 6
____________________________________
_nilai maksimum pada array adalah 6_

setelah nilai maksimum didapat, maka nilai maksimum tersebut dibandingkan dengan permintaan ```x m^``` teman Ana. Apabila *nilai maksimum >= ```x```*, maka permintaan temannya Ana dapat **terpenuhi**. Namun apabila tidak, maka permintaan teman Ana **tidak terpenuhi**. Pada inputan kali ini ```x``` bernilai 5 dan nilai maksimum adalah 6, maka dapat disimpulkan bahwa **array inputan** memenuhi *nilai maksimum >= ```x```*.

## Penjelasan Program
```
#include <bits/stdc++.h>
using namespace std;

char **arr;
int *check;
int n,x,p,l;
int COUNT=0;
int MAXCOUNT=0;
int *sudah;
int maxToday=0;

...
...
...

int main()
{
    
    cin>>n>>x;    
    for(int i=0; i<n; i++)
    {
        MAXCOUNT=0;
        cin>>p>>l;
        
        arr=(char**)malloc(sizeof(char*)*p);
        for(int j=0; j<p; j++)
            arr[j]=(char*)malloc(sizeof(char)*l);
        
        for(int j=0; j<p; j++)
        {
            for(int k=0; k<l; k++)
                cin>>arr[j][k];
        }
                
        int maxNum;
        init();
        for(int j=0; j<p; j++)
        {
            initBool();
            checkArr(j);
            recursive();
            MAXCOUNT=max(MAXCOUNT, COUNT);
        }
        if(MAXCOUNT>=x)
            cout<<"IYA\n";
        else
            cout<<"TIDAK\n";
    }
    return 0;
}
```

Sebagian besar variable pada program kali ini didefinisikan pada global variable untuk mempermudah passing variabel dari satu fungsi ke fungsi yang lain. Di dalam ```main()``` function, pertama program akan menerima inputan dua bilangan bulat pada variabel ```n``` yang meyimpan berapa kali program akan dijalankan dan ```x``` yang menyimpan berapa luas ```m^2``` tanah minimum yang diminta oleh teman Ana. 

Di dalam iterasi yang bernilai kurang dari ```n```, selanjutnya program menerima jumlah panjang baris dan lebar kolom dengan variabel ```p``` dan ```l```.  Setelah itu program melakukan proses pendeklarasian dan pengcastingan array dua dimensi menggunakan malloc dan iterasi (hal ini dikarenakan array pada global variabel didefinisikan sebagai double pointer yang bertujuan untuk mempermudah passing nilai dan memperkecil penggunaan memory karena penginisiasian akan bersifat dinamis). Iterasi di dalam pendefinisian array dibutuhkan untuk memenuhi jumlahan memori kolom array yang dibutuhkan pada tiap single/baris pointer.

Setelah array dua dimensi diinisiasi dengan variabel bertipe char ```arr[p][l]```, selanjutnya adalah penginputan dengan menggunakan iterasi ```p x l``` kali, dimana ``p`` adalah panjang dan ```l``` adalah lebar array.

Selanjutnya program akan melakukan inisiasi sebuah array pointer satu dimensi yang berukuran ```l``` bertipe integer. Tiap anggotanya bernilai ```0``` dan diinisiasi menggunakan ```calloc``` serta satu buah variabel ```MAXCOUNT``` yang berfungsi untuk menampung nilai maksimum dari proses penghitungan nantinya. penginisiasian variabel-variabel tersebut menggunakan fungsi ```init()``` pada ```main()``` function.

```
/*
>>>>> Fungsi pemanggil berada pada main() function <<<<
init();
*/

void init()
{
    check=(int*)calloc(l, sizeof(int));
    MAXCOUNT=0;
}

```

Pada proses berikutnya, program akan melakukan iterasi sebanyak ```p``` atau panjang atau baris dari array dua dimensi. Hal ini dikarenakan _array histogram_ yang digunakan untuk mengecek nilai maksimum hanya perlu dicek sebanyak ```p``` kali. Di dalam iterasi, terdapat beberapa fungsi, di antaranya: ```initBool()```, ```checkArr()```, dan ```recursive```, serta satu buah variabel ```MAXCOUNT``` yang nilainya akan diupdate pada tiap iterasi/perulangan karena berfungsi untuk mencari nilai maksimum yang di dapat antara baris satu dengan baris lainnya.

```
for(int j=0; j<p; j++)
{
    initBool();
    checkArr(j);
    recursive();
    MAXCOUNT=max(MAXCOUNT, COUNT);
{
```

Fungsi ```initBool()``` digunakan untuk menginisiasi sebuah array ```check[l]``` untuk mengecek apakah suatu array pernah dikunjungi sebelumnya. Fungsi ini akan selalu dipanggil dipanggil dan begitu juga penginisiasian variabel ```check[l]``` selama perulangan berjalan.

Fungsi ```checkArr()``` berfungsi mengkonversi array dua dimensi ```arr[p][l]``` pada baris ke-j dan sebanyak ```l``` kolom ke dalam array satu dimensi ```check[l]``` yang merupakan representasi dari histogram yang dibentuk oleh array ```arr[p][l]``` pada tiap baris iterasi.

Fungsi ```recursive()``` digunakan untuk mengecek nilai dari tiap anggota array ```arr[p][l]``` yang divisualisasikan pada tiap barisnya oleh array ```check[l]```. Fungsi ini akan selalu mengupdate nilai dari variabel ```COUNT``` yang nantinya variabel ini berfungsi untuk mendapatkan nilai maksimum histogram yang dibentuk pada tiap baris. Fungsi ini memiliki algoritma yang sangat kompleks.

Setelah program mendapatkan nilai maksimum dari array ```arr[p][l]``` yang ditampung pada variabel ```MAXCOUNT```. selanjutnya adalah mengecek apakah nilai dari ```MAXCOUNT``` >= ```x``` (x adalah nilai luas kotakan minimum yang diminta teman Ana). Apabila memenuhi keluarkan ```"IYA"```, apabila tidak memenuhi keluarkan ```"TIDAK"```.

### Fungsi ```initBool()```
Seperti yang telah diterangkan sebelumnya, Fungsi ```initBool()``` digunakan untuk menginisiasi sebuah array ```check[l]``` untuk mengecek apakah suatu array pernah dikunjungi sebelumnya.Berikut adalah kode programnya.
```
/*
>>>>> Fungsi pemanggil berada pada main() function <<<<<
initBool();
*/

void initBool()
{
    sudah=(int*)calloc(l, sizeof(int));    
}
```

### Fungsi ```checkArr()```
Fungsi ```checkArr()``` berfungsi untuk mengkonversi array dua dimensi ```arr[p][l]``` pada baris ke ```j``` ke dalam array bertipe integer yang bernama ```check[l]```. ```arr[p][l]``` di sini berfungsi sebagai **array inputan**, sedangkan ```check[l]``` adalah _array histogram_. array ```check[l]``` nantinya digunakan sebagai acuan untuk menentukan nilai maksimum karena berisi dari nilai histogram yang dibentuk oleh ```arr[p][l]``` pada tiap barisnya. Nilai dari ```check[l]``` akan selalu berubah menyesuaikan dengan nilai yang ada pada array dua dimensi.
```
/*
>>>>> fungsi pemanggil berada pada main() function <<<<<
checkArr(j);
*/

void checkArr(int r)
{
    for(int i=0; i<l; i++)
    {
        if(arr[r][i]=='0')
        {
            if(check[i] != 0)
                (check[i])++;
            else 
                (check[i])=1;
        }
        else
            check[i]=0;
    }
}
```
Fungsi ini mempassing nilai dari j, j merupakan variabel hasil dari iterasi pada main function yang bisa menunjukkan baris iterasi yang sedang dilakukan saat ini. 

### Fungsi ```recursive()```
Fungsi recursive digunakan untuk mengecek nilai dari tiap anggota ```check[l]``` secara rekursif guna mendapatkan nilai maksimum pada tiap baris array ```arr[p][l]```. Pertama fungsi akan mengupdate nilai dari variabel global ```COUNT``` menjadi nol, nantinya variabel ini akan digunakan untuk membandingkan nilai maksimum antar baris array ```arr[p][l]``` di ```main()``` function. Di dalam fungsi ```recursive()``` terdapat iterasi sejumlah ```l``` atau lebar/kolom dari **array inputan** tadi. Di dalamnya masih terdapat fungsi yang akan dijalankan secara rekursif nantinya, yaitu fungsi ```autoCount()```. Fungsi ini mempassing nilai i, yang merupakan tanda dari urutan kolom yang diiterasi dan nilai dari array ```check[]``` pada indeks ke i.

```
/*
>>>>> Fungsi pemanggil berada pada main() function <<<<<
recursive();
*/

void recursive()
{
    COUNT=0;
    for(int i=0; i<l; i++)
    {
        autoCount(i, check[i]);
        COUNT=max(res, COUNT);
        res=0;
        revitalize();
    }
}
```
Setelah fungsi ```autoCount()``` selesai. Proses tersebut akan mendapatkan nilai maksimal dari iterasi fungsi ```check[]``` pada indeks  kolom ke-i. Nilai tersebut di tampung pada sebuah global variabel yang bernama ```res```. Setelah nilai dari variabel tersebut dibandingkan, nilainya akan diupdate menjadi nol karena akan digunakan pada iterasi selanjutnya. Mengenai fungsi ```autoCount()``` akan dibahas lebih lanjut pada subbab setelah ini. 

Selanjutnya fungsi ```revitalize()```. Fungsi ini berguna untuk mengecek apakah suatu fungsi pernah dikunjungi pada saat iterasi rekursif fungsi ```autoCount()``` sedang terjadi. Fungsi ini sangat penting untuk mencegah pengulangan rekursif mengalami masalah ```segmentation fault``` dan ```run time error```.

#### Fungsi ```autoCount()```
fungsi ```autoCount()``` merupakan inti dari proses algoritma ini. Fungsi ini mengecek tiap nilai dari array ```check[l]``` secara rekursive dan mencari nilai maksimum dari array tersebut Berikut adalah kode programnya.
```
/*
>>>>> Fungsi pemanggil berada pada recursive() function <<<<<
autoCount(i, check[i]);
*/

int res=0;
void autoCount(int c, int number)
{
    if(check[c]>0 && !pernah(c))
    {
        sudah[c]++;
        res+=number;
        if(check[c-1]>=number && c!=0)
            autoCount(c-1, number);
        if(check[c+1]>=number & c!=l-1)
            autoCount(c+1, number);
    }
}
```
Fokus utama pada fungsi ini adalah menghitung nilai maksimum pada array ```check``` berdasarkan iterasi dengan jumlah kolom array ```arr[p][l]``` pada fungsi ```recursive()```. nilai dari program ini akan ditampung pada global variabel yang diinisiasi tepat di atas fungsi ```autoCount()``` ini.

Pertama, untuk mengefisiensikan waktu. Program akan mengecek apakah nilai ```check[c]``` > 0 dan belum pernah dikunjungi yang mana menggunakan bantuan fungsi ```pernah()```. Apabila keduanya memenuhi, maka program akan dilanjutkan.
```
/*
>>>>> Fungsi dipanggil oleh autoCount() function <<<<<
if(check[c]>0 && !pernah(c))
*/

bool pernah(int c)
{
    if(sudah[c])
        return true;
    else
        return false;
}
```
Selanjutnya program akan menandai bahwa ```check[c]``` sudah dikunjungi dengan menambahkan nilai pada array ```sudah[c]```. kemudian nilai dari ```res``` akan dijumlahkan dengan ```number``` (nilai dari check[i] pada fungsi ```recursive()```). Kemudian progam akan mengecek nilai array ```check[c]``` sesudah dan sebelumnya. Pegulangan rekursif akan berhenti kertika array ```check[c]``` <= 0, pernah dikunjungi,  bernilai < ```number```, dan c bernilai 0 atau ```l```-1 (```l``` adalah nilai dari kolom array ```arr[p][l]```). 

> Setelah proses iterasi rekursif pada fungsi ```autoCount``` selesai dan pengecekan mencapai ```l```-1, program akan kembali ke fungsi ```recursive()``` function.

> Setelah proses iterasi pada fungsi ```recursive()``` selesai dan pengecekan mencapai ```l```-1, program akan kembali ke fungsi ```main()``` function.

> Setelah proses iterasi pada fungsi ```main()``` selesai dan pengecekan mencapai ```p```-1, program akan keluar dari iterasi. Lalu melanjutkan algoritma programnya di ```main()``` function (Kelanjutannya sudah dijelaskan pada subbab **Penjelasan program** paragraf terakhir).


# MALUR RAJIN
## Verdict 
AC saat revisi

## Bukti
![acB](https://user-images.githubusercontent.com/81814981/113518065-1ee36800-95ae-11eb-8cc2-45e9a9f6b39d.png)


## Penjelasan Soal
Menentukan jumlah buku yang malur harus pisahkan dengan diikuti nama buku tiap kali input memberikan perintah ```-1```.



## Visualisasi Solusi
INPUT.
```
6
9 enggres
6 matematika
8 geo
-1
3 fisika
-1
```
OUTPUT
```
1 matematika
0 fisika
```

![bVisualSolving](https://user-images.githubusercontent.com/81814981/113493580-9bbd0600-950a-11eb-8230-b31d42321cf0.png)

Pada tiap perintah kecuali variabel ```page``` bernilai ```0``` dan ```-1```, maka program akan melakukan push pada ```stack``` dan melakukan update pada ```pqueue```. Apabila ```page``` bernilai ```-1```, maka program akan memeriksa nilai dari ```head``` pada ```pqueue``` lalu nilai tersebut disimpan pada suatu variabel. Setelah itu program akan melakukan iterasi sampai menemukan nilai yang sama pada variabel tersebut (isi dari list dijamin sama, hanya urutannya saja yang berbeda). setelah ketemu, nilai dari stack yang sama akan di```pop``` dan isi dari ```pqueue``` akan diupdate, lalu nilai dari variabel yang didapat dari ```pqueue``` sebelum diupdate tadi akan dicetak beserta dengan jumlah buku yang harus Malur pisahkan.

Lebih lanjut seperti halnya yang ada digambar, buku yang memiliki nilai minimal akan selalu berada di atas pada list ```pqueue```. Sehingga untuk mencari buku mana yang akan dipop, maka program hanya tinggal mengecek isi data dari head list ```pqueue```.

## Penjelasan Solusi

```
//main() function
int main()
{
    buku belajar,cadangan;
    init(&belajar);
    init(&cadangan);

    int n;
    cin>>n;
    int page; 
    char book[16];
    for(int i=0; i<n; i++)
    {
        cin>>page;
        if(page==-1)
        {
            pushAndPop(&belajar, &cadangan);
            update(&belajar, &cadangan, cadangan.Size);
        }
        else
        {
            cin>>book;
            if(page==0)
                continue;
            else
            {
                pQueue(&belajar, page, book);
                Stack(&cadangan, page, book);
            }
        }
    }

   return 0;
}
```
Petama, program akan menampung jumlah input testcase pada variabel ```n```. Setelah itu dilakukan iterasi sebanyak ```n``` kali pada program. Tiap iterasi terdapat inputan variabel ```page``` untuk menyimpan perintah ```-1``` (Malur ingin mengerjakan soal yang tersisa pada buku) atau masukan lain yang akan menyimpan nama dari buku yang telah dibaca Malur pada variabel ```book```. Pada saat ```page``` bernilai ```-1``` program akan menjalankan fungsi ```pushAndPop()``` yang berfungsi untuk menemukan soal yang berjumlah paling sedikit lalu mengepop stack yang urutannya di bawah soal tersebut. Selanjutnya adalah fungsi ```update()``` yang berfungsi untuk mengupdate stack dan priority queue, ```stack``` berfungsi untuk menampung data sesuai inputan, sedangkan ```pqueue``` berfungsi untuk menemukan anggota stack dengan jumlah soal yang paling sedikit (stack dengan jumlah paling sedikit berada pada nilai ```head```nya karena ```pqueue``` disusun secara ascending). Selain itu fungsi ```update``` juga akan mencetak jumlah buku yang harus Malur pisahkan dan judul buku yang memiliki jumlah soal minimal.

Pada program selanjutnya di dalam percabangan yang sama, apabila ```page``` bernilai nol, maka program akan melakukan ```continue``` dan tidak melakukan update baik pada stack maupun pqueue. Selain , program akan memproses dengan melakukan update data pada list ```stack``` dan ```pqueue```.

## Penjelasan Program
### Fungsi ```pushAndPop()```
```
/*
pushAndPop(&belajar, &cadangan);
*/

void pushAndPop(buku *urut, buku *notUrut)
{
    int running=0;
    if(notUrut->head != NULL)
    {
        linked *temp = notUrut->head;
        if ((urut->head->soal == temp->soal)) 
        {
            notUrut->head=notUrut->head->next;
            cout<<running<<' '<<temp->nama<<endl;
            notUrut->Size=notUrut->Size-1;
            free(temp);
        }
        else
        {
            while ((temp->next != NULL) &&  (temp->next->soal != urut->head->soal)) {
                temp = temp->next;
                running++;
            }
            notUrut->head=temp->next;
            cout<<running+1<<' '<<notUrut->head->nama<<endl;

            notUrut->head=notUrut->head->next;
            notUrut->Size=notUrut->Size-(running+2);
        }
    }

    //output
    if(urut->head!=NULL)
    {
        //pop2
        linked *temp=urut->head;
        urut->head=temp->next;
        urut->Size--;
        free(temp);
    }
}
```
Pada fungsi ```pushAndPop()``` terdapat tiga algoritma sekaligus. Pertama adalah mencari nilai ```stack``` yang memiliki jumlah soal minimal lalu mencetaknya dan mengepop ```stack``` yang memiliki jumlah soal minimal tersebut. Variabel ```running``` pada program digunakan untuk mencari tahu pada urutan ke berapa variabel yang dicari berada dengan cara menghitung berapa kali perulangan terjadi. pada program pertama, apabila head pada ```stack``` tidak bernilai ```NULL``` (untuk mencegah ```segmentation vault```) maka program akan berjalan. Pada percabangan pertama, apabila head pada ```stack``` bernilai sama dengan head pada```pqueue```, maka nilai pada head ```stack``` akan di pop dan buku yang harus dipisahkan Malur bernilai ```0```. Namun apabila tidak memenuhi, maka program akan masuk ke percabangan berikutnya dengan mencari nilai sampai ketemu, tiap kali perulangan terjadi, variabel ```stack``` akan selalu diincreamentkan. terakhir adalah mencetak dan mengepop nilai tersebut pada ```stack```. Pada saat melakukan output, nilai ```running``` ditambah dengan satu karena sudah dianggap melewati satu kali perulangan, yaitu cek head pada percabangan pertama.

Program yang ketika adalah melakukan pop pada ```pqueue```. ```pqueue``` dipop karena isi dari anggotanya sudah tidak sesuai dan nantinya akan diupdate kembali melalui fungsi lainnya pada ```main()``` function.

### Fungsi ```update()```
```
/*
pushAndPop(&belajar, &cadangan);
*/

void update(buku *urut, buku *notUrut, int val)
{
    urut->head=NULL;
    urut->Size=0;
    if(notUrut->head!=NULL)
    {
        linked *temp=notUrut->head;
        while(temp!=NULL)
        {
            pQueue(urut, temp->soal, temp->nama);
            temp=temp->next;
        }
    }
}
```
Pada fungsi ini, program akan melakukan pengupdate-an pada list ```pqueue``` yang mana nilainya akan sama dengan list ```stack``` akan tetapi memiliki urutan yang berbeda.

### Fungsi ```pQueue()```
```
/*
pQueue(&belajar, page, book);
*/

void pQueue(buku *belajar, int page, char title[])
{
    linked *newNode=(linked*) malloc (sizeof(linked));
    belajar->Size++;

    strcpy(newNode->nama, title);
    newNode->soal=page;
    newNode->next=NULL;

    if(belajar->head==NULL)
        belajar->head=newNode;
    else
    {
        linked *temp=belajar->head;
        if(page < temp->soal )
        {
            belajar->head=newNode;
            newNode->next=temp;
        }
        else
        {
            while(temp->next != NULL && temp->next->soal < page)
            {
                temp=temp->next;
            }
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }
}
```
Fungsi ```pQueue()``` berfungsi untuk membuat sebuah list dengan prioritas tertentu. Pada program ini, prioritasnya ialah jumlah dari soal yang dikerjakan Malur. Apabila jumlah soal lebih sedikit maka akan menjadi prioritas dengan meletakkan di atas anggota list yang memiliki jumlah soal lebih banyak.

### Fungsi ```Stack()```
```
/*
Stack(&cadangan, page, book);
*/
void Stack(buku *asli, int urut, char judul[])
{
    linked *newNode =(linked*)malloc(sizeof(linked));
    asli->Size++;
    strcpy(newNode->nama, judul);
    newNode->soal=urut;
    newNode->next=NULL;

    if(asli->head==NULL)
    {    
        asli->head=newNode;
    }
    else
    {
        newNode->next=asli->head;
        asli->head=newNode;
    }
}
```
Fungsi ```Stack()``` berfungsi untuk membuat list dengan model pengurutan stack layaknya "tumpukan piring". Fungsi stack dipilih karena lebih mudah dalam mengiterasi dan menentukan berapa banyak jumlah buku yang harus dipisahkan oleh malur, programnya mudah dan lebih simple, serta yang terpenting dapat diterapkan pada problem kali ini.


# Garasi Mobil Saha
## Verdict
AC saat revisi

## Bukti
![acC](https://user-images.githubusercontent.com/81814981/113518078-315da180-95ae-11eb-9e56-a0c8162ab3d9.png)


## Penjelasan Soal
Menentukan apakah mobil pertama yang masuk garasi berhasil keluar ketika jadwalnya telah tiba, dengan kata lain tidak ada mobil menumpuk melebihi kapasitas garasi saat mobil pertama akan keluar. Garasi tidak memungkinkan sebuah mobil atau lebih masuk pada waktu yang sama atau keluar pada waktu yang sama tapi memungkinkan lebih dari 1 mobil masuk dan keluar pada waktu yang sama.

## Visualisasi Solusi
Untuk memprogram jumlahan dari ```sizeCar```.  Penting untuk menerapkan syarat-syarat yang tepat pada pengujian data yang masuk ke dalam ```queue```. Berikut adalah visualisasi syarat suatu data (```timeIn``` dan ```timeOut```) dapat masuk ke dalam ```queue```.

![cVisualSolving](https://user-images.githubusercontent.com/81814981/113496237-daaa8600-9521-11eb-939d-896d5adf0855.png)

Angka ```1``` menunjukkan jadwal mobil pertama dan sekaligus menjadi acuan bagi mobil lain apakah memenehi syarat. Sebuah data akan dimasukkan ke dalam ```queue``` apabila memenuhi kriteria berikut:
1. ```timeIn``` inputan baru > ```timeIn``` mobil pertama dan ```timeOut``` inputan baru < ```timeOut``` mobil pertama.
2. ```timeIn``` inputan baru < ```timeIn``` mobil pertama dan ```timeOut``` inputan baru > ```timeOut``` mobil pertama.
3. ```timeIn``` inputan baru < ```timeIn``` mobil pertama dan ```timeOut``` inputan baru <= ```timeOut``` mobil pertama.
4. ```timeIn``` inputan baru >= ```timeOut``` mobil pertama dan ```timeOut``` inputan baru > ```timeOut``` mobil pertama.

Kriteria di atas juga mengasumsikan bahwa inputan baru memiliki```timeIn``` >= ```timeOut```.

Apabila kriteria di atas terpenuhi, maka anggota list ```queue``` bertambah, begitu pula ```sizeCar```nya.


## Penjelasan Solusi
```
//main() function
int main()
{
    int n;
    cin>>n;
    
    int p, q;
    for(int i=0; i<n; i++)
    {
        init();
        cin>>p>>q;
        int timeIn, timeOut;
        int checkInn[p]={}, checkOutt[p]={};
        int pernah=0;
        for(int j=0; j<p; j++)
        {
            cin>>timeIn>>timeOut;
            checkInn[j]=timeIn;
            checkOutt[j]=timeOut;
            
            if(j==0)
                push(timeIn, timeOut);
            else if(isAcc(timeIn, timeOut))
                pQueue(timeIn, timeOut);
            
            if((timeIn==timeOut))
            { 
                pernah++;
            }
            else if ((checkIn(checkInn, j, timeIn) || checkOut(checkOutt, j, timeOut)))
            {
                pernah++;
            }
        }
        if(pernah)
            cout<<"Hmm harus renovasi garasi nich\n";
        else
        {
            if(sizeCar < q)
                cout<<"Hore gausah renov garasi\n";
            else
                cout<<"Hmm harus renovasi garasi nich\n";
        }
    }
    return 0;
}
```
Pertama, program akan menyimpan data ke variabel ```n``` untuk mengetahui berapa kali testcase akan dilakukan. Di dalam iterasi, program akan menyimpan data banyak mobil yang akan masuk garasi dan kapasitas garasi ke dalam variabel ```p``` dan ```q```. Berikutnya, program akan melakukan iterasi lagi sejumlah p lalu menyimpan tiap-tiap perulangannya akan menyimpan data jadwal mobil masuk dan keluar pada variabel ```timeIn``` dan ```timeOut```. Disediakan array ``checkInn[j]`` dan ``checkOutt[j]`` untuk merekam apakah jadwal  masuk dan keluar sudah pernah digunakan sebelumnya dan akan digunakan pada fungsi berikutnya.

Konsep yang utama untuk memecahkan solusi kali ini berada pada pengambilan keputusan apakah suatu jadwal memenuhi syarat untuk dimasukkan ke dalam ``queue`` list. Pengujian syaratnya dilakukan beberapa kali, antara lain : perulangan ke j==0 karena yang menjadi acuan adalah mobil pertama, maka pasti mobil pertama akan masuk ke dalam ``queue``, fungsi ``isAcc()`` untuk mengecek apakah inputan memenuhi syarat (syarat-syarat lebih lanjut dibahas pada subbab **Visualisasi Solusi**), apakah ``timeIn == timeOut``, dan apakah jadwal mobil masuk atau mobil keluar pernah digunakan sebelumnya menggunakan fungsi ``checkIn()`` dan ``checkOut()``. Salah satu titik uji yang penting untuk mengambil keputusan ada pada percabangan berikut.
```
if((timeIn==timeOut))
{ 
    pernah++;
}
else if ((checkIn(checkInn, j, timeIn) || checkOut(checkOutt, j, timeOut)))
{
    pernah++;
}
```
Apabila suatu kondisi memenuhi kondisi-kondisi tersebut, maka variabel ```pernah``` yang semula bernilai minimal nol akan mengalami increament. Apabila  Hal ini terjadi, maka dapat dipastikan inputan program tidak memenuhi syarat. Itulah mengapa hal ini akan mempengaruhi pengambilan keputusan program berikutnya.
```
if(pernah)
    cout<<"Hmm harus renovasi garasi nich\n";
else
{
    if(sizeCar < q)
        cout<<"Hore gausah renov garasi\n";
    else
        cout<<"Hmm harus renovasi garasi nich\n";
}
```
```sizeCar``` adalah variabel global yang menyimpan berapa size ```queue``` list saat ini. Apabila size kurang dari ``` q``` berarti mobil yang ada pada garasi tidak melebihi kapasitas dan mobil pertama dipastikan dapat keluar. Sebaliknya, apabila size lebih dari maka garasi akan melebihi kapasitas dan mobil pertama tidak bisa keluar.


## Penjelasan Program
### Fungsi ```push()```
Fungsi ```push()``` akan diprogram saat kali pertama perulangan terjadi. Fungsi ini khusus dibuat untuk memasukkan data mobil 1 ke dalam ```queue``` karena mobil ini nantinya menjadi acuan pengambilan keputusan program berikutnya. Berikut adalah kode programnya.
```
/*
push(timeIn, timeOut);
*/

void push(int yo, int ot)
{
    linked *newNode = (linked*) malloc(sizeof(linked));
    sizeCar++;
    newNode->in=yo;
    newNode->out=ot;
    newNode->next=NULL;
    head=newNode;
}
```
### Fungsi ```isAcc()```
```
/*
isAcc(timeIn, timeOut);
*/

bool isAcc(int in, int out)
{
    if(in==out)
        return false;
    else if((in < head->in) && (out<=head->in))
        return false;
    else if((in < head->in) && (out>head->out))
        return false;
    else if((in > head->in) && (out < head->out))
        return false;
    else if((in >= head->out) && (out > head->out))
        return false;
    else
        return true;
}
```
Fungsi ini berfungsi sebagai penyeleksi data apa saja yang bisa dimasukkan ke dalam ```queue```. Kriteria/syarat terkait sudah dijelaskan pada subbab **Visualisasi Data**.

### Fungsi ```pQueue()```
Fungsi ini berfungsi untuk menampung semua jadwal mobil masuk dan keluar yang memenuhi kriteria yang mana pengambil keputusannya ada pada fungsi ```isAcc()```. Fungsi ```pQueue()``` ini menggunakan prinsip ```queue```, dimana data yang baru masuk akan diletakkan di tail (```push_back```).
```
/*
pQueue(timeIn, timeOut);
*/

void pQueue(int in, int out)
{
    linked *newNode = (linked*) malloc(sizeof(linked));
    (sizeCar)++;
    newNode->in = in;
    newNode->out = out;
    newNode->next = NULL;

    linked *temp = head;    
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

```

### Fungsi ```checkIn()``` dan ```checkOut()```
Fungsi ini adalah fungsi terakhir yang ada pada program kali ini. Kedua fungsi ini digunakan untuk mengecek apakah ada jadwal masuk atau keluar yang sama sebelumnya. Apabila iya maka akan memberikan nilai ```return True``` dan sebaliknya. Berikut adalah kode programnya.
```
/*
checkIn(checkInn, j, timeIn);
checkOut(checkOutt, j, timeOut);
*/

bool checkIn(int arr[], int index, int val)
{
    for(int i=0; i<index; i++)
        if(arr[i]==val)
            return true;
    return false;
}

bool checkOut(int arr[], int index, int val)
{
    for(int i=0; i<index; i++)
        if(arr[i]==val)
            return true;
    return false;
}
```

# Bread Problemo
## Verdict
AC saat revisi

## Bukti
![acE](https://user-images.githubusercontent.com/81814981/113518096-594d0500-95ae-11eb-93bd-a81207954fba.png)


## Penjelasan Soal
Pada mulanya terdapat ```n``` buah roti pada Roy. Ibu berhak membagikan roti itu dari Ray kepada kakaknya atau pun sebaliknya. Tumpukan yang dipindah harus satu persatu. Output diminta untuk menentukan tumpukan roti Ray dan roti kakak. 

## Visualisasi Program
Berikut adalah contoh masukan/input pada program.

INPUT
```
5
5
1 1
1 2
1 1
2 1
2 2
```
OUTPUT
```
2 1
3 :(
4
5
```
Berikut adalah visualisasi perlakuan program pada inputan di atas.
![eVisualInput](https://user-images.githubusercontent.com/81814981/113500894-e1e68980-954b-11eb-9ae3-7d122e1e3c18.png)

Pertama program membentuk sebuah list stack sejumlah tumpukan roti. Setelah program berjalan, maka kondisi list dari Ray dan kakak akan ikut berubah tergantung pada inputan ```x``` dan ```y```. Apabila perintah ```x``` bernilai ```1```. maka program akan melakukan push front pada ```stack kakak``` dan melakukan pop pada ```stack ray```. Apabila perintah ```x``` bernilai ```2```. maka program akan melakukan push front pada ```stack ray``` dan melakukan pop pada ```stack kakak```. Sedangkan apabila ```x``` bernilai selain dua angka tersebut, maka program akan mengoutputkan ```"TumpukAnnya saLah! :("``` dan program berhenti memproses.

Ketika iterasi sudah dijalankan, maka program akan mengeluarkan output dari ```stack Ray``` dan ```stack kakak``` dengan ketentuan tertentu yang akan dibahas lebih lanjut pada subbab berikutnya.

## Penjelasan Solusi
Berikut adalah kode program ```main()``` function.
```
int main()
{
    so ray;
    so kakak;
    init(&ray, &kakak);
    int n;
    cin>>n;
    if(n==0)
    {
        cout<<"Ray SangaT MaraH!"<<endl;
    }

    for(int i=n; i>=1; i--)
        pushBack(&ray, i);

    int t;
    cin>>t;
    int x, y;
    for(int i=0; i<t; i++)
    {
        cin>>x>>y;
        if(x==1)
        {
            for(int j=0; j<y; j++)
                pushAndPop(&kakak, &ray);
        }
        else if(x==2)
        {
            for(int j=0; j<y; j++)
                pushAndPop(&ray, &kakak);
        }
        else
        {
            cout<<"TumpukAnnya saLah! :("<<endl;
            return 0;
        }
    }

    int index=max(ray.Size, kakak.Size);
    int ever=0;
    for(int i=0; i<index; i++)
    {
        if(ray.Size>0)
        {
            cout<<ray.head->data<<' ';
            pop(&ray);
        }
        else
        {
            if(ray.Size<=0 && !ever)
            {
                cout<<"- ";
                ever++;
            }
            else
                cout<<" ";
        }
        if(kakak.Size>0)
        {
            cout<<kakak.head->data<<endl;
            pop(&kakak);
        }
        else
        {
            if(kakak.Size<=0 && !ever)
            {
                cout<<":("<<endl;
                ever++;
            }
            else
                cout<<endl;
        }
    }
    return 0;
}
```
Mulanya program akan melakukan pendeklarasian tipe data struct ```so ray``` dan ```so```. tipe data ini berisi dua komponen seperti berikut.
```
typedef struct Snode{
    int data;
    Snode *next;
}linked;

typedef struct inData
{
    linked* head;
    unsigned Size;
}so;
```
setelah itu, kedua variabel tadi diinisiasi melalu fungsi ```init()```. Selanjutnya program akan menyimpan banyaknya roti Ray melalui variabel ```n```. Apabila ```n``` bernilai nol, maka program mengeluarkan output ```"Ray SangaT MaraH!"```.

Lebih lanjut program akan melakukan iterasi menggunakan permodelan stack pada fungsi ```pushBack```. Pemrograman ini bertujuan untuk menyimpan list sejumlah ```n``` tumpuk roti Ray yang diberikan ibu.

Selanjutnya, program menyimpan jumlah masukan yang akan dilakukan pada program pada variabel ```t```. Kemudian program akan melakukan iterasi sebanyak ```t``` kali. Di dalam perulangan, program menyimpan variabel ```x``` untuk menentukan perintah Pemindahan tumpukan dari Ray ke kakak (```1```) atau sebaliknya (```2```) dan ```y``` untuk menentukan seberapa banyak tumpukan yang akan dipindahkan oleh ibu. 

Apabila perintah ```x``` bernilai ```1```. maka program akan melakukan push front pada ```stack kakak``` dan melakukan pop pada ```stack ray```. Apabila perintah ```x``` bernilai ```2```. maka program akan melakukan push front pada ```stack ray``` dan melakukan pop pada ```stack kakak```. Sedangkan apabila ```x``` bernilai selain dua angka tersebut, maka program akan mengoutputkan ```"TumpukAnnya saLah! :("``` dan program berhenti memproses.

Setelah program selesai melakukan iterasi, maka proses pertukaran tumpukan roti Ray dan kakak ikut berhenti. Selanjutnya program akan mengkondisikan untuk mendapatkan hasil output sesuai dengan ketentuan seperti ketentuan berikut.
1. Jika tumpukan Ray lebih sedikit keluarkan "-" diatas tumpukan roti Ray.
2. Jika lebih banyak keluarkan ":(" diatas tumpukan roti kakaknya.
3. Jika mereka tidak mendapat tumpukan roti keluarkan "Ray SangaT MaraH!".

Untuk mendapatkan hasil sesuai dengan ketentuan di atas, pertama adalah menentukan berapa banyak iterasi untuk output data dapat dilakukan. Variabel ```index``` melakukan inisiasi sekaligus mencari nilai max dari tumpukan roti ray dan kakak menggunakan variabel berikut ```index=max(ray.Size, kakak.Size)```. Selanjutnya program melakukan inisiasi pada variabel ```ever``` untuk variabel penentu apakah suatu list sudah tidak mempunyai anggota lagi dan apakah emot kusus sudah dikeluarkan atau belum layaknya ketentuan di atas.

Selanjutnya, program akan melakukan iterasi sebanyak ```index```. kemudian program akan melakukan printout sekaligus melakukan pop pada list tumpukan roti Ray dan kakak. Program akan membuat keputusan dengan memperhatikan apakah variabel ```ever``` sudah terisi dan banyaknya tumpukan roti Ray dan kakak saat ini.


## Penjelasan Program
### Fungsi ```pushBack()```
Fungsi ini bertujuan untuk memasukkan list data pada ```stack``` tumpukan roti Ray. Berikut kode programnya.
```
/*
>>>>> fungsi di main() function <<<<<
for(int i=n; i>=1; i--)
    pushBack(&ray, i);
*/

void pushBack(so *who, int val)
{
    linked *newNode =(linked*)malloc(sizeof(linked));
    who->Size++;
    newNode->data=val;
    newNode->next=NULL;

    if(isEmpty(who))
        who->head=newNode;
    else
    {
        linked *temp=who->head;
        who->head=newNode;
        newNode->next=temp;
    }
}
```
Program dijalankan sebanyak serta dimulai dari ```n``` sampai dengan data bernilai ```1```. Hal ini karena pada tumpukan harus tersusun secara ascending dari head sampai tail list.

### Fungsi ```pushAndPop()```
fungsi ini berguna untuk mengepush atau mengepop list dari Ray atau kakak yang mana pengambilan keputusan, list mana yang dipush atau dipop, tergantung dari data yang diterima oleh variabel ```x``` pada ```main()``` function. Berikut adalah kode program.
```
/*
>>>>> Fungsi di main() function <<<<<
if(x==1)
{
    for(int j=0; j<y; j++)
        pushAndPop(&kakak, &ray);
}
else if(x==2)
{
    for(int j=0; j<y; j++)
        pushAndPop(&ray, &kakak);
}
*/

void pushAndPop(so *PUSH, so *POP)
{
    if(POP->head!=NULL)
    {
        //push
        pushBack(PUSH, POP->head->data);

        //pop
        POP->Size--;
        linked *temp = POP->head;
        POP->head = POP->head->next;
        free(temp);
    }
}

```

# Nadut & Cayo
## Verdict
AC saat revisi

## Bukti
![acF](https://user-images.githubusercontent.com/81814981/113518099-623dd680-95ae-11eb-979b-5cdf61cbcd45.png)


## Penjelasan Soal
Program diminta untuk menentukan sususan blok angka dengan ketentuan Jika ada blok angka yang lebih besar dibanding blok sebelumnya maka blok angka sebelumnya harus dikeluarkan dari tumpukan.

## Visualisasi Program
Penyelesaian permasalahan kali ini menggunakan algoritma pemrograman berupa priority queue. Yang berbeda pada priority queue kali ini ialah linked pointer yang menghubungkan list satu dengan list lainnya selalu didefinisikan ```NULL``` tanpa perkecualian dengan **tujuan untuk mengeliminasi, menggantikan, dan memutus list yang memiliki nilai < nilai inputan**. Berikut adalah visualisasi pemrogramannya.
INPUT
```
1
5
5 4 7 2 1
```
OUTPUT
```
Susunan blok yang disusun Nadut dan Cayo adalah : 7 2 1
```

![fVisualInput](https://user-images.githubusercontent.com/81814981/113514250-be493080-9597-11eb-871a-9b50deed8165.png)

Seperti yang telah dijelaskan sebelumnya, selama iterasi pada program memenuhi data pada list > data inputan, maka program akan berjalan, seperti pada contoh inputan ke dua. Namun, apabila nilai inputan > dari list, maka secara otomatis nilai inputan akan  mengeliminasi, menggantikan, dan memutus list berikutnya seperti pada contoh inputan ke tiga.

## Penjelasan Solusi
```
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        init();
        int num;
        cin>>num;
        if (num==0)
        {
            printOut();
            return 0;
        }
        int arr;
        for(int j=0; j<num; j++)
        {
            cin>>arr;
            pushBack(arr);
        }
        printOut();
        pop();
    }
}
```
Pertama, program akan menyimpan banyaknyak testcase yang akan diujikan pada program di variabel ```n```. Lalu program akan melakukan iterasi sebanyak ```n``` kali. Di dalam iterasi, program akan melakukan inisiasi pada global variabel ```pNode *head``` dengan ```NULL```.  Variabel itu nantinya akan menampung list susunan blok Cayo.

Selanjutnya, program menyimpan nilai dari banyak blok yang akan disusun pada variabel ```num```. Setelah itu, program akan memasuki percabangan yang apabila ```num``` bernilai nol maka program akan mengeluarkan list susunan blok cayo melalui fungsi ```printOut()``` dan memberhentikan program dengan memberikan nilai kembalian ```main()``` function nol.

Berikutnya, program akan melakukan iterasi sebanyak ```num``` dan menyimpan data berupa angka yang akan disusun pada blok Cayo yang kemudian akan mempassingnya ke fungsi ```pushBack)_```. Pada fungsi ```pushBack()``` program akan menjalankan algoritma seperti yang telah dijelaskan pada subbab **Visualisasi Data**.

Setelah iterasi selesai dilakukan, program akan mengeluarkan list dari priority queue susunan angka blok Cayo lalu mengepopnya.

## Penjelasan Program
### Fungsi ```init()```
Fungsi ini bertujuan untuk mendefinisikan nilai ```pNode *head``` menjadi ```NULL```. Variabel ini akan digunakan untuk menyusun list blok Cayo.
```
/*
>>>>> fungsi berada di main() function <<<<< 
init();
*/

void init()
{
    head=NULL;
}
```

### Fungsi ```pushBAck()```
Fungsi ini merupakan inti dari algoritma pemrograman, dimana data pada list blok Cayo akan disusun sesuai dengan ketentuan yang telah dijelaskan sebelumnya. Perbedaan dari list ini selain pada ketentuan pembandingnya ialah pointer yang menghubungkan list baru dengan list lama selalu didefinisikan ```NULL```. Dengan begitu secara otomatis list akan tergantikan sekaligus mengeliminasi list yang datanya bernilai kurang dari data inputan.
```
/*
>>>>> Fungsi berada di main() function <<<<<
pushBack(arr);
*/

void pushBack(int numb)
{
    pNode *newNode=(pNode*) malloc (sizeof(pNode));
    newNode->arr=numb;    
    newNode->next=NULL;

    if(head==NULL)
        head=newNode;
    else
    {
        pNode *temp=head;
        if(temp->arr < numb)
        {
            head=newNode;
        }
        else
        {
            while(temp->next != NULL && temp->next->arr >= numb)
            {
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
}
```

### Fungsi ```printOut()```
Program pada fungsi ini bertugas untuk mengeluarkan output string yang sesuai dengan ketentuan dan data list blok Cayo dari head hingga tail. berikut adalah kode programnya,
```
/*
>>>>> fungsi berada di main() function <<<<<
printOut();
*/
void printOut()
{
    pNode *temp=head;
    cout<<"Susunan blok yang disusun Nadut dan Cayo adalah : ";
    while( temp != ULL )
    {
        cout<<temp->arr<<' ';
        temp=temp->next;
    }
    cout<<endl;
}
```

### Fungsi ```pop()```
Fungsi ini mememiliki peran yang cukup penting pada program, yaitu melakukan pop pada tiap anggota list blok Cayo dari head hingga tail. Berikut programnya.
```
/*
>>>>> Fungsi berada di main() functon <<<<<
pop();
*/

void pop()
{
    if(head!=NULL)
    {
        pNode *temp= head;
        head=head->next;
        free(temp);
    }
}
```
