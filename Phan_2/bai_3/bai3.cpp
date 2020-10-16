#include<iostream>
using namespace std;

class PhanSo {
private:
    int ts,ms;
public:
    // hàm khởi tạo
    PhanSo() {}
    PhanSo(int ts, int ms) {
        this->ts = ts;
        this->ms = ms;
    }

    ~PhanSo() {}

    // hàm nhập
    friend istream &operator>>(istream &in, PhanSo &P) {
        cout << "Nhap tu so: "; in >> P.ts;
        cout << "Nhap mau so: "; in >> P.ms;
        return in;
    }

    // hàm xuất
    friend ostream &operator<<(ostream &out, PhanSo P) {
        out << P.ts << "/" << P.ms << endl;
        return out;
    }

    // hàm cộng
    PhanSo operator+(PhanSo b) {
        PhanSo c;
        c.ts = ts*b.ms + b.ts*ms;
        c.ms = ms*b.ms;

        return c;
    }

    // hàm trừ
    PhanSo operator-(PhanSo b) {
        PhanSo c;
        c.ts = ts*b.ms - b.ts*ms;
        c.ms = ms*b.ms;

        return c;
    }

    // hàm nhân
    PhanSo operator*(PhanSo b) {
        PhanSo c;
        c.ts = ts*b.ts;
        c.ms = ms*b.ms;

        return c;
    }

    // hàm chia
    PhanSo operator/(PhanSo b) {
        PhanSo c;
        c.ts = ts*b.ms;
        c.ms = ms*b.ts;

        return c;
    }
};

int main() {
    PhanSo a,b;
    cin >> a;cin>>b;
    cout << "phan so a: " << a << endl;
    cout << "phan so b: " << b << endl;

    PhanSo c1,c2,c3,c4;
    c1 = a+b;
    cout << "a+b: " << c1  << endl;
    c2 = a-b;
    cout << "a-b: " << c2 << endl;
    c3 = a*b;
    cout << "a*b: " << c3 << endl;
    c4 = a/b;
    cout << "a/b: " << c4 << endl;
}
