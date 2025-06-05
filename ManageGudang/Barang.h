#ifndef BARANG_H
#define BARANG_H

struct Barang {
    int id;
    char nama[50];
    int jumlah;
    double harga;
    char kategori[30];
    Barang* next;
};

#endif
