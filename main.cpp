#include <iostream>
#include "Gudang.h"
#include "Gudang.cpp"

using namespace std;

void tampilkanMenu() {

    cout << endl;
    cout << "====================================" << endl;
    cout << "===== MENU MANAJEMEN GUDANG ========" << endl;
    cout << "==== MOHAMMAD RIZAL AJI PERMANA ====" << endl; 
    cout << "===== FANZA ADHITYA PRAMADANU ======" << endl; 
    cout << "====================================" << endl;
    cout << endl;
    cout << "1. Tambah Barang" << endl;
    cout << "2. Tambah Stok" << endl;
    cout << "3. Kurangi Stok" << endl;
    cout << "4. Tampilkan Semua" << endl;
    cout << "5. Cari Barang" << endl;
    cout << "6. Sorting" << endl;
    cout << "7. Statistik" << endl;
    cout << "8. Hapus Barang" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih: ";
}

int main() {
    ManajemenGudang gudang;
    int pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1: gudang.tambahBarang(); break;
            case 2: gudang.tambahStok(); break;
            case 3: gudang.kurangiStok(); break;
            case 4: gudang.tampilkanSemuaBarang(); break;
            case 5: gudang.cariBarang(); break;
            case 6: gudang.sortingBarang(); break;
            case 7: gudang.hitungTotalNilai(); break;
            case 8: gudang.hapusBarang(); break;
            case 0: cout << "Terima kasih.\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 0);

    return 0;
}