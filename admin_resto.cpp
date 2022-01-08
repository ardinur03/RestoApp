#include <iostream>
#include "conio.h"
#include "beranda.h"
#include "admin_resto.h"
#include <time.h>
#include "string.h"


void tambah_minuman();
void crud_minuman();
void menu_crud_minuman();
void ubah_minuman();

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
        break;

    }
    case 2: // CRUD MINUMAN
    {
        crud_minuman();
        break;
    }
    case 3: // Lihat Transaksi
    {
        break;
    }
    case 4: // Lihat Daftar Pelanggan
    {
        break;
    }
    case 5: // Lihat Transaksi Pelanggan
    {
        break;
    }
    case 6: // Tutup Aplikasi
    {
        // exit aplikasi
        system("cls");
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
    printf("\n\t\t|====================== CRUD MAKANAN ======================|\n");
    printf("\t\t|                                                          |\n");
    printf("\t\t| 1. Tambah Makanan                                        |\n");
    printf("\t\t| 2. Ubah Makanan                                          |\n");
    printf("\t\t| 3. Hapus Makanan                                         |\n");
    printf("\t\t| 4. Lihat Daftar Makanan                                  |\n");
    printf("\t\t| 5. Detail Makanan                                        |\n");
    printf("\t\t| 6. Kembali                                               |\n");
    printf("\t\t|                                                          |\n");
    printf("\t\t|==========================================================|\n");

    printf("\n\t Masukkan pilihan anda : ");
    scanf("%d", &pilih);
     switch (pilih)
    {
    case 1: // Tambah Makanan
    {
        system("cls");
        // panggil prosedur tambah Makanan
        create_array_pointers_to_files();
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
    printf("\n\t\t|====================== CRUD MINUMAN ======================|\n");
    printf("\t\t|                                                          |\n");
    printf("\t\t| 1. Tambah Minuman                                        |\n");
    printf("\t\t| 2. Ubah Minuman                                          |\n");
    printf("\t\t| 3. Hapus Minuman                                         |\n");
    printf("\t\t| 4. Lihat Daftar Minuman                                  |\n");
    printf("\t\t| 5. Detail Minuman                                        |\n");
    printf("\t\t| 6. Kembali                                               |\n");
    printf("\t\t|                                                          |\n");
    printf("\t\t|==========================================================|\n");

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

