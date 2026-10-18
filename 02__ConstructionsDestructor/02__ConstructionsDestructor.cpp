#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//struct Date
//{
//	int day;
//	int month;
//	int year;
//	void PrintDate()
//	{
//		cout << "Birthdate : " << day << "/"
//			<< month << "/" << year << endl;
//	}
//};
//class Student
//{
//	string name;
//	string surname;
//	string middlename;
//	Date birthdate;
//	string phone;
//	int* marks;
//	int countMarks;
//	float averageMark;
//	void AverageMark()
//	{
//		double summa = 0;
//		for (int i = 0; i < countMarks; i++)
//		{
//			summa += marks[i];
//		}
//		averageMark = summa / countMarks;
//	}
//public:
//	//ctor + TAB
//	Student()//methods 
//	{
//		cout << "Default constructor" << endl;
//		name = "no name";
//		surname = "no surname";
//		middlename = "no middlename";
//		birthdate = { 1,1,1 };
//		phone = "no phone";
//		marks = nullptr;
//		countMarks = 0;
//		averageMark = 0;
//	}
//	Student(string name, string surname, string middlename)
//	{
//		cout << "Parametrized constructor" << endl;
//		this->name = name;
//		this->surname = surname;
//		this->middlename = middlename;
//		birthdate = { 1,1,1 };
//		phone = "no phone";
//		marks = nullptr;
//		countMarks = 0;
//		averageMark = 0;
//	}
//	void AddMark(int mark)
//	{
//		int* temp = new int[countMarks + 1];
//		for (int i = 0; i < countMarks; i++)
//		{
//			temp[i] = marks[i];
//		}
//		temp[countMarks] = mark;
//		if (marks != nullptr)
//			delete[]marks;
//		marks = temp;
//		countMarks++;
//		AverageMark();
//
//
//	}
//	void Print()
//	{
//		cout << "Name : " << name << endl;
//		cout << "Surname : " << surname << endl;
//		cout << "MiddleName : " << middlename << endl;
//		birthdate.PrintDate();
//		cout << "Phone : " << phone << endl;
//		cout << "Marks : ";
//		for (int i = 0; i < countMarks; i++)
//		{
//			cout << marks[i] << " ";
//		}
//		cout << "\nAverage Mark : " << averageMark << endl;
//
//	}
//	void setName(string name) { this->name = name; }
//	void setLastName(string surname) { this->surname = surname; }
//	void Initialization()
//	{
//		name = "no name";
//		surname = "no surname";
//		middlename = "no middlename";
//		birthdate = { 1,1,1 };
//		phone = "no phone";
//		marks = nullptr;
//		countMarks = 0;
//		averageMark = 0;
//	}
//	~Student()
//	{
//		cout << "Destructor" << name << endl;
//		if (marks != nullptr)
//			delete[]marks;
//	}
//};


//1
//—творити клас Rectangle, €кий буде описувати пр€мокутник.
//  лас м≥стить розм≥ри : ширина, висота, символ, €кий в≥дображатиме пр€мокутник на екран≥ 
// та координати розм≥щенн€.
// ƒл€ збереженн€ координат створити структуру Coord, €ка м≥ститиме X та Y координату.
struct Coord
{
	int x;
	int y;
};
class MyRectangle
{
private:
	int width;
	int height;
	char symbol;
	Coord coordinates;

public:

	// лас повинен м≥стити наступн≥ конструктори

	//Х онструктор по замовчуванню, €кий встановлюватиме Ђдефолтн≥ї дан≥

	// онструктор за замовчуванн€м н≥чого не бере в≥д користувача
	//викликаЇтьс€ без аргумент≥в
	MyRectangle() {
		width = 10;
		height = 5;
		symbol = '=';
		coordinates.x = 0; // ƒоступ до пол≥в структури через крапку
		coordinates.y = 0;
	}

	//Хѕараметризований конструктор, 
	// €кий приймаЇ один параметр Ђрозм≥рї та ≥н≥ц≥ал≥зуЇ ним ширину та висоту

	// ≤н≥ц≥ал≥зувати = задати зм≥нн≥й початкове значенн€ при створенн≥
	//(викликаЇтьс€ з аргументом ) 

	MyRectangle(int size) {
		if (size > 0) {
			width = size;	//тод≥ тут буде значенн€ задане корисувачем
			height = size;	// висота дор≥внюЇ ширин≥  буде - квадрат
		}
		else {
			cout << "Incorrect value" << endl;
			width = 8;	// тут програмою за замовчуванн€м, €кщо користувач введе хибну умову
			height = 4;
		}
		symbol = '=';
		coordinates.x = 0;
		coordinates.y = 0;
	}

	//Хѕараметризований конструктор, €кий приймаЇ два параметри Ђширинуї та Ђвисотуї, 
	// €к≥ €вл€ютьс€ розм≥рами обТЇкта
	//ƒан≥ в≥д користувача приймаЇ саме параметризований.

	// лог≥ка €к в size
	MyRectangle(int w, int h) {
		if (w > 0 and h > 0) {
			width = w;
			height = h;
		}
		else {
			cout << "Incorrect value" << endl;
			width = 6;
			height = 3;
		}
		symbol = '=';
		coordinates.x = 0;
		coordinates.y = 0;
	}


	//“а наступн≥ методи :

	//Х¬ив≥д ф≥гури на екран, в≥дпов≥дного розм≥ру, символом та у в≥дпов≥дних координатах

	void Show_Rectangle()
	{
		for (int i = 0; i < coordinates.y; i++)
		{
			cout << endl;
		}
		for (int i = 0; i < height; i++)
		{
			for (int k = 0; k < coordinates.x; k++)
			{
				cout << " ";
			}
			for (int j = 0; j < width; j++)
			{
				cout << symbol;
			}
			cout << endl;
		}
	}

	//Х	«м≥на розм≥ру пр€мокутника.ћетод приймаЇ два парметри : 1 Ц зм≥на висоти, 2 Ц ширини

	void New_Size(int h, int w) {
		if (h > 0 and w > 0) {
			height = h;
			width = w;
		}
		else {
			cout << "Incorrect value" << endl;
		}
	}

	//Х	ѕерем≥щенн€ пр€мокутника. ћетод приймаЇ два парметри: 1 Ц величина перем≥щенн€ по ос≥ X, 2 Ц по ос≥ Y
	void move(int x, int y) {
		if (coordinates.x + x >= 0 && coordinates.y + y >= 0) {
			coordinates.x += x;
			coordinates.y += y;
		}
		else {
			cout << "Incorrect value" << endl;
		}
	}
};

//2

//—творити клас Student €кий буде м≥стити характеристики : ≥мТ€, в≥к, колекц≥€ оц≥нок,
// к≥льк≥сть оц≥нок та середню оц≥нку.

class Student {
private:
	string name;
	int age;
	int* marks;
	int count_marks;
	float average_mark;

	//3.SetAverageMark() Ц приватний метод дл€ обрахунку та
	// встановленн€ середньоњ оц≥нки студента(викликаЇтьс€
	// всередин≥ класа при додаванн≥ оц≥нки)
	void SetAverageMark() {
		float temp = 0;
		for (int i = 0; i < count_marks; i++)
		{
			temp += marks[i];
			average_mark = temp / count_marks;
		}
	}

public:
	//¬ клас≥ повинн≥ буди реал≥зован≥ наступн≥ конструктори :

	//Х	 онструктор по замовчуванню() Ц встановлюватиме початков≥ дан≥
	Student() {
		name = "Mark";
		age = 18;
		marks = nullptr;
		count_marks = 0;
		average_mark = 0;
	}
	//Х	ѕараметризований конструктор(const char* name, int age) Ц 
	// ≥н≥ц≥ал≥зуЇ клас значенн€ми з параметр≥в
	Student(const char* name, int age) {
		this->name = name;
		if (age > 0) {
			this->age = age;
		}
		else {
			cout << "Age cannot be negative and 0  " << endl;
			this->age = 18;

		}
		marks = nullptr; //дл€ вказ≥вник≥в 0 не пишуть , а пишуть nullptr!.
		count_marks = 0;
		average_mark = 0;
	}
	//“акож створити деструктор дл€ зв≥льненн€ ресурс≥в та наступн≥ методи :
	~Student()
	{
		cout << "Destructor " << name << endl;
		if (marks != nullptr)
			delete[]marks;
	}
	//1.Print() Ц виводить ≥нформац≥ю про студента на екран
	void Print() {
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "Marks : ";
		for (int i = 0; i < count_marks; i++)
		{
			cout << marks[i] << " ";
		}
		cout << "\nAverage Mark : " << average_mark << endl;
	}
	//2.AddMark(int mark) Ц додаЇ оц≥нку дл€ студента
	void AddMark(int mark) {
		int* temp = new int[count_marks + 1];
		for (int i = 0; i < count_marks; i++)
		{
			temp[i] = marks[i];
		}
		temp[count_marks] = mark;
		if (marks != nullptr)
			delete[]marks;
		marks = temp;
		count_marks++;
		SetAverageMark();
	}
	//4.	Save() Ц збереженн€ студента в файл
	void Save()
	{
		ofstream out("Student.txt", ios_base::out);
		if (out.is_open()) {
			out << name << endl;
			out << age << endl;
			out << count_marks << endl;
			for (int i = 0; i < count_marks; i++) {
				out << marks[i] << " ";
			}
			out << endl;
			out.close();
			cout << "File saved" << endl;
		}
		else {
			cout << "Error" << endl;
		}
	}

	//5.Load() Ц зчитуванн€ студента в файла
	void Load() {
		ifstream in("Student.txt", ios_base::in);
		if (in.is_open())
		{
			getline(in, name);
			in >> age;
			int temp;
			in >> temp;

			if (marks != nullptr)
				delete[]marks;
			marks = nullptr;
			count_marks = 0;
			average_mark = 0;

			for (int i = 0; i < temp; i++) {
				int mark;
				in >> mark;
				AddMark(mark);
			}
			in.close();
			cout << "File loaded" << endl;

		}
		else {
			cout << "Error" << endl;
		}
	}

	//«абезпечити клас необх≥дними методами дл€ доступа до властивостей(getters, setters).ѕо можливост≥ застосувати делегуванн€ конструктор≥в.

	//getters
	string getName()
	{
		return name;
	}
	int getAge()
	{
		return age;
	}
	int* getMarks()
	{
		return marks;
	}
	int getCount_marks()
	{
		return count_marks;
	}
	float getAverage_mark()
	{
		return average_mark;
	}

	// setters
	void setName(string name) {
		this->name = name;
	}
	void setAge(int age) {
		if (age > 0) {
			this->age = age;
		}
		else {
			cout << "Error age" << endl;
		}
	}
};//




int main()
{
	//2

	Student s1("Anton", 20);

	s1.AddMark(10);
	s1.AddMark(5);
	s1.AddMark(8);
	s1.AddMark(2);

	s1.Print();

	s1.Save();
	s1.Load();
	s1.Print();

	cout << s1.getName() << endl;
	cout << s1.getAge() << endl;
	cout << s1.getCount_marks() << endl;
	cout << s1.getAverage_mark() << endl;


	s1.setName("Vania");
	s1.setAge(19);
	s1.setAge(-99);
	s1.Print();






	//1
			//MyRectangle r1;                
			//r1.Show_Rectangle();
			//MyRectangle r2(5);   
			//cout << endl;
			//r2.Show_Rectangle();
			//MyRectangle r3(10, 4); 
			//cout << endl;
			//r3.move(1, 4);
			//r3.Show_Rectangle();
			//r3.New_Size(3, 8);          
			//r3.Show_Rectangle();
			//MyRectangle r4(-10);
			//cout << endl;
			//r4.Show_Rectangle();
			//MyRectangle r5(-2, 4);
			//cout << endl;
			//r5.Show_Rectangle();
			//r3.move(-9, 0);
			//cout << endl;
			//r3.New_Size(0, -1);
			//r3.Show_Rectangle();
			//MyRectangle r6(9, 4);
			//cout << endl;
			//r6.Show_Rectangle();



		//Student student;//default constrcutor
		////student.Initialization();
		//student.Print();
		//student.setName("Anton");
		//student.setLastName("Chugun");
		//student.AddMark(2);
		//student.AddMark(4);
		//student.AddMark(6);
		//student.AddMark(3);
		//student.Print();

		//Student st2("Vasia", "Ivanchuk", "Mukolayouvich");
		//st2.AddMark(7);
		//st2.AddMark(12);
		//st2.AddMark(8);
		//st2.AddMark(9);
		//st2.Print();

		//if (5 > 2)
		//{
		//	Student test("Boria", "Slipuy", "Nimuy");//Parametrized constructor
		//	test.AddMark(10);
		//	test.AddMark(11);
		//	test.AddMark(9);
		//	test.AddMark(8);
		//	test.Print();
		//}
	//







}
