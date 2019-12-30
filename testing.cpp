#include <iostream>
#include <sstream>
#include <cassert>
using namespace std;

int fun1(string s,int pos){    /* It takes a string of numbers and a position and 
								returns the number in the integer form at that position */
	string x;                    
	int digit;
	x=s[pos];
	digit=stoi(x);
	return digit;
}

string fun2(string s){     	   // It takes a string and returns the ulta form of that string
	string string_input_chunk = "";
	string string_output = "";
	for (int i=0; i<s.length(); i++){
		if ( s[i] == ' ' || i+1 == s.length() ){
			if ( s[i] != ' ')
				string_input_chunk = string_input_chunk + s[i];
			string_output = string_input_chunk + ' ' + string_output;
			string_input_chunk = "";
		}
		else
			string_input_chunk = string_input_chunk + s[i];
	}
	return string_output;
}
 //Here Goes testingw
void test_fun1(){
	assert( 2 == fun1("12",1) );
	cout << "Passed the test" <<endl;
}

void test_1_fun2(){
	assert ( "test the fail to want don't I Plea " == fun2("Please!! I don't want to fail the test") );
	cout << "Yahoo I Passed the second test!!" <<endl;
}

void test_2_fun2(){
	//string result = "human a not am I" ;
	assert ( "human a am I " == fun2("I am a human") );
	cout << "Yahoo the test passed" <<endl;
}

int main(){
	test_fun1();
	test_1_fun2();
	test_2_fun2();

	return 0;
}