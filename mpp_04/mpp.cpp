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
        AlarmClock(int h = 0, int m = 0, int s = 0) : alarm_hour(h), alarm_minute(m), alarm_second(s) {}

private:
    int alarm_hour, alarm_minute, alarm_second;
    bool military_format;
};


int main(){

    Clock time_without_light(1, 3, 0);
    
    cout << time_without_light.getTime() << endl;
    time_without_light.addSecond();
    cout << time_without_light.getTime() << endl;
    time_without_light.setClock(2, 3, 59);
    cout << time_without_light.getTime() << endl;
    time_without_light.addSecond();
    cout << time_without_light.getTime() << endl;


    AlarmClock time_with_light(12, 5, 0);
    cout << time_with_light.getTime() << endl;
    time_with_light.addSecond();
    cout << time_with_light.getTime() << endl;
    time_with_light.setClock(2, 3, 0);
    cout << time_with_light.getTime() << endl;

    return 0;
}

