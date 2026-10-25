#include <iostream>
#include <string>
using namespace std;

//class Date {
//public:
//    int day;
//    int month;
//    int year;
//
//  Date(int day, int month, int year)
//    {
//        if (day > 0 and day <= 31)
//            this->day = day;
//    }
//    void setDate(int day)
//    {
//        this->day = day;
//    }
//    int getDay()
//    {
//        day += 10;
//        return day;
//    }
//    int getDay()const//  не міняє поля які належать this  
//    {
//
//        return day;
//    }
//    void Print()const
//    {
//        cout << "Date : " << day << "/" << month << "/" << year << endl;
//    }
//};
//class Account {
//private:
//    double sum;
//    const double rate;
//public:
//    Account(double sum, double rate) : rate(rate)
//    {
//        this->sum = sum;
//    }
//    double getRate()const
//    {
//        return rate;
//    }
//    double getIncome()
//    {
//        return sum * rate / 100;
//    }
//    double getIncome()const
//    {
//        return sum * rate / 100;
//    }
//    double getSum()const
//    {
//        return sum;
//    }
//    double setSum()
//    {
//        sum += getIncome();
//        return sum;
//    }
//};
//
//void doSomething(long number)
//{
//
//}
//float doSomething() { return 1.5; }
//
//class Array
//{
//    int* arr;
//    int size;
//public:
//    Array()
//    {
//        size = 0;
//        arr = nullptr;
//    }
//    explicit Array(int size)
//    {
//        this->size = size;
//        arr = new int[size];
//    }
//    Array(int size, int num)
//    {
//        this->size = size;
//        arr = new int[size];
//    }
//    ~Array()
//    {
//        if (arr != nullptr)
//            delete[]arr;
//    }
//    int getSize()const
//    {
//        return size;
//    }
//    int getValue(int index)
//    {
//        return arr[index];
//    }
//    void setValue(int num, int index)
//    {
//        arr[index] = num;
//    }
//    void display(int index)const
//    {
//        cout << arr[index] << " ";
//    }
//
//};
//void PrintArray(const Array& arr)
//{
//    for (int i = 0; i < arr.getSize(); i++)
//    {
//        arr.display(i);
//    }
//    cout << endl;
//}
//void Print(string name)
//{
//
//}
//void Test(int a) {}

//1
class Book {
private:
    string author;
    string title;
    string publisher;
    int number;
    int year;
    int pages;

public: 
    explicit Book(string author, string title, string publisher, int number, int year, int pages) {

        this->author = author;
        this->title = title;
        this->publisher = publisher;
        this->number = number;
        this->year = year;
        this->pages = pages;
    }
    void Print()const {
        cout << "Author: " << author << endl;
        cout << "Title: " << title << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Number: " << number << endl;
        cout << "Year: " << year << endl;
        cout << "Pages: " << pages << endl;
        cout << endl;
  }

    string get_author() const { return author;}
    string get_title() const { return title;}
    string get_publisher() const { return publisher;}
    int get_number() const { return number; }
    int get_year() const { return year; }
    int get_pages() const { return pages; }

};//------------

void Search_by_author(const Book arr[], int size, const string& author) { // через int 
    
    int found{};
    for (int i = 0; i < size; i++)
    {
        if (arr[i].get_author() == author) {
            arr[i].Print();
            found++;
        }
    }
    if (found == 0) {
        cout << "No books with this author found " << endl;
    }
}
void Search_by_publisher(const Book arr[], int size, const string& publisher) {  // через bool

    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].get_publisher() == publisher) {
            arr[i].Print();
            found = true;
        }
    }
    if (!found) {
        cout << "No books with this publisher found " << endl;
    }
}
void Search_after_year(const Book arr[], int size, const int& year) {
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].get_year() > year) {
            arr[i].Print();
            found = true;
        }
    }
    if (!found) {
        cout << "No books after year " << year << " found" << endl; 
    }
}



int main()
{
//Завдання 1
//Створіть клас Book.Необхідно зберігати дані : автор,
//назва, видавництво, рік, кількість, сторінок.
//Створити масив об’єктів.Вивести :
//? список книг заданого автора;
//? список книг, випущених заданим видавництвом;
//? список книг, випущених після заданого року.
//Використовуйте explicit - конструктор і константні
//функції - члени(наприклад, для відображення даних про
//книгу і т.д.

    const int size = 5;
    Book arr[size] = {
        Book("J.R.R. Tolkien", "The Hobbit", "George Allen & Unwin", 1, 1937, 310),
        Book("J.K. Rowling", "Harry Potter and the Philosopher's Stone", "Bloomsbury", 2, 1997, 223),
        Book("Jane Austen", "Pride and Prejudice", "Modern Library", 3, 2000, 320),
        Book("F. Scott Fitzgerald", "The Great Gatsby", "Scribner", 4, 2004, 180),
        Book("Ernest Hemingway", "The Old Man and the Sea", "Scribner", 5, 1995, 128)
    };

    Search_by_author(arr, size, "Jane Austen");
    Search_by_publisher(arr, size, "Scribner");
    Search_after_year(arr, size, 1990);




/*
    Print("khsfjksdd");
    Print(77);
    Test(100);
    Test("ksdgskdjg");
    int size = 4;
    Array arr(size);
    for (int i = 0; i < arr.getSize(); i++)
    {
        arr.setValue(size - i, i);
    }
    PrintArray(arr);
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    Explicit
    PrintArray(8);// implicit int ---> Array неявне перетворення 

    Array a = 100;
    PrintArray(a);

    Array r(5, 77);
    Array t = 8, 99;


    int a = 3.14; //implicit   double ---> int//implicit double->int звужуюче пеертворення
    cout << a << endl;

    double b(10);// implicit int --> double// implicit int-> double;   розширяється перетворення
    cout << b << endl;

    doSomething(5);//// implicit  int --> long


    float pi = (float)3.14;//explicit
    
    Account account1(2000, 5);


    const Account account2(5000, 8);

    cout << account1.getRate() << endl;
    cout << account2.getRate() << endl;

    cout << account1.getSum() << endl;
    cout << account2.getSum() << endl;

    cout << account1.getIncome() << endl;
    cout << account2.getIncome() << endl;

    cout << account1.setSum() << endl;
    cout << account2.setSum() << endl;error

    const int size = 5;
    const int month[3]{ 31,31,28 };
    month[0] = 45;

    Date holidayDate{ 25,10,2026 };
    holidayDate.Print();
    holidayDate.setDate(19);
    holidayDate.Print();

    holidayDate.day = 31;
    holidayDate.Print();

    holidayDate.getDay();

    const Date independencyDay{ 24,8,2027 };
   independencyDay.Print();
    independencyDay.day = 25;
    independencyDay.setDate(19);
    independencyDay.getDay();
     independencyDay.Print();
     */


}
