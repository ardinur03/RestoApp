#include <iostream>
#include "transaksi.h"

void transaksi(){
    pelanggan dt_pelanggan;
    FILE *f_pelanggan;

    f_pelanggan = fopen("data_transaksi.dat", "rt");

    if (!f_pelanggan)
    {
        printf("ERROR : File tidak dapat dibuka !\n");
        exit(1);
    }

    // create table transaksi
    printf("|==========================================================================================|\n");
    printf("|                                      Data Transaksi                                      |\n");
    printf("|==========================================================================================|\n"); 
    printf("| ID      Nama      Makanan     Minuman       Harga normal       Diskon       Harga Total  |\n");
    printf("|==========================================================================================|\n");

    // while ((fread(&dt_pelanggan, sizeof(dt_pelanggan), JUM_BLOK, f_pelanggan)) == JUM_BLOK)
	// {
	// 	printf("  %-5d %-10s %-10s %-10d %-10li\n", dt_pelanggan.code, dt_pelanggan.name, dt_pelanggan.type, dt_pelanggan.total, dt_pelanggan.price);
	// }

    // while (!feof(f_pelanggan))
    // {
    //     fscanf(f_pelanggan, "%s %s %f", &dt.nama, &dt.pelanggan, &dt.harga_total);
    //     printf("%s %s %3.2f\n", dt.nama, dt.pelanggan, dt.harga_total);
    // }
    // fclose(f_pelanggan);
}

void buat_file_transaksi(){
    // buat file transaksi
	pelanggan dt;
    FILE *f_pelanggan;
	if ( (f_pelanggan=fopen("data_transaksi.dat","wb")) == NULL )
    {
        printf("File tidak dapat dibuat!\r\n");
        exit(1);
    }
}




