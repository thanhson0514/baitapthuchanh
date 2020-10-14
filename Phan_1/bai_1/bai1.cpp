#include<iostream>
#define PI 3.14
using namespace std;
class Circle {
private:
    float r;
public:
    Circle(int r=0) {
        this->r = r;
    }

    // ham nhap du lieu
    void input() {
        cout << "Nhap ban kinh R: ";
        cin >> this->r;
    }

    // ham tinh dien tich va in dien tich ra man hinh
    void area() {
        float rs = PI*(this->r)*(this->r);
        cout << "Dien tich hinh tron: " << rs << endl;
    }

    // ham tinh chu vi va in chu vi ra man hinh
    void perimeter() {
        float rs = 2*PI*(this->r);
        cout << "Chu vi hinh tron: " << rs << endl;
    }
};
int main() {
    Circle *C = new Circle;

    C->input();
    C->area();
    C->perimeter();

    return 0;
}
