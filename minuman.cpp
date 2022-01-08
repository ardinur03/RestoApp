#include <iostream>
#include "prototype.h"
#include <conio.h>
#include <string>
#include "minuman.h"
#include <ctime>
#include <cstring>
#include "admin_resto.h"

using namespace std;

void toppingTeh();
void kembali_crud_minuman();
void lihat_daftar_minuman();
string nama_minuman;
int harga_minuman;

void minumanMenu()
{

    char airmineral;
    int pil;

    printf("\t\t|====================== Daftar Minuman ===============|\n");
    printf("\t\t|                                                     |\n");
    printf("\t\t| Nama Minuman                         Harga          |\n");
    printf("\t\t| 1. Teh                               Rp. 3000       |\n");
    printf("\t\t| 2. Air Mineral                       Rp. 3000       |\n");
    printf("\t\t| 3. Kembali ke Daftar Menu Pembelian                 |\n");
    printf("\t\t|                                                     |\n");
    printf("\t\t|=====================================================|\n");

    printf("\n\t Minuman apa yang ingin anda beli ?  ");
    scanf("%d", &pil);
    switch (pil)
    {
    case 1:
    {
        system("cls");
        printf("Anda Memilih :\n");
        printf("\n\t Minuman : Teh");
        printf("\n\t Harga   : Rp. 3000 \n");

        toppingTeh();
        break;
    }
    case 2:
    {
        nama_minuman = "Air Mineral";
        harga_minuman = 3000;
    kembali:
        system("cls");
        printf("Anda Memilih :\n");
        printf("\n\t Minuman : Air Mineral ");
        printf("\n\t Harga   : Rp. 3000");
        printf("\n\n\t Apakah ingin sudahi pesanan ? (y/t) ");
        scanf("%s", &airmineral);

        if (airmineral == 'y' || airmineral == 'Y')
        {
            printf("\n\t Pesanan Anda Sudah Tercatat");
            printf("\n\t Tekan enter untuk melanjutkan . . .");
            getche();
            system("cls");
            printf("Anda Memilih\n");
            printf("\n\t Minuman      : Air Mineral        Rp. 3000");
            printf("\n\t Topping      : -                  Rp. 0");
            printf("\n\t Harga Total  : Rp. 3000");
            printf("\n\t Silahkan tekan enter untuk kembali ke Beranda ");
            getche();
            beranda();
        }
        else if (airmineral == 't' || airmineral == 'T')
        {
            system("cls");
            printf("\n\n\tTekan enter untuk Kembali Memesan . . .");
            getche();
            daftar_menu();
        }
        else
        {
            system("cls");
            printf("Inputan anda salah !");
            printf("\n\t Tekan Enter Untuk Kembali");
            getche();
            goto kembali;
        }
    }
    case 3:
    {
        system("cls");
        daftar_menu();
        break;
    }
    default:
    {
        break;
    }
    }
}
void toppingTeh()
{
    int DP;
    char pilih;

    printf("\n\t Pilih Topping Teh ? (y/t) ");
    scanf("%s", &pilih);

    if (pilih == 'y' || pilih == 'Y')
    {
        printf("\t\t|==================== Topping Teh ===================|\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t| Nama Topping                        Harga          |\n");
        printf("\t\t| 1. Manis Panas                     Rp. 2000        |\n");
        printf("\t\t| 2. Dingin                          Rp. 1000        |\n");
        printf("\t\t| 3. Kembali ke Daftar Menu Pembelian                |\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t|====================================================|\n");

        printf("\n\t Toping apa yang ingin anda pilih ?  ");
        scanf("%d", &DP);
        switch (DP)
        {
        case 1:
        {
            nama_minuman = "Teh Manis Panas";
            harga_minuman = 3000 + 2000;
            system("cls");
            printf("\n\t Pesanan Anda Tercatat ");
            printf("\n\t Tekan enter untuk melanjutkan . . .");
            getche();
            system("cls");
            printf("Anda Memilih\n");
            printf("\n\t Minuman      : Teh              Rp. 3000");
            printf("\n\t Topping      : Manis Panas      Rp. 2000");
            printf("\n\t Harga Total  : Rp. 5000 \n");
            printf("\n\t Silahkan tekan enter untuk kembali ke Menu makanan ");
            getche();

            // save ke transaksi
            // transaksi(nama, nama_makanan, minuman);
            daftar_menu();
            break;
        }
        case 2:
        {
            nama_minuman = "Teh Dingin";
            harga_minuman = 3000 + 1000;
            system("cls");
            printf("\n\t Pesanan Anda Tercatat ");
            printf("Tekan enter untuk melanjutkan . . .");
            getche();
            system("cls");
            printf("Anda Memilih\n");
            printf("\n\t Minuman      : Teh          Rp. 3000");
            printf("\n\t Topping      : Dingin       Rp. 1000");
            printf("\n\t Harga Total  : Rp. 4000");
            printf("\n\t Silahkan tekan enter untuk kembali ke Menu makanan ");
            getche();
            daftar_menu();
            break;
        }
        case 3:
        {
            system("cls");
            daftar_menu();
            break;
        }
        default:
        {
            break;
        }
        }
    }
    else if (pilih == 't' || pilih == 'T')
    {
        nama_minuman = "Teh Tawar";
        harga_minuman = 3000;
    kembali:
        printf("Apakah anda ingin sudahi pesanan? (y/t) ");
        scanf("%s", &pilih);
        if (pilih == 'y' || pilih == 'Y')
        {
            system("cls");
            printf("Pesanan anda sudah tercatat !");
            printf("\n\t Minuman : Teh Tawar");
            printf("\n\t Harga   : RP. 3000");
            printf("\n\t Silahkan tekan enter untuk kembali ke Beranda ");
            getche();
            beranda();
        }
        else if (pilih == 't' || pilih == 'T')
        {
            system("cls");
            printf("Pesanan anda sudah tercatat !");
            printf("\n\t Tekan Enter Untuk Kembali");
            getche();
            daftar_menu();
        }
        else
        {
            system("cls");
            printf("Inputan anda salah !");
            printf("\n\t Tekan Enter Untuk Kembali");
            getche();
            goto kembali;
        }
    }
}

// tambah minuman
void tambah_minuman()
{
    minumanData dt_minuman;
    FILE *f_minuman;

    lihat_daftar_minuman();
    printf("\n");
    printf("\n");

    // Number Acak
    srand((unsigned)time(0));
    int id_random;
    id_random = (rand() % 999) + 1;

    dt_minuman.id_minuman = id_random;
    printf("\n \tMasukan nama Minuman : ");
    fflush(stdin);
    gets(dt_minuman.nama_minuman);

    printf("\n\tMasukan Harga Minuman : ");
    scanf("%d", &dt_minuman.harga_minuman);

    // Mneyimpan data minuman kedalam FILE
    f_minuman = fopen("data_minuman.dat", "ab+");

    if (!f_minuman)
    {
        printf("\n\t Gagal Membuat file minuman.dat");
        exit(1);
    }
    fwrite(&dt_minuman, sizeof(dt_minuman), 1, f_minuman);
    fclose(f_minuman);

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
    minumanData dt_minuman;
    FILE *f_minuman;

    f_minuman = fopen("data_minuman.dat", "rb");
   
    if (!f_minuman)
    {
        printf("\n\t Gagal membuat file minuman.dat");
        exit(1);
    }

    if (!feof(f_minuman)){
        printf("\n\tID Minuman\tNama Minuman\tHarga Minuman\n");
        
        while (fread(&dt_minuman, sizeof(dt_minuman), 1, f_minuman))
        {
            printf("\n\t%d\t\t%s\t\t%d\n", dt_minuman.id_minuman, dt_minuman.nama_minuman, dt_minuman.harga_minuman);
        }
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
}

void kembali_crud_minuman(){
    printf("\n\tTekan enter untuk kembali . . .");
    getche();
    crud_minuman();
}