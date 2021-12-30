#include <iostream>
#include "beranda.h"
#include "transaksi.h"

int main() {
	
	int pil = 0;
	beranda();

    for (;;){
		printf("\n\t Pilihan : ");
        scanf("%d", &pil);

		switch (pil)
		{
			case 1:
			{
				system("cls");
				beranda();
				printf("case 1\n");
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
