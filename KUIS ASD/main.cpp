#include <iostream>

using namespace std;

struct data{
    string nama;
    int dd;
    int mm;
    int yyyy;
}barangterjual[15];

void insertionSort(int larik[], int n)
{
    int i, k, j;
    for (i = 1; i < n; i++)
    {
        k = larik[i];
        j = i - 1;

        while (j >= 0 && larik[j] > k)
        {
            larik[j + 1] = larik[j];
            j = j - 1;
        }
        larik[j + 1] = k;
    }
}

void output(int larik[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    cout << larik[i] << " ";
    cout << endl;
}
int main()
{
    cout<<"Mahran Radifan Zhafir\n105219001\n";
    cout<<"nomor 1\nkode setelah di urutkan : ";
    int pilihan;
    int i;
    int n= 10;
    int x= 0;
    int kode[n] = {811, 712, 513, 314, 915,516, 317, 518, 419, 120};
    insertionSort(kode, n);
    output(kode, n);
    cout<<"\n=============\n";

    do{
        cout<<"Masukkan Barang terjual : ";
        cin>>barangterjual[x].nama;
        cout<<"Masukkan tanggal : ";
        cin>>barangterjual[x].dd;
        cout<<"Masukkan bulan : ";
        cin>>barangterjual[x].mm;
        cout<<"Masukkan tahun : ";
        cin>>barangterjual[x].yyyy;
        x++;
        cout<<"Apakah ingin menambah lagi?\n1.ya\n2tidak\n"; cin>>pilihan;

    }while (pilihan==1);

    cout<<"Barang terjual\t\ttanggal terjual\n";
    for(i=0; i<x; i++){
        cout<<barangterjual[i].nama<<"\t\t"<<barangterjual[i].dd<<"-"<<barangterjual[i].mm<<"-"<<barangterjual[i].yyyy<<endl;
    }

    return 0;
}
