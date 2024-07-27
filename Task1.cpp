#include<iostream>
#include<fstream>
using namespace std;
int length(const char* ptr) {
	if (ptr == nullptr) {
		return 0;
	}
	int count = 0;
	for (int i = 0; ptr[i] != '\0'; i++) {
		count++;
	}
	return count;
}
char* copy(const char* _ptr) {
	if (_ptr == nullptr) {
		return nullptr;
	}
	int l = length(_ptr);
	char* newPtr = new char[l + 1];
	for (int i = 0; i < l + 1; i++) {
		newPtr[i] = _ptr[i];
	}
	return newPtr;
}
bool compare(const char* ptr1, const char* ptr2) {
	if (length(ptr1) == length(ptr2)) {
		for (int i = 0; i < length(ptr1); i++) {
			if (ptr1[i] != ptr2[i]) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}

class MyString {
private:
	char* ptr;

public:
	MyString() {
		ptr = nullptr;
	}

	MyString(const char* _ptr) {
		ptr = copy(_ptr);
	}

	MyString(const MyString& other) {
		ptr = copy(other.ptr);
	}

	void setString(const char* _ptr) {
		delete[] ptr;
		ptr = copy(_ptr);
	}

	bool operator==(const MyString& d) const {
		return compare(d.ptr);
	}

	char* getString()const {
		return copy(ptr);
	}

	void input() {
		ptr = new char[100];
		//cout << "Enter the value in array: " << endl;
		cin.getline(ptr, 100, '\n');
	}

	void display() const {
		cout << ptr << endl;
	}

	void append(const char* _ptr) {
		int l1 = count(ptr);
		int l2 = count(_ptr);
		int l = l1 + l2;
		char* str = new char[l + 1];
		for (int i = 0; i < l1; i++) {
			str[i] = ptr[i];
		}
		for (int i = l1; i < l + 1; i++) {
			str[i] = _ptr[i - l1];
		}
		delete[] ptr;
		ptr = copy(str);
		delete[] str;
	}

	int count(const char* _ptr)const {
		if (_ptr == nullptr) {
			return 0;
		}
		int counter = 0;
		for (int i = 0; _ptr[i] != '\0'; i++) {
			counter++;
		}
		return counter;
	}

	int count() const {
		if (ptr == nullptr) {
			return 0;
		}
		int counter = 0;
		for (int i = 0; ptr[i] != '\0'; i++) {
			counter++;
		}
		return counter;
	}

	bool compare(const char* _ptr) const {
		if (length(ptr) == length(_ptr)) {
			for (int i = 0; i < count(ptr); i++) {
				if (ptr[i] != _ptr[i]) {
					return false;
				}
			}
			return true;
		}
		else {
			return false;
		}
	}

	bool isEmpty() const {
		return (ptr == nullptr);
	}

	MyString operator+(const MyString& d) const {
		MyString result = ptr;
		result.append(d.ptr);
		return result;
	}

	bool operator!=(const MyString& d) const {
		return !compare(d.ptr);
	}

	bool operator<(const MyString& d) const {
		return (compare(d.ptr) < 0);
	}

	bool operator>(const MyString& d) const {
		return (compare(d.ptr) > 0);
	}

	bool operator<=(const MyString& d) const {
		return (*this == d || *this < d);
	}

	bool operator>=(const MyString& d) const {
		return (*this == d || *this > d);
	}

	const MyString& operator=(const MyString& d) {
		if (this != &d) {
			delete[] ptr;
			ptr = copy(d.ptr);
		}
		return *this;
	}

	MyString operator++() {
		if (ptr != nullptr) {
			int len = count(ptr);
			for (int i = 0; i < len; i++) {
				ptr[i]++;
			}
		}
		return *this;
	}

	MyString operator++(int) {
		MyString result(*this);
		if (ptr != nullptr) {
			int len = count(ptr);
			for (int i = 0; i < len; i++) {
				ptr[i]++;
			}
		}
		return result;
	}

	MyString operator--() {
		if (ptr != nullptr) {
			int len = count(ptr);
			for (int i = 0; i < len; i++) {
				ptr[i]--;
			}
		}
		return *this;
	}

	MyString operator--(int) {
		MyString result(*this);
		if (ptr != nullptr) {
			int len = count(ptr);
			for (int i = 0; i < len; i++) {
				ptr[i]--;
			}
		}
		return result;
	}

	~MyString() {
		delete[] ptr;
	}
};

istream& operator>>(istream& rd, MyString& a) {
	char* Str = new char[100];
	//cout << "Enter String: " << endl;
	rd.getline(Str, 100, '\n');
	a.setString(Str);
	delete[] Str;
	return rd;
}

ostream& operator<<(ostream& wr, const MyString& a) {
	wr << a.getString() << endl;
	return wr;

}

MyString concatenate(MyString& a, MyString& b) {
	int l1 = a.count(a.getString());
	int l2 = b.count(b.getString());
	int l = l1 + l2;
	char* temp = new char[l + 1];
	char* str = copy(a.getString());
	char* str2 = copy(b.getString());
	for (int i = 0; i < l1; i++) {
		temp[i] = str[i];
	}
	for (int i = l1; i < l + 1; i++) {
		temp[i] = str2[i - l1];
	}
	MyString result(temp);
	delete[] str;
	delete[] str2;
	delete[] temp;
	return result;
}
bool isEqual(MyString& a, MyString& b) {
	return a.compare(b.getString());
}

void increment(int& sz, MyString*& dp) {
	MyString* nd = new MyString[sz + 1];
	if (dp != nullptr) {
		for (int i = 0; i < sz; i++) {
			nd[i] = dp[i];
		}
		delete[] dp;
	}
	dp = nd;
}

void input(int& no, MyString*& d) {
	cout << "How many Strings will you enter: ";
	cin >> no;
	if (d != nullptr) {
		delete[] d;
	}
	cin.ignore();
	d = new MyString[no];
	for (int i = 0; i < no; i++) {
		cin >> d[i];
	}
}

MyString* copyName(const MyString* const& other, const int& size) {
	MyString* name = new MyString[size];
	for (int i = 0; i < size; i++) {
		name[i] = other[i];
	}
	return name;
}
int* copySalary(const int* const& other,const int& size) {
	int* salary = new int[size];
	for (int i = 0; i < size; i++) {
		salary[i] = other[i];
	}
	return salary;
}
float* copyCgpa(const float* const& other, const int& size) {
	float* cgpa = new float[size];
	for (int i = 0; i < size; i++) {
		cgpa[i] = other[i];
	}
	return cgpa;
}
void readMyStringsFromFile(MyString*& d, int& no, const char* p) {
	ifstream fin(p);
	char s[100];
	for (int i = 0; fin >> s; i++) {
		increment(no, d);
		d[i] = MyString(s);
	}
}

void writeMyStringsToFile(MyString* d, int& no, const char* p) {
	ofstream fout(p);
	fout << no << " ";
	for (int i = 0; i < no; i++) {
		fout << d[i] << " ";
	}
}

void verifyMyStringsFiles(MyString* d, int& no, const char* p) {
	MyString* copyD = nullptr;
	int sz = 0;
	readMyStringsFromFile(copyD, sz, p);
	for (int i = 0; i < no; i++) {
		if (isEqual(d[i], copyD[i])) {
			cout << d[i] << " == " << copyD[i] << " is true \n";
		}
		else {
			cout << d[i] << " == " << copyD[i] << " is false \n";
		}
	}
}

class Person {
public:
	Person() :firstName{}, secondName{}, dateOfBirth{}, address{} {
		numPerson = 0;
	}
	Person(const int& _numPerson,const MyString*& _firstName,const MyString*& _secondName,const MyString*& _dateOfBirth,const MyString*& _address){
		numPerson = _numPerson;
		firstName = copyName(_firstName,numPerson);
		secondName = copyName(_secondName,numPerson);
		dateOfBirth = copyName(_dateOfBirth,numPerson);
		address = copyName(_address,numPerson);
	}
	Person(const Person& other) {
		numPerson = other.numPerson;
		firstName = copyName(other.firstName, numPerson);
		secondName = copyName(other.secondName, numPerson);
		dateOfBirth = copyName(other.dateOfBirth, numPerson);
		address = copyName(other.address, numPerson);
	}
	~Person() {
		delete[]firstName;
		delete[]secondName;
		delete[]dateOfBirth;
		delete[]address;
		cout << "Person Destructor is Called" << endl;
	}
	void setNumPerson(const int& _numPerson) {
		numPerson = _numPerson;
	}
	int getNumPerson()const {
		return numPerson;
	}
	bool operator==(const Person& other) {
		if (numPerson == other.numPerson) {
			for (int i = 0; i < numPerson; i++) {
				if (firstName[i] != other.firstName[i]||secondName[i] != other.secondName[i]||
					dateOfBirth[i] != other.dateOfBirth[i]||address[i] != other.address[i]) {
								return false;
				}
			}
			return true;
		}
		else {
			return false;
		}
	}
	bool operator!=(const Person& other) {
		return !(*this == other);
	}
	const Person& operator=(const Person& other) {
		if (*this != other) {
			numPerson = other.numPerson;
			for (int i = 0; i < numPerson; i++) {
				firstName[i] = other.firstName[i];
				secondName[i] = other.secondName[i];
				dateOfBirth[i] = other.dateOfBirth[i];
				address[i] = other.address[i];
			}
		}
		return *this;
	}
	void readPerson(istream& rd, const int& num, const int& index) {
		if (index == 0) {
			numPerson = num;
			firstName = new MyString[numPerson];
			secondName = new MyString[numPerson];
			dateOfBirth = new MyString[numPerson];
			address = new MyString[numPerson];
			rd >> firstName[index];
			rd >> secondName[index];
			rd >> dateOfBirth[index];
			rd >> address[index];
		}
		else {
			rd >> firstName[index];
			rd >> secondName[index];
			rd >> dateOfBirth[index];
			rd >> address[index];
		}
	}
	void writePerson(ostream& wr,const int& index) const {
		wr << "the First Name is :" << firstName[index] << endl;
		wr << "the Second Name is :" << secondName[index] << endl;
		wr << "the Date of birth is :" << dateOfBirth[index] << endl;
		wr << "the Address is :" << address[index] << endl;
	}
	void read(istream& rd) {
		rd >> numPerson;
		firstName = new MyString[numPerson];
		secondName = new MyString[numPerson];
		dateOfBirth = new MyString[numPerson];
		address = new MyString[numPerson];
		rd.ignore();
		for (int i = 0; i < numPerson; i++) {
			rd >> firstName[i];
			rd >> secondName[i];
			rd >> dateOfBirth[i];
			rd >> address[i];
		}
	}
	void write(ostream& wr)const {
		for (int i = 0; i < numPerson; i++) {
			wr << "the First Name is :" << firstName[i] << endl;
			wr << "the Second Name is :" << secondName[i] << endl;
			wr << "the Date of birth is :" << dateOfBirth[i] << endl;
			wr << "the Address is :" << address[i] << endl;
		}
	}
private:
	int numPerson;
	MyString* firstName;
	MyString* secondName;
	MyString* dateOfBirth;
	MyString* address;
};
ostream& operator << (ostream & wr, const Person & other) {
	other.write(wr);
	return wr;
}
istream& operator >> (istream& rd, Person& other) {
	other.read(rd);
	return rd;
}
class Student :public Person{
public:
	Student() :Person(), regNum{},
		addmissionDate{}, currentCourse{} {
		numStudent = 0;
		batch = NULL;
		cgpa = NULL;
		fees = NULL;
	}
	Student(const int& _numStudent, const MyString*& _fristName, const MyString*& _lastName, const MyString*& _regNum, const MyString*& _address,
		const MyString* _dateOfBirth,const MyString*& _addmissionDate, const int*& _batch, const float*& _cgpa, const MyString*& _currentCourse, const int*& _fees) 
		:Person(_numStudent,_fristName,_lastName,_address,_dateOfBirth)
	{
		numStudent = _numStudent;
		regNum = copyName(_regNum, numStudent);
		addmissionDate = copyName(_addmissionDate, numStudent);
		batch = copySalary(_batch, numStudent);
		cgpa = copyCgpa(_cgpa, numStudent);
		currentCourse = copyName(_currentCourse, numStudent);
		fees = copySalary(_fees, numStudent);
	}
	Student(const Student& other):Person(other) {
		numStudent = other.numStudent;
		//fristName = copyName(other.fristName, numStudent);
		//lastName = copyName(other.lastName, numStudent);
		regNum = copyName(other.regNum, numStudent);
		//address = copyName(other.address, numStudent);
		addmissionDate = copyName(other.addmissionDate, numStudent);
		batch = copySalary(other.batch, numStudent);
		cgpa = copyCgpa(other.cgpa, numStudent);
		currentCourse = copyName(other.currentCourse, numStudent);
		fees = copySalary(other.fees, numStudent);
	}
	~Student() {
		//delete[]fristName;
		//delete[]lastName;
		delete[]regNum;
		//delete[]address;
		delete[]addmissionDate;
		delete[]batch;
		delete[]cgpa;
		delete[]currentCourse;
		delete[]fees;
		cout << "Student Destructor" << endl;
	}
	bool operator==(const Student& other) {
		if (this->numStudent == other.numStudent) {
			for (int i = 0; i < numStudent; i++) {
				if (Person::operator==(other) || this->regNum[i] != other.regNum[i] ||
					this->addmissionDate[i] != other.addmissionDate[i] || this->batch[i] != other.batch[i]
					|| this->cgpa[i] != other.cgpa[i] || this->currentCourse[i] != other.currentCourse[i] || this->fees[i] != other.fees[i]) {
					return false;
				}
			}
			return true;
		}
		else {
			return false;
		}
	}
	bool operator!=(const Student& other) {
		return !(Person::operator!=(other)&&*this == other);
	}
	const Student& operator=(const Student& other) {
		if (*this != other) {
			Person::operator=(other);
			numStudent = Person::getNumPerson();
			//fristName = copyName(other.fristName, numStudent);
			///lastName = copyName(other.lastName, numStudent);
			regNum = copyName(other.regNum, numStudent);
			//address = copyName(other.address, numStudent);
			addmissionDate = copyName(other.addmissionDate, numStudent);
			batch = copySalary(other.batch, numStudent);
			cgpa = copyCgpa(other.cgpa, numStudent);
			currentCourse = copyName(other.currentCourse, numStudent);
			fees = copySalary(other.fees, numStudent);
		}
		return *this;
	}
	void read(istream& rd) {
		rd >> numStudent;
		rd.ignore();
		//fristName = new MyString[numStudent];
		//lastName = new MyString[numStudent];
		regNum = new MyString[numStudent];
		//address = new MyString[numStudent];
		addmissionDate = new MyString[numStudent];
		currentCourse = new MyString[numStudent];
		batch = new int[numStudent];
		cgpa = new float[numStudent];
		fees = new int[numStudent];
		for (int i = 0; i < numStudent; i++) {
			Person::readPerson(rd, numStudent, i);
			//rd >> fristName[i];
			//rd >> lastName[i];
			rd >> regNum[i];
			//rd >> address[i];
			rd >> addmissionDate[i];
			rd >> currentCourse[i];
			rd >> batch[i];
			rd >> cgpa[i];
			rd >> fees[i];
			rd.ignore();
		}
	}
	void write(ostream& wr)const {
		wr << "<--Students-->" << endl;
		wr << "Number of Students  : " << numStudent << endl;
		for (int i = 0; i < numStudent; i++) {
			Person::writePerson(wr, i);
			//wr << "The frist Name of Student " << i + 1 << ": \t" << fristName[i] << endl;
			//wr << "The last Name of Student " << i + 1 << ": \t" << lastName[i] << endl;
			wr << "The registration Number of Student " << i + 1 << ": \t" << regNum[i] << endl;
			//wr << "The address of Student " << i + 1 << ": \t" << address[i] << endl;
			wr << "The date of admission of Student " << i + 1 << ": \t" << addmissionDate[i] << endl;
			wr << "The current Course of Student " << i + 1 << ": \t" << currentCourse[i] << endl;
			wr << "The batch of Student " << i + 1 << ": \t" << batch[i] << endl;
			wr << endl;
			wr << "The cgpa of Student " << i + 1 << ": \t" << cgpa[i] << endl;
			wr << endl;
			wr << "The fees of Student " << i + 1 << ": \t" << fees[i] << endl;
			wr << endl;
		}
	}
private:
	int numStudent = 0;
	MyString* regNum;
	MyString* addmissionDate;
	int* batch;
	float* cgpa;
	MyString* currentCourse;
	int* fees;
};
ostream& operator<<(ostream& wr, const Student& A) {
	A.write(wr);
	return wr;
}
istream& operator>>(istream& rd, Student& A) {
	A.read(rd);
	return rd;
}
class Teacher :public Person {
public:
	Teacher() :Person(), teacherDegree{}, teacherDestination{}, teacherDateOfJoining{} {
		numTeacher = 0;
		teacherSalary = NULL;
		id = NULL;
	}

	Teacher(const int& _numTeacher, const MyString*& _firstName, const MyString*& _secondName, const MyString*& _dateOfBirth, const MyString*& _address, const int*& _teacherSalary, const int*& _id,
		const MyString*& _teacherDegree, const MyString*& _teacherDestination, const MyString*& _teacherDateOfJoining) 
		:Person(_numTeacher,_firstName,_secondName,_dateOfBirth,_address)
	{
		numTeacher = _numTeacher;
	//	teacherName = copyName(_teacherName, numTeacher);
		teacherSalary = copySalary(_teacherSalary, numTeacher);
		id = copySalary(_id, numTeacher);
		teacherDegree = copyName(_teacherDegree, numTeacher);
		teacherDestination = copyName(_teacherDestination, numTeacher);
		teacherDateOfJoining = copyName(_teacherDateOfJoining, numTeacher);
	}
	Teacher(const Teacher& other):Person(other) {
		numTeacher = other.numTeacher;
		//teacherName = copyName(other.teacherName, numTeacher);
		teacherSalary = copySalary(other.teacherSalary, numTeacher);
		id = copySalary(other.id, numTeacher);
		teacherDegree = copyName(other.teacherDegree, numTeacher);
		teacherDestination = copyName(other.teacherDestination, numTeacher);
		teacherDateOfJoining = copyName(other.teacherDateOfJoining, numTeacher);
	}
	~Teacher() {
		//delete[]teacherName;
		delete[]teacherSalary;
		delete[]id;
		delete[]teacherDegree;
		delete[]teacherDestination;
		delete[]teacherDateOfJoining;
		cout << "Teacher Destructor" << endl;
	}
	bool operator==(const Teacher& other) {
		if (this->numTeacher == other.numTeacher) {
			for (int i = 0; i < numTeacher; i++) {
				if (Person::operator==(other) || this->teacherSalary[i] != other.teacherSalary[i] ||
					this->id[i] != other.id[i] || this->teacherDegree[i] != other.teacherDegree[i] ||
					this->teacherDestination[i] != other.teacherDestination[i]
					|| this->teacherDateOfJoining[i] != other.teacherDateOfJoining[i]
					) {
					return false;
				}
			}
			return true;
		}
		else {
			return false;
		}
	}
	bool operator!=(const Teacher& other) {
		return !(*this == other);
	}
	const Teacher& operator=(const Teacher& other) {
		if (*this != other) {
			numTeacher = other.numTeacher;
			Person::operator=(other);
		//	teacherName = copyName(other.teacherName, numTeacher);
			teacherSalary = copySalary(other.teacherSalary, numTeacher);
			id = copySalary(other.id, numTeacher);
			teacherDegree = copyName(other.teacherDegree, numTeacher);
			teacherDestination = copyName(other.teacherDestination, numTeacher);
			teacherDateOfJoining = copyName(other.teacherDateOfJoining, numTeacher);
		}
		return *this;
	}
	void read(istream& rd) {
		rd >> numTeacher;
		//teacherName = new MyString[numTeacher];
		teacherDegree = new MyString[numTeacher];
		teacherDestination = new MyString[numTeacher];
		teacherDateOfJoining = new MyString[numTeacher];
		teacherSalary = new int[numTeacher];
		id = new int[numTeacher];
		rd.ignore();
		for (int i = 0; i < numTeacher; i++) {
			Person::readPerson(rd, numTeacher, i);
		//	rd >> teacherName[i];
			rd >> teacherDegree[i];
			rd >> teacherDestination[i];
			rd >> teacherDateOfJoining[i];
			rd >> teacherSalary[i];
			rd >> id[i];
			rd.ignore();
		}
	}
	void write(ostream& wr)const {
		wr << "<---Teachers--->" << endl;
		wr << "Number of Teachers  : " << numTeacher << endl;
		for (int i = 0; i < numTeacher; i++) {
			Person::writePerson(wr, i);
			//wr << "The Name of teacher " << i + 1 << " : \t" << teacherName[i] << endl;
			wr << "The Degree of teacher " << i + 1 << " : \t" << teacherDegree[i] << endl;
			wr << "The Destination of teacher " << i + 1 << " : \t" << teacherDestination[i] << endl;
			wr << "The Date of Joining of teacher " << i + 1 << " : \t" << teacherDateOfJoining[i] << endl;
			wr << "The Salary of teacher " << i + 1 << " : \t" << teacherSalary[i] << endl;
			wr << endl;
			wr << "The ID of teacher " << i + 1 << " : \t" << id[i] << endl;
			wr << endl;
		}
	}
	void find() {
		int _id = 0;
		int n = 0;
		cout << "Enter the Id of the Teacher you want to find:(1001-1020)" << endl;
		cin >> _id;
		cout << endl;
		cout << "the Detail of person With User Id :" << _id << endl;
		for (int i = 0; i < numTeacher; i++) {
			if (id[i] == _id) {
			//	cout << "The Name of teacher " << " : \t" << teacherName[i] << endl;
				cout << "The Degree of teacher " << " : \t" << teacherDegree[i] << endl;
				cout << "The Destination of teacher " << " : \t" << teacherDestination[i] << endl;
				cout << "The Date of Joining of teacher " << " : \t" << teacherDateOfJoining[i] << endl;
				cout << "The Salary of teacher " << " : \t" << teacherSalary[i] << endl;
				cout << endl;
				cout << "The ID of teacher " << " : \t" << id[i] << endl;
				cout << endl;
				n = i;
				break;
			}
		}
		if (!(id[n] == _id)) {
			cout << "not found" << endl;
		}
	}
	void calculate() {
		int S = 0;

		for (int i = 0; i < numTeacher; i++) {
			S += teacherSalary[i];
		}
		cout << "the salary of all teacher:" << S << endl;
	}
private:
	int numTeacher;
	int* teacherSalary;
	int* id;
	MyString* teacherDegree;
	MyString* teacherDestination;
	MyString* teacherDateOfJoining;
};
ostream& operator<<(ostream& wr, const Teacher& A) {
	A.write(wr);
	return wr;
}
istream& operator>>(istream& rd, Teacher& A) {
	A.read(rd);
	return rd;
}

int main()
{
	Person A;
	ifstream fin;
	fin.open("person.txt");
	if (fin.is_open()) {
		fin >> A;
	}
	cout << A << endl;
	Student B;
	ifstream In;
	In.open("student.txt");
	if (In.is_open()) {
		In >> B;
	}
	cout << B << endl;
	Teacher C;
	ifstream file;
	file.open("teacher.txt");
	if (file.is_open()) {
		file >> C;
	}
	cout << C << endl;


	return 0;
}