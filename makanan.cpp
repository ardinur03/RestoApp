#include <iostream>
#include "prototype.h"

void getMakanan(){
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
            printf("Nasi Goreng\n");
            break;
        }
        case 2: // Ayam Geprek
        {
            system("cls");
            printf("Ayam Geprek\n");
            break;
        }
        case 3: // Ikan Bakar
        {
            system("cls");
            printf("Ikan Bakar\n");
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