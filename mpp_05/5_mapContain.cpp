#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Lesson {
public:
    Lesson(int number, const string& subject, const string& teacher, const string& form)
        : number(number), subject(subject), teacher(teacher), form(form) {}

    virtual void print() const {
        cout << "Lesson Number: " << number << ", Subject: " << subject
             << ", Teacher: " << teacher << ", Form: " << form << endl;
    }

    int getNumber() const { return number; }

protected:
    int number;
    string subject;
    string teacher;
    string form;
};

class SpecializedLesson : public Lesson {
public:
    SpecializedLesson(int number, const string& subject, const string& teacher, const string& form, const string& room, int duration)
        : Lesson(number, subject, teacher, form), room(room), duration(duration) {}

    void print() const override {
        Lesson::print();
        cout << "Room: " << room << ", Duration: " << duration << " minutes" << endl;
    }

private:
    string room;
    int duration;
};

class Schedule {
public:
    Schedule(const vector<Lesson>& initialLessons) : lessons(initialLessons) {}

    void addLesson(const Lesson& lesson) {
        lessons.push_back(lesson);
    }

    void print() const {
        for (const auto& lesson : lessons) {
            lesson.print();
            cout << endl;
        }
    }

    void removeLesson(int number) {
        auto it = lessons.begin();
        while (it != lessons.end()) {
            if (it->getNumber() == number) {
                lessons.erase(it);
                return;
            }
            ++it;
        }
    }



private:
    vector<Lesson> lessons;
};

map<string, Schedule> weekSchedule;


void initializeWeekSchedule() {
    weekSchedule["Monday"].addLesson(Lesson(1, "Mathematics", "Mr. Smith", "Lecture"));
    weekSchedule["Monday"].addLesson(Lesson(2, "Biology", "Ms. Green", "Lab"));
    weekSchedule["Monday"].addLesson(Lesson(3, "History", "Mr. Brown", "Lecture"));
    weekSchedule["Monday"].addLesson(Lesson(4, "Mathematics", "Mr. Smith", "Lecture"));
    weekSchedule["Monday"].addLesson(Lesson(5, "Biology", "Ms. Green", "Lab"));
    weekSchedule["Tuesday"].addLesson(Lesson(3, "History", "Mr. Brown", "Lecture"));
    weekSchedule["Wednesday"].addLesson(Lesson(4, "Geography", "Ms. White", "Lecture"));
    weekSchedule["Thursday"].addLesson(SpecializedLesson(5, "Physics", "Dr. Brown", "Lab", "Room 101", 90));
    weekSchedule["Friday"].addLesson(SpecializedLesson(6, "Chemistry", "Mrs. White", "Lab", "Room 102", 90));
}




/*

void initializeWeekSchedule() {    weekSchedule["Monday"].addLessons({
        Lesson(1, "Mathematics", "Mr. Smith", "Lecture"),
        Lesson(2, "Biology", "Ms. Green", "Lab")
    });
    weekSchedule["Tuesday"].addLessons({
        Lesson(3, "History", "Mr. Brown", "Lecture")
    });
    weekSchedule["Wednesday"].addLessons({
        Lesson(4, "Geography", "Ms. White", "Lecture")
    });
    weekSchedule["Thursday"].addLessons({
        SpecializedLesson(5, "Physics", "Dr. Brown", "Lab", "Room 101", 90)
    });
    weekSchedule["Friday"].addLessons({
        SpecializedLesson(6, "Chemistry", "Mrs. White", "Lab", "Room 102", 90)
    });
}
*/

int main() {
    initializeWeekSchedule();

    cout << "Weekly Schedule:" << endl;
    for (const auto& pair : weekSchedule) {
        cout << pair.first << ":" << endl;
        pair.second.print();
    }

    weekSchedule["Monday"].addLesson(Lesson(7, "English", "Mrs. Green", "Lecture"));
    weekSchedule["Tuesday"].removeLesson(3);

    cout << endl << "Updated Weekly Schedule:" << endl;
    for (const auto& pair : weekSchedule) {
        cout << pair.first << ":" << endl;
        pair.second.print();
    }

    return 0;
}
