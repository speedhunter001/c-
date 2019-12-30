#include <cmath>

int get_width(int x1, int x3) {
	return x3 - x1;
}

int get_height(int y1, int y3) {
	return y3 - y1;
}

int get_distance(int x1, int y1, int x2, int y2) {
	int distance;
	distance = sqrt( pow( (x2 - x1), 2 ) + pow( (y2-y1), 2 ) );
	return distance;
}