#include <iostream>
#include <fstream>
using namespace std;

int main(){
	/*ifstream fin;
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
	ofstream fout;
	string line;
	int uppers = 0;
	int spaces = 0;
	int upper_conversion_ascii;
	char upper_conversion;
	string str;
	int words = 0;
	fin.open("input-2.txt");
	fout.open("output-2.txt");

	while( !fin.eof() ){
		getline(fin,line);
		cout << line << endl;
		
		for ( int i = 0; i < line.length(); i++){
			char ch = line[i];
			if ( ch == ' ' ){
				spaces = spaces + 1;\
				fout << ch;
			}

			else if ( (int)ch >= 65 && (int)ch < 97 ){
				uppers = uppers + 1;
				fout << ch;
			}
			else if ( (int)ch >= 97 && (int)ch < 123 ){
				upper_conversion_ascii = (int)ch - 32;
				upper_conversion = (char)upper_conversion_ascii;
				fout << upper_conversion;
			}
			else
				fout << ch;
		}

	}

	cout << "Spaces are : " << spaces << endl;
	cout << "Upper letters are : " << uppers << endl;
	

	fin.close();
	fout.close();

	fin.open("input-2.txt");
	while( !fin.eof() ){
		fin>>str;
		cout << str << endl;
		words = words + 1;
	}
	cout << "Words are : " << words << endl;
	fin.close();
	return 0;
}