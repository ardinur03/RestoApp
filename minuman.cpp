#include <iostream>
#include "prototype.h"

void toppingTeh();

void minumanMenu(){

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
            system("cls");
            printf("Teh\n");
            printf("\n\t Minuman : Teh");
            printf("\n\t Harga   : Rp. 3000 \n");

            toppingTeh();
            break;
        }
        case 2:
        {
            system("cls");
            printf("Air mineral\n");
            printf("\n\t Minuman : Air Mineral ");
            printf("\n\t Harga   : Rp. 3000");
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
void toppingTeh(){

    int DP;
    char pilih;

    printf("\n\t Teh Panas ? (y/t) ");
    scanf("%s", &pilih);

    if (pilih == 'y' || pilih == 'Y')
    {
        printf("\t\t|====================== Daftar Teh ==================|\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t| Nama Topping                        Harga          |\n");
        printf("\t\t| 1. Panas                           Rp. 1000        |\n");
        printf("\t\t| 2. Dingin                          Rp. 1000        |\n");
        printf("\t\t| 3. Kembali ke Daftar Menu Pembelian                |\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t|====================================================|\n");

         printf("\n\t Minuman apa yang ingin anda beli ?  ");
    scanf("%d", &DP);
    switch (DP)
    {
        case 1:
        {
            system("cls");
            printf("Teh\n");
            printf("\n\t Minuman : Teh panas");
            printf("\n\t Harga   : Rp. 4000 \n");

            toppingTeh();
            break;
        }
        case 2:
        {
            system("cls");
            printf("Air mineral\n");
            printf("\n\t Minuman : Teh Dingin ");
            printf("\n\t Harga   : Rp. 4000");
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

    }else{
        printf("Apakah anda ingin sudahi pesanan? (y/t) ");
        scanf("%s", &pilih);
        if(pilih == 'y' || pilih == 'Y'){
            printf("Pesanan anda sudah tercatat !");
            printf("\n\t Minuman : Teh Panas");
            printf("\n\t Harga   : RP. 4000");
        }else if(pilih == 't' || pilih == 'T'){
            printf("Pesanan anda belum tercatat !");
        }else{
            printf("Inputan anda salah !");
        }
    }
   
}

