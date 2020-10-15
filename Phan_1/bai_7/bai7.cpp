#include<iostream>
#include<string>
#include<iomanip>
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
           cout << "Dinh dang thoi gian khong dung!" << endl;
    }
    // hàm tăng giây
    void increaseSeconds(int s) {
        int 
            new_seconds = (seconds+s)%60,
            new_minutes = (minutes+(seconds+s)/60)%60,
            new_hour = (hour+(minutes+(seconds+s)/60)/60)%24;
        
        hour = new_hour;
        minutes = new_minutes;
        seconds = new_seconds;
    }
};

int main() {
    Time T;

    T.setTime(23,59,59);
    T.view24h();
    T.view12h();

    T.increaseSeconds(2);
    T.view24h();
    T.view12h();

    // chức năng test thời gian
    for (int i=0;i<100000;++i) {
        cout<<i<<":\n";
        T.increaseSeconds(1);
        T.view24h();
        T.view12h();
    }

    return 0;
}
