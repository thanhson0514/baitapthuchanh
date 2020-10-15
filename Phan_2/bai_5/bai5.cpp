#include<iostrem>
using namespace std;

class String {
private:
    char s;
    int length;
public:
    // hàm tạo
    String(char *s="") {
        this->s = s;
    }

    // hàm sao chép
    String(String s2) {
        this->s = s2.s;
        this->length = s2.length;
    }

    // hàm hủy
    ~String(){}
};

int main() {


    return 0;
}
