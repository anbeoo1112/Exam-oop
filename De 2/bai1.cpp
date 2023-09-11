#include<bits/stdc++.h>
using namespace std;

class PS {
private:
    int tuso, mauso;

public:
    PS() {}

    PS(int tuso, int mauso) {
        if (mauso == 0) {
            cout << "Mau so khong the la 0!" << endl;
            exit(1);
        }
        this->tuso = tuso;
        this->mauso = mauso;
    }

    void input() {
        string str;
        cin >> str;
        stringstream ss(str);
        char delimiter;
        ss >> tuso >> delimiter >> mauso;
        if (delimiter != '/' || ss.fail()) {
            cerr << "Nhap khong hop le!" << endl;
            exit(1);
        }
    }

    PS operator*(const PS &other);
    friend ostream &operator<<(ostream &os, const PS &ps);  // Declaration of operator+
};

ostream &operator<<(ostream &os, const PS &ps) {
    os << ps.tuso << "/" << ps.mauso;
    return os;
}

// Definition of operator*
PS PS::operator*(const PS &other) {
    int new_tu = tuso * other.tuso;
    int new_mau = mauso * other.mauso;
    return PS(new_tu, new_mau);
}

int main() {
    PS p1, p2;
    p1.input();
    p2.input();
    PS p = p1 * p2;  // Using the overloaded * operator for multiplication
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "Tich 2 phan so la: " << p << endl;

    return 0;
}
