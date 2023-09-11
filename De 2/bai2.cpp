#include<bits/stdc++.h>
#include <string.h>
using namespace std;

class Mathang {
private:
    long long mahang;
    string ten;
    string nhasanxuat;
    int soluong;
    unsigned long long dongia;

public:
    long long get_mahang(){
        return mahang;
    }

    int get_soluong(){
        return soluong;
    }

    string getTen(){
        return ten;
    }
    unsigned long long get_dongia(){
        return this->dongia;
    }
    

    void nhap() {
        cout << "Nhap thong tin mat hang:" << endl;
        cout << "Nhap mahang: ";
        cin >> mahang;
        cin.ignore();  // Loại bỏ ký tự '\n' còn lại trong bộ nhớ đệm
        cout << "Nhap ten: ";
        getline(cin, ten);
        cout << "Nhap nhasanxuat: ";
        getline(cin, nhasanxuat);
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
            cout << "NSX: " << nhasanxuat << endl;
            cout << "So luong: " << soluong << endl;
            cout << "Don gia: " << dongia << endl;
            cout << endl;
        
    }
};

class Maytinh : public Mathang {
private:
    string cpu;
    string hdh;
    double trongluong;

public:
    string get_hdh(){
        return hdh;
    }

    void nhap_maytinh() {
        Mathang::nhap();
        cout << "Nhap CPU: ";
        cin.ignore();
        getline(cin, cpu);
        cout << "Nhap HDH: ";
        getline(cin, hdh);
        cout << "Nhap Trong Luong: ";
        cin >> trongluong;
        cout<<endl;
    }

    void output_maytinh() {
        Mathang::output();
        cout << "CPU: "<<cpu<<endl;
        cout <<"HDH: "<<hdh<<endl;
        cout<<"Trong Luong: "<<trongluong<<endl;
    }
    
};

int main() {
   int n;
    cout << "Nhap so luong mat hang: ";
    cin >> n;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Maytinh mt[n];

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin cua mat hang " << i + 1 << endl;
        mt[i].nhap_maytinh();
    }

    int max_dongia = 0;
    for (int i = 0; i < n; i++) {
        if (mt[i].get_dongia() > max_dongia) {
            max_dongia = mt[i].get_dongia();
        }
    }
    
    int choose;
    cout << "Ban muon tim may theo ten hay ma hang:" << endl;
    cout << "1. Ten hang" << endl;
    cout << "2. Ma hang" << endl;
    cout << "Moi nhap lua chon: ";
    cin >> choose;
    
    while (choose != 1 && choose != 2) {
        cout << "Moi chon lai yeu cau: ";
        cin >> choose;
    }
    
    bool found = false;
    
    if (choose == 1) {
        string tenmay;
        cin.ignore(); // Clear the newline character
        cout << "Nhap ten may ban muon tim: ";
        getline(cin, tenmay);
        
        for (int i = 0; i < n; i++) {
            if (mt[i].getTen() == tenmay) {
                mt[i].output_maytinh();
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << "Khong the tim thay mau may ban can tim" << endl;
        }
    }
    else if (choose == 2) {
        long long mamay;
        cout << "Nhap ma may ban muon tim: ";
        cin >> mamay;
        
        for (int i = 0; i < n; i++) {
            if (mt[i].get_mahang() == mamay) {
                mt[i].output_maytinh();
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << "Khong the tim thay mau may ban can tim" << endl;
        }
    }

    cout << "Mat hang co don gia cao nhat:" << endl;
    for (int i = 0; i < n; i++) {
        if (mt[i].get_dongia() == max_dongia) {
            mt[i].output();
        }
    }

    return 0;
}







