/*
Ahmad Ferdiansyah Ramadhani
5025201218
Struktur Data H
*/

#include <bits/stdc++.h>
#include <fstream>
using namespace std;

#define BUGG(n) cout << "masuk " << n << endl;

class Database
{
private:
    //isi data
    vector<pair<string, string>> pegawai;
    //tabel
    int range_tabel = 6;
    int temp_tabel = 0;
    //input output dan user interface
    string name, nip;
    string pilihan;
    //for read files
    ifstream rfiles;
    //for print new data file in table
    ofstream nfiles;

public:
    void get_data_files();
    void toupper_data();
    void get_range_table();
    void sort_data_upload();
    void option();
    void get_option();
    void add_data();
    void show_data();
    void show_data_name_nip();
    void upload_data();
    void print_files();
    void delete_data();
    void delete_all_data();
    void delete_a_data();
    void change_data();
};

bool comp(pair<string, string> &a, pair<string, string> &b)
{
    if (a.second.size() == b.second.size())
        return (a.second < b.second);
    else
        return (a.second.size() < b.second.size());
}

bool comp_sort(pair<string, string> &a, pair<string, string> &b)
{
    return (a.second < b.second);
}

int upperBound(string acuan, vector<pair<string, string>> pegawai, int l, int r)
{
    int mid = l + (r - l) / 2;
    while (l < r)
    {
        if (pegawai[mid].second <= acuan)
            l = mid + 1;
        else
            r = mid;
        mid = l + (r - l) / 2;
    }
    return mid - 1;
}

void Database::get_data_files()
{
    rfiles.open("nip.txt", fstream::in);
    if (rfiles)
    {
        bool handle = false;
        int status = 0;
        while (!rfiles.eof())
        {
            if (!handle || status == 1)
            {
                getline(rfiles, name);
                toupper_data();
                if (name[0] == ' ' || name.size() == 0)
                {
                    status = 1;
                    handle = true;
                }
                else
                {
                    status = 0;
                    handle = false;
                }
                get_range_table();
            }
            if (!handle || status == 2)
            {
                getline(rfiles, nip);
                if (nip[0] == ' ' || nip.size() == 0)
                {
                    status = 2;
                    handle = true;
                }
                else
                {
                    status = 0;
                    handle = false;
                }
                get_range_table();
            }
            if (!handle)
                pegawai.push_back(make_pair(name, nip));
        }
    }
    rfiles.close();
    if (temp_tabel == 0)
    {
        upload_data();
    }
}

void Database::toupper_data()
{
    for (int i = 0; i < name.size(); i++)
    {
        if (name[i] >= 'a')
            name[i] = name[i] - ('a' - 'A');
    }
}

void Database::get_range_table()
{
    if (range_tabel < nip.size())
        range_tabel = nip.size();
    if (range_tabel < name.size())
        range_tabel = name.size();

    if (temp_tabel < nip.size())
        temp_tabel = nip.size();
    if (temp_tabel < name.size())
        temp_tabel = name.size();
}

void Database::sort_data_upload()
{
    sort(pegawai.begin(), pegawai.end());
    upload_data();
}

void Database::upload_data()
{
    nfiles.open("nip.txt", fstream::out);
    if (temp_tabel == 0)
        pegawai.clear();
    else
    {
        for (auto it : pegawai)
        {
            nfiles << it.first
                   << endl
                   << it.second
                   << endl;
        }
    }
    nfiles.close();
}

void Database::option()
{
    cout << "\n-------Pilihan/opsi----------\n";
    cout << "1. menambahkan data\n";
    cout << "2. menampilkan data\n";
    cout << "3. menghapus data\n";
    cout << "4. merubah data\n";
    cout << "5. keluar\n";
    cout << "-----------------------------\n";
    cout << "masukkan opsi angka : ";
    cin >> pilihan;
    cout << "-----------------------------\n";
    get_option();
}

void Database::get_option()
{
    if (pilihan == "1")
        add_data();
    else if (pilihan == "2")
        show_data();
    else if (pilihan == "3")
        delete_data();
    else if (pilihan == "4")
        change_data();
    else if (pilihan == "5")
        exit(0);
    else
    {
        cout << "ERROR number do not exist\n";
        option();
    }
}

void Database::add_data()
{
    cout << "Apakah Anda yakin ingin menambahkan data?(Y/N)\t: ";
    cin >> pilihan;
    if (pilihan == "y" || pilihan == "Y")
    {
        cout << "masukkan nama\t\t: ";
        getchar();
        getline(cin, name);
        toupper_data();

    a:
        cout << "masukkan NIP \t\t: ";
        cin >> nip;
        sort(pegawai.begin(), pegawai.end(), comp_sort);
        int index = upperBound(nip, pegawai, 0, pegawai.size());
        if (pegawai.size() != 0 && nip == pegawai[index].second)
        {
            cout << "\n------NIP SUDAH DIGUNAKAN------\n";
            goto a;
        }
        get_range_table();
        pegawai.push_back(make_pair(name, nip));
        sort_data_upload();
        cout << "\n\n----DATA BERHASIL DITAMBAHKAN----\n";
    }
}

///////////////////////////
//TAMPILAN DATA MAHASISWA//
///////////////////////////

void Database::show_data()
{
    if (pegawai.size() != 0)
    {
    a:
        cout << "\nTampilkan data urut berdasarkan :\n";
        cout << "1. Nama\n";
        cout << "2. NIP\n";
        cout << "3. Kembali ke menu utama\n";
        cout << "-----------------------------\n";
        cout << "masukkan pilihan (1/2/3)\t: ";
        cin >> pilihan;
        if (pilihan != "3")
        {
            if (pilihan != "1" && pilihan != "2")
            {
                cout << "\nERROR!! angka tidak tersedia\n";
                goto a;
            }
            show_data_name_nip();
            cout << "\nApakah data ingin dicetak? (Y/N): ";
            string choice;
            cin >> choice;
            if (choice == "Y" || choice == "y")
                print_files();
        }
    }
    else
    {
        remove("data_cetak.txt");
        cout << "\n-------- DATA KOSONG --------\n";
    }
}

void Database::show_data_name_nip()
{
    cout << left;
    for (int i = 0; i < 2 * range_tabel + 7; i++)
        cout << "-";
    cout << endl;

    if (pilihan == "1")
    {
        sort(pegawai.begin(), pegawai.end());
        cout << "|" << setw(range_tabel + 2) << "NAMA"
             << "|" << setw(range_tabel + 2) << "NIP"
             << "|" << endl;
        for (int i = 0; i < 2 * range_tabel + 7; i++)
            cout << "-";
        cout << endl;
        for (auto it : pegawai)
        {
            cout << "|" << setw(range_tabel + 2) << it.first << "|" << setw(range_tabel + 2) << it.second << "|" << endl;
        }
        for (int i = 0; i < 2 * range_tabel + 7; i++)
            cout << "-";
        cout << endl;
        sort_data_upload();
    }
    else
    {
        sort(pegawai.begin(), pegawai.end(), comp);
        cout << "|" << setw(range_tabel + 2) << "NIP"
             << "|" << setw(range_tabel + 2) << "NAMA"
             << "|" << endl;
        for (int i = 0; i < 2 * range_tabel + 7; i++)
            cout << "-";
        cout << endl;
        for (auto it : pegawai)
        {
            cout << "|" << setw(range_tabel + 2) << it.second << "|" << setw(range_tabel + 2) << it.first << "|" << endl;
        }
        for (int i = 0; i < 2 * range_tabel + 7; i++)
            cout << "-";
        cout << endl;
    }
}

void Database::print_files()
{
    nfiles.open("data_cetak.txt", fstream::out);
    nfiles << left;
    for (int i = 0; i < 2 * range_tabel + 7; i++)
        nfiles << "-";
    nfiles << endl;

    if (pilihan == "1")
    {
        sort(pegawai.begin(), pegawai.end());
        nfiles << "|" << setw(range_tabel + 2) << "NAMA"
               << "|" << setw(range_tabel + 2) << "NIP"
               << "|\n";
        for (int i = 0; i < 2 * range_tabel + 7; i++)
            nfiles << "-";
        nfiles << endl;
        for (auto it : pegawai)
        {
            nfiles << "|" << setw(range_tabel + 2) << it.first << "|" << setw(range_tabel + 2) << it.second << "|" << endl;
        }
        for (int i = 0; i < 2 * range_tabel + 7; i++)
            nfiles << "-";
        nfiles << endl;
        sort_data_upload();
    }
    else
    {
        sort(pegawai.begin(), pegawai.end(), comp);
        nfiles << "|" << setw(range_tabel + 2) << "NIP"
               << "|" << setw(range_tabel + 2) << "NAMA"
               << "|\n";
        for (int i = 0; i < 2 * range_tabel + 7; i++)
            nfiles << "-";
        nfiles << endl;
        for (auto it : pegawai)
        {
            nfiles << "|" << setw(range_tabel + 2) << it.second << "|" << setw(range_tabel + 2) << it.first << "|" << endl;
        }
        for (int i = 0; i < 2 * range_tabel + 7; i++)
            nfiles << "-";
        nfiles << endl;
    }
    nfiles.close();
    cout << "\n-----DATA BERHASIL DICETAK-----\n";
}

/////////////////////////////////
//BATAS TAMPILAN DATA MAHASISWA//
/////////////////////////////////

void Database::delete_data()
{
    if (temp_tabel != 0)
    {
    a:
        cout << "Opsi Hapus data\n";
        cout << "1. Hapus satu data\n";
        cout << "2. Hapus semua data\n";
        cout << "3. Kembali ke menu utama\n";
        cout << "Masukkan pilihan \t: ";
        cin >> pilihan;

        if (pilihan == "1")
            delete_a_data();
        else if (pilihan == "2")
            delete_all_data();
        else if (pilihan != "3")
        {
            cout << "Angka tidak valid\n";
            goto a;
        }
    }
    else
    {
        cout << "\n-------- DATA KOSONG --------\n";
    }
}

void Database::delete_a_data()
{
    cout << "masukkan nama\t\t: ";
    getchar();
    getline(cin, name);
    toupper_data();
    cout << "masukkan NIP\t\t: ";
    cin >> nip;

    sort(pegawai.begin(), pegawai.end(), comp_sort);
    int index = upperBound(nip, pegawai, 0, pegawai.size());
    if (pegawai[index].first == name && pegawai[index].second == nip)
    {
        cout << "\nApakah Anda yakin menghapus data Berikut ? (Y/N): ";
        cin >> pilihan;
        if (pilihan == "y" || pilihan == "Y")
        {
            pegawai.erase(pegawai.begin() + index);
            nfiles.open("nip.txt", fstream::out);
            nfiles.close();
            cout << "\n-----DATA TELAH DIHAPUS-----\n";
        }
    }
    else
        cout << "\nNama dan/ NIP yang Anda masukkan tidak tersedia\n";
    sort_data_upload();
}

void Database::delete_all_data()
{
    cout << "Apakah yakin menghapus semua data? (Y/N)\t: ";
    cin >> pilihan;
    if (pilihan == "y" || pilihan == "Y")
    {
        pegawai.clear();
        range_tabel = 6;
        temp_tabel = 0;
        upload_data();
        cout << "\n----DATA TELAH DIHAPUS----\n";
    }
}

void Database::change_data()
{
    if (temp_tabel != 0)
    {
        cout << "Apakah Anda yakin akan merubah data?(Y/N)\t: ";
        cin >> pilihan;
        if (pilihan == "y" || pilihan == "Y")
        {
            cout << "masukkan nama\t: ";
            getchar();
            getline(cin, name);
            toupper_data();
            cout << "masukkan NIP\t: ";
            cin >> nip;

            sort(pegawai.begin(), pegawai.end(), comp_sort);
            int index = upperBound(nip, pegawai, 0, pegawai.size());

            if (pegawai[index].first == name && pegawai[index].second == nip)
            {
            a:
                cout << "\nData yang akan dirubah\n";
                cout << "1. nama\n";
                cout << "2. nip\n";
                cout << "masukkan pilihan angka \t: ";
                string pilihan;
                cin >> pilihan;
                cout << "-----------------------------\n";
                if (pilihan == "1")
                {
                    cout << "masukkan nama baru\t: ";
                    getchar();
                    getline(cin, name);
                    toupper_data();
                    pegawai[index].first = name;
                }
                else if (pilihan == "2")
                {
                    cout << "masukkan NIP baru\t: ";
                    cin >> nip;
                    pegawai[index].second = nip;
                }
                else
                {
                    cout << "Pilihan tidak valid\n";
                    goto a;
                }
                cout << "\n-----DATA TELAH DIRUBAH-----\n";
            }
            else
                cout << "\nNAMA DAN/ NIP TIDAK TERSEDIA\n";
            sort_data_upload();
        }
    }
    else
    {
        cout << "\n-------- DATA KOSONG --------\n";
    }
}

int main()
{
    Database data;
    data.get_data_files();
    data.sort_data_upload();
    while (1)
    {
        data.option();
    }
    return 0;
}