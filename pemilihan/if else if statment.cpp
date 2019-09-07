#include <iostream>
using namespace std;

int main(){
	int a;
	
	cout<<" Masukkan nilai = "; cin>>a;
	
	if (a >= 70){
		cout<<" Selamat anda lulus "<<endl;
	}
	
	else if (a >= 50){
		cout<<" nilai cukup (kkm)"<<endl;
	}
	
	else{
		cout<<" Gagal "<<endl;
	}
	

	
	return 0;
}
