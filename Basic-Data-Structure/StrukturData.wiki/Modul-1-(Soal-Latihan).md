# Soal Latihan

- ## Soal 1

    Buatlah program untuk memeriksa apakah sebuah string merupakan palindrom atau bukan menggunakan **stack**.

    **Contoh Input**

    ```
    kasur_rusak
    ```

    **Contoh Output**

    ```
    palindrom
    ```

    **Contoh Input**

    ```
    macbook pro
    ```

    **Contoh Output**

    ```
    mahal, eh bukan palindrom deh
    ```

- ## Soal 2

    Sebuah klinik TC sedang melayani antrian pasien. Setiap pasien mempunyai **id** dan **level urgensi** masing-masing yang direpresentasikan oleh sebuah bilangan. Buatlah program untuk mensimulasikan antrian pada klinik tersebut.

    ### Input

    Baris pertama adalah Q, banyaknya query. Setiap query dapat berupa:
    - `MASUK id x` - id adalah id dari orang dan x adalah tingkat urgensinya.
    - `LAYANI` - cetak id orang yang akan dilayani sekarang.

    ### Output

    Untuk setiap query `LAYANI`, cetak id orang yang akan dilayani saat ini. Jika sudah tidak ada pasien yang antri, maka cetak "HORE".

    ### Contoh Input

    ```
    9
    MASUK 1 15
    MASUK 3 2
    MASUK 2 6
    MASUK 7 15
    LAYANI
    LAYANI
    MASUK 8 100
    LAYANI
    LAYANI
    ```

    ### Contoh Output

    ```
    1
    7
    8
    2
    ```

- ## Soal 3

    Modifikasilah program stack, queue, deque dan priority queue pada github untuk menyimpan tipe string dengan maksimum karakter adalah 100 karakter.

