#include <iostream>
using namespace std;

void fun_1(int a ,int b){     //pass by value concept
	a = 500;
	b = 300;
}

void fun_2(int &a,int &b){    //pass by reference concept
	a = 500;
	b = 300;

}

void swap_1(int x,int y){
	int a = x;
	int b = y;

	x = b;
	y = a;
}


void swap_2(int &x,int &y){
	int a = x;
	int b = y;

	x = b;
	y = a;
}

int max_nums(int num_1,int num_2,int num_3,int num_4,int num_5){
	int parameters[] = {num_1,num_2,num_3,num_4,num_5};
	int max = parameters[0];
	for (int i = 0; i < 5; i++){
		if ( parameters[i] > max)
			max = parameters[i];
	}
	return max;
}

string max_string(string s1,string s2,string s3,string s4,string s5){
	string parameters[] = {s1,s2,s3,s4,s5};
	int max_length = parameters[0].length();
	string max_string = "";
	for (int i = 0; i < 5; i++){
		if ( parameters[i].length() > max_length){
			max_length = parameters[i].length();
			max_string = parameters[i];
		}

	}
	return max_string;
}


char To_upper(char ch){
	int asci_value_lower,asci_value_upper;
	char value_upper;
	if ( (int)ch >= 65 && (int)ch <97)
		return ch;
	else{
	asci_value_lower = (int)ch;
	asci_value_upper = asci_value_lower - 32;
	value_upper = (char)asci_value_upper;
	}
	return value_upper;
}

char To_lower(char ch){
	int asci_value_upper,asci_value_lower;
	char value_lower;
	if ( (int)ch >=97 && (int)ch <123)
		return ch;
	else{
	asci_value_upper = (int)ch;
	asci_value_lower = asci_value_upper + 32;
	value_lower = (char)asci_value_lower;
	}
	return value_lower;
}



int main(){
	/*cout <<"Hello world" <<endl;
	int x = 5;
	int y = 10;
	
	fun_1(x,y);	
	cout <<x <<"," <<y <<endl;

	fun_2(x,y);
	cout <<x <<"," <<y <<endl;
	
	int x = 5;
	int y = 10;

	swap_1(x,y);                           
	cout << x  << "," << y  << endl;

	swap_2(x,y);						//make sure to pass x and y variables to the parameter not the values directly
	cout << x  << ","  << y  <<endl;
	

	int a,b,c,d,e;
	a = 1;
	b = 2;
	c = 3;
	d = 10;
	e = 5;
	cout << max_nums(a,b,c,d,e) << endl; 
	
	string a,b,c,d,e;
	a = "Hi";
	b = "how";
	c = "wow";
	d = "hey bro how are you";
	e = "ting";
	cout << max_string(a,b,c,d,e) << endl;    //please note that if you give all strings of same size even if they are dfferent then it will give you the last string I think so ....
	*/

	cout << To_lower('X') <<endl;
	return 0;
}