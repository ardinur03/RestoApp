#include <iostream>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "prototype.h"
#include "transaksi.h"
#include "admin_resto.h"

using namespace std;

void kembali_crud_makanan();
int ambil_nilai_berdasarkan_id(int p_id_makanan);
string nama_makanan;
long int harga_makanan;

// daftar menu yang di ambil dari data_makanan.dat
int daftar_menu_makanan(){
    system("cls");
    // local Variabel
    int pil, i =1;
    
    lihat_daftar_makanan();
    // pilih nomor id berdasarkan nomor index
    printf("\n\nPilih nomor makanan yang ingin dipesan : ");
    scanf("%d", &pil);
    return pil;
}


// CRUD MAKANAN In ADMIN
// tambah Makanan
void tambah_makanan()
{
    makananData dt_makanan[100];
    FILE *f_makanan;
    int i = 0;
    f_makanan = fopen("data_makanan.dat", "a+b");

    lihat_daftar_makanan();
    printf("\n");
    printf("\n");

    // cek apakah file bisa dibuka
    if (f_makanan == NULL)
    {
        printf("File tidak dapat dibuka");
        getch();
        kembali_crud_makanan();
    }
    else
    {
        // cek isi file data_makanan.dat apakah ada ada jika ada data maka lanjutkan index elementnya
        if (fread(&dt_makanan, sizeof(makananData), 1, f_makanan) == 1)
        {
            while (fread(&dt_makanan, sizeof(makananData), 1, f_makanan))
            {
                i++;
            }
        }

        // input data makanan baru berdassarkan nomor index variabel arraynya
        printf("\t TAMBAH MAKANAN \n");
        printf("\t\t Masukkan nama makanan  : ");
        fflush(stdin);
        gets(dt_makanan[i].nama_makanan);
        printf("\t\t Masukkan harga makanan : ");
        fflush(stdin);
        scanf("%ld", &dt_makanan[i].harga_makanan); 

        // generate random number 3 digit
        srand((unsigned)time(0));
        int id_random3;
        id_random3 = (rand() % 999) + 1;
        dt_makanan[i].id_makanan = id_random3;

        // tambahkan data makanan baru ke file data_makanan.dat
        fwrite(&dt_makanan[i], sizeof(makananData), 1, f_makanan);
        fclose(f_makanan);

        // refresh variabel array
        i = 0;
    }

    system("cls");
    printf("Data makanan berhasil di tambahkan !");
    kembali_crud_makanan();
    
}

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
    makananData dt_makanan[100];
    FILE *f_makanan;
    int i = 0, index = 1;

    f_makanan = fopen("data_makanan.dat", "rb+");
    if (!f_makanan)
    {
        printf("\n\t Gagal membuat file makanan.dat");
        exit(1);
    }

    // print data berdasarkan no index
    printf("|=======================================================================|");
    printf("\n|\t\t\t        DAFTAR MAKANAN\t\t\t\t|");
    printf("\n|=======================================================================|");
    printf("\n\tNO\tID Makanan\tNama Makanan\t\tHarga Makanan\n");
    while (fread(&dt_makanan[i], sizeof(dt_makanan[i]), 1, f_makanan))
    {
        printf("\n\t%d\t%d \t\t %s\t\t Rp. %d\n", index++, dt_makanan[i].id_makanan, dt_makanan[i].nama_makanan, dt_makanan[i].harga_makanan);
        i++;
    }

    fclose(f_makanan);
}

// lihat data berdasarkan id
void detail_makanan(){
    makananData dt_makanan;
    FILE *f_makanan;
    int id_makanan, pilih;

    printf("\n\t DETAIL MAKANAN\n");
    printf("\n\tMasukkan ID Makanan  : ");
    scanf("%d", &id_makanan);

    ambil_nilai_berdasarkan_id(id_makanan);

    kembali_crud_makanan();
}

// prosedure kembali ke menu
void kembali_crud_makanan(){
    printf("\n\tTekan enter untuk kembali . . .");
    getche();
    crud_makanan();
}


// function cari id
int ambil_nilai_berdasarkan_id(int p_id_makanan){
    makananData dt_makanan;
    FILE *f_makanan;
    int id_makanan, pilih;
    int cek_makanan;
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
        if (dt_makanan.id_makanan == p_id_makanan)
        {
            cek_makanan = 0;
            // cetak data dengan id yang dicari yang rapi
            printf("\n\n\t Data Makanan Berhasil di temukan !");
            printf("\n\n\tID Makanan\tNama Makanan\t\tHarga Makanan\n");
            printf("\n\t%d \t\t %s\t\t Rp. %d\n", dt_makanan.id_makanan, dt_makanan.nama_makanan, dt_makanan.harga_makanan);
        }
    }
    if (cek_makanan == 1)
    {
        printf("\n\tData Makanan tidak ditemukan !");
    }

    return 0;
}