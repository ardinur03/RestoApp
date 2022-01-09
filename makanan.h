#ifndef makanan_h
#define makanan_h

#define MAX_MAKANAN 100
void makananMenu();
void tambah_makanan();
void ubah_makanan();
void hapus_makanan();
void lihat_daftar_makanan();
void detail_makanan();
void detail_makanan_by_index(int index);
void daftar_menu_makanan();

// data makanan
typedef struct {
    int id_makanan; 
    char nama_makanan[50]; 
    long int harga_makanan;
} makananData; 
#endif

