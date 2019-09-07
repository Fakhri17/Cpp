#include <iostream>
using namespace  std;
 
 int main (){
 	
 	int pilihan;
 	cout<<" Menentukan nama hari dengan angka\n\n ";
 	cout<<" Masukkan angka (1-7) "; cin>>pilihan;
 	
 	switch(pilihan){
 			case 1:
 			cout<<" Hari senin "<<endl;
 			break;
 			
 			case 2:
 			cout<<" Hari selasa "<<endl;
 			break;
 			
 			case 3:
 			cout<<" Hari rabu "<<endl;
 			break;
 			
 			case 4:
 			cout<<" Hari kamis "<<endl;
 			break;
 			
 			case 5:
 			cout<<" Hari jumat "<<endl;
 			break;
 			
 			case 6:
 			cout<<" Hari sabtu "<<endl;
 			break;
 			
 			case 7:
 			cout<<" Hari minggu "<<endl;
 			break;
 			
 			default :
 				cout<<" masukkan salah "<<endl;
	 }
 }
