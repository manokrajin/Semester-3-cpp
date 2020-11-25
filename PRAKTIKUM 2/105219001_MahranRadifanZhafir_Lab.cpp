#include <iostream>
using namespace std;
int iterasi=0;
struct data{
    string nama;
    int tipesenjata;
}inventory[50];

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

void kodesenjata(string tipe){
    if(tipe=="pedang"){
        inventory[iterasi].tipesenjata=10;
    }
    if(tipe=="panah"){
        inventory[iterasi].tipesenjata=22;
    }
    if(tipe=="kapak"){
        inventory[iterasi].tipesenjata=38;
    }
    if(tipe=="senjata mesin"){
        inventory[iterasi].tipesenjata=49;
    }
    if(tipe=="pistol"){
        inventory[iterasi].tipesenjata=52;
    }
    if(tipe=="granat"){
        inventory[iterasi].tipesenjata=78;
    }
    if(tipe=="senjata sihir"){
        inventory[iterasi].tipesenjata=83;
    }
}

void tampilan(){
    int x;
    cout<<"inventory : ";
     for( x=0 ; x < iterasi ; x++){
        if(x==iterasi-1){
            cout<<inventory[x].nama<<endl;
        }
        else {
            cout<<inventory[x].nama<<", ";
        }
    }
}

void urut(){
    int i,j;
    for (i = 0; i < iterasi-1; i++){ //BUBBLE SORT
        for (j = 0; j < iterasi-i-1; j++){
            if (inventory[j].tipesenjata > inventory[j+1].tipesenjata){
                swap(&inventory[j].nama, &inventory[j+1].nama);
                swap(&inventory[j].tipesenjata, &inventory[j+1].tipesenjata);
            }
        }
    }
}

void tambah(){
    string tipe;
    cin.ignore();
    cout<<"Masukkan tipe senjata anda : "; getline(cin, tipe);
    kodesenjata(tipe);
    cout<<"Masukkan nama senjata anda : ";getline(cin, inventory[iterasi].nama);
    iterasi++;

}

void cari(){
    string pencari;
    int x;
    cin.ignore();
    cout<<"Masukkan kata yang dicari : "; getline(cin, pencari);
    for( x=0 ; x<iterasi ; x++){
        if ( pencari == inventory[x].nama ){
            cout<<pencari<<" berada di indeks ke : "<<x;
        }
    }
}

void hapus(){
 string namahapus;
 int indeksbaru, x;
 cin.ignore();
 cout<<"Masukkan nama yang ingin dihapus : "; getline(cin,namahapus);
 for (x=0 ; x<iterasi ; x++){
        if (namahapus==inventory[x].nama){
                for (indeksbaru=x; indeksbaru<iterasi; indeksbaru++){
                    inventory[indeksbaru].nama=inventory[indeksbaru+1].nama;
                    inventory[indeksbaru].tipesenjata=inventory[indeksbaru+1].tipesenjata;
                }
        }
    }
}

int main()
{
    int pilihan;
    do{
        cout<<"\n#####Manok's Inventory#####\n";
        tampilan();
        cout<<"1.Tambah Senjata\n2.Urutkan Senjata\n3.Cari Senjata\n4.Hapus Senjata\n0.EXIT\n";
        cout<<"Input Command : "; cin>>pilihan;
        if (pilihan==1){
            tambah();
        }
        if (pilihan==2){
            urut();
        }
        if (pilihan==3){
            cari();
        }
        if (pilihan==4){
            hapus();
        }
    }while(pilihan!=0);
    return 0;
}
