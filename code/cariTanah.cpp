#include <bits/stdc++.h>
using namespace std;

void convert (int arr[201][201], int ans[201][201],int baris, int kolom){
    for(int i = 0 ; i < kolom ; i++){
        int total_0 = 0;
        for(int j = 0 ; j < baris ; j++){
            if(arr[j][i] == 1){
                ans[j][i] = 0;
                total_0 = 0;
            }else{
                 total_0++;
                ans[j][i] = total_0;
            }
        }
    }
}

int main()
{
    int q, luas_cari;
    cin >> q >> luas_cari;
    while(q--){
        int baris, kolom;
        cin >> baris >> kolom;
        string map_str[201];
        int conv_map[201][201];
        int ans[201][201];
        for(int i = 0 ; i < baris; i++){
            cin >>map_str[i];
            for(int j = 0 ; j < kolom ; j++){
                conv_map[i][j] = map_str[i][j]-48;
            }
        }
        convert(conv_map,ans,baris,kolom);
        int tinggi_skrng = 1;
        int luas_terbesar = 0;
        for(int i = 0 ; i < baris ; i++){
            int luas_sementara = 0;
            int luas_terbesar_sementara = 0;                                         
            for(int j = 1 ; j <= tinggi_skrng ; j++){
                int cnt = 0;
                int max_cnt = 0;
                for(int k = 0 ; k < kolom ;  k++){
                    if(ans[i][k] >= j) {
                        cnt++;
                    }else{
                        if(max_cnt < cnt)
                        {
                            max_cnt = cnt;
                        }
                        cnt = 0;
                    }
                    if(max_cnt < cnt){
                            max_cnt = cnt;
                          //  cout << "cnt dijadiin max_cnt : " << cnt << endl;
                    }
                }
             //   cout << "max_cnt sebelum luas smentara : " << max_cnt << "j" << j << endl;
                luas_sementara = max_cnt*j;
               // cout << "luas_sementara : " << luas_sementara << endl;
                if(luas_terbesar_sementara < luas_sementara){
                    luas_terbesar_sementara = luas_sementara;
                }
            }
            tinggi_skrng++;
            if( luas_terbesar < luas_terbesar_sementara) {
                 luas_terbesar = luas_terbesar_sementara;
            }
        }

        if(luas_terbesar < luas_cari){
            cout << "TIDAK" << endl;
        }
        else{
            cout << "IYA" << endl;
        }
    }

    return 0;
}