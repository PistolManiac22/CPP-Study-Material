#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack <string> s;
    stack <string> temporary;
    string push, cari;
    int banyak, opsi, pop;
    bool found = false;
    do
    {
        cout << "Opsi : " << endl;
        cout << "1. Tambah Bookmark" << endl;
        cout << "2. Hapus Bookmark" << endl;
        cout << "3. Cari Bookmark" << endl;
        cout << "4. Tampilkan Semua Bookmark" << endl;
        cout << "5. Exit" << endl;
        cout << "Pilih : " ; cin >> opsi;
        cout << endl << endl ;
        switch (opsi) 
        {
            case 1 :
            cout << "Anda ingin menambahkan berapa bookmark : " ; cin >> banyak;
            for (int i = 1 ; i <= banyak ; i++)
            {
                cout << "Masukkan nama tempat : " ; cin >> push;
                s.push(push);
            }
            goto akhir;
            case 2 :
            if (!s.empty())
            {
                cout << "Anda ingin menghapus berapa banyak bookmark terbaru : " ; cin >> pop;
                for (int a = 1 ; a <= pop ; a++)
                {
                    s.pop();
                }
            }
            else 
            {
                cout << "Bookmark Kosong!" << endl;
            }
            goto akhir;
            case 3 :
            if (!s.empty())
            {
                cout << "Masukkan nama bookmark yang ingin dicari : " ; cin >> cari;
                cout << endl;
                for ( temporary = s; !temporary.empty() ; temporary.pop())
                {
                    if (cari == temporary.top())
                    {
                        cout << "Bookmark Ditemukan!" << endl;
                        found = true;
                    }
                }
                if (found != true)
                {
                    cout << "Bookmark Tidak Ditemukan!" << endl;
                }
            }
            else 
            {
                cout << "Bookmark Kosong!" << endl;
            }
            goto akhir;
            case 4 :
            if (!s.empty())
            {
                for ( temporary = s; !temporary.empty() ; temporary.pop())
                {
                    cout << temporary.top() << endl;
                }
            }
            else 
            {
                cout << "Bookmark Kosong!" << endl;
            }
            goto akhir;
        }
        akhir :;
        cout << endl << endl;
    } while (opsi != 5);
}