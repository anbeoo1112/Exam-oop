#include <iostream>
#include <string>

using namespace std;

class Nguoi {
private:
    string ht;
    unsigned int tuoi;

public:
    void input() {
        cin.ignore(); // Clear newline character from previous input
        cout << "Nhap ho ten: ";
        getline(cin, ht);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
    }

    void output() {
        cout << "Ho va ten: " << ht << endl;
        cout << "Tuoi: " << tuoi << endl;
    }
};

class qlnv : public Nguoi {
private:
    unsigned int snct;
    unsigned long long luong;

public:
    void input() {
        Nguoi::input();
        cout << "Nhap so nam cong tac: ";
        cin >> snct;
        cout << "Nhap luong: ";
        cin >> luong;
    }

    void output() {
        Nguoi::output();
        cout << "So nam cong tac: " << snct << endl;
        cout << "Luong: " << luong << endl;
    }

    unsigned long long getluong() {
        return luong;
    }

    unsigned int getnam() {
        return snct;
    }
};

int main() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    qlnv cty[n];
    for (int i = 0; i < n; i++) {
        cty[i].input();
    }
    
    unsigned long long tong = 0;
    for (int i = 0; i < n; i++) {
        tong += cty[i].getluong();
    }
    cout << "Luong trung binh: " << static_cast<double>(tong) / n << endl;
    
    unsigned int maxNam = 0;
    for (int i = 0; i < n; i++) {
        if (cty[i].getnam() > maxNam)
            maxNam = cty[i].getnam();
    }
    
    cout << "Nhung nhan vien co luong cao nhat: \n";
    for (int i = 0; i < n; i++) {
        if (cty[i].getnam() == maxNam) {
            cty[i].output();
            cout << endl;
        }
    }

    return 0;
}
