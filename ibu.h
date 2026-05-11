// #ifndef IBU_H
// #define IBU_H
// #include <vector>

// class ibu {
//     public : 
//         string nama;
//         vector<anak*> daftar_anak;

//         ibu(string pNama) :nama(pNama) {
//              cout << "Ibu \"" << nama << "\" ada\n";
//             }
//         ~ibu () {
//             cout << "Ibu \"" << nama << "\" Tidak ada\n"; 
//         }

//     void tambahAnak(anaka*);
//     void cetakAnak();
// };
// void ibu::tambahAnak(anak* pAnak){
//     daftar_anak.push_back(pAnak);
// }
// void ibu::cetakAnak(){
//     cout << "Daftar Anak dari Ibu \"" << this->nama << "\":\n";
//     /* for (auto& a : daftar_anak) {
//     cout << a->nama << "\n";
//     } */
//    for (int i = 0; i < daftar_anak.size(); i++) {
//     cout << daftar_anak[i]->nama << endl;
//    }
//    cout << endl;
// }
// #endif

#ifndef IBU_H // Gunakan ifndef, bukan ifdef
#define IBU_H
#include <vector>
#include <iostream>
#include <string>

class ibu {
public:
    string nama;
    vector<anak*> daftar_anak;

    ibu(string pNama) : nama(pNama) {
        cout << "Ibu \"" << nama << "\" ada\n";
    }
    ~ibu() {
        cout << "Ibu \"" << nama << "\" Tidak ada\n";
    }

    void tambahAnak(anak* pAnak); // Perbaiki typo 'tambahAnaka' dan 'anaka'
    void cetakAnak();
};

void ibu::tambahAnak(anak* pAnak) {
    daftar_anak.push_back(pAnak);
}

void ibu::cetakAnak() {
    cout << "Daftar Anak dari Ibu \"" << this->nama << "\":\n";
    for (int i = 0; i < daftar_anak.size(); i++) {
        cout << daftar_anak[i]->nama << endl;
    }
    cout << endl;
}
#endif
