#include<iostream>
using namespace std;
#include "../bai_1/phanso.h"

template<class T>
void Swap(T &a, T&b) {
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
// sắp xếp tăng dần
void Sort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (arr[i] > arr[j])
                Swap(arr[i],arr[j]);
        }
    }
}

template<class T>
void Print(T arr[], int n) {
    cout << "Cac phan tu trong mang la:";
    for(int i = 0; i < n; ++i)
        cout << " " << arr[i];
}

int main() {
    int arr[] = {3,4,7,1,5,2,6};
    int n = sizeof(arr)/sizeof(*arr);
    Sort(arr,n);
    Print(arr,n);

    cout << "\n-------------------------\n";

    // sử dụng lớp phân số
    int n1;
    cout << "Nhap n1: "; cin >> n1;
    PhanSo P[n1];

    for (int i = 0; i < n1; ++i)
        cin >> P[i];

    Sort(P,n1);
    Print(P,n1);

    return 0;
}
