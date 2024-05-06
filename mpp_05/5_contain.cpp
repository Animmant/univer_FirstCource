#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Lesson {
public:
    Lesson(int number, const string& subject, const string& teacher, const string& form)
        : number(number), subject(subject), teacher(teacher), form(form) {}

    void print() const {
        cout << "Lesson Number: " << number << ", Subject: " << subject
             << ", Teacher: " << teacher << ", Form: " << form << endl;
    }

protected:
    int number;        // Номер пари
    string subject;    // Предмет
    string teacher;    // Прізвище викладача
    string form;       // Форма заняття
};

class SpecializedLesson : public Lesson {
public:
    SpecializedLesson(int number, const string& subject, const string& teacher, const string& form,
                      const string& room, int duration)
        : Lesson(number, subject, teacher, form), room(room), duration(duration) {}

    void print() const {
        Lesson::print(); // Викликаємо метод базового класу
        cout << "Room: " << room << ", Duration: " << duration << " minutes" << endl;
    }

private:
    string room;      // Додаткове поле: кімната
    int duration;     // Додаткове поле: тривалість заняття
};

class Schedule {
public:
    void addLesson(const Lesson& lesson) {
        lessons.push_back(lesson);
    }

    void addSpecializedLesson(const SpecializedLesson& lesson) {
        specializedLessons.push_back(lesson);
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
    vector<Lesson> lessons;                 // Вектор звичайних занять
    vector<SpecializedLesson> specializedLessons; // Вектор спеціалізованих занять
};

int main() {
    Schedule weekSchedule;

    Lesson lesson1(1, "Mathematics", "Mr. Smith", "Lecture");
    SpecializedLesson lesson2(2, "Physics", "Dr. Brown", "Lab", "Room 101", 90);

    weekSchedule.addLesson(lesson1);
    weekSchedule.addSpecializedLesson(lesson2);

    weekSchedule.print();

    return 0;
}
