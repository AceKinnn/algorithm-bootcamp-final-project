#include <stdio.h>
#include <stdlib.h>
int tujuan, select;
void pilihankembali();

void clear(){
	system("cls");
}
struct User {
	char Username[100];
	int Pin[50];
}users;

void welcome(){
	printf(" +==================================+ \n");
	printf(" +=             MINI ATM           =+ \n");
	printf(" +==================================+ \n");
	printf("\n");
	printf("Silahkan Login Untuk Melanjutkan Transaksi \n");
	printf("\n");
	printf("Username : "); 
	scanf ("%s", &users.Username);
	printf("Pin : ");
	scanf ("%d", &users.Pin);
	clear();
}

void chosing(){
	printf("Selamat Datang Di Mini ATM \n");
	printf("-------------------------- \n");
	printf("\n");
	printf("Menu \n");
	printf("---- \n");
	printf("\n");
	printf("1. Cek Saldo      3. Tarik Tunai\n");
	printf("2. Transfer       4. Setor Tunai\n");
	printf("0. Batal\n");
	printf("\n");
	printf("Silahkan Pilih :  ");
}

int deposit(int initialSaldo){
	clear();
  	int toBeDeposit;
  	printf("----------- \n");
	printf("Setor Tunai \n");
	printf("----------- \n");
	printf("\n");
	printf("Masukkan Nominal Setor Tunai       : ");
  	scanf("%d", &toBeDeposit);
  	clear();
		printf("Atas Nama                  : %s\n", users.Username);
		printf("Nomor Rekening             : 8017892742\n");
		printf("\n");
		printf("Jumlah Setor Tunai Nominal : %d\n", toBeDeposit);
		printf("Lanjutkan? \n1.Yes\n2.No\n");
		scanf("%d", &select);
		clear();
		if (select==1){
			printf("Sisa saldo anda : %d\n",initialSaldo+toBeDeposit);
			return initialSaldo+toBeDeposit;
		}
		else if (select==2){
		return initialSaldo;
		}
		else printf("ERROR\n");
}

void checkSaldo(int saldo){
	clear();
  	printf("Sisa Saldo Anda: %d\n", saldo);
}

int transfer(int initialSaldo){
	clear();
  	int toBeTransferred;
	printf("-------- \n");
	printf("Transfer \n");
	printf("-------- \n");
	printf("\n");
	printf("Masukkan Nomor Rekening Tujuan : "); 
	scanf("%d", &tujuan);
	printf("Masukkan Nominal Transfer      : "); 
	scanf("%d", &toBeTransferred);
	clear();
	printf("-------- \n");
	printf("Tranfer \n");
	printf("-------- \n");
	printf("\n");
	printf("Anda Akan Mentransfer Uang Ke \n");
	printf("No. Rekening   : %d\n", tujuan);
	printf("Jumlah Nominal : %d\n", toBeTransferred);
	printf("Lanjutkan? \n1.Yes\n2.No\n"); 
	scanf("%d", &select);
	clear();
	if(select==1){
		if (initialSaldo>=toBeTransferred) {
			printf("Transaksi Anda Telah Berhasil\n");
			printf("Sisa Saldo Anda = %d\n", initialSaldo-toBeTransferred);
			return initialSaldo-toBeTransferred;
		}
		else if (initialSaldo < toBeTransferred) {
			printf("Maaf Saldo Anda Tidak Cukup Untuk Melakukan Transaksi \n");
			printf("\n");
			return initialSaldo;
		}
	}
	else if (select==2) {
		return initialSaldo;
	}
	else printf("ERROR\n");
}

int tarik(int initialSaldo){
	clear();
  	int toBewithdraw;
	printf("-------- \n");
	printf("Tarik Tunai \n");
	printf("-------- \n");
	printf("\n");
	printf("Masukan Nominal Tarik Tunai     : "); 
	scanf("%d", &toBewithdraw);
	clear();
	printf("-------- \n");
	printf("Tarik Tunai \n");
	printf("-------- \n");
	printf("\n");
	printf("Atas Nama                       : %s\n", users.Username);
	printf("Jumlah Nominal Yang Akan Ditarik: %d\n", toBewithdraw);
	printf("Lanjutkan? \n1.Yes\n2.No\n"); 
	scanf("%d", &select);
	clear();
	if(select==1){
		if (initialSaldo>=toBewithdraw) {
			printf("Transaksi Anda Telah Berhasil\n");
			printf("Sisa Saldo Anda = %d\n", initialSaldo-toBewithdraw);
			return initialSaldo - toBewithdraw;
		}
		else if (initialSaldo < toBewithdraw) {
			printf("Maaf Saldo Anda Tidak Cukup Untuk Melakukan Transaksi \n");
			printf("\n");
			return initialSaldo;
		}
	}
	else if (select==2) {
		return initialSaldo;
	}
	else printf("ERROR\n");
}

void pilihankembali(){
	printf("Kembali Ke Menu Utama?\n");
	puts("1. Kembali Ke Menu Utama");
	puts("2. Selesai Transaksi");
}

void selesai(){
	clear();
	printf("             Terima Kasih Sudah Percaya Dengan Kami             \n");
	printf("              Jangan Lupa Untuk Kembali Lagi :D                 \n");
	printf("        Test Program C By : Final Projek Bootcamp Algorithm     \n");
	printf("                         Terima Kasih                           \n");
}

void app(){
  int saldo = 3000000;
  int choice;
  do {
	chosing(); 
  	scanf("%d", &choice);
    switch (choice) {
		case 1:
	        checkSaldo(saldo);
	        	pilihankembali();
	        break;
		case 2:
	        saldo = transfer(saldo);
	        	pilihankembali();
	        break;
	    case 3:
	    	saldo = tarik(saldo);
	    		pilihankembali();
	    	break;
      	case 4:
	        saldo = deposit(saldo);
	        	pilihankembali();
	        break;
	    default: selesai();   	
    }
    scanf("%d", &choice);
    if (choice==1) {
		clear(); 
	}
	else if (choice==2){
	choice = 0; 
	}
  } while (choice != 0);
	selesai();
}

int main(void){
  welcome();
  app();

  return 0;
}
