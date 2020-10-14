class Vector {
private:
    float *v;
    int n;
public:
    ~Vector() {}

    // hàm thiết lập không tham số
    void set() {
        cout << "Nhap n: ";cin >> n;
        v = new float[n];
        for (int i = 0; i < n; ++i)
        {
            cout << "Nhap phan tu thu " << (i+1) << ": ";
            cin >> v[i];
        }
        return;
    }

    // hàm thiết lập 1 tham số
    void set(int n) {
        v = new float[n];
        for (int i = 0; i < n; ++i) {
            cout << "Nhap phan tu thu " << (i+1) << ": ";
            cin >> v[i];
        }
        this->n = n;
        return;
    }

    // hàm thiết lập 2 tham số
    void set(int n, float arr[]) {
        for (int i = 0; i < n; ++i) {
            v[i] = arr[i];
        }
        this->n = n;
    }

    // hàm sao chép
    void copy(Vector v2) {
        v = new float[v2.n];
        for (int i = 0; i < v2.n; ++i)
            v[i] = v2.v[i];

        this->n = v2.n;
    }

    // hàm hiện thị
    void print() {
        cout << "So phan tu: " << n << endl;
        cout << "Cac toa do cua v:";
        for (int i = 0; i < n; ++i)
            cout << " " << v[i];
    }
};
