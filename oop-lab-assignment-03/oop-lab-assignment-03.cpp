/*
Name : Muhammad Ammar Abid
Creation date : 10/3/2019
Problem Description : This assignment is of file handling but due to lack of time few things are missing
*/
#include <iostream>
#include <fstream>
using namespace std;
void question_01(){
	ifstream fin;
	ofstream fout;
	string path,expression,num_1,num_2,operated,div,mul,add,sub;
	char operation;
	int opening_bracket_index,closing_bracket_index,divide_index,multiply_index,add_index,sub_index,tens,units;
	

	//cout << "Enter the absolute or full path of your file with slashes : ";
	//cin >> path;
	
	fin.open("expressions.txt");
	fout.open("expressions-output.txt");

	while( !fin.eof() ){
		getline(fin,expression);
		
		while ( true ){
			
			if ( expression.find( ')' ) ){
				opening_bracket_index = expression.find( '(' );
				closing_bracket_index = expression.find( ')' );
				// no need for writing conditions for numbers in tens
				num_1 = expression[opening_bracket_index+1] + ' ';
				num_2 = expression[closing_bracket_index-1] + ' ';
				operation = expression[opening_bracket_index+2];

				cout << expression << endl;
				if ( operation == '/' ){
					operated = to_string( ( stoi(num_1) / stoi(num_2) ) );
				}

				if ( operation == '*' ){
					operated = to_string( ( stoi(num_1) * stoi(num_2) ) );
				}

				if ( operation == '+' ){
					operated = to_string( ( stoi(num_1) + stoi(num_2) ) );
				}

				if ( operation == '-' ){
					operated = to_string( ( stoi(num_1) - stoi(num_2) ) );
				}

				expression.replace(opening_bracket_index,closing_bracket_index+1,operated);
			}

			else if ( expression.find('/') ){
				divide_index = expression.find('/');
				if ( (int)(expression[divide_index-2]) >=48 && (int)(expression[divide_index-2]) <= 57 ){
					tens = divide_index-2;   // in 10/.. 1's index will be tens
					num_1 = expression[tens] + expression[divide_index-1];
				}
				else{
					tens = divide_index-1;
					num_1 = expression[tens] + ' ';
				}
				
				if ( (int)(expression[divide_index+2]) >=48 && (int)(expression[divide_index+2]) <= 57 ){
					units = divide_index+2;     // in ../10  0's index will be units
					num_2 = expression[divide_index+1] + expression[units];  
				}
				else{
					units = divide_index+1;
					num_2 = expression[units] + ' ';
				}
				cout << expression << endl;
				div = to_string( ( stoi(num_1) / stoi(num_2) ) );
				expression.replace(tens,units+1,div);
			}
			
			
			else if ( expression.find('*') ){
				multiply_index = expression.find('*');
				if ( (int)(expression[multiply_index-2]) >=48 && (int)(expression[multiply_index-2]) <= 57 ){
					tens = multiply_index-2;   // in 10*.. 1's index will be tens
					num_1 = expression[tens] + expression[multiply_index-1];
				}
				else{
					tens = multiply_index-1;
					num_1 = expression[tens] + ' ';
				}
				
				if ( (int)(expression[multiply_index+2]) >=48 && (int)(expression[multiply_index+2]) <= 57 ){
					units = multiply_index+2;     // in ..*10  0's index will be units
					num_2 = expression[multiply_index+1] + expression[units];  
				}
				else{
					units = multiply_index+1;
					num_2 = expression[units] + ' ';
				}
				cout << expression << endl;
				mul = to_string( ( stoi(num_1) * stoi(num_2) ) );
				expression.replace(tens,units+1,mul);
			}

			
			else if ( expression.find('+') ){
				add_index = expression.find('+');
				if ( (int)(expression[add_index-2]) >=48 && (int)(expression[add_index-2]) <= 57 ){
					tens = add_index-2;   // in 10+.. 1's index will be tens
					num_1 = expression[tens] + expression[add_index-1];
				}
				else{
					tens = add_index-1;
					num_1 = expression[tens] + ' ';
				}
				
				if ( (int)(expression[add_index+2]) >=48 && (int)(expression[add_index+2]) <= 57 ){
					units = add_index+2;     // in ..+10  0's index will be units
					num_2 = expression[add_index+1] + expression[units];  
				}
				else{
					units = add_index+1;
					num_2 = expression[units] + ' ';
				}
				cout << expression << endl;
				add = to_string( ( stoi(num_1) + stoi(num_2) ) );
				expression.replace(tens,units+1,add);

			}
		
			
			else if ( expression.find('-') ){
				sub_index = expression.find('-');
				if ( (int)(expression[sub_index-2]) >=48 && (int)(expression[sub_index-2]) <= 57 ){
					tens = sub_index-2;   // in 10-.. 1's index will be tens
					num_1 = expression[tens] + expression[sub_index-1];
				}
				else{
					tens = sub_index-1;
					num_1 = expression[tens] + ' ';
				}
				
				if ( (int)(expression[sub_index+2]) >=48 && (int)(expression[sub_index+2]) <= 57 ){
					units = sub_index+2;     // in ..-10  0's index will be units
					num_2 = expression[sub_index+1] + expression[units];  
				}
				else{
					units = sub_index+1;
					num_2 = expression[units] + ' ';
				}
				
				sub = to_string( ( stoi(num_1) - stoi(num_2) ) );
				expression.replace(tens,units+1,sub);
			}	

			else{
				fout << expression << endl;
			break;
			}
		
		}		
	}
	fin.close();
	fout.close();

}
void question_02(){
	"question-02";
	ifstream fin;
	ofstream fout;
	string correct_answers,id_and_answers,id,all_answers;
	char answer;
	char grade;
	int score = 0;
	int score_percentage = 0;
 

	id = "";
	all_answers = "";
	fin.open("question-02.txt");
	fout.open("question-02-output.txt");
	
	getline(fin, correct_answers);

	while ( !fin.eof() ){
		getline(fin, id_and_answers);
		
		for (int i = 0; i < 8; i++){    						//id 
			id = id + id_and_answers[i];
		}
		cout << id << endl;
		
		for ( int i = 10; i < 29; i++){   	//score calculation and all answers in a string 
			answer = id_and_answers[i];
			if ( answer == correct_answers[i-10] )
				score = score + 2;
			else if ( answer != correct_answers[i-10] )
				score = score - 1;
			else if ( answer == ' ' )      //I could have not written this condition but for the sake of understanding I did
				score = score + 0;

			all_answers = all_answers + answer;
		
		}
		cout << all_answers << endl;
		cout << score << endl;
		
		score_percentage = (score * 100) / 20 ;

		if ( score_percentage >= 90 && score_percentage <= 100 )						//grade calculation
			grade = 'A';
		else if ( score_percentage >= 80 && score_percentage < 90 )
			grade = 'B';
		else if ( score_percentage >= 70 && score_percentage < 80 )
			grade = 'C';
		else if ( score_percentage >= 60 && score_percentage < 70 )
			grade = 'D';
		else if ( score_percentage >= 0 && score_percentage < 60 )
			grade = 'F';
		else
			grade = 'F';
		cout << grade << endl;
		
		fout << id << " " << all_answers << " " << score << " " << grade << endl;
		
		id = "";
		score = 0;
		all_answers = "";
	}
	
	fin.close();
	fout.close();

}


void question_03(){
	"question-03";
	ifstream fin;
	ofstream fout;
	fstream f_both;
	char choice;
	string line,record_line,new_planet,new_population,new_gravity;
	int record_no,line_no;

	line_no = 0;

	
	while( true ){
		cout << "Press 'C' for copy,Press 'X' for cut,Press 'E or M' for edit/modify : ";
		cin >> choice;
		cin.ignore();
		if ( choice == 'C' ){
			fin.open("planet.txt");
			fout.open("copy.txt");

			while( !fin.eof() ){
				getline(fin,line);
				fout << line << endl;
			}

			fin.close();
			fout.close();
			break;
		}

		else if ( choice == 'X' ){
			fin.open("planet.txt");
			fout.open("cut.txt");

			while( !fin.eof() ){
				getline(fin,line);
				fout << line << endl;
			}

			fin.close();
			fout.close();
			
			fout.open("planet.txt");      //erasing data

			fout << endl;

			fout.close();
			break;
		} 

		else if ( choice == 'E' || choice == 'M' ){
			f_both.open("planet.txt");    //or 	f_both.open("planet.txt", ios::out | ios::in);
			
			cout << "Enter the record number you wish to change : ";
			cin >> record_no;
			while( !f_both.eof() ){

				getline(f_both,line);
				line_no = line_no + 1;
				
				if ( line_no-1 == record_no ){
					fin.open("planet.txt");
					for ( int i = 0; i < record_no + 2; i++){
						
						getline(fin,record_line);
						
					}
					fin.close();
					cout << "Your selection is : " << record_line << endl;
					cout << "Enter new name for this planet : ";
					cin >> new_planet;
					cout << "Enter planetary population : ";
					cin >> new_population;
					cout << "Enter planet's acceleration of gravity : ";
					cin >> new_gravity;
					cout << "The new contents have been placed " << endl; 
					line = to_string(record_no) + "	  " + new_planet + ":" + "  " + new_population + "  " + new_gravity ; //no need of to_string for others bcs they already are in string
					cin.ignore();
					f_both << line << endl;

					}

			
				}
				
				f_both.close();
				break;
			}
		else 
			cout << "Wrong Input,Please Try Again" << endl;
	
	}

}

struct Employee_struct{
		string first_name;
		string last_name;
		string father_name;
		int emp_number;      
		string blood_group;
		int emp_age;
		string factory_name;
		string department;
		int phone_number;   
		string email_address;
		string home_address;
		double salary[4];
};

void swap( Employee_struct &x, Employee_struct &y){
	Employee_struct a = x;
	Employee_struct b = y;
	x = b;
	y = a;
}

void question_04(){
	ifstream fin;
	ofstream fout;

	string line,f_n,l_n,fthr_n,b_g,dp,email,ha;
	int e_n,age,ph;
	double s1,s2,s3,s4;
	Employee_struct e[9];

	fin.open("employee.txt");
	fout.open("employee-output.txt");
	getline(fin,line);

	while ( !fin.eof() ){
		for ( int i = 0; i < 9; i++){

		fin >> f_n;
		e[i].first_name = f_n;
		fout << f_n << "    ";

		fin >> l_n;
		e[i].last_name = l_n;
		fout << l_n << "    ";

		fin >> fthr_n;
		e[i].father_name = fthr_n;
		fout << fthr_n << "    ";

		fin >> e_n;
		e[i].emp_number = e_n;
		fout << e_n << "      ";

		fin >> b_g;
		e[i].blood_group = b_g;
		fout << b_g << "      ";

		fin >> age;
		e[i].emp_age = age;
		fout << age << "      ";

		fin >> f_n;
		e[i].father_name = f_n;
		fout << f_n << "      ";

		fin >> dp;
		e[i].department = dp;
		fout << dp << "      ";

		fin >> ph;
		e[i].phone_number = ph;
		fout << ph << "      ";

		fin >> email;
		e[i].email_address = email;
		fout << email << "    ";

		fin >> ha;
		e[i].home_address = ha;
		fout << ha << "    ";

		fin >> s1;
		e[i].salary[0] = s1;

		fin >> s2;
		e[i].salary[1] = s2;

		fin >> s3;
		e[i].salary[2] = s3;

		fin >> s4;
		e[i].salary[3] = s4;

		for ( int j = 0; j < 4; j++){             //salary incrementation
			e[i].salary[j] = e[i].salary[j] + 5000;
			fout << e[i].salary[j] << "  ";
			}

		fout << endl;
		}
	}

	
	fin.close();
	fout.close();
}

int str_to_int(string s,int pos){
	string x;
	if (pos<0)
		return 0;
	int digit;
	x=s[pos];
	digit=stoi(x);
	return digit;
}

int main(){
	//question_01();
	//question_02();
	//question_03();
	//question_04();

	return 0;
}


