#include <iostream>
#include "prototype.h"
#include <conio.h>
#include <string>

using namespace std;

void toppingTeh();

string nama_minuman;
int harga_minuman;

void minumanMenu(){

    char airmineral;
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
            printf("Anda Memilih :\n");
            printf("\n\t Minuman : Teh");
            printf("\n\t Harga   : Rp. 3000 \n");

            toppingTeh();
            break;
        }
        case 2:
        {
            nama_minuman = "Air Mineral";
            harga_minuman = 3000;
            kembali:
            system("cls");
            printf("Anda Memilih :\n");
            printf("\n\t Minuman : Air Mineral ");
            printf("\n\t Harga   : Rp. 3000");
            printf("\n\n\t Apakah ingin sudahi pesanan ? (y/t) ");
            scanf("%s", &airmineral);

            if(airmineral == 'y'|| airmineral == 'Y'){
                printf("\n\t Pesanan Anda Sudah Tercatat");
                printf("\n\t Tekan enter untuk melanjutkan . . .");
                getche();
                system("cls");
                printf("Anda Memilih\n");
                printf("\n\t Minuman      : Air Mineral        Rp. 3000");
                printf("\n\t Topping      : -                  Rp. 0");
                printf("\n\t Harga Total  : Rp. 3000");
                printf("\n\t Silahkan tekan enter untuk kembali ke Beranda ");
                getche();
                beranda();
                }
                else if(airmineral == 't' ||airmineral == 'T'){
                    system("cls");
                    printf("\n\n\tTekan enter untuk Kembali Memesan . . .");
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
                nama_minuman = "Teh Manis Panas";
                harga_minuman = 3000 + 2000;
                system("cls");
                printf("\n\t Pesanan Anda Tercatat ");
                printf("\n\t Tekan enter untuk melanjutkan . . .");
                getche();
                system("cls");
                printf("Anda Memilih\n");
                printf("\n\t Minuman      : Teh              Rp. 3000");
                printf("\n\t Topping      : Manis Panas      Rp. 2000");
                printf("\n\t Harga Total  : Rp. 5000 \n");
                printf("\n\t Silahkan tekan enter untuk kembali ke Menu makanan ");
                getche();

                // save ke transaksi
                // transaksi(nama, nama_makanan, minuman);
                daftar_menu();
                break;
            }
            case 2:
            {
                nama_minuman = "Teh Dingin";
                harga_minuman = 3000 + 1000;
                system("cls");
                printf("\n\t Pesanan Anda Tercatat ");
                printf("Tekan enter untuk melanjutkan . . .");
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
        nama_minuman = "Teh Tawar";
        harga_minuman = 3000;
        kembali:
        printf("Apakah anda ingin sudahi pesanan? (y/t) ");
        scanf("%s", &pilih);
        if(pilih == 'y' || pilih == 'Y'){
            system("cls");
            printf("Pesanan anda sudah tercatat !");
            printf("\n\t Minuman : Teh Tawar");
            printf("\n\t Harga   : RP. 3000");
            printf("\n\t Silahkan tekan enter untuk kembali ke Beranda ");
            getche();
            beranda();
        }else if(pilih == 't' || pilih == 'T'){
            system("cls");
            printf("Pesanan anda sudah tercatat !");
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




// tambah minuman
// hapus minuman
// lihat daftar minuman