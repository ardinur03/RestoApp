#ifndef admin_resto_h
#define admin_resto_h

void admin_resto();
void crud_makanan();
// data minuman
typedef struct {
    int id_minuman; 
    char nama_minuman[50]; 
    long int harga;
} minumanData;
#endif