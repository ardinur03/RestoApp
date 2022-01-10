#include <iostream>
#include "app.h"
#include "transaksi.h"
#include <conio.h>
#include "admin_resto.h"
#include "time.h"

void welcome_app(){
    system("cls");
    printf("!=============================================================|\n");
    printf("|                       >>SELAMAT DATANG<<                    |\n");
    printf("!=============================================================|\n");
    printf("|                                                             |\n");
    printf("|                                                             |\n");
    printf("|                                                             |\n");
    printf("|                       Y. Mulai Memesan                      |\n");
    printf("|                                                             |\n");
    printf("|                                                             |\n");
    printf("|                                                             |\n");
    printf("|   T. Tentang              L. Login               E. Keluar  |\n");
    printf("|                                                             |\n");
    printf("!=============================================================|\n");
    printf("|                 Copyright 2021 - RestoApp                   |\n");
    printf("!=============================================================|\n");
}

// untuk tampilan pelanggan
void beranda() {
    system("cls");
    getTime();
    printf("\t\t|=============================================================|\n");
    printf("\t\t|                      >>Beranda RestoApp<<                   |\n");
    printf("\t\t|=============================================================|\n");
    printf("\t\t|                                                             |\n");
    printf("\t\t|       1. Lihat Daftar Menu                                  |\n");
    printf("\t\t|       2. Tutup Aplikasi                                     |\n");
    printf("\t\t|                                                             |\n");
    printf("\t\t|                                                             |\n");
    printf("\t\t|                                                             |\n");
    printf("\t\t|                                                             |\n");
    printf("\t\t|                                                             |\n");
    printf("\t\t|=============================================================|\n");
    printf("\t\t|                  COPYRIGHT 2021 | RestoApp                  |\n");
    printf("\t\t|=============================================================|\n");
}

void tentang(){
    char pilih;
    system("cls");
    printf("\t\t|=============================================================|\n");
    printf("\t\t|                         >>RestoApp<<                        |\n");
    printf("\t\t|=============================================================|\n");
    printf("\t\t|                                                             |\n");
    printf("\t\t|  RestoApp adalah aplikasi pencatat transaksi restoran.      |\n");
    printf("\t\t|Dengan alur yang  sederhana dan mudah digunakan. Applikasi   |\n");
    printf("\t\t|RestoApp ini terdapat dua user, yaitu Adim dan Pengguna      |\n");
    printf("\t\t|                                                             |\n");
    printf("\t\t|                                                             |\n");
    printf("\t\t|                                                             |\n");
    printf("\t\t|                                                             |\n");
    printf("\t\t|                                                             |\n");
    printf("\t\t|=============================================================|\n");
    printf("\t\t|                  COPYRIGHT 2021 | RestoApp                  |\n");
    printf("\t\t|=============================================================|\n");
    printf("\n\t klik enter untuk kembali... ");
    getche();
    welcome();
}

// untuk tampilan admin
void beranda_admin(){
    system("cls");
    printf("\t\t|=============================================================|\n");
    printf("\t\t|                      >>RestoApp Admin<<                     |\n");
    printf("\t\t|=============================================================|\n");
    printf("\t\t|                                                             |\n");
    printf("\t\t| 1. CRUD Makanan                                             |\n");
    printf("\t\t| 2. CRUD Minuman                                             |\n");
    printf("\t\t| 3. Lihat Transaksi                                          |\n");
    printf("\t\t| 4. Lihat Pelanggan                                          |\n");
    printf("\t\t| 5. Lihat Transaksi Pelanggan                                |\n");
    printf("\t\t| 6. Tutup Aplikasi                                           |\n");
    printf("\t\t|                                                             |\n");
    printf("\t\t|                                                             |\n");
    printf("\t\t|=============================================================|\n");
    printf("\t\t|                  COPYRIGHT 2021 | RestoApp                  |\n");
    printf("\t\t|=============================================================|\n");
}









