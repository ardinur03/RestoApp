#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <cstdlib> 
#include <cstring>
#include <ctime> 
#include <iomanip> 
#include "app.h"
#include "transaksi.h"
#include "minuman.h"
#include "makanan.h"
#include "admin_resto.h"
#include "beranda.h"
#include "time.h"
#include "auth.h"
#include "loading.h"

using namespace std;

// prototype ini di simpan di file yg sama bertujuan karena yang bisa akses hanya file ini saja
void ambil_detail_pemesanan(int index_makanan, char jenis_pesanan);
void beli_makanan_by_index(int param_index_makanan, int param_jumlah_porsi, int param_id_transaksi);
void beli_minuman_by_index(int param_index_minuman, int param_jumlah_porsi, int param_id_transaksi);
void transaksi_terbaru(int param_id_transaksi);
void cetak_struk_transaksi(int param_id_transaksi);

int create_transaksi();
int create_nama_pelanggan();
void cek_diskon(int param_id_transaksi);
int temp_id_transaksi, temp_index_makanan, temp_index_minuman, temp_harga_normal, temp_diskon, temp_harga_total, temp_jumlah_porsi_makanan, temp_jumlah_harga_makanan_perporsi, temp_jumlah_harga_minuman_perporsi, jumlah_porsi_minuman_temp;
char temp_makanan[50], temp_minuman[50], temp_nama_pelanggan[50];

Transaksi dt_transaksi[100];
FILE *f_transaksi;

// buat file transaksi
void buat_file_transaksi(){
    // buat id pelanggan dan masukkan ke file transaksi.dat
    temp_id_transaksi   = create_transaksi();
    temp_nama_pelanggan[50] = create_nama_pelanggan();
    f_transaksi=fopen("data_transaksi.dat","ab+");
	if (!f_transaksi)
    {
        printf("File tidak dapat dibuat!\r\n");
        exit(1);
    }
}

// untuk tampilan pelanggan
void welcome(){
    char pilih;
    welcome_app(); // tampilan awal beranda.cpp
    printf("\n\t Masukkan pilihan anda : ");
    scanf("%s", &pilih);
    if (pilih == 'y' || pilih == 'Y')
    {
        system("cls");
        // buat file data_transaksi.dat
        buat_file_transaksi();
    	app();
    }else if (pilih == 't' || pilih == 'T'){
        system("cls");
        tentang();
    }else if (pilih == 'e' || pilih == 'E'){
        // exit aplikasi
        system("cls");
        salam();
        exit(0);
    }else if(pilih == 'l' || pilih == 'L'){
        system("cls");
        login();
    }
    else{
        system("cls");
        printf("\n\t Inputan yang anda masukkan salah !!! ");
        welcome(); // function rekursif
    }


}

// transaksi pemesanan
void transaksi_pemesanan(){
	int pil = 0;
    int jumlah_porsi_temp;
    // kemudian ketika ingin memesan makanan/minuman update file transaksi.dat berdasarkan id pelanggan sebelumnya
    daftar_menu(); // app.h
    printf("\n\t Mau beli apa ?  ");
    scanf("%d", &pil);
    switch (pil)
    {
        case 1:
        {
            system("cls");
            temp_index_makanan = daftar_menu_makanan(); // ambil no index
            printf("%d", temp_index_makanan);
            // ambil detail makanan
            ambil_detail_pemesanan(temp_index_makanan, 'M');
            printf("\n\n\tBerapa banyak porsi yang akan anda beli ? ");
            printf("\n\t Masukkan jumlah : ");
            scanf("%d", &jumlah_porsi_temp);
            beli_makanan_by_index(temp_index_makanan, jumlah_porsi_temp, temp_id_transaksi); //cari makanan dan harga nya dan simpan ke dalam file transaksi berdasarkan temp_id_transaksi sebelumnya
            break;
        }
        case 2:
        {
            system("cls");
            temp_index_minuman = daftar_menu_minuman(); // ambil no index
            // ambil detail minuman
            ambil_detail_pemesanan(temp_index_minuman, 'N');
            printf("\n\n\tBerapa banyak porsi yang akan anda beli ? ");
            printf("\n\t Masukkan jumlah : ");
            scanf("%d", &jumlah_porsi_minuman_temp);
            beli_minuman_by_index(temp_index_minuman, jumlah_porsi_minuman_temp, temp_id_transaksi); //cari makanan dan harga nya dan simpan ke dalam file transaksi berdasarkan temp_id_transaksi sebelumnya
            break;
        }
        case 3:
        {
            system("cls");
            transaksi_terbaru(temp_id_transaksi); 
            
    
            break;
        }
        case 4:
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

// MAKANAN
void beli_makanan_by_index(int param_index_makanan, int param_jumlah_porsi, int param_id_transaksi){
    Transaksi dt_transaksi2;
    // ambil detail makanan berdasarkan index
    param_index_makanan -= 1;
    makananData dt_makanan[100];    
    FILE *f_makanan;
    int id_makanan, pilih, i =0;
    f_makanan = fopen("data_makanan.dat", "rb+");
     while (fread(&dt_makanan[i], sizeof(dt_makanan[i]), 1, f_makanan))
    {
        i++;
    }
    printf("\n\t Id Transaksi : %d", param_id_transaksi);
    printf("\n\t Nama Makanan : %s", dt_makanan[param_index_makanan].nama_makanan);
    printf("\n\t Harga        : %d", dt_makanan[param_index_makanan].harga_makanan);
    printf("\n\t Jumlah Porsi : %d", param_jumlah_porsi);
    printf("\n\t Harga Total  : %d", param_jumlah_porsi * dt_makanan[param_index_makanan].harga_makanan);
    

    // simpan ke file transaksi.dat
    f_transaksi = fopen("data_transaksi.dat", "rb+");
    if (!f_transaksi)
    {
        printf("\n\t Gagal membuat file transaksi.dat");
        exit(1);
    }
    while(fread(&dt_transaksi2, sizeof(dt_transaksi2), 1, f_transaksi))
    {
        if(dt_transaksi2.id_transaksi == param_id_transaksi)
        {
            strcpy(dt_transaksi2.nama_pelanggan, temp_nama_pelanggan);
            strcpy(dt_transaksi2.makanan, dt_makanan[param_index_makanan].nama_makanan);
            dt_transaksi2.porsi_makanan = param_jumlah_porsi;
            dt_transaksi2.harga_makanan = param_jumlah_porsi * dt_makanan[param_index_makanan].harga_makanan;
            // strcpy(dt_transaksi2.minuman, "");
            // dt_transaksi2.porsi_minuman = 0;
            // dt_transaksi2.harga_minuman = 0;
            fseek(f_transaksi, -sizeof(dt_transaksi2), SEEK_CUR);
            fwrite(&dt_transaksi2, sizeof(dt_transaksi2), 1, f_transaksi);
            break;
        }
    }
    fclose(f_transaksi);
    // refresh variabel array
    i = 0;
    printf("\n\t Pesanan Anda berhasil disimpan");
    printf("\n\t Tekan enter untuk melanjutkan ...");
    getche();
    transaksi_pemesanan();
}

// function return makanan yang dipilih nama_makanan dan harga_makanan
void ambil_detail_pemesanan(int index_makanan, char jenis_pesanan){
    if(jenis_pesanan == 'M'){ // jika makanan
        system("cls");
        printf("\n\t Anda sudah memilih makanan, tekan enter untuk melanjutkan ...");
        getche();
        system("cls");
        printf("\n\t Makanan yang anda pilih adalah : \n");
        index_makanan -= 1;
        makananData dt_makanan[100];    
        FILE *f_makanan;
        int id_makanan, pilih, i =0;

        f_makanan = fopen("data_makanan.dat", "rb+");
    
        if (!f_makanan)
        {
            printf("\n\t Gagal membuat file makanan.dat");
            exit(1);
        }

        // file data_makanan.dat to array
        while (fread(&dt_makanan[i], sizeof(dt_makanan[i]), 1, f_makanan))
        {
            i++;
        }
        printf("\t Nama Makanan : %s", dt_makanan[index_makanan].nama_makanan);
        printf("\n\t Harga        : %d", dt_makanan[index_makanan].harga_makanan);
    } else if(jenis_pesanan == 'N'){ // jika minuman
        system("cls");
        printf("\n\t Anda sudah memilih minuman, tekan enter untuk melanjutkan ...");
        getche();
        system("cls");
        printf("\n\t Minuman yang anda pilih adalah : ");
        index_makanan -= 1;
        minumanData dt_minuman[100];    
        FILE *f_minuman;
        int id_minuman, pilih, i =0;

        f_minuman = fopen("data_minuman.dat", "rb+");
    
        if (!f_minuman)
        {
            printf("\n\t Gagal membuat file minuman.dat");
            exit(1);
        }

        // file data_minuman.dat to array
        while (fread(&dt_minuman[i], sizeof(dt_minuman[i]), 1, f_minuman))
        {
            i++;
        }
        printf("\n\t Nama Minuman : %s", dt_minuman[index_makanan].nama_minuman);
        printf("\n\t Harga        : %d", dt_minuman[index_makanan].harga_minuman);
    }
}

// input id_transaksi
int create_transaksi(){
    int i = 0;

    f_transaksi = fopen("data_transaksi.dat", "ab+");
    if(!f_transaksi) {
        printf("\n\t Gagal membuat file transaksi.dat");
        exit(1);
    } else{
        // cek isi file data_transaksi.dat apakah ada ada jika ada data maka lanjutkan index elementnya
        if(fread(&dt_transaksi, sizeof(Transaksi), 1, f_transaksi)==1){
            while(fread(&dt_transaksi, sizeof(Transaksi), 1, f_transaksi)){
                i++;
            }
        }
        //  generate random number 3 digit
        srand((unsigned)time(0));
        int random_number =  (rand() % 999) + 1;
        dt_transaksi[i].id_transaksi = random_number;

        // input string kosong ke nama makanan
        strcpy(dt_transaksi[i].nama_pelanggan, "");
        strcpy(dt_transaksi[i].makanan, "");
        dt_transaksi[i].porsi_makanan = 0;
        dt_transaksi[i].harga_makanan = 0;
        strcpy(dt_transaksi[i].minuman, "");
        dt_transaksi[i].porsi_minuman = 0;
        dt_transaksi[i].harga_minuman = 0;

        fwrite(&dt_transaksi[i], sizeof(Transaksi), 1, f_transaksi);
        fclose(f_transaksi);

        // refresh variabel array
        i = 0;

    return random_number;
    }
   
}

// create nama pelanggan
int create_nama_pelanggan(){
    int i = 0;
    // input nama pelanggan
    isi_nama:
    printf("\n\t Masukkan nama anda : ");
    fflush(stdin);
    scanf("%s", &temp_nama_pelanggan);

    f_transaksi = fopen("data_transaksi.dat", "rt");
    while (fread(&dt_transaksi[i], sizeof(dt_transaksi), 1, f_transaksi)){
        if(temp_nama_pelanggan == dt_transaksi[i].nama_pelanggan){
            printf("\n\t Nama pelanggan sudah ada, silahkan masukkan nama lain");
            getche();
            goto isi_nama;
        }
        i++;
    }
    return temp_nama_pelanggan[50];
}

// MINUMAN
void beli_minuman_by_index(int param_index_minuman, int param_jumlah_porsi_minuman, int param_id_transaksi){
    Transaksi dt_transaksi2;
    
    param_index_minuman -= 1;
    minumanData dt_minuman[100];
    FILE *f_minuman;
    int id_minuman, pilih, i =0;
    f_minuman = fopen("data_minuman.dat", "rb+");
    if (!f_minuman)
    {
        printf("\n\t Gagal membuat file minuman.dat");
        exit(1);
    }
    while (fread(&dt_minuman[i], sizeof(dt_minuman[i]), 1, f_minuman))
    {
        i++;
    }
    printf("\n\t Id Transaksi  : %d", param_id_transaksi);
    printf("\n\t Nama Minuman  : %s", dt_minuman[param_index_minuman].nama_minuman);
    printf("\n\t Harga Minuman : %d", dt_minuman[param_index_minuman].harga_minuman);
    printf("\n\t Jumlah Porsi  : %d", param_jumlah_porsi_minuman);
    printf("\n\t Harga Total   : %d", dt_minuman[param_index_minuman].harga_minuman * param_jumlah_porsi_minuman);

    // simpan ke file data_transaksi.dat
    f_transaksi = fopen("data_transaksi.dat", "rb+");
    if (!f_transaksi)
    {
        printf("\n\t Gagal membuat file transaksi.dat");
        exit(1);
    }
    while (fread(&dt_transaksi2, sizeof(dt_transaksi2), 1, f_transaksi))
    {
        if(param_id_transaksi == dt_transaksi2.id_transaksi){
            strcpy(dt_transaksi2.minuman, dt_minuman[param_index_minuman].nama_minuman);
            dt_transaksi2.porsi_minuman = param_jumlah_porsi_minuman;
            dt_transaksi2.harga_minuman = dt_minuman[param_index_minuman].harga_minuman * param_jumlah_porsi_minuman;
            fseek(f_transaksi, -sizeof(dt_transaksi2), JUM_BLOK);
            fwrite(&dt_transaksi2, sizeof(dt_transaksi2), 1, f_transaksi);
            break;
        }
    }
    fclose(f_transaksi);

    // refresh variabel array
    i = 0;
    printf("\n\t Pesanan Anda berhasil disimpan");
    printf("\n\t Tekan enter untuk melanjutkan ...");
    getche();
    transaksi_pemesanan();
}


// munculin data transaksi untuk user yang baru saja mencatat transaksi makanan atau minuman
void transaksi_terbaru(int param_id_transaksi){
    // lihat daftar transaksi di dalam file data_transaksi.dat
    system("cls");
    int i = 0;
    int pilihan;
    f_transaksi = fopen("data_transaksi.dat", "rb+");
    if (!f_transaksi)
    {
        printf("\n\t Gagal membuat file transaksi.dat");
        exit(1);
    }
    while (fread(&dt_transaksi[i], sizeof(dt_transaksi[i]), 1, f_transaksi))
    {
        i++;
    }
    printf("\n\t Daftar Transaksi Anda pada  : \n");
    printf("\n\t|-------------------------------------------------------------------------------------------------------------------------|");
    printf("\n\t| ID Transaksi |   Nama Pelanggan   |   Makanan   | Porsi |   Harga Makanan   |   Minuman   |   Qty   |   Harga Minuman   |");
    printf("\n\t|-------------------------------------------------------------------------------------------------------------------------|");
    for (int j = 0; j < i; j++)
    {
        if(param_id_transaksi == dt_transaksi[j].id_transaksi){
            printf("\n\t| %-12d | %-18s | %-11s | %-5d | %-17d | %-11s | %-7d | %-17d |", dt_transaksi[j].id_transaksi, dt_transaksi[j].nama_pelanggan, dt_transaksi[j].makanan, dt_transaksi[j].porsi_makanan, dt_transaksi[j].harga_makanan, dt_transaksi[j].minuman, dt_transaksi[j].porsi_minuman, dt_transaksi[j].harga_minuman);
        }
    }
    printf("\n\t|-------------------------------------------------------------------------------------------------------------------------|");
    printf("\n\n\t Apakah anda ingin mencetak Struk Transaksi ?  ");
    printf("\n\t 1. Ya : ");
    printf("\n\t 2. Tidak : ");
    scanf("%d", &pilihan);
    switch (pilihan)
    {
    case 1:
        {
            cetak_struk_transaksi(param_id_transaksi);
            printf("\n\t Tekan enter untuk kembali ...");
            getche();
            system("cls");
            transaksi_pemesanan();
            break;
        }
    case 2:
        {
            transaksi_pemesanan();
            break;
        }
    default:
        printf("\n\t Pilihan tidak ada");
        printf("\n\t Tekan enter untuk melanjutkan ...");
        getche();
        transaksi_pemesanan();
        break;
    }
    
}

//cetak_struk_transaksi
void cetak_struk_transaksi(int param_id_transaksi_struk){
    system("cls");
    // lihat daftar transaksi di dalam file data_transaksi.dat
    int i = 0, cek_transaksi;
    f_transaksi = fopen("data_transaksi.dat", "rb+");
    if (!f_transaksi)
    {
        printf("\n\t Gagal membuat file transaksi.dat");
        exit(1);
    }
    cek_transaksi = 0;
    while (fread(&dt_transaksi[i], sizeof(dt_transaksi[i]), 1, f_transaksi))
    {
        if(dt_transaksi[i].id_transaksi == param_id_transaksi_struk){
            cek_transaksi = 1;
            int temp_total_harga_transaksi;
            char a[2] = "|";
            printf("\n\t Struk Transaksi Anda : \n");
            getTime();
            printf("\n\t\t|--------------------------------------------------------------------------|\n");
            printf("\t\t|                               >>RESTOAPP<<     %27s\n", a);
            printf("\t\t|--------------------------------------------------------------------------|\n");
            printf("\t\t|                                                %27s\n", a);
            printf("\t\t| Nama Pelanggan    : %s                         %27s\n", dt_transaksi[i].nama_pelanggan, a);
            printf("\t\t| Makanan           : %s             Porsi : %d  %27s\n", dt_transaksi[i].makanan, dt_transaksi[i].porsi_makanan, a);
            printf("\t\t| Minuman           : %s             Porsi : %d  %27s\n", dt_transaksi[i].minuman, dt_transaksi[i].porsi_minuman, a);
            printf("\t\t|                                                %27s\n", a);
            printf("\t\t|                                                %27s\n", a);
            printf("\t\t|                                                %27s\n", a);
            printf("\t\t|==========================================================================|\n");
            printf("\t\t|--------------------------------------------------------------------------|\n");
            temp_total_harga_transaksi = dt_transaksi[i].harga_makanan + dt_transaksi[i].harga_minuman;
            cek_diskon(temp_total_harga_transaksi);
            printf("\t\t|--------------------------------------------------------------------------|\n");
            printf("\t\t|                    TERIMA KASIH ATAS KUNJUNGAN ANDA                      |\n");
            printf("\t\t|--------------------------------------------------------------------------|\n");
            printf("\t\t|                       COPYRIGHT 2021 | RestoApp                          |\n");
            printf("\t\t|--------------------------------------------------------------------------|\n");

            break;
        }
        i++;
    }
    if(cek_transaksi == 0){
        printf("\n\tData makanan tidak ditemukan !");
    }

}

// cek diskon
void cek_diskon(int param_harga_total){
    char a[2] = "|";
    if(param_harga_total >= 100000){
        // diskon 10%
        printf("\t\t| Total Harga normal           : Rp. %d            %27s\n", param_harga_total, a);
        printf("\t\t|   Anda mendapatkan Diskon sebesar 10 persen    %27s\n", a);
        param_harga_total = param_harga_total - (param_harga_total * 0.1);
        printf("\t\t|   Total Harga setelah Diskon : %d              %27s\n", param_harga_total, a);
        printf("\t\t|                                                %27s\n", a);
    } else {
        printf("\t\t|   Total Harga                : %d              %27s\n", param_harga_total, a);
    }
}

// lihat semua daftar transaksi
void lihat_daftar_transaksi(){
    // lihat daftar transaksi di dalam file data_transaksi.dat
    system("cls");
    int i = 0;
    f_transaksi = fopen("data_transaksi.dat", "rb+");
    if (!f_transaksi)
    {
        printf("\n\t Gagal membuat file transaksi.dat");
        exit(1);
    }
    while (fread(&dt_transaksi[i], sizeof(dt_transaksi[i]), 1, f_transaksi))
    {
        i++;
    }
    printf("\n\t Daftar Transaksi : \n");
    printf("\n\t|-------------------------------------------------------------------------------------------------------------------------|");
    printf("\n\t| ID Transaksi |   Nama Pelanggan   |   Makanan   | Porsi |   Harga Makanan   |   Minuman   |   Qty   |   Harga Minuman   |");
    printf("\n\t|-------------------------------------------------------------------------------------------------------------------------|");
    for (int j = 0; j < i; j++)
    {
        printf("\n\t| %-12d | %-18s | %-11s | %-5d | %-17d | %-11s | %-7d | %-17d |", dt_transaksi[j].id_transaksi, dt_transaksi[j].nama_pelanggan, dt_transaksi[j].makanan, dt_transaksi[j].porsi_makanan, dt_transaksi[j].harga_makanan, dt_transaksi[j].minuman, dt_transaksi[j].porsi_minuman, dt_transaksi[j].harga_minuman);
    }
    printf("\n\t|-------------------------------------------------------------------------------------------------------------------------|");
    
}

// hapus data teransaksi berdasarkan index element
void hapus_data_transaksi(){
    // hapus data transaksi berdasarkan id transaksi
    int i = 0;
    f_transaksi = fopen("data_transaksi.dat", "rb+");
    if (!f_transaksi)
    {
        printf("\n\t Gagal membuat file transaksi.dat");
        exit(1);
    }
    while (fread(&dt_transaksi[i], sizeof(dt_transaksi[i]), 1, f_transaksi))
    {
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        dt_transaksi[j].id_transaksi = 0;
        strcpy(dt_transaksi[j].nama_pelanggan, "");
        strcpy(dt_transaksi[j].makanan, "");
        strcpy(dt_transaksi[j].minuman, "");
        dt_transaksi[j].porsi_makanan = 0;
        dt_transaksi[j].porsi_minuman = 0;
        dt_transaksi[j].harga_makanan = 0;
        dt_transaksi[j].harga_minuman = 0;
        break;
    }
    fclose(f_transaksi);
    f_transaksi = fopen("data_transaksi.dat", "wb+");
    if (!f_transaksi)
    {
        printf("\n\t Gagal membuat file transaksi.dat");
        exit(1);
    }
    for (int j = 0; j < i; j++)
    {
        fwrite(&dt_transaksi[j], sizeof(dt_transaksi[j]), 1, f_transaksi);
    }

    printf("\n\t Data transaksi berhasil dihapus !");
    printf("\n\t Tekan enter untuk kembali ...");
    getche();
    system("cls");
    admin_resto();
}

// lihat daftar transaksi yang muncul hanya nama pelanggan
void lihat_daftar_transaksi_pelanggan(){
    // lihat daftar transaksi di dalam file data_transaksi.dat
    system("cls");
    int i = 0;
    f_transaksi = fopen("data_transaksi.dat", "rb+");
    if (!f_transaksi)
    {
        printf("\n\t Gagal membuat file transaksi.dat");
        exit(1);
    }
    while (fread(&dt_transaksi[i], sizeof(dt_transaksi[i]), 1, f_transaksi))
    {
        i++;
    }
    printf("\n\t Daftar Transaksi : \n");
    printf("\n\t|-----------------------------------|");
    printf("\n\t| ID Transaksi |   Nama Pelanggan   |");
    printf("\n\t|-----------------------------------|");
    for (int j = 0; j < i; j++)
    {
        printf("\n\t| %-12d | %-18s |", dt_transaksi[j].id_transaksi, dt_transaksi[j].nama_pelanggan);
    }
    printf("\n\t|-----------------------------------|");
    
    printf("\n\t Hapus Transaksi pelanggan ? (Y/T) ...");
    char pilih;
    pilih = getche();
    if(pilih == 'Y' || pilih == 'y'){
        // printf("\n\t Masukkan ID transaksi yang ingin dihapus : ");
        // int id_transaksi;
        // scanf("%d", &id_transaksi);
        hapus_data_transaksi();
    } else {
        printf("\n\t Tekan enter untuk kembali ...");
        getche();
        system("cls");
        admin_resto();
    }


    printf("\n\t Tekan enter untuk kembali ...");
    getche();
    system("cls");
    admin_resto();
}

void lihat_transaksi_satu_pelanggan(int param_id_transaksi){
    int i = 0;
    int pilihan;
    f_transaksi = fopen("data_transaksi.dat", "rb+");
    if (!f_transaksi)
    {
        printf("\n\t Gagal membuat file transaksi.dat");
        exit(1);
    }
    while (fread(&dt_transaksi[i], sizeof(dt_transaksi[i]), 1, f_transaksi))
    {
        i++;
    }
    printf("\n\t Daftar Transaksi Anda pada  : \n");
    printf("\n\t|-------------------------------------------------------------------------------------------------------------------------|");
    printf("\n\t| ID Transaksi |   Nama Pelanggan   |   Makanan   | Porsi |   Harga Makanan   |   Minuman   |   Qty   |   Harga Minuman   |");
    printf("\n\t|-------------------------------------------------------------------------------------------------------------------------|");
    for (int j = 0; j < i; j++)
    {
        if(param_id_transaksi == dt_transaksi[j].id_transaksi){
            printf("\n\t| %-12d | %-18s | %-11s | %-5d | %-17d | %-11s | %-7d | %-17d |", dt_transaksi[j].id_transaksi, dt_transaksi[j].nama_pelanggan, dt_transaksi[j].makanan, dt_transaksi[j].porsi_makanan, dt_transaksi[j].harga_makanan, dt_transaksi[j].minuman, dt_transaksi[j].porsi_minuman, dt_transaksi[j].harga_minuman);
        }
    }
    printf("\n\t|-------------------------------------------------------------------------------------------------------------------------|");

    printf("\n\n\t Apakah anda ingin mencetak Struk Transaksi ?  ");
    printf("\n\t 1. Ya : ");
    printf("\n\t 2. Tidak : ");
    scanf("%d", &pilihan);
    switch (pilihan)
    {
    case 1:
        {
            cetak_struk_transaksi(param_id_transaksi);
            printf("\n\t Tekan enter untuk kembali ...");
            getche();
            system("cls");
            admin_resto();
            break;
        }
    case 2:
        {
            admin_resto();
            break;
        }
    default:
        printf("\n\t Pilihan tidak ada");
        printf("\n\t Tekan enter untuk melanjutkan ...");
        getche();
        admin_resto();
        break;
    }

}
//  lihat transaksi 1 pelanggan di dalam file data_transaksi.dat
void lihat_transaksi_satu_pelanggan_void(){
    system("cls");

    printf("\n Masukkan ID Pelanggan yang ingin di cari : ");
    int id_pelanggan;
    scanf("%d", &id_pelanggan);

    lihat_transaksi_satu_pelanggan(id_pelanggan);

    printf("\n\t Tekan enter untuk kembali ...");
    getche();
    system("cls");
    admin_resto();
}