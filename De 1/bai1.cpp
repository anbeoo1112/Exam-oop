#include<bits/stdc++.h>
using namespace std;

class dathuc {
    private:
        int bac;
        double* heso;  // Sử dụng con trỏ để định nghĩa mảng động

    public:
        dathuc(int bac) {  // Constructor
            this->bac = bac;
            heso = new double[bac + 1];
            memset(heso, 0, sizeof(double) * (bac + 1));  // Khởi tạo mảng thành 0
        }

        ~dathuc() {  // Destructor để giải phóng bộ nhớ
            delete[] heso;
        }

        void input(double arr[]) {
            for (int i = 0; i <= bac; i++) {
                heso[i] = arr[i];
            }
        }

        void output() {
            for (int i = 0; i <= bac; i++) {
                if (heso[i] == 0) continue;  // Bỏ qua các hệ số 0
                if (i == 0) {
                    cout << heso[0];
                } else if (i == 1) {
                    cout << "+" << heso[1] << "x";
                } else {
                    cout << "+" << heso[i] << "x^" << i;
                }
            }
            cout << endl;
        }

        double result(double d) {
            double ketqua = 0;
            for (int i = 0; i <= bac; i++) {
                ketqua += heso[i] * pow(d, i);
            }
            return ketqua;
        }
};

int main() {
    int bac;
    cout << "Nhap bac cua da thuc: ";
    cin >> bac;
    double* heso = new double[bac + 1];
    cout << "Nhap he so cua da thuc: ";
    for (int i = 0; i <= bac; i++) {
        cin >> heso[i];
    }

    dathuc dt(bac);
    dt.input(heso);

    cout << "Da thuc vua nhap: ";
    dt.output();

    double x;
    cout << "Nhap gia tri x: ";
    cin >> x;
    cout << "Ket qua da thuc tai x = " << x << " la: " << dt.result(x) << endl;

    delete[] heso;

    return 0;
}
