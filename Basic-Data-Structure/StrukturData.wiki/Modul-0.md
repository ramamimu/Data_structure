# Pengenalan Struktur Data

## Apa itu Struktur Data?

Struktur Data adalah sebuah organisasi dan manajemen data yang dibuat sedemikian rupa sehingga memungkinkan pengaksesan dan modifikasi yang efisien. Lebih tepatnya, struktur data adalah koleksi dari sekumpulan nilai/data, hubungan diantara data-data tersebut, dan operasi-operasi yang dapat diaplikasikan pada data tersebut.

## Mengenal Abstract Data Type (ADT)

_**Abstract Data Type**_, atau biasa disingkat ADT secara sederhana adalah tipe/objek dimana perilaku dari ADT tersebut didefinisikan oleh kumpulan nilai (_value_) dan kumpulan operasi. Abstract Data Type merupakan _interface_ “abstrak” yang implementasinya disembunyikan dari user. Implementasi dari sebuah ADT bisa bermacam-macam, namun sebuah ADT selalu mempunyai maksud yang sama.

Contohnya adalah **Integer**. Integer merupakan ADT, yang mempunyai nilai-nilai …,−2,−1,0,1,2,… dan operasi-operasi seperti penjumlahan, pengurangan, perkalian, pembagian dsb. Disini, user tidak perlu tahu bagaimana Integer diimplementasikan pada komputer. User hanya perlu tahu bahwa **“there exist Integer”**.

### ADT vs Struktur Data

- ADT merupakan ranah logikal (menyediakan interface) dan dapat diimplementasikan dengan berbagai cara.
- Struktur Data adalah implementasi konkret dari ADT.

**Contoh Analogi**

Bayangkan “Kendaraan” sebagai sebuah ADT. “Kendaraan” dapat diimplementasikan dengan berbagai bentuk, bisa mobil, kereta, bus,dll.

Contoh-contoh ADT yang sering dijumpai pada bahasa pemrograman.

**Abstract Data Type**|**Implementasi Struktur Data**
-----|-----
List|Dynamic Array/Linked List
Stack|Linked List/Dynamic Array
Queue|Linked List/Dynamic Array
Bitset|Dynamic/Static Array
Priority Queue|Linked List
Set dan Map|Balanced Binary Search Tree (AVL Tree)
(Unordered) Set dan Map|Hash Table
Graph|Directed/Undirected Graph

## Jenis Struktur Data

Pada umumnya, struktur data dibedakan berdasarkan bentuk penyimpanannya. Struktur data dikelompokkan menjadi dua jenis, yakni Struktur Data Linear dan Struktur Data Non-Linear.

- ### Struktur Data Linear

    Suatu struktur data dianggap linear apabila data-datanya disusun dalam bentuk berupa sekuens linear berurutan (_one after another_). Contoh struktur data linear yang sering kita jumpai adalah **Array**. Contoh lainnya yang akan dibahas berupa **Linked list**, **Stack** dan **Queue**.

- ### Struktur Data Non-Linear

    Struktur data non-linear berbanding terbalik dengan linear. Dalam struktur data non-linear, data disusun dan dibangun tidak secara berurutan/sekuensial melainkan disusun secara hirarkikal menggunakan aturan tertentu. Contoh struktur data non-linear adalah **Tree** dan **Graf**.

# Notasi "Big-O"

Kompleksitas dari sebuah algoritma dapat dihitung dengan berbagai faktor. Untuk saat ini, kita hanya akan membatasinya dengan melihat kompleksitas dari sebuah algoritma melalui waktu yang dibutuhkan (_runtime_). Notasi yang umum digunakan untuk mengukur waktu (_runtime_) adalah “Big-O”. Faktor penentunya adalah banyaknya data/input yang biasa dinotasikan dengan 𝑁.

## Contoh Umum

**Kompleksitas**|**Sebutan**|**Contoh**
-----|-----|-----
O(1)|Constant Time|Waktu yang dibutuhkan selalu konstan tidak peduli seberapa besar jumlah data. Contohnya mengakses elemen array.
O(N)|Linear Time|Waktu yang dibutuhkan sebanding dengan jumlah data. Contohnya Linear Search.
O(log N)|Logarithmic Time|Biasanya pada algoritma yang membagi masalah menjadi masalah yang lebih kecil (sub-problem). Contohnya Binary Search.
O(N log N)|Linearithmic Time|Contohnya pada Merge-Sort.
O(N<sup>2</sup>)|Quadratic Time|Contohnya pada Bubble-Sort.
O(2<sup>N</sup>)|Exponential Time|Mencari seluruh subset dari sebuah set memerlukan waktu 2<sup>N</sup>.
O(N!)|Factorial Time|Mencari seluruh permutasi dari sebuah string dengan panjang N.

[**Lanjut ke Dynamic Array >**](https://github.com/AlproITS/StrukturData/wiki/Modul-0-(Dynamic-Array))