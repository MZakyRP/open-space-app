#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

struct MataKuliah {
	string kode;
	string nama;
	int sks;
	char nilai_huruf;
	float nilai_numerik;
	
	void setNilaiNumerik() {
		switch (nilai_huruf) {
			case 'A': nilai_numerik = 4.0; break;
			case 'B': nilai_numerik = 3.0; break;
			case 'C': nilai_numerik = 2.0; break;
			case 'D': nilai_numerik = 1.0; break;
			case 'E': nilai_numerik = 0.0; break;
			default: nilai_numerik = 0.0; break;
		}
	}
};

struct Mahasiswa {
	string nim;
	string nama;
	vector<MataKuliah> mata_kuliah_list;
	
	float hitungIPK() {
		int total_sks = 0;
		float total_nilai = 0.0;
		for (auto& mk : mata_kuliah_list) {
			total_sks += mk.sks;
			total_nilai += mk.sks * mk.nilai_numerik;
		}
		return (total_sks > 0) ? total_nilai / total_sks : 0.0;
	}
	
	void tampilkanKHS() {
		cout << "\nKartu Hasil Studi (KHS) Mahasiswa: " << nama << " (" << nim << ")\n";
		cout << left << setw(10) << "Kode" << setw(30) << "Nama Mata Kuliah" << setw(5) << "SKS"
			 << setw(15) << "Nilai Huruf" << "Nilai Numerik" << endl;
			 
		for (auto& mk : mata_kuliah_list) {
			cout << setw(10) << mk.kode << setw(30) << mk.nama << setw(5) << mk.sks
				 << setw(15) << mk.nilai_huruf << mk.nilai_numerik << endl;
		}
		
		cout << "IPK: " << fixed << setprecision(2) << hitungIPK() << endl;
	}
};

int main () {
	vector<Mahasiswa> mahasiswa_list;
	char lagi;
	
	do {
		Mahasiswa mahasiswa;
		
		cout << "Masukkan data mahasiswa:\n";
		cout << "NIM: ";
		cin >> mahasiswa.nim;
		cin.ignore();
		cout << "Nama: ";
		getline(cin, mahasiswa.nama);
		
		int jumlah_mk;
		cout << "Berapa banyak mata kuliah yang diambil (maks 5)?";
		cin >> jumlah_mk;
		if (jumlah_mk > 5) jumlah_mk = 5;
		
		for(int i = 0;i < jumlah_mk; i++) {
			MataKuliah mk;
			
			cout << "\nMata Kuliah ke-" << (i + 1) << ":\n";
			cout << "Kode Mata Kuliah: ";
			cin >> mk.kode;
			cin.ignore();
			cout << "Nama Mata Kuliah: ";
			getline(cin, mk.nama);
			cout << "Bobot SKS: ";
			cin >> mk.sks;
			cout << "Nilai Huruf (A,B,C,D,E): ";
			cin >> mk.nilai_huruf;
			mk.setNilaiNumerik();
			
			mahasiswa.mata_kuliah_list.push_back(mk);
		}
		
		mahasiswa_list.push_back(mahasiswa);
	
		cout << "\nApakah ada mahasiswa lain? (y/n): ";
		cin >> lagi;
	} while(lagi == 'Y' || lagi == 'y');
	
	cout << "\nKartu Hasil Studi (KHS) Semua Mahasiswa:\n";
	
	for (auto& mhs : mahasiswa_list) {
		mhs.tampilkanKHS();
	}
	
	return 0;
}
