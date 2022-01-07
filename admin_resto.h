#ifndef admin_resto_h
#define admin_resto_h

// data makanan
typedef struct {
    int id_makanan; 
    char nama_makanan[50]; 
    long int harga;
} makananData;  

// data minuman
typedef struct {
    int id_minuman; 
    char nama_minuman[50]; 
    long int harga;
} minumanData;
#endif