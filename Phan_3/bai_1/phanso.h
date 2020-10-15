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
