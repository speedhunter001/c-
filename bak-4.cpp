#include <iostream>
using namespace std;

class parent {
	private:
	int point;

	public:
	void set_point(int x){
		point = x;
		cout << point << endl;
	}
};

class child : public parent{

};

int main() {
	child l;
	l.set_point(5);
	return 0;
}