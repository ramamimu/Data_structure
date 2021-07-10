# Melangkah menuju C++

Setelah satu tahun belajar C, sekarang kita akan mempelajari C++.

![C++](img/c++.png)

C++ merupakan bahasa pemrograman yang dikembangkan dari bahasa C.

## Apa saja yang baru di C++?

- Library `<iostream>`  
Library ini menyediakan fungsi dasar **input output**.
  - `cin` - standard input
  - `cout` - standard output  

  Trivia: Apa perbedaan `cin` dengan `scanf` dan `cout` dengan `printf`?  
  Hint: Silahkan perhatikan contoh implementasi.
- `namespace`  
Pada C, biasanya kita menggunakan **prefix** pada **identifier** untuk menghindari konflik nama. `namespace` dapat diibaratkan sebagai wadah yang digunakan untuk mengelompokkan fungsi (atau data lainnya) sehingga menjadi dapat dibedakan.
- `class`  
Familiar dengan `struct`? `class` juga merupakan **User Defined Data Type**. Satu-satunya perbedaan adalah **default** dari **access modifier**-nya. Pada struct **default**-nya adalah `public`, sedangkan pada `class` **default**-nya adalah `private` (akan dipelajari lebih lanjut di mata kuliah Pemrograman Berorientasi Objek, jangan bingung dulu hehe).
- `template`  
Untuk membuat sebuah fungsi atau `class` yang dapat menyesuaikan dan bekerja dengan tipe data yang berbeda, maka gunakanlah `template`.
- dan masih banyak lagi...

> Catatan: semua library yang berlaku di C juga berlaku di C++, namun tidak sebaliknya.

> Apa arti `using namespace std;` pada contoh implementasi?  
**standard library** pada C++ memakai
**prefix** `std::` supaya dapat digunakan. Maka, untuk menghindari penulisan prefix tersebut berulang-ulang, ditambahkan baris tersebut pada program.
