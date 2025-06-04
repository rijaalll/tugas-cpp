#include <iostream>
#include <cstring>

using namespace std;

struct Barang {
    int id;
    char nama[50];
    int jumlah;
    double harga;
    char kategori[30];
    Barang* next;
};

class ManajemenGudang {
private:
    Barang* head;
    int nextId;
    int totalItems;

public:
    ManajemenGudang() : head(nullptr), nextId(1), totalItems(0) {}

    ~ManajemenGudang() {
        Barang* current = head;
        while (current != nullptr) {
            Barang* temp = current;
            current = current->next;
            delete temp;
        }
    }

    void tambahBarang() {
        Barang* barangBaru = new Barang;
        barangBaru->id = nextId++;
        barangBaru->next = nullptr;

        cout << "\n=== TAMBAH BARANG BARU ===" << endl;
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

        if (head == nullptr) {
            head = barangBaru;
        } else {
            Barang* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = barangBaru;
        }

        totalItems++;
        cout << "Barang berhasil ditambahkan dengan ID: " << barangBaru->id << endl;
    }

    Barang* cariBarangById(int id) {
        Barang* current = head;
        while (current != nullptr) {
            if (current->id == id) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void tambahStok() {
        int id, jumlahTambah;
        cout << "\n=== TAMBAH STOK BARANG ===" << endl;
        cout << "Masukkan ID barang: ";
        cin >> id;

        Barang* barang = cariBarangById(id);
        if (barang != nullptr) {
            cout << "Barang ditemukan: " << barang->nama << endl;
            cout << "Stok saat ini: " << barang->jumlah << endl;
            cout << "Jumlah yang akan ditambah: ";
            cin >> jumlahTambah;
            barang->jumlah += jumlahTambah;
            cout << "Stok berhasil ditambah. Stok sekarang: " << barang->jumlah << endl;
        } else {
            cout << "Barang dengan ID " << id << " tidak ditemukan!" << endl;
        }
    }

    void kurangiStok() {
        int id, jumlahKurang;
        cout << "\n=== KURANGI STOK BARANG ===" << endl;
        cout << "Masukkan ID barang: ";
        cin >> id;

        Barang* barang = cariBarangById(id);
        if (barang != nullptr) {
            cout << "Barang ditemukan: " << barang->nama << endl;
            cout << "Stok saat ini: " << barang->jumlah << endl;
            cout << "Jumlah yang akan dikurangi: ";
            cin >> jumlahKurang;

            if (jumlahKurang <= barang->jumlah) {
                barang->jumlah -= jumlahKurang;
                cout << "Stok berhasil dikurangi. Stok sekarang: " << barang->jumlah << endl;
            } else {
                cout << "Error: Jumlah yang dikurangi melebihi stok yang tersedia!" << endl;
            }
        } else {
            cout << "Barang dengan ID " << id << " tidak ditemukan!" << endl;
        }
    }

    void sortingBarang() {
        if (head == nullptr || head->next == nullptr) {
            cout << "Tidak cukup data untuk diurutkan!" << endl;
            return;
        }

        int pilihan;
        cout << "\n=== SORTING BARANG ===" << endl;
        cout << "1. Sort berdasarkan Nama (A-Z)" << endl;
        cout << "2. Sort berdasarkan Jumlah (Terkecil ke Terbesar)" << endl;
        cout << "3. Sort berdasarkan Harga (Termurah ke Termahal)" << endl;
        cout << "Pilih opsi sorting: ";
        cin >> pilihan;

        bool swapped = true;
        while (swapped) {
            swapped = false;
            Barang* current = head;

            while (current->next != nullptr) {
                bool needSwap = false;

                switch (pilihan) {
                    case 1:
                        needSwap = strcmp(current->nama, current->next->nama) > 0;
                        break;
                    case 2:
                        needSwap = current->jumlah > current->next->jumlah;
                        break;
                    case 3:
                        needSwap = current->harga > current->next->harga;
                        break;
                    default:
                        cout << "Pilihan tidak valid!" << endl;
                        return;
                }

                if (needSwap) {
                    swapBarang(current, current->next);
                    swapped = true;
                }
                current = current->next;
            }
        }

        switch (pilihan) {
            case 1: cout << "Barang berhasil diurutkan berdasarkan nama!" << endl; break;
            case 2: cout << "Barang berhasil diurutkan berdasarkan jumlah!" << endl; break;
            case 3: cout << "Barang berhasil diurutkan berdasarkan harga!" << endl; break;
        }
    }

    void swapBarang(Barang* a, Barang* b) {
        int tempId = a->id;
        a->id = b->id;
        b->id = tempId;

        char tempNama[50];
        strcpy(tempNama, a->nama);
        strcpy(a->nama, b->nama);
        strcpy(b->nama, tempNama);

        int tempJumlah = a->jumlah;
        a->jumlah = b->jumlah;
        b->jumlah = tempJumlah;

        double tempHarga = a->harga;
        a->harga = b->harga;
        b->harga = tempHarga;

        char tempKategori[30];
        strcpy(tempKategori, a->kategori);
        strcpy(a->kategori, b->kategori);
        strcpy(b->kategori, tempKategori);
    }

    void cariBarang() {
        int pilihan;
        cout << "\n=== CARI BARANG ===" << endl;
        cout << "1. Cari berdasarkan ID" << endl;
        cout << "2. Cari berdasarkan Nama" << endl;
        cout << "3. Cari berdasarkan Kategori" << endl;
        cout << "Pilih metode pencarian: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: cariBarangByIdMenu(); break;
            case 2: cariBarangByNama(); break;
            case 3: cariBarangByKategori(); break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    }

    void cariBarangByIdMenu() {
        int id;
        cout << "Masukkan ID barang: ";
        cin >> id;

        Barang* barang = cariBarangById(id);
        if (barang != nullptr) {
            tampilkanBarang(barang);
        } else {
            cout << "Barang dengan ID " << id << " tidak ditemukan!" << endl;
        }
    }

    void cariBarangByNama() {
        char nama[50];
        cout << "Masukkan nama barang: ";
        cin.ignore();
        cin.getline(nama, 50);

        bool found = false;
        Barang* current = head;

        while (current != nullptr) {
            if (strstr(current->nama, nama) != nullptr) {
                if (!found) {
                    cout << "\nHasil pencarian:" << endl;
                    found = true;
                }
                tampilkanBarang(current);
            }
            current = current->next;
        }

        if (!found) {
            cout << "Tidak ada barang dengan nama yang mengandung '" << nama << "'" << endl;
        }
    }

    void cariBarangByKategori() {
        char kategori[30];
        cout << "Masukkan kategori: ";
        cin.ignore();
        cin.getline(kategori, 30);

        bool found = false;
        Barang* current = head;

        while (current != nullptr) {
            if (strstr(current->kategori, kategori) != nullptr) {
                if (!found) {
                    cout << "\nBarang dalam kategori '" << kategori << "':" << endl;
                    found = true;
                }
                tampilkanBarang(current);
            }
            current = current->next;
        }

        if (!found) {
            cout << "Tidak ada barang dalam kategori '" << kategori << "'" << endl;
        }
    }

    void tampilkanBarang(Barang* barang) {
        cout << "----------------------------------------" << endl;
        cout << "ID: " << barang->id << endl;
        cout << "Nama: " << barang->nama << endl;
        cout << "Jumlah: " << barang->jumlah << endl;
        cout << "Harga: Rp " << barang->harga << endl;
        cout << "Kategori: " << barang->kategori << endl;
        cout << "----------------------------------------" << endl;
    }

    // === FUNGSI REKURSIF UNTUK TAMPILKAN BARANG ===
    void tampilkanBarangRekursif(Barang* barang) {
        if (barang == nullptr) return;
        cout << barang->id << "\t" << barang->nama << "\t\t\t"
             << barang->jumlah << "\t" << barang->harga << "\t\t"
             << barang->kategori << endl;
        tampilkanBarangRekursif(barang->next);
    }

    void tampilkanSemuaBarang() {
        if (head == nullptr) {
            cout << "\nGudang kosong! Tidak ada barang." << endl;
            return;
        }

        cout << "\n=== DAFTAR SEMUA BARANG ===" << endl;
        cout << "ID\tNama\t\t\tJumlah\tHarga\t\tKategori" << endl;
        cout << "----------------------------------------------------------------" << endl;
        tampilkanBarangRekursif(head);
    }

    // === FUNGSI REKURSIF UNTUK HITUNG STATISTIK ===
    void hitungStatistikRekursif(Barang* barang, int& jenis, int& totalJumlah, double& totalNilai) {
        if (barang == nullptr) return;

        jenis++;
        totalJumlah += barang->jumlah;
        totalNilai += barang->jumlah * barang->harga;

        hitungStatistikRekursif(barang->next, jenis, totalJumlah, totalNilai);
    }

    void hitungTotalNilai() {
        int jenisBarang = 0, totalJumlah = 0;
        double totalNilai = 0.0;

        hitungStatistikRekursif(head, jenisBarang, totalJumlah, totalNilai);

        cout << "\n=== STATISTIK GUDANG ===" << endl;
        cout << "Total Jenis Barang: " << jenisBarang << endl;
        cout << "Total Jumlah Barang: " << totalJumlah << endl;
        cout << "Total Nilai Gudang: Rp " << totalNilai << endl;
    }

    void hapusBarang() {
        int id;
        cout << "\n=== HAPUS BARANG ===" << endl;
        cout << "Masukkan ID barang yang akan dihapus: ";
        cin >> id;

        if (head == nullptr) {
            cout << "Gudang kosong!" << endl;
            return;
        }

        if (head->id == id) {
            Barang* temp = head;
            head = head->next;
            cout << "Barang '" << temp->nama << "' berhasil dihapus!" << endl;
            delete temp;
            totalItems--;
            return;
        }

        Barang* current = head;
        while (current->next != nullptr && current->next->id != id) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Barang* temp = current->next;
            current->next = temp->next;
            cout << "Barang '" << temp->nama << "' berhasil dihapus!" << endl;
            delete temp;
            totalItems--;
        } else {
            cout << "Barang dengan ID " << id << " tidak ditemukan!" << endl;
        }
    }
};

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "\n============================================" << endl;
    cout << "         SISTEM MANAJEMEN GUDANG           " << endl;
    cout << "============================================" << endl;
    cout << "1. Tambah Barang Baru" << endl;
    cout << "2. Tambah Stok Barang" << endl;
    cout << "3. Kurangi Stok Barang" << endl;
    cout << "4. Tampilkan Semua Barang" << endl;
    cout << "5. Cari Barang" << endl;
    cout << "6. Sorting Barang" << endl;
    cout << "7. Statistik Gudang" << endl;
    cout << "8. Hapus Barang" << endl;
    cout << "0. Keluar" << endl;
    cout << "============================================" << endl;
    cout << "Pilih menu: ";
}

int main() {
    ManajemenGudang* gudang = new ManajemenGudang();
    int pilihan;

    cout << "Selamat datang di Sistem Manajemen Gudang!" << endl;

    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1: gudang->tambahBarang(); break;
            case 2: gudang->tambahStok(); break;
            case 3: gudang->kurangiStok(); break;
            case 4: gudang->tampilkanSemuaBarang(); break;
            case 5: gudang->cariBarang(); break;
            case 6: gudang->sortingBarang(); break;
            case 7: gudang->hitungTotalNilai(); break;
            case 8: gudang->hapusBarang(); break;
            case 0:
                cout << "Terima kasih telah menggunakan Sistem Manajemen Gudang!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid! Silakan coba lagi." << endl;
        }

        if (pilihan != 0) {
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }

    } while (pilihan != 0);

    delete gudang;
    return 0;
}
