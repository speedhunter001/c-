#include <iostream>
using namespace std;

template <class T>
void fun(T v){
	if (v == 0)
		throw "an int dude";
	else if (v == 'a')
		throw "a string man";
	cout << "I am not ullo ka patha" << endl;

}


int main(){
	// try {
	// 	//fun<int>(0);
	// 	//fun<char>('a');

	// 	char v = 'a';
	// 	fun<char>(v);
	// }

	// catch (const char * msg){
	// 	cout << msg << endl;
	// }
	string val = NULL;
}