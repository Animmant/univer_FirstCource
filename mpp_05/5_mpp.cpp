#include <iostream>
#include <string>
#include <vector>

using namespace std;

class timeTable{
protected:
    string day;
    public:
    timeTable(string day){
        this->day = day;
    }
    virtual void display() = 0;
    virtual void setAlarm() = 0;
    virtual void removeAlarm() = 0;
};

class programistTimeTable_programist : public timeTable{
    private:
    string alarm;
    public:
    programistTimeTable(string day, string alarm) : timeTable(day){
        this->alarm = alarm;
    }}

};
int main(){
    
    cout << "timeTable without alarm:" << endl;
    vector;




}