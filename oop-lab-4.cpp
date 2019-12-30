#include <iostream>
#include <cmath>
using namespace std;

struct point {
	int x,y;
};

struct user {
	string name;
	int age;
	char gender;
	double salary[4];
};

int distance_formula(point a,point b){
	int formula;
	formula = sqrt( pow( ( b.x - a.x ),2 ) + pow( ( b.y - a.y),2 ) );
	return formula;
	}

void print(user x){
	cout << " User " << endl;
	cout << x.name << endl;
	cout << x.age << endl;
	cout << x.gender << endl;
	for (int i=0; i<4; i++){
		cout << x.s0alary[i]  << " ";
		}
	cout <<endl;

	}


	
int main(){
	/*point p1,p2;

	cout << "Enter the value of p1.x : ";
	cin >> p1.x;
	cout << "Enter the value of p1.y : ";
	cin >> p1.y;

	cout << endl;

	cout << "Enter the value of p2.x : ";
	cin >> p2.x;
	cout << "Enter the value of p2.y : ";
	cin >> p2.y;

	cout << "The dictance formula of p1 and p2 is : " << distance_formula( p1,p2 ) <<endl;
 */
	user u1,u2;
	cout << "First User"	<<endl;
	
	cout << "Enter you name : ";
	cin >> u1.name;
	
	cout << "Enter your age : ";
	cin >> u1.age;

	cout << "Enter your gender : ";
	cin >> u1.gender;

	
	for (int i=0; i<4; i++){
		cout <<"Enter your salary : ";
		cin >> u1.salary[i];
	}


	cout << "Second User" <<endl;

	cout << "Enter you name : ";
	cin >> u2.name;
	
	cout << "Enter your age : ";
	cin >> u2.age;

	cout << "Enter your gender : ";
	cin >> u2.gender;

	
	for (int i=0; i<4; i++){
		cout <<"Enter your salary : ";
		cin >> u2.salary[i];
	}


	print( u1 );
	print( u2 );


	return 0;
}