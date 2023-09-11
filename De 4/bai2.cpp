#include<bits/stdc++.h>
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
int main(){
    int n;
    cout << "Nhap so luong mat hang: ";
    cin >> n;
    Maytinh mt[n];

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin cua mat hang " << i + 1 << endl;
        mt[i].nhap_maytinh();
    }
     int dem=0;
    for (int i=0;i<n;i++){
        if (mt[i].get_soluong()==0){
           dem=1;

        }
    }
    if (dem==1){
        cout<<"Nhung mat hang dang het:"<<endl;
        for (int i=0;i<n;i++){
        if (mt[i].get_soluong()==0){
           mt[i].output_maytinh();
           }

        }
    }

    else
        cout<<"Khong mat hang nao het"<<endl;

        int max_dongia = 0;
    for (int i = 0; i < n; i++) {
        if (mt[i].get_dongia() > max_dongia && mt[i].get_hdh() == "Windows") {
            max_dongia = mt[i].get_dongia();
        }
    }

    cout << "Mat hang co don gia cao nhat va HDH Windows:" << endl;
    for (int i = 0; i < n; i++) {
        if (mt[i].get_dongia() == max_dongia && mt[i].get_hdh() == "Windows") {
            mt[i].output();
        }
    }

    return 0;
}
