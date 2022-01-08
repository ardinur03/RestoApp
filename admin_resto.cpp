#include <iostream>
#include "conio.h"
#include "beranda.h"
#include "minuman.h"
#include "makanan.h"

void crud_makanan();
void crud_minuman();
void menu_crud_makanan();
void menu_crud_minuman();

void admin_resto(){
    int pilih;
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
    default:
        break;
    }

}

// makanan
void crud_makanan(){
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
    printf("\t\t| 5. Kembali                                               |\n");
    printf("\t\t|                                                          |\n");
    printf("\t\t|==========================================================|\n");

    printf("\n\t Masukkan pilihan anda : ");
    scanf("%d", &pilih);
     switch (pilih)
    {
    case 1: // Tambah Makanan
    {
        // panggil prosedur tambah Makanan
        tambah_makanan();
        break;
    }
    case 2: // Ubah Makanan
    {
        // panggil prosedur ubah Makanan
        ubah_makanan();
        break;
    }
    case 3: // Hapus Makanan
    {
        // panggil prosedur hapus Makanan
        hapus_makanan();
        break;
    }
    case 4: // Lihat Daftar Minuman
    {
        // panggil prosedur lihat daftar minuman
        lihat_daftar_makanan();
        break;
    }
    case 5: // Kembali
    {
        // kembali ke menu utama
        break;
    }
    default:
        break;
    }

}
// minuman
void menu_crud_minuman(){
    int pilih;
    printf("\n\t\t|====================== CRUD MINUMAN ======================|\n");
    printf("\t\t|                                                          |\n");
    printf("\t\t| 1. Tambah Minuman                                        |\n");
    printf("\t\t| 2. Hapus Minuman                                         |\n");
    printf("\t\t| 3. Lihat Daftar Minuman                                  |\n");
    printf("\t\t| 4. Kembali                                               |\n");
    printf("\t\t|                                                          |\n");
    printf("\t\t|==========================================================|\n");

    printf("\n\t Masukkan pilihan anda : ");
    scanf("%d", &pilih);
    switch (pilih)
    {
    case 1: // Tambah Minuman
    {
        // panggil prosedur tambah minuman
        break;
    }
    case 2: // Hapus Minuman
    {
        // panggil prosedur hapus minuman
        break;
    }
    case 3: // Lihat Daftar Minuman
    {
        // panggil prosedur lihat daftar minuman
        break;
    }
    default:
        break;
    }
}

