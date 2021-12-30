#include <iostream>

typedef struct
{
    char nama[3];
    char pesanan[11];
    float harga_total;
} Pembeli;

void transaksi(){
    Pembeli dt;
    FILE *f_pembeli;
    if ((f_pembeli = fopen("data_transaksi.dat", "r")) == NULL)
    {
        printf("File tidak dapat dibuka\n");
        exit(1);
    }
    printf("\nISI FILE data_transaksi.dat ADALAH : \n\n");
    printf("Nama | Pesanan | Harga Toral \n");
    while (!feof(f_pembeli))
    {
        fscanf(f_pembeli, "%s %s %f", &dt.nama, &dt.pesanan, &dt.harga_total);
        printf("%s %s %3.2f\n", dt.nama, dt.pesanan, dt.harga_total);
    }
    fclose(f_pembeli);
}


