#include <iostream>
#include "beranda.h"

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
				printf("case 2\n");
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
