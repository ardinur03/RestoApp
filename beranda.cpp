#include <iostream>
#include "pelanggan.h"
#include "app.h"
#include "transaksi.h"
#include <conio.h>

void tentang();

// untuk tampilan pelanggan
void welcome(){
    char pilih;
    system("cls");
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
        getNama();
    	app();
    }else if (pilih == 't' || pilih == 'T'){
        system("cls");
        tentang();
    }else if (pilih == 'e' || pilih == 'E'){
        // exit aplikasi
        system("cls");
        exit(0);
    }else{
        system("cls");
        printf("\n\t Inputan yang anda masukkan salah !!! ");
        welcome(); // function rekursif
    }


}

// untuk tampilan pelanggan
void beranda() {
    system("cls");
    printf("\t\t|====================== RESTO APP ======================|\n");
    printf("\t\t|                                                       |\n");
    printf("\t\t| 1. Lihat Daftar Menu                                  |\n");
    printf("\t\t| 2. Lihat Transaksi                                    |\n");
    printf("\t\t| 3. Tutup Aplikasi                                     |\n");
    printf("\t\t|                                                       |\n");
    printf("\t\t|=======================================================|\n");
    
}

void tentang(){
    char pilih;
    system("cls");
    printf("\t\t|====================== RESTO APP ======================|\n");
    printf("\t\t|                                                       |\n");
    printf("\t\t| RestoApp adalah aplikasi pencatat transaksi restoran. |\n");
    printf("\t\t| Dengan alur yang  sederhana dan mudah digunakan.      |\n");
    printf("\t\t|                                                       |\n");
    printf("\t\t|=======================================================|\n");
    printf("\t\t|               COPYRIGHT 2021 | RestoApp               |\n");
    printf("\t\t|=======================================================|\n");
    printf("\n\t klik enter untuk kembali... ");
    getche();

    welcome();
}

// untuk tampilan admin
void beranda_admin(){
    system("cls");
    printf("\t\t|====================== RESTO APP ADMIN ======================|\n");
    printf("\t\t|                                                             |\n");
    printf("\t\t| 1. CRUD Pemesanan                                           |\n");
    printf("\t\t| 2. Lihat Transaksi                                          |\n");
    printf("\t\t| 3. Lihat Pelanggan                                          |\n");
    printf("\t\t| 4. Lihat Transaksi Pelanggan                                |\n");
    printf("\t\t|                                                             |\n");
    printf("\t\t|=============================================================|\n");
}









