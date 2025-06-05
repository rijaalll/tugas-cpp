#include <iostream>
#include "Gudang.h"

using namespace std;

void tampilkanMenu() {
    cout << "\n=== MENU MANAJEMEN GUDANG ===\n";
    cout << "1. Tambah Barang\n";
    cout << "2. Tambah Stok\n";
    cout << "3. Kurangi Stok\n";
    cout << "4. Tampilkan Semua\n";
    cout << "5. Cari Barang\n";
    cout << "6. Sorting\n";
    cout << "7. Statistik\n";
    cout << "8. Hapus Barang\n";
    cout << "0. Keluar\n";
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
