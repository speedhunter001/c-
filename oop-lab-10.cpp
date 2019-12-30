#include <iostream>
#include <vector>
using namespace std;

template<class T>
void output_vector_values(vector<T> v) {
	cout << "[ ";
	for (auto i = v.begin(); i != v.end(); i++)
		cout << *i << " ";
	cout << "]" << endl;
}

int main() {
	//vector<char> v1;
	// char value;

	// v1.push_back('h');
	// v1.push_back('e');
	// v1.push_back('l');
	// v1.push_back('l');
	// v1.push_back('o');
	
	// output_vector_values<char>(v1);
	
	
	// for (int i = 0; i < v1.size(); i++)
	// 	cout << v1[i] << endl;

	// cout << "Enter the value which you want to find in vector : ";
	// cin >> value;
	// for (int i = 0; i < v1.size(); i++) {
	// 	if (v1[i] == value) {
	// 		cout << "Found" << endl;
	// 		break;
	// 	}
	// 	else if (v1[i] == v1.back()) 
	// 		cout << "Not found" << endl;
	// }


	vector<double> v1, v2;
	int size, count;
	double input, v1_check, v2_check;

	size = 3;
	count = 0;

	cout << "Initialize v1 " << endl;
	for (int i = 0; i < size; i++) {
		cin >> input;
		v1.push_back(input);
	}
	output_vector_values(v1);

	cout << "Initialize v2 "<< endl;
	for (int i = 0; i < size; i++) {
		cin >> input;
		v2.push_back(input);
	}
	output_vector_values(v2);

	for (int i = 0; i < size; i++) {
		v1_check = v1[i];
		for (int i = 0; i < size; i++) {
			v2_check = v2[i];
			if (v2_check > v1_check)
				count = count + 1;
		}
		cout << "For element " << v1[i] << " at index " <<"'"<< i << "'" << " " << count << " elements are greater in v2" << endl;
		count = 0;
	}

	return 0;
}