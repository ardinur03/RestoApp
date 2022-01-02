#include <iostream>
#include "prototype.h"
#include <conio.h>

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

    printf("\n\t Pilih Topping Teh ? (y/t) ");
    scanf("%s", &pilih);

    if (pilih == 'y' || pilih == 'Y')
    {
        printf("\t\t|==================== Topping Teh ===================|\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t| Nama Topping                        Harga          |\n");
        printf("\t\t| 1. Manis Panas                     Rp. 2000        |\n");
        printf("\t\t| 2. Dingin                          Rp. 1000        |\n");
        printf("\t\t| 3. Kembali ke Daftar Menu Pembelian                |\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t|====================================================|\n");

        printf("\n\t Toping apa yang ingin anda pilih ?  ");
        scanf("%d", &DP);
        switch (DP)
        {
            case 1:
            {
                system("cls");
                printf("\n\t Pesanan Anda Tercatat ");
                printf("Tekan enter untuk melanjutkan . . .");

                getche();

                system("cls");
                printf("Anda Memilih\n");
                printf("\n\t Minuman      : Teh              Rp. 3000");
                printf("\n\t Topping      : Manis Panas      Rp. 2000");
                printf("\n\t Harga Total  : Rp. 5000 \n");

                printf("\n\t Silahkan tekan enter untuk kembali ke Menu makanan ");

                getche();

                daftar_menu();
                break;
            }
            case 2:
            {
                system("cls");
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
                printf("\n\tPesanan Anda Tercatat ");
                printf("\n\tTekan enter untuk melanjutkan . . .");
=======
                printf("\n\t Pesanan Anda Tercatat ");
                printf("Tekan enter untuk melanjutkan . . .");
>>>>>>> 39ad1ddb337477e3b9c88cf526591cac2aa11acd
=======
                printf("\n\t Pesanan Anda Tercatat ");
                printf("Tekan enter untuk melanjutkan . . .");
>>>>>>> 39ad1ddb337477e3b9c88cf526591cac2aa11acd
=======
                printf("\n\t Pesanan Anda Tercatat ");
                printf("Tekan enter untuk melanjutkan . . .");
>>>>>>> 39ad1ddb337477e3b9c88cf526591cac2aa11acd
=======
                printf("\n\t Pesanan Anda Tercatat ");
                printf("Tekan enter untuk melanjutkan . . .");
>>>>>>> 39ad1ddb337477e3b9c88cf526591cac2aa11acd

                getche();

                system("cls");
                printf("Anda Memilih\n");
                printf("\n\t Minuman      : Teh          Rp. 3000");
                printf("\n\t Topping      : Dingin       Rp. 1000");
                printf("\n\t Harga Total  : Rp. 4000");
                printf("\n\t Silahkan tekan enter untuk kembali ke Menu makanan ");

                getche();

                daftar_menu();

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

    }else if (pilih == 't' || pilih == 'T'){
        kembali:
        printf("Apakah anda ingin sudahi pesanan? (y/t) ");
        scanf("%s", &pilih);
        if(pilih == 'y' || pilih == 'Y'){
            system("cls");
            printf("Pesanan anda sudah tercatat !");
            printf("\n\t Minuman : Teh Panas");
            printf("\n\t Harga   : RP. 4000");

            printf("\n\t Silahkan tekan enter untuk kembali ke Menu makanan ");

            getche();

            daftar_menu();

        }else if(pilih == 't' || pilih == 'T'){
            system("cls");
            printf("Pesanan anda belum tercatat !");
            printf("\n\t Tekan Enter Untuk Kembali");

            getche();

            daftar_menu();
        }else{
            system("cls");
            printf("Inputan anda salah !");
            printf("\n\t Tekan Enter Untuk Kembali");

            getche();

            goto kembali;
        }
    }
   
}

