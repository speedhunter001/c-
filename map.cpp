#include <iostream>
#include <map>
using namespace std;

void output_map_1(map<int, int> m) {
	cout << "{ ";
	for ( auto itr = m.begin(); itr != m.end(); itr++ ) {
		cout << " " << itr->first << " : " << itr->second << ", ";
	}
	cout << "}" << endl;
}

void output_map_2(map<string, int> m) {
	cout << "{";
	for ( auto itr = m.begin(); itr != m.end(); itr++ ) {
		cout << " " << itr->first << " : " << itr->second << ", ";
	}
	cout << "}" << endl;
}

int main() {

	// map<int, int> m_ex;
	// m_ex.insert( pair<int, int>(1,10) );
	// m_ex.insert( pair<int, int>(2,20) );
	// m_ex.insert( pair<int, int>(2,40) ); //ignored so can't update through insertion
	// output_map_1(m_ex);

	// m_ex.insert( pair<int, int>(3,30) );
	// output_map_1(m_ex);

	// m_ex.erase(2);
	// output_map_1(m_ex);

	// cout << "The value of key 1 is : " << m_ex[1] << endl;
	// cout << "The value of key 7 is : " << m_ex[7] << endl; //this key does not exist but there will be zero in this key and now there is a key of 7 with value 0
	// output_map_1(m_ex);

	// cout << "Count for key 1 is : " << m_ex.count(1) << endl;

	// if ( m_ex.count(711) > 0 ) 
	// 	cout << "Value for key 711 is : " << m_ex[711] << endl;
	// else 
	// 	cout << "The key 711 does not exist" << endl; 


	// //This method also does insetion and is the same as python but is not recommended 
	// m_ex[4] = 40;      //not in the end
	// output_map_1(m_ex);
	// m_ex[8] = 80;
	// output_map_1(m_ex);  //key 8 in the end no idea why but is greater than 7 at the end I guess

	// m_ex[1] = 100;
	// output_map_1(m_ex);  //now this overwrites

	

	map<string, int> m2;
	m2.insert( pair<string, int>( "one", 1 ) );
	m2.insert( pair<string, int>( "two", 2 ) );
	m2.insert( pair<string, int>( "three", 3 ) );
	m2.insert( pair<string, int>( "three", 5000 ) );	//ignored so can't update through insertion
	output_map_2(m2);

	m2.erase("three");
	output_map_2(m2);

	cout << "The value of key one is : " << m2["one"] << endl;	
	cout << "The value of key four(which does not exist but notice the bewakoofi after this) is : " << m2["four"] << endl;
	output_map_2(m2);
	m2.erase("four");
	output_map_2(m2);

	cout << "The count for key four is : " << m2.count("four") << endl;  //means if one then it exists

	if ( m2.count("fifty") )
		cout << "The value of key fifty is : " << m2["fifty"] << endl;
	else 
		cout << "The key fifty does not exist" << endl;

	//This method also does insetion and is the same as python but is not recommended but this method lets us update 
	m2["four"] = 4;
	m2["five"] = 5;
	m2["three"] = 3;
	output_map_2(m2);

	m2["one"] = 1000000;  //now key one is updated
	output_map_2(m2);

	//so now proved that in map is insertion in the alphabatecal order

	return 0;
}