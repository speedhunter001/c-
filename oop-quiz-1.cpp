#include <iostream>
#include <cassert>
using namespace std;

int fun1(string s,int pos){
	string x;
	if (pos<0)
		return 0;
	int digit;
	x=s[pos];
	digit=stoi(x);
	return digit;
}

string fun2(string s1,string s2){
	int d1,d2,maximum,sum;
	int carry=0;
	string sum_string,sum_string_in_tens,out_string;
	
	if ( s2.length()<s1.length() ){
		while ( s2.length()<s1.length() ){
			s2 = "0" + s2;
		}
	}
	else if ( s1.length()<s2.length() ){
		while ( s1.length()<s2.length() ){
			s1 = "0" + s1;
		}
	}
	
	maximum = max(s1.length(),s2.length());
	out_string = "";
	for (int i=maximum-1; i>=0; i--){
		d1 = fun1(s1,i);
		d2 = fun1(s2,i);
		sum = d1 + carry + d2;
		if ( (d1 + d2) >10 ){
			sum_string_in_tens = to_string(sum);
			sum_string = sum_string_in_tens[1] ;
			carry = fun1(sum_string_in_tens,0);
			out_string = sum_string + out_string;

		}
		else if ( (d1 + d2) <10 ){
			sum_string = to_string(sum);
			carry = 0;
			out_string = sum_string + out_string;
		}

		
	}

	return out_string;
} 

string fun3(string s){
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
/*
void  test_fun2(){
	assert ("3333333333333333333333344444444555555555555555555" == fun2("1111111111111111111111111111111222222222222222222","2222222222222222222222233333333333333333333333333") );
	cout << "yahoo the test passed" <<endl; 
} */


int main(){
	int x[] = {1,2,3};
	cout<<fun1("123",1)<<endl;
	// cout <<to_string(fun1("123",1))<<endl;   //to_string is used for converting a number in a string form
	// cout << max(5,10) <<endl; 
	//cout <<fun2("1111111111111111111111111111111222222222222222222","2222222222222222222222233333333333333333333333333") <<endl;
	cout <<fun2("1234","19") <<endl;
	cout <<fun3("My name is Ammar") <<endl;
	
	return 0;
}