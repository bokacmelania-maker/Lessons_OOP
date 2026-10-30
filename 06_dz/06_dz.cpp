#include <iostream>
using namespace std;

//—творити клас ЂTimeї, €кий буде описувати час 3 - ма характеристиками : години, хвилини, секунди.
class Time {
private:
	int hours{};
	int minutes{};
	int seconds{};

public:
//	¬ клас≥ потр≥бно реал≥зувати наступн≥ конструктори :
//Х	 онструктор по замовчуванню() Ц встановлюватиме початков≥ дан≥
	Time() {
		hours,minutes,seconds = 0;
	}
//Х	ѕараметризований(hours, minutes, seconds) Ц встановлюЇ кожну властив≥сть
	Time(int h, int m, int s) {
		hours = h;
		minutes = m;
		seconds = s;
	}
//Х	ѕараметризований(seconds) Ц створюЇ клас перев≥вши дану к≥льк≥сть секунд в години, хвилини, секунди
// .Ќаприклад : 5555 = 1год 32хв 35сек
//Х	5555 / 3600 - h; 5555 / 60 % 60 Ц m; 5555 % 60 - s	
//	¬икористайте explicit дл€ де€ких конструктор≥в.	
	explicit Time(int seconds) {
		this -> hours = seconds / 3600;
		this -> minutes = (seconds / 60) % 60;
		this -> seconds = seconds % 60;
	}

//1 ¬иводу часу на екран в формат≥ hh : mm:ss
friend void Print(const Time& time);

//2.«б≥льшенн€ часу на одну секунду(11:59 : 59)++ -> 12 : 00 : 00
	Time& operator++() {
		seconds++;
		if (seconds == 60) {
			seconds = 0;
			minutes++;
		}
		if (minutes == 60) {
			minutes = 0;
			hours++;
		}
		return *this;
	}
	Time operator++(int) {
		// Time перед temp це тип даних
		Time temp = *this; //Time temp = *this; створюЇ нову зм≥нну з ≥менем temp, 
		//€ка Ї об'Їктом класу Time, ≥ кладе в нењ коп≥ю *this.
		++(*this);
		return temp;
	}

	int Total_count_of_sec() const {
		return hours * 3600 + minutes * 60 + seconds;
	}

// лас повинен мати перевантаженн€ наступних б≥нарних оператор≥в :
//Х + Ц * / виконуЇтьс€ певна арифметична операц≥€ з часом та повертаЇтьс€ результат у вигл€д≥ нового об'Їкту Time
	Time operator + (const Time& other) const {
		return Time(this -> Total_count_of_sec() + other.Total_count_of_sec());
	}					    
	Time operator - (const  Time& other) const {
		return Time(this -> Total_count_of_sec() - other.Total_count_of_sec());
	}					    
	Time operator * (const  Time& other) const {
		return Time(this -> Total_count_of_sec() * other.Total_count_of_sec());
	}					    
	Time operator / (const  Time& other) const {
		return Time(this -> Total_count_of_sec() / other.Total_count_of_sec());
	}

//Х > < >= <=	перев≥р€Їтьс€, €кий обТЇкт м≥стить б≥льшу / меншу к≥льк≥сть часу та повертаЇтьс€ результат у вигл€д≥ типу bool

	bool operator > (const Time& other) const {
		return this -> Total_count_of_sec() > other.Total_count_of_sec();
	}
	bool operator < (const Time& other) const {
		return this -> Total_count_of_sec() < other.Total_count_of_sec();
	}			    
	bool operator >= (const Time& other) const {
		return this -> Total_count_of_sec() >= other.Total_count_of_sec();
	}			    
	bool operator <= (const Time& other) const {
		return this -> Total_count_of_sec() <= other.Total_count_of_sec();
	}
//Х	==  перев≥р€Їтьс€ чи класи мають не / однаковий час
	bool operator == (const Time& other) const {
		return this -> Total_count_of_sec() == other.Total_count_of_sec();
	}			    
	bool operator!= (const Time& other) const {
		return this  -> Total_count_of_sec() != other.Total_count_of_sec();
	}
};

void Print(const Time& time) { // функц≥€ не належить об'Їкту, тому об'Їкт передаЇмо параметром; через нього читаЇмо пол€ (доступ до private даЇ friend)time
	if (time.hours < 10) cout << "0";
	cout << time.hours << ":";
	if (time.minutes < 10) cout << "0";
	cout << time.minutes << ":";
	if (time.seconds < 10) cout << "0";
	cout << time.seconds << endl;
}

int main() {
	//«авданн€ 1 :
	Time t;
	cout << "t0: ";Print(t);

	Time t1(12,60,33);
	cout << "t1: ";Print(t1);

	Time t2(1111);
	cout << "t2: "; Print(t2);

	cout << "prefix: ";
	Time time3(10, 59, 29);
	++time3; 
	Print(time3);

	cout << "posfix: ";
	Time time4(12, 9, 20);
	time4++; 
	Print(time4);

	Time result1 = t1 + t2;
	cout << "t1 + t2: "; Print(result1);

	Time result2 = t1 - t2;
	cout << "t1 - t2: "; Print(result2);

	Time result3 = t1 / t2;
	cout << "t1 / t2: "; Print(result3);

	Time result4 = t1 * t2;
	cout << "t1 * t2: "; Print(result4);

	cout << boolalpha; // переводить 0/1 на True/False
	cout << "t2 < t1: " << (t2 < t1) << endl;
	cout << "t2 > t1: " << (t2 > t1) << endl;
	cout << "t2 <= t1: " << (t2 <= t1) << endl;
	cout << "t2 >= t1: " << (t2 >= t1) << endl;
	cout << "t2 != t1: " << (t2 != t1) << endl;
	cout << "t2 == t1: " << (t2 == t1) << endl;

}



	
  

