#include <iostream>
using namespace std;

class Employee{
	public:
	int salary;

	void sign_in();
	Employee();            //constructor
	Employee(int salary);  //constructor or we are using constructor overloading

	~Employee();

};

void Employee::sign_in(){
	cout << "Signing in the employee" << endl;
}

Employee::Employee(){
	cout << "Employee() instance being created....." << endl;
	salary = 10000;
}

Employee::Employee(int salary){
	cout << "Employee(salary) instance being created with salary....." << endl;
	this->salary = salary;
}

Employee::~Employee(){
	cout << "Destruction Destruction Destruction ... ... ..." << endl;
}
int main(){
/*	Employee e1;
	cout << e1.salary << endl;

	Employee e2(70000);
	cout << e2.salary << endl;

	Employee * e1;
	e1 = new Employee;    
	cout << "Salary : " << e1->salary << endl;
*/
	Employee * e;
	
	e = new Employee();      // e = new Employee;
	cout << "Salary : " << e->salary << endl;
	delete e;
	cout << endl;

	e = new Employee(500000000);
	cout << "Salary : " << e->salary << endl;
	delete e;
	e = NULL;

	return 0;
}