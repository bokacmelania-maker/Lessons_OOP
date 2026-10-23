#include <iostream>
#include <cstdlib>
using namespace std;

//Classwork
// 
//struct Point
//{
//	int x;
//	int y;
//};
//
//class Student
//{
//private:
//	string name;
//	int age;
//	int* marks;
//	int countMarks;
//public:	
//	Student()
//	{
//		this->name = "no name";
//		this->age = 0;
//		this->marks = nullptr;
//		this->countMarks = 0;
//
//	}
//	Student(string name, int age) {
//		this->name =name;  //
//		this->age = age;   //
//		this->marks = nullptr;
//		this->countMarks = 0;
//	}
// 	//конструктор копіювання 
//	Student(const Student& other) {
//		this->name = other.name;
//		this->age = other.age;
//		this->countMarks = other.countMarks;
//		//this->marks = other.marks;
//		this->marks = new int[countMarks];
//		for (int i = 0; i < countMarks; i++)
//		{
//			this->marks = other.marks;
//		}
//	}
//	void Addmark(int mark) {
//		int* temp = new int[countMarks + 1];
//		for (int i = 0; i < countMarks; i++)
//		{
//			temp[i] = marks[i];
//		}
//		temp[countMarks] = mark;
//		if (marks != nullptr) {
//		delete[]marks;
//		}
//		marks = temp;
//		countMarks++;
//	}
//	void Delete() {
//		if (marks != nullptr) {
//			delete[]marks;
//		}
//	}
//	void Print() {
//		cout << "Name:" << name << endl;
//		cout << "Age:" << age << endl;
//		cout << "Count marks:" << countMarks << endl;
//		cout << "Marks:";
//		for (int i = 0; i < countMarks; i++)
//		{
//			cout << marks[i] << " ";
//		}
//		cout << endl;
//	}
//	~Student()
//	{
//		Delete;
//	}
//};

//Конструктор копіювання, вказіник this
//Завдання 1:
//Створіть клас Array – це клас динамічного масиву чисел з певним функціоналом(початковий шаблон завантажено в Slack).
// Властивостями класа буде вказівник на сам масив(long* arr) та його теперішній розмір(int size).

class Array
{
private:
	long* arr;
	int size;
public:
//Клас повинен дозволяти наступний функціонал :

//•	Заповнити масив значеннями(випадковими, з клавіатури або ж по замовчуванню)

//випадковими
	void Fill_random_arr(){
		if (arr == nullptr || size <= 0) {
			cout << "Error, arr and size must be greater that 0 " << endl;
			return;
		}
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 100;
		}
	}

//з клавіатури
	void Fill_keyboard_arr()
	{
		if (arr == nullptr || size <= 0) {
			cout << "Error, arr and size must be greater that 0 " << endl;
			return;
		}
		for (int i = 0; i < size; i++)
		{
			cout << "Enter number " << i << ": "; // щоб бачити який по рахунку вводимо(показ. індекс)
			cin >> arr[i];
		}
	}

//по замовчуванню
	void Fill_default_arr(long value = 67)
	{
		if (arr == nullptr || size <= 0) {
			cout << "Error, arr and size must be greater that 0 " << endl;
			return;
		}
		for (int i = 0; i < size; i++)
		{
			arr[i] = value;
		}
	}

//•	Відображати вміст масиву
	void Print_arr()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

//•	Додавати елемент в масив
	void New_element_end(long new_el_end)
	{
		long* temp = new long[size + 1];
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		temp[size] = new_el_end;

		if (arr != nullptr) {
			delete[] arr;
		}
		arr = temp;
		size++;
	}

//•	Видаляти елемент з масива:

// по значенню 
	void Delete_by_value(long value)
	{
		if (arr == nullptr || size <= 0) {
			cout << "Error, arr and size must be greater that 0 " << endl;
			return;
		}
	
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == value) {
				return Delete_index(i);
			}
		}
		cout << "Error, element not found" << endl;
	}

//  по індексу	
	void Delete_index(int index)
	{
		if  (arr == nullptr || size <= 0 || index < 0 || index >= size) { 
			cout << "Error, arr, size and index(<size) must be greater that 0 " << endl;
			return;
		}
		long* temp = new long[size - 1];
		int j = 0;
		for (int i = 0; i < size; i++)
		{
			if (i != index) {
				temp[j] = arr[i];
				j++;
			}
		}
		delete[] arr;
		arr = temp;
		size--;
	}

//•	Відсортувати масив(по спаданню / зростанню)

// по спаданню
	void Decline_Sort(){
		long temp;
		for (int i = 0; i < size; i++){
		for (int j = size - 1; j > i; j--){
			if (arr[j - 1] < arr[j]){
					temp = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = temp;
			}
		}
	}
}

// зростанню
	void Growth_Sort(){
		long temp;
		for (int i = 0; i < size-1; i++){
		for (int j = 0; j < size -1 - i; j++){
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//•	Визначати значення(мінімальне, максимальне або середнє арифметичне)

// мінімальне, максимальне
	void min_max(){
		if (arr == nullptr || size <= 0) {
			cout << "Error, arr and size must be greater that 0 " << endl;
			return;
		}
		long min_number = arr[0];
		int min_index = 0;
		long max_number = arr[0];
		int max_index = 0;

		for (int i = 1; i < size; i++) {
			if (arr[i] < min_number) {
				min_number = arr[i];
				min_index = i;
			}
			if (arr[i] > max_number) {
				max_number = arr[i];
				max_index = i;
			}
		}
		cout << "Min: " << min_number << "\nIndex min: " << min_index << endl;
		cout << "Max: " << max_number << "\nIndex max: " << max_index << endl;
	}

// середнє арифметичне
	void Average(){
		if (arr == nullptr || size <= 0) {
			cout << "Error, arr and size must be greater that 0 " << endl;
			return;
		}
		int sum = 0;
		for (int i = 0; i < size; i++){
			sum += arr[i];
		}
		cout << "Average: " << sum / size << endl;
		
	}

//Також передбачити набір конструкторів :

//•	Конструктор за замовчуванням, який встановлювтиме початкові значення
	Array(){
		arr = nullptr;
		size = 0;
	}

//•	Конструктор, який прийматиме розмір масиву та заповнюватиме нулем всі елементи
	Array(int size){
		if (size <= 0) {
			arr = nullptr;
			this->size = 0;
			cout << "Size must be greater than 0" << endl;
			return;
		}
		this->size = size;
		arr = new long[size];
		for (int i = 0; i < size; i++){
			arr[i] = 0;
		}
	}

//•	Конструктор копіювання, який буде копіювати всі дані об'єкта включаючи масив
	Array(const Array& other){
		size = other.size;
		if (size <= 0) {
			arr = nullptr;
			size = 0;
			return;
		}
		arr = new long[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = other.arr[i];
		}
	}

//Також реалізувати деструктор в класі для уникнення втрати пам’яті.

// Деструктор
	~Array(){
		delete[] arr;
	}


};//-------------------------------------------------------------

int main(){
	srand(time(0));

//Конструктор копіювання, вказіник this
//Завдання 1:

  
	Array a1(3); 
	a1.Print_arr();
	a1.Fill_random_arr(); 

	a1.Print_arr();          
	a1.Delete_index(0); 

	a1.Print_arr();
	a1.Delete_by_value(10);      

	a1.Fill_keyboard_arr();
	a1.Print_arr();

	a1.Fill_default_arr();
	a1.Print_arr();

	a1.New_element_end(9);
	a1.Print_arr();

	Array a2(4);
	a2.Fill_keyboard_arr();
	a2.Print_arr();

	a2.Decline_Sort();
	a2.Print_arr();

	a2.Growth_Sort();
	a2.Print_arr();

	a2.min_max();

	a2.Average();
	
	Array a3;
	a3.Fill_default_arr();
	a3.Print_arr();

	Array a4(4);
	a4.Fill_default_arr();
	a4.Print_arr();

	a4.Delete_by_value(2);
	a4.Print_arr();

	Array a5(5);
	a5.Print_arr();

	Array a0(6);
	a0.Fill_random_arr();
	a0.Print_arr();

	Array a6(a0);
	a6.Print_arr();


	//Classwork
	// 
	//Student st;
	//st.Print();
	//Student student("Ivan", 18);
	//student.Addmark(11);
	//student.Addmark(2);
	//student.Addmark(8);
	//student.Print();
	//Student copy = Student(student);
	//cout << "Org: " << endl;
	//student.Print();
	//cout << "Copy" << endl; 
	//copy.Print();

	//Point point{ 15,25 };
	//int number = 2;	//ініціалізація з копіюванням 
	//
	//int value(2);// пряма ініціалізація
	//
	//int size{ 33 };// уніфікована ініціалізація
	////int size{ 33.33 };// помилка втрата даних додатково перевіряє
	//cout << number << endl;
	//cout << value << endl;
	//cout << size << endl;
	//int answer{5};
	////int answer = 5;
	//const float goodTemp{ 36.6 };
	//int marks[3]{ 1,2,3 };
	//int matrix[2][2]{ {1,2},{3,4} };
	//int* dataPtr{ nullptr };

} //

