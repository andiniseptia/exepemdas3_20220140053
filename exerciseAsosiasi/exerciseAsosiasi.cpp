#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Pengarang {
public:
    Pengarang(string nama) {
        this->nama = nama;
    }

    string getNama() {
        return nama;
    }

    void tambahBuku(string judul) {
        buku.push_back(judul);
    }

    string nama;
    vector<string> buku;
};

class Penerbit {
public:
    Penerbit(string nama) {
        this->nama = nama;
    }

    string getNama() {
        return nama;
    }

    void tambahPengarang(Pengarang pengarang) {
        daftarPengarang.push_back(pengarang);
    }

    string nama;
    vector<Pengarang> daftarPengarang;
};

class Buku {
public:
    string judul;
    vector<Pengarang*> pengarang;

    Buku(string judul) : judul(judul) {}

    void tambahPengarang(Pengarang* p) {
        pengarang.push_back(p);
    }

    string getJudul() {
        return judul;
    }

    vector<Pengarang*> getPengarang() {
        return pengarang;
    }
};

int main() {
    //Membuat objek pengarang
    Pengarang joko("Joko");
    Pengarang lia("Lia");
    Pengarang giga("Giga");
    Pengarang asroni("Asroni");
    Pengarang gigaIntan("Giga");

    //Hubungan pengarang dan penerbit
    Penerbit gamaPress("Gama Press");
    gamaPress.tambahPengarang(joko);
    gamaPress.tambahPengarang(lia);
    gamaPress.tambahPengarang(giga);

    //Hubungan pengarang dan penerbit
    Penerbit intanPariwara("Intan Pariwara");
    intanPariwara.tambahPengarang(asroni);
    intanPariwara.tambahPengarang(gigaIntan);

    //Hubungan buku dan pengarang
    joko.tambahBuku("Fisika");
    joko.tambahBuku("Algoritma");

    //Hubungan buku dan pengarang
    lia.tambahBuku("Basisdata");

    //Hubungan buku dan pengarang
    asroni.tambahBuku("Dasar Pemrograman");

    //Hubungan buku dan pengarang
    giga.tambahBuku("Matematika");
    giga.tambahBuku("Multimedia 1");

    //Menampilkan daftar pengarang pada penerbit "Gama Press"
    cout << "Daftar pengarang pada penerbit \"Gama Press\":" << endl;
    for (Pengarang pengarang : gamaPress.daftarPengarang) {
        cout << pengarang.getNama() << endl;
    }

    //Menampilkan daftar pengarang pada penerbit "Intan Pariwara"
    cout << "\nDaftar pengarang pada penerbit \"Intan Pariwara\":" << endl;
    for (Pengarang pengarang : intanPariwara.daftarPengarang) {
        cout << pengarang.getNama() << endl;
    }

    //Menampilkan daftar penerbit yang diikuti oleh "Giga"
    cout << "\nDaftar penerbit yang diikuti \"Giga\":" << endl;
    if (giga.getNama() == gigaIntan.getNama()) {
        cout << gamaPress.getNama() << endl;
        cout << intanPariwara.getNama() << endl;
    }

    //Menampilkan daftar buku yang dikarang oleh "Joko"
    cout << "\nDaftar buku yang dikarang Joko:" << endl;
    for (string buku : joko.buku) {
        cout << buku << endl;
    }

    //Menampilkan daftar buku yang dikarang oleh "Lia"
    cout << "\nDaftar buku yang dikarang Lia:" << endl;
    for (string buku : lia.buku) {
        cout << buku << endl;
    }

    //Menampilkan daftar buku yang dikarang oleh "Asroni"
    cout << "\nDaftar buku yang dikarang Asroni:" << endl;
    for (string buku : asroni.buku) {
        cout << buku << endl;
    }

    //Menampilkan daftar buku yang dikarang oleh "Giga"
    cout << "\nDaftar buku yang dikarang Giga:" << endl;
    for (string buku : giga.buku) {
        cout << buku << endl;
    }

    return 0;
}
