#include<iostream>
#include<cmath>
using namespace std;

class Triagle {
private:
    float a,b,c;
public:
    // hàm nhập giá trị cho các cạnh
    void input() {
        cout << "Nhap canh a: "; cin >> this->a;
        cout << "Nhap canh b: "; cin >> this->b;
        cout << "Nhap canh c: "; cin >> this->c;
    }

    // hàm kiểm tra có phải là tam giac tam giác
    bool isTriagle() {
        return (a+b > c && a+c > b && b+c > a);
    }

    // hàm kiểm tra tính chất của tam giác
    void protertyTriagle() {
        if (!this->isTriagle()) cout << "3 canh a,b,c khong tao thanh 1 tam giac!" << endl;
        else {
            if (a == b || a == c || b == c) {
                if (a*a+b*b == c*c || a*a+c*c == b*b || b*b+c*c == a*a)
                    cout << "Tam giac nay la tam giac vuong can." << endl;
                else
                    cout << "Tam giac nay la tam giac deu." << endl;
            }
            else if (a*a+b*b == c*c || a*a+c*c == b*b || b*b+c*c == a*a)
                cout << "Tam giac nay la tam giac vuong." << endl;
            else if (a == b && a == c && b == c)
                cout << "Tam giac nay la tam giac deu." << endl;
            else
                cout << "Tam giac nay la tam giac thuong.";
        }
    }

    // hàm tính diện tích tam giác và in diện tích ra màn hình
    void area() {
        float p = (a+b+c)/2.0;
        float s = sqrt( p*(p-a)*(p-b)*(p-c) );

        cout << "Dien tich tam giac: " << s << endl;
    }
    // hàm in thông tin của tam giac
    void info() {
        if (this->isTriagle()) {
            this->area();
            this->protertyTriagle();
        } else
            this->protertyTriagle();
    }
};

int main() {
    Triagle T;

    T.input();
    T.info();

    return 0;
}
