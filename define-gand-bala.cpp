#include <iostream>
#define SIZE 5
#define ABS(a) ( (a) < 0 ? -(a) : a )
#define INVENTORY                          //notice that I have not given anything here after Inventory
using namespace std;

#ifdef INVENTORY
	void showing_inventory(){
	cout << "Showing inventory stuff.HAHAHAH there is nothing here" << endl;
}
#endif

int main(){

	for (int i = 0; i < SIZE; i++){
		cout << i << endl;
	}

	cout << ABS(-25) << endl; 

#ifdef INVENTORY
	showing_inventory();
#endif


	return 0;
}