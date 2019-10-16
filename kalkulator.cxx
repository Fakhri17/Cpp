#include <iostream>
#include <string>
#include <stack>
using namespace std;
 
//variabel global
stack<float> s_angka;
stack<char> s_op;
 
//prototipe fungsi
short prioritasOperator(const char op);
bool bandingkanPrioritasOperator(const char op1, const char op2);
void hitung(const std::string ekspresi);
 
int main() 
{
    string ekspresi;
     
    cout << "Masukkan Operasi : ";
    getline(cin, ekspresi);
 
    hitung(ekspresi);
 
    cout << "Hasil operasi = " << s_angka.top();
 
    return 0;
}
 
short prioritasOperator(const char op) 
{
    if(op == '+' or op == '-') return 1;
    if(op == '*' or op == '/') return 2;
 
    return 0;
}
 
bool bandingkanPrioritasOperator(const char op1, const char op2)
{
    return (prioritasOperator(op1) < prioritasOperator(op2));
}
 
void lakukanOperasiAritmatika() 
{
    float angka_1 = s_angka.top();
    s_angka.pop();
     
    float angka_2 = s_angka.top();
    s_angka.pop();
 
    switch(s_op.top()) 
    {
        case '+':
            angka_2 += angka_1;
            break;
        case '-':
            angka_2 -= angka_1;
            break;
        case '*':
            angka_2 *= angka_1;
            break;
        case '/':
            angka_2 /= angka_1;
            break;
    }
 
    s_angka.push(angka_2);
}
 
void hitung(const string ekspresi) 
{
    int len = ekspresi.length();
    float angka = 0.0f;
 
    for(int i = 0; i < len; ++i) 
    {
        char token = ekspresi.at(i);
        bool apakah_angka = false;
 
        if(token == ' ') continue;
         
        if(token >= '0' and token <= '9') 
        {
            apakah_angka = true;
             
            /*
                membentuk angka dari array of char
                perulangan akan terus berlangsung selama karakter yang didapat
                dari ekspresi adalah angka dan variabel i tidak melebihi panjang ekspresi
            */
            do
            {
                angka = angka * 10.f + token - '0';
                i = i + 1;
                 
                //jika index i melebihi panjang ekspresi, maka keluar dari perulangan
                if(i == len) 
                {
                    break;
                }
 
                token = ekspresi.at(i);
            } while(token >= '0' and token <= '9');
        }
 
        //jika token yang didapat sebelumnya adalah angka, maka masukkan angka ke dalam stack angka
        if(apakah_angka == true) 
        {
            s_angka.push(angka);
            angka = 0.0f;
        }
         
        if (token == '+' or token == '-' or token == '*' or token == '/') 
        {
            if(s_op.empty() or !bandingkanPrioritasOperator(token, s_op.top()) or s_op.top() == '(') 
            {
                s_op.push(token);
            } 
            else if(bandingkanPrioritasOperator(token, s_op.top())) 
            {
                while(!s_op.empty()) 
                {
                    lakukanOperasiAritmatika();
                    s_op.pop();
                }
 
                s_op.push(token);
            }
        } 
        else if(token == '(') 
        {
            s_op.push(token);
        } 
        else if(token == ')') 
        {
            while(s_op.top() != '(') 
            {
                lakukanOperasiAritmatika();
                s_op.pop();
            }
 
            s_op.pop();
        }
    }
 
    while(!s_op.empty()) 
    {
        lakukanOperasiAritmatika();
        s_op.pop();
    }
}