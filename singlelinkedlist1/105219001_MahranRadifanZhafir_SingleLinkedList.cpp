#include <iostream>
#include <windows.h>
using namespace std;

struct Node{
    string kata;
    struct Node *next;
};
Node* head;

void printList()
{
    Node *data;
    data = head;
    while (data != NULL)
    {
        cout<<data->kata<<endl;
        data = data->next;
    }
}
//melakukan push data dari sebelum head, menjadikan data baru masuk menjadi head yang baru
void push (Node* *headRef , string data){
    Node* newnode = new Node();
    newnode->kata = data;
    //pengisian node baru dengan data baru
    newnode->next = *headRef;
    *headRef = newnode;
}
//terdapat overload function untuk delete node agar sesuai dengan inputan user
//apakah menghapus indeks yang ditunjuk atau menghapus kata yang terdapat dalam
//linked list
void deleteNode (Node **headRef, int posisi){
    int i;
    if(headRef == NULL){
        //kalau linked list tidak ada maka delete tidak dilakukan
        return;
    }
    Node* temp = *headRef;//variabel bantu untuk mengecek isi linked list

    if(posisi == 0){
            //jika ingin melakukan penghapusan head
        *headRef = temp->next;
        delete(temp);
        return;
    }

    for (i=0 ; temp==NULL && i<posisi-1; i++){
            //mencari indeks yang sesuai dengan permintaan user
        temp=temp->next;
    }
        if(temp == NULL && temp->next == NULL){
        //kalau inputan indeks melebihi jumlah indeks yang ada
            return;
        }
        Node *next = temp->next->next;
        //menyambung data sebelum data yang dihapus agar data pindah ke data yang sudah dihapus
        delete(temp->next);
        // menghapus data linked list yang dituju
        temp->next = next;
        //menghapus hubungan link kosong dengan linked list
}

void deleteNode(Node **headRef, string kataHapus){
    Node* temp = *headRef;
    //variabel bantu
    while(temp->next->kata != kataHapus){
    //pencarian dimana link yang terdapat data yang akan dihapus
        temp=temp->next;
    }
    Node *next = temp->next->next;
     //menyambung data sebelum data yang dihapus agar data pindah ke data yang sudah dihapus
    delete(temp->next);
    //mengikuti keterangan yang ada pada overload function
    temp->next = next;
}


void insertAfter (Node* prevnode, string data, string sebelum){
    int i;
    if(prevnode == NULL){
        cout<<"gaboleh kosong";
        return;
    }
    Node* node;
    while (prevnode->kata != sebelum){
    //pencarian kata yang akan kita inputkan data baru setelahnya
        prevnode=prevnode->next;
    }
    Node* newnode = new Node();
    newnode->kata = data;
    //pembuatan node baru yang akan diinput data
    newnode->next = prevnode->next;
    prevnode->next = newnode;
}



int main()
{
    cout<<"MAHRAN RADIFAN ZHAFIR\nNIM : 105219001\n\n";
    push(&head, "malang");
    push(&head, "batu");
    push(&head, "lawang");
    push(&head, "sidoarjo");
    push(&head, "mojokerto");
    push(&head, "surabaya");
    cout<<"Kota Kota sebelum tenggelam\n==========\n";
    printList();
    deleteNode(&head, "sidoarjo");
    cout<<"Kota Kota setelah tenggelam\n==========\n";
    printList();
    insertAfter(head->next, "sidobaru", "lawang");
    cout<<"kota kota setelah pembangunan ulang\n==========\n";
    printList();
    system("PAUSE");


}
