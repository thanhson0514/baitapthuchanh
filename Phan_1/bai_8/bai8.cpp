#include<iostream>
using namespace std;
#include "../bai_5/vector.h"

class Matrix {
public:
    Vector *M;
    // m hàng, n cột
    int m, n;
    // hàm khởi tạo
    Matrix(){}
    Matrix(int m,int n) {
        this->m = m; this->n = n;
        M = new Vector[m];
        for (int i = 0; i < m; ++i) {
            M[i].v = new float[n];
            for (int j = 0; j < n; ++j)
                M[i].v[j] = 0;

        }
    }
    // hàm hủy
    ~Matrix(){}

    // hàm nhập
    void input() {
        cout << "Nhap m hang: "; cin >> m;
        cout << "Nhap n cot: "; cin >> n;
        M = new Vector[m];
        for (int i = 0; i < m; ++i) {
            cout << "Hang thu " << (i+1) << ": " << endl;
            M[i].set(n);
        }
    }

    // hàm xuất
    void output() {
        cout << "Ma tran co dang:\n";
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                cout << " " << M[i].v[j];
            cout << endl;
        }
    }

    // nhân ma trận
    friend Matrix MmultiplyMatrix(Matrix M1, Matrix M2);

};
Matrix multiplyMatrix(Matrix M1,Matrix M2) {
    int row = M1.m, col = M2.n;
    Matrix M3(row, col);
    M3.output();
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            for (int k = 0; k < col; ++k) {
                M3.M[i].v[j] += M1.M[i].v[k]* M2.M[k].v[j];
            }
        }
    }

    return M3;
}
int main() {
    Matrix M1, M2;

    M1.input();
    M2.input();

    Matrix M3;
    M3 = multiplyMatrix(M1,M2);
    M3.output();

    return 0;
}
