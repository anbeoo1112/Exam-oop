#include<bits/stdc++.h>
using namespace std;

class diem {
private:
    int x, y;

public:
    diem() : x(0), y(0) {};
    diem(int a, int b) : x(a), y(b) {};

    int khoangcach(diem &other) {
        return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
    }

    bool operator==(diem &other) {
        return (this->x == other.x && this->y == other.y);
    }

    diem operator*(diem &other) {
        int x_ = this->x * other.x;
        int y_ = this->y * other.y;
        return diem(x_, y_);
    }

    friend istream &operator>>(istream &is, diem &p);
    friend ostream &operator<<(ostream &os, diem &p);
};

istream &operator>>(istream &is, diem &p) {
    is >> p.x >> p.y;
    return is;
}

ostream &operator<<(ostream &os, diem &p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

int main() {
    diem point1(1, 2);
    diem point2(3, 4);
    diem result = point1 * point2;

    cout << "Point1: " << point1 << endl;
    cout << "Point2: " << point2 << endl;
    cout << "Tich 2 diem: " << result << endl;

    return 0;
}
