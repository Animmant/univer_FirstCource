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

    AlarmClock(int h = 0, int m = 0, int s = 0, int ah = 0, int am = 0, int as = 0, bool mil = true) 
    : Clock(h, m, s), alarm_hour(ah), alarm_minute(am), alarm_second(as), military_format_24(mil) {}

    void setAlarm(int ah, int am, int as) {
        alarm_hour = ah;
        alarm_minute = am;
        alarm_second = as;
    }
    
    void addSecond() {
        Clock::addSecond();
        if (hour == alarm_hour && minute == alarm_minute && second == alarm_second) {
            cout << "Wake up!" << endl;
        }
    }
     
    void setFormat(bool mil) {
        military_format_24 = mil;
    }
   protected:
    int alarm_hour, alarm_minute, alarm_second;
    bool military_format_24 = 1;

};



int main(){
    
    cout << "Clock without alarm:" << endl;
    Clock time_without_light(1, 3, 59);
    cout << time_without_light.getTime() << endl;  
    time_without_light.addSecond();
    cout << time_without_light.getTime() << endl;  // After adding a second
    time_without_light.setClock(23, 59, 59);
    cout << time_without_light.getTime() << endl;  // Set time to one second before midnight
    time_without_light.addSecond();
    cout << time_without_light.getTime() << endl;  // Midnight
    time_without_light.addSecond();
    cout << time_without_light.getTime() << endl;  // One second after midnight

    cout << "\nAlarm Clock:" << endl;
    AlarmClock time_with_light(12, 5, 0);
    time_with_light.setAlarm(12, 5, 1);  // Setting alarm time
    cout << time_with_light.getTime() << endl;  // Initial time
    time_with_light.addSecond();
    cout << time_with_light.getTime() << endl;  // After adding a second, should trigger alarm
    time_with_light.setClock(2, 3, 0);
    cout << time_with_light.getTime() << endl;  // New time set
    time_with_light.setClock(23, 59, 59);
    cout << time_with_light.getTime() << endl; 
    time_with_light.addSecond(); // One second before
    time_with_light.addSecond(); // Midnight
    cout << time_with_light.getTime() << endl;  // One second after midnight
}

