#include <iostream>
#include <vector>
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
    SpecializedLesson(int number, const string& subject, const string& teacher, const string& form,
                      const string& room, int duration)
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
    void addLesson(const Lesson& lesson) {
        lessons.push_back(lesson);
    }

    void addSpecializedLesson(const SpecializedLesson& lesson) {
        specializedLessons.push_back(lesson);
    }

    void removeLesson(int number) {
        for (size_t i = 0; i < lessons.size(); ++i) {
            if (lessons[i].getNumber() == number) {
                lessons.erase(lessons.begin() + i);
                return;
            }
        }
    }

    void removeSpecializedLesson(int number) {
        for (size_t i = 0; i < specializedLessons.size(); ++i) {
            if (specializedLessons[i].getNumber() == number) {
                specializedLessons.erase(specializedLessons.begin() + i);
                return;
            }
        }
    }

    void print() const {
        cout << "Weekly Schedule:" << endl;
        for (const auto& lesson : lessons) {
            lesson.print();
        }

        for (const auto& specLesson : specializedLessons) {
            specLesson.print();
        }
    }

private:
    vector<Lesson> lessons;
    vector<SpecializedLesson> specializedLessons;
};

int main() {
    Schedule weekSchedule;

    Lesson lesson1(1, "Mathematics", "Mr. Smith", "Lecture");
    SpecializedLesson lesson2(2, "Physics", "Dr. Brown", "Lab", "Room 101", 90);
    SpecializedLesson lesson3(3, "Chemistry", "Mrs. White", "Lab", "Room 102", 90);

    weekSchedule.addLesson(lesson1);
    weekSchedule.addSpecializedLesson(lesson2);
    weekSchedule.addSpecializedLesson(lesson3);

    weekSchedule.print();

    cout << "\nRemoving lesson 2:\n";
    weekSchedule.removeSpecializedLesson(2);
    weekSchedule.print();

    return 0;
}
