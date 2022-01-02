#include <iostream>
#include <conio.h>
#include "pelanggan.h"
#include "beranda.h"

FILE *f_pelanggan;
pelanggan dt_pelanggan;
int i = 1;
int val_cek_id;

int cekIdPelanggan(pelanggan dt_pelanggan, int id);
void getNama() {
    // input id pelanggan   
    input_id:
    system("cls");
    printf("Masukkan ID  (1 angka) : ");
    fflush(stdin);
    scanf("%d", &dt_pelanggan.id_pelanggan);

    // cek inputan id tidak melebihi 2 digit
    if (dt_pelanggan.id_pelanggan > 99) {
        printf("VALIDATE WARNING : ID tidak boleh lebih dari 1 digit !\n");
        // input ulang id pelanggan
        printf("\n klik enter untuk kembali ...");
        getch();
        goto input_id;
    }

    // cek id apakah ada atau tidak
    val_cek_id = cekIdPelanggan(dt_pelanggan, dt_pelanggan.id_pelanggan);
    if (val_cek_id != 0) {
        printf("VALIDATE WARNING : Id pelanggan sudah ada !\n");
        printf("\n\t klik enter untuk kembali ...");
        getch();
        goto input_id;
    }
    
    // input nama
    printf("\n\tMasukkan nama anda : ");
    fflush(stdin);
    gets(dt_pelanggan.nama);

    // save to file pelanggan.txt
    f_pelanggan = fopen("pelanggan.dat", "ab+");
    if(!f_pelanggan) {
        printf("\n\t Gagal membuat file pelanggan.dat");
        exit(1);
    }
    fwrite(&dt_pelanggan, sizeof(dt_pelanggan), 1, f_pelanggan);
    fclose(f_pelanggan);
}

void readPelanggan(){
    // read file pelanggan.dat
    f_pelanggan = fopen("pelanggan.dat", "rb");
    if(!f_pelanggan) {
        printf("\n\t Gagal membuka file pelanggan.dat");
        exit(1);
    }

    printf("|========================================================================|\n");
    printf("|                          DATA PELANGGAN                                |\n");
    printf("|========================================================================|\n");
    printf("| NO |   ID PELANGGAN   |                NAMA PELANGGAN                  |\n");
    printf("|------------------------------------------------------------------------|\n");
    while(fread(&dt_pelanggan, sizeof(dt_pelanggan), JUM_BLOK, f_pelanggan) == JUM_BLOK) {
    printf("  %-2d          %-2d            %-2s\n", i++, dt_pelanggan.id_pelanggan, dt_pelanggan.nama);
    }
    fclose(f_pelanggan);

    printf("\n\t klik enter untuk kembali ...");
    getch();
    system("cls");
    welcome();
}

// cek id pelanggan
int cekIdPelanggan(pelanggan dt_pelanggan, int id) {
	f_pelanggan = fopen("pelanggan.dat", "rt"); // buka file pelanggan.dat menggunakan "rt"
    
    while(fread(&dt_pelanggan, sizeof(dt_pelanggan), 1, f_pelanggan)) {
        if(id == dt_pelanggan.id_pelanggan) {
            fclose(f_pelanggan);
            return 1;
        }
    }
}
