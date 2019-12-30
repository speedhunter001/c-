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



Shapes::Shapes(){
	num_points = 0;
	points = NULL;
}

void Shapes::plotting_points(int x1, int y1, int x2, int y2, int x3, int y3) {
	cout << "I cannot do anything" << endl;
}

int Shapes::get_num_points() {
	return num_points;
}

Point * Shapes::get_points() {
	return points;
}

Triangle::Triangle(){
	num_points = 3;
	points = NULL;
}

void Triangle::plotting_points(int x1, int y1, int x2, int y2, int x3, int y3) {
	points = new Point[num_points];
	
	points[0].set_coordinates(x1, y1);
	points[1].set_coordinates(x2, y2);
	points[2].set_coordinates(x3, y3);
}

int Triangle::get_num_points() {
	return num_points;
}

Point * Triangle::get_points() {
	return points;
}



Square::Square(){
	num_points = 4;
	points = NULL;
	square_width_height = 0;
}

void Square::plotting_points(int x1, int y1, int x2, int y2, int x3, int y3) {       //we need only x1,y1
	points = new Point[1];
	points[0].set_coordinates(x1, y1);
}

void Square::set_square_width_and_height(int w_h) {
	square_width_height = w_h;
}

int Square::get_square_width_and_height() {
	return square_width_height;
}

int Square::get_num_points() {
	return num_points;
	
	
}

Point * Square::get_points() {
	return points;
}



Rectangle::Rectangle(){
	num_points = 4;
	points = NULL;
	rectangle_width = 0;
	rectangle_height = 0;
}

void Rectangle::plotting_points(int x1, int y1, int x2, int y2, int x3, int y3) {     //we only need x1,y1
	points = new Point[1];
	points[0].set_coordinates(x1, y1);
}

void Rectangle::set_rectangle_width_and_height(int w, int h) {
	rectangle_width = w;
	rectangle_height = h;
}

int Rectangle::get_rectangle_width() {
	return rectangle_width;
}

int Rectangle::get_rectangle_height() {
	return rectangle_height;
}

int Rectangle::get_num_points() {
	return num_points;
}

Point * Rectangle::get_points() {
	return points;
}



Circle::Circle(){
	num_points = 1;     //like we need centre so only one point  
	points = NULL;
	radius = 0;
}

void Circle::plotting_points(int x1, int y1, int x2, int y2, int x3, int y3) {     //we only need x1,y1 for plotting the center
	points = new Point[1];
	points[0].set_coordinates(x1, y1);
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



Line::Line(){
	num_points = 2;
}

void Line::plotting_points(int x1, int y1, int x2, int y2, int x3, int y3) {       //we only need x1,y1 and x2,y2
	points = new Point[2];
	points[0].set_coordinates(x1, y1);
	points[1].set_coordinates(x2, y2);
}

int Line::get_num_points() {
	return num_points;
}

Point * Line::get_points() {
	return points;
}
