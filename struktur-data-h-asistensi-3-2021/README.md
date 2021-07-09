# Trie
Trie atau biasa disebut dengan prefix tree adalah jenis binary search tree yang biasanya node berisi sebuah string. Konsep Trie layaknya sebuah kamus dimana anggota nodenya akan disusun berdasarkan tiap huruf yang tersedia. Berikut adalah visualisasinya.

![download](https://user-images.githubusercontent.com/81814981/115872278-cfd17a00-a46b-11eb-9583-31c096037f26.png)

Pada contoh di atas, trie adalah sebuah susunan kata yang dibentuk atas node-node pada sebuah tree pada data structure. Ada beberapa hal yang penting pada tree, diantaranya:

1. Isi string pada root tree kosong serta hanya berisikan alamat child root.
2. Tiap data structure berisi node char/string dan pointer `*next` yang menghubungkan antar node.
3. Tiap inputan akan mengikuti jalur hurufnya(apabila ada). jika tidak ada maka akan membuat jalur baru.
4. Setiap inputan kata akan ditandai sebagai prefix dan apabila pada inputan selanjutnya terdapat inputan yang sama dan terdiri dari susunan yang lebih panjang, maka prefix sebelumnya akan terdeteksi. Contoh pada gambar adalah node yang paling kanan, dimana terdiri dari tiga prefix kata, yaitu i, in, dan inn.
5. Tiap akhir prefix akan ditandai dengan variable boolean atau integer yang menandakan true, sedangkan yang lainnya false (lihat tanda angka pada contoh di atas yang menandakan keberadaan prefix dari tiap susunan node).

Penerapan algoritma Trie dapat dilihat pada gambar berikut.

![implementation of trie](https://user-images.githubusercontent.com/81814981/115873214-de6c6100-a46c-11eb-9dcc-779ec2a5a7c8.gif)

Pada sistem autocomplete, terdapat banyak sekali kemungkinan keyword yang muncul. Kemungkinan-kemungkinan tersebut merupakan representasi dari algoritma Trie

## Program Algoritma Trie
### Fungsi ``main()``
```
int main()
{
    struct Trie* head = getNewTrieNode(); 

    insert(head, "hello");
    insert(head, "helloworld");
    insert(head, "hell");
    
    insert(head, "h");
    printf("%d \n", search(head, "h"));         // print 1 + newline
 
    deletion(&head, "hello");
    printf("%d ", search(head, "hello"));       // print 0 (hello deleted)

    deletion(&head, "h");
    deletion(&head, "helloworld");
 
    deletion(&head, "hell");
 
    if (head == NULL) {
        printf("Trie empty!!\n");               // Trie is empty now
    }
 
    printf("%d ", search(head, "hell"));        // print 0
 
    return 0;
}
```
Pertama program akan menginisiasi type data structure ```Trie *head``` menggunakan fungsi getNewTrieNode(). Selanjutnya proses-proses lainnya akan dilakukan berdasarkan nama fungsi di atas.

### fungsi ``insert()``
```
void insert(struct Trie *head, char* str)
{
    // start from the root node
    struct Trie* curr = head;
    while (*str)
    {
        // create a new node if the path doesn't exist
        if (curr->character[*str - 'a'] == NULL) {
            curr->character[*str - 'a'] = getNewTrieNode();
        }
 
        // go to the next node
        curr = curr->character[*str - 'a'];
 
        // move to the next character
        str++;
    }
 
    // mark the current node as a leaf
    curr->isLeaf = 1;
}
```
Program akan memasukkan tiap kata ke nodenya masing-masing yang mana mengikuti aturan autocomplete huruf. program akan mengiterasi terus menerus sampai pointer char ``*str`` bernilai ``NULL``. Setelah bernilai null, maka akan ditandai batas prefix tersebut dengan memberikan nilai ```curr->isleaf=1``` yang artinya variabel tersebut bernilai ```true``` dan mengandung suatu kata atau kalimat.

### fungsi ``search()``
```
int search(struct Trie* head, char* str)
{
    // return 0 if Trie is empty
    if (head == NULL) {
        return 0;
    }
 
    struct Trie* curr = head;
    while (*str)
    {
        // go to the next node
        curr = curr->character[*str - 'a'];
 
        // if the string is invalid (reached end of a path in the Trie)
        if (curr == NULL) {
            return 0;
        }
 
        // move to the next character
        str++;
    }
 
    // return 1 if the current node is a leaf and the
    // end of the string is reached
    return curr->isLeaf;
}
```
Program tersebut mencari apakah nilai batas dari suatu string yang dicari bernilai ```true``` atau ```false```. apabila true berartu string yang dicari pernah diinputkan dan apabila false, maka string yang dicari tidak pernah diinputkan dalam bentuk prefix.
