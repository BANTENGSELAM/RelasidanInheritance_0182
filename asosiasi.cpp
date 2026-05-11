#include <iostream>
#include <vector>
using namespace std;

class dokter;
class pasien {  // assosiasi
    public: 
    string nama;
    vector<dokter*> daftar_dokter;
    pasien(string pNama) :nama(pNama){
        cout << "Pasien\"" << nama << "\" ada\n";
    }
    ~pasien() {
        cout << "Pasien\"" << nama << "\" tidak ada\n";
    }
    void tambahDokter(dokter*);
    void cetakDokter();
};

class dokter {
    public:
        string nama;
        vector<pasien*> daftar_pasien;

        dokter(string pNama) :nama(pNama) {
            cout << "Dokter\"" << nama << "\" ada\n";
        }
        ~dokter(){
            cout << "Dokter\"" << nama << "\"tidak ada\n";
        }
};

void pasien::tambahDokter(dokter* pDokter){
    daftar_dokter.push_back(pDokter);
}
void pasien::cetakDokter(){
    cout << "Daftar Dokter yang menangani pasien \"" << this->nama << "\" : \n";
    for (auto& a : daftar_dokter) { // auto digunakan dalam perualangan for untuk secara otomatis menentukan tipe data dari elemen yang diitera
        cout << a->nama << "\n";
    }
    cout << endl;
}
void dokter::tambahPasien(pasien* pPaisen){
    daftar_pasien.push_back(pPasien);
    pPasien->tambahDokter(this);
}
void dokter::cetakPasien(){
    cout << "Daftar Pasien dari dokter \"" << this->nama << "\" : \n";
    for (auto& a : daftar_pasien) { // auto digunakan dalam perualangan for untuk secara otomatis menentukan tipe data dari elemen yang diitera
        cout << a->nama << "\n";
    }
    cout << endl;
}