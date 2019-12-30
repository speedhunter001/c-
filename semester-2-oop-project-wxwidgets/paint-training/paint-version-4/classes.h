/*
PROJECT: PAINT
GROUP MEMBERS: AMMAR ABID P18-0016, MOMINA ATIF DAR P18-0030, SANA HAIDER P18-0011
SECTION: B
*/
#include <vector>
#include <string>
using namespace std;

class Point {
	private:
	int x;
	int y;

	public:
	void set_coordinates(int x, int y);
	int get_x();
	int get_y();	
	void print_point();
};

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

class Shapes {
	protected:
	int num_points;
	vector<Point> points;
	
	public:
	Shapes();
	virtual void set_points(vector<Point> input_points);
	virtual int get_num_points();
	virtual  vector<Point> get_points();
	virtual string get_shape_type() = 0;
};

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

class Triangle : public Shapes {
	public:
	Triangle();
	string get_shape_type();
};

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

class Square : public Shapes {
	public:
	Square();
	string get_shape_type();
};

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

class Rect : public Shapes {    
	public:
	Rect();	
	string get_shape_type();
};



class Circle : public Shapes {
	public:
	Circle();                
	string get_shape_type();
};


class Line : public Shapes {
	public:
	Line();                
	string get_shape_type();
};

/*
class Star : public Shapes{
	public:
	Star();    	
};

Star::Star(){
	num_points = 10;
}

class AnyDigit : public Shapes{
	public:
	Digit();                                          //we will adjust it somehow
};

class Digits : public AnyDigit{      
	public:                         //All these functons will use the functions from AnyDigit class         
	void make_one(); 
	void make_two();
	void make_three();
	void make_four();	
	void make_five();
	void make_six();
	void make_seven();
	void make_eight();
	void make_nine();  //we might provide the option to user to write a number and that no. of points will be set on screen, he may make what he wishes with them
};

class ColorFilling{			//We are not giving any parameters because we don't know how to access the colors yet
	public:						
	void check_boundaries();
	void color_fill();          //this will use the check_boundaries method and color within the boundaries, be it of shape or canvas
};

template <class T>             //not sure about the datatype of pencil pointer
class Pencil{
	private:
	T * pencil;

	public:
	void draw();             
};

template<class T>
class Eraser{
	private:
	T * eraser;
	
	public:
	void erase();
};	


class Zoom{                                      //OPTIONAL
	public:
	void zoom_in();
	void zoom_out();
};

class Text{										//OPTIONAL
	private:
	string text;

	public:
	void show_text_on_screen();
};

class Tutorial{                                  //OPTIONAL
	private:
	string message;

	public:
	void set_message(string message);
	string show_message();
};

*/
