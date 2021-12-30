#include <iostream>
#include "app.h"

// prototype
void makanan(); 

void daftar_menu(){
	int pil = 0;

    printf("\t\t|====================== Daftar Pembelian =================|\n");
    printf("\t\t|                                                         |\n");
    printf("\t\t| 1. Makanan                                              |\n");
    printf("\t\t| 2. Minuman                                              |\n");
    printf("\t\t| 3. Kembali ke Beranda                                   |\n");
    printf("\t\t|                                                         |\n");
    printf("\t\t|=========================================================|\n");

    printf("\n\t Mau beli apa ?  ");
    scanf("%d", &pil);
    switch (pil)
    {
        case 1:
        {
            system("cls");
            makanan();
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

// Makanan
void makanan(){
     printf("\t\t|====================== Daftar Makanan ==================|\n");
    printf("\t\t|                                                         |\n");
    printf("\t\t| 1. Mie                                                  |\n");
    printf("\t\t| 2. Nasi                                                 |\n");
    printf("\t\t|                                                         |\n");
    printf("\t\t|=========================================================|\n");
}


// Minuman