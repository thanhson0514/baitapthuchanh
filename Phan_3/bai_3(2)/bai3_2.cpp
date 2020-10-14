#include<iostream>
using namespace std;
template<class T>
T Min(T a,T b) {
    if (a > b) return b;
    else return a;
}

template<class T>
T Min(T arr[], int n) {
    T m = arr[0];
    for (int i = 1; i < n; ++i)
        if (arr[i] < m) m = arr[i];

    return m;
}

int main() {
    int a1 = 2, b1 = 3;
    cout << "Gia tri nho nhat giua 2 so nguyen: " << Min(a1,b1) << endl;
    float a2 = 3.5, b2 = 1.9;
    cout << "Gia tri nho nhat giua 2 so thuc: " << Min(a2,b2) << endl;;
    string a3 = "abc", b3 = "acf";
    cout << "Gia tri nho nhat giua 2 chuoi ki tu: " << Min(a3,b3) << endl;

    cout << "------------------------------------\n";
    int arr1[] = {4,5,2,7};
    int n1 = sizeof(arr1)/sizeof(*arr1);
    cout << "Phan tu nho nhat tron mang so nguyen la: " << Min(arr1,n1) << endl;
    float arr2[] = {4.3,6.2,3.1,3.2,5};
    int n2 = sizeof(arr2)/sizeof(*arr2);
    cout << "Phan tu nho nhat tron mang so thuc la: " << Min(arr2,n2) << endl;
    string arr3[] = {"ab","be","ac", "t","bde"};
    int n3 = sizeof(arr3)/sizeof(*arr3);
    cout << "Phan tu nho nhat tron mang chuoi ki tu la: " << Min(arr3,n3) << endl;


    return 0;
}
