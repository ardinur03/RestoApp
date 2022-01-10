#include <iostream>
#include "conio.h"
#include "beranda.h"
#include "minuman.h"
#include "makanan.h"
#include "transaksi.h"
#include "loading.h"
void crud_makanan();
void crud_minuman();
void menu_crud_makanan();
void menu_crud_minuman();

void admin_resto(){
    int pilih;
    system("cls");

    // tampilan awal menu admin
    beranda_admin();

    printf("\n\t Masukkan pilihan anda : ");
    scanf("%d", &pilih);

    switch (pilih)
    {
    case 1: // CRUD Makanan
    {
        crud_makanan();
        break;
    }
    case 2: // CRUD MINUMAN
    {
        crud_minuman();
        break;
    }
    case 3: // Lihat Transaksi
    {
        lihat_daftar_transaksi();
        printf("\n\t Tekan enter untuk kembali ...");
        getche();
        system("cls");    
        admin_resto();
        break;
    }
    case 4: // Lihat Daftar Pelanggan
    {
        lihat_daftar_transaksi_pelanggan();
        break;
    }
    case 5: // Lihat Transaksi Pelanggan
    {
        lihat_transaksi_satu_pelanggan_void();
        break;
    }
    case 6: // Tutup Aplikasi
    {
        // exit aplikasi
        system("cls");
        salam();
        exit(0);
        break;
    }
    default:
        break;
    }

}

// makanan
void crud_makanan(){
    system("cls");
    menu_crud_makanan();
}


// minuman
void crud_minuman(){
    menu_crud_minuman();
}

// tampilan
// makanan
void menu_crud_makanan(){
    int pilih;
    printf("\t\t|=============================================================|\n");
    printf("\t\t|                       >>CRUD MAKANAN<<                      |\n");
    printf("\t\t|=============================================================|\n");
    printf("\t\t|                                                             |\n");
    printf("\t\t|  1. Tambah Makanan                                          |\n");
    printf("\t\t|  2. Ubah Makanan                                            |\n");
    printf("\t\t|  3. Hapus Makanan                                           |\n");
    printf("\t\t|  4. Lihat Daftar Makanan                                    |\n");
    printf("\t\t|  5. Detail Makanan                                          |\n");
    printf("\t\t|  6. Kembali                                                 |\n");
    printf("\t\t|                                                             |\n");
    printf("\t\t|                                                             |\n");
    printf("\t\t|=============================================================|\n");
    printf("\t\t|                  COPYRIGHT 2021 | RestoApp                  |\n");
    printf("\t\t|=============================================================|\n");
    printf("\n\t Masukkan pilihan anda : ");
    scanf("%d", &pilih);
     switch (pilih)
    {
    case 1: // Tambah Makanan
    {
        system("cls");
        // panggil prosedur tambah Makanan
        tambah_makanan();
        break;
    }
    case 2: // Ubah Makanan
    {
        system("cls");
        // panggil prosedur ubah Makanan
        ubah_makanan();
        break;
    }
    case 3: // Hapus Makanan
    {
        system("cls");
        // panggil prosedur hapus Makanan
        hapus_makanan();
        break;
    }
    case 4: // Lihat Daftar Minuman
    {
        system("cls");
        // panggil prosedur lihat daftar minuman
        lihat_daftar_makanan();
        printf("\n\tTekan enter untuk kembali . . .");
        getche();
        crud_makanan();
        break;
    }
    case 5: // Detail Makanan
    {
        system("cls");
        // panggil prosedur detail makanan
        detail_makanan();
        break;
    }
    case 6: // Kembali
    {
        // kembali ke menu utama
        admin_resto();
        break;
    }
    default:
        break;
    }

}

// minuman
void menu_crud_minuman(){
    int pilih;
    system("cls");
    printf("\t\t|=============================================================|\n");
    printf("\t\t|                       >>CRUD MINUMAN<<                      |\n");
    printf("\t\t|=============================================================|\n");
    printf("\t\t|                                                             |\n");
    printf("\t\t|  1. Tambah Minuman                                          |\n");
    printf("\t\t|  2. Ubah Minuman                                            |\n");
    printf("\t\t|  3. Hapus Minuman                                           |\n");
    printf("\t\t|  4. Lihat Daftar Minuman                                    |\n");
    printf("\t\t|  5. Detail Minuman                                          |\n");
    printf("\t\t|  6. Kembali                                                 |\n");
    printf("\t\t|                                                             |\n");
    printf("\t\t|                                                             |\n");
    printf("\t\t|=============================================================|\n");
    printf("\t\t|                  COPYRIGHT 2021 | RestoApp                  |\n");
    printf("\t\t|=============================================================|\n");
    printf("\n\t Masukkan pilihan anda : ");
    scanf("%d", &pilih);
    switch (pilih)
    {
    case 1: // Tambah Minuman
    {
        system("cls");
        // panggil prosedur tambah minuman
        tambah_minuman();
        break;
    }
    case 2: // Hapus Minuman
    {
        system("cls");
        // panggil prosedur hapus minuman
        ubah_minuman();
        break;
    }
    case 3: // hapus daftar minuman
    {
        system("cls");
        // panggil prosedur lihat daftar minuman
        hapus_minuman();
        break;
    }
    case 4: // lihat daftar minuman
    {
        system("cls");
        // panggil prosedur lihat daftar minuman
        lihat_daftar_minuman();
        printf("\n\tTekan enter untuk kembali . . .");
        getche();
        crud_minuman();
        break;
    }
    case 5: // detail minuman
    {
        system("cls");
        // panggil prosedur detail minuman
        detail_minuman();
        break;
    }
    case 6: // kembali
    {
        // kembali ke menu utama
        admin_resto();
        break;
    }
    default:
        break;
    }
}

