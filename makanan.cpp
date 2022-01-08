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

void topping_nasi_goreng();
void topping_ayamgeprek();
void topping_ikan();
void kembali_crud_makanan();
// void catat_transaksi(string nama_pr, string makanan_pr, string minuman_pr, int harga_normal_pr, int diskon_pr, int harga_total_pr);
// void catat_makanan(string nama_makanan, int harga);

string nama_makanan;
long int harga_makanan;

void makananMenu()
{
    // local Variabel
    int pil;

    printf("\t\t|====================== Daftar Makanan ==============|\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t| Nama Makanan                        Harga          |\n");
    printf("\t\t| 1. Nasi Goreng                      Rp. 25000      |\n");
    printf("\t\t| 2. Ayam Geprek                      Rp. 15000      |\n");
    printf("\t\t| 3. Ikan Bakar                       Rp. 50000      |\n");
    printf("\t\t| 4. Kembali ke Daftar Menu Pembelian                |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|====================================================|\n");

    printf("\n\t Makanan apa yang ingin anda beli ?  ");
    scanf("%d", &pil);
    switch (pil)
    {
    case 1: // Nasi Goreng
    {
        system("cls");
        printf("Anda memilih : \n");
        printf("\tMakanan : Nasi Goreng\n");
        printf("\tHarga   : Rp. 25000\n");
        topping_nasi_goreng();
        break;
    }
    case 2: // Ayam Geprek
    {
        system("cls");
        printf("Ayam Geprek\n");
        printf("\t Makanan : Ayam Geprek \n");
        printf("\t Harga   : Rp. 15000 \n");

        topping_ayamgeprek();
        break;
    }
    case 3: // Ikan Bakar
    {
        system("cls");
        printf("Ikan Bakar\n");
        printf("\t Makanan : Ikan Bakar \n");
        printf("\t Harga   : Rp. 50000 \n");

        topping_ikan();
        break;
    }
    case 4: // Kembali ke Daftar Menu Pembelian
    {
        system("cls");
        daftar_menu();
        break;
    }
    default: // default
    {
        system("cls");
        app();
        break;
    }
    }
}

void topping_nasi_goreng()
{

    int pilTop;             // Variabel Lokal ( Untuk case memilih topping)
    int akhir, harga_minum; // Varibel Lokal ( untuk case pesanan tidak tercatat kembali ke menu)
    char pilih;             // Variabel Lokal
    string nama_minum;      // Variabel Lokal

    printf("\n\tApakah ingin menggunakan Topping ? (y/t) ");
    scanf("%s", &pilih);

    if (pilih == 'y' || pilih == 'Y')
    {
        system("cls");
        printf("\t\t|====================== Daftar Topping ==============|\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t| Nama Topping                        Harga          |\n");
        printf("\t\t| 1. Pedas                            Rp. 1000       |\n");
        printf("\t\t| 2. Tambah 1/2 porsi                 Rp. 11000      |\n");
        printf("\t\t| 3. Kembali ke Daftar Menu Pembelian                |\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t|====================================================|\n");

        printf("\n\t Topping apa yang ingin anda tambahkan ?  ");
        scanf("%d", &pilTop);
        switch (pilTop)
        {
        case 1: // pedas
        {

            nama_makanan = "Nasi Goreng Pedas";
            harga_makanan = 25000 + 1000;

            // printf("%s\n", namaMakanan.c_str());
            system("cls");
            // catat_makanan(nama_makanan, harga_makanan);
            printf("\n\t Pesanan Anda Tercatat ");
            printf("\n\t Tekan enter untuk melanjutkan . . .");
            getche();
            system("cls");
            printf("Anda memilih : \n");
            printf("\tMakanan : Nasi Goreng Pedas\n");
            printf("\tHarga   : Rp. 26000");
            printf("\n\n\tTekan enter untuk Kembali Memesan . . .");
            getche();
            daftar_menu();

            break;
        }
        case 2:
        {
            nama_makanan = "Nasi Goreng Tambah 1/2 Porsi";
            harga_makanan = 25000 + 11000;

            system("cls");
            printf("\n\t Pesanan Anda Tercatat ");
            printf("\n\t Tekan enter untuk melanjutkan . . .");
            getche();
            system("cls");
            printf("Anda memilih : \n");
            printf("\tMakanan : Nasi Goreng + 1/2 porsi\n");
            printf("\tHarga   : Rp. 36000");
            printf("\n\n\tTekan enter untuk Kembali Memesan . . .");
            getche();
            daftar_menu();

            break;
        }
        default:
        {
            system("cls");
            break;
        }
        }
    }
    else
    {

        nama_makanan = "Nasi Goreng";
        harga_makanan = 25000;

        printf("\tApakah anda ingin sudahi pesanan? (y/t) ");
        scanf("%s", &pilih);
        if (pilih == 'y' || pilih == 'Y')
        {

            system("cls");
            printf("\tPesanan anda sudah tercatat !");
            printf("\n\tTekan enter untuk melanjutkan . . .");

            getche();

            system("cls");
            printf("\tBerikut Pesanan Anda :");
            printf("\n\n\t Makanan : Nasi Goreng");
            printf("\n\t Harga   : RP. 25000");
            printf("\n\n\t Apakah anda ingin memesan Minuman? (y/t)");
            scanf("%s", &pilih);
            if (pilih == 'y' || pilih == 'Y')
            {
                system("cls");
                minumanMenu();
            }
            else if (pilih == 't' || pilih == 'T')
            {
                system("cls");
                daftar_menu();
            }
            else
            {
                system("cls");
                printf("Inputan anda salah !");
                getche();
            }
            getche();
            beranda();
        }
        else if (pilih == 't' || pilih == 'T')
        {
            printf("\n\t Pesanan anda sudah tercatat !\n");
            printf("\n\n\tTekan enter untuk Kembali Memesan . . .");
            getche();
            daftar_menu();
        }
        else
        {
            system("cls");
            printf("Inputan anda salah !");
            getche();
        }
    }
}
void topping_ayamgeprek()
{

    int akhir;
    int pilTop;
    char pilih; // var lokal

    printf("\n\tApakah ingin Menggunakan Topping ? (y/t) ");
    scanf(" %s", &pilih);

    if (pilih == 'y' || pilih == 'Y')
    {
        system("cls");
        printf("\t\t|====================== Daftar Topping ==============|\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t| Nama Topping                        Harga          |\n");
        printf("\t\t| 1. Nasi                            Rp. 5000        |\n");
        printf("\t\t| 2. Kentang                         Rp. 5000        |\n");
        printf("\t\t| 3. Kembali ke Daftar Menu Pembelian                |\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t|====================================================|\n");

        printf("\n\t Topping apa yang ingin anda pilih ?  ");
        scanf("%d", &pilTop);
        switch (pilTop)
        {
        case 1: // nasi
        {
            nama_makanan = "Ayam Geprek Nasi";
            harga_makanan = 15000 + 5000;

            system("cls");
            printf("\n\t Pesanan Anda Tercatat ");
            printf("\n\t Tekan enter untuk melanjutkan . . .");

            getche();

            system("cls");
            printf("Anda memilih : \n");
            printf("\tMakanan      : Ayam Geprek         Rp. 15000\n");
            printf("\tTopping      : Nasi                Rp. 5000\n");
            printf("\tHarga Total  : Rp. 20000 ");
            printf("\n\n\tTekan enter untuk Kembali Memesan . . .");
            getche();
            daftar_menu();
            break;
        }
        case 2:
        {
            nama_makanan = "Ayam Geprek Kentang";
            harga_makanan = 15000 + 5000;

            system("cls");
            printf("\n\t Pesanan Anda Tercatat ");
            printf("\n\t Tekan enter untuk melanjutkan . . .");
            getche();
            system("cls");
            printf("Anda memilih : \n");
            printf("\tMakanan      : Ayam Geprek         Rp. 15000\n");
            printf("\tTopping      : Kentang             Rp. 5000\n");
            printf("\tHarga Total  : Rp. 20000");
            printf("\n\n\tTekan enter untuk Kembali Memesan . . .");
            getche();
            daftar_menu();
            break;
        }
        default:
        {
            system("cls");
            topping_ayamgeprek();
            break;
        }
        }
    }
    else
    {
        nama_makanan = "Ayam Geprek";
        harga_makanan = 15000;

        printf("\tApakah anda ingin sudahi pesanan? (y/t) ");
        scanf("%s", &pilih);
        if (pilih == 'y' || pilih == 'Y')
        {
            system("cls");
            printf("\n\tPesanan anda sudah tercatat !");
            printf("\n\tTekan enter untuk melanjutkan . . .");
            getche();
            system("cls");
            printf("\tBerikut Pesanan Anda :\n");
            printf("\n\t Makanan      : Ayam Geprek");
            printf("\n\t Harga Total  : RP. 15000");
            printf("\n\n\tTekan enter untuk Kembali ke beranda . . .");
            getche();
            beranda();
        }
        else if (pilih == 't' || pilih == 'T')
        {

            printf("\n\t Pesanan anda sudah tercatat !\n");
            printf("\n\n\tTekan enter untuk Kembali Memesan . . .");
            getche();
            daftar_menu();
        }
        else
        {
            printf("Inputan anda salah !");
        }
    }
}

void topping_ikan()
{

    int akhir;
    int pilTop;
    char pilih; // var lokal

    printf("\n\tApakah ingin memilih ikan (jika anda pilih TIDAK, sistem akan mencatat Ikan Mas Otomatis) ? (y/t) ");
    scanf(" %s", &pilih);

    if (pilih == 'y' || pilih == 'Y')
    {
        system("cls");
        printf("\t\t|====================== Jenis Ikan ==================|\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t| Jenis Ikan                            Harga        |\n");
        printf("\t\t| 1. Ikan Mas                              -          |\n");
        printf("\t\t| 2. Ikan Gurame                        Rp. 80000    |\n");
        printf("\t\t| 3. Kembali ke Daftar Menu Pembelian                |\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t|====================================================|\n");

        printf("\n\t Makanan apa yang ingin anda beli ?  ");
        scanf("%d", &pilTop);
        switch (pilTop)
        {
        case 1:
        {
            nama_makanan = "Ikan Bakar Mas";
            harga_makanan = 50000;
            system("cls");
            printf("\n\t Pesanan Anda Tercatat ");
            printf("\n\t Tekan enter untuk melanjutkan . . .");
            getche();
            system("cls");
            printf("Anda memilih : \n");
            printf("\tMakanan : Ikan Bakar          Rp. 50000\n");
            printf("\tJenis   : Ikan Mas                -\n");
            printf("\tHarga   : Rp. 50000 ");
            printf("\n\n\tTekan enter untuk Kembali Memesan . . .");
            getche();
            daftar_menu();
            break;
        }
        case 2: // gurame
        {
            nama_makanan = "Ikan Bakar Gurame";
            harga_makanan = 50000 + 30000;

            system("cls");
            printf("\n\t Pesanan Anda Tercatat ");
            printf("\n\t Tekan enter untuk melanjutkan . . .");
            getche();
            system("cls");
            printf("Anda memilih : \n");
            printf("\tMakanan    : Ikan Bakar       Rp. 50000\n");
            printf("\tJenis Ikan : Ikan Gurame      Rp. 30000\n");
            printf("\tHarga      : Rp. 80000");
            printf("\n\n\tTekan enter untuk Kembali Memesan . . .");
            getche();
            daftar_menu();
            break;
        }
        default:
        {
            system("cls");
            topping_ikan();
            break;
        }
        }
    }
    else
    {
        nama_makanan = "Ikan Bakar Mas";
        harga_makanan = 50000;

        printf("\tApakah anda ingin sudahi pesanan? (y/t) ");
        scanf("%s", &pilih);
        if (pilih == 'y' || pilih == 'Y')
        {

            system("cls");
            printf("\n\tPesanan anda sudah tercatat !");
            printf("\n\tTekan enter untuk melanjutkan . . .");
            getche();
            system("cls");
            printf("\tBerikut Pesanan Anda :");
            printf("\n\n\t Makanan : Ikan Mas");
            printf("\n\t Harga   : RP. 50000");
            printf("\n\n\tTekan enter untuk Kembali Ke Beranda . . .");
            getche();
            beranda();
        }
        else if (pilih == 't' || pilih == 'T')
        {

            printf("\n\t Pesanan anda sudah tercatat !\n");
            printf("\n\n\tTekan enter untuk Kembali Memesan . . .");
            getche();
            daftar_menu();
        }
        else
        {
            printf("Inputan anda salah !");
        }
    }
}

// // input transaksi makanan
// void catat_makanan(string nama_makanan, int harga)
// {
//     Transaksi dt_transaksi;
//     FILE *f_transaksi;

//     // generate random number
//     srand((unsigned)time(0));
//     int id_random;
//     id_random = (rand() % 6) + 1;

//     dt_transaksi.id_transaksi = id_random;
//     dt_transaksi.makanan, nama_makanan;
//     dt_transaksi.makanan, harga;

//     //  save to file transaksi.dat
//     f_transaksi = fopen("data_transaksi.dat", "ab+");
//     if (!f_transaksi)
//     {
//         printf("\n\t Gagal membuat file transaksi.dat");
//         exit(1);
//     }
//     fwrite(&dt_transaksi, sizeof(dt_transaksi), 1, f_transaksi);
//     fclose(f_transaksi);
// }


// CRUD MAKANAN
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
    printf("Data berhasil diubah");
    kembali_crud_makanan();
}

// hapus data 1 makanan
void hapus_makanan(){
    makananData dt_makanan;
    FILE *f_makanan;
    int id_makanan;
    int pilih;

    /*printf("\n\tMasukkan ID Makanan : ");
    scanf("%d", &id_makanan);

    f_makanan = fopen("data_makanan.dat", "rb+");
    // cek id ada atau tidak
    while (fread(&dt_makanan, sizeof(dt_makanan), 1, f_makanan))
    {
        if (dt_makanan.id_makanan == id_makanan)
        {
            printf("\n\tApakah anda yakin ingin menghapus data ini ?\n");
            printf("\n\t1. Ya");
            printf("\n\t2. Tidak");
            printf("\n\tMasukkan Pilihan : ");
            scanf("%d", &pilih);
            if (pilih == 1)
            {
                fseek(f_makanan, -sizeof(dt_makanan), SEEK_CUR);
                fwrite(&dt_makanan, sizeof(dt_makanan), 1, f_makanan);
                printf("\n\tData berhasil dihapus");
                break;
            }
            else if (pilih == 2)
            {
                printf("\n\tData tidak dihapus");
                break;
            }
            else
            {
                printf("\n\tInputan anda salah !");
            }
        }
    }
    */
    
    
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
        printf("\n\t\t\t Makanan Kosong");
    }
    while (fread(&dt_makanan, sizeof(dt_makanan), JUM_BLOK, f_makanan))
    {
        printf("\n\t%d\t\t%s\t\t Rp. %d\n", dt_makanan.id_makanan, dt_makanan.nama_makanan, dt_makanan.harga_makanan);
    }

    fclose(f_makanan);
}

void kembali_crud_makanan(){
    system("cls");
    printf("\n\tTekan enter untuk kembali . . .");
    getche();
    crud_makanan();
}