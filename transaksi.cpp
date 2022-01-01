#include <iostream>
#include "transaksi.h"

void transaksi(){
    Pembeli dt;
    FILE *f_pembeli;

    if ((f_pembeli = fopen("data_transaksi.dat", "rt")) == NULL)
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

void buat_file_transaksi(){
    // buat file transaksi
	Pembeli dt;
    FILE *f_pembeli;
	if ( (f_pembeli=fopen("data_transaksi.dat","wb")) == NULL )
    {
        printf("File tidak dapat dibuat!\r\n");
        exit(1);
    }
}




