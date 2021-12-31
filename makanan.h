#ifndef makanan_h
#define makanan_h

void makananMenu();

typedef struct {
    int id_makanan; 
    char nama_makanan[20]; 
    long int price;
} makananData;  

#endif

