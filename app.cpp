#include <iostream>
#include "prototype.h"

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
				// transaksi();
				input_transaksi();
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