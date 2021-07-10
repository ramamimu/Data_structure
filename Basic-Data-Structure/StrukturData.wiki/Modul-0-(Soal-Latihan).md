# Soal Latihan

## Soal 1 (Linked List)

Implementasikanlah fungsi baru bernama **`forEachElement`** untuk **Linked List** (bisa diterapkan pada Singly Linked List atau Doubly Linked List). Fungsi **`forEachElement`** akan berfungsi layaknya iterator (mengiterasi) untuk setiap elemen dari awal hingga akhir pada **`Linked List`** yang mana setiap elemennya dikenakan operasi/fungsi lain untuk tujuan tertentu.

Misalkan, fungsi **`forEachElement`** untuk mencetak tiap elemen dalam Linked List.

**Contoh Implementasi :**

```c
#include <stdio.h>
#include <stdlib.h>

/*
Linked list
.
.
*/

void printElement(int *elem) {
    .
    .
}

void multiply2(int *elem) {
    .
    .
}

int main()
{
    List myList;
    dlist_init(&myList);

    // Anggap isi linked list adalah [1,2,3,4,5]
    // .
    // .
    // .

    // contoh fungsi forEachElement untuk mencetak data pada list

    forEachElement(&myList, printElement);

    // contoh fungsi forEachElement untuk mengalikan setiap elemen
    // dengan 2

    forEachElement(&myList, multiply2);

    // isi list menjadi [2,4,6,8,10]
    return 0;
}
```

Selain itu, ujilah fungsi **`forEachElement`** yang kamu buat dengan beberapa fungsi berikut:

- reverseEach -- yakni untuk membalikkan (reverse) setiap bilangan.
- sumDigit -- yakni mengganti elemen dengan penjumlahan semua digit setiap bilangan.

## Soal 2 (DynamicArray)

> Implementasi ini harus mengacu pada implementasi github.

Buatlah implementasi fungsi **`dArray_insertAt`** dan **`dArray_removeAt`** yang berguna untuk memasukkan elemen baru pada posisi yang diinginkan dan menghapus elemen pada posisi yang diinginkan. Prototipe fungsinya seperti berikut.

```c
void dArray_insertAt(DynamicArray *darray, unsigned index, int value);
void dArray_removeAt(Dynamic *darray, unsigned index);
```

- **`index`** merupakan posisi/indeks yang diinginkan.
- **`value`** adalah nilai baru yang akan dimasukkan.

## Soal 3 (Linked List/Dynamic Array)

Modifikasilah kode Dynamic Array dan Linked List (SinglyList) yang ada pada github agar menyimpan tipe **string** (asumsikan panjang string maks. adalah 100 karakter).



