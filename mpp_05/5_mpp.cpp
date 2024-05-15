#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Lesson{
protected:
    int number;       
    string subject;    
    string teacher;    
    string form; 
public:
    Lesson(int number, string subject, string teacher, string form)
        : number(number), subject(subject), teacher(teacher), form(form) {}
};

class 

};
int main(){
    
    const Lesson math(1, "Math", "Mr. Smith", "10A");
    cout << math << endl;




}