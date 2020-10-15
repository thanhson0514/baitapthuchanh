#include<iostream>
#include<string>
#include<iomanip>
#include<Windows.h>
using namespace std;

class Time {
private:
    int hour, minutes, seconds;
public:
    // hàm cài đặt thời gian
    void setTime(int hour, int minutes, int seconds) {
        this->hour = hour;
        this->minutes = minutes;
        this->seconds = seconds;
    }

    // hàm kiểm tra giờ phút giây hợp lệ
    bool isTime() {
        bool isH = false, isM = false, isS = false;
        if (hour >= 0 && hour <= 23) isH = true;
        if (minutes >= 0 && minutes <= 59) isM = true;
        if (seconds >= 0 && seconds <= 69) isS = true;

        return isH && isM && isS;
    }

    // hàm in giờ phút giây dạng 24h
    void view24h() {
        if (isTime()) {
            cout << "time: " << setfill('0') << setw(2) << (hour%24) << ":";
            cout << setfill('0') << setw(2) << minutes << ":";
            cout << setfill('0') << setw(2) << seconds << endl;
        } else
            cout << "Dinh dang thoi gian khong dung!" << endl;
    }

    // hàm in giờ phút giây dạng 12h
    void view12h() {
        if (isTime()) {
            string t = (hour%24) > 12 ? "PM":"AM";
            cout << "time: " << setfill('0') << setw(2) << (hour%12) << ":";
            cout << setfill('0') << setw(2) << minutes << ":";
            cout << setfill('0') << setw(2) << seconds << t << endl;
        } else
    }       cout << "Dinh dang thoi gian khong dung!" << endl;

    // hàm tăng giây
    void increaseSeconds(int s) {
        int new_minutes = minutes;
        int new_hour = hour;

        new_minutes += (seconds+s)/60;
        new_hour += (minutes+new_minutes)/60;

        hour = new_hour;
        minutes = new_minutes%60;
        seconds = (seconds+s)%60;
    }
};

int main() {
    Time T;

    T.setTime(23,59,59);
    T.view24h();
    T.view12h();

    T.increaseSeconds(61);
    T.view24h();
    T.view12h();

    // chức năng test thời gian
    int i = 0;
    while(true) {
        Sleep(5);
        system("CLS");
        T.increaseSeconds(i++);
        T.view12h();
        T.view24h();
    }

    return 0;
}
