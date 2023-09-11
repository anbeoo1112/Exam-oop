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

    void output() {
        cout << tuso << "/" << mauso << endl;
    }

    PS operator+(const PS &other);  // Declaration of operator+
};

// Definition of operator+
PS PS::operator+(const PS &other) {
    int new_tu = tuso * other.mauso + mauso * other.tuso;
    int new_mau = mauso * other.mauso;
    return PS(new_tu, new_mau);
}

int main() {
    PS p1, p2;
    p1.input();
    p2.input();
    PS p = p1 + p2;  // Using the overloaded + operator
    cout << "p1: ";
    p1.output();
    cout << "p2: ";
    p2.output();
    cout << "Tong 2 phan so la: ";
    p.output();

    return 0;  // Added a return statement
}
