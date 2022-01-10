#ifndef transaksi_h
#define transaksi_h
#define JUM_BLOK 1

void transaksi();
void buat_file_transaksi();
void input_transaksi();
void transaksi_pemesanan();
void lihat_daftar_transaksi();
void welcome();
void lihat_daftar_transaksi_pelanggan();
void lihat_transaksi_satu_pelanggan_void();
// array makanan
struct makanan {
    int id_makanan;
    char nama[20];
    int harga;
};

// array minuman
struct minuman {
    int id_minuman;
    char nama[20];
    int harga;
};

// struct transaksi makanan dan minuman
typedef struct{
    int id_transaksi;
    char nama_pelanggan[50];
    char makanan[50];
    int porsi_makanan;
    int harga_makanan;
    char minuman[50];
    int porsi_minuman;
    int harga_minuman;
} Transaksi;


#endif