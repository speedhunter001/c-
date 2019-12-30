#include <iostream>
#include <vector>
using namespace std;

void output_vector_values(vector<int> v) {
	cout << "[ ";
	for (auto i = v.begin(); i != v.end(); i++)
		cout << *i << " ";
	cout << "]" << endl;
}

void output_vector_values_alternative(vector<int> v) {
	cout << "[ ";
	for (int x : v)
		cout << x << " ";
	cout << "]" << endl;
}

void reverse_output_vector_values(vector<int> v) {
	cout << "[ ";
	for (auto i = v.rbegin(); i!=v.rend(); i++)
		cout << *i << " ";
	cout << "]" << endl;
}

int main() {
	// vector<int> marks1, marks2;

	//cout << "Without Alternatives" << endl;
	// for(int i = 1; i <= 5; i++) 
	// 	marks1.push_back(i*10);
	// output_vector_values(marks1);

	// cout << "At index 2: " << marks1[2] << endl;

	// reverse_output_vector_values(marks1);

	// auto sar1 = marks1.begin();
	// cout << "Removing at index 1 : " << endl;
	// marks1.erase(sar1 + 1);
	// output_vector_values(marks1);
	
	// cout << "Removing at new index 2: " << endl;
	// marks1.erase(sar1 + 2);
	// output_vector_values(marks1);

	// cout << endl;

	// for (int i = 1; i <= 5; i++)
	// 	marks2.push_back(i*10);
	// output_vector_values(marks2);

	// auto sar2 = marks2.begin();

	// cout << "Removing at index 0: " << endl;
	// marks2.erase(sar2);
	// output_vector_values(marks2);

	// cout << "Removing at new index 0: " << endl;
	// marks2.erase(sar2);
	// output_vector_values(marks2);
	
	cout << "Through Alternatives " << endl;
	vector<int> marks1{10, 20, 30, 40, 50}, marks2{10, 20, 30, 40, 50};

	cout << "At index 2: " << marks1[2] << endl;

	auto sar1 = marks1.begin();
	cout << "Removing at index 1 : " << endl;
	marks1.erase(sar1 + 1);
	output_vector_values_alternative(marks1);
	
	cout << "Removing at new index 2: " << endl;
	marks1.erase(sar1 + 2);
	output_vector_values_alternative(marks1);

	cout << endl;

	output_vector_values_alternative(marks2);

	auto sar2 = marks2.begin();

	cout << "Removing at index 0: " << endl;
	marks2.erase(sar2);
	output_vector_values_alternative(marks2);

	cout << "Removing at new index 0: " << endl;
	marks2.erase(sar2);
	output_vector_values_alternative(marks2);
	return 0;
}