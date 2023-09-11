#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Mon_hoc {
private:
    int ma, sotin;
    string tenmon;

public:
    Mon_hoc(int ma = 0, string tenmon = "", int sotin = 0) {
        this->ma = ma;
        this->tenmon = tenmon;
        this->sotin = sotin;
    }

    void input() {
        cout << "Nhap ma mon: ";
        cin >> ma;
        cin.ignore();
        cout << "Nhap ten mon: ";
        getline(cin, tenmon);
        cout << "Nhap so tin chi: ";
        cin >> sotin;
    }

    void output() {
        cout << "\tMa mon: " << ma << endl;
        cout << "\tTen mon: " << tenmon << endl;
        cout << "\tSo tin chi: " << sotin << endl;
    }

    int get_sotin() {
        return sotin;
    }

    int get_ma() {
        return ma;
    }
};

class DKHP {
private:
    int msv;
    string hoten;
    vector<Mon_hoc> dangky;

public:
    DKHP(int msv = 0, string hoten = "") {
        this->msv = msv;
        this->hoten = hoten;
    }

    void input() {
        cout << "Nhap ma sinh vien: ";
        cin >> msv;
        cin.ignore();
        cout << "Nhap ten sinh vien: ";
        getline(cin, hoten);

        int numCourses;
        cout << "Nhap so mon hoc muon dang ky: ";
        cin >> numCourses;
        dangky.clear(); // Xóa danh sách đăng ký trước đó

        for (int i = 0; i < numCourses; i++) {
            int maMon;
            cout << "Nhap ma mon hoc " << i + 1 << ": ";
            cin >> maMon;
            Mon_hoc monHoc(maMon);
            dangky.push_back(monHoc);
        }
    }

    void output() {
        cout << "Ma sinh vien: " << msv << endl;
        cout << "Ten sinh vien: " << hoten << endl;
        cout << "So tin chi dang ky: " << tinhTongTinChi() << endl;
        cout << "Danh sach mon hoc da dang ky:" << endl;
        for (int i = 0; i < dangky.size(); i++) {
            cout << "Mon " << i + 1 << ":" << endl;
            dangky[i].output();
        }
    }

    int tinhTongTinChi() {
        int tongTinChi = 0;
        for (int i = 0; i < dangky.size(); i++) {
            tongTinChi += dangky[i].get_sotin();
        }
        return tongTinChi;
    }

    bool coMonHoc(int maMon) {
        for (int i = 0; i < dangky.size(); i++) {
            if (dangky[i].get_ma() == maMon) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int m, n;
    cout << "Nhap so luong mon hoc: ";
    cin >> m;
    vector<Mon_hoc> danhSachMonHoc;
    
    for (int i = 0; i < m; i++) {
        Mon_hoc monHoc;
        cout << "Nhap thong tin mon hoc " << i + 1 << ":" << endl;
        monHoc.input();
        danhSachMonHoc.push_back(monHoc);
    }

    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    vector<DKHP> danhSachSinhVien;

    for (int i = 0; i < n; i++) {
        DKHP sinhVien;
        cout << "Nhap thong tin sinh vien " << i + 1 << ":" << endl;
        sinhVien.input();
        danhSachSinhVien.push_back(sinhVien);
    }

    // In thông tin số tín chỉ của mỗi sinh viên
    for (int i = 0; i < n; i++) {
        cout << "Sinh vien " << i + 1 << " da dang ky " << danhSachSinhVien[i].tinhTongTinChi() << " tin chi." << endl;
    }

    // Nhập mã môn học và thống kê số sinh viên đã đăng ký môn
    int maMonHoc;
    cout << "Nhap ma mon hoc can thong ke: ";
    cin >> maMonHoc;
    int soSinhVienDangKy = 0;
    for (int i = 0; i < n; i++) {
        if (danhSachSinhVien[i].coMonHoc(maMonHoc)) {
            soSinhVienDangKy++;
        }
    }
    cout << "Co " << soSinhVienDangKy << " sinh vien da dang ky mon hoc co ma " << maMonHoc << "." << endl;

    return 0;
}
