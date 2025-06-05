# Sistem Manajemen Gudang

Aplikasi console-based untuk mengelola inventori barang di gudang menggunakan bahasa C++. Sistem ini mengimplementasikan struktur data linked list untuk penyimpanan data barang dan berbagai algoritma untuk pengelolaan inventori.

## Fitur Utama

### 🔧 Operasi CRUD
- **Tambah Barang**: Menambahkan barang baru dengan auto-increment ID
- **Hapus Barang**: Menghapus barang berdasarkan ID
- **Update Stok**: Menambah atau mengurangi stok barang

### 📊 Manajemen Inventori
- **Tampilan Semua Barang**: Menampilkan seluruh inventori dengan implementasi rekursif
- **Pencarian Multi-kriteria**: Cari berdasarkan ID, nama (substring), atau kategori
- **Sorting**: Urutkan barang berdasarkan nama, jumlah, atau harga
- **Statistik**: Hitung total jenis barang, jumlah stok, dan nilai inventori

### 💡 Fitur Teknis
- Implementasi **Linked List** untuk struktur data dinamis
- **Bubble Sort** untuk pengurutan data
- **Rekursi** untuk traversal dan perhitungan statistik
- **Memory management** otomatis dengan destruktor

## Struktur Project

```
ManageGudang/
├── Barang.h          # Definisi struct Barang
├── Gudang.h          # Deklarasi class ManajemenGudang
├── Gudang.cpp        # Implementasi class ManajemenGudang
├── main.cpp          # Program utama dan menu
└── README.md         # Dokumentasi project
```

## Struktur Data

### Struct Barang
```cpp
struct Barang {
    int id;              // ID unik (auto-increment)
    char nama[50];       // Nama barang
    int jumlah;          // Jumlah stok
    double harga;        // Harga per unit
    char kategori[30];   // Kategori barang
    Barang* next;        // Pointer ke barang berikutnya
};
```

### Class ManajemenGudang
- **Private Members**:
  - `Barang* head`: Pointer ke node pertama linked list
  - `int nextId`: Counter untuk auto-increment ID
  - `int totalItems`: Jumlah total barang
  
- **Public Methods**: Berbagai operasi CRUD dan utility functions

## Cara Kompilasi dan Menjalankan

### Prerequisites
- Compiler C++ (g++, clang++, atau MSVC)
- Sistem operasi: Linux, macOS, atau Windows

### Kompilasi
```bash
# Masuk ke direktori project
cd ManageGudang/

# Kompilasi semua file .cpp
g++ main.cpp Gudang.cpp -o main

# Atau dengan cara alternatif
g++ -o main main.cpp Gudang.cpp
```

### Menjalankan Program
```bash
# Linux/macOS
./main

# Windows
main.exe
```

## Panduan Penggunaan

### Menu Utama
```
=== MENU MANAJEMEN GUDANG ===
1. Tambah Barang
2. Tambah Stok
3. Kurangi Stok
4. Tampilkan Semua
5. Cari Barang
6. Sorting
7. Statistik
8. Hapus Barang
0. Keluar
```

### Contoh Penggunaan

#### 1. Menambah Barang Baru
```
Pilih: 1
=== TAMBAH BARANG BARU ===
Nama Barang: Laptop Gaming
Jumlah: 5
Harga: 15000000
Kategori: Elektronik
Barang berhasil ditambahkan dengan ID: 1
```

#### 2. Mencari Barang
```
Pilih: 5
Cari berdasarkan:
1. ID
2. Nama
3. Kategori
Pilih: 2
Nama (substring): Laptop
ID: 1   Nama: Laptop Gaming   Jumlah: 5   Harga: 1.5e+07   Kategori: Elektronik
```

#### 3. Sorting Barang
```
Pilih: 6
=== SORT BARANG ===
1. Nama
2. Jumlah
3. Harga
Pilih: 3
Sorting selesai.
```

#### 4. Statistik
```
Pilih: 7
=== STATISTIK ===
Jenis Barang: 3
Total Jumlah: 25
Total Nilai: Rp 50000000
```

## Algoritma yang Digunakan

### 1. Linked List Traversal
- **Linear Search**: O(n) untuk pencarian berdasarkan ID
- **Substring Search**: Menggunakan `strstr()` untuk pencarian nama dan kategori

### 2. Bubble Sort
- **Time Complexity**: O(n²) worst case, O(n) best case
- **Space Complexity**: O(1)
- Implementasi dengan swap data antar node

### 3. Recursive Functions
- **Display**: Traversal rekursif untuk menampilkan semua barang
- **Statistics**: Perhitungan rekursif untuk statistik inventori

## Validasi Input

### Stok Management
- **Tambah Stok**: Tidak ada batasan maksimum
- **Kurangi Stok**: Validasi agar stok tidak negatif
- **Error Handling**: Pesan error jika barang tidak ditemukan

### Pencarian
- **Case Sensitive**: Pencarian nama dan kategori case-sensitive
- **Substring Match**: Mendukung pencarian partial string
- **Empty Results**: Pesan informatif jika tidak ada hasil

## Fitur Keamanan

### Memory Management
- **Destruktor**: Automatic cleanup saat program berakhir
- **Dynamic Allocation**: Proper `new` dan `delete` untuk node
- **No Memory Leaks**: Semua allocated memory dibersihkan

### Input Validation
- **Numeric Input**: Validasi untuk ID, jumlah, dan harga
- **String Input**: Buffer overflow protection dengan fixed-size arrays
- **Menu Validation**: Handle invalid menu choices

## Pengembangan Lebih Lanjut

### Possible Enhancements
1. **File I/O**: Save/load data ke/dari file
2. **Database Integration**: MySQL atau SQLite support
3. **GUI**: Interface grafis dengan Qt atau wxWidgets
4. **Web API**: REST API untuk akses remote
5. **Multi-threading**: Concurrent access support
6. **Advanced Search**: Filter berdasarkan range harga/stok
7. **Reporting**: Export laporan ke PDF/Excel
8. **User Authentication**: Login system dengan roles

### Code Improvements
1. **STL Containers**: Ganti linked list dengan `std::list` atau `std::vector`
2. **Smart Pointers**: Gunakan `std::unique_ptr` untuk memory safety
3. **Exception Handling**: Implementasi try-catch blocks
4. **Unit Testing**: Test cases dengan framework seperti Google Test
5. **Configuration**: External config file untuk settings

## Troubleshooting

### Common Issues
1. **Linker Error**: Pastikan kompilasi semua file .cpp
   ```bash
   g++ main.cpp Gudang.cpp -o main
   ```

2. **Segmentation Fault**: Biasanya terjadi karena akses null pointer
   - Check apakah linked list kosong sebelum akses
   - Validasi input ID yang tidak ada

3. **Input Buffer Issues**: 
   - Gunakan `cin.ignore()` setelah numeric input sebelum `getline()`

### Debug Tips
- Compile dengan debug flag: `g++ -g -o main main.cpp Gudang.cpp`
- Gunakan debugger: `gdb ./main`
- Add debug prints untuk trace execution flow

## Kontribusi

Untuk berkontribusi pada project ini:
1. Fork repository
2. Buat feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit changes (`git commit -m 'Add some AmazingFeature'`)
4. Push ke branch (`git push origin feature/AmazingFeature`)
5. Buat Pull Request