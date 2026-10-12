#include <iostream>
#include <fstream>
#include <string>////
using namespace std;
/*
struct Player
{
    string name;
    short age;
    int games;
    int goals;
};
void PrintPlayer(Player &pl)
{
    cout << "Name:" << pl.name << endl;
    cout << "Age:" << pl.age << endl;
    cout << "Games:" << pl.games << endl;
    cout << "Goals:" << pl.goals << endl;
}
void InitPlayer(Player& pl) {
    cout << "Enter name"; cin >> pl.name;
    cout << "Enter age"; cin >> pl.age;
    pl.games = 0;
    pl.goals = 0;
}
void AddGameToPlayer(Player& pl, int goals = 0) {
    pl.games++;
    pl.goals += goals;

}
*/

//class Player {
//private:
//    string name;
//    short age;
//    int games;
//    int goals;
//
//public:
//    void PrintPlayer()
//    {
//        cout << "Name:" << name << endl;
//        cout << "Age:" <<age << endl;
//        cout << "Games:" << games << endl;
//        cout << "Goals:" << goals << endl;
//    }
//    void InitPlayer() {
//        cout << "Enter name"; cin >> name;
//        cout << "Enter age"; cin >> age;
//        games = 0;
//        goals = 0;
//    }
//    void AddGameToPlayer( int goalss = 0) {
//        games++;
//        this ->goals  += goalss; //
//    }
//};
//
//
//class Student {
//private:
//    string name; // data member
//    int marks[3];
//
//public:
//    //setter
//    void setName(string name) {
//        this->name = name;     //
//    }
//    void setMark(int index, int mark) {
//        if (mark >= 1 && mark <= 12) {
//            marks[index] = mark;
//        }
//        else {
//            marks[index] = 0;
//        }
//    }
//    //getter
//
//    string  getName() {
//        return name;
//    }
//
//    int getMark(int index) {
//        return marks[index];
//    }
// 
//
//    double getAverange() {// member function, функції-члени класу методт
//        double summa = 0;
//        for (int i = 0; i < 3; i++)
//        {
//            summa += marks[i];
//        }
//        return (double)summa / 3;
//    }
//};

//

//2 Реалізуйте клас «Точка».Необхідно зберігати координати
//    x, y, z в змінних - членах класу.Реалізуйте функції - члени
//    класу для введення даних, виведення даних, реалізуйте
//    аксесор для доступу до змінних - членів, реалізуйте збе -
//    реження в файл і завантаження даних з файлу.

class Point {

private:
    int x = 10;
    int y = 5;
    int z = 67;

public:
    void PrintPoint()
    {
        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
        cout << "z: " << z << endl;
    }
    void InitPoint() {   
        cout << "Enter x: " ; cin >> x;
        cout << "Enter y: " ; cin >> y;
        cout << "Enter z: " ; cin >> z;
    }
    //setter
    void set_x(int x) {
        this->x = x;
    }
    void set_y(int y) {
        this->y = y;
    }
    void set_z(int z) {
        this->z = z;
    }
    //getter
    int get_x(){
        return x; }
    int get_y(){
        return y; }
    int get_z(){
        return z; }
    
    void save_to_file(const  string& filename) {
        ofstream out(filename);
        if (out.is_open()) {
            out << x << " " << y << " " << z << endl;
            out.close();
            cout << "Save to file!" << endl;
        }
        else {
            cout << "Error, not save to file!" << endl;
        }
    }
    
    void load_from_file(const string& filename) {
        ifstream in(filename);
        if (in.is_open()) {
            if (in >> x >> y >> z) {     
                cout << "File load" << endl;
            }  
        }
        else {  
            cout << "Error file isn't load" << endl;
        }
        in.close();
    }
};

/* 1 Реалізуйте клас «Студент».Необхідно зберігати в
змінних - членах класу : ПІБ, дату народження, контактний
телефон, місто, країну, назву навчального закладу, місто
та країну(де знаходиться навчальний заклад), номер
групи.
Реалізуйте функції - члени класу для введення даних, виведення даних, реалізуйте аксесор для доступу до
окремих змінних - членів.*/

class New_Student
{
private:
   string name = "Olena";
   string last_name = "Kovalenko";
   string patronymic = "Ihorivna";
   string birth = "02.02.2002";
   string phone_number = "+380971234567";
   string city = "Rivne";
   string country = "Ukraine";
   string school_name = "Lviv Polytechnic National University";
   string school_city = "Lviv";
   string school_country = "Ukraine";
   string group_number = "SE-21";
public:
    void PrintNew_Student()
    {
        cout << "First name: " << name << endl;
        cout << "Last name: " << last_name << endl;
        cout << "Patronymic: " << patronymic << endl;
        cout << "Birth: " << birth << endl;
        cout << "Phone: " << phone_number << endl;
        cout << "City: " << city << endl;
        cout << "Country: " << country << endl;
        cout << "School: " << school_name << endl;
        cout << "School city: " << school_city << endl;
        cout << "School country: " << school_country << endl;
        cout << "Group: " << group_number << endl;
    }
    void InitNew_Student() {
        cout << "Enter name: ";             getline(cin, name);
        cout << "Enter last name: ";        getline(cin, last_name);
        cout << "Enter patronymic: ";       getline(cin, patronymic);
        cout << "Enter birth date: ";       getline(cin, birth);
        cout << "Enter phone: ";            getline(cin, phone_number);
        cout << "Enter city: ";             getline(cin, city);
        cout << "Enter country: ";          getline(cin, country);
        cout << "Enter school name: ";      getline(cin, school_name);
        cout << "Enter school city: ";      getline(cin, school_city);
        cout << "Enter school country: ";   getline(cin, school_country);
        cout << "Enter group number: ";     getline(cin, group_number);
    }
    // реалізуйте аксесор для доступу окремих змінних - членів.
    
    //setter
    void set_name(const string& name) {
        this->name = name;
    }
    void set_last_name(const string& last_name) {
        this->last_name = last_name;
    }
    void set_patronymic(const string& patronymic) {
        this->patronymic = patronymic;
    }
    void set_birth(const string& birth) {
        this->birth = birth;
    }
    void set_phone_number(const string& phone_number) {
        this->phone_number = phone_number;
    }
    void set_city(const string& city) {
        this->city = city;
    }
    void set_country(const string& country) {
        this->country = country;
    }
    void set_school_name(const string& school_name) {
        this->school_name = school_name;
    }
    void set_school_city(const string& school_city) {
        this->school_city = school_city;
    }
    void set_school_country(const string& school_country) {
        this->school_country = school_country;
    }
    void set_group_number(const string& group_number) {
        this->group_number = group_number;
    }

    //getter
    string get_name() {
        return name;
    }
    string get_last_name() {
        return last_name;
    }
    string get_patronymic() {
        return patronymic;
    }
    string get_birth() {
        return birth;
    }
    string get_phone_number() {
        return phone_number;
    }
    string get_city() {
        return city;
    }
    string get_country() {
        return country;
    }
    string get_school_name() {
        return school_name;
    }
    string get_school_city() {
        return school_city;
    }
    string get_school_country() {
        return school_country;
    }
    string get_group_number() {
        return group_number;
    }
   
   
};




int main(){
    //1
    New_Student n;
    n.PrintNew_Student();  
    n.InitNew_Student();
    n.PrintNew_Student();

    //2
    Point point;
    point.InitPoint();
    point.save_to_file("point.txt");

    Point new_point;                      
    new_point.load_from_file("point.txt");
    new_point.PrintPoint();



  /*  Student st;
    st.setName  ("Ivan");
    st.setMark(0, 10);
    st.setMark(1, 11);
    st.setMark(5, 1);

    cout << "Name:" << st.getName() << "Marks:" << st.getMark(0) << " " <<
        st.getMark(1) << " " << st.getMark(2) << endl;

    cout << "Averange mark: " << st.getAverange() << endl;


    Player player;
    player.InitPlayer();
    player.PrintPlayer();
    player.AddGameToPlayer(3);
    player.PrintPlayer();*/


    //Player player;
    //InitPlayer(player);
    //PrintPlayer(player);
    //AddGameToPlayer(player,1);
    //AddGameToPlayer(player,2);
    //PrintPlayer(player);

}