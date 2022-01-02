#include <iostream>
#include "transaksi.h"

Transaksi dt_transaksi;
FILE *f_transaksi;

void transaksi(){
    f_transaksi = fopen("data_transaksi.dat", "rt");

    if (!f_transaksi)
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

    while ((fread(&dt_transaksi, sizeof(dt_transaksi), JUM_BLOK, f_transaksi)) == JUM_BLOK)
	{
		printf("  %-5d %-10s %-10s %-10s %-10d %-10d %-10d\n", dt_transaksi.id_transaksi, dt_transaksi.nama, dt_transaksi.makanan, dt_transaksi.minuman, dt_transaksi.harga_normal, dt_transaksi.diskon, dt_transaksi.harga_total);
	}

    fclose(f_transaksi);
}

void buat_file_transaksi(){
    f_transaksi=fopen("data_transaksi.dat","wb");
	if (!f_transaksi)
    {
        printf("File tidak dapat dibuat!\r\n");
        exit(1);
    }
}




