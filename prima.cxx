#include <iostream>
#include <cmath>
using namespace std;
// Thanks To CPP Wariors
 
bool Prima(int bilangan)
{
    //Karena 2 adalah satu-satunya bilangan prima yang genap, maka return true
    if(bilangan == 2) return true;
 
    //jika bilangan lebih kecil sama dengan 1 atau habis dibagi 2, maka return false
    if(bilangan <= 1 or (bilangan & 1) == 0) return false;
 
    int n = sqrt(bilangan);
 
    for(int i = 3; i <= n; i += 2)
    {
        //jika bilangan habis dibagi i, maka return false
        if(bilangan % i == 0) return false;
    }
     
    //jika sudah sampai ke titik ini, berarti bilangan adalah prima, maka return true
    return true;
}
 
int main() 
{
    int n;
 cout<<" \t\t Thanks To CPP Wariors \n";
    cout << "Masukkan banyak bilangan prima yang ingin dicetak: ";
    cin >> n;
 
    //variabel i digunakan untuk menghitung banyak bilangan prima yang muncul
    for(int i = 0, j = 0; i < n; ++j)
    {
        //jika j adalah prima, maka cetak j dan i ditambah 1
        if(Prima(j))
        {
            cout << j << " ";
            i = i + 1;
        }
    }
 
    return 0;
}