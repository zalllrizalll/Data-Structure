#include<iostream>
#include<conio.h>
#include<vector>
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

vector<int> V;				/*Variabel V - Vector, Untuk Menampung Sebuah Angka*/

// Declare Iterator
vector<int>::iterator iter;

bool isEmpty()
{
    V.empty();
}

void insert_depan(int input)
{
    V.insert(V.begin(), input);
    cout << "Data berhasil masuk ! ";
}

void insert_belakang(int n)
{
    V.push_back(n);
    gotoxy(0,2);
    cout << "Data berhasil masuk";
    gotoxy(0,4);
    cout << "Press Any Key ...";
}

void insert_tengah(int input)
{
    int posisi;
    cout << "Input Data ke posisi : ";cin>> posisi;
    V.insert(V.begin()+posisi, input);
    cout << "Data berhasil masuk !";
}

void delete_depan()
{
    if(isEmpty())
    {
        cout << "Data Kosong";
        gotoxy(0,2);
        cout << "Press Any Key ...";
    }
    else
    {
        // Menghapus elemen vector paling depan
        V.erase(V.begin());
        cout << "Data Berhasil Dihapus !";
        gotoxy(0,2);
        // Menampilkan data menggunakan iterator with for loop
        for(iter = V.begin(); iter != V.end(); ++iter)
        {
            cout << *iter << " ";
        }
        gotoxy(0,4);
        cout << "Press Any Key ...";
    }
}

void delete_belakang()
{
    if(isEmpty())
    {
        cout << "Data Kosong";
        gotoxy(0,2);
        cout << "Press Any Key ...";
    }
    else
    {
        // Menghapus elemen vector paling akhir
        V.pop_back();
        cout << "Data Berhasil Dihapus !";
        gotoxy(0,2);
        // Menampilkan data menggunakan iterator with for loop
        for(iter = V.begin(); iter != V.end(); ++iter)
        {
            cout << *iter << " ";
        }
        gotoxy(0,4);
        cout << "Press Any Key ...";
    }
}

void delete_tengah()
{
    int posisi;
    cout << "Hapus data di posisi : ";cin>> posisi;
    if(isEmpty())
    {
        gotoxy(0,2);
        cout << "Data Kosong";
        gotoxy(0,4);
        cout << "Press Any Key ...";
    }
    else
    {
        // Menghapus elemen vector di tengah
        V.erase(V.begin()+posisi);
        gotoxy(0,2);
        cout << "Data Berhasil Dihapus !";
        gotoxy(0,4);
        // Menampilkan data menggunakan iterator with for loop
        for(iter = V.begin(); iter != V.end(); ++iter)
        {
            cout << *iter << " ";
        }
        gotoxy(0,6);
        cout << "Press Any Key ...";
    }
}

void cari(int cari)
{
    for(int x = 0; x < V.size(); x++)
    {
        if(V[x]==cari)
            cout << "Data : " << cari << " ketemu di posisi " << x << endl;
     }

}

void sort_ascending()
{
    sort(V.begin(), V.end());
    for(auto x : V)
    {
        cout << x << " ";
    }

}

void sort_descending()
{
    sort(V.begin(), V.end(), greater<int>());
    for(auto x : V)
    {
        cout << x << " ";
    }
}

void tampil_data()
{
    if(isEmpty())
    {
        cout << "Data elements of Vector : ";
        gotoxy(0,2);
        cout << "Data Kosong";
        gotoxy(0,4);
        cout << "Press Any Key ...";
    }
    else
    {
        cout << "Data elements of Vector : ";
        gotoxy(0,2);
        // Menampilkan data menggunakan iterator with for loop
        for(iter = V.begin(); iter != V.end(); ++iter)
        {
            cout << *iter << " ";
        }
        gotoxy(0,4);
        cout << "Press Any Key ...";
    }
}

int tampil_menu()
{
    int menu;
    cout << "=======================================\n";
    cout << "\tProgram Menu Vector\t\n";
    cout << "=======================================\n";
    cout<<"1. Menambah Data Didepan"<<endl;
    cout<<"2. Menambah Data Belakang"<<endl;
    cout<<"3. Menambah Data DiTengah"<<endl;
    cout<<"4. Menghapus Data DiDepan"<<endl;
    cout<<"5. Menghapus Data DiBelakang"<<endl;
    cout<<"6. Menghapus Data DiTengah"<<endl;
    cout<<"7. Menampilkan Data"<<endl;
    cout<<"8. Cari Data"<<endl;
    cout<<"9. Sorting Data"<<endl;
    cout<<"10. Keluar"<<endl;

    return menu;

}

int main()
{
    string menu;
	int pilih, n{}, sort_data;

	do
	{
        system("cls");
        menu = tampil_menu();
		cout<<"Pilihan Anda [1-10] : ";cin>>pilih;
		switch(pilih)
		{
            case 1:
            system("cls");
            {
                // tambah data depan
                cout << "Input data : ";
                cin >> n;
                insert_depan(n);
                getch();
                break;
            }
            case 2:
            system("cls");
            {
                // tambah data belakang
                cout << "Input data : ";
                cin >> n;
                insert_belakang(n);
                getch();
                break;
            }
            case 3:
            system("cls");
            {
                // tambah data tengah
                cout << "Input data : ";
                cin >> n;
                insert_tengah(n);
                getch();
                break;
            }
            case 4:
            system("cls");
            {
                // hapus data depan
                delete_depan();
                getch();
                break;
            }
            case 5:
            system("cls");
            {
                // hapus data belakang
                delete_belakang();
                getch();
                break;
            }
            case 6:
            system("cls");
            {
                // hapus data tengah
                delete_tengah();
                getch();
                break;
            }
            case 7:
            system("cls");
            {
                // menampilkan data
                tampil_data();
                getch();
                break;
            }
            case 8:
            system("cls");
            {
                // mencari data
                cout << "Cari elements of vector : ";cin>>n;
                cari(n);
                getch();
                break;
            }
            case 9:
            system("cls");
            {
                cout << "Pilih Sort : "<<endl;
                cout << "1. Ascending"<<endl;
                cout << "2. Descending"<<endl;
                gotoxy(0,4);
                cout << "Masukkan pilihan : ";
                cin>>sort_data;
                gotoxy(0,6);
                cout << "Hasil Sort : ";
                if(sort_data==1)
                {
                    sort_ascending();
                }
                else
                {
                    sort_descending();
                }
                getch();
                break;
            }
            default:
            system("cls");
            {
                cout << "Maaf Pilihan Anda Tidak Tersedia !"<<endl;
            }
		}
	}
	while(pilih!=10);

	return 0;
}
