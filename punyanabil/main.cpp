#include <iostream>
using namespace std;

void modus();
void hapusdata();
void urut();
void output();
void swap(int a,int b);
void swap(string a,string b);
void input();


    int pilih,money,klaim[100],tanggal[100],totalkl[100],tgl[20],bln[20],yr[20],klaim_hari[100];
    string nama[100],polis[100];
    int i=0,iterati;

int main()
{
    cout << "===================ASURANSI===================" << endl;
    cout << " (1) input data " << endl;
    cout << " (2) cari modus data " << endl;
    cout << " (3) tampilkan data " << endl;
    cout << " (4) hapus data " << endl;
    cout << " (5) keluar " << endl;

    while (pilih != 5)
  {
    cout << "|-| masukkan pilihan : " ; cin >> pilih;
    cout << "==============================================" << endl;

    if (pilih == 1)
    {
        /*cout << "Nama : " ; cin >> nama[i];
        cin.ignore();
        cout << "No. polis : " ; getline(cin,polis[i]);
        cout << "klaim : " ; cin >> klaim[i];
        cout << "tanggal : " ; cin >> tanggal[i];
        cout << "bulan : " ; cin >> bln[i];
        cout << "tahun : " ; cin >> yr[i];
        cout << "==============================================" << endl; */
        input();

    }
     //i++;
     if (pilih == 2)
      {

      }else if (pilih == 3)
         {
            cout << "nama\tno.polis\tklaim\ttanggal\tbulan\ttahun" << endl;
            urut();
            cout << "==============================================" << endl;
         }else if (pilih == 4)
             {

             }
  }

}

void input()
{
  int uang;
        cout << "Nama : " ; cin >> nama[i];
        cin.ignore();
        cout << "No. polis : " ; getline(cin,polis[i]);
        cout << "klaim : " ; cin >> money;
         if (money <= 10000000)
         {
             klaim[i] = money;
             cout << "tanggal : " ; cin >> tanggal[i];
             cout << "bulan : " ; cin >> bln[i];
             cout << "tahun : " ; cin >> yr[i];
             cout << "==============================================" << endl;
             klaim_hari[i]=tanggal[i]+(30*bln[i])+(365*yr[i]);
             i++;
         }

        cout << "==============================================" << endl;
}

void swap(int *a,int *b)
{
   int sum = *a;
   *a = *b;
   *b = sum;
}

void swap(string *a,string *b)
{
    string sum = *a;
    *a = *b;
    *b = sum;

}

void urut()
{
    iterati = i;
  for (int j = 0;j < iterati-1;j++)
  {
      for (int k = 0;k <iterati-j-1;k--)
      {
          if (klaim_hari[k] > klaim_hari[k+1])
         {
           swap(&nama[k],&nama[k+1]);
           swap(&polis[k],&polis[k+1]);
           swap(&klaim[k],&klaim[k+1]);
           swap(&tanggal[k],&tanggal[k+1]);
           swap(&bln[k],&bln[k+1]);
           swap(&yr[k],&yr[k+1]);
           swap(&klaim_hari[k],&klaim_hari[k+1]);
         }
      }
  }

  for (int x = 0;x < i;x++)
  {
     cout << nama[x] << "\t" << polis[x] << "\t" << klaim[x] << "\t" << tanggal[x] << "\t" << bln[x] << "\t" << yr[x] << endl;
  }

}

