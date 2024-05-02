#include<iostream>
#include<string>

using namespace std;



class Book{
public:
    Book(const string& title, const string& author, const int& year) : title(title), author(author), year(year) {};

    void setTitle(const string& title) {
        this->title = title;
    }
    void setAuthor(const string& author) {
        this->author = author;
    }
    void setYear(const int& year) {
        this->year = year;
    }

    string getTitle()  {
        return title;
    }
    string getAuthor()  {
        return author;
    }
    int getYear() {
        return year;
    }
     
    //  train
    virtual void print()  {
        cout << "Title: " << title << ", Author: " << author
             << ", Year: " << year  << endl;
    }
    void show() { cout << "show base class\n"; }
protected:
string title;
string author;
int year;
};

class Manga : public Book {
public:
    Manga(const string& title, const string& author, const int& year) : Book(title, author, year) {}

    void print() override { cout << "print derived class\n"; }
    void show() { cout << "show base class\n"; }
};


class Encyclopedia : public Book {
public:
    Encyclopedia(const string& title, const string& author, const int& year, const int& series)
        : Book(title, author, year), series(series) {}

    void setSeries(int s) {
        series = s;
    }

    int getSeries() const {
        return series;
    }

    void print() override {
        cout << "Title: " << title << ", Author: " << author
             << ", Year: " << year << ", Series: " << series << endl;
    }

private:
    int series;
};
/*
class Dog : public Book {
public:
Dog(const string& title) : Book(title) {}}

};
class Dog : public Book {
public:
Dog(const string& title) : Book(title) {}
    void voice() {
        cout << "Woof woof" << endl;
    }
    void walk() {
        cout << "The dog is going for a walk" << endl;
    }
};

class Cat : public Book {
public:
Cat(const string& title) : Book(title) {}
    void voice() {
        cout << "mauy" << endl;
    }
    void hunt() {
        cout << "A cat hunts a mouse" << endl;
    }
};
*/

int main(){

    Manga myManga("Naruto", "Masashi Kishimoto", 1999);
    myManga.print(); // Перевірка методу похідного класу

    printf("\n");

    Encyclopedia myEncyclopedia("The Great Soviet Encyclopedia", "Soviet Academy of Sciences", 1974, 31);
    myEncyclopedia.print(); // Перевірка методу похідного класу

    printf("\n");

    Book history("The Count of Monte Cristo", "Alexandre Dumas", 1844);
    cout << history.getTitle() << endl;
    cout << history.getAuthor() << endl;
    cout << history.getYear() << endl;

    history.setTitle("The Three Musketeers");
    history.setAuthor("Alexandre Dumas");
    history.setYear(1844);

    cout << "After changes:" << endl;
    cout << history.getTitle() << endl;
    cout << history.getAuthor() << endl;
    cout << history.getYear() << endl;

    Book historyc("The Count of Monte Cristo", "Alexandre Dumas", 1844);
    cout << historyc.getTitle() << endl;
    cout << historyc.getAuthor() << endl;
    cout << historyc.getYear() << endl;

    historyc.setTitle("The Three Musketeers");
    historyc.setAuthor("Alexandre Dumas");
    historyc.setYear(1844);

    cout << "After changes:" << endl;
    cout << historyc.getTitle() << endl;
    cout << historyc.getAuthor() << endl;
    cout << historyc.getYear() << endl;

    return 0;
}
