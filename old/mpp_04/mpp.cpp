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
       return formatTimeElem(hour) + ":" + formatTimeElem(minute) + ":" + formatTimeElem(second);
    }
    protected:
    int hour, minute, second;

     string formatTimeElem(int timeElem) {
        return (timeElem < 10 ? "0" : "") + to_string(timeElem); // add leading zero if needed
    }
    
};

class AlarmClock : public Clock {
    public:
    AlarmClock(int h = 0, int m = 0, int s = 0, int ah = 0, int am = 0, int as = 0, bool mil = true) 
    : Clock(h, m, s), alarm_hour(ah), alarm_minute(am), alarm_second(as), military_format_24(mil) {
        checkAlarm(); 
    }

    void checkAlarm() {
        if (hour == alarm_hour && minute == alarm_minute && second == alarm_second) {
            cout << "Wake up! Current time: "<< getTime() << endl;

        }
    }

    void setAlarm(int ah, int am, int as) {
        alarm_hour = ah;
        alarm_minute = am;
        alarm_second = as;
        checkAlarm(); 
    }
    
    void addSecond() {
        Clock::addSecond();
        checkAlarm();
    }
     
    void setFormat(bool mil) {
        military_format_24 = mil;
    }

    string getTime() {
        if (!military_format_24) {
            int displayHour = hour % 12;
            string suffix = (hour < 12) ? " AM" : " PM";
            return formatTimeElem(displayHour) + ":" + formatTimeElem(minute) + ":" + formatTimeElem(second) + suffix;
        } else {
            return Clock::getTime();
        }
    }


   protected:
    int alarm_hour, alarm_minute, alarm_second;
    bool military_format_24 = 1;

};



int main(){
    
    cout << "Clock without alarm:" << endl;
    Clock simple_Clock(1, 3, 59);
    cout << simple_Clock.getTime() << endl;  
    simple_Clock.addSecond();
    cout << simple_Clock.getTime() << endl;  
    simple_Clock.setClock(23, 59, 59);
    cout << simple_Clock.getTime() << endl;  
    simple_Clock.addSecond();
    cout << simple_Clock.getTime() << endl;  
    simple_Clock.addSecond();
    cout << simple_Clock.getTime() << endl;  



    cout << "\nAlarm Clock with set alarm:" << endl;
    AlarmClock simpleAlarmClock(11, 59, 58);
    simpleAlarmClock.setFormat(0);
    simpleAlarmClock.setAlarm(12, 0, 1);  
    for (int i = 0; i < 5; i++) {
        cout << simpleAlarmClock.getTime() << endl;  
        simpleAlarmClock.addSecond();  
    }

    cout << "\nAlarm Clock:" << endl;
    AlarmClock simple_alarmClock(12, 5, 10, 12 , 5, 11);
    for (int i = 0; i < 5; i++) {
        cout << simple_alarmClock.getTime() << endl;  
        simple_alarmClock.addSecond();  
    }
}
