#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Lesson{
protected:
    int number;       
    string subject;    
    string teacher;    
    string form; 
public:
    Lesson(int number, string subject, string teacher, string form){
        this->number = number;
        this->subject = subject;
        this->teacher = teacher;
        this->form = form;
    }
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