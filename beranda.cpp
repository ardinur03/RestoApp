#include <iostream>
#include "pelanggan.h"
#include "app.h"

void welcome(){

    char pilih;

    printf("!=============================================================|\n");
    printf("|                         SELAMAT DATANG                      |\n");
    printf("!=============================================================|\n");
    printf("|                                                             |\n");
    printf("|                      Y. Mulai Memesan                       |\n");
    printf("|   T. Tentang                                  E. Keluar     |\n");
    printf("!=============================================================|\n");
    printf("|                 Copyright 2021 - RestoApp                   |\n");
    printf("!=============================================================|\n");

    printf("\n\t Masukkan pilihan anda : ");
    scanf("%s", &pilih);
    if (pilih == 'y' || pilih == 'Y')
    {
        system("cls");
        // getNama();
    	app();
    }else if (pilih == 't' || pilih == 'T'){
        system("cls");
        printf("\n\t Lorem ipsum dolor sit amet consectetur adipisicing elit. Magnam suscipit corrupti sequi incidunt eaque rerum dolore nam laboriosam eos, error placeat. Similique, sequi.\n");
        
    }else if (pilih == 'e' || pilih == 'E'){
        system("cls");
    }else{
        system("cls");
        printf("\n\t Inputan yang anda masukkan salah !!! ");
        welcome(); // function rekursif
    }


}


void beranda() {
    
    printf("\t\t|====================== RESTO APP ======================|\n");
    printf("\t\t|                                                       |\n");
    printf("\t\t| 1. Lihat Daftar Menu                                  |\n");
    printf("\t\t| 2. Lihat Transaksi                                    |\n");
    printf("\t\t| 3. Tutup Aplikasi                                     |\n");
    printf("\t\t|                                                       |\n");
    printf("\t\t|=======================================================|\n");
    
}
