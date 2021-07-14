#include <bits/stdc++.h>
#include <fstream>
using namespace std;

#define BUGG(n) cout<<"masuk "<<n;

typedef struct
{
    string nama;
    string nrp;
}data;

bool compare(data a, data b)
{
    return (a.nrp<b.nrp);
}

int main()
{
    int jumlah;
    cout<<"Jumlah data \t:";
    cin >> jumlah;

    // opsi
    /*
        membaca dan mengunggah isi file (last)
        penambahan data
        menampilkan daftar nama dalam keadaan urut
        menampilkan daftar nama
        penghapusan (searching delete)
        dapat merubah nama dan nip baru (last)
    */


    data mahasiswa[jumlah];
    for(int i=0; i<jumlah;i++)
    {
        cout<<"nama mahasiswa \t: ";    
        cin >> mahasiswa[i].nama;
        cout<<"NRP mahasiswa \t: ";
        cin >> mahasiswa[i].nrp;
    }
    sort(mahasiswa, mahasiswa+jumlah, compare);
    BUGG("MASUKKK\n");
    for(int i=0; i<jumlah; i++)
    {
        cout<<mahasiswa[i].nama<<" "<<mahasiswa[i].nrp<<endl;
    }
    return 0;
}