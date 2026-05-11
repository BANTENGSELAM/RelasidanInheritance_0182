#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User {
protected:
    static int globalId;

public:
    int id;
    string nama;
    string email;

    User(string pNama, string pEmail)
        : nama(pNama), email(pEmail)
    {
        id = generateId();

        cout << "User \"" << nama << "\" dibuat\n";
    }

    ~User() {
        cout << "User \"" << nama << "\" dihapus\n";
    }

    int generateId() {
        return ++globalId;
    }
};

int User::globalId = 0;

class Member : public User {
public:
    bool status;

    Member(string pNama, string pEmail)
        : User(pNama, pEmail)
    {
        status = true;

        cout << "Member \"" << nama << "\" dibuat\n";
    }

    ~Member() {
        cout << "Member \"" << nama << "\" dihapus\n";
    }

    void showProfile() {
        cout << "\n===== PROFILE MEMBER =====\n";
        cout << "ID     : " << id << endl;
        cout << "Nama   : " << nama << endl;
        cout << "Email  : " << email << endl;
        cout << "Status : ";

        if (status == true) {
            cout << "Aktif\n";
        } else {
            cout << "Nonaktif\n";
        }

        cout << endl;
    }
};

class Admin : public User {
public:
    vector<Member*> daftarMember;

    Admin(string pNama, string pEmail)
        : User(pNama, pEmail)
    {
        cout << "Admin \"" << nama << "\" dibuat\n";
    }

    ~Admin() {
        cout << "Admin \"" << nama << "\" dihapus\n";
    }

    void tambahMember(Member* pMember) {
        daftarMember.push_back(pMember);
    }

    void showAllMember() {
        cout << "\n===== DAFTAR MEMBER =====\n";

        for (int i = 0; i < daftarMember.size(); i++) {
            cout << "ID     : " << daftarMember[i]->id << endl;
            cout << "Nama   : " << daftarMember[i]->nama << endl;
            cout << "Email  : " << daftarMember[i]->email << endl;

            cout << "Status : ";

            if (daftarMember[i]->status == true) {
                cout << "Aktif\n";
            } else {
                cout << "Nonaktif\n";
            }

            cout << endl;
        }
    }

    void toggleActivationMember(Member* pMember) {
        pMember->status = !pMember->status;

        cout << "Status member \"" << pMember->nama << "\" berhasil diubah\n";
    }
};

int main() {

    Admin* admin1 = new Admin("Budi", "admin@gmail.com");

    Member* member1 = new Member("Andi", "andi@gmail.com");
    Member* member2 = new Member("Rina", "rina@gmail.com");

    admin1->tambahMember(member1);
    admin1->tambahMember(member2);

    admin1->showAllMember();

    member1->showProfile();

    admin1->toggleActivationMember(member1);

    member1->showProfile();

    delete admin1;
    delete member1;
    delete member2;

    return 0;
}