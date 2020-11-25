#include <iostream>
using namespace std;
int iterasi=0;
struct data {
    string nama;
    string polis;
    int uang;
    int tanggal;
    int bulan;
    int tahun;
    int jumlahhari;
}klaim[50];

void swap(int *xp, int *yp)  { //FUNGSI SWAP INTEGER
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swap(string *xp, string *yp)  { //FUNGSI SWAP STRING
    string temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void inputan(){ // INPUT
    int uang;
    int totaluang=0;
    int x;
    cout<<"Masukkan nama anda : "; cin>>klaim[iterasi].nama;
    cin.ignore();
    cout<<"Masukkan no polisi anda : "; getline(cin, klaim[iterasi].polis);
    for (x=0 ; x<iterasi ; x++){
        if(klaim[x].polis==klaim[iterasi].polis){
            totaluang=totaluang+klaim[x].uang;
        }
    }
    cout<<"Masukkan klaim anda : "; cin>>uang;
    totaluang=uang+totaluang;
        if (totaluang <= 10000000){
            klaim[iterasi].uang = uang ;
            cout<<"Masukkan Tanggal Inputan : "; cin>>klaim[iterasi].tanggal;
            cout<<"Masukkan Bulan Inputan : "; cin>>klaim[iterasi].bulan;
            cout<<"Masukkan Tahun Inputan : "; cin>>klaim[iterasi].tahun;
            klaim[iterasi].jumlahhari=klaim[iterasi].tanggal+(30*klaim[iterasi].bulan)+(365*klaim[iterasi].tahun);
            iterasi++;
        }
        if (totaluang > 10000000){
            cout<<"POLIS DITOLAK!!";
        }


}

void hapus(){ //DELETE
    string nama;
    int tanggalhapus,bulanhapus,tahunhapus, x,jumlahharihapus, indeksbaru;
    cout<<"Masukkan nama yang ingin anda hapus : "; cin>>nama;
    cout<<"cocokkan tanggal : "; cin>>tanggalhapus;
    cout<<"cocokkan bulan : "; cin>>bulanhapus;
    cout<<"cocokkan tahun : "; cin>>tahunhapus;
    jumlahharihapus=tanggalhapus+(30*bulanhapus)+(365*tahunhapus);
    for (x=0 ; x<iterasi ; x++){
        if (nama==klaim[x].nama){
            if(jumlahharihapus==klaim[x].jumlahhari){
                for (indeksbaru=x; indeksbaru<iterasi; indeksbaru++){
                    klaim[indeksbaru].nama=klaim[indeksbaru+1].nama;
                    klaim[indeksbaru].polis=klaim[indeksbaru+1].polis;
                    klaim[indeksbaru].uang=klaim[indeksbaru+1].uang;
                    klaim[indeksbaru].tanggal=klaim[indeksbaru+1].tanggal;
                    klaim[indeksbaru].bulan=klaim[indeksbaru+1].bulan;
                    klaim[indeksbaru].tahun=klaim[indeksbaru+1].tahun;
                    klaim[indeksbaru].jumlahhari=klaim[indeksbaru+1].jumlahhari;
                }
            }
        }
    }
    iterasi--;
}

void tampilan(){ //OUTPUT
    int i, j , x;
    for (i = 0; i < iterasi-1; i++){ //BUBBLE SORT
        for (j = 0; j < iterasi-i-1; j++){
            if (klaim[j].jumlahhari > klaim[j+1].jumlahhari){
                swap(&klaim[j].nama, &klaim[j+1].nama);
                swap(&klaim[j].polis, &klaim[j+1].polis);
                swap(&klaim[j].uang, &klaim[j+1].uang);
                swap(&klaim[j].tanggal, &klaim[j+1].tanggal);
                swap(&klaim[j].bulan, &klaim[j+1].bulan);
                swap(&klaim[j].tahun, &klaim[j+1].tahun);
                swap(&klaim[j].jumlahhari, &klaim[j+1].jumlahhari);
            }
        }
    }

    cout<<"Nama \t\t no.polis \t\t klaim \t\t tanggal"<<endl;
    for( x=0 ; x < iterasi ; x++){
        cout<<klaim[x].nama<<"\t\t"<<klaim[x].polis<<"\t\t"<<klaim[x].uang<<"\t\t"<<klaim[x].tanggal<<"/"<<klaim[x].bulan<<"/"<<klaim[x].tahun<<endl;
    }
}

void modus(){
    string namamodus;
    int x;
    int modus=0;
    void tampilan();
    cout<<"masukkan nama yang dicari : "; cin>>namamodus;

    for( x=0 ; x<iterasi ; x++){
        if (namamodus==klaim[x].nama){
            modus++;
        }
    }
    cout<<namamodus<<" keluar sebanyak : "<<modus<<" kali"<<endl;
}

int main()
{
    int pilihan=0;
    do{
        cout<<"\n==========================\t";
        cout<<"\nMasukkan Pilihan anda : \n 1.Input Data\n 2.Hapus Data\n 3.Tampilkan Data\n 4.Tampilkan Modus"<<endl;
        cout<<"Pilihan : "; cin>>pilihan;

        if (pilihan==1){
            inputan();
        }
        if(pilihan==2){
            hapus();
        }
        if (pilihan==3){
            tampilan();
        }
        if (pilihan==4){
            modus();
            cout<<"==========================";
        }
    }while(pilihan!=0);

    cout<<"TERIMAKASIH DAN SAMPAI JUMPA";


    return 0;
}

