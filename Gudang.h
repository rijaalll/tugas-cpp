#ifndef GUDANG_H
#define GUDANG_H

#include "Barang.h"

class ManajemenGudang {
private:
    Barang* head;
    int nextId;
    int totalItems;

    void tampilkanBarang(Barang* barang);
    void tampilkanBarangRekursif(Barang* barang);
    void hitungStatistikRekursif(Barang* barang, int& jenis, int& totalJumlah, double& totalNilai);
    void swapBarang(Barang* a, Barang* b);

public:
    ManajemenGudang();
    ~ManajemenGudang();

    void tambahBarang();
    void tambahStok();
    void kurangiStok();
    void tampilkanSemuaBarang();
    void hitungTotalNilai();
    void hapusBarang();
    void sortingBarang();
    void cariBarang();
    Barang* cariBarangById(int id);
    void cariBarangByIdMenu();
    void cariBarangByNama();
    void cariBarangByKategori();
};

#endif
