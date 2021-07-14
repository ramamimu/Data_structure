# Djikstra

![KEKE](https://miro.medium.com/max/210/1*2jRCHqAbTCY7W7oG5ntMOQ.gif)

Djikstra adalah sebuah algoritma pemrograman yang digunakan sebagai sebuah cara untuk menemukan minimum cost pathway (dengan nilai non-negatif) pada sebuah weighted graph. Misalnya, bila titik dari sebuah graf melambangkan kota-kota dan bobot garis melambangkan jarak antara kota-kota tersebut, algoritme Dijkstra dapat digunakan untuk menemukan jarak terpendek antara dua kota. 

![220px-Dijkstra_Animation](https://user-images.githubusercontent.com/81814981/118640214-e8cb1200-b802-11eb-8ebe-bc46aafd5bc5.gif)

Algoritma ini akan memprioritaskan path terkecil terlebih dahulu kemudian menyimpannya lalu menandainya bahwa node itu telah dilalui. Pertama program akan menginisiasi setiap nilai path pada node bernilai infinite lalu nilai dari tiap node akan diupdate setelah dijelajahi ketika program sedang berlangsung.

## Langkah-Langkah Pengambilan Keputusan pada Algoritma Djikstra
### Pertama
![one_BFS](https://user-images.githubusercontent.com/81814981/118642030-0f8a4800-b805-11eb-8f65-c1d485f3e891.jpeg)

### Kedua
![second BFS](https://miro.medium.com/max/500/1*1lrE19y01X5a16cfz8tXBA.jpeg)

### Ketiga
![Third BFS](https://miro.medium.com/max/500/1*7eo3aWZUtCdbUH3lHMxEIQ.jpeg)

### Keempat
![Fourth BFS](https://miro.medium.com/max/500/1*K3yWhgjshcexOQMh_LTWDg.jpeg)

### Kelima 
![exp BFS](https://miro.medium.com/max/700/1*aJfwaqVN6vKvObqFDLE0ig.jpeg)

![fifth BFS](https://miro.medium.com/max/700/1*Xg1OVLT9sXnP_AsYngXnAg.jpeg)

## Pseudocode Djikstra
```
  fungsi Dijkstra(Graf, asal):
      Q adalah himpunan titik

      untuk setiap titik v dalam Graf:
          jarak[v] ← tak hingga
          sebelum[v] ← kosong
          tambahkan v ke dalam Q
      jarak[asal] ← 0;

      selama Q tidak kosong:
          u ← titik dalam Q dengan nilai jarak[u] terkecil
          hapus u dari Q

          untuk setiap tetangga v dari u: // hanya v yang masih dalam Q
              alt ← jarak[u] + jarak_antara(u, v)
              jika alt < jarak[v]:
                  jarak[v] ← alt
                  sebelum[v] ← u
kembalikan jarak[], sebelum[]
```

### Referensi
> https://medium.com/basecs/finding-the-shortest-path-with-a-little-help-from-dijkstra-613149fbdc8e
> https://id.wikipedia.org/wiki/Algoritme_Dijkstra
> https://en.wikipedia.org/wiki/Breadth-first_search
