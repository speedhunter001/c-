#include <iostream>
using namespace std;

int char_finder( char * c, char ch){
	int index = 0;
	while ( *c != ch ) {
		if ( *c == '\0' )
			return -1;
		index = index + 1;
		c = c + 1;   //incrementing the address
	}
	return index;
}

int digits_in_string( char * c ){
	int count = 0;
	while ( *c != '\0' ){
		if ( (int)(*c) >= 48 && (int)(*c) <=57 )
			count = count +1;
		c = c + 1; //incrementing the address
	}
	return count;
}
int main(){
	string x = "hello";
	string y = "A quick brown fox (id: 45) jumped over a lazy dog (id: 9)";
	string z = " I have a 1 bottle and 4 eggs";
	cout << digits_in_string( &y[0] ) << endl;
	return 0;
}