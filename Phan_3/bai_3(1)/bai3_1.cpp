#include<iostream>
using namespace std;
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

int main() {
    int arr[] = {3,4,7,1,5,2,6};
    int n = sizeof(arr)/sizeof(*arr);
    Sort(arr,n);
    for (int i: arr) cout << i;
    return 0;
}
