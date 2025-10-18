#include <iostream>
using namespace std;

double nilairata(int uts, int uas, int tugas) {return (tugas * 0.25) + (uts * 0.35) + (uas * 0.4);}
double nilaibobotakhirUTS(int uts) {return uts * 0.35;}
double nilaibobotakhirUAS(int uas) {return uas * 0.4;}
double nilaibobotakhirTugas(int tugas) {return tugas * 0.25;}

struct tanggal { int hari; int bulan; int tahun; };
struct nilai { int uts; int uas; int tugas; };
struct Mahasiswa {
    string nama;
    int umur;
    string jurusan;
    tanggal lahir;
    nilai nilaiMhs;
};
int jumlahMahasiswa() {
    int jumlahMhs;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlahMhs;
    cout << endl;
    return jumlahMhs;
}
void mahasiswaInfo(Mahasiswa &mhs) {
    cin.ignore(); 
    cout << "Masukkan nama: ";
    getline(cin, mhs.nama);
    cout << "Masukkan umur: ";
    cin >> mhs.umur;
    cin.ignore();
    cout << "Masukkan jurusan: ";
    getline(cin, mhs.jurusan);
    cout << endl;
}
void inputTanggal(tanggal &tgl) {
    cout << "Masukkan tanggal lahir: " << endl;  
    cout << "Tanggal: ";
    cin >> tgl.hari;
    cout << "Bulan: ";
    cin >> tgl.bulan;
    cout << "Tahun: ";
    cin >> tgl.tahun;
    cout << endl;
}
void inputNilai(nilai &nilaiMhs) {
    cout << "Masukkan nilai UTS: ";
    cin >> nilaiMhs.uts;
    cout << "Masukkan nilai UAS: ";
    cin >> nilaiMhs.uas;
    cout << "Masukkan nilai Tugas: ";
    cin >> nilaiMhs.tugas;
    cout << endl;
}
void bobotNilai(const nilai &nilaiMhs) {
    cout << "Bobot Nilai:" << endl;
    cout << "UTS   : " << nilaibobotakhirUTS(nilaiMhs.uts) << endl;
    cout << "UAS   : " << nilaibobotakhirUAS(nilaiMhs.uas) << endl;
    cout << "Tugas : " << nilaibobotakhirTugas(nilaiMhs.tugas) << endl;
    cout << endl;
}
void printMahasiswaData(const Mahasiswa &mhs) {
    cout << "Nama   : " << mhs.nama << endl;
    cout << "Umur   : " << mhs.umur << endl;
    cout << "Jurusan: " << mhs.jurusan << endl << endl;
    cout << "      ** Tanggal Lahir **" << endl;
    cout << "   tanggal " << mhs.lahir.hari << " /bulan " << mhs.lahir.bulan << " /tahun " << mhs.lahir.tahun << endl << endl;
    cout << "          ** Nilai **" << endl;
    cout << "UTS   : " << mhs.nilaiMhs.uts << endl;
    cout << "UAS   : " << mhs.nilaiMhs.uas << endl;
    cout << "Tugas : " << mhs.nilaiMhs.tugas << endl;
    bobotNilai(mhs.nilaiMhs);
    cout << "Nilai Rata-rata: " 
         << nilairata(mhs.nilaiMhs.uts, mhs.nilaiMhs.uas, mhs.nilaiMhs.tugas) << endl;
    cout << "===============================" << endl;
}
int main() {
    int jumlahMhs = jumlahMahasiswa();
    Mahasiswa mhs[jumlahMhs];

    for (int i = 0; i < jumlahMhs; i++) {
        cout << "     **input Mahasiswa ke-" << i + 1 << "**" << endl; 
        mahasiswaInfo(mhs[i]);
        inputTanggal(mhs[i].lahir);
        inputNilai(mhs[i].nilaiMhs);
    }
    for (int i = 0; i < jumlahMhs; i++) {
        cout << "===============================" << endl;
        cout << "    **Data Mahasiswa ke-" << i + 1 << "**" << endl;
        printMahasiswaData(mhs[i]);
    }
    return 0;
}
