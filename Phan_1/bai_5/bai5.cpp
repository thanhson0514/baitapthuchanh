#include<iostream>
using namespace std;
#include "vector.h"

int main() {
    Vector v1;
    v1.set();
    v1.print();
    cout << "\n-------------------------------\n";
    v1.set(2);
    v1.print();
    cout << "\n-------------------------------\n";
    float arr[] = {1,2,3,4,5};
    v1.set(5,arr);
    v1.print();
    cout << "\n-------------------------------\nCopy: \n";
    Vector v2;
    v2.copy(v1);
    v2.print();
    return 0;
}
