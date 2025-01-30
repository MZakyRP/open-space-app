#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int inputJam() {
	int jam;
    int menit;
    int detik;
	
	cin >> jam;
	if (jam < 0 && jam > 24) {
		cout << "Rentang angka jam tidak sesuai";
		return 1;
	}
    if ( cin.get() != '.' )
    {
       cout << "Format: Jam.Menit.Detik \n";
       return 1;
    }
    
    cin >> menit;
    if (menit < 0 && menit > 60) {
		cout << "Rentang angka menit tidak sesuai";
		return 1;
	}
    if ( cin.get() != '.' )
    {
       cout << "Format: Jam.Menit.Detik \n";
       return 1;
    }
    
    cin >> detik;
    if (detik < 0 && detik > 60) {
		cout << "Rentang angka detik tidak sesuai";
		return 1;
	}
	
	return (jam * 3600) + (menit * 60) + detik;
}

int main () {
    int jam_mulai;
    int jam_selesai;
    int lama_pemakaian;
    float biaya = 10000;
    
    cout << "Masukkan Jam Mulai (Jam.Menit.Detik): ";
    jam_mulai = inputJam();
    
    cout << endl;
    
    cout << "Masukkan Jam Selesai (Jam.Menit.Detik): ";
    jam_selesai = inputJam();
    
    cout << endl;
    
    lama_pemakaian = jam_selesai - jam_mulai;
    cout << "Lama Pemakaian: " << lama_pemakaian / 3600 << " Jam " << (lama_pemakaian % 3600) / 60 << " Menit " << (lama_pemakaian % 3600 % 60) << " Detik";
	
	cout << endl;
	
	cout << "Total Biaya: Rp. " << round(biaya / 3600 * lama_pemakaian);
	return 0;
}
