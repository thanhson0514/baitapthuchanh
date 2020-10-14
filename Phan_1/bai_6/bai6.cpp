#include<iostream>
#include<string>
using namespace std;

class Candidate {
private:
    float pMath = 0, pPhysic = 0, pChemis = 0;
    string SBD = "DDL";
public:
    static int number;
    // hàm nhập 1 thí sinh
    void inputSingleCandidate() {
        cin.ignore();
        cout << "Nhap diem Toan: "; cin >> pMath;
        cout << "Nhap diem Ly: "; cin >> pPhysic;
        cout << "Nhap diem Hoa: "; cin >> pChemis;
        SBD += to_string(number);
        ++number;
    }

    // hàm xem thông tin nhiều thí sinh
    void infoSingleCandidate() {
        cout << "SBD: " << SBD << endl;
        cout << "Diem Toan: " << pMath << endl;
        cout << "Diem Ly: " << pPhysic << endl;
        cout << "Diem Hoa: " << pChemis << endl;
    }

    // hàm tính tổng điểm
    float totalPoint() {
        return (pMath+pPhysic+pChemis);
    }
};

class ListCandidates {
private:
    Candidate *candidates;
    int n;

public:
    ListCandidates(){}
    ListCandidates(int n){
        this->n = n;
    }

    // hàm nhập danh sách thí sinh
    void inputCandidates() {
        cout << "Nhap so luong thi sinh: "; cin >> n;
        candidates = new Candidate[n];

        for (int i = 0; i < n; ++i) {
            cout << "Nhap thi sinh thu " << (i+1) << ":\n";
            candidates[i].inputSingleCandidate();
        }
    }

    // hàm xem thông tin danh sich các thí sinh
    void infoCandidates() {
        for (int i = 0; i < n; ++i) {
            cout << "Thi sinh thu " << (i+1) << ":\n";
            candidates[i].infoSingleCandidate();
        }
    }

    // hàm sắp xếp diểm từ cao đến thấp
    void sortGreaterPoint() {
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j > n; ++j) {
                if (candidates[i].totalPoint() < candidates[j].totalPoint()) {
                    Candidate temp = candidates[i];
                    candidates[i] = candidates[j];
                    candidates[j] = temp;
                }
            }
        }
    }

    // hàm in các thí sinh có điểm >= 18
    void candidatesGreater18() {
        const int point = 18;
        for (int i = 0; i < n; ++i)
            if (candidates[i].totalPoint() >= point)
                candidates[i].infoSingleCandidate();
    }
};

int Candidate::number = 100;

int main() {
    ListCandidates list;

    list.inputCandidates();
    cout << "------------------------------------------\n";
    cout << "THONG TIN THI SINH:\n";
        list.infoCandidates();

    cout << "------------------------------------------\n";
    cout << "Sap xep thu tu tang dan:\n";
        list.sortGreaterPoint();
        list.infoCandidates();

    cout << "------------------------------------------\n";
    cout << "THI SINH CO TONG DIEM LON HON HOAC BANG 18:\n";
        list.candidatesGreater18();
}
