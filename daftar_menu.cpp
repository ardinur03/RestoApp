#include <iostream>
#include "prototype.h"

void daftar_menu(){
	int pil = 0;

    system("cls");
    printf("\t\t|========================= Daftar Menu ====================|\n");
    printf("\t\t|                                                          |\n");
    printf("\t\t| 1. Makanan                                               |\n");
    printf("\t\t| 2. Minuman                                               |\n");
    printf("\t\t| 3. Kembali ke Beranda                                    |\n");
    printf("\t\t|                                                          |\n");
    printf("\t\t|==========================================================|\n");

    printf("\n\t Mau beli apa ?  ");
    scanf("%d", &pil);
    switch (pil)
    {
        case 1:
        {
            system("cls");
            makananMenu();
            break;
        }
        case 2:
        {
            system("cls");
            minumanMenu();
            break;
        }
        case 3:
        {
            system("cls");
            app();
            break;
        }
        default:
        {
            break;
        }
    }
}

