#include <iostream>
using namespace std;

class a
{
	public:
	int d;
	void fun1(){
	 e=2; 
	}
	private:
	int e;
	protected:
	int c;
};

// class b:public a {
// 	public:
// 	int f;
// 	void fun() {
// 		d=2; c=5; // Protected member can be accessed here e=5 ;
// 		// error private can't be accessed here fun1();
// 	}
// };

// class b:protected a {
// 	public:
// 	int f;
// 	void fun() {
// 		d=2;
// 		c=5; // Protected member can be accessed here
// 		e=1000 ; // error private can't be accessed here
// 		fun1();
// 	}
// }

// class b:private a {
// 	public:
// 	int f;
// 	void fun() {
// 		d=2; // public can be accessed because now this is private member
// 		c=5; // Protected member can be accessed here because now this is private member
// 	}
// };

class Person {
	public:
	string name, id;
	Person();
};

Person::Person() {
	cout << "Constructor of Person class has been called" << endl;
}



class Student : virtual public Person {
	public:
	string roll_no;
	Student();
};

Student::Student() {
	cout << "Constructor of Student class has been called" << endl; 
}



class Faculty : virtual public Person {
	public:
	int salary;
	Faculty();
};

Faculty::Faculty() {
	cout << "Constructor of Faculty has been called" << endl;
}

class TA : public Student, public Faculty {
	public:
	TA();
};

TA::TA() {
	cout << "Constructor of TA class has been caled" << endl;
}

int main() {
	// b obj;
	// obj.d=3; //public member directly accessed here g.c=4;
	// //protected member can't be accessed here g.fun();
	// system("pause");
	

	// b obj;
	// obj.d=3; //public member can’t be accessed here directly
	// //because now it is protected member
	// obj.c=4;//protected member can't be accessed here
	// system("pause");


	// b obj;
	// obj.d=3; // error public member can't be accessed here directly
	// //because now it is private member
	// obj.fun();//protected member can't be accessed here
	// system("pause");

	TA t1;
	t1.name = "jinbaba";
	t1.id = "p18000";

	cout << t1.name << endl;
	cout << t1.id << endl;


	return 0;
}