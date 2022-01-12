#include <stdio.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int x,int y){
	COORD coord;
	coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void getLoadingAdmin(){
	system("color A");	
	int r,q;
	gotoxy(35,16);
	printf("Loading to dashboard admin...");
	gotoxy(35,18);
	for(r=1;r<=20;r++){
		for(q=0;q<100000000;q++);
		printf("%c",177);
	}
}

void salam(){
    //deklarasi string x
    char x[]="TERIMAKASIH TELAH MENGGUNAKAN LAYANAN KAMI SALAM HANGAT DARI ADMIN RESTOAPP :)";
    //deklarasi variabel bertipe integer
    int a,b,i,n;
    //menghitung panjang string x
    n=strlen(x);
    
    //perulangan sebanyak panjang string
    for(i=0; i<n; i++){
        /*perulangan untuk menimbulkan jeda waktu
        antar penampilan karakter*/
        for(a=0; a<99999;a++){
            for(b=0; b<500; b++){
            }
        }
        //mencetak string x per karakter
        printf("%c",x[i]);
    }
}