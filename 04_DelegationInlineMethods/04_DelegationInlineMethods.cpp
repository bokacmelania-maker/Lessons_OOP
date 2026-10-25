#include <iostream>
#include <string>
using namespace std;

//#define PI 3.14;

//inline void Hello()
//{
//    cout << "hello" << endl;
//}  

/*
class Human{
    string name;
    int age;
    int weight;
public:
     static int count_humans;
    static int getCount(){ return count_humans;}
Human(){
        name = "no name";
        age = 0;
        weight = 0;}

//список ініціалізаторів//Human() :name{ "no name" }, age{ 0 }, weight{ 0 }

Human() :name("no name"), age(0), weight(0) { count_humans++; }

Human(string name) :Human(){
        this->name = name;
        // age = 0;
        //weight = 0;
   }
Human(string name, int age):Human(name){
        //this->name = name;
        this->age = age;
        //this->weight = 0;
}
Human(string name, int age, int weight):Human(name, age){
        //this->name = name;
        //this->age = age;
        this->weight = weight;
}
void Print(){
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Weight : " << weight << endl;
        cout << endl << endl;
}
   
};//-------------------------

int Human::count_humans = 0;
*/

//Завдання 1 :(практична робота на уроці)
//Створіть додаток «Телефонна книга».Необхідно збері -
//гати дані про абонента(ПІБ, домашній телефон, робочий
//телефон, мобільний телефон, додаткова інформація про
//контакт) всередині відповідного класу(Abonent).Наповніть клас
//змінними - членами, функціями - членами, конструкторами.
//Створити статичну змінну для
//кількості абонентів.Використати делегування конструкторів.

class Abonent {
private:
    string last_name{};
    string first_name{};
    string patronymic{};
    string home_phone{};
    string work_phone{};
    string mobile_phone{};
    string contact_information{};

    static int count_abonent;//кількість створених абонентів
public:
    static int getCount(){
        return count_abonent; 
    }
    
// конструктор за замовчуванням(цільовий для делегування):задає значення полів(список ініціалізації)
    Abonent():last_name("no name"), first_name("no first name"), patronymic("no patronymic"),home_phone("no home phone"), work_phone("no work phone "), mobile_phone("no mobile phone"), contact_information("no contact information"){count_abonent++;}
//делегування
// делегуючий конструктор : цільовий Abonent()
    Abonent(string last_name, string first_name, string patronymic) : Abonent() {
        this->last_name = last_name;//присвоюємо значення параметра полю класу.
        this->first_name = first_name;
        this->patronymic = patronymic;
    }
// У дужках ПЕРШИХ (параметри) пишемо типи: старі параметри + нові, у тому ж порядку.
// Після двокрапки ДРУГІ  (виклик попереднього конструктора) ТИПИ НЕ пишемо, тільки імена старих параметрів.
// У тілі присвоюємо(this) тільки нові поля.
    Abonent(string last_name, string first_name, string patronymic,
        string home_phone, string work_phone, string mobile_phone)
        : Abonent(last_name, first_name, patronymic) {
        this->home_phone = home_phone;
        this->work_phone = work_phone;
        this->mobile_phone = mobile_phone;
    }
    Abonent(string last_name, string first_name, string patronymic,
        string home_phone, string work_phone, string mobile_phone, string contact_information) :
        Abonent(last_name, first_name, patronymic, home_phone, work_phone, mobile_phone) {
        this->contact_information = contact_information;
    }

    void Print() {
        cout << "last name: " << last_name << endl;
        cout << "first name: " << first_name << endl;
        cout << "patronymic: " << patronymic << endl;
        cout << "home phone: " << home_phone << endl;
        cout << "work phone: " << work_phone << endl;
        cout << "mobile phone: " << mobile_phone << endl;
        cout << "contact information: " << contact_information << endl;
        cout << endl << endl;
    }

};//---
int Abonent::count_abonent = 0;// ініціалізація static-змінної(створюється один раз, поза класом;виділяє пам'ять, початкове значення 0)

int main()
{
//Завдання 1
    cout << "Count abonents: " << Abonent::getCount() << endl;
    Abonent::getCount();

    Abonent a1; //без параметрів
    a1.Print();
    cout << "Count abonents: " << a1.getCount() << endl;

    Abonent a2("Anna","Boslavska","Olecsiivna");
    a2.Print();
    cout << "Count abonents: " << a2.getCount() << endl;

    Abonent a3("Shevchenko", "Taras", "Hryhorovych","0362123456", "0362654321", "0501234567");
    a3.Print();
    cout << "Count abonents: " << a3.getCount() << endl;

    Abonent a4("Franko", "Ivan", "Yakovych","0362111111", "0362222222", "0503333333","Colleague from work");
    a4.Print();
    cout << "Count abonents:" << a4.getCount() << endl;





 /*
    cout << "Count humans : " << Human::getCount() << endl;
    Human::getCount();


    Human h1;    
    h1.Print();
   
    cout << "Count humans : "<< h1.getCount() << endl;

    Human h2("Oleg");
    h2.Print();
    cout << "Count humans : " << h2.getCount() << endl;


    Human h3("Ivan", 17);
    h3.Print();
    cout << "Count humans : " << h1.getCount() << endl;
    cout << "Count humans : " << h2.getCount() << endl;
    cout << "Count humans : " << h3.getCount() << endl;
    cout << "Count humans : " << Human::getCount() << endl;



    Human h4("Mukola", 47, 89);
    h4.Print();
    cout << "Count humans : " << h4.count_humans << endl;


    Human::count_humans = 0;
    cout << "Count humans : " << Human::count_humans << endl;

    //cout << "hello" << endl;// Hello();
    //cout << 3.14;// Hello();

 
    */
}
