#include<iostream>
#include<string.h>
#define N 10000
using namespace std;

class String {
private:
    int length = 0;
    char *s;
public:
    // hàm tạo
    String(char *s="") {
        this->s = s;
        int i = 0;
        while ( *(this->s+i) != '\0')
        {
            ++this->length;
            ++i;
        }
    }

    // hàm sao chép
    String(const String &s2) {
        this->s = s2.s;
        this->length = s2.length;
    }

    // hàm hủy
    ~String(){}

    // toán tử gán
    String &operator=(String &b) {
        this->s = b.s;
        this->length = b.length;
        return *this;
    }

    // toán tử cộng
    String &operator+=(const String &b) {
        int n = this->length + b.length;
        char *buf = new char[n];
        strcpy(buf, this->s);
        strcat(buf,b.s);

        this->s = buf;
        this->length = n;
        return *this;
    }

    // toán tử so sánh bằng
    bool operator==(String &b) {
        int i = 0, j = 0;
        if (length != b.length) return false;
        for (; i < length; ++i) {
            if (*(this->s+i) != b.s[j]) return false;
            ++j;
        }
        return true;
    }

    // toán tử so sánh khác
    bool operator!=(String &b) {
        int i = 0, j = 0;
        if (length != b.length) return true;
        for (; i < length; ++i) {
            if (*(this->s+i) != b.s[j]) return true;
            ++j;
        }
        return false;
    }

    // toán tử so sánh lớn hơn
    bool operator>(String &b) {
        int i = 0, j = 0;
        for (; i < length; ++i) {
            if (*(this->s+i) > b.s[j]) return true;
            else if (*(this->s+i) < b.s[j]) return false;
            if(j < b.length) ++j;
        }
        return length > b.length ? true: false;
    }

    // toán tử so sánh bé hơn
    bool operator<(String &b) {
        int i = 0, j = 0;
        for (; i < length; ++i) {
            if (*(this->s+i) > b.s[j]) return false;
            else if (*(this->s+i) < b.s[j]) return true;
            if(j < b.length) ++j;
        }
        return length > b.length ? false: true;
    }

    // toán tử so sánh lớn hơn hoặc bằng
    bool operator>=(String &b) {
        int i = 0, j = 0;
        for (; i < length; ++i) {
            if (*(this->s+i) > b.s[j]) return true;
            else if (*(this->s+i) < b.s[j]) return false;
            if(j < b.length) ++j;
        }
        return length >= b.length ? true: false;
    }

    // toán tử nhỏ hơn hoặc bằng
    bool operator<=(String &b) {
        int i = 0, j = 0;
        for (; i < length; ++i) {
            if (*(this->s+i) > b.s[j]) return false;
            else if (*(this->s+i) < b.s[j]) return true;
            if(j < b.length) ++j;
        }
        return length >= b.length ? false: true;
    }

    // toán tử lấy phần tử xâu tại 1 chỉ số
    char operator[](int i) {
        if (i < 0 || i > length) return 0;
        return s[i];
    }

    // toán tử nhập
    friend istream &operator>>(istream &in, String &S) {
        char *new_s = new char[N];
        cout << "Nhap xau:"; in >> new_s;
        S.s = new_s;
        int i = 0;
        while ( *(S.s+i) != '\0' ) {
            ++S.length;
            ++i;
        }
        return in;
    }

    // toán tử nhập
    friend ostream &operator<<(ostream &out, String &S) {
        out << "Do dai cua chuoi la: " << S.length << endl;
        out << "Chuoi co dang: " << S.s << endl;
        return out;
    }
};

int main() {
    String s1;
    cin >> s1;
    cout << s1;
    cout << "----------------------------------\n";
    String s2("Hello World");
    s2 += s1;
    cout << s2;

    cout << "----------------------------------\n";
    String s3 = s1;
    cout << "s3 == s2: ";
    if (s3 == s2) cout << "True" << endl;
    else cout << "False" << endl;

    cout << "s3 >= s1: ";
    if (s3 >= s1) cout << "True" << endl;
    else cout << "False" << endl;

    cout << "----------------------------------\n";
    int i; cout << "Nhap phan tu thu i: "; cin>>i;
    cout << "Phan tu thu " << i << " cua s1: " << s1[i] << endl;
    return 0;
}
