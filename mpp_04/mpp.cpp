#include <iostream>
#include <string>

using namespace std;

class Clock{
    public:
    Clock(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}
    void setAlarm(int h, int m, int s){
        hour = h;
        minute = m;
        second = s;
    }
    void addSecond(){
        second += 1;
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

private:
    int alarm_hour, alarm_minute, alarm_second;
    bool military_format;
};


int main(){

    Clock time_without_light(12, 35, 0);
    string currentTime = time_without_light.getTime();
    time_without_light.addSecond();
    cout << time_without_light.getTime() << endl;
    return 0;
}

