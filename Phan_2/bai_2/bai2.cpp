#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Complex {
private:
    int real, image;
public:
    // hàm khởi tạo
    Complex() {}
    Complex(int real, int image) {
        this->real = real; this->image = image;
    }

    // hàm hủy
    ~Complex(){}

    // hàm nhập
    void input() {
        cout << "Nhap phan thuc: "; cin >> real;
        cout << "Nhap phan ao: "; cin >> image;
    }

    // hàm xuất
    void output() {
        cout << "So phuc: " << real << (image>0?"+":"");
        cout << (abs(image)!=1?to_string(image):"") << "i" << endl;
    }

    // toán tử nhập
    friend istream &operator>>(istream &in, Complex C) {
        cout << "Nhap phan thuc: "; in >> C.real;
        cout << "Nhap phan ao: "; in >> C.image;
        return in;
    }

    // toán tử xuất
    friend ostream &operator<<(ostream &out, Complex C) {
        out << C.real << (C.image>0?"+":"");
        cout << (abs(C.image)!=1?to_string(C.image):"") << "i" << endl;
        return out;
    }

    // toán tử cộng 2 số phức
    Complex operator+(Complex C) {
        Complex C1;
        C1.real = this->real + C.real;
        C1.image = this->image + C.image;
        return C1;
    }

    // toán tử trừ 2 số phức
    Complex operator-(Complex C) {
        Complex C1;
        C1.real = this->real - C.real;
        C1.image = this->image - C.image;
        return C1;
    }

    // độ lớn của số phức
    float size() {
        return sqrt(real*real + image*image);
    }
};

int main() {
    Complex c1(6,3), c2(5,2),c3;
    c3 = c1 + c2;
    cout << "Tong 2 so phuc: " << c3;
    c3 = c1 - c2;
    cout << "Hieu 2 so phuc: " << c3;

    int n;
    cout << "Nhap n:"; cin >> n;
    Complex listC[n];

    for (int i = 0; i < n; ++i)
        listC[i].input();

    // sắp xếp số phức tăng dần
    for (int i = 0; i < 0; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (listC[i].size() > listC[j].size()) {
                Complex temp = listC[i];
                listC[i] = listC[j];
                listC[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; ++i)
        listC[i].output();

    return 0;
}
