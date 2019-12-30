#include <iostream>
using namespace std;



int main() {

	//int a[];         //only this is not possible
	//char x = 'A';
	//cout << x+1 << endl;   //here x will be treated as ascii value
	//char a[6] = "hello";     //6 is here because there are 6 elements at 0 index is h and at 5 index is '\0'
	//cout << a << endl;       //full string outputted

	int a = 50;
	if (true){
		int a = 30;
		cout << a << endl;
	}
	cout << a << endl;

	return 0;
}