#include <iostream>
using namespace std;

class namaloom {
	public:
	void fun() {
		cout << "I am namaloom" << endl;
	}
};


class buyer : public namaloom{
	
	public:
	//virtual void do_nothing() = 0;
	buyer(){
		cout << "Hello constructor" << endl;
	}
	~buyer(){
		cout << "hello destructor" << endl;
	}
};

class ghareeb : public buyer {
	int h = 0;
	public:
	ghareeb(){
		cout << "I am so ghareeb" << endl;
		do_nothing();
	}
	void do_nothing(){
		cout << "DO NOTHING" << endl;
	}
	// ghareeb(){
	// 	cout << "I am so ghareeb" << endl;
	// 	do_nothing();
	// }
	~ghareeb(){
		cout << "I am rich so no more ghareeb.." << endl;
	}
};

int main(){
	ghareeb g;
	g.fun();
	return 0;
}