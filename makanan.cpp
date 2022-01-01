#include <iostream>
#include <conio.h>
#include "prototype.h"

void topping_makanan();
void topping_ayamgeprek();
void topping_ikan();

void makananMenu(){
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
            printf("Anda memilih : \n");
            printf("\tMakanan : Nasi Goreng\n");
            printf("\tHarga   : Rp. 25000\n\n");
            

            topping_makanan();
            break;
        }
        case 2: // Ayam Geprek
        {
            system("cls");
            printf("Ayam Geprek\n");
            printf("\t Makanan : Ayam Geprek \n");
            printf("\t Harga   : Rp. 15000 \n");

            topping_ayamgeprek();
            break;
        }
        case 3: // Ikan Bakar
        {
            system("cls");
            printf("Ikan Bakar\n");
            printf("\t Makanan : Ikan Bakar \n");
            printf("\t Harga   : Rp. 50000 \n");

            topping_ikan();
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


void topping_makanan(){

    int pilTop; // Variabel Lokal ( Untuk case memilih topping)
    int akhir; // Varibel Lokal ( untuk case pesanan tidak tercatat kembali ke menu)
    char pilih; // Variabel Lokal

    printf("\n\tApakah ingin menggunakan Topping ? (y/t) ");
    scanf("%s", &pilih);

    if (pilih == 'y' || pilih == 'Y')
    {
        system("cls");
        printf("\t\t|====================== Daftar Topping ==============|\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t| Nama Topping                        Harga          |\n");
        printf("\t\t| 1. Pedas                            Rp. 1000       |\n");
        printf("\t\t| 2. Tambah 1/2 porsi                 Rp. 11000      |\n");
        printf("\t\t| 3. Kembali ke Daftar Menu Pembelian                |\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t|====================================================|\n");

        printf("\n\t Topping apa yang ingin anda tambahkan ?  ");
            scanf("%d", &pilTop);
            switch (pilTop)
            {
                case 1:
                {
                    system("cls");
                    printf("Anda memilih : \n");
                    printf("\tMakanan : Nasi Goreng Pedas\n");
                    printf("\tHarga   : Rp. 26000\n\n");
                    break;
                }
                case 2:
                {
                    system("cls");
                    printf("Anda memilih : \n");
                    printf("\tMakanan : Nasi Goreng + 1/2 porsi\n");
                    printf("\tHarga   : Rp. 36000\n\n");
                    break;
                }
                default:
                {
                    system("cls");
                    topping_makanan();
                    break;
                }

            }

    }else
        {
        printf("\tApakah anda ingin sudahi pesanan? (y/t) ");
        scanf("%s", &pilih);
        if(pilih == 'y' || pilih == 'Y'){

            system("cls");
            printf("\tPesanan anda sudah tercatat !\n");
            printf("\tBerikut Pesanan Anda :");
            printf("\n\n\t Makanan : Nasi Goreng");
            printf("\n\t Harga   : RP. 25000");

        }else if(pilih == 't' || pilih == 'T'){

            printf("\n\t Pesanan anda belum tercatat !\n");
            printf("\n\t Silakan tekan 1 untuk kembali\n");
            printf("\n\t Masukan : ");
            scanf(" %d", &akhir);
            if(akhir == 1 )
                system("cls");
                daftar_menu();
        }else{
            printf("Inputan anda salah !");
        }
    }
   
}
void topping_ayamgeprek(){

    int akhir;
    int pilTop;
    char pilih; //var lokal

    printf("\n\tApakah ingin pakai Nasi ? (y/t) ");
    scanf(" %s", &pilih);

    if (pilih == 'y' || pilih == 'Y')
    {
        system("cls");
        printf("\t\t|====================== Daftar Topping ==============|\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t| Nama Topping                        Harga          |\n");
        printf("\t\t| 1. Nasi                            Rp. 5000        |\n");
        printf("\t\t| 2. Kentang                         Rp. 5000       |\n");
        printf("\t\t| 3. Kembali ke Daftar Menu Pembelian                |\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t|====================================================|\n");

            printf("\n\t Makanan apa yang ingin anda beli ?  ");
            scanf("%d", &pilTop);
            switch (pilTop)
            {
                case 1:
                {
                    system("cls");
                    printf("Anda memilih : \n");
                    printf("\tMakanan : Ayam Geprek + Nasi\n");
                    printf("\tHarga   : Rp. 20000 \n\n");
                    break;
                }
                case 2:
                {
                    system("cls");
                    printf("Anda memilih : \n");
                    printf("\tMakanan : Ayam Geprek + Kentang\n");
                    printf("\tHarga   : Rp. 20000\n\n");
                    break;
                }
                default:
                {
                    system("cls");
                    topping_ayamgeprek();
                    break;
                }

            }

        }else
        {
        printf("\tApakah anda ingin sudahi pesanan? (y/t) ");
        scanf("%s", &pilih);
        if(pilih == 'y' || pilih == 'Y'){

            system("cls");
            printf("\tPesanan anda sudah tercatat !\n");
            printf("Tekan enter untuk melanjutkan . . .");
            getche();
            system("cls");
            printf("\tBerikut Pesanan Anda :");
            printf("\n\n\t Makanan : Ayam Geprek");
            printf("\n\t Harga   : RP. 15000");

        }else if(pilih == 't' || pilih == 'T'){

            printf("\n\t Pesanan anda belum tercatat !\n");
            printf("\n\t Silakan tekan 1 untuk kembali\n");
            printf("\n\t Masukan : ");
            scanf(" %d", &akhir);
            if(akhir == 1 )
                system("cls");
                daftar_menu();
                
        }else{
            printf("Inputan anda salah !");
        }
    }
}

void topping_ikan()
{

    int akhir;
    int pilTop;
    char pilih; //var lokal

    printf("\n\t Apakah ingin memilih ikan ? (y/t) ");
    scanf(" %s", &pilih);

    if (pilih == 'y' || pilih == 'Y')
        {
        system("cls");
        printf("\t\t|====================== Jenis Ikan ==================|\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t| Jenis Ikan                            Harga        |\n");
        printf("\t\t| 1. Ikan Mas                           Rp. 50000    |\n");
        printf("\t\t| 2. Ikan Gurame                        Rp. 80000    |\n");
        printf("\t\t| 3. Kembali ke Daftar Menu Pembelian                |\n");
        printf("\t\t|                                                    |\n");
        printf("\t\t|====================================================|\n");

            printf("\n\t Makanan apa yang ingin anda beli ?  ");
            scanf("%d", &pilTop);
            switch (pilTop)
            {
                case 1:
                {
                    system("cls");
                    printf("Anda memilih : \n");
                    printf("\tMakanan : Ikan Mas\n");
                    printf("\tHarga   : Rp. 50000 \n\n");
                    break;
                }
                case 2:
                {
                    system("cls");
                    printf("Anda memilih : \n");
                    printf("\tMakanan : Ikan Gurame\n");
                    printf("\tHarga   : Rp. 20000\n\n");
                    break;
                }
                default:
                {
                    system("cls");
                    topping_ikan();
                    break;
                }

            }

        }
        else
        {
        printf("\tApakah anda ingin sudahi pesanan? (y/t) ");
        scanf("%s", &pilih);
        if(pilih == 'y' || pilih == 'Y'){

            system("cls");
            printf("\tPesanan anda sudah tercatat !\n");
            printf("\tBerikut Pesanan Anda :");
            printf("\n\n\t Makanan : Ikan Mas");
            printf("\n\t Harga   : RP. 50000");

        }else if(pilih == 't' || pilih == 'T'){

            printf("\n\t Pesanan anda belum tercatat !\n");
            printf("\n\t Silakan tekan 1 untuk kembali\n");
            printf("\n\t Masukan : ");
            scanf(" %d", &akhir);
            if(akhir == 1 )
                system("cls");
                daftar_menu();
                
        }else{
            printf("Inputan anda salah !");
        }
    }
}


