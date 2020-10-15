#include<iostrem>
using namespace std;

class Vector {
private:
    int n, *v;
public:
    // hàm tạo
    Vector(){}
    Vector(int size, int *a){
        n = size;
        v = new int[n];
        for (int i = 0; i < n; ++i)
            v[i] = a[i];
    }

    // hàm sao chép
    Vector(Vector a) {
        this->n = a.n;
        this->v = a.v;
    }

    //hàm hủy
    ~Vector(){}
};

int main() {


    return 0;
}

