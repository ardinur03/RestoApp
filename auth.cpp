#include <iostream>
#include <string>
#include <conio.h>
#include "admin_resto.h"
#include "loading.h"
using namespace std;

string data_login[2][3] = {{"admin", "123", "Admin"}, {"user", "123", "Operator"}};
string username, pass, level;
char ch;

void cek_authentication(string us, string pas);

int login()
{
    system("cls");
    cout << "===========================================================" << endl;
    cout << "=                       >> LOGIN <<                       =" << endl;
    cout << "===========================================================" << endl;
    cout << "\n\t\tUsername : ";
    cin >> username;
    cout << "\n\t\tPassword : ";
    ch = _getch();
    while (ch != 13)
    {
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }

    cek_authentication(username, pass);

    return 0;
}

void cek_authentication(string us, string pas)
{
    for (int i = 0; i <= 1; i++)
    {
        // Cek inputan dengan data yang disimpan
        if (data_login[i][0] == us && data_login[i][1] == pas)
        {
            // Menyimpan data dari array ke variabel level
            level = data_login[i][2];
            break;
        }
    }

    if (level == "Admin")
    {
        system("cls");
        getLoadingAdmin();
        admin_resto();
    }
    else if (level == "Operator")
    {
        cout << "Anda login sebagi Operator";
    }
    else
    {
        cout << "\n Login gagal, username atau password salah";
        cout << "\n Silahkan coba lagi ...";
        getche();
        login();
    }
}