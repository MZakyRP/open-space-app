#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

// Tugas Kelompok : Daftar gaji karyawan dengan larik
int strtoint(string strs) {
	stringstream ss;
	ss.clear();
	ss.flush();
	
	ss << strs;
	int num = 0;
	ss >> num;
	
	return num;
}

int main() {
  int jumlahKaryawan;

  cout << "Masukkan jumlah karyawan : ";
  cin >> jumlahKaryawan;

  string daftarKaryawan[jumlahKaryawan][6];

  for (int i = 0; i < jumlahKaryawan; i++) {
    cout << "\nMasukkan nama karyawan : ";
    cin >> daftarKaryawan[i][0];
    cout << "\nMasukkan golongan karyawan : ";
    cin >> daftarKaryawan[i][1];
    cout << "\nMasukkan gaji karyawan : Rp. ";
    cin >> daftarKaryawan[i][2];
    cout << "\nMasukkan tunjangan karyawan : Rp. ";
    cin >> daftarKaryawan[i][3];
    cout << "\nMasukkan tunjangan transportasi karyawan : Rp. ";
    cin >> daftarKaryawan[i][4];

	int gaji = strtoint(daftarKaryawan[i][2]);
	int tunjangan = strtoint(daftarKaryawan[i][3]);
	int transport = strtoint(daftarKaryawan[i][4]);
	
    ostringstream oss;
	int jumlah = gaji + tunjangan + transport;
	oss << jumlah;
	
	daftarKaryawan[i][5] = oss.str();

    cout << "\n=====================================================" << endl;
  }

  int max = strtoint(daftarKaryawan[0][5]);
  int min = strtoint(daftarKaryawan[0][5]);
  int maxId = 0;
  int minId = 0;

  for(int i = 0; i < jumlahKaryawan; i++) {
    if (strtoint(daftarKaryawan[i][5]) > max) {
      max = strtoint(daftarKaryawan[i][5]);
      maxId = i;
    }

    if (strtoint(daftarKaryawan[i][5]) < min) {
      min = strtoint(daftarKaryawan[i][5]);
      minId = i;
    }
  }

  using std::setw;
  cout << endl;
  cout << left;
  cout <<
	setw(14) << "[Keterangan]" << setw(20) << "[Nama]" << setw(7) << "[Gol]" << setw(16) << "[Gaji]" << setw(16) << "[Tunjangan]" << setw(16) << "[Transport]" << setw(16) << "[Jumlah]" << '\n' <<
	setw(14) << "Tertinggi" << setw(20) << daftarKaryawan[maxId][0] << setw(7) << daftarKaryawan[maxId][1] << "Rp. " << setw(12) << daftarKaryawan[maxId][2] << "Rp. " << setw(12) << daftarKaryawan[maxId][3] << "Rp. " << setw(12) << daftarKaryawan[maxId][4] << "Rp. " << setw(12) << daftarKaryawan[maxId][5] << '\n' <<
	setw(14) << "Terendah"  << setw(20) << daftarKaryawan[minId][0] << setw(7) << daftarKaryawan[minId][1] << "Rp. " << setw(12) << daftarKaryawan[minId][2] << "Rp. " << setw(12) << daftarKaryawan[minId][3] << "Rp. " << setw(12) << daftarKaryawan[minId][4] << "Rp. " << setw(12) << daftarKaryawan[minId][5] << '\n';

  return 0;
}

