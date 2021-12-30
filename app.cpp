#include <iostream>
#include "beranda.h"
#include "transaksi.h"
#include "daftar_menu.h"

int app(){

    int pil = 0;

	// munculkan menu utama
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
				daftar_menu();
				break;
			}
			case 2:
			{
				system("cls");
				transaksi();
				break;
			}
			case 3:
			{
				break;
			}
			default:
			{
				return (0);
			}
        }
	}

    return 0;
}