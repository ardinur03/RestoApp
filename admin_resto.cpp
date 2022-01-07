#include <iostream>
#include "conio.h"
#include "beranda.h"

void admin_resto(){
    int pilih;
    // tampilan awal menu admin
    beranda_admin();

    printf("\n\t Masukkan pilihan anda : ");
    scanf("%s", &pilih);

    switch (pilih)
    {
    case 1: // CRUD Makanan
    {
        break;

    }
    case 2: // CRUD MINUMAN
    {
        break;
    }
    default:
        break;
    }

}

// makanan

// minuman
