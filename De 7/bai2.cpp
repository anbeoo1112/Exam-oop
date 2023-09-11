#include <iostream>
#include <cmath>

using namespace std;

class toado {
private:
    double x, y;
public:
    void input() {
        cout << "Nhap hoanh do: ";
        cin >> x;
        cout << "Nhap tung do: ";
        cin >> y;
    }

    void output() {
        cout << "(" << x << "," << y << ")" << endl;
    }

    double khoangcach() {
        return sqrt(x * x + y * y);
    }
};

class diemmau : public toado {
private:
    int mau;
public:
    void input() {
        toado::input();
        cout << "Chon mau: 1-Red, 2-Green, 3-Blue: ";
        cin >> mau;
    }

    void output() {
        toado::output();
        cout << "Mau: ";
        switch (mau) {
            case 1:
                cout << "red" << endl;
                break;
            case 2:
                cout << "Yellow" << endl;
                break;
            case 3:
                cout << "blue" << endl;
                break;
            default:
                cout << "No color" << endl;
                break;
        }
    }

    int getmau() {
        return mau;
    }
};

int main() {
    int n;
    cout << "Nhap so diem: ";
    cin >> n;
    diemmau mau[n];
    int red = 0, yel = 0, blue = 0;
    for (int i = 0; i < n; i++) {
        mau[i].input();
        switch (mau[i].getmau()) {
            case 1:
                red++;
                break;
            case 2:
                yel++;
                break;
            case 3:
                blue++;
                break;
        }
    }
    cout << "Thong ke cac mau\n";
    cout << "Do: " << red << endl;
    cout << "Vang: " << yel << endl;
    cout << "Xanh bien: " << blue << endl;
    double max = 0;
    for (int i = 0; i < n; i++)
        if (mau[i].khoangcach() > max)
            max = mau[i].khoangcach();
    for (int i = 0; i < n; i++)
        if (mau[i].khoangcach() == max)
            mau[i].output();
    return 0;
}