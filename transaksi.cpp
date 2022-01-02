#include <iostream>
#include <string>
#include <conio.h>
#include "transaksi.h"
#include <cstdlib> 
#include <ctime> 
#include "minuman.h"

using namespace std;

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
	printf("  %d       %s         %s           %s          %d                 %d           %-d \n", dt_transaksi.id_transaksi, dt_transaksi.nama, dt_transaksi.makanan, dt_transaksi.minuman, dt_transaksi.harga_normal, dt_transaksi.diskon, dt_transaksi.harga_total);
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

// void catat_transaksi(string nama_pr, string makanan_pr, string minuman_pr, int harga_normal_pr, int diskon_pr, int harga_total_pr){
    
//     // generate random number
//     srand((unsigned)time(0)); 
//     int id_random;
//     id_random = (rand()%6)+1; 
    
//     // simpan ke file
//     dt_transaksi.id_transaksi = id_random;
//     dt_transaksi.nama, nama_pr.c_str();
//     dt_transaksi.makanan, makanan_pr.c_str();
//     dt_transaksi.minuman, minuman_pr.c_str();
//     dt_transaksi.harga_normal = harga_normal_pr;
//     dt_transaksi.diskon = diskon_pr;
//     dt_transaksi.harga_total = harga_total_pr;

//     // save to file transaksi.dat
//     f_transaksi = fopen("data_transaksi.dat", "ab+");
//     if(!f_transaksi) {
//         printf("\n\t Gagal membuat file transaksi.dat");
//         exit(1);
//     }
//     fwrite(&dt_transaksi, sizeof(dt_transaksi), 1, f_transaksi);
//     fclose(f_transaksi);
// }

void input_transaksi(){
    // string nama_pr, makanan_pr, minuman_pr;
    // int harga_normal_pr, int diskon_pr, int harga_total_pr;
    // generate random number
    srand((unsigned)time(0)); 
    int id_random;
    id_random = (rand()%6)+1; 

    // input data transaksi
    printf("\n\t Masukkan nama pelanggan : ");
    fflush(stdin);
    gets(dt_transaksi.nama);

    printf("\n\t Masukkan makanan : ");
    fflush(stdin);
    gets(dt_transaksi.makanan);

    printf("\n\t Masukkan minuman : ");
    fflush(stdin);
    gets(dt_transaksi.minuman);

    printf("\n\t Masukkan harga normal : ");
    fflush(stdin);
    scanf("%d", &dt_transaksi.harga_normal);

    printf("\n\t Masukkan diskon : ");
    fflush(stdin);
    scanf("%d", &dt_transaksi.diskon);

    printf("\n\t Masukkan harga total : ");
    fflush(stdin);
    scanf("%d", &dt_transaksi.harga_total);

    // save to file transaksi.dat
    f_transaksi = fopen("data_transaksi.dat", "ab+");
    if(!f_transaksi) {
        printf("\n\t Gagal membuat file transaksi.dat");
        exit(1);
    }
   
    fwrite(&dt_transaksi, sizeof(dt_transaksi), 1, f_transaksi);
    fclose(f_transaksi);
}
