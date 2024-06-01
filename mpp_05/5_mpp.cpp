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
    Schedule(const vector<Lesson>& initialLessons = {}) : lessons(initialLessons) {}
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
    weekSchedule["Monday"] = Schedule({
        Lesson(1, "Mathematics", "Dr. Smith", "Lecture"),
        Lesson(2, "Physics", "Dr. Brown", "Lab"),
        Lesson(3, "Chemistry", "Dr. White", "Lecture"),
        Lesson(4, "History", "Mr. Black", "Seminar")
    });

    weekSchedule["Tuesday"] = Schedule({
        Lesson(1, "Biology", "Dr. Green", "Lecture"),
        Lesson(2, "Computer Science", "Dr. Blue", "Lab"),
        Lesson(3, "Physical Education", "Coach Red", "Exercise"),
        Lesson(4, "Art", "Ms. Yellow", "Workshop")
    });

    weekSchedule["Wednesday"] = Schedule({
        Lesson(1, "English", "Ms. Violet", "Lecture"),
        Lesson(2, "Economics", "Dr. Indigo", "Lecture"),
        Lesson(3, "Philosophy", "Dr. Grey", "Seminar"),
        Lesson(4, "Music", "Mr. Pink", "Workshop")
    });

    weekSchedule["Thursday"] = Schedule({
        Lesson(1, "Geography", "Dr. Orange", "Lecture"),
        Lesson(2, "Literature", "Ms. Purple", "Seminar"),
        Lesson(3, "Sociology", "Dr. Gold", "Lecture"),
        Lesson(4, "Drama", "Ms. Silver", "Workshop")
    });

    weekSchedule["Friday"] = Schedule({
        Lesson(1, "Statistics", "Dr. White", "Lecture"),
        Lesson(2, "Programming", "Dr. Black", "Lab"),
        Lesson(3, "Robotics", "Dr. Brown", "Lab"),
        Lesson(4, "Health", "Dr. Green", "Seminar")
    });
}

void printAllSchedule() {
    const vector<string> days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    for (const auto& day : days) {
        cout << day << ":" << endl;
        weekSchedule[day].print();
    }
}

void displayMenu() {
    cout << "1. Display Weekly Schedule\n"
         << "2. Add a Lesson\n"
         << "3. Remove a Lesson\n"
         << "4. Exit\n"
         << "Select an option: ";
}

bool isValidDay(const string& day) {
    return weekSchedule.find(day) != weekSchedule.end();
}

void handleAddLesson() {
    string day;
    int number, duration;
    string subject, teacher, form, room;

    cout << "Enter day: ";
    cin >> day;
    if (!isValidDay(day)) {
        cout << "Invalid day entered. Please try again." << endl;
        return;
    }

    cout << "Enter lesson number: ";
    cin >> number;
    cout << "Enter subject: ";
    cin.ignore();
    getline(cin, subject);
    cout << "Enter teacher: ";
    getline(cin, teacher);
    cout << "Enter form: ";
    getline(cin, form);
    cout << "Is it a specialized lesson? (y/n): ";
    char isSpecialized;
    cin >> isSpecialized;
    cin.ignore(); 
    if (isSpecialized == 'y') {
        cout << "Enter room: ";
        cin.ignore();
        getline(cin, room);
        cout << "Enter duration (in minutes): ";
        cin >> duration;
        weekSchedule[day].addLesson(SpecializedLesson(number, subject, teacher, form, room, duration));
    } else {
        weekSchedule[day].addLesson(Lesson(number, subject, teacher, form));
    }
}

void handleRemoveLesson() {
    string day;
    int number;

    cout << "Enter day: ";
    cin >> day;
    if (!isValidDay(day)) {
        cout << "Invalid day entered. Please try again." << endl;
        return;
    }

    cout << "Enter lesson number to remove: ";
    cin >> number;
    weekSchedule[day].removeLesson(number);
}

void handleMenuOption() {
    int option;
    cin >> option;

    switch (option) {
    case 1:
        printAllSchedule();
        break;
    case 2:
        handleAddLesson();
        break;
    case 3:
        handleRemoveLesson();
        break;
    case 4:
        cout << "Exiting program." << endl;
        exit(0);
    default:
        cout << "Unknown option." << endl;
        break;
    }
}



int main() {
    initializeWeekSchedule();

    cout << "Weekly Schedule:" << endl;
    printAllSchedule();

    weekSchedule["Monday"].addLesson(Lesson(7, "English", "Mrs. Green", "Lecture"));
    weekSchedule["Tuesday"].removeLesson(3);

    cout << endl << "Updated Weekly Schedule:" << endl;
    printAllSchedule();

    while (true) {
        displayMenu();
        handleMenuOption();
    }

    return 0;
}