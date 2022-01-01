#ifndef transaksi_h
#define transaksi_h

void transaksi();
void buat_file_transaksi();

typedef struct
{
    char nama[3];
    char pesanan[11];
    float harga_total;
} Pembeli;
#endif