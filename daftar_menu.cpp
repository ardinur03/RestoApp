#include <iostream>
#include "app.h"
#include "daftar_menu.h"

// prototype
void makanan();

void minuman();

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
        case 2:
        {
            system("cls");
            minuman();
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

    int pil;
    printf("\t\t|====================== Daftar Makanan ==============|\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t| 1. Nasi Goreng                      Rp. 25000      |\n");
    printf("\t\t| 2. Ayam Geprek                      Rp. 15000      |\n");
    printf("\t\t| 3. Ikan Bakar                       Rp. 50000      |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|====================================================|\n");

   }



// Minuman
void minuman(){
    printf("\t\t|====================== Daftar Minuman =============|\n");
    printf("\t\t|                                                   |\n");
    printf("\t\t| 1. Teh                             Rp. 3000       |\n");
    printf("\t\t| 2. Air Mineral                     Rp. 3000       |\n");
    printf("\t\t|                                                   |\n");
    printf("\t\t|===================================================|\n");

}


//}



