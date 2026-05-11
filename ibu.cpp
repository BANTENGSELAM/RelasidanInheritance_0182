#ifdef IBU_H
#define IBU_H
#include <vector>

class ibu {
    public : 
        string nama;
        vector<anak*> daftar_anak;

        ibu(string pNama) :nama(pNama) {
             cout << "Ibu \"" << nama << "\" ada\n";
            }
        ~ibu () {
            cout << "Ibu \"" << nama << "\" Tidak ada\n"; 
        }

    void tambahAnaka(anaka*);
    void cetakAnak();
};
void ibu::tambahAnak(anak* pAnak){
    daftar_anak.push_back(pAnak);
}