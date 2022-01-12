#include <iostream>
#include "prototype.h"
#include <conio.h>
#include <string>
#include <ctime>
#include <cstring>
#include "admin_resto.h"
#include "minuman.h"
using namespace std;

void kembali_crud_minuman();
void lihat_daftar_minuman();
string nama_minuman;
int harga_minuman;

int daftar_menu_minuman()
{
    // local Variabel
    int pil;
    lihat_daftar_minuman(); // melihat daftar Minuman
    // pilih nomor id berdasarkan nomor index
    printf("\n\t Minuman apa yang ingin anda beli ?  ");
    scanf("%d", &pil);
    return pil;
}

// tambah minuman
void tambah_minuman()
{
    minumanData dt_minuman[100];
    FILE *f_minuman;
    int i = 0;
    f_minuman = fopen("data_minuman.dat", "a+b");

    lihat_daftar_minuman();
    printf("\n");
    printf("\n");

    // cek apakah file bisa di buka
    if (f_minuman == NULL)
    {
        printf("\n\t File tidak bisa dibuka");
        getch();
        kembali_crud_minuman();
    }else {
        // cek isi file data_minuman.dat apakah ada ada jika ada data maka lanjutkan index elementnya
        if (fread(&dt_minuman, sizeof(makananData), 1, f_minuman) == 1)
        {
            while (fread(&dt_minuman, sizeof(makananData), 1, f_minuman))
            {
                i++;
            }
        }

        // input data minuman baru berdassarkan nomor index variabel arraynya
        printf("\t TAMBAH MINUMAN \n");
        printf("\n\t Masukkan nama minuman : ");
        fflush(stdin);
        gets(dt_minuman[i].nama_minuman);
        printf("\n\t Masukkan harga minuman : ");
        fflush(stdin);
        scanf("%d", &dt_minuman[i].harga_minuman);

        // Number Acak
        srand((unsigned)time(0));
        int id_random;
        id_random = (rand() % 999) + 1;
        dt_minuman[i].id_minuman = id_random;

        fwrite(&dt_minuman[i], sizeof(makananData), 1, f_minuman);
        fclose(f_minuman);

        // refresh variabel array
        i = 0;
    }

    system("cls");
    printf("\n\t Data Minuman Berhasil Ditambahkan");
    kembali_crud_minuman();
}

// hapus minuman
void hapus_minuman(){
    minumanData dt_minuman;
    FILE *f_minuman;
    int id_minuman;
    int pilih;

    // konfitmasi penghapusan data
    printf("\n\t Apakah anda yakin ingin menghapus semua data ?\n ");
    printf("\n\t 1. Ya \n");
    printf("\n\t 2. Tidak \n");
    printf("\n\tMasukkan Pilihan : ");
    scanf("%d", &pilih);
    if(pilih == 1){
        f_minuman = fopen("data_minuman.dat", "wb+");
        fclose(f_minuman);
        system("cls");
        printf("\n\t Data Minuman Berhasil Dihapus");
    }
    else if(pilih == 2){
        system("cls");
        kembali_crud_minuman();
    }
    else{
        system("cls");
        printf("\n\t Inputan anda salah !");
        printf("\n\t Tekan Enter Untuk Kembali");
        getche();
        hapus_minuman();
    }
   

    kembali_crud_minuman();
}

//Ubah Minuman
void ubah_minuman(){
    minumanData dt_minuman;
    FILE *f_minuman;
    int id_minuman;
    char nama_minuman[30];
    int harga_minuman;
    int pilih;

    lihat_daftar_minuman();
    printf("\n");
    printf("\n");

    printf("\n\tMasukan ID Minuman : ");
    scanf("%d", &id_minuman);
    printf("\n\tMasukan Nama Minuman : ");
    fflush(stdin);
    gets(nama_minuman);
    printf("\n\tMasukan Harga Minuman : ");
    scanf("%d", &harga_minuman);

    f_minuman = fopen("data_minuman.dat","rb+");

    if(!f_minuman)
    {
        printf("\n\tGagal membuat file minuman.dat");
        exit(1);
    }

    while(fread(&dt_minuman,sizeof(dt_minuman),1,f_minuman)){
        if(dt_minuman.id_minuman == id_minuman){
            dt_minuman.id_minuman = id_minuman;
            strcpy(dt_minuman.nama_minuman,nama_minuman);
            dt_minuman.harga_minuman = harga_minuman;
            fseek(f_minuman,-sizeof(dt_minuman),SEEK_CUR);
            fwrite(&dt_minuman,sizeof(dt_minuman),1,f_minuman);
            printf("\n\tData Berhasil diubah");
            break;
        }
    }

    fclose(f_minuman);
    system("cls");
    printf("\n\t Data berhasil diubah ");
    kembali_crud_minuman();
}

// lihat daftar minuman
void lihat_daftar_minuman(){
    minumanData dt_minuman[100];
    FILE *f_minuman;
    int i = 0, index = 1;

    f_minuman = fopen("data_minuman.dat", "rb");
   
    if (!f_minuman)
    {
        printf("\n\t Gagal membuat file minuman.dat");
        exit(1);
    }

    // print data berdasarkan no index
    printf("|=======================================================================|");
    printf("\n|\t\t\t        DAFTAR MINUMAN\t\t\t\t|");
    printf("\n|=======================================================================|");
    printf("\n\tNO\tID Minuman\tNama Minuman\t\tHarga Minuman\n");
    while (fread(&dt_minuman[i], sizeof(makananData), 1, f_minuman))
    {
        printf("\n\t%d\t%d \t\t %s\t\t Rp. %d\n", index, dt_minuman[i].id_minuman, dt_minuman[i].nama_minuman, dt_minuman[i].harga_minuman);
        index++;
        i++;
    }

    fclose(f_minuman);
}

// lihat data berdasarkan id
void detail_minuman(){
    minumanData dt_minuman;
    FILE *f_minuman;
    int id_minuman, pilih, cek_minuman;

    printf("\n\t DETAIL MINUMAN\n");
    printf("\n\tMasukkan ID Makanan  : ");
    scanf("%d", &id_minuman);

    f_minuman = fopen("data_minuman.dat", "rb");
    if (!f_minuman)
    {
        printf("\n\t Gagal membuat file minuman.dat");
        exit(1);
    }

    // validasi cek jika ada minuman dengan id yang dicari
    cek_minuman = 1;
    while (fread(&dt_minuman, sizeof(dt_minuman), 1, f_minuman))
    {
        if (dt_minuman.id_minuman == id_minuman)
        {
            cek_minuman = 0;
            printf("\n\tID Minuman\tNama Minuman\tHarga Minuman\n");
            printf("\n\t%d\t\t%s\t\t%d\n", dt_minuman.id_minuman, dt_minuman.nama_minuman, dt_minuman.harga_minuman);
            break;
        }
    }

    if (cek_minuman == 1)
    {
        printf("\n\tData Minuman tidak ditemukan !");
    }
    kembali_crud_minuman();
}


void kembali_crud_minuman(){
    printf("\n\tTekan enter untuk kembali . . .");
    getche();
    crud_minuman();
}