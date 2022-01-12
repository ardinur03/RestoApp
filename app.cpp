#include <iostream>
#include "prototype.h"
#include "loading.h"
void daftar_menu(){
	int pil = 0;
    system("cls");
    printf("\t\t|========================= Daftar Menu ====================|\n");
    printf("\t\t|                                                          |\n");
    printf("\t\t| 1. Makanan                                               |\n");
    printf("\t\t| 2. Minuman                                               |\n");
	printf("\t\t| 3. Transaksi                                             |\n");
    printf("\t\t| 4. Kembali ke Beranda                                    |\n");
    printf("\t\t|                                                          |\n");
    printf("\t\t|==========================================================|\n");
}

int app(){

    int pil = 0;
	// munculkan menu utama
	system("cls");
	beranda();
    for (;;){
		printf("\n\t Pilih Menu : ");
        scanf("%d", &pil);
		// pemilihan menu
		switch (pil)
		{
			case 1:
			{
				system("cls"); // clear screen
				// pilih daftar menu makanan atau minuman
				transaksi_pemesanan();
				break;
			}
			case 2:
			{
				// exit program
				system("cls");
				salam();
				exit(0);
				break;
			}
			default:
			{
				salam();
				return (0);
			}
        }
	}

    return 0;
}