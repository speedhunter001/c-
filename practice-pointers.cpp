#include <iostream>
using namespace std;



int main(){
	int x;

	x = 5 + 100 * 10;
	//cout << x << endl;
	
	int * y;

	y = &x;
	cout <<  y << endl;

	int * z;
	z = y;
	cout << *z << endl;

	return 0;
}