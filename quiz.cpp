#include <iostream>
#include <algorithm>
using namespace std;

int find_neighbours_sum( int a[][3], int num_row, int num_column ){
	int sum_upper_area, sum_same_row, sum_lower_area, total_sum;

	if ( a[num_row-1][num_column-1] == 0 || a[num_row-1][num_column-1] == 1  && a[num_row-1][num_column]==0 || a[num_row-1][num_column] == 1  && a[num_row-1][num_column+1] == 0 || a[num_row-1][num_column+1] == 1 )
		sum_upper_area = a[num_row-1][num_column-1] + a[num_row-1][num_column] + a[num_row-1][num_column+1];
	else if ()
	if ( a[num_row][num_column-1] == 0 || a[num_row][num_column-1] == 1  && a[num_row][num_column+1]==0 || a[num_row][num_column+1] == 1  )
		sum_same_row = a[num_row][num_column-1] + a[num_row][num_column+1];
	
	if ( a[num_row+1][num_column-1] == 0 || a[num_row+1][num_column-1] == 1  && a[num_row+1][num_column]==0 || a[num_row+1][num_column] == 1  && a[num_row+1][num_column+1] == 0 || a[num_row+1][num_column+1] == 1 )
		sum_lower_area = a[num_row+1][num_column-1] + a[num_row+1][num_column] + a[num_row+1][num_column+1];

	total_sum = sum_upper_area + sum_same_row + sum_lower_area;
	if ( total_sum < 2 ) 
		return 0;
	else if ( total_sum == 2 || total_sum == 3 )  //also works for total_sum == 3 which could have been another condition
		return 1;
	else if ( total_sum > 3 )
		return 0;
} -
/*
int * game_of_life(int a[]){

	for (int i = 0; i < length; i++){
		for (int j = 0; j < length; j++){

		}
	}
}

*/
int main(){
	
	int x[][3] = {                 //multidimensional array must have bounds except the first one
				{0, 1, 0},
				{0, 0, 1},
				{1, 1, 1},
				{0, 0, 0}
			   };
	cout << find_neighbours_sum( x, 2, 1) << endl;	
	return 0;



}