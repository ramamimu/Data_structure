#include <bits/stdc++.h>
#include <fstream>

using namespace std;

#define BUGG(n) cout<<"masuk "<<n;

void is_read_o(ofstream &files)
{
    if(!files)
    {
        cout<<"File is fail to created\n";
    }
    else
        cout<<"success\n";
}
void is_read_i(ifstream &files)
{
    if(!files)
    {
        cout<<"File is fail to created\n";
    }
    else
        cout<<"success\n";
}

int main()
{
    ofstream files;
    ofstream rfiles;
    ifstream wfiles;
    // rfiles.open("nip.txt", fstream::out);
    files.open("baru.txt", fstream::app);
    wfiles.open("baru.txt", fstream::in);
    is_read_o(files);
    is_read_i(wfiles);
    
    vector <string> p;
    string temp;
    int index=0;
    // files << "helllo\n";
    files << "first experience\n";
    while(!wfiles.eof())
    {
        // cout<<index<<endl;
        // files >> temp;
        getline(wfiles, temp);
        p.push_back(temp);
        index++;
    }
 
    temp = "sahabat sejati preketek";
    char abuh[100]="uwuu asdkjad";
    int a=1000;
    files << abuh;
    files << temp;
    files << a<<endl;
    files <<"yakailllll\n";
    // stringstream ss;
    for(auto it:p)
    {
        // ss << it;
        // files.open (ss.str().c_str());
        // files << ss;
        cout<<it<<endl;
        // cout<<p[i]<<endl;
        // files << p[i];
        files << it <<endl;
    }
    cout<<"hello\n";
    // rfiles.open("nip.txt", fstream::out);
    // rfiles<<"hello\n";
   files.close();  
    return 0;
}