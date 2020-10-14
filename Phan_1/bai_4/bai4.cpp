#include<iostream>
#include<string.h>
#define N 10000
using namespace std;

class String {
public:
    char *str;
    int length = 0;
    // hàm tạo
    String() {
        this->str = "";
    };
    String(char *str) {
        this->str = str;
        this->length = this->strlen();
    }

    // hàm hủy
    ~String() {
        this->str = "";
    }

    // hàm nhập xâu
    void input() {
        char s[N];
        cout << "Nhap xau ki tu: ";
        cin >> s;
        this->str = s;
        this->length = this->strlen();
    }

    // hàm trả về dộ dài xâu
    int strlen() {
        int i = 0;
        while ( *((this->str) + i ) != '\0')
        {
            ++this->length;
            ++i;
        }

        return this->length;
    }

    // hàm hiển thị xâu và dộ dài xâu
    void info() {
        cout << "Xau co dang: " << str << endl;
        cout << "Do dai xau la: " << length << endl;
    }

    // hàm nối dể cộng 2 xâu
    void concat(String s) {
        int l = this->length+s.length;
        char *buf = new char[l];
        strcpy(buf, this->str);
        strcat(buf, s.str);

        this->str = buf;
        this->length = l;
    }
};

int main() {
    String s1;
    s1.input();
    s1.info();

    String s2("Hello");
    s2.info();

    s1.concat(s2);
    cout << "Xau sau khi noi la:\n";
    s1.info();
    return 0;
}
