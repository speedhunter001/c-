#include <iostream>
using namespace std;

void ghareeb(int s = 5) {
	cout << s << endl;
}

void rich1(int s = 100000);
void rich2(int s);// this is not possible bcs when you declare the body later and you give a default argument

int main() {

	ghareeb();
	ghareeb(10);

	rich1();
	rich1(500000000);

	//rich2();
	//rich2(10000);

	return 0;
}

// void rich(int s = 100000) {      //This will give error
// 	cout << s << endl;
// }

void rich1(int s) {
	cout << s << endl;
}

// void rich2(int s = 1000000) {
// 	cout << s << endl;
// }