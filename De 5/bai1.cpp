#include<bits/stdc++.h>
using namespace std;
class diem{
    private:
        double x,y;
    public:
        void input(){
            cout<<"Nhap hoanh do:";cin>>x;
            cout<<"Nhap tung do:";cin>>y;
        }
        void output(){
            cout<<"Hoanh do: "<<x<<endl;
            cout<<'Tung do: '<<y<<endl;

        }
        double dodai(diem &other){
                   return sqrt((this->x-other.x)*(this->x-other.x)+(this->y-other.y)*(this->y-other.y));
        }
};
int main (){
    int n;
    cout<<"Nhap so diem: ";cin>>n;
    diem k[n];
    for (int i=0;i<n;i++){
        k[i].input();
    }
    double dodai=0;
    for (int i=0;i<n;i++){
        int nextindex=(i+1)%n;
        dodai=k[i].dodai(k[nextindex]);
        cout<<"Do dai den diem "<<nextindex<<" la: "<<dodai<<endl;

    }
}