#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

class Hang {
private:
    long long mahang;
    string ten;
    int soluong;
    unsigned long long dongia;

public:
    long long get_mahang() {
        return mahang;
    }

    int get_soluong() {
        return soluong;
    }

    string getTen() {
        return ten;
    }

    unsigned long long get_dongia() {
        return dongia;
    }

    void nhap() {
        cout << "Nhap thong tin mat hang:" << endl;
        cout << "Nhap mahang: ";
        cin >> mahang;
        cin.ignore(); // Loại bỏ ký tự '\n' còn lại trong bộ nhớ đệm
        cout << "Nhap ten: ";
        getline(cin, ten);
        cout << "Nhap soluong: ";
        cin >> soluong;
        cout << "Nhap dongia: ";
        cin >> dongia;
        if (mahang <= 0 || soluong < 0 || dongia == 0) {
            throw("Thieu hoac sai du lieu");
        }
    }

    void output() {
        cout << "Ma hang: " << mahang << endl;
        cout << "Ten: " << ten << endl;
        cout << "So luong: " << soluong << endl;
        cout << "Don gia: " << dongia << endl;
        cout << endl;
    }
};

class Maygiat : public Hang {
private:
    double can;

public:
    double get_can() {
        return can;
    }

    void nhap_maygiat() {
        Hang::nhap();
        cout << "Nhap so can: ";
        cin >> can;
    }

    void output_maygiat() {
        Hang::output();
        cout << "So can: " << can << endl;
    }
};

int main() {
    int n;
    cout << "Nhap so luong mat hang: ";
    cin >> n;
    Maygiat mt[n];

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin cua mat hang " << i + 1 << endl;
        mt[i].nhap_maygiat();
    }

    vector<Maygiat> find;
    cout << "Nhap ten mat hang muon tim: ";
    string find_ten;
    cin.ignore();
    getline(cin, find_ten);
    for (int i = 0; i < n; i++) {
        if (mt[i].getTen() == find_ten)
            find.push_back(mt[i]);
    }

    if (!find.empty()) {
        for (auto &item : find) {
            item.output_maygiat();
        }
    } else {
        cout << "Khong co mat hang nao tim thay" << endl;
    }

    unsigned long long min_dongia = ULLONG_MAX;
    for (int i = 0; i < n; i++) {
        if (mt[i].get_dongia() < min_dongia && mt[i].get_can() == 6) {
            min_dongia = mt[i].get_dongia();
        }
    }

    cout << "Mat hang co don gia thap nhat va so can la 6:" << endl;
    for (int i = 0; i < n; i++) {
        if (mt[i].get_dongia() == min_dongia && mt[i].get_can() == 6) {
            mt[i].output_maygiat();
        }
    }

    return 0;
}
