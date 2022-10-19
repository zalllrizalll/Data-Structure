#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct TNode{
    string target;
    int NilaiX;
    int NilaiY;
    TNode *next;
};

TNode *head, *tail;

void init (){
    head = NULL;
    tail = NULL;
}

int countNodes (struct TNode *p)
{
    int count{};
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

int isEmpty(){
    if(tail==NULL)
        return 1;
    else
        return 0;
}

void insertDepan(int databaru1, int databaru2, string databaru3)
{
    TNode *baru;
    baru = new TNode;
    baru->NilaiX = databaru1;
    baru->NilaiY = databaru2;
    baru->target = databaru3;
    baru->next = NULL;

    if(isEmpty()==1)
        head=tail=baru;
    else
    {
        baru->next = head;
        head=baru;
    }
    cout<<"Data masuk\n";
}

void tampil(){
    TNode *bantu;
    bantu=head;
        if(isEmpty()==0)
        {
            while(bantu!=NULL)
            {
                cout<<"Nilai X = " << bantu->NilaiX <<" "<< "Nilai Y = " << bantu->NilaiY << " " << "Nilai Z = " << bantu->target << endl;
                bantu=bantu->next;
            }
        }
        else
            cout <<"Data Masih kosong\n";
}

void hapusDepan()
{
    TNode *hapus;
    int delete1, delete2;
    string delete3;
    if (isEmpty()==0)
    {
        if(head!=tail)
        {
            hapus=head;
            delete1=hapus->NilaiX;
            delete2 = hapus->NilaiY;
            delete3 = hapus->target;
            head=head->next;
            delete hapus;
        }
        else
        {
            delete1=tail->NilaiX;
            delete2=tail->NilaiY;
            delete3=tail->target;
            head=tail=NULL;
        }
    cout<<delete1 << "," << delete2 << " dan " << delete3 << " Terhapus";
    }
    else
        cout<<"Data Masih kosong\n";
}

void hapus_tengah(int cari1, int cari2, string cari3)
{
    TNode *hapus, *bantu, *bantu2;
    if (isEmpty() == 0)
    {
        bantu = head;
        while ((bantu->NilaiX != cari1) && (bantu->NilaiY != cari2) && (bantu->target != cari3))
        {
            bantu2 = bantu;
            bantu = bantu->next;
        }
        if ((bantu->NilaiX == cari1) && (bantu->NilaiY == cari2) && (bantu->target == cari3))
        {
            if (bantu == head)
            {
                hapus = head;
                head = head->next;
                delete hapus;
            }
            else if (bantu == tail)
            {
                hapus = tail;
                tail = bantu2;
                tail->next = NULL;
                delete hapus;
            }
            else
            {
                bantu2->next = bantu->next;
                delete bantu;
            }
            cout << "Data berhasil dihapus" << endl;
        }
        else
        {
            cout << "Data tidak ditemukan" << endl;
        }
    }
    else
    {
        cout << "Data masih kosong" << endl;
    }
}

void hapusBelakang()
{
    TNode *bantu = tail;
    TNode *hapus = head;
    int delete1, delete2;
    string delete3;
    if (isEmpty()==0)
    {
        for (int i = 0; i < countNodes(head)-2; i++)
            hapus = hapus->next;
        if(hapus->next != NULL)
        {
            delete1=tail->NilaiX;
            delete2 = tail->NilaiY;
            delete3 = tail->target;
            tail = hapus;
            tail->next = NULL;
            delete bantu;
        }
        else
        {
            delete1=tail->NilaiX;
            delete2=tail->NilaiY;
            delete3=tail->target;
            delete bantu;
            head=tail=NULL;
        }
            cout<<delete1 << ", " << delete2 << " dan " << delete3  << " Terhapus";
    }
    else
        cout<<"Data Masih kosong\n";
}
void insertBelakang (int data1, int data2, string data3)
{
    struct TNode *baru;
    baru = new struct TNode;
    baru->NilaiX = data1;
    baru->NilaiY = data2;
    baru->target = data3;
    baru->next = NULL;
    if (isEmpty())
        head = tail = baru;
    else
    {
        tail->next = baru;
        tail = baru;
    }
    cout<<"Data masuk\n";
}

void searchData (int key1, int key2, string key3)
{
    int flag1 {-1};
    int flag2 {-1};
    string flag3 {-1};
    struct TNode *bantu;
    bantu = head;
    while (bantu != NULL)
    {
        if ((bantu->NilaiX == key1) && (bantu->NilaiY == key2) && (bantu->target == key3))
        {
            flag1 =  key1;
            flag2 =  key2;
            flag3 =  key3;
            cout << "Data ditemukan : " << flag1 << ", "<< flag2 << " dan " << flag3 <<endl;
            break;
        }
        else
            cout << "Data tidak ditemukan" << endl;

        bantu = bantu->next;
    }
}

void insertAfter (int data1, int data2, string data3)
{
    struct TNode *bantu = head;
    int cari1{}, cari2{};
    string cari3{};
    cout << "Insert Data Setelah Nilai" << endl;
    cout << "Nilai X = ";
    cin >> cari1;
    cout << "Nilai Y = ";
    cin >> cari2;
    cout << "Nilai Z = ";
    cin >> cari3;
    if (!isEmpty())
    {
        struct TNode *baru;
        baru = new struct TNode;
        baru->NilaiX = data1;
        baru->NilaiY = data2;
        baru->target = data3;
        baru->next = NULL;

        while (bantu != NULL)
        {
            if ((bantu->NilaiX == cari1) && (bantu->NilaiY == cari2) && (bantu->target == cari3))
            {
                if (bantu->next != NULL)
                {
                    baru->next = bantu->next;
                    bantu->next = baru;
                    break;
                }
                else
                {
                    bantu->next = baru;
                    tail = baru;
                }
            }
            bantu = bantu->next;
        }
    }
    else
        cout << "Data tidak ditemukan" << endl;
}

void insertBefore (int data1, int data2, string data3)
{
    struct TNode *bantu = head;
    int cari1{}, cari2{};
    string cari3{};
    cout << "Insert Data Sebelum Nilai" << endl;
    cout << "Sebelum Nilai X = ";
    cin >> cari1;
    cout << "Sebelum Nilai Y = ";
    cin >> cari2;
    cout << "Sebelum Nilai Z = ";
    cin >> cari3;
    if (!isEmpty())
    {
        struct TNode *baru;
        baru = new struct TNode;
        baru->NilaiX = data1;
        baru->NilaiY = data2;
        baru->target = data3;
        baru->next = NULL;

        while (bantu != NULL)
        {
            if ((bantu->next->NilaiX == cari1) && (bantu->next->NilaiY == cari2) && (bantu->next->target == cari3))
            {
                if (bantu->next != NULL)
                {
                    baru->next = bantu->next;
                    bantu->next = baru;
                    break;
                }
                else
                {
                    bantu->next = head;
                    head = baru;
                }
            }
            bantu = bantu->next;
        }
        cout<<"Data Berhasil Ditambahkan sebelum ("<<cari1<<", "<<cari2<<", "<<cari3<<")";
    }
    else
        cout << "Data tidak ditemukan" << endl;
}
void clear()
{
    TNode *bantu, *hapus;
    bantu =head;
    while(bantu!=NULL)
    {
        hapus=bantu;
        bantu=bantu->next;
        delete hapus;
    }
    head = NULL;
    printf("clear");
}
int nama_menu(){
	cout <<"====================================================="<<endl;
	cout <<"Nama : Muhammad Rizal Pratama\t NIM = A11.2021.13329"<<endl;
	cout <<"====================================================="<<endl<<endl;
	cout<<"\t\t    SINGLE LINKED LIST"<<endl;
	int menu;
	cout << "MENU : "<<endl<<endl;
    cout<<" ============================"<<endl;
    cout<<" =   PROGRAM LINKED LIST    ="<<endl;
    cout<<" ============================"<<endl;
    cout<<" = 1. Insert Depan          ="<<endl;
    cout<<" = 2. Insert Belakang       ="<<endl;
    cout<<" = 3. Insert After          ="<<endl;
    cout<<" = 4. Insert Before         ="<<endl;
    cout<<" = 5. Delete Depan          ="<<endl;
    cout<<" = 6. Delete Tengah         ="<<endl;
    cout<<" = 7. Delete Belakang       ="<<endl;
    cout<<" = 8. Tampil Data           ="<<endl;
    cout<<" = 9. Cari Data             ="<<endl;
    cout<<" = 10. Clear                ="<<endl;
    cout<<" = 11. Exit                 ="<<endl;
    cout<<" ============================"<<endl;
	return menu;
}

int main()
{
    int pil{}, databaru1{},databaru2{};
    string databaru3{};
    int cari1{}, cari2{};
    string cari3{};

    string menu;


    do
    {
        system("cls");
        tampil();
        menu = nama_menu();

        cout<<" Masukan Pilihan : ";cin>>pil;
        switch (pil)
        {
            case 1: system("cls");{
                cout <<"Masukan Nilai X = ";
                cin >> databaru1;
                cout << "Masukkan Nilai Y = ";
                cin >> databaru2;
                cout << "Masukkan Nilai Z = ";
                cin >> databaru3;
                insertDepan(databaru1, databaru2, databaru3);
                break;
            }
            case 2: system("cls");{
                cout<<"Masukan Nilai X = ";
                cin >> databaru1;
                cout << "Masukkan Nilai Y = ";
                cin >> databaru2;
                cout << "Masukkan Nilai Z = ";
                cin >> databaru3;
                insertBelakang(databaru1, databaru2, databaru3);
                break;
            }
            case 3: system("cls");{
                cout<<"Masukan Nilai X = ";
                cin >> databaru1;
                cout << "Masukkan Nilai Y = ";
                cin >> databaru2;
                cout << "Masukkan Nilai Z = ";
                cin >> databaru3;
                insertAfter(databaru1, databaru2, databaru3);
                break;
            }
            case 4: system("cls");{
                cout<<"Masukan Nilai X = ";
                cin >> databaru1;
                cout << "Masukkan Nilai Y = ";
                cin >> databaru2;
                cout << "Masukkan Nilai Z = ";
                cin >> databaru3;
                insertBefore(databaru1, databaru2, databaru3);
                break;
            }
            case 5: system("cls");{
                hapusDepan();
                break;
            }
            case 6: system("cls");{
                cout << "Masukkan nilai X yang akan dihapus : ";
                cin >> cari1;
                cout << "Masukkan nilai Y yang akan dihapus : ";
                cin >> cari2;
                cout << "Masukkan nilai Z yang akan dihapus : ";
                cin >> cari3;
                hapus_tengah(cari1, cari2, cari3);
                break;
            }
            case 7: system("cls");{
                hapusBelakang();
                break;
            }
            case 8: system("cls");
            {
                tampil();
                break;
            }
            case 9: system("cls");{
                if (!isEmpty())
                {
                    cout << "Cari Data" << endl;
                    cout << "Nilai X = ";
                    cin >> databaru1;
                    cout << "Nilai Y = ";
                    cin >> databaru2;
                    cout << "Nilai Z = ";
                    cin >> databaru3;
                    searchData(databaru1, databaru2, databaru3);
                }
                else
                    cout << "Data masih kosong" << endl;
                break;
            }
            case 10: system("cls");{
                clear();
                break;
            }
            case 11: system("cls");{
                return 0;
                break;
            }
            default : system("cls");
            {
                cout<<"\n Maaf, Pilihan yang anda pilih tidak tersedia!";
            }
        }
        getch();
    }
    while (pil!=10);
    return 0;
}
