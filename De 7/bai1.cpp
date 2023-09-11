#include<bits/stdc++.h>
using namespace std;

class diem {
private:
    double x, y;

public:
    diem() : x(0), y(0) {}
    
    friend istream& operator>>(istream &is, diem &diem_);
    friend ostream& operator<<(ostream &os, const diem &diem_);

    double khoangcach(const diem &other) {
        return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
};

istream& operator>>(istream &is, diem &diem_) {
    cout << "Nhap vao toa do X: "; is >> diem_.x;
    cout << "Nhap vao toa do Y: "; is >> diem_.y;
    return is;
}

ostream& operator<<(ostream &os, const diem &diem_) {
    os << "(" << diem_.x << "," << diem_.y << ")";
    return os;
}

int main() {
    int n;
    cout << "Nhap so diem: "; cin >> n;
    diem k[n];
    for (int i = 0; i < n; i++) {
        cout << "Diem " << i + 1 << ":\t"; cin >> k[i];
    }
    
    diem a;
    double tong = 0;
    double minDist = numeric_limits<double>::max();
    for (int i = 0; i < n; i++) {
        tong += k[i].khoangcach(a);
        if (k[i].khoangcach(a) < minDist)
            minDist = k[i].khoangcach(a);
    }
    cout<<"Cac diem gan goc toa do nhat:\n";
    for (int i = 0; i < n; i++)
        if (k[i].khoangcach(a) == minDist)
            cout << k[i] << endl;

    return 0;
}
