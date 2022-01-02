#ifndef transaksi_h
#define transaksi_h
#define JUM_BLOK 1

void transaksi();
void buat_file_transaksi();
void input_transaksi();

typedef struct
{
    int id_transaksi;
    char nama[20];
    char makanan[20];
    char minuman[20];
    int harga_normal;
    int diskon;
    int harga_total;
} Transaksi;

#endif