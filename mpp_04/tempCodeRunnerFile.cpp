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

    string getTime()  {
        if (!military_format_24) {
            int displayHour = hour % 12;
            if (displayHour == 0) displayHour = 12;
            string suffix = (hour < 12) ? " AM" : " PM";
            return (displayHour < 10 ? "0" + to_string(displayHour) : to_string(displayHour)) + ":" +
                   (minute < 10 ? "0" + to_string(minute) : to_string(minute)) + ":" +
                   (second < 10 ? "0" + to_string(second) : to_string(second)) + suffix;
        }
        return Clock::getTime();
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
    cout << simple_Clock.getTime() << endl;  // After adding a second
    simple_Clock.setClock(23, 59, 59);
    cout << simple_Clock.getTime() << endl;  // Set time to one second before midnight
    simple_Clock.addSecond();
    cout << simple_Clock.getTime() << endl;  // Midnight
    simple_Clock.addSecond();
    cout << simple_Clock.getTime() << endl;  // One second after midnight

    cout << "\nAlarm Clock:" << endl;
    AlarmClock simple_alarmClock(12, 5, 0);
    simple_alarmClock.setAlarm(12, 5, 1);  // Setting alarm time
    cout << simple_alarmClock.getTime() << endl;  // Initial time
    simple_alarmClock.addSecond();
    cout << simple_alarmClock.getTime() << endl;  // After adding a second, should trigger alarm
    simple_alarmClock.setClock(2, 3, 0);
    cout << simple_alarmClock.getTime() << endl;  // New time set
    simple_alarmClock.setClock(23, 59, 59);
    cout << simple_alarmClock.getTime() << endl; 
    simple_alarmClock.addSecond(); // One second before
    cout << simple_alarmClock.getTime() << endl;  // One second after midnight

    cout << "Clock without alarm:" << endl;
    cout << simple_Clock.getTime() << endl;  
    simple_Clock.addSecond();
    cout << simple_Clock.getTime() << endl;  // After adding a second
    simple_Clock.setClock(23, 59, 59);
    cout << simple_Clock.getTime() << endl;  // Set time to one second before midnight
    simple_Clock.addSecond();
    cout << simple_Clock.getTime() << endl;  // Midnight
    simple_Clock.addSecond();
    cout << simple_Clock.getTime() << endl;  // One second after midnight

}

