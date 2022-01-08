#include <iostream>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "prototype.h"
#include "transaksi.h"
#include "admin_resto.h"
#include "makanan.h"

using namespace std;

void kembali_crud_makanan();
void daftar_menu_makanan();

string nama_makanan;
long int harga_makanan;

// makanan menu di role pelanggan
void makananMenu()
{
   // tampilan daftar makanan
    daftar_menu_makanan();   
}

// daftar menu yang di ambil dari data_makanan.dat
void daftar_menu_makanan(){
    system("cls");
    // local Variabel
    int pil, i =1;
    makananData dt_makanan;
    FILE *f_makanan;

    f_makanan = fopen("data_makanan.dat", "rt");
    if (f_makanan == NULL)
    {
        printf("File tidak dapat dibuka");
        exit(0);
    }
    else
    {
        // munculkan data makanan
        printf("| No | \tNama Makanan | \t Harga |\n");
        while (fread(&dt_makanan, sizeof(makananData), 1, f_makanan))
        {
            printf("\n \t %d \t %s. %d \n", i++, dt_makanan.nama_makanan, dt_makanan.harga_makanan);
        }

        // pilih nomor id berdasarkan nomor index
        printf("\n\nPilih nomor makanan yang ingin dipesan: ");

        scanf("%d", &pil);
    }

    fclose(f_makanan); 

}


// CRUD MAKANAN In ADMIN
// tambah Makanan
void tambah_makanan()
{
    makananData dt_makanan;
    FILE *f_makanan;

    lihat_daftar_makanan();
    printf("\n");
    printf("\n");

    // generate random number 3 digit
    srand((unsigned)time(0));
    int id_random3;
    id_random3 = (rand() % 999) + 1;
    dt_makanan.id_makanan = id_random3;

    printf("\t TAMBAH MAKANAN \n");
    printf("\n\tMasukkan Nama Makanan : ");
    fflush(stdin);
    gets(dt_makanan.nama_makanan);
    printf("\n\tMasukkan Harga Makanan : ");
    scanf("%d", &dt_makanan.harga_makanan);

    //  save to file makanan.dat
    f_makanan = fopen("data_makanan.dat", "ab+");
    if (!f_makanan)
    {
        printf("\n\t Gagal membuat file makanan.dat");
        exit(1);
    }
    fwrite(&dt_makanan, sizeof(dt_makanan), 1, f_makanan);
    fclose(f_makanan);

    system("cls");
    printf("\n\tData Makanan Berhasil Ditambahkan !");
    kembali_crud_makanan();
    
}

// create array of pointers to files
// void create_array_pointers_to_files()
// {
//     makananData dt_makanan;
//     FILE **f_makanan;
//     for (int i = 0; i < MAX_MAKANAN; i++)
//     {
//         f_makanan[i] = fopen("data_makanan.dat", "rb+");
//             // input data makanan
//         srand((unsigned)time(0));
//         int id_random3;
//         id_random3 = (rand() % 999) + 1;
//         dt_makanan.id_makanan = id_random3;

//         printf("\t TAMBAH MAKANAN \n");
//         printf("\n\tMasukkan Nama Makanan : ");
//         fflush(stdin);
//         gets(dt_makanan.nama_makanan);
//         printf("\n\tMasukkan Harga Makanan : ");
//         scanf("%d", &dt_makanan.harga_makanan);

//         //  save to file makanan.dat
//         f_makanan = fopen("data_makanan.dat", "ab+");
//         if (!f_makanan)
//         {
//             printf("\n\t Gagal membuat file makanan.dat");
//             exit(1);
//         }
        
//         // save array of pointers to files to file makanan.dat
//         fwrite(&dt_makanan, sizeof(dt_makanan), 1, f_makanan[i]);
//     }

    

// }

// ubah makanan
void ubah_makanan(){
    makananData dt_makanan;
    FILE *f_makanan;
    int id_makanan;
    char nama_makanan[30];
    int harga_makanan;
    int pilih;

    lihat_daftar_makanan();
    printf("\n");
    printf("\n");

    printf("\n\t EDIT MAKANAN\n");
    printf("\n\tMasukkan ID Makanan : ");
    scanf("%d", &id_makanan);
    printf("\n\tMasukkan Nama Makanan : ");
    fflush(stdin);
    gets(nama_makanan);
    printf("\n\tMasukkan Harga Makanan : ");
    scanf("%d", &harga_makanan);

    f_makanan = fopen("data_makanan.dat", "rb+");
    if (!f_makanan)
    {
        printf("\n\t Gagal membuat file makanan.dat");
        exit(1);
    }
    while (fread(&dt_makanan, sizeof(dt_makanan), 1, f_makanan))
    {
        if (dt_makanan.id_makanan == id_makanan)
        {
            dt_makanan.id_makanan = id_makanan;
            strcpy(dt_makanan.nama_makanan, nama_makanan);
            dt_makanan.harga_makanan = harga_makanan;
            fseek(f_makanan, -sizeof(dt_makanan), SEEK_CUR);
            fwrite(&dt_makanan, sizeof(dt_makanan), 1, f_makanan);
            printf("\n\tData berhasil diubah");
            break;
        }
    }
    fclose(f_makanan);
    
    system("cls");
    printf("Data berhasil diubah");
    kembali_crud_makanan();
}

// hapus data makanan
void hapus_makanan(){
    makananData dt_makanan;
    FILE *f_makanan;
    int id_makanan;
    int pilih;

    // konfirmasi penghapusan data
    printf("\n\tApakah anda yakin ingin menghapus semua data ?\n");
    printf("\n\t1. Ya");
    printf("\n\t2. Tidak");
    printf("\n\tMasukkan Pilihan : ");
    scanf("%d", &pilih);
    if (pilih == 1)
    {
        // delete all data in file data_makanan.dat
        f_makanan = fopen("data_makanan.dat", "wb+");
        fclose(f_makanan);
        printf("\n\tData berhasil dihapus");
    }
    else if (pilih == 2)
    {
        printf("\n\tData tidak dihapus");
    }
    else
    {
        printf("\n\tInputan anda salah !");
    }
   
    system("cls");
    printf("\n\tData berhasil dihapus !");
    kembali_crud_makanan();
}

// lihat daftar makanan
void lihat_daftar_makanan(){
    makananData dt_makanan;
    FILE *f_makanan;

    f_makanan = fopen("data_makanan.dat", "rb");
    if (!f_makanan)
    {
        printf("\n\t Gagal membuat file makanan.dat");
        exit(1);
    }
    printf("|===============================================================|");
    printf("\n|\t\t\tDAFTAR MAKANAN\t\t\t\t|");
    printf("\n|===============================================================|");
    printf("\n\tID Makanan\tNama Makanan\t\tHarga Makanan\n");
    
    // cek isi file makanan.dat jika kosong
    if(f_makanan == NULL){
        printf("\n\t\t\t Data Makanan Kosong");
    }
    while (fread(&dt_makanan, sizeof(dt_makanan), JUM_BLOK, f_makanan))
    {
        printf("\n\t%d\t\t%s\t\t Rp. %d\n", dt_makanan.id_makanan, dt_makanan.nama_makanan, dt_makanan.harga_makanan);
    }

    fclose(f_makanan);
}

// lihat data berdasarkan id
void detail_makanan(){
    makananData dt_makanan;
    FILE *f_makanan;
    int id_makanan, pilih, cek_makanan;

    printf("\n\t DETAIL MAKANAN\n");
    printf("\n\tMasukkan ID Makanan  : ");
    scanf("%d", &id_makanan);

    f_makanan = fopen("data_makanan.dat", "rb");
    if (!f_makanan)
    {
        printf("\n\t Gagal membuat file makanan.dat");
        exit(1);
    }

    // validasi cek jika ada makanana dengan id yang dicari
    cek_makanan = 1;
    while (fread(&dt_makanan, sizeof(dt_makanan), 1, f_makanan))
    {
        if (dt_makanan.id_makanan == id_makanan)
        {
            cek_makanan = 0;
            printf("\n\tID Makanan\tNama Makanan\t\tHarga Makanan\n");
            printf("\n\t%d\t\t%s\t\t Rp. %d\n", dt_makanan.id_makanan, dt_makanan.nama_makanan, dt_makanan.harga_makanan);
            break;
        }
    }
    if (cek_makanan == 1)
    {
        printf("\n\tData Makanan tidak ditemukan !");
    }

    kembali_crud_makanan();
}

// prosedure kembali ke menu
void kembali_crud_makanan(){
    printf("\n\tTekan enter untuk kembali . . .");
    getche();
    crud_makanan();
}