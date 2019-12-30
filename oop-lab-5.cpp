#include <iostream>
#include <fstream>
using namespace std;

int main(){
/*	ifstream fin;
	ofstream fout;
	string line;
	
	fin.open("input.txt");
	fout.open("output.txt");

	while (fin){
		getline(fin,line);
		fout << line << endl;
	}

	fin.close();
	fout.close();
*/
	ifstream fin;
	string line;

	fin.open("input-2.txt");
	while (fin){
		getline(fin,line);
		cout << line << endl;
	}

	fin.close();

	return 0;
}