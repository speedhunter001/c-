/*
Name:Muhammad Ammar Abid
Creation date : 21/2/2019 10:49pm
Promblem description: This assignment is for the sake of practice of structs but I just found out that we have an assignment at 10pm
*/
#include <iostream>
using namespace std;

struct grade_rec {
	float percent;
	char grade;
};

struct student_rec{
	string fname;
	string iname;
	int age;
	double marks[5];
	grade_rec course_grade[5];
};
void input( student_rec x ){
	cout <<
}

void calculate_grade( double marks[] ){
	for (int i = 0; i < 5; i++){
		if ( marks[i] >= 91 )
			cout << "A+ ";
		else if ( marks[i] <=91  && marks[i] >=86  )
			cout << "A ";
		else if ( marks[i] <=86  && marks[i] >=82  )
			cout << "A- ";
		else if ( marks[i] <=82  && marks[i] >=78  )
			cout << "B+ ";
		else if ( marks[i] <=78  && marks[i] >=74  )
			cout << "B ";
		else if ( marks[i] <=74  && marks[i] >=70  )
			cout << "B- ";
		else if ( marks[i] <=70  && marks[i] >=66  )
			cout << "C+ ";
		else if ( marks[i] <=66  && marks[i] >=62  )
			cout << "C ";
		else if ( marks[i] <=62  && marks[i] >=58  )
			cout << "D+ ";
		else if ( marks[i] <=58  && marks[i] >=54  )
			cout << "D ";
		else if ( marks[i] <=54  && marks[i] >=50  )
			cout << "D- ";
		else if ( marks[i] < 50  )
			cout << "F ";	}
	cout << endl;	
}
int main(){
	student_rec s[5];
	cout << 
	return 0;
}