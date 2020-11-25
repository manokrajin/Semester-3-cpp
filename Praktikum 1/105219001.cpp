#include <iostream>

using namespace std;
/*
Demam : 25%​
Batuk : 25%​
Sakit kepala : 5%​
Diare : 35%​
Mata merah : 10 %​
Jika <= 65% maka bisa jadi​
Jika > 65% covid​
Jika <=30% tidak covid​
acuan tanggal untuk gejala covid yaitu tanggal hari ini​
Jadi hitung jarak dari gejala mulai keluar sampai hari ini​
Jika gejala diketahui melebihi 2 bulan. Maka harus isolasi rumah sakit​
Jika tidak, maka isolasi mandiri
*/
struct tabel{
    string nama;
    string demam;
    string batuk;
    string kepala;
    string diare;
    string mata;
    string status;
    int tanggal;
    string bulan;
    string penanganan;
}covid[50];

int main()
{
   int jumlah,i,indikasi, angkabulan, x;
   cout << "masukkan jumlah orang : ";
   cin >> jumlah;
   for (i = 0; i < jumlah; i++) {
    indikasi = 0;
    cin.ignore();
    cout << "Nama " << i + 1 << " : ";
    getline(cin, covid[i].nama);

    cout << "Demam : ";
    cin >> covid[i].demam;
    if (covid[i].demam == "ya") {
      indikasi=indikasi+25;
    }

    cout << "Batuk : ";
    cin >> covid[i].batuk;
    if (covid[i].batuk == "ya") {
      indikasi = indikasi + 25;
    }

    cout<<"Diare : ";
    cin>> covid[i].diare;
    if (covid[i].diare == "ya"){
        indikasi=indikasi+35;
    }

    cout << "Sakit Kepala : ";
    cin >> covid[i].kepala;
    if (covid[i].kepala == "ya") {
      indikasi = indikasi+5;
    }
    cout << "Mata Merah : ";
    cin >> covid[i].mata;

    if (covid[i].mata == "ya") {
      indikasi = indikasi+10;
    }

    if (indikasi > 65) {
      covid[i].status = "covid";
    }
    if (indikasi <= 30){
        covid[i].status = "tidak berpotensi";

    } else {
      covid[i].status = "bisa jadi";
    }
    if (covid[i].status != "tidak berpotensi"){
           cout<<"masukkan bulan terjangkit : ";
           cin>>covid[i].bulan;
            if (covid[i].bulan == "agustus" || covid[i].bulan  == "september"){
                covid[i].penanganan = "isolasi mandiri";
            }
            cout<<"masukkan tanggal : ";
            cin>>covid[i].tanggal;
            if (covid[i].tanggal >= 19 && covid[i].bulan == "juni"){
                covid[i].penanganan = "isolasi mandiri";
            }
            else {
                 covid[i].penanganan = "isolasi di rumah sakit";
            }
        }
        else{
            covid[i].penanganan = "Dirumah aja :)";
        }
   }

cout << "Hasil Diagnosis : " << endl;
cout << "Nama \t\t demam \t\t diare \t\t batuk \t\t sakit kepala \t\t mata merah \t\t status" << endl;
  for (x = 0; x < jumlah; x++) {
    cout << covid[x].nama << "\t\t" << covid[x].demam << "\t\t" << covid[x].diare << "\t\t" << covid[x].batuk << "\t\t" << covid[x].kepala << "\t\t" << covid[x].mata << "\t\t" << covid[x].status << endl;
  }

cout << "Saran Perawatan"<<endl;
cout<< "Nama \t\t perawatan\n";
  for (x = 0; x < jumlah; x++){
    cout << covid[x].nama << "\t\t" << covid[x].penanganan<<endl;
  }
    return 0;
}
