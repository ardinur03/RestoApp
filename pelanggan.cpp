#include <iostream>

typedef struct{
    char nama[20];
} pelanggan;

void getNama() {
    char nama[20];

    // input nama
    printf("\n\t Masukkan nama anda : ");
    scanf("%s", &nama);

    // save to file pelanggan.txt
    pelanggan dt_pelanggan;
    FILE *f_pelanggan;
    f_pelanggan = fopen("pelanggan.dat", "ab+");
    if(!f_pelanggan) {
        printf("\n\t Gagal membuat file pelanggan.dat");
        exit(1);
    }
    // fprintf(file, "%s", nama);

    fwrite(&dt_pelanggan, sizeof(dt_pelanggan), 1, f_pelanggan);

    fclose(f_pelanggan);

}
