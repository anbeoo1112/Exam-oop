    #include <iostream>
    #include <cmath>
    using namespace std;

    class Ds_nguyen {
    private:
        int sophantu;
        int *so;

    public:
        Ds_nguyen(int n) : sophantu(n), so(new int[n]) {}

        friend istream &operator>>(istream &is, Ds_nguyen &other);
        int get_size() {
            return sophantu;
        }

        ~Ds_nguyen() {
            delete[] so; // Free memory in the destructor
        }
        int get_so(int i){
            return so[i];
        }
    };

    istream &operator>>(istream &is, Ds_nguyen &other) {
        cout << "Nhap " << other.sophantu << " so: ";
        for (int i = 0; i < other.sophantu; i++) {
            is >> other.so[i];
        }
        return is;
    }

    int main() {
        int n;
        cout << "Nhap so luong phan tu cua mang: ";
        cin >> n;

        Ds_nguyen arr(n);
        cin >> arr;

        int count_duong = 0;
        double tong = 0;

        for (int i = 0; i < arr.get_size(); i++) {
            if (arr.get_so(i) > 0) {
                count_duong++;
                tong += arr.get_so(i);
            }
        }

        cout << "Trung binh cong cac so duong la: " << (count_duong == 0 ? 0 : tong / count_duong) << endl;

        cout << "Nhung so chinh phuong la: ";
        for (int i = 0; i < arr.get_size(); i++) {
            int temp = sqrt(arr.get_so(i));
            if (arr.get_so(i) == temp * temp) {
                cout << arr.get_so(i) << " ";
            }
        }

        return 0;
    }
