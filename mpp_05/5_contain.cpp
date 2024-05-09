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

    int getNumber() const {
        return number;
    }

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
    void addLesson(const string& day, Lesson* lesson) {
        schedule[day].push_back(lesson);
    }

    void addLessons(const string& day, const vector<Lesson*>& lessons) {
        for (const auto& lesson : lessons) {
            schedule[day].push_back(lesson);
        }
    }

    void removeLesson(const string& day, int number) {
        auto& lessons = schedule[day];
        for (size_t i = 0; i < lessons.size(); ++i) {
            if (lessons[i]->getNumber() == number) {
                delete lessons[i];
                lessons.erase(lessons.begin() + i);
                break;
            }
        }
    }

    void print() const {
        const string daysOrder[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

        for (const string& day : daysOrder) {
            auto it = schedule.find(day);
            if (it != schedule.end()) {
                cout << day << ":" << endl;
                for (const auto& lesson : it->second) {
                    lesson->print();
                    cout << endl;
                }
            }
        }
    }

    ~Schedule() {   
        for (auto& entry : schedule) {
            for (auto& lesson : entry.second) {
                delete lesson;
            }
        }
    }

private:
    map<string, vector<Lesson*>> schedule;
};

int main() {
    Schedule weekSchedule;

    weekSchedule.addLessons("Monday", {
        new Lesson(1, "Mathematics", "Mr. Smith", "Lecture"),
        new Lesson(2, "Biology", "Ms. Green", "Lab"),
        new Lesson(3, "Physics", "Mr. Johnson", "Lecture"),
        new Lesson(4, "Chemistry", "Dr. Brown", "Lecture"),
        new Lesson(5, "English", "Ms. White", "Lecture")
    });

    weekSchedule.addLessons("Tuesday", {
        new Lesson(2, "History", "Mr. Black", "Lecture"),
        new Lesson(3, "Computer Science", "Ms. Blue", "Lab")
    });


    weekSchedule.addLessons("Wednesday", {
        new Lesson(1, "Mathematics", "Mr. Smith", "Lecture"),
        new Lesson(2, "Biology", "Ms. Green", "Lab"),
        new Lesson(3, "Physics", "Mr. Johnson", "Lecture"),
        new Lesson(4, "Chemistry", "Dr. Brown", "Lecture"),
        new Lesson(5, "English", "Ms. White", "Lecture"),
        new Lesson(8, "History", "Mr. Carter", "Lecture")
    });
    weekSchedule.addLesson("Thursday", new SpecializedLesson(2, "Physics", "Dr. Brown", "Lab", "Room 101", 90));
    weekSchedule.addLesson("Friday", new SpecializedLesson(1, "Chemistry", "Mrs. White", "Lab", "Room 102", 90));

    cout << "Initial schedule:" << endl;
    weekSchedule.print();

    cout << "Removing Wednesday's lesson (8):" << endl;
    weekSchedule.removeLesson("Wednesday", 8);

    weekSchedule.print();

    return 0;
}
