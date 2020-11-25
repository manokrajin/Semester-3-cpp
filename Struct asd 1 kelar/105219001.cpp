#include <iostream>

using namespace std;
int indeks=0;
struct inventory{
    string nama, jenis, harga, stok, lokasi;
}data[50];

int masukan(int indeks){
    cout<<"masukkan barang anda : ";     cin>>data[indeks].nama;
    cout<<"masukkan jenis barang : ";     cin>>data[indeks].jenis;
    cout<<"masukkan harga barang : ";    cin>>data[indeks].harga;
    cout<<"masukkan stok barang : ";     cin>>data[indeks].stok;
    cout<<"masukkan lokasi barang : ";  cin>>data[indeks].lokasi;
    return indeks;
}

int keluaran(int indeks){
    cout<<"nama\t\tjenis\t\tharga\t\tstok\t\tlokasi"<<endl;
    for(int x = 0; x<indeks; x++){
        cout<<data[x].nama<<"\t\t"<<data[x].jenis<<"\t\t"<<data[x].harga<<"\t\t"<<data[x].stok<<"\t\t"<<data[x].lokasi<<endl;
    }
}
int main()
{
    int menu;
    do{
    menu=0;
        cout<<"1. Tambah inventory  2.Show Inventory    0.to exit \n pilih menu : ";
        cin>>menu;

        if(menu == 1){
            masukan(indeks);
            indeks++;
        }
        if(menu == 2){
            keluaran(indeks);
        }

    }while(menu != 0);
    cout<<"goodbye!";
    return 0;
}
