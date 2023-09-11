#include <iostream>
#include <cmath>

using namespace std;

class dathuc {
private:
    int bac;
    double *heso;

public:
    dathuc() : bac(0), heso(nullptr) {}

    ~dathuc() {
        if (heso)
            delete[] heso;
    }

    void input() {
        cout << "Nhap bac cua phuong trinh: ";
        cin >> bac;
        heso = new double[bac + 1];
        for (int i = 0; i < bac + 1; i++) {
            cout << "Nhap he so thu " << i << ": ";
            cin >> heso[i];
        }
    }

    void output() {
        cout << "Phuong trinh vua nhap la: ";
        cout<<"(";
        for (int i = 0; i < bac + 1; i++) {
            cout<<heso[i]<<" ";
        }
        cout << ")\n";
    }

    double giatri(double x) {
        double value = 0;
        for (int i = 0; i < bac + 1; i++) {
            value += heso[i] * pow(x, i);
        }
        return value;
    }
};

int main() {
    dathuc f;
    f.input();
    double x;
    cout << "Nhap gia tri x: ";
    cin >> x;
    cout << "Gia tri ket qua la : " << f.giatri(x) << "\n";
}
    