#include <iostream>
#include <cstring>
#include "Gudang.h"

using namespace std;

ManajemenGudang::ManajemenGudang() : head(nullptr), nextId(1), totalItems(0) {}

ManajemenGudang::~ManajemenGudang() {
    Barang* current = head;
    while (current != nullptr) {
        Barang* temp = current;
        current = current->next;
        delete temp;
    }
}

void ManajemenGudang::tambahBarang() {
    Barang* barangBaru = new Barang;
    barangBaru->id = nextId++;
    barangBaru->next = nullptr;

    cout << "\n=== TAMBAH BARANG BARU ===\n";
    cout << "Nama Barang: ";
    cin.ignore();
    cin.getline(barangBaru->nama, 50);
    cout << "Jumlah: ";
    cin >> barangBaru->jumlah;
    cout << "Harga: ";
    cin >> barangBaru->harga;
    cout << "Kategori: ";
    cin.ignore();
    cin.getline(barangBaru->kategori, 30);

    if (head == nullptr) head = barangBaru;
    else {
        Barang* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = barangBaru;
    }

    totalItems++;
    cout << "Barang berhasil ditambahkan dengan ID: " << barangBaru->id << endl;
}

Barang* ManajemenGudang::cariBarangById(int id) {
    Barang* current = head;
    while (current != nullptr) {
        if (current->id == id) return current;
        current = current->next;
    }
    return nullptr;
}

void ManajemenGudang::tambahStok() {
    int id, tambah;
    cout << "\n=== TAMBAH STOK BARANG ===\nID barang: ";
    cin >> id;

    Barang* b = cariBarangById(id);
    if (b) {
        cout << "Stok sekarang: " << b->jumlah << "\nTambah: ";
        cin >> tambah;
        b->jumlah += tambah;
        cout << "Stok baru: " << b->jumlah << endl;
    } else cout << "Barang tidak ditemukan.\n";
}

void ManajemenGudang::kurangiStok() {
    int id, kurang;
    cout << "\n=== KURANGI STOK BARANG ===\nID barang: ";
    cin >> id;

    Barang* b = cariBarangById(id);
    if (b) {
        cout << "Stok sekarang: " << b->jumlah << "\nKurangi: ";
        cin >> kurang;
        if (kurang <= b->jumlah) {
            b->jumlah -= kurang;
            cout << "Stok baru: " << b->jumlah << endl;
        } else cout << "Jumlah terlalu banyak!\n";
    } else cout << "Barang tidak ditemukan.\n";
}

void ManajemenGudang::swapBarang(Barang* a, Barang* b) {
    swap(a->id, b->id);
    swap(a->jumlah, b->jumlah);
    swap(a->harga, b->harga);
    char tempNama[50], tempKategori[30];
    strcpy(tempNama, a->nama);
    strcpy(a->nama, b->nama);
    strcpy(b->nama, tempNama);
    strcpy(tempKategori, a->kategori);
    strcpy(a->kategori, b->kategori);
    strcpy(b->kategori, tempKategori);
}

void ManajemenGudang::sortingBarang() {
    int pilihan;
    cout << "\n=== SORT BARANG ===\n1. Nama\n2. Jumlah\n3. Harga\nPilih: ";
    cin >> pilihan;

    if (!head || !head->next) return;

    bool swapped;
    do {
        swapped = false;
        Barang* curr = head;
        while (curr->next) {
            bool needSwap = false;
            switch (pilihan) {
                case 1: needSwap = strcmp(curr->nama, curr->next->nama) > 0; break;
                case 2: needSwap = curr->jumlah > curr->next->jumlah; break;
                case 3: needSwap = curr->harga > curr->next->harga; break;
            }
            if (needSwap) {
                swapBarang(curr, curr->next);
                swapped = true;
            }
            curr = curr->next;
        }
    } while (swapped);

    cout << "Sorting selesai.\n";
}

void ManajemenGudang::tampilkanBarang(Barang* b) {
    cout << "ID: " << b->id << "\tNama: " << b->nama << "\tJumlah: " << b->jumlah
         << "\tHarga: " << b->harga << "\tKategori: " << b->kategori << endl;
}

void ManajemenGudang::tampilkanBarangRekursif(Barang* b) {
    if (!b) return;
    tampilkanBarang(b);
    tampilkanBarangRekursif(b->next);
}

void ManajemenGudang::tampilkanSemuaBarang() {
    if (!head) {
        cout << "Gudang kosong.\n";
        return;
    }

    cout << "\n=== DAFTAR BARANG ===" << endl;
    tampilkanBarangRekursif(head);
}

void ManajemenGudang::hitungStatistikRekursif(Barang* b, int& jenis, int& jumlah, double& nilai) {
    if (!b) return;
    jenis++;
    jumlah += b->jumlah;
    nilai += b->jumlah * b->harga;
    hitungStatistikRekursif(b->next, jenis, jumlah, nilai);
}

void ManajemenGudang::hitungTotalNilai() {
    int jenis = 0, jumlah = 0;
    double nilai = 0;
    hitungStatistikRekursif(head, jenis, jumlah, nilai);

    cout << "\n=== STATISTIK ===\n";
    cout << "Jenis Barang: " << jenis << "\nTotal Jumlah: " << jumlah << "\nTotal Nilai: Rp " << nilai << endl;
}

void ManajemenGudang::hapusBarang() {
    int id;
    cout << "\nHapus barang ID: ";
    cin >> id;

    if (!head) return;
    if (head->id == id) {
        Barang* temp = head;
        head = head->next;
        delete temp;
        totalItems--;
        cout << "Barang dihapus.\n";
        return;
    }

    Barang* curr = head;
    while (curr->next && curr->next->id != id) curr = curr->next;

    if (curr->next) {
        Barang* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        totalItems--;
        cout << "Barang dihapus.\n";
    } else cout << "ID tidak ditemukan.\n";
}

void ManajemenGudang::cariBarang() {
    int p;
    cout << "\nCari berdasarkan:\n1. ID\n2. Nama\n3. Kategori\nPilih: ";
    cin >> p;
    switch (p) {
        case 1: cariBarangByIdMenu(); break;
        case 2: cariBarangByNama(); break;
        case 3: cariBarangByKategori(); break;
    }
}

void ManajemenGudang::cariBarangByIdMenu() {
    int id;
    cout << "ID: ";
    cin >> id;
    Barang* b = cariBarangById(id);
    if (b) tampilkanBarang(b);
    else cout << "Tidak ditemukan.\n";
}

void ManajemenGudang::cariBarangByNama() {
    char nama[50];
    cout << "Nama (substring): ";
    cin.ignore();
    cin.getline(nama, 50);

    Barang* curr = head;
    bool found = false;
    while (curr) {
        if (strstr(curr->nama, nama)) {
            tampilkanBarang(curr);
            found = true;
        }
        curr = curr->next;
    }
    if (!found) cout << "Tidak ada barang ditemukan.\n";
}

void ManajemenGudang::cariBarangByKategori() {
    char kat[30];
    cout << "Kategori: ";
    cin.ignore();
    cin.getline(kat, 30);

    Barang* curr = head;
    bool found = false;
    while (curr) {
        if (strstr(curr->kategori, kat)) {
            tampilkanBarang(curr);
            found = true;
        }
        curr = curr->next;
    }
    if (!found) cout << "Tidak ada barang ditemukan.\n";
}
