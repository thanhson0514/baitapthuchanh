#include<iostream>
#include<cmath>
using namespace std;

class Point {
private:
    float x,y;
public:
    // hàm tạo
    Point(){this->x = 0; this->y = 0;}
    Point(float x, float y) {
        this->x = x;
        this->y = y;
    }

    // hàm hủy
    ~Point(){}

    // Nạp chồng toán tử nhập
    friend istream &operator>>(istream &in, Point &P) {
        cout << "Nhap toa do x: "; in >> P.x;
        cout << "Nhap toa do y: "; in >> P.y;
        return in;
    }

    // Nạp chồng toán tử xuất
    friend ostream &operator<<(ostream &out, Point P) {
        out << "Toa do diem: (" << P.x << ", " << P.y << ")";
        return out;
    }

    // hàm tính khoảng cách
    friend float space(Point a, Point b);
};

float space(Point a, Point b) {
    float d = sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
    return d;
}

class Polygonal {
private:
    Point *a;
    int size;
public:
    // hàm tạo
    Polygonal(){}
    Polygonal(int size){
        a = new Point[size];
        this->size = size;
    }

    // hàm hủy
    ~Polygonal(){}

    // Nạp chồng toán tử nhập
    friend istream &operator>>(istream &in, Polygonal &Pol) {
        cout << "Nhap so toa do: "; in >> Pol.size;
        Pol.a = new Point[Pol.size];
        for (int i = 0; i < Pol.size; ++i)
            in >> Pol.a[i];
        return in;
    }

    // Nạp chồng toán tử xuất
    friend ostream &operator<<(ostream &out, Polygonal Pol) {
        cout << "Cac toa do:\n";
        for (int i = 0; i < Pol.size; ++i)
            out << Pol.a[i] << endl;
        return out;
    }

    // hàm kiểm tra đa giác có phải là tam giác
    friend bool isTriagle(Polygonal Pol);

    friend bool isIsoscelesPolygonal(Polygonal Pol);
};

bool isTriagle(Polygonal Pol) {
    if (Pol.size != 3) return false;

        float a = space(Pol.a[0], Pol.a[1]);
        float b = space(Pol.a[0], Pol.a[2]);
        float c = space(Pol.a[1], Pol.a[2]);

        if (a+b > c && a+c > b && b+c > a) return true;

        return false;
}

bool isIsoscelesPolygonal(Polygonal Pol) {
    bool isIsosceles = true;

    for (int i = 0; i < Pol.size-1; ++i)
        for (int j = i+1; j < Pol.size-1; ++j)
            isIsosceles = ( space(Pol.a[i],Pol.a[j]) == space(Pol.a[i+1],Pol.a[j+1]) ) && isIsosceles;

    return isIsosceles;
}

int main() {
    Polygonal Pol;

    cin >> Pol;

    cout << Pol;

    if (isTriagle(Pol)) cout << "Da giac nay la tam giac." << endl;
    if(isIsoscelesPolygonal(Pol)) cout << "Da giac nay la da giac deu." << endl;

    return 0;
}

