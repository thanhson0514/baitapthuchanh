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
        out << (P.ts/P.gcd(P.ts,P.ms)) << "/" << (P.ms/P.gcd(P.ts,P.ms)) << endl;
        return out;
    }

    // hàm UCLN - O(log(n))
    int gcd(int a, int b) {
        if (a == 0) return b;
        return gcd(b%a, a);
    }

    // hàm cộng
    PhanSo operator+(PhanSo b) {
        PhanSo c;
        c.ts = ts*b.ms + b.ts*ms;
        c.ms = ms*b.ms;

        c.ts = c.ts/gcd(c.ts,c.ms);
        c.ms = c.ms/gcd(c.ts,c.ms);
        return c;
    }

    // hàm trừ
    PhanSo operator-(PhanSo b) {
        PhanSo c;
        c.ts = ts*b.ms - b.ts*ms;
        c.ms = ms*b.ms;

        c.ts = c.ts/gcd(c.ts,c.ms);
        c.ms = c.ms/gcd(c.ts,c.ms);
        return c;
    }

    // hàm nhân
    PhanSo operator*(PhanSo b) {
        PhanSo c;
        c.ts = ts*b.ts;
        c.ms = ms*b.ms;

        c.ts = c.ts/gcd(c.ts,c.ms);
        c.ms = c.ms/gcd(c.ts,c.ms);
        return c;
    }

    // hàm chia
    PhanSo operator/(PhanSo b) {
        PhanSo c;
        c.ts = ts*b.ms;
        c.ms = ms*b.ts;

        c.ts = c.ts/gcd(c.ts,c.ms);
        c.ms = c.ms/gcd(c.ts,c.ms);
        return c;
    }

    // hàm so sánh
    bool operator>(PhanSo b) {
        return (ts*b.ms) > (b.ts*ms) ? true:false;
    }
};
// 0.75 > 1.3
template<class T>
T Max(T arr[],int n) {
    T m = arr[0];
    for (int i = 1; i < n; ++i)
        if (arr[i] > m) m = arr[i];

    return m;
}


int main() {
    int n1;
    cout << "Nhap n1: "; cin >> n1;
    PhanSo P[n1];

    for (int i = 0; i < n1; ++i)
        cin >> P[i];

    cout << "Cac phan so vua nhap:\n";
    for (PhanSo item: P)
        cout << item;

    cout << endl;
    cout << "Phan so lon nhat: " << Max(P, n1);

    cout << "----------------------------\n";
    int n;
    cout << "Nhap n: "; cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cout << "Nhap so nguyen thu " << (i+1) << ": ";
        cin >> arr[i];
    }
    cout << "So nguyen lon nhat la: " << Max(arr, n);
    return 0;
}
