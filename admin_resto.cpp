#include <iostream>
#include "conio.h"
#include "beranda.h"
#include "minuman.h"

void crud_minuman();
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

// minuman
void crud_minuman(){
    menu_crud_minuman();
}


// tampilan
// makanan
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

