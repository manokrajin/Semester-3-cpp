#include <iostream>

using namespace std;
  int kode [10]= {811,712,513,314,915,516,317,518,419,120};
char nama[10] = {'a','b','c','d','e','f','g','h','i','j'};
struct dataDiri{ //assignment untuk data diri
    string nama,nim,prodi;
}dataDiri[10];

struct dataNilai{ //assignment untuk data nilai
    float uts,uas,praktikum,nilaiakhir;
}dataNilai[10];

void hitungnilai( int x) { //funsgi menghitung nilai
    dataNilai[x].nilaiakhir=  (0.3 * dataNilai[x].uts) + (0.4 * dataNilai[x].uas) + (0.3 * dataNilai[x].praktikum);

}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swap(char *a,char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

// fungsi bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] < arr[j+1])
            swap(&arr[j], &arr[j+1]);
            swap(&nama[j], &nama[j+1]);
}

//fungsi mencetak output
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void printArray(char arr[], int size)
{
    char i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

     //mencari array apakah dimana dia berada
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    // kalau array tidak ditemukan
    return -1;
}
int penjumlahan(int x, int y) {
  if (x == 0) {
    return y;
  } else {
    return penjumlahan(x - 1, y) + 1;
  }
}
int pembagian(int x, int y) {
  if (y == 0) {
    return 0;
  } else if (x - y == 0) {
    return 1;
  } else if (x < y) {
    return 0;
  } else {
    return (pembagian(x - y, y) + 1);
  }
}
int factorial(int n) {
  if (n == 0)
    return 1;
  return n * factorial(n - 1);
}

int main()
{
    int x;
    dataDiri[0].nama = "Mahran Radifan Zhafir";
    dataDiri[0].nim = "105219001";
    dataDiri[0].prodi = "Ilmu Komputer";
    dataNilai[0].uts= 81;
    dataNilai[0].uas= 61;
    dataNilai[0].praktikum = 71;
    hitungnilai(0); // menginput data dan pemanngilan fungsi pada array yang sudah ada isi;
    dataDiri[1].nama = "Mahran ";
    dataDiri[1].nim = "105219002";
    dataDiri[1].prodi = "Ilmu kelautan";
    dataNilai[1].uts= 13;
    dataNilai[1].uas= 40;
    dataNilai[1].praktikum = 62;
    hitungnilai(1); // menginput data dan pemanngilan fungsi pada array yang sudah ada isi;
    for (x=0 ; x<2 ; x++){ //looping array untuk menampilkan data;
    cout<< "\n======================";
    cout<<"\nNama : "<< dataDiri[x].nama;
    cout<<"\nNim : "<<   dataDiri[x].nim;
    cout<<"\nProdi : "<<  dataDiri[x].prodi;
    cout<<"\nNilai uts : "<<  dataNilai[x].uts;
    cout<<"\nNilai uas : "<< dataNilai[x].uas;
    cout<<"\nNilai Praktikum : "<< dataNilai[x].praktikum;
    cout<< "\nNilai akhir : "<<dataNilai[x].nilaiakhir;
    }
cout<<"\n\n";

/*
811  = a
712 = b
513 = c
314 = d
915 = e
516 = f
317 = g
518 = h
419 = i
120 = j
*/
    bubbleSort(kode, 10);
    printArray(kode,10);

    int n = sizeof(kode) / sizeof(kode[0]);
    cout<< binarySearch(kode, 0 , n-1 , 120);

cout<<"\n\n";

int a=10, b=5, c=2;
cout<< " \npenambahan : "<< penjumlahan(a,c) ;
cout<< " \npembagian : "<<pembagian(a,b);
cout<< " \nfaktorial : "<<factorial(a);
    return 0;
}
