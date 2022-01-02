#ifndef transaksi_h
#define transaksi_h
#define JUM_BLOK 1

void transaksi();
void buat_file_transaksi();

typedef struct
{
    int id_transaksi;
    char nama[20];
    char makanan[20];
    char minuman[20];
    float harga_normal;
    float diskon;
    float harga_total;
} Transaksi;

#endif