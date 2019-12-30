#include <iostream>
#include <sstream>
using namespace std;

int string_or_char_to_int(string num_str) {
	stringstream stream(num_str);		//or     istringstream stream;    istringstream stream;  stream(num) is invalid
	int num;

	stream >> num;

	return num;
}

string int_to_string(int num) {
	stringstream stream;          			//or     ostringstream stream;    stringstream stream(num) or ostringstream stream(num) is invalid
	stream << num;
	return stream.str();
}

int main() {

	cout << string_or_char_to_int("550") << endl;
	cout << string_or_char_to_int("0") << endl;


	cout << int_to_string(500) << endl;
	cout << int_to_string(0) << endl;    
	return 0;
}