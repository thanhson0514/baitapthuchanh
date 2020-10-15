#include<iostream>
using namespace std;
#include "phanso.h"

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
