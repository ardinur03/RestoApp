#ifndef minuman_h
#define minuman_h

void minumanMenu();
void tambah_minuman();
void ubah_minuman();
void hapus_minuman();
void lihat_daftar_minuman();
void detail_minuman();

// data minuman
typedef struct {
    int id_minuman; 
    char nama_minuman[50]; 
    long int harga_minuman;
} minumanData;
#endif