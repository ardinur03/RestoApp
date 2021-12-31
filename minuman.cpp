#include <iostream>
#include "prototype.h"

void getMinuman(){

    int pil;

    printf("\t\t|====================== Daftar Minuman ===============|\n");
    printf("\t\t|                                                     |\n");
    printf("\t\t| Nama Minuman                         Harga          |\n");
    printf("\t\t| 1. Teh                               Rp. 3000       |\n");
    printf("\t\t| 2. Air Mineral                       Rp. 3000       |\n");
    printf("\t\t| 3. Kembali ke Daftar Menu Pembelian                 |\n");
    printf("\t\t|                                                     |\n");
    printf("\t\t|=====================================================|\n");

    printf("\n\t Minuman apa yang ingin anda beli ?  ");
    scanf("%d", &pil);
    switch (pil)
    {
        case 1:
        {
            system("clear");
            printf("Teh\n");
            break;
        }
        case 2:
        {
            system("cls");
            printf("Air mineral\n");
            break;
        }
        case 3:
        {
            system("cls");
            daftar_menu();
            break;
        }
        default:
        {
            break;
        }
    }
}
