/*
PROJECT: PAINT
GROUP MEMBERS: AMMAR ABID P18-0016, MOMINA ATIF DAR P18-0030, SANA HAIDER P18-0011
SECTION: B
*/


#include <iostream>
#include "classes.h"
using namespace std;

void Point::set_coordinates(int x, int y) {
	this->x = x;
	this->y = y;
}

int Point::get_x() {
	return x;
}

int Point::get_y() {
	return y;
}

void Point::print_point() {
	cout << "( "<< x <<" , " << y << " )" << endl;
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

Shapes::Shapes(){
	num_points = 0;
}

void Shapes::set_points(vector<Point> input_points) {
	points = input_points;
}

int Shapes::get_num_points() {
	return num_points;
}

vector<Point> Shapes::get_points() {
	return points;
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

Triangle::Triangle() {
	num_points = 3;
}

string Triangle::get_shape_type() {
	return "TRIANGLE";
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

Square::Square(){
	num_points = 4;
}

string Square::get_shape_type() {
	return "SQUARE";
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

Rectangle::Rectangle(){
	num_points = 4;
}

string Rectangle::get_shape_type() {
	return "RECTANGLE";
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
/*
Circle::Circle(){
	num_points = 1;     //like we need centre so only one point  
}

void Circle::set_radius(int r) {
	radius = r;
}

int Circle::get_radius() {
	return radius;
}

int Circle::get_num_points() {
	return num_points;
}

Point * Circle::get_points() {
	return points;
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

Line::Line(){
	num_points = 2;
}

int Line::get_num_points() {
	return num_points;
}

Point * Line::get_points() {
	return points;
}
*/
