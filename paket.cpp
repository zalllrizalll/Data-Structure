#include<iostream>
#include<conio.h>
#include<windows.h>

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


using namespace std;
struct paket
{
    char jenis_brg[30];
    int berat;
    char kota[30];
};

struct paket kirim[100];

/*******************************************/
void bersihlayar()
{
    for(int a=0;a<80;a++)
    {
        for(int b=0;b<=24;b++)
        {
            gotoxy(a,b);cout<<" ";
        }
    }
}

void tambahdata(int x, int y)
{
    if (x <= y)
    {
     gotoxy(20,15);cout<<"Inputkan Jenis Barang    :";
     cin>>kirim[x].jenis_brg;
     gotoxy(20,16);cout<<"Inputkan Berat           :";
     cin>>kirim[x].berat;
     gotoxy(20,17);cout<<"Inputkan Kota Tujuan     :";
     cin>>kirim[x].kota;
    }

    gotoxy(20,19);cout<<"Press Any Key...";
}

void tampildata(int x, int y)
{
    if(x-1 <= y)
    {
        gotoxy(40,10);cout<<"Daftar Kiriman Paket"<<endl;
        gotoxy(40,15);cout << "Data Kosong";
    }
    else
    {
        gotoxy(40,10);cout<<"Daftar Kiriman Paket"<<endl;
        for(int a=1; a<x; a++)
        {
            gotoxy(40,19-a);
            cout<<a<<" ";
            cout<<kirim[a].jenis_brg<<" ";
            cout<<kirim[a].berat<<" ";
            cout<<kirim[a].kota<<endl;
        }
    }

    gotoxy(40,20);
    cout<<"Press Any Key...";
    getch();
    /*harus Ijin --> #include<conio.h>*/
}

void hapusdata(int x, int y)
{
    if (x > y)
    {
        gotoxy(40,12);cout<<"Data Terakhir yang anda Hapus Adalah :"<<endl;
        gotoxy(40,13);cout<<kirim[x].jenis_brg<<" ";
        cout<<kirim[x].berat<<" Kg ";
        cout<<kirim[x].kota<<endl<<endl;
    } else
        cout << "Sorry Stack is Empty";

    gotoxy(40,15);cout<<"Press Any Key...";
    getch();
}

int main()
{
    int pilih;
    int datake = 1;
    int Min = 0;
    int Max;

    gotoxy(15,0);cout << "PROGRAM STACK C++";
    gotoxy(0,2);cout << "Masukkan Maksimal Jumlah Barang : ";
    cin >> Max;
    do
    {
        bersihlayar();
        gotoxy(1,1);cout<<"MENU UTAMA";
        gotoxy(1,2);cout<<"1. Tambah Data";
        gotoxy(1,3);cout<<"2. Hapus Data Terakhir"<<endl;
        gotoxy(1,4);cout<<"3. Tampil Data"<<endl;
        gotoxy(1,5);cout<<"9. Keluar"<<endl;

        gotoxy(1,7);cout<<"Pilihan Anda [1-9] : ";
        cin>>pilih;
        if(pilih==1)
            { /*Menambah data baru diletakan di DATAKE*/
                if (datake <= Max)
                {
                    tambahdata(datake, Max);
                    datake++;
                } else
                    cout << "Sorry Stack is Full!!!";
                    gotoxy(20,19);cout<<"Press Any Key...";
                    getch();
            }
        if(pilih==2)
            { /*Menghapus Data Terakhir (DATAKE-1*/
                hapusdata(datake-1, Min);
                datake--;
            }
        if(pilih==3) /*Menampilkan Data mulai data ke-1 hingga DATAKE*/
            tampildata(datake, Min);

    }
    while(pilih!=9);
    return 0;
}
