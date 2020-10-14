#include<iostream>
#include<cmath>
using namespace std;

class Point {
private:
    float x,y;
public:
    // hàm khởi tạo
    Point(){
        this->x = 0; this->y = 0;
    };
    Point(float x, float y) {
        this->x = x;
        this->y = y;
    }

    // hàm hủy
    ~Point(){
        this->x = 0;
        this->y = 0;
    }

    void input() {
        cout << "Nhap toa do x: "; cin >> x;
        cout << "Nhap toa do y: "; cin >> y;
    }

    // hàm xuất
    void output() {
        cout << "Toa do (" << x << ", " << y << ")." << endl;
    }

    // hàm tính khoảng cách giữa 2 điểm
    float spacePoint(Point b) {
        float d = sqrt( (this->x - b.x)*(this->x - b.x) + (this->y - b.y)*(this->y - b.y) );
        return d;
    }

};

int main() {
    int n;
    cout << "Nhap n: "; cin >> n;
    Point points[n];

    for (int i = 0; i < n; ++i) {
        cout << "Diem thu " << (i+1) << ":\n";
        points[i].input();
    }

    cout << "---------------------------------\n";
    for (int i = 0; i < n; ++i) {
        cout << "Diem thu " << (i+1) << ":\n";
        points[i].output();
    }

    cout << "---------------------------------\n";
    // tìm khoảng cách lớn nhất giữa 2 điểm trong n điểm - O(n^2)
    float m = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            float r = points[i].spacePoint(points[j]);
            if (m < 0) m = r;
            else if (r > m) m = r;
        }
    }
    cout << "Khoang cach lon nhat: " << m << endl;

    return 0;
}
