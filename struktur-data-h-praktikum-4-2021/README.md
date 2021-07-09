# Malur Javanese Ngulski
## Verdict
AC Revisi
## Bukti
![soal 1](https://user-images.githubusercontent.com/81814981/120257147-db5d5f80-c2b9-11eb-9328-99043f707e96.png)

## Penjelasan Soal
Menghitung biaya minimum yang diperlukan untuk membangun jalan dimana terdapat n buah rumah dengan posisi ```x```, ```y```, dan tingkat kerumitan ```h```.
## Visualisasi Solusi

Sample Input 0
```
5
3434 5546 1058
1461 5000 3652
2941 5764 5711
3918 9476 1946
9467 7739 7082
```

Sample Output 0
```
18801687.039806
```
![MST 1](https://user-images.githubusercontent.com/81814981/120258251-e0231300-c2bb-11eb-946e-0cb02c8f3f07.png)
![MST final](https://user-images.githubusercontent.com/81814981/120258255-e2856d00-c2bb-11eb-8304-6ff44a36a4d7.png)

Path pada tiap node direpresentasikan dengan rumus  **euclidian(x, y) * delta(h)**. Algoritma yang digunakan untuk memecahkan problem ini dengan MST (Minimum Spanning Tree). Minimum Spanning Tree merupakan Spanning Tree yang memiliki cost paling minimum di antara semua Spanning Tree. Cost yang dimaksud adalah jumlah weight dari semua edge yang ada pada tree tersebut. Memungkinkan untuk terdapat lebih dari 1 Minimum Spanning Tree.

## Penjelasan Program
```
int main()
{
    int n;
    cin >> n;
    city = (double**) malloc (n*sizeof(double*));
    for(int i=0; i<n; i++)
        city[i] = (double*) malloc (n*sizeof(double));        
    double input[n][3];
    for(int i=0; i<n; i++)
    {
        cin >> input[i][0]
            >> input[i][1]
            >> input[i][2];
            for(int j=0; j<=i; j++)
            {
                if(i==j)
                {
                    city[i][j]=0;
                    continue;
                }
                city[i][j]=sqrt(pow((input[i][0]-input[j][0]),2)+pow((input[i][1]-input[j][1]),2))*abs(input[i][2]-(input[j][2]));
                city[j][i]=city[i][j];
        }
    }
    
    findcost(n);
    return 0;
}
```
Pertama program akan menyimpan nilai perulangan untuk menyimpan nilai titik x, y dan keindahan pada suatu node di variabel ```n```.  Setelah itu, program melakukan inisiasi array dua dimensi ```city[][]```guna menyimpan nilai node yg ada pada tiap node. setiap node direpresentasikan pada sebuah array dua dimensi yang bernilai n x n. Urutan didasarkan pada posisi data pada inputan, misal diinput pertama maka akan berada pada node 0 dst.

Lalu Program akan mengambil 3 data berupa nilai x pada variabel ```input[n][0]```, nilai y pada variabel ```input[n][1]```, dan nilai keindahan tiap node pada variabel ```input[n][2]```. Pada iterasi di dalamnya, tiap node akan diberikan nilai kemungkinan pada tiap node dengan pathnya berdasarkan tiap inputan yang masuk guna mempercepat waktu eksekusi program. Terakhir program akan melakukan spanning minimum trees pada fungsi ```findcost()```.

# Distribusi Vaksin
## Verdict
AC Praktikum
## Bukti
![soal 2](https://user-images.githubusercontent.com/81814981/120257166-e0baaa00-c2b9-11eb-8316-f9c0f5a5cf15.png)

## Penjelasan Soal
Disediakan jalan (path) dan kota (node). Program diminta untuk menentukan total waktu minimum yang dibutuhkan untuk distribusi vaksin.

## Visualisasi Solusi
**Sample Input**
```
5 6 5
1 2 6
1 4 12
3 2 8
3 4 4
3 5 10
5 4 16
1
5
2
4
3
```

**Sample Output**
```
58
```
Program akan mencari jalan terpendek antar node menggunakan algoritma djikstra yang menggunakan priority queue. Program akan menjelajahi tiap node dan path satu persatu kemudian menentukan nilai path terpendeknya.

## Penjelasan Program
```
int main()
{
    cin >> n
        >> m
        >> q;
    int V = m;
    vector<iPair > adj[V];
  
    int node1, node2, weight;
    for(int i=0; i<m; i++)
    {
        cin >> node1
            >> node2
            >> weight;
        addEdge(adj, node1, node2, weight);
    }
    
    if(q==1)
    {
        cout<<'0'<<endl;
    }
    else
    {
        source = new int[q];
        for(int i=0; i<q; i++)
            cin >> source[i];

        for(int i=0; i<q-1; i++)
        {
            nextClc=source[i+1];
            shortestPath(adj, V, source[i]);
        }
        cout<<total<<endl;
    }
  
    return 0;
}
```
Pertama, program akan menyimpan data edge dengan bantuan fungsi ```addEdge()```. Lalu program akan mengecek tiap node yang dimasukkan yang mana disimpan pada variable ```source[]```. Variabel ```nextClc``` digunakan untuk menyimpan data node yang akan dikunjungi dari ```source[i]```. Selanjutnya program akan melakukan algoritma djikstra pada fungsi ```shortestPath()```.

# Roy sang kurir
## Verdict
AC Praktikum
## Bukti
![soal 3](https://user-images.githubusercontent.com/81814981/120257178-e7e1b800-c2b9-11eb-9a06-ebf0f15c8a67.png)

## Penjelasan Soal
Mengecek apakah rute pengiriman yang dilalui Roy akan membentuk sebuah cycle atau tidak.

## Visualisasi Solusi
**Sample Input 0**

```
5
1 0
0 2
2 1
0 3
3 4
```
**Sample Output 0**
```
Ada Cycle!
```
![circle or nor](https://user-images.githubusercontent.com/81814981/120260907-fed7d880-c2c0-11eb-8a9f-28db00c4118a.png)
Dapat dilihat, pada grafik terdapat siklus pada 0 -> 1 -> 2 -> 0 .... Maka Output menghasilkan "Ada Cycle!.

Untuk mendeteksi apakah pada suatu undirected graph terdapat circle atau tidak, program yang akan digunakan adalah DFS traversal.

## Penjelasan Program
```
int main() {
    int n;
    cin >> n;
    int arr[n][2];
    int maxi=INT_MIN;
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i][0]
            >> arr[i][1];

        if (arr[i][0]>maxi)
            maxi=arr[i][0];
        if (arr[i][1]>maxi)
            maxi=arr[i][1];
    }
    maxi+=1;
    NODE = maxi;
    
    graph = new int*[maxi];
    for(int i = 0; i < maxi; ++i)
    {    
        graph[i] = new int[maxi];
        for(int j=0; j<maxi; j++)
            graph[i][j]=0;
    }

    for(int i = 0; i < n; ++i)
    {
        graph[arr[i][0]][arr[i][1]]=1;
        graph[arr[i][1]][arr[i][0]]=1;
    }

   bool res;
   res = hasCycle();
   if(res)
      cout << "Ada Cycle!" << endl;
   else
      cout << "Tidak Ada Cycle!" << endl;
}
```
Pertama program akan merepresentasikan adjacent node menggunakan array dua dimensi yang disimpan pada vaariabel ```arr[][]```. Setelah itu, program akan mengecek circle pada fungsi ```hasCycle()``` dengan kembalian nilai boolean.

# Cayo Refreshing
## Verdict
AC Revisi
## Bukti
![soal 4](https://user-images.githubusercontent.com/81814981/120257190-ed3f0280-c2b9-11eb-847c-055db9e680ba.png)

## Penjelasan Soal
Program diminta untuk menghitung berapa jembatan yang diperlukan untuk menghubungkan seluruh pulau.

## Visualisasi Solusi
https://www.geeksforgeeks.org/program-to-count-number-of-connected-components-in-an-undirected-graph/

![connected graph](https://user-images.githubusercontent.com/81814981/120264476-18305300-c2c8-11eb-8bba-df5b4e0b73d3.jpg)

1. program akan menginisialisasi semua vertex sebagai sebuah node yang belum dikunjungi 
2. semua vertex akan mengecek jika vertex tersebut belum dikunjungi, sebanding dengan banyaknya DFS yang dilakukan pada graph, variabel count akan bertambah 1.

## Penjelasan Program
```
int main()
{
    int node, path;
    cin >> node
        >> path;
    Graph g(node);
    int satu, dua;
    while(node--)
    {
        cin >> satu
            >> dua;
        g.addEdge(satu-1, dua-1);
    }
 
    cout << g.NumberOfconnectedComponents()-1;
 
    return 0;
}
```
Pertama program akan memasukkan data-data node yg saling terhubung pada fungsi ```addEdge()```. Setelah itu, program akan memasuki fungsi NumberOfConnectedComponents(). Tiap inputan akan dikurangi 1 karena default dari program mengacu angka awal 1. Sedangkan pada problem kali ini diperintahkan angka awalnya adalah 0.

# Sayonara
## Verdict
Wrong Answer
## Bukti
![soal 5](https://user-images.githubusercontent.com/81814981/120257285-24151880-c2ba-11eb-841e-5935c75171d5.png)

## Ide Solusi
Pertama program akan membuat array dua dimensi untuk merepresentasikan pola yang terbentuk seperti pada soal. Setelah itu, tiap nilai dari array dua dimensi akan disimpan pada sebuah struct untuk mempercepat pencarian ketika program mencari koordinat suatu titik pada array dua dimensi. Setelah itu program akan melakukan algoritma DFS untuk mencapai nilai yang telah ditentukan sebelumnya. 

# Puzzle MudMud
## Verdict
Wrong Answer
##  Bukti
![soal 6](https://user-images.githubusercontent.com/81814981/120257293-29726300-c2ba-11eb-9a1e-c1fd3ecced20.png)

## Ide Solusi
Terdapat dua program dalam soal ini, yang pertama adalah mengecek apakah puzzle dapat diselesaikan. Yang kedua, ketika puzzle diidentifikasi dapat diselesaikan, maka program harus mengeluarkan rentetan penyelesaiannya. Ide baru yang akan dilakukan pada program adalah mengganti algoritma branch and bound pada program saat menampilkan step-stepnya dengan BFS (binary search first).
