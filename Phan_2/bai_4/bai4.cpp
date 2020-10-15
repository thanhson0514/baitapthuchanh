#include<iostream>
using namespace std;

class Vector {
private:
    int n, *v;
public:
    // biến đếm static
    static int count;
    // hàm tạo
    Vector(){
        this->n = 0;
        ++count;
    }

    // hàm sao chép
    Vector(const Vector &a) {
        this->n = a.n;
        this->v = a.v;
        ++count;
    }

    Vector(int size, int *a){
        n = size;
        v = new int[n];
        for (int i = 0; i < n; ++i)
            v[i] = a[i];

        ++count;
    }

    //hàm hủy
    ~Vector(){}

    // toán tử gán
    Vector operator=(Vector &b) {
        Vector c;
        c.v = b.v;
        c.n = b.n;
        return c;
    }

    // toán tử so sánh bằng
    bool operator==(Vector &b) {
        int i = 0, j = 0;
        for (;i < n; ++i) {
            if (v[i] > b.v[j]) return false;
            else if (v[i] < b.v[j]) return false;
            if (j < b.n) ++j;
        }
        return i != j ? false:true;
    }

    // toán tử so sánh khác
    bool operator!=(Vector &b) {
        int i = 0, j = 0;
        for (;i < n; ++i) {
            if (v[i] > b.v[j]) return true;
            else if (v[i] < b.v[j]) return true;
            if (j < b.n) ++j;
        }
        return i == j ? false:true;
    }

    // toán tử lấy phần tử tại chỉ số
    int operator[](int i) {
        if (i > n || i < 0) return 0;
        return v[i];
    }

    // toán tử nhập
    friend istream &operator>>(istream &in, Vector &V) {
        cout << "Nhap so phan tu: "; in >> V.n;
        V.v = new int[V.n];
        cout << "Nhap cac phan tu: ";
        for (int i = 0; i < V.n; ++i) {
            in >> *(V.v+i);
        }

        return in;
    }

    // toán tử xuất
    friend ostream &operator<<(ostream &out, Vector &V) {
        cout << "So phan tu: " << V.n << endl;
        cout << "Cac phan tu:";
        for (int i = 0; i < V.n; ++i)
            out <<  " " << V.v[i];

        return out;
    }
};
int Vector::count = 0;
int main() {
    Vector V1;
    cin >> V1;
    cout << "V: " << V1 << endl;

    cout << "----------------------------------\n";
    int arr[] = {1,2,3,4};
    Vector V2(4,arr);
    cout << "V2: " << V2 << endl;

    cout << "----------------------------------\n";
    Vector V3(V1);
    cout << "V3: " << V3 << endl;

    cout << "----------------------------------\n";
    cout << "V1 != V2 is ";
    if (V1 != V2) cout << "true" << endl;
    else cout << "false" << endl;

    cout << "V1 == V3 is ";
    if (V1 == V3) cout << "true"<< endl;
    else cout << "false" << endl;

    cout << "V3 == V2 is ";
    if (V3 == V2) cout << "true" << endl;
    else cout << "false" << endl;

    cout << "----------------------------------\n";
    int i = 0;
    cout << "Nhap phan tu thu: "; cin >> i;
    cout << "Phan tu thu " << i << " cua V2: " << V2[i] << endl;

    cout << "----------------------------------\n";
    Vector V4 = V2;
    cout << "V4: " << V4 << endl;
    cout << "So vector da khoi tao: " << Vector::count << endl;
    return 0;
}

