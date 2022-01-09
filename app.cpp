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
            daftar_menu_makanan();
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

int app(){

    int pil = 0;

	// munculkan menu utama
	system("cls");
	beranda();

	// buat file data_transaksi.dat
	buat_file_transaksi();
	
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
				daftar_menu();
				break;
			}
			case 2:
			{
				system("cls");
				// pilih daftar transaksi
				transaksi();
				// input_transaksi();
				break;
			}
			case 3:
			{
				// exit program
				system("cls");
				exit(0);
				return (0);
			}
			default:
			{
				return (0);
			}
        }
	}

    return 0;
}