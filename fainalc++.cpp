#include <iostream> 
#include <conio.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include<windows.h>


using namespace std;
void garis(){
	cout<<" \t=======================welcome============================= \n";} 
	int main(){
	char user[20], pass[5], status; 
	int balik; 
	int a, b, c, d, e, f, j, k, i; 
	int pil; 
	
	struct buku{
		int kodeB;
		char judul[30];
		int sewa; 
		int stock;
	}z[100];
	
		struct daftar{
			int kodeP;
			char nama[50];
			char tlp[20];
		} y[100];
	
			struct pinjam{
				int kp;
				int kb;
				int noPinjam; 
				char tglP[20];
				char tglU[20];
			} x[100];
			c=0;
			e=0;
	
	garis(); 
	cout<<" \t 	Aplikasi Peminjaman Buku Perpustakaan 	\n";
	garis(); 
	cout<<endl;
	atas:
	cout<<" Login terlebih dahulu untuk menggunakan aplikasi ini! \n";
	cout<<" Username : "; cin>>user;
	cout<<" Password : "; cin>>pass;
	if(strcmp(pass,"12345")==0) {  
		cout<<" Logi berhasil\n";
		garis(); 
		cout<<endl;
		system("cls"); 
		
	}else{
		cout<< " upsss !! Password Salah, silahkan masukkan kembali\n";
		cout<<endl;
		goto atas;
	}
	menu:
	garis(); 
	cout<<" \t\tMenu Peminjaman\n";
	cout<<" [1] Input Data Buku\n";
	cout<<" [2] Registrasi Anggota\n";
	cout<<" [3] Biodata\n";
	cout<<" [4] Peminjaman Buku\n";
	cout<<" [5] Pengembalian Buku\n";
	cout<<" [0] Keluar\n";
	cout<<" Masukan disini -> Pilihan Anda : "; cin>>pil; 
	system("cls"); 
	switch(pil){
		case 1:
			goto input; 
			break;
	case 2:
		goto daf; 
		break;
		case 3:
			goto data; 
			break;
	case 4:
		goto pjm; 
		break;
		case 5:
			goto bali; 
			break;
	case 0:
		cout<<" Terimakasih, selamat berjumpah kembali\n";
		cout<<endl;
		goto end; 
		break;
	default:
		cout<<" Pilihan tidak tersedia\n";
		cout<<endl;
		goto menu; 
		break;
	}

input:
		cout<<" Masukan Banyaknya buku yang akan diinputkan : "; cin>>a;
		for(b=0; b<a; b++){ 
			cout<<" Masukan data buku ke- "<<b+1<<endl; 
			cout<<" Kode buku\t ";
			cin>>z[b].kodeB;  
			cout<<" Judul buku\t ";
			cin>>z[b].judul; 
			cout<<" Jumlah buku\t ";
			cin>>z[b].stock; 
			cout<<endl;
		}
		system("cls"); 
		goto menu; 
daf:
	for(d=c; d<c+1; d++){ 
		cout<<" Kode Peminjaman (angka): ";
		cin>>y[d].kodeP; 
		cout<<" Nama : ";
		cin>>y[d].nama; 
		cout<<" Nomor Telepon : ";
		cin>>y[d].tlp; 
		cout<<endl;
	}
	c=c+1;
	k=c;
	cout<<" Ingin menginputkan data lagi? (y/n) : "; cin>>status;
	if(status=='Y'||status=='y'){ 
		goto daf; 
	}else{ 
	system("cls"); 
	goto menu; 
	}
			//biddata anggota
data:
	garis();
	cout<<" ----->->->->->->->-> Data Nama Anggota <-<-<-<-<-<-<-<-<-----\n";
	garis();
	cout<<" | Kode Peminjaman\t| Nama | No. Telepon | \n";
	garis();
	for(d=0; d<c; d++){ 
		cout<<" |\t"<<y[d].kodeP<<"\t| "<<y[d].nama <<"\t\t|\t"<< y[d].tlp<<endl;	
	}
	goto menu; 
			//peminjaman
pjm:
	for(f=e; f<e+1; f++){ 
		cout<<" Nomor Peminjaman : ";
		cin>>x[f].noPinjam; 
		cout<<" Kode Peminjam : ";
		cin>>x[f].kp; 
		for(d=0;d<c-1;d++){ 
			if(y[d].kodeP==x[f].kp){ 
				cout<<" Nama peminjam : "<<y[d].nama<<endl; 
				break; 
			}else{ 
			cout<<" Data tidak ditemukan "<<endl; 
			cout<<" Ingin menginputkan data lagi? (y/n) : "; cin>>status;
	if(status=='Y'||status=='y'){ 
		goto pjm; 
	}else{ 
	system("cls");
	goto menu; 
	}			}
		}
		cout<<" Kode buku : "; cin>>x[f].kb; 
		for(b=0; b<a; b++){ 
			if(z[b].kodeB==x[f].kb){ 
				cout<<" Judul buku : "<<z[b].judul<<endl; 
				break;
			}else{ 
				cout<<" Data tidak ditemukan silakan coba lagi"<<endl; 
				goto pjm; 
				
			}
		}
		cout<<" Tanggal Pinjam : ";
		cin>>x[f].tglP; 
		cout<<" Tanggal Kembali : ";
		cin>>x[f].tglU; 
		cout<<endl;
	}
	cout<<" Ingin menginputkan data lagi? (y/n) : "; cin>>status;
	if(status=='Y'||status=='y'){ 
		goto pjm; 
	}else{ 
		e=e+1;
		system("cls"); 
		goto menu; 
	}
			//pengembalian
bali:
	cout<<" kode peminjaman : ";
	cin>>balik; 
	for(f=0; f<e; f++) 
		if(x[f].kp==balik){
			cout<<" masukkan Kode buku : "<<x[f].kb<<endl; 
			cout<<" Tanggal Pinjam : "<<x[f].tglP<<endl; 
			cout<<" Tanggal Kembali : "<<x[f].tglU<<endl;
		}else{ 
			cout<<" Kode yang anda masukan salah "<<endl;
			goto bali; 
		}
		cout<<endl;
		goto menu; 

		
end:
	system("pause"); 
	return 0; 
}
