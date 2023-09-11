#include<bits/stdc++.h>
using namespace std;

class QLH {
private:
    int mahang;
    string tenhang;
    string xuatxu;
    int loaihang, soluong;

public:
    void input() {
        cout << "Nhap ma hang: ";
        cin >> mahang;
        cout << "\nNhap ten hang: ";
        cin.ignore(); // Ignore newline left in buffer
        getline(cin, tenhang);
        cout << "\nNhap xuat xu: ";
        cin >> xuatxu;
        cout << "\nNhap so luong: ";
        cin >> soluong;
        cout << "\nNhap loai hang: ";
        cin >> loaihang;
    }

    void output() {
        cout << "Ma Hang: " << mahang << endl
             << "Ten Hang: " << tenhang << endl
             << "Xuat Xu: " << xuatxu << endl
             << "So luong: " << soluong << endl;
    }

    int get_loai() {
        return loaihang;
    }

    int get_soluong() {
        return soluong;
    }

    int get_ma() {
        return mahang;
    }
};

class DIENTU : public QLH {
private:
    int tgbh;

public:
    void input(){
        QLH::input();
        cout<<"Nhap thoi gian bao hanh:";cin>>tgbh;
    }
    void output(){
        QLH::output();cout<<"\nThoi Gian Bao Han:"<<tgbh;
    }
    int get_baohanh() {
        return tgbh;
    }
};

int main() {
    int n;
    cout << "Nhap so luong mat hang: ";
    cin >> n;
    DIENTU may[n];
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin cho mat hang thu " << i + 1 << ":";
        may[i].input();
    }
    for (int i = 0; i < n; i++) {
        cout << "May co ma so " << may[i].get_ma() << " co so luong la: " << may[i].get_soluong() << " may" << endl;
    }
    int max_bh = 0;
    for (int i = 0; i < n; i++) {
        if (may[i].get_baohanh() > max_bh && may[i].get_loai() == 1) {
            max_bh = may[i].get_baohanh();
        }
    }
    cout << "Cac dong may loai 1 va duoc bao hanh lau nhat la:\n";
    for (int i = 0; i < n; i++) {
        if (may[i].get_baohanh() == max_bh && may[i].get_loai() == 1)
            may[i].output();
    }

    return 0; // Added a return statement
}
