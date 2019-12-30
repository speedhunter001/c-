#include <iostream>
using namespace std;

// class user{
// 	private:
// 	static int x;

// 	public:
// 	user(){
// 		cout << "hello constructor" << endl;
// 		cout << next_user_id() << endl;
// 	}
// 	int next_user_id(){
// 		x++;
// 		return x;
// 	}
// 	~user(){
// 		cout << "hello destructor" << endl;
// 	}
// };
// int user::x = 0;

// int	fib(int n){
// 	static int x = 0;
// 	if ( n==-1 )
// 		return x;
// 	x++;
// 	if( n<=1 )
// 		return n;
// 	else
// 		return fib(n-2)+fib(n-1);
// }

class plugin{
	public:
	virtual void filter( int img[5][5] ) = 0;
	// void filter( int img[5][5] ) {
	// 	cout << "This flter is doing nothing" << endl;
	// }
};

class black : public plugin{
	public:
	void filter( int img[5][5] ){
		for ( int i = 0; i < 5; i++ ){
			for ( int j = 0; j < 5; j++ ){
				img[i][j] = 0;
			}
		}
	}
};

class white : public plugin{
	public:
	void filter( int img[5][5] ){
		for ( int i = 0; i < 5; i++ ){
			for ( int j = 0; j < 5; j++ ){
				img[i][j] = 255;
			}
		}
	}
};

void init( int pic[5][5] );
void print( int pic[5][5] );
plugin * select_plugin();


int main(){
	//user u[5];
	// fib(2);
	// cout << fib(-1) << endl;
	int test[5][5];
	init(test);
	print(test);
	cout << endl;

	//plugin p1;                         //generates an error bcs of being abstract class

	// white w;
	// w.filter(test);
	// print(test);
	// cout << endl;

	// black b;
	// b.filter(test);
	// print(test);
	// cout << endl;
	
	plugin * p2;
	p2 = select_plugin();
	p2->filter(test);
	print(test);
	return 0;
}


void init( int pic[5][5] ){
	for ( int i = 0; i < 5; i++ ){
		for ( int j =0; j < 5; j++ ){
			pic[i][j] = 999;
		}
	}
}

void print ( int pic[5][5] ){
	//cout << "{ ";
	for ( int i = 0; i < 5; i++ ){
		//cout << " { ";
		for ( int j = 0; j < 5; j++ ){
			cout << pic[i][j] << ' ';
		}
		//cout << " }";
		cout << endl;
	}
	//cout << "}" << endl; 
}

plugin * select_plugin(){
	plugin * p;
	string selection = "black";
	if ( selection == "black" )
		p = new black;
	else 
		p = new white;
	return p;
}