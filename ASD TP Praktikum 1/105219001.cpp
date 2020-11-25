#include <iostream>
using namespace std;
struct tabel {
  string nama;
  string demam;
  string batuk;
  string kepala;
  string diare;
  string mata;
  string status;
}
covid[50];

int main() {
  cout<<"---------------------------------------------------------------\n";
  cout<<"------------------Mahran Radifan Zhafir------------------\n";
  cout<<"--------------------------105219001-------------------------\n";
  cout<<"---------------------------------------------------------------\n";
  int jumlah, i, indikasi, x;
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
      indikasi++;
    }

    cout << "Batuk : ";
    cin >> covid[i].batuk;
    if (covid[i].batuk == "ya") {
      indikasi++;
    }
    cout << "Sakit Kepala : ";
    cin >> covid[i].kepala;
    if (covid[i].kepala == "ya") {
      indikasi++;
    }
    cout << "Mata Merah : ";
    cin >> covid[i].mata;

    if (covid[i].mata == "ya") {
      indikasi++;
    }

    if (indikasi >= 3) {
      covid[i].status = "bisa jadi";
    } else {
      covid[i].status = "tidak berpotensi";
    }

  }

  cout << "Hasil Diagnosis : " << endl;
  cout << "Nama \t\t demam \t\t batuk \t\t sakit kepala \t\t mata merah \t\t status" << endl;
  for (x = 0; x < jumlah; x++) {
    cout << covid[x].nama << "\t\t" << covid[x].demam << "\t\t" << covid[x].batuk << "\t\t" << covid[x].kepala << "\t\t" << covid[x].mata << "\t\t" << covid[x].status << endl;
  }
  return 0;
}
