# Dynamic Array

Array mungkin sudah tidak asing lagi, merupakan struktur data paling dasar yang sering digunakan untuk menyimpan data. Array bersifat statis, yang artinya ukurannya selalu tetap dan tidak dapat berubah (grow/shrink). Namun, array memungkinkan kita untuk mengakses elemennya dengan waktu yang konstan 𝑂(1). 
> Kita akan menggunakan **“Static Array”** untuk menyebutkan array statis (fixed-size array).

## Definisi

Sama seperti namanya, **Dynamic Array** memungkinkan kita untuk membuat array yang memiliki kemampuan untuk berubah ukuran (size) sesuai dengan banyaknya data yang dimasukkan dengan tetap mempertahankan karakteristik array, yakni pengaksesan elemen menggunakan _indexing_.

## Ilustrasi

Dynamic Array biasanya diimplementasikan menggunakan Static Array dengan kapasitas awal tertentu.

Misalkan, kapasitas awalnya adalah 2 dan sudah diisi dengan dua elemen yakni 6 dan 5. Ketika hendak mengisi lagi elemen 3, dapat dilihat bahwa kapasitas array sudah penuh.

![](img/m0-1.png)

Jika kapasitas array sudah penuh, maka akan mengalokasikan array baru dengan ukuran 2 kali ukuran awal (pada umumnya faktor pertumbuhannya adalah 2x), kemudian menyalin data dari array lama ke array baru. Array barulah yang akan digunakan. Disini, array terbagi menjadi dua area:

- **_Logical Size_** adalah area array yang dapat diakses.
- **_Capacity_** adalah ukuran array yang sebenarnya. Area diluar logical size seharusnya tidak dapat diakses.

![](img/m0-2.png)

> Catatan : Dynamic Array berbeda dengan array yang dialokasikan secara dinamis.

## Static Array vs Dynamic Array

Berikut tabel perbandingan antara Static Array dengan Dynamic Array.

**Static Array**|**Dynamic Array**
-----|-----
Ukurannya tetap.|Ukuran dapat berubah sesuai dengan banyaknya data.
Sangat efisien dalam segi waktu, tidak melibatkan realokasi memori.|Sedikit kurang efisien dalam segi waktu dibandingkan Static Array karena memerlukan alokasi-realokasi memori pada saat run-time.
Bagus digunakan apabila ukuran data diketahui dan tetap.|Bagus digunakan apabila ukuran data tidak tetap.
Sangat mungkin wasting memori|Kecil kemungkinan wasting memori apabila diimplementasikan dengan benar

## Operasi Dasar

Secara umum, Dynamic Array mendukung operasi-operasi dasar seperti berikut.

- **pushBack** – menambahkan data baru dari belakang. Operasi ini mempunyai mekanisme yang sudah dijelaskan pada ilustrasi.
- **popBack** – menghapus data terakhir/paling belakang.
- **back** – mendapatkan data terakhir/paling belakang.
- **front** – mendapatkan data terdepan/data pertama.
- **getAt(i)** – mendapatkan data pada indeks ke-i (dilakukan secara konstan O(1)).
- **setAt(i, value)** – mengubah data pada indeks ke-i dengan nilai baru.
- **isEmpty** – memeriksa apakah array kosong atau tidak.

## Implementasi ADT: **`DynamicArray`**

[**Link Implementasi Lengkap `DynamicArray` dapat dilihat disini**](https://github.com/AlproITS/StrukturData/)

Implementasi Dynamic Array akan dibawa ke Abstract Data Type dengan nama yang sama, yakni **`DynamicArray`** yang menyimpan tipe data **`int`**. Kapasitas awal array adalah 2 dengan faktor pertumbuhan 2 kali lipat.

Berikut adalah kompleksitas waktu dari implementasi di bawah.

**Operasi**|**Kompleksitas Waktu**
-----|-----
isEmpty|O(1)
pushBack|**amortized** O(1)
popBack|O(1)
back|O(1)
front|O(1)
setAt|O(1)
getAt|O(1)

- ### Struktur DynamicArray

    Struktur ADT Dynamic Array berisi array (variabel `_arr`), kemudian informasi ukuran (`_size`) dan kapasitas array (`_capacity`).

    ```c
    typedef struct dynamicarr_t {
        int *_arr;
        unsigned _size, _capacity;
    } DynamicArray;
    ```

- ### isEmpty

    Untuk memeriksa apakah Array kosong, cukup dengan memeriksa `_size` (ukurannya) apakah bernilai 0.

    ```c
    bool dArray_isEmpty(DynamicArray *darray) {
        return (darray->_size == 0);
    }
    ```

- ### pushBack

    Terdapat dua kasus pada saat melakukan **pushBack**, yakni.

    **Kasus 1: kapasitas array masih cukup**

    + Cukup dengan memasukkan data pada index selanjutnya.

    **Kasus 2: kapasitas array sudah penuh**

    + Jika kapasitas array sudah penuh, maka perlu dibuat array baru.
    + Alokasikan array baru dengan ukuran dua kali dari kapasitas semula.
    + Salin semua data pada array lama ke array baru.
    + Referensikan array yang sekarang ke array baru.
    + Hapus array yang lama.
    + Masukkan data baru pada index selanjutnya.

    ```c
    void dArray_pushBack(DynamicArray *darray, int value)
    {
        if (darray->_size + 1 > darray->_capacity) {
            unsigned it;
            darray->_capacity *= 2;
            int *newArr = (int*) malloc(sizeof(int) * darray->_capacity);

            for (it=0; it < darray->_size; ++it)
                newArr[it] = darray->_arr[it];
            
            int *oldArray = darray->_arr;
            darray->_arr = newArr;
            free(oldArray);
        }
        darray->_arr[darray->_size++] = value;
    }
    ```

- ### popBack

    Melakukan **popBack** cukup dengan menurunkan ukuran dari array, sehingga index yang diakses tidak akan melebihi size. Pastikan saat melakukan **popBack**, array tidak kosong.

    ```c
    void dArray_popBack(DynamicArray *darray) {
        if (!dArray_isEmpty(darray)) darray->_size--;
        else return;
    }
    ```

- ### back

    Untuk mendapatkan data paling belakang, sangat sederhana, yakni ambil nilai index **size**-1 pada array.

    ```c
    int dArray_back(DynamicArray *darray) {
        if (!dArray_isEmpty(darray))
            return darray->_arr[darray->_size-1];
        else return 0;
    }
    ```

- ### front

    Untuk mendapatkan data paling depan, cukup dengan mengambil data pada indeks 0 pada array.

    ```c
    int dArray_front(DynamicArray *darray) {
        if (!dArray_isEmpty(darray))
            return darray->_arr[0];
        else return 0;
    }
    ```

- ### setAt

    Operasi **setAt** dapat dilakukan dengan sangat mudah yakni cukup ubah nilai pada indeks yang diinginkan.

    > Selain itu, lakukanlah validasi apakah indeks yang diinputkan sesuai.

    ```c
    void dArray_setAt(
        DynamicArray *darray, unsigned index, int value)
    {
        if (!dArray_isEmpty(darray)) {
            if (index >= darray->_size)
                darray->_arr[darray->_size-1] = value;
            else
                darray->_arr[index] = value;
        }
    }
    ```

- ### getAt

    Operasi **getAt** dapat dilakukan dengan sangat mudah yakni cukup ubah menggunakan indeks yang diinginkan pada array.

    > Selain itu, lakukanlah validasi apakah indeks yang diinputkan sesuai dan array memang tidak kosong.

    ```c
    int dArray_getAt(DynamicArray *darray, unsigned index)
    {
        if (!dArray_isEmpty(darray)) {
            if (index >= darray->_size)
                return darray->_arr[darray->_size-1];
            else
                return darray->_arr[index];
        }
    }
    ```

[**Lanjut ke Linked List >**](https://github.com/AlproITS/StrukturData/wiki/Modul-0-(Linked-List))