#include <iostream>
using namespace std;

class Buyer {
	private:
	long money;
	string buyer_or_ghareeb;

	public:
	Buyer() {
		money = 1000000;
		buyer_or_ghareeb = "BUYER";
		cout << "IN BUYER CONSRUCTOR  " << money << endl;
	}
	
	virtual void status() {
		cout << "I am only a buyer with " << money << " ruppees" << endl;
	}

	string get_B_G() {
		return buyer_or_ghareeb;
	}
};

class Ghareeb : public Buyer {
	private:
	long money;

	public:
	Ghareeb() {
		long money = 0;
		//buyer_or_ghareeb = "GHAREEB";  this is not possible bcs buyer_or_.. is private member of buyer 
		cout << "IN GHAREEB CONSTRUCTOR  " << money << endl;
	}
	// void status() {
	// 	cout << "I am a ghareeb with " << money << " ruppees" << endl;
	// }
};

int main(){
	
	Buyer * b;
	b = new Ghareeb;
	b->status();

	//cout << b->get_B_G << endl;
	cout << b->get_B_G() << endl;   //but we can access the private variable of parent through inherited getter 

	return 0;
}