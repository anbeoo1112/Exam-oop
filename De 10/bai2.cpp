#include <bits/stdc++.h>
using namespace std;

class dathuc {
private:
    int bac;
    double *heso;

public:
    dathuc() : bac(0), heso(nullptr) {};
    dathuc(int a, double *b) : bac(a) {
        heso = new double[a + 1];
        for (int i = 0; i <= a; i++) {
            heso[i] = b[i];
        }
    }

    // Copy constructor
    dathuc(const dathuc &other) : bac(other.bac) {
        heso = new double[bac + 1];
        for (int i = 0; i <= bac; i++) {
            heso[i] = other.heso[i];
        }
    }

    // Destructor to free memory
    ~dathuc() {
        delete[] heso;
    }

    friend ostream &operator<<(ostream &os, const dathuc &other);
    friend istream &operator>>(istream &is, dathuc &other);

    dathuc operator+(const dathuc &other) {
        int max_bac = max(this->bac, other.bac);
        double *result_heso = new double[max_bac + 1];

        for (int i = 0; i <= max_bac; i++) {
            double this_heso = (i <= this->bac) ? this->heso[i] : 0.0;
            double other_heso = (i <= other.bac) ? other.heso[i] : 0.0;
            result_heso[i] = this_heso + other_heso;
        }

        return dathuc(max_bac, result_heso);
    }
};

ostream &operator<<(ostream &os, const dathuc &other) {
    for (int i = other.bac; i >= 0; i--) {
        if (i > 1)
            os << other.heso[i] << "x^" << i << "+";
        else if (i == 1)
            os << other.heso[i] << "x+";
        else
            os << other.heso[i];
    }
    return os;
}

istream &operator>>(istream &is, dathuc &other) {
    cout << "Nhap bac cua da thuc: ";
    is >> other.bac;

    if (other.bac < 0) {
        other.bac = 0;
    }

    delete[] other.heso;
    other.heso = new double[other.bac + 1];

    for (int i = other.bac; i >= 0; i--) {
        cout << "Nhap he so bac " << i << ": ";
        is >> other.heso[i];
    }

    return is;
}

int main() {
    dathuc daThuc1, daThuc2;
    cin >> daThuc1 >> daThuc2;

    dathuc sum = daThuc1 + daThuc2;

    cout << "Tong cua hai da thuc la: " << sum << endl;

    return 0;
}
