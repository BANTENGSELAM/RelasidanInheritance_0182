#include <iostream>
#include <string>
using namespace std;

class orang {
public:
    string nama;

    orang(string pNama) : nama(pNama) {
        cout << "orang dibuat" << endl;
    }
    ~orang() {
        cout << "orang dihapus" << endl;
    }

    int jumlah(int a, int b) {
        return a + b;
    }
};

class pelajar : public orang {
public:
    string sekolah;

    pelajar(string pNama, string pSekolah) : orang(pNama), sekolah(pSekolah) {
        cout << "pelajar dibuat" << endl;
    }
    ~pelajar() {
        cout << "pelajar dihapus" << endl;
    }
    string perkenalan() {
        return "Hallo, Nama saya " + nama + " dari sekolah " + sekolah + "\n";
    }
};

int main() {
    pelajar siswa1("andi laksono", "SMK MA'ARIF NU 1 AJIBARANG");
    cout << siswa1.perkenalan();
    cout << "Hasil = " << siswa1.jumlah(10, 90) << endl;

    return 0;
}
