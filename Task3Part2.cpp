#include <iostream>
#include <fstream>
using namespace std;

int length(const char *ptr)
{
	if (ptr == nullptr)
	{
		return 0;
	}
	int count = 0;
	for (int i = 0; ptr[i] != '\0'; i++)
	{
		count++;
	}
	return count;
}
bool compare(const char *ptr1, const char *ptr2)
{
	if (length(ptr1) == length(ptr2))
	{
		for (int i = 0; i < length(ptr1); i++)
		{
			if (ptr1[i] != ptr2[i])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}
char *copy(const char *_ptr)
{
	if (_ptr == nullptr)
	{
		return nullptr;
	}
	int l = length(_ptr);
	char *newPtr = new char[l + 1];
	for (int i = 0; i < l + 1; i++)
	{
		newPtr[i] = _ptr[i];
	}
	return newPtr;
}
class MyString
{
private:
	char *ptr;

public:
	MyString()
	{
		ptr = nullptr;
	}

	MyString(const char *_ptr)
	{
		ptr = copy(_ptr);
	}

	MyString(const MyString &other)
	{
		ptr = copy(other.ptr);
	}

	void setString(const char *_ptr)
	{
		delete[] ptr;
		ptr = copy(_ptr);
	}

	bool operator==(const MyString &d) const
	{
		return compare(d.ptr);
	}

	char *getString() const
	{
		return copy(ptr);
	}

	void input()
	{
		ptr = new char[100];
		// cout << "Enter the value in array: " << endl;
		cin.getline(ptr, 100, '\n');
	}

	void display() const
	{
		cout << ptr << endl;
	}

	void append(const char *_ptr)
	{
		int l1 = count(ptr);
		int l2 = count(_ptr);
		int l = l1 + l2;
		char *str = new char[l + 1];
		for (int i = 0; i < l1; i++)
		{
			str[i] = ptr[i];
		}
		for (int i = l1; i < l + 1; i++)
		{
			str[i] = _ptr[i - l1];
		}
		delete[] ptr;
		ptr = copy(str);
		delete[] str;
	}

	int count(const char *_ptr) const
	{
		if (_ptr == nullptr)
		{
			return 0;
		}
		int counter = 0;
		for (int i = 0; _ptr[i] != '\0'; i++)
		{
			counter++;
		}
		return counter;
	}

	int count() const
	{
		if (ptr == nullptr)
		{
			return 0;
		}
		int counter = 0;
		for (int i = 0; ptr[i] != '\0'; i++)
		{
			counter++;
		}
		return counter;
	}

	bool compare(const char *_ptr) const
	{
		if (length(ptr) == length(_ptr))
		{
			for (int i = 0; i < count(ptr); i++)
			{
				if (ptr[i] != _ptr[i])
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isEmpty() const
	{
		return (ptr == nullptr);
	}

	MyString operator+(const MyString &d) const
	{
		MyString result = ptr;
		result.append(d.ptr);
		return result;
	}

	bool operator!=(const MyString &d) const
	{
		return !compare(d.ptr);
	}

	bool operator<(const MyString &d) const
	{
		return (compare(d.ptr) < 0);
	}

	bool operator>(const MyString &d) const
	{
		return (compare(d.ptr) > 0);
	}

	bool operator<=(const MyString &d) const
	{
		return (*this == d || *this < d);
	}

	bool operator>=(const MyString &d) const
	{
		return (*this == d || *this > d);
	}

	const MyString &operator=(const MyString &d)
	{
		if (this != &d)
		{
			delete[] ptr;
			ptr = copy(d.ptr);
		}
		return *this;
	}

	MyString operator++()
	{
		if (ptr != nullptr)
		{
			int len = count(ptr);
			for (int i = 0; i < len; i++)
			{
				ptr[i]++;
			}
		}
		return *this;
	}

	MyString operator++(int)
	{
		MyString result(*this);
		if (ptr != nullptr)
		{
			int len = count(ptr);
			for (int i = 0; i < len; i++)
			{
				ptr[i]++;
			}
		}
		return result;
	}

	MyString operator--()
	{
		if (ptr != nullptr)
		{
			int len = count(ptr);
			for (int i = 0; i < len; i++)
			{
				ptr[i]--;
			}
		}
		return *this;
	}

	MyString operator--(int)
	{
		MyString result(*this);
		if (ptr != nullptr)
		{
			int len = count(ptr);
			for (int i = 0; i < len; i++)
			{
				ptr[i]--;
			}
		}
		return result;
	}

	~MyString()
	{
		delete[] ptr;
	}
};

istream &operator>>(istream &rd, MyString &a)
{
	char *Str = new char[100];
	// cout << "Enter String: " << endl;
	rd.getline(Str, 100, '\n');
	a.setString(Str);
	delete[] Str;
	return rd;
}

ostream &operator<<(ostream &wr, const MyString &a)
{
	wr << a.getString() << endl;
	return wr;
}

MyString concatenate(MyString &a, MyString &b)
{
	int l1 = a.count(a.getString());
	int l2 = b.count(b.getString());
	int l = l1 + l2;
	char *temp = new char[l + 1];
	char *str = copy(a.getString());
	char *str2 = copy(b.getString());
	for (int i = 0; i < l1; i++)
	{
		temp[i] = str[i];
	}
	for (int i = l1; i < l + 1; i++)
	{
		temp[i] = str2[i - l1];
	}
	MyString result(temp);
	delete[] str;
	delete[] str2;
	delete[] temp;
	return result;
}

bool isEqual(MyString &a, MyString &b)
{
	return a.compare(b.getString());
}

void increment(int &sz, MyString *&dp)
{
	MyString *nd = new MyString[sz + 1];
	if (dp != nullptr)
	{
		for (int i = 0; i < sz; i++)
		{
			nd[i] = dp[i];
		}
		delete[] dp;
	}
	dp = nd;
}

void input(int &no, MyString *&d)
{
	cout << "How many Strings will you enter: ";
	cin >> no;
	if (d != nullptr)
	{
		delete[] d;
	}
	cin.ignore();
	d = new MyString[no];
	for (int i = 0; i < no; i++)
	{
		cin >> d[i];
	}
}

MyString *copyName(const MyString *const &other, const int &size)
{
	MyString *name = new MyString[size];
	for (int i = 0; i < size; i++)
	{
		name[i] = other[i];
	}
	return name;
}
int *copySalary(const int *const &other, const int &size)
{
	int *salary = new int[size];
	for (int i = 0; i < size; i++)
	{
		salary[i] = other[i];
	}
	return salary;
}
float *copyCgpa(const float *const &other, const int &size)
{
	float *cgpa = new float[size];
	for (int i = 0; i < size; i++)
	{
		cgpa[i] = other[i];
	}
	return cgpa;
}
void readMyStringsFromFile(MyString *&d, int &no, const char *p)
{
	ifstream fin(p);
	char s[100];
	for (int i = 0; fin >> s; i++)
	{
		increment(no, d);
		d[i] = MyString(s);
	}
}

void writeMyStringsToFile(MyString *d, int &no, const char *p)
{
	ofstream fout(p);
	fout << no << " ";
	for (int i = 0; i < no; i++)
	{
		fout << d[i] << " ";
	}
}

void verifyMyStringsFiles(MyString *d, int &no, const char *p)
{
	MyString *copyD = nullptr;
	int sz = 0;
	readMyStringsFromFile(copyD, sz, p);
	for (int i = 0; i < no; i++)
	{
		if (isEqual(d[i], copyD[i]))
		{
			cout << d[i] << " == " << copyD[i] << " is true \n";
		}
		else
		{
			cout << d[i] << " == " << copyD[i] << " is false \n";
		}
	}
}
class Date
{
public:
	Date()
	{
		day = 0;
		month = 0;
		year = 0;
	}
	Date(const int &_day, const int &_month, const int &_year)
	{
		day = _day;
		month = _month;
		year = _year;
	}
	Date(const Date &other)
	{
		day = other.day;
		month = other.month;
		year = other.year;
	}
	int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }
	~Date()
	{
		cout << "Date destructor is Called" << endl;
	}
	bool operator==(const Date &other)
	{
		if (day == other.day && month == other.month && year == other.year)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator!=(const Date &other)
	{
		return !(*this == other);
	}
	const Date &operator=(const Date &other)
	{
		if (*this != other)
		{
			day = other.day;
			month = other.month;
			year = other.year;
		}
		return *this;
	}
	int calculateAge(const Date &other)
	{
		int age = other.year - year;
		// Adjust age based on the birthdate in the current year
		if (other.month < month || (other.month == month && other.day < day))
		{
			age--;
		}
		cout << "The Age of Person is : " << age << " years " << endl;
		return age;
	}
	void display()
	{
		cout << "The Date is :" << day << " : " << month << " : " << year << endl;
	}
	void read(istream &rd)
	{
		rd >> day;
		rd >> month;
		rd >> year;
	}
	void write(ostream &wr) const
	{
		wr << day << " : " << month << " : " << year << endl;
	}

private:
	int day;
	int month;
	int year;
};
ostream &operator<<(ostream &wr, const Date &other)
{
	other.write(wr);
	return wr;
}
istream &operator>>(istream &rd, Date &other)
{
	other.read(rd);
	return rd;
}
class Info
{
public:
	Info() : name{}, Uniaddress{}, dateOfFormation{}, email{}, website{}
	{
		Uninumber = 0;
	}
	Info(const MyString &_name, const MyString &_Uniaddress, const MyString &_dateOfFormation,
		 long long const int &_Uninumber, const MyString &_email, const MyString &_website)
	{
		name = _name;
		Uniaddress = _Uniaddress;
		dateOfFormation = _dateOfFormation;
		Uninumber = _Uninumber;
		email = _email;
		website = _website;
	}
	Info(const Info &other)
	{
		name = other.name;
		Uniaddress = other.Uniaddress;
		dateOfFormation = other.dateOfFormation;
		Uninumber = other.Uninumber;
		email = other.email;
		website = other.website;
	}
	bool operator==(const Info &other)
	{
		if (name == other.name)
		{
			if (Uniaddress == other.Uniaddress)
			{
				if (dateOfFormation == other.dateOfFormation)
				{
					if (email == other.email)
					{
						if (website == other.website)
						{
							return true;
						}
						return false;
					}
					return false;
				}
				return false;
			}
			return false;
		}
		else
		{
			return false;
		}
	}
	bool operator!=(const Info &other)
	{
		return !(*this == other);
	}
	const Info &operator=(const Info &other)
	{
		if (*this != other)
		{
			name = other.name;
			Uniaddress = other.Uniaddress;
			dateOfFormation = other.dateOfFormation;
			Uninumber = other.Uninumber;
			email = other.email;
			website = other.website;
		}
		return *this;
	}
	void read(istream &rd)
	{
		rd >> name;
		rd >> Uniaddress;
		rd >> dateOfFormation;
		rd >> email;
		rd >> website;
		rd >> Uninumber;
	}
	void write(ostream &wr) const
	{
		wr << "<---Information About University--->" << endl;
		wr << endl;
		wr << "Name : " << name << endl;
		wr << "Address : " << Uniaddress << endl;
		wr << "Date of formation : " << dateOfFormation << endl;
		wr << "Contact Number : " << Uninumber << endl;
		wr << endl;
		wr << "Email : " << email << endl;
		wr << "Website : " << website << endl;
	}
	~Info()
	{
		cout << "Info Destructor" << endl;
	}

private:
	MyString name;
	MyString Uniaddress;
	MyString dateOfFormation;
	long long int Uninumber = 0;
	MyString email;
	MyString website;
};
ostream &operator<<(ostream &wr, const Info &A)
{
	A.write(wr);
	return wr;
}
istream &operator>>(istream &rd, Info &A)
{
	A.read(rd);
	return rd;
}
class Person
{
public:
	Person() : firstName{}, secondName{}, dateOfBirth{}, address{} {}
	Person(const MyString &_firstName, const MyString &_secondName, const Date &_dateOfBirth, const MyString &_address)
	{
		firstName = _firstName;
		secondName = _secondName;
		dateOfBirth = _dateOfBirth;
		address = _address;
	}
	Person(const Person &other)
	{
		firstName = other.firstName;
		secondName = other.secondName;
		dateOfBirth = other.dateOfBirth;
		address = other.address;
	}
	~Person()
	{
		cout << "Person Destructor is Called" << endl;
	}
	Date getDate() const { return dateOfBirth; }
	bool operator==(const Person &other)
	{
		if (firstName == other.firstName && secondName == other.secondName && dateOfBirth == other.dateOfBirth &&
			address == other.address)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator!=(const Person &other)
	{
		return !(*this == other);
	}
	const Person &operator=(const Person &other)
	{
		if (*this != other)
		{
			firstName = other.firstName;
			secondName = other.secondName;
			dateOfBirth = other.dateOfBirth;
			address = other.address;
		}
		return *this;
	}
	void read(istream &rd)
	{
		rd >> firstName;
		rd >> secondName;
		rd >> dateOfBirth;
		rd.ignore();
		rd >> address;
	}
	virtual void write(ostream &wr) const = 0; /*{
		  wr << "the First Name is :" << firstName << endl;
		  wr << "the Second Name is :" << secondName << endl;
		  wr << "the Date of birth is :" << dateOfBirth << endl;
		  wr << "the Address is :" << address << endl;
	  }*/
	virtual void display() const = 0;
	bool findPerson(MyString &other)
	{
		if (isEqual(secondName, other))
		{
			return true;
		}
		else
		{
			/*cout << "Not found" << endl;*/
			return false;
		}
	}
	int findAge()
	{
		Date currentDate;
		cout << "Enter the current Date (day month year) to calculate Age :" << endl;
		cin >> currentDate;
		return dateOfBirth.calculateAge(currentDate);
	}

protected:
	MyString firstName;
	MyString secondName;
	Date dateOfBirth;
	MyString address;
};
ostream &operator<<(ostream &wr, const Person &other)
{
	other.write(wr);
	return wr;
}
istream &operator>>(istream &rd, Person &other)
{
	other.read(rd);
	return rd;
}
class Student : public Person
{
public:
	Student() : regNum{},
				admissionDate{}, currentCourse{}
	{
		batch = 0;
		cgpa = 0;
		fees = 0;
	}
	Student(const MyString &_firstName, const MyString &_lastName, const Date &_dateOfBirth, const MyString &_regNum, const MyString &_address,
			const MyString &_admissionDate, const int &_batch, const float &_cgpa, const MyString &_currentCourse, const int &_fees)
		: Person(_firstName, _lastName, _dateOfBirth, _address)
	{
		regNum = _regNum;
		admissionDate = _admissionDate;
		batch = _batch;
		cgpa = _cgpa;
		currentCourse = _currentCourse;
		fees = _fees;
	}
	Student(const Student &other) : Person(other)
	{
		regNum = other.regNum;
		admissionDate = other.admissionDate;
		batch = other.batch;
		cgpa = other.cgpa;
		currentCourse = other.currentCourse;
		fees = other.fees;
	}
	~Student()
	{
		cout << "Student Destructor" << endl;
	}
	bool operator==(const Student &other)
	{
		if (Person::operator==(other) && regNum == other.regNum)
		{
			if (admissionDate == other.admissionDate && currentCourse == other.currentCourse)
			{
				if (batch == other.batch && cgpa == other.cgpa && fees == other.fees)
				{
					return true;
				}
				return false;
			}
			return false;
		}
		else
		{
			return false;
		}
	}
	bool operator!=(const Student &other)
	{
		return !(*this == other);
	}
	const Student &operator=(const Student &other)
	{
		if (*this != other)
		{
			Person::operator=(other);
			regNum = other.regNum;
			admissionDate = other.admissionDate;
			batch = other.batch;
			cgpa = other.cgpa;
			currentCourse = other.currentCourse;
			fees = other.fees;
		}
		return *this;
	}
	void read(istream &rd)
	{
		Person::read(rd);
		rd >> regNum;
		rd >> admissionDate;
		rd >> currentCourse;
		rd >> batch;
		rd >> cgpa;
		rd >> fees;
		rd.ignore();
	}
	void write(ostream &wr) const override
	{
		wr << "<--Students-->" << endl;
		// Person::write(wr);

		wr << "The First Name of Student is : " << firstName << endl;
		wr << "The Last Name of Student is : " << secondName << endl;
		wr << "The Date of Birth of Student is : " << dateOfBirth << endl;
		wr << "The Address of Student is : " << address << endl;
		wr << "The Registration Number of Student " << ": \t" << regNum << endl;
		wr << "The date of admission of Student " << ": \t" << admissionDate << endl;
		wr << "The current Course of Student " << ": \t" << currentCourse << endl;
		wr << "The batch of Student " << ": \t" << batch << endl;
		wr << endl;
		wr << "The CGPA of Student " << ": \t" << cgpa << endl;
		wr << endl;
		wr << "The fees of Student " << ": \t" << fees << endl;
		wr << endl;
	}
	void display() const override
	{
		cout << "<--Students-->" << endl;
		// Person::display();
		cout << "The First Name of Student is : " << firstName << endl;
		cout << "The Last Name of Student is : " << secondName << endl;
		cout << "The Date of Birth of Student is : " << dateOfBirth << endl;
		cout << "The Address of Student is : " << address << endl;
		cout << "The Registration Number of Student " << ": \t" << regNum << endl;
		cout << "The date of admission of Student " << ": \t" << admissionDate << endl;
		cout << "The current Course of Student " << ": \t" << currentCourse << endl;
		cout << "The batch of Student " << ": \t" << batch << endl;
		cout << endl;
		cout << "The CGPA of Student " << ": \t" << cgpa << endl;
		cout << endl;
		cout << "The fees of Student " << ": \t" << fees << endl;
		cout << endl;
	}
	bool findStudent(MyString &name)
	{
		bool B = Person::findPerson(name);
		return B;
	}
	int findStudentAge(MyString &name)
	{
		bool B = Person::findPerson(name);
		if (B == 1)
		{
			return Person::findAge();
		}
		else
		{
			return 0;
		}
	}

private:
	MyString regNum;
	MyString admissionDate;
	int batch;
	float cgpa;
	MyString currentCourse;
	int fees;
};
ostream &operator<<(ostream &wr, const Student &A)
{
	A.write(wr);
	return wr;
}
istream &operator>>(istream &rd, Student &A)
{
	A.read(rd);
	return rd;
}
class Teacher : public Person
{
public:
	Teacher() : Person(), teacherDegree{}, teacherDestination{}, teacherDateOfJoining{}
	{
		teacherSalary = 0;
		id = 0;
	}

	Teacher(const MyString &_firstName, const MyString &_secondName, const Date &_dateOfBirth, const MyString &_address, const int &_teacherSalary,
			const int &_id, const MyString &_teacherDegree, const MyString &_teacherDestination, const MyString &_teacherDateOfJoining)
		: Person(_firstName, _secondName, _dateOfBirth, _address)
	{
		teacherSalary = _teacherSalary;
		id = _id;
		teacherDegree = _teacherDegree;
		teacherDestination = _teacherDestination;
		teacherDateOfJoining = _teacherDateOfJoining;
	}
	Teacher(const Teacher &other) : Person(other)
	{
		teacherSalary = other.teacherSalary;
		id = other.id;
		teacherDegree = other.teacherDegree;
		teacherDestination = other.teacherDestination;
		teacherDateOfJoining = other.teacherDateOfJoining;
	}
	int getSalary() const { return teacherSalary; }
	~Teacher()
	{
		cout << "Teacher Destructor" << endl;
	}
	bool operator==(const Teacher &other)
	{
		if (Person::operator==(other) || this->teacherSalary != other.teacherSalary ||
			this->id != other.id || this->teacherDegree != other.teacherDegree ||
			this->teacherDestination != other.teacherDestination || this->teacherDateOfJoining != other.teacherDateOfJoining)
		{
			return false;
		}
		else
		{
			return false;
		}
	}
	bool operator!=(const Teacher &other)
	{
		return !(*this == other);
	}
	const Teacher &operator=(const Teacher &other)
	{
		if (*this != other)
		{
			Person::operator=(other);
			teacherSalary = other.teacherSalary;
			id = other.id;
			teacherDegree = other.teacherDegree;
			teacherDestination = other.teacherDestination;
			teacherDateOfJoining = other.teacherDateOfJoining;
		}
		return *this;
	}
	void read(istream &rd)
	{
		Person::read(rd);
		rd >> teacherDegree;
		rd >> teacherDestination;
		rd >> teacherDateOfJoining;
		rd >> teacherSalary;
		rd >> id;
		rd.ignore();
	}
	void write(ostream &wr) const override
	{
		wr << "<---Teachers--->" << endl;
		// Person::write(wr);
		wr << "The First Name of teacher is :" << firstName << endl;
		wr << "The Second Name of teacher is :" << secondName << endl;
		wr << "The Date of birth of teacher is :" << dateOfBirth << endl;
		wr << "The Address of teacher is :" << address << endl;
		wr << "The Degree of teacher " << " : \t" << teacherDegree << endl;
		wr << "The Destination of teacher " << " : \t" << teacherDestination << endl;
		wr << "The Date of Joining of teacher " << " : \t" << teacherDateOfJoining << endl;
		wr << "The Salary of teacher " << " : \t" << teacherSalary << endl;
		wr << endl;
		wr << "The ID of teacher " << " : \t" << id << endl;
		wr << endl;
	}
	void display() const override
	{
		cout << "<---Teachers--->" << endl;
		// Person::display();
		cout << "The First Name of teacher is :" << firstName << endl;
		cout << "The Second Name of teacher is :" << secondName << endl;
		cout << "The Date of birth of teacher is :" << dateOfBirth << endl;
		cout << "The Address of teacher is :" << address << endl;
		cout << "The Degree of teacher " << " : \t" << teacherDegree << endl;
		cout << "The Destination of teacher " << " : \t" << teacherDestination << endl;
		cout << "The Date of Joining of teacher " << " : \t" << teacherDateOfJoining << endl;
		cout << "The Salary of teacher " << " : \t" << teacherSalary << endl;
		cout << endl;
		cout << "The ID of teacher " << " : \t" << id << endl;
		cout << endl;
	}
	bool findTeacher(int _id)
	{
		if (id == _id)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int findTeacherAge(int _id)
	{
		if (id == _id)
		{
			return Person::findAge();
		}
		else
		{
			return 0;
		}
	}

private:
	int teacherSalary;
	int id;
	MyString teacherDegree;
	MyString teacherDestination;
	MyString teacherDateOfJoining;
};
ostream &operator<<(ostream &wr, const Teacher &A)
{
	A.write(wr);
	return wr;
}
istream &operator>>(istream &rd, Teacher &A)
{
	A.read(rd);
	return rd;
}

class Course
{
public:
	Course() : course{}, courseOutline{}, courseCode{}
	{
		creditHour = 0;
	}
	Course(const MyString &_course,
		   const int &_creditHour, const MyString &_courseCode, const MyString &_courseOutline)
	{
		this->course = _course;
		this->creditHour = _creditHour;
		this->courseCode = _courseCode;
		this->courseOutline = _courseOutline;
	}
	Course(const Course &other)
	{
		this->course = other.course;
		this->creditHour = other.creditHour;
		this->courseCode = other.courseCode;
		this->courseOutline = other.courseOutline;
	}
	~Course()
	{
		cout << "Course Destructor" << endl;
	}
	bool operator==(const Course &other)
	{
		if (course == other.course && creditHour == other.creditHour && courseCode == other.courseCode && courseOutline == other.courseOutline)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator!=(const Course &other)
	{
		return !(*this == other);
	}
	const Course &operator=(const Course &other)
	{
		if (*this != other)
		{
			this->course = other.course;
			this->creditHour = other.creditHour;
			this->courseCode = other.courseCode;
			this->courseOutline = other.courseOutline;
		}
		return *this;
	}
	void read(istream &rd)
	{
		rd >> course;
		rd >> creditHour;
		rd.ignore();
		rd >> courseCode;
		rd >> courseOutline;
	}
	void write(ostream &wr) const
	{
		wr << "<--- Courses --->" << endl;
		wr << "Course Name : " << "\t" << course << endl;
		wr << "Credit Hour : " << "\t" << creditHour << endl;
		wr << endl;
		wr << "Course Code : " << "\t" << courseCode << endl;
		wr << endl;
		wr << "Course Outline : " << "\t" << courseOutline << endl;
	}

private:
	MyString course;
	int creditHour;
	MyString courseCode;
	MyString courseOutline;
};
ostream &operator<<(ostream &wr, const Course &A)
{
	A.write(wr);
	return wr;
}
istream &operator>>(istream &rd, Course &A)
{
	A.read(rd);
	return rd;
}
class Degree
{
public:
	Degree() : degreeName{}, students{}, teachers{}, courses{}
	{
		durationOfDegree = 0;
		numStudents = 0;
		numTeachers = 0;
		numCourses = 0;
	}
	Degree(const MyString &_degreeName, const int &_durationOfDegree)
	{
		this->degreeName = _degreeName;
		this->durationOfDegree = _durationOfDegree;
	}
	Degree(const Degree &other)
	{

		this->degreeName = other.degreeName;
		this->durationOfDegree = other.durationOfDegree;
	}
	~Degree()
	{
		delete[] courses;
		delete[] students;
		delete[] teachers;
		cout << "Degree Destructor" << endl;
	}
	bool operator==(const Degree &other)
	{
		if (degreeName == other.degreeName && durationOfDegree == other.durationOfDegree)
		{
			return true;
		}
		else
		{
			return true;
		}
	}
	bool operator!=(const Degree &other)
	{
		return !(*this == other);
	}
	const Degree &operator=(const Degree &other)
	{
		if (*this != other)
		{
			this->degreeName = other.degreeName;
			this->durationOfDegree = other.durationOfDegree;
			numCourses = other.numCourses;
			for (int i = 0; i < numCourses; i++)
			{
				courses[i] = other.courses[i];
			}
			numStudents = other.numCourses;
			for (int i = 0; i < numStudents; i++)
			{
				students[i] = other.students[i];
			}
			numTeachers = other.numTeachers;
			for (int i = 0; i < numTeachers; i++)
			{
				teachers[i] = other.teachers[i];
			}
		}
		return *this;
	}
	void read(istream &rd)
	{
		rd >> degreeName;
		rd >> durationOfDegree;
		rd >> numStudents;
		students = new Student[numStudents];
		rd.ignore();
		for (int i = 0; i < numStudents; i++)
		{
			rd >> students[i];
		}
		rd >> numTeachers;
		teachers = new Teacher[numTeachers];
		rd.ignore();
		for (int i = 0; i < numTeachers; i++)
		{
			rd >> teachers[i];
		}
		rd >> numCourses;
		courses = new Course[numCourses];
		rd.ignore();
		for (int i = 0; i < numCourses; i++)
		{
			rd >> courses[i];
		}
	}
	void write(ostream &wr) const
	{
		wr << "<--- Degrees --->" << endl;
		wr << endl;
		wr << "Degree  " << " : \t" << degreeName << endl;
		wr << "Duration of Degree  " << " : \t" << durationOfDegree << " year " << endl;
		wr << endl;
		wr << "The number of Courses in the Degree are : " << numCourses << endl;
		for (int i = 0; i < numCourses; i++)
		{
			wr << courses[i] << endl;
		}
		wr << "The number of Students in the Degree are : " << numStudents << endl;
		for (int i = 0; i < numStudents; i++)
		{
			wr << students[i] << endl;
		}
		wr << "The number of Teachers in the Degree are : " << numTeachers << endl;
		for (int i = 0; i < numTeachers; i++)
		{
			wr << teachers[i] << endl;
		}
	}
	void findStudents(MyString &name)
	{

		for (int i = 0; i < numStudents; i++)
		{
			if (students[i].findStudent(name) == 1)
			{
				students[i].display();
				break;
			}
		}
	}
	void findTeachers(int &_id)
	{

		for (int i = 0; i < numTeachers; i++)
		{
			if (teachers[i].findTeacher(_id) == 1)
			{
				teachers[i].display();
				break;
			}
		}
	}
	void findAges(MyString &name)
	{
		for (int i = 0; i < numStudents; i++)
		{
			if (students[i].findStudent(name) == 1)
			{
				students[i].findAge();
				break;
			}
		}
	}
	long long int findSalaries()
	{
		long long int S = 0;
		for (int i = 0; i < numTeachers; i++)
		{
			S += teachers[i].getSalary();
		}
		return S;
	}

private:
	MyString degreeName;
	int durationOfDegree;
	int numStudents;
	Student *students;
	int numTeachers;
	Teacher *teachers;
	int numCourses;
	Course *courses;
};
ostream &operator<<(ostream &wr, const Degree &A)
{
	A.write(wr);
	return wr;
}
istream &operator>>(istream &rd, Degree &A)
{
	A.read(rd);
	return rd;
}
Degree *copyDegree(const Degree *&other, const int &num)
{
	Degree *A = new Degree[num];
	for (int i = 0; i < num; i++)
	{
		A[i] = other[i];
	}
	return A;
}
class University
{
public:
	University() : info{}, degree{}
	{
		numDegree = 0;
	}
	University(const Info &_info, const Degree *&_degree, const int &_numDegree)
	{
		info = _info;
		numDegree = _numDegree;
		degree = new Degree[numDegree];
		degree = copyDegree(_degree, numDegree);
	}
	University(const University &other)
	{
		info = other.info;
		degree = new Degree[numDegree];
		for (int i = 0; i < numDegree; i++)
		{
			degree[i] = other.degree[i];
		}
	}
	bool operator==(const University &other)
	{
		if (this->info == other.info && numDegree == other.numDegree)
		{
			for (int i = 0; i < numDegree; i++)
			{
				if (degree[i] != other.degree[i])
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator!=(const University &other)
	{
		return !(*this == other);
	}
	const University &operator=(const University other)
	{
		if (*this != other)
		{
			info = other.info;
			numDegree = other.numDegree;
			degree = new Degree[numDegree];
			for (int i = 0; i < numDegree; i++)
			{
				degree[i] = other.degree[i];
			}
		}
		return *this;
	}
	void read(istream &rd)
	{
		rd >> info;
		rd >> numDegree;
		degree = new Degree[numDegree];
		rd.ignore();
		for (int i = 0; i < numDegree; i++)
		{
			rd >> degree[i];
		}
	}
	void write(ostream &wr) const
	{
		wr << info;
		wr << "the number of Degree offered in University are : " << numDegree << endl;
		for (int i = 0; i < numDegree; i++)
		{
			wr << degree[i] << endl;
		}
	}
	void _student()
	{
		MyString name;
		cout << "Enter the Last Name of Student You Want to find :" << endl;
		cin >> name;
		for (int i = 0; i < numDegree; i++)
		{
			degree[i].findStudents(name);
		}
	}
	void _teacher()
	{
		int _id;
		cout << "Enter the Id of teacher You Want to find (101 - 120) :" << endl;
		cin >> _id;
		for (int i = 0; i < numDegree; i++)
		{
			degree[i].findTeachers(_id);
		}
	}
	void _salary()
	{
		long long int S = 0;
		for (int i = 0; i < numDegree; i++)
		{
			S += degree[i].findSalaries();
		}
		cout << "The Total salary of teachers in the University is  :" << S << endl;
	}
	~University()
	{
		delete[] degree;
		cout << "Destructor" << endl;
	}
	void age()
	{

		MyString n;
		cout << "Enter the Last Name of Student You Want to find :" << endl;
		cin >> n;
		for (int i = 0; i < numDegree; i++)
		{
			degree[i].findAges(n);
		}
	}

private:
	Info info;
	int numDegree;
	Degree *degree;
};
ostream &operator<<(ostream &wr, const University &A)
{
	A.write(wr);
	return wr;
}
istream &operator>>(istream &rd, University &A)
{
	A.read(rd);
	return rd;
}
int main()
{
	University A;
	ifstream fin;
	fin.open("University.txt");
	if (fin.is_open())
	{
		fin >> A;
	}

	// cout << A << endl;
	// Date dateOfBirth1(17, 10, 2003);
	// Date dateOfBirth2(05, 8, 1965);
	// Date dateOfJoining(11, 5, 2005);
	// Student s("Muhammad", "Asaad", dateOfBirth1, "L1F22BSCS0568", "Pak Arab , Lahore",
	//	"10/09/2022", 2022, 3.6, "Object Oriented Programming", 50000);
	// Teacher t("Ahmad", "Shahbar", dateOfBirth2, "Johar Town Lahore", 500000, 101,
	//	"Phd. in Computer Science", "Dean", "11/5/2005");
	// Person* ptr2 = &t;
	// Person* ptr = &s;
	// First Prue Virtual Function
	/*ptr->display();
	ptr2->display();*/
	// Second Prue Virtual Function
	/*cout << *ptr << endl;
	cout << *ptr2 << endl;*/
	cout << "====================================================" << endl;
	cout << "\tUNIVERSITY MANAGEMENT SYSTEM" << endl;
	cout << "====================================================" << endl;
	int choice = 0;

	char flag;
	do
	{
		cout << "Press 1 : To See full database of University" << endl;
		cout << "Press 2 : To find a student by Name" << endl;
		cout << "Press 3 : To calculate the age of student by Name" << endl;
		cout << "Press 4 : To find a teacher by Employee Id" << endl;
		cout << "Press 5 : To Calculate teachers Salaries" << endl;
		cout << "Press 6 : To exit" << endl;
		cin >> choice;
		cin.ignore();
		if(choice==1){
			cout<<A<<endl;
		}
		if (choice == 2)
		{
			// function to find student by name
			A._student();
		}
		else if (choice == 3)
		{
			// function to calculate age of student by giving name
			A.age();
		}
		else if (choice == 4)
		{
			// function to find teacher by employee Id
			A._teacher();
		}
		else if (choice == 5)
		{
			// function to calculate teachers Salaries
			A._salary();
			cout << endl;
			// cin.ignore();
		}
		else if (choice == 6)
		{
			cout << "<--- You Exit the Program --->" << endl;
			break;
		}

		cout << "If you want to continue Press Y/y (YES) , if not Press N/n (NO)" << endl;
		cin >> flag;

	} while (flag != 'N' && flag != 'n');

	return 0;
}