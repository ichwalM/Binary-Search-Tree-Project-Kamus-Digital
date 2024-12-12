#include <iostream>
#include <string>
using namespace std;

//struktur tree
struct Node{
    string key;
    string Meaning;
    Node *left;
    Node *right;
};

Node* root = nullptr, *n = nullptr, *temp = nullptr;

//pembuatan Node
Node* createNode(string key,string meaning){
    n=new Node;
    n->key=key;
    n->Meaning=meaning;
    n->left=nullptr;
    n->right=nullptr;
    return n;
}

//penambahan data
void insertNode(Node*& root, string key, string meaning){
    if(root==NULL)
        root=createNode(key,meaning);
    else if(key<=root->key)
        insertNode(root->left,key,meaning);
    else
        insertNode(root->right,key,meaning);
}
//search node memastikan nilai true or false
bool cari(Node* root, string key) {
    if (root == nullptr)
        return false;
    else if (key < root->key)
        return cari(root->left, key);
    else if (key > root->key)
        return cari(root->right, key);
    else
        return true;
}
//mencari dan mengembalikan nilai yang dicari
Node* search(Node* root, string key) {
    if (root == nullptr || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return search(root->left, key);
    }
    return search(root->right, key);
}
//menampilkan node yang ingin ditampilkan
void diplayNode(Node*reslut){
    if(root!=NULL){
        cout<<"kata : "<<reslut->key<<endl;
        cout<<"Arti : "<<reslut->Meaning<<endl;
        return;
    }
    cout<<"Kata Tidak Ditemukan atau belum ditambahkan..."<<endl;
}

//menampilkan semua tree menggunakan inorder traversal Asc
void displayAz(Node* root) {
    if (root == nullptr) return;
    displayAz(root->left);
    cout << root->key << "\t: "<<root->Meaning<<endl;
    displayAz(root->right);
}

//menampilkan semua tree menggunakan inorder traversal Dsc
void displayZa(Node* root) {
    if (root == nullptr) return;
    displayZa(root->right);
    cout << root->key << "\t: "<<root->Meaning<<endl;
    displayZa(root->left);
}

//update node dengan inputan key
void updateNode(Node* root, string key, string newMeaning) {
    if (root == nullptr) {
        cout << "Kata tidak ditemukan dalam kamus.\n";
        return;
    }
    if (key < root->key) {
        updateNode(root->left, key, newMeaning);
    } else if (key > root->key) {
        updateNode(root->right, key, newMeaning);
    } else {
        root->Meaning = newMeaning;
        cout << "Data berhasil diperbarui"<<endl;
        cout<<"Kata     : " << key <<endl;
        cout<<"Arti Baru: " << newMeaning << endl;
    }
}
//cari nilai min dalam node
Node* cariMin(Node* root) {
    if (root == nullptr)
        return nullptr;
    while (root->left != nullptr)
        root = root->left;
    return root;
}

//menghapus node sesuai inputan
void hapus(Node*& root, string key) {
    if (root == nullptr)
        return;
    else if (key < root->key)
        hapus(root->left, key);
    else if (key > root->key)
        hapus(root->right, key);
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete(root);
            root = nullptr;
        }
        else if (root->left == nullptr) {
            temp = root;
            root = root->right;
            delete(temp);
            temp = nullptr;
        }
        else if (root->right == nullptr) {
            temp = root;
            root = root->left;
            delete(temp);
            temp = nullptr;
        }
        else {
            temp = cariMin(root->right);
            root->key = temp->key;
            hapus(root->right, temp->key);
        }
    }
}
//delete tree atau all node
void deleteAllNodes(Node* &root) {
    if (root == nullptr) return;
    deleteAllNodes(root->left);
    deleteAllNodes(root->right);
    delete root;
    root = nullptr;
}

void home1();
void insertDatabase();
void introduction();
void homePage();
void displayOne(){
    int choice;
    string key,meaning,newMeaning;
    while(choice!=7){
        homePage();
        cin>>choice;
        cin.clear();
        cin.ignore();
        system("clear");
        switch(choice){
            case 1:{
                cout<<"Menambah Kosakata"<<endl;
                cout<<"--------------------"<<endl;
                cout<<"Masukkan Kata : ";getline(cin,key);
                cout<<"Masukkan Arti : ";getline(cin,meaning);
                insertNode(root,key,meaning);
                system("clear");
                cout<<"Menambah Kosakata"<<endl;
                cout<<"kata     : "<<key<<endl;
                cout<<"Artinya  : "<<meaning<<endl;
                cout<<"Berhasil Ditambahkan..."<<endl;
                system("sleep 1.5");
                break;
            }case 2:{
                if(root==NULL){
                    cout<<"Kata Belum Ada."<<endl<<"Silahkan tambahkan kosakata terlebih dahulu..."<<endl;
                }else{
                    cout<<"Mencari kata"<<endl;
                    cout<<"--------------------"<<endl;
                    cout<<"Masukkan Kata : ";getline(cin,key);
                    if(cari(root,key)==true){
                        Node *result = search(root,key);
                        diplayNode(result);
                    }else{
                        cout<<"Kata : "<<key<<" Tidak ditemukan..."<<endl;
                    }
                }
                system("sleep 1.5");
                break;
            }case 3:{
                if(root==NULL){
                    cout<<"Kata Belum Ada."<<endl<<"Silahkan tambahkan kosakata terlebih dahulu..."<<endl;
                }else{
                    cout<<"Isi Kamus[A-Z]"<<endl;
                    cout<<"----------------------------"<<endl;
                    cout<<"Kata :   Artinya"<<endl;
                    displayAz(root);    
                }
                system("sleep 1.5");
                break;
            }case 4:{
                if(root==NULL){
                    cout<<"Kata Belum Ada."<<endl<<"Silahkan tambahkan kosakata terlebih dahulu..."<<endl;
                }else{
                    cout<<"Isi Kamus[Z-A]"<<endl;
                    cout<<"----------------------------"<<endl;
                    cout<<"Kata     :   Artinya"<<endl;
                    displayZa(root);    
                }
                system("sleep 1.5");
                break;
            }case 5:{
                cout<<"Perbaharui Kata"<<endl;
                cout<<"Masukkan Kata     : ";getline(cin,key);
                cout<<"Masukkan arti Baru: ";getline(cin,newMeaning);
                updateNode(root,key,newMeaning);
                system("sleep 1.5");
                break;
            }case 6:{
                cout<<"Hapus kata"<<endl<<endl;
                cout<<"Masukkan Kata: ";getline(cin,key);
                if(cari(root,key)==true){
                    Node *result = search(root,key);
                    diplayNode(result);
                    hapus(root,key);
                    cout<<"Berhasil Dihapuss"<<endl;
                }else{
                    cout<<"Kata : "<<key<<" Tidak ditemukan..."<<endl;
                }
                system("sleep 1.5");
                break;
            }
            case 7:{
                cout<<"See You Next Time..."<<endl;
                cout<<"Sampai Jumpa..."<<endl;
                break;
            }default:{
                cout<<"Inputan Tidak Valid..."<<endl;
                system("sleep 1.5");
                break;
            }
        }
    }
}

int main(){
    int choice,home;
    string key,meaning;
    introduction();
    while(home!=3){
        insertDatabase();
        home1();cin>>home;
        cin.clear();
        cin.ignore();
        switch(home){
            case 1:{
                displayOne();break;
            }case 2:{
                deleteAllNodes(root);
                displayOne();
                break;
            }case 3:{
                cout<<"See You Next Time..."<<endl;
                cout<<"Sampai Jumpa..."<<endl;
                break;
            }default:{
                cout<<"Inputan Tidak Valid..."<<endl;
                system("sleep 1.5");
                break;
            }
        }
    }
}
//introduction aplikasi
void introduction() {
    system("clear");
    cout<<"==========================================="<<endl;
    cout<<"= Selamat Datang Di Aplikasi Kamus Digital="<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"= Aplikasi Kamus Digital adalah sistem    ="<<endl;
    cout<<"= yang memungkinkan pengguna mencari      ="<<endl;
    cout<<"= arti kata dengan cepat.                 ="<<endl;
    cout<<"-------------------------------------------"<<endl;
    system("sleep 1.5");
    cout<<"= Aplikasi ini di dirancang oleh:         ="<<endl;
    cout<<"= 1. Ichwal      \t13020230049       ="<<endl;
    cout<<"= 2. Andi Rizky Akbar \t13020230054       ="<<endl;
    cout<<"= 3. Muh Rifky Ahlul \t13020230038       ="<<endl;
    cout<<"==========================================="<<endl;
    system("sleep 1.5");
}
//home page aplikasi
void home1(){
    system("clear");
    cout<<"Selamat Datang Di Program Kamus Digital Bahasa Inggris"<<endl;
    cout<<"Di bawah terdapat 2 pilihan:"<<endl;
    cout<<"1. Kamus Telah Berisi 100 kata"<<endl;
    cout<<"2. Kamus Masi Kosong"<<endl;
    cout<<"3. Keluar Dari Aplikasih"<<endl;
    cout<<"Masukkan Pilihan[1..3]: ";
}

//sub home page aplikasi
void homePage(){
    system("clear");
    cout<<"Selamat Datang Di Program Kamus Digital"<<endl;
    cout<<"1. Tambah Kata"<<endl;
    cout<<"2. Cari Kata"<<endl;
    cout<<"3. Tampilkan Semua Kata[A-Z]"<<endl;
    cout<<"4. Tampilkan Semua Kata[Z-A]"<<endl;
    cout<<"5. Perbaharui Arti Kata"<<endl;
    cout<<"6. Hapus Kata"<<endl;
    cout<<"7. Kembali Ke Beranda"<<endl;
    cout<<"Masukkan Pilihan[1..6] :";
}

/*
insert manual semua data secara default pada saat program
dijalankan ini menggunakan array 2 dimensi
*/
void insertDatabase(){
    string data[][2] = {
        {"hello", "halo"}, {"good", "baik"}, {"morning", "pagi"}, {"night", "malam"}, {"thanks", "terima kasih"},
        {"sorry", "maaf"}, {"yes", "iya"}, {"no", "tidak"}, {"friend", "teman"}, {"family", "keluarga"},
        {"home", "rumah"}, {"school", "sekolah"}, {"work", "kerja"}, {"money", "uang"}, {"time", "waktu"},
        {"car", "mobil"}, {"food", "makanan"}, {"drink", "minuman"}, {"love", "cinta"}, {"happy", "senang"},
        {"sad", "sedih"}, {"angry", "marah"}, {"tired", "lelah"}, {"hungry", "lapar"}, {"thirsty", "haus"},
        {"book", "buku"}, {"pen", "pulpen"}, {"table", "meja"}, {"chair", "kursi"}, {"window", "jendela"},
        {"door", "pintu"}, {"tree", "pohon"}, {"water", "air"}, {"fire", "api"}, {"earth", "tanah"},
        {"wind", "angin"}, {"phone", "telepon"}, {"computer", "komputer"}, {"internet", "internet"}, {"music", "musik"},
        {"movie", "film"}, {"game", "permainan"}, {"song", "lagu"}, {"dance", "tari"}, {"story", "cerita"},
        {"travel", "perjalanan"}, {"beach", "pantai"}, {"mountain", "gunung"}, {"rain", "hujan"}, {"sun", "matahari"},
        {"moon", "bulan"}, {"star", "bintang"}, {"sky", "langit"}, {"river", "sungai"}, {"lake", "danau"},
        {"ocean", "laut"}, {"island", "pulau"}, {"forest", "hutan"}, {"flower", "bunga"}, {"animal", "hewan"},
        {"cat", "kucing"}, {"dog", "anjing"}, {"bird", "burung"}, {"fish", "ikan"}, {"cow", "sapi"},
        {"horse", "kuda"}, {"sheep", "domba"}, {"goat", "kambing"}, {"chicken", "ayam"}, {"duck", "bebek"}
    };
    //tambah data ke bst
    for (auto& item : data) {
        insertNode(root, item[0], item[1]);
    }
}