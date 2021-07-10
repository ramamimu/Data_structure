# C++ Standard Template Library Container

**Container** adalah sebuah obyek yang digunakan untuk menyimpan sekumpulan obyek lain (disebut sebagai elemen pada container tersebut) dan mengatur ruang penyimpanannya.  
Pada C++, **container** diimplementasikan sebagai **template class**, sehingga tersedia fungsi-fungsi untuk mengakses elemen-elemennya.  

## `std::array`

### [Contoh implementasi lengkap `std::array`](https://github.com/AlproITS/StrukturData/blob/master/For%20C%2B%2B/Standard%20Template%20Library/array.cpp)

Masih ingat [Array](https://github.com/AlproITS/DP_modul-2)?  
`std::array` merupakan jenis struktur data yang menampung elemen secara sekuensial dengan ukuran (kapasitas) yang tetap (**fixed-size**).  
Operasi-operasi pada `std::array`:  

- `operator[]` - Mengakses elemen di posisi spesifik.
- `at()` - Mengakses elemen di posisi spesifik sekaligus mengecek batas ukuran array. Mengembalikan nilai yang sama dengan ``operator[]``. Perbedaannya adalah ketika indeks elemen yang akan diakses melebihi batas ukuran array. Pada `at(),` program akan melemparkan error `out_of_range` saat dijalankan. Pada ``operator[]``, hal tersebut menyebabkan **undefined behavior**.
- `front()` - Mengakses elemen di posisi pertama.
- `back()` - Mengakses elemen di posisi terakhir.
- `begin()` - Sebuah iterator untuk awal sekuens.
- `end()` - Sebuah iterator untuk elemen setelah akhir sekuens.
- `size()` - Mendapatkan jumlah elemen.
- `max_size()` - Mendapatkan jumlah maksimal elemen yang dapat ditampung oleh array.   Mengembalikan nilai yang sama dengan `size().`
- `empty()` - Memeriksa apakah array kosong atau tidak. Jika ukuran array adalah 0, mengembalikan nilai `true`. Jika tidak, mengembalikan nilai `false`.
- `swap()` - Menukar seluruh elemen pada sebuah array dengan seluruh elemen pada array lain yang memiliki tipe data dan ukuran yang sama.
- `fill()` - Mengisi seluruh elemen pada array dengan nilai tertentu.

## `std::vector`

### [Contoh implementasi lengkap `std::vector`](https://github.com/AlproITS/StrukturData/blob/master/For%20C%2B%2B/Standard%20Template%20Library/vector.cpp)

Masih ingat [Dynamic Array](https://github.com/AlproITS/StrukturData/wiki/Modul-0-(Dynamic-Array))?  
`std::vector` merupakan jenis struktur data yang merepresentasikan array dengan kemampuan untuk berubah ukuran (kapasitas) secara dinamis sesuai dengan banyaknya data yang dimasukkan.  
Operasi-operasi pada `std::vector`:  

- `operator[]` - Mengakses elemen di posisi spesifik.
- `at()` - Mengakses elemen di posisi spesifik sekaligus mengecek batas ukuran vector. Mengembalikan nilai yang sama dengan `operator[]`. Perbedaannya adalah ketika indeks elemen yang akan diakses melebihi batas ukuran vector. Pada `at(),` program akan melemparkan error `out_of_range` saat dijalankan. Pada `operator[]`, hal tersebut menyebabkan **undefined behavior**.
- `front()` - Mengakses elemen di posisi pertama.
- `back()` - Mengakses elemen di posisi terakhir.
- `begin()` - Sebuah iterator untuk awal sekuens.
- `end()` - Sebuah iterator untuk elemen setelah akhir sekuens.
- `size()` - Mendapatkan jumlah elemen.
- `max_size()` - Mendapatkan jumlah maksimal elemen yang dapat ditampung oleh vector.
- `resize()` - Mengubah ukuran vector menjadi jumlah elemen tertentu. `resize()` juga dapat disertai dengan menetapkan nilai tertentu, namun tidak akan mengubah elemen yang sudah ada nilainya sebelumnya (berbeda dengan `assign()`).
- `empty()` - Memeriksa apakah vector kosong atau tidak. Jika ukuran vector adalah 0, mengembalikan nilai `true`. Jika tidak, mengembalikan nilai `false`.
- `assign()` - Menetapkan ukuran vector menjadi jumlah elemen tertentu dengan nilai tertentu pada seluruh elemennya.
- `push_back()` - Menambahkan elemen di posisi terakhir.
- `pop_back()` - Menghapus elemen terakhir.
- `insert()` - Memasukkan nilai di posisi (atau **range**) spesifik.
- `erase()` - Menghapus nilai di posisi (atau **range**) spesifik.
- `clear()` - Menghapus seluruh elemen, sehingga ukuran vector menjadi 0.
- `swap()` - Menukar seluruh elemen pada sebuah vector dengan seluruh elemen pada vector lain yang memiliki tipe data yang sama (ukuran dapat berbeda).
- `sort(first,last)` - Mengurutkan elemen pada array secara _descending_ pada rentang [first,last).
- `lower_bound(first,last,val)` - Mengembalikan iterator yang menunjuk pada elemen terkecil yang tidak kurang dari $val$ pada rentang [first,last). Jika tidak ada, maka akan mengembalikan iterator last.
- `upper_bound(first,last,val)` - Mengembalikan iterator yang menunjuk pada elemen terkecil yang lebih dari $val$ pada rentang [first,last). Jika tidak ada, maka akan mengembalikan iterator last.

## `std::list`

### [Contoh implementasi lengkap `std::list`](https://github.com/AlproITS/StrukturData/blob/master/For%20C%2B%2B/Standard%20Template%20Library/list.cpp)

Masih ingat [Linked List](https://github.com/AlproITS/StrukturData/wiki/Modul-0-(Linked-List))?  
`std::list` merupakan jenis struktur data yang menampung elemen secara sekuensial dan mampu melakukan operasi `insert()` dan `erase()` secara **constant time**.  
Operasi-operasi pada `std::list`:  

- `front()` - Mengakses elemen di posisi pertama.
- `back()` - Mengakses elemen di posisi terakhir.
- `begin()` - Sebuah iterator untuk awal sekuens.
- `end()` - Sebuah iterator untuk elemen setelah akhir sekuens.
- `size()` - Mendapatkan jumlah elemen.
- `max_size()` - Mendapatkan jumlah maksimal elemen yang dapat ditampung oleh list.
- `resize()` - Mengubah ukuran list menjadi jumlah elemen tertentu. `resize()` juga dapat disertai dengan menetapkan nilai tertentu, namun tidak akan mengubah elemen yang sudah ada nilainya sebelumnya (berbeda dengan `assign()`).
- `empty()` - Memeriksa apakah list kosong atau tidak. Jika ukuran list adalah 0, mengembalikan nilai `true`. Jika tidak, mengembalikan nilai `false`.
- `assign()` - Menetapkan ukuran list menjadi jumlah elemen tertentu dengan nilai tertentu pada seluruh elemennya.
- `push_front()` - Menambahkan elemen di posisi pertama.
- `pop_front()` - Menghapus elemen di posisi pertama.
- `push_back()` - Menambahkan elemen di posisi terakhir.
- `pop_back()` - Menghapus elemen di posisi terakhir.
- `insert()` - Memasukkan nilai di posisi (atau **range**) spesifik.
- `erase()` - Menghapus nilai di posisi (atau **range**) spesifik.
- `clear()` - Menghapus seluruh elemen, sehingga ukuran list menjadi 0.
- `swap()` - Menukar seluruh elemen pada sebuah list dengan seluruh elemen pada list lain yang memiliki tipe data yang sama (ukuran dapat berbeda).
- `reverse()` - Membalikkan urutan posisi elemen.
- `sort()` - Mengurutkan seluruh elemen secara **ascending** (**default**, dapat diubah).
- `merge()` - Memindahkan seluruh elemen pada sebuah list ke list lain, dengan syarat kedua list sudah terurut, sehingga seluruh elemen pada list tujuan pun terurut.
- `splice()` - Memindahkan seluruh elemen atau elemen tertentu pada sebuah posisi spesifik di list tersebut atau list lain.
- `unique()` - Menghapus elemen duplikat pada sebuah list, menyisakan sebuah list yang berisikan elemen-elemen unik.
- `remove()` - Menghapus elemen dengan nilai tertentu. Berbeda dengan `erase()` yang menghapus berdasarkan posisi elemen, `remove()` menghapus elemen berdasarkan nilainya.
- `remove_if()` - Menghapus elemen dengan nilai tertentu yang memenuhi syarat tertentu.

## `std::stack`

### [Contoh implementasi lengkap `std::stack`](https://github.com/AlproITS/StrukturData/blob/master/For%20C%2B%2B/Standard%20Template%20Library/stack.cpp)

Masih ingat [Stack](https://github.com/AlproITS/StrukturData/wiki/Modul-1-(Stack))?  
`std::stack` merupakan jenis struktur data dinamis yang mengikuti prinsip Last In First Out (LIFO).  
Operasi-operasi pada `std::stack`:  

- `top()` - Mengakses elemen di posisi pertama.
- `size()` - Mendapatkan jumlah elemen.
- `empty()` - Memeriksa apakah stack kosong atau tidak. Jika ukuran stack adalah 0, mengembalikan nilai `true`. Jika tidak, mengembalikan nilai `false`.
- `push()` - Menambahkan elemen di posisi pertama.
- `pop()` - Menghapus elemen di posisi pertama.
- `swap()` - Menukar seluruh elemen pada sebuah stack dengan seluruh elemen pada stack lain yang memiliki tipe data yang sama (ukuran dapat berbeda).

## `std::queue`

### [Contoh implementasi lengkap `std::queue`](https://github.com/AlproITS/StrukturData/blob/master/For%20C%2B%2B/Standard%20Template%20Library/queue.cpp)

Masih ingat [Queue](https://github.com/AlproITS/StrukturData/wiki/Modul-1-(Queue))?  
`std::queue` merupakan jenis struktur data dinamis yang mengikuti prinsip First In First Out (FIFO).  
Operasi-operasi pada `std::queue`:  

- `front()` - Mengakses elemen di posisi pertama.
- `back()` - Mengakses elemen di posisi terakhir.
- `size()` - Mendapatkan jumlah elemen.
- `empty()` - Memeriksa apakah queue kosong atau tidak. Jika ukuran queue adalah 0, mengembalikan nilai `true`. Jika tidak, mengembalikan nilai `false`.
- `push()` - Menambahkan elemen di posisi pertama.
- `pop()` - Menghapus elemen di posisi terakhir.
- `swap()` - Menukar seluruh elemen pada sebuah queue dengan seluruh elemen pada queue lain yang memiliki tipe data yang sama (ukuran dapat berbeda).

## `std::deque`

### [Contoh implementasi lengkap `std::deque`](https://github.com/AlproITS/StrukturData/blob/master/For%20C%2B%2B/Standard%20Template%20Library/deque.cpp)

Masih ingat [Deque](https://github.com/AlproITS/StrukturData/wiki/Modul-1-(Deque))?  
`std::deque` (**double-ended queue**) merupakan jenis struktur data dinamis yang dapat menambah data atau mengurangi data baik di posisi awal maupun posisi akhir.
Operasi-operasi pada `std::deque`:  

- `operator[]` - Mengakses elemen di posisi spesifik.
- `at()` - Mengakses elemen di posisi spesifik sekaligus mengecek batas ukuran deque. Mengembalikan nilai yang sama dengan `operator[]`. Perbedaannya adalah ketika indeks elemen yang akan diakses melebihi batas ukuran deque. Pada `at(),` program akan melemparkan error `out_of_range` saat dijalankan. Pada `operator[]`, hal tersebut menyebabkan **undefined behavior**.
- `front()` - Mengakses elemen di posisi pertama.
- `back()` - Mengakses elemen di posisi terakhir.
- `begin()` - Sebuah iterator untuk awal sekuens.
- `end()` - Sebuah iterator untuk elemen setelah akhir sekuens.
- `size()` - Mendapatkan jumlah elemen.
- `max_size()` - Mendapatkan jumlah maksimal elemen yang dapat ditampung oleh deque.
- `resize()` - Mengubah ukuran deque menjadi jumlah elemen tertentu. `resize()` juga dapat disertai dengan menetapkan nilai tertentu, namun tidak akan mengubah elemen yang sudah ada nilainya sebelumnya (berbeda dengan `assign()`).
- `empty()` - Memeriksa apakah deque kosong atau tidak. Jika ukuran deque adalah 0, mengembalikan nilai `true`. Jika tidak, mengembalikan nilai `false`.
- `assign()` - Menetapkan ukuran deque menjadi jumlah elemen tertentu dengan nilai tertentu pada seluruh elemennya.
- `push_front()` - Menambahkan elemen di posisi pertama.
- `pop_front()` - Menghapus elemen di posisi pertama.
- `push_back()` - Menambahkan elemen di posisi terakhir.
- `pop_back()` - Menghapus elemen di posisi terakhir.
- `insert()` - Memasukkan nilai di posisi (atau **range**) spesifik.
- `erase()` - Menghapus nilai di posisi (atau **range**) spesifik.
- `clear()` - Menghapus seluruh elemen, sehingga ukuran deque menjadi 0.
- `swap()` - Menukar seluruh elemen pada sebuah deque dengan seluruh elemen pada deque lain yang memiliki tipe data yang sama (ukuran dapat berbeda).

## `std::priority_queue`

### [Contoh implementasi lengkap `std::priority_queue`](https://github.com/AlproITS/StrukturData/blob/master/For%20C%2B%2B/Standard%20Template%20Library/priority_queue.pp)

Masih ingat [Priority Queue](https://github.com/AlproITS/StrukturData/wiki/Modul-1-(Priority-Queue))?  
`std::priority_queue` merupakan jenis struktur data dinamis yang dapat otomatis menampung elemen dengan susunan terurut secara **descending** (**default**, dapat diubah).  
Operasi-operasi pada `std::priority_queue`:  

- `top()` - Mengakses elemen di posisi pertama.
- `size()` - Mendapatkan jumlah elemen.
- `empty()` - Memeriksa apakah priority queue kosong atau tidak. Jika ukuran priority queue adalah 0, mengembalikan nilai `true`. Jika tidak, mengembalikan nilai `false`.
- `push()` - Menambahkan elemen di posisi pertama.
- `pop()` - Menghapus elemen di posisi terakhir.
- `swap()` - Menukar seluruh elemen pada sebuah priority queue dengan seluruh elemen pada priority queue lain yang memiliki tipe data yang sama (ukuran dapat berbeda).cpp)

## `std::map`

### [Contoh implementasi lengkap `std::map`](https://github.com/AlproITS/StrukturData/blob/master/For%20C%2B%2B/Standard%20Template%20Library/map.cpp)

`std::map` merupakan **associative container** yang menampung elemen dengan dalam bentuk **key**-**value**.  
Operasi-operasi pada `std::map`:  

- `operator[]` - Mengakses value dari suatu key.
- `begin()` - Sebuah iterator untuk awal sekuens.
- `end()` - Sebuah iterator untuk elemen setelah akhir sekuens.
- `size()` - Mendapatkan jumlah elemen.
- `max_size()` - Mendapatkan jumlah maksimal elemen yang dapat ditampung oleh map.
- `empty()` - Memeriksa apakah map kosong atau tidak. Jika ukuran map adalah 0, mengembalikan nilai `true`. Jika tidak, mengembalikan nilai `false`.
- `insert()` - Memasukkan nilai di posisi (atau **range**) spesifik.
- `erase()` - Menghapus nilai di posisi (atau **range**) spesifik.
- `clear()` - Menghapus seluruh elemen, sehingga ukuran map menjadi 0.
- `swap()` - Menukar seluruh elemen pada sebuah map dengan seluruh elemen pada map lain yang memiliki tipe data yang sama (ukuran dapat berbeda).
- `find()` - Menemukan elemen berdasarkan **key**.
- `count()` - Mencari jumlah elemen dengan nilai yang sama.

## `std::set`

### [Contoh implementasi lengkap `std::set`](https://github.com/AlproITS/StrukturData/blob/master/For%20C%2B%2B/Standard%20Template%20Library/set.cpp)

`std::set` merupakan **associative container** yang menampung elemen dalam bentuk **key**-**value**, dimana **value**-nya merupakan **key**-nya, sehingga setiap elemen merupakan elemen yang unik.  
Operasi-operasi pada `std::set`:  

- `begin()` - Sebuah iterator untuk awal sekuens.
- `end()` - Sebuah iterator untuk elemen setelah akhir sekuens.
- `size()` - Mendapatkan jumlah elemen.
- `max_size()` - Mendapatkan jumlah maksimal elemen yang dapat ditampung oleh set.
- `empty()` - Memeriksa apakah set kosong atau tidak. Jika ukuran set adalah 0, mengembalikan nilai `true`. Jika tidak, mengembalikan nilai `false`.
- `insert()` - Memasukkan nilai di posisi (atau **range**) spesifik.
- `erase()` - Menghapus nilai di posisi (atau **range**) spesifik.
- `clear()` - Menghapus seluruh elemen, sehingga ukuran set menjadi 0.
- `swap()` - Menukar seluruh elemen pada sebuah set dengan seluruh elemen pada set lain yang memiliki tipe data yang sama (ukuran dapat berbeda).
- `find()` - Menemukan elemen berdasarkan **key**.
- `count()` - Mencari jumlah elemen dengan nilai yang sama. Karena setiap elemen di set merupakan elemen yang unik, maka jika elemen ditemukan akan mengembalikan nilai `1`, sedangkan jika tidak ditemukan akan mengembalikan nilai `0`.

- `lower_bound(val)` - mengembalikan iterator yang menunjuk ke key yang memiliki nilai terkecil yang tidak lebih kecil dari $val$. Jika tidak ada, maka akan mengembalikan iterator `end()`.
- `upper_bound(val)` - mengembalikan iterator yang menunjuk ke key yang memiliki nilai terkecil yang lebih besar dari $val$. Jika tidak ada, maka akan mengembalikan iterator `end()`.

## Policy-Based Data Structure (PBDS)

### [Contoh implementasi lengkap PBDS](https://github.com/AlproITS/StrukturData/blob/master/For%20C%2B%2B/Standard%20Template%20Library/PBDS.cpp)

Kurang lebih, struktur data ini berfungsi sama seperti `std::set` tetapi, memiliki tambahan fungsi lain yaitu :

- `find_by_order(k)` - Mengembalikan bilangan pada urutan ke - K jika diurutkan secara _ascending_.
- `order_of_key(val)` - Mengembalikan banyaknya bilangan yang memiliki nilai lebih kecil dari $val$.

Implementasi `map`, `set`, `priority_queue`, dan `PBDS` menggunakan struktur data _balanced binary search tree_ atau _heap_ yang menyebabkan pengaksesan elemen pada STL tersebut membutuhkan waktu yang logaritmik terhadap jumlah elemennya $O(lg N)$. 
Sedangkan STL lain yang dijelaskan di modul ini membutuhkan waktu konstan untuk mengakses elemen-elemennya $O(1)$.

Untuk informasi lebih detail mengenai STL dapat dibaca di : cplusplus.com
Khusus untuk PBDS dapat dilihat di : https://codeforces.com/blog/entry/11080