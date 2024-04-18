#include <iostream>
#include <string>

using namespace std;

class Clock{
    public:
    Clock(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}
    void setClock(int h, int m, int s){
        hour = h;
        minute = m;
        second = s;
    }
    void addSecond(){
        second++;
        if (second >= 60) {
            second = 0;
            minute++;
            if (minute >= 60) {
                minute = 0;
                hour++;
                if (hour >= 24) {
                    hour = 0;
                }
            }
        }
    }


    string getTime(){
        string time = to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
        return time;
    }
    protected:
    int hour, minute, second;
    
};

class AlarmClock : public Clock {
    public:
    AlarmClock(int h = 0, int m = 0, int s = 0, bool mil = true) : alarm_hour(h), alarm_minute(m), alarm_second(s), military_format_24(mil) {}
/*
    void addSecond() {
        Clock::addSecond();
        if (military_format_24) {
            if (hour == alarm_hour && minute == alarm_minute && second == alarm_second) {
                cout << "Wake up!" << endl;
            }}}
    string getAlarmTime() {
        ostringstream oss;
        oss << setfill('0') << setw(2) << alarm_hour << ":" 
            << setw(2) << alarm_minute << ":" << setw(2) << alarm_second;
        return oss.str();
    }
*/
   protected:
    int alarm_hour, alarm_minute, alarm_second;
    bool military_format_24 = 1;

};


int main(){

    Clock time_without_light(1, 3, 59);
    
    cout << time_without_light.getTime() << endl;
    time_without_light.addSecond();
    cout << time_without_light.getTime() << endl;
    time_without_light.setClock(23, 59, 59);
    cout << time_without_light.getTime() << endl;
    time_without_light.addSecond();
    cout << time_without_light.getTime() << endl;
    time_without_light.addSecond();
    cout << time_without_light.getTime() << endl;

    cout << "\nalarm clock:" << endl;
    AlarmClock time_with_light(12, 5, 0);

    cout << time_with_light.getTime() << endl;
    time_with_light.addSecond();
    cout << time_with_light.getTime() << endl;
    time_with_light.setClock(2, 3, 0);
    cout << time_with_light.getTime() << endl;
    return 0;
}

