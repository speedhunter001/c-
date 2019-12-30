#include <vector>
#include <sstream>
using namespace std;

vector<int> string_to_int(string points_str) {
	string num_str = "";
	int num;
	vector<int> points;

	for ( int i = 0; i < points_str.length(); i++ ) {
		if ( points_str[i] == ',' ) {
			istringstream stream(num_str);
			stream >> num;
			points.push_back(num);
			num_str = "";
		}
		else {
			num_str = num_str + points_str[i]; 
		}
	}
	istringstream stream(num_str);
	stream >> num;
	points.push_back(num);

	return points;
}
