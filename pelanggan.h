#ifndef pelanggan_h
#define pelanggan_h
#define JUM_BLOK 1
// prototype
void getNama();
void readPelanggan();

typedef struct{
    int id_pelanggan;
    char nama[50];
} pelanggan;
#endif