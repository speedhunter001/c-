#include <iostream>
using namespace std;

void game_of_life( int a[4][3] ){
	int our_index = 0;
	int sum = 0;
	int b[4][3] = { { a[0][0],a[0][1],a[0][2] },
		   		    { a[1][0],a[1][1],a[1][2] },
		   		    { a[2][0],a[2][1],a[2][2] },
		   		    { a[3][0],a[3][1],a[3][2] }  };
	       
										
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			//cout <<"[" << i << "," << j <<"]" << endl;
			our_index = a[i][j];
			
			for (int k = 1; k > -3; k--) {       //neighbours accessing and sum 
  				for (int l = 1; l > -3; l--) {
					if ( i-k < 0 || j-l < 0 )
						continue;
					else if ( a[i-k][j-l] == 1 ){
						if ( i == i-k && j == j-l )
							continue;
						sum = sum + 1;
					}
				}
			}
		
			if ( our_index == 1 ){               //condition checking
				if ( sum < 2 )
					b[i][j] = 0;
				else if ( sum == 2 || sum == 3 )
					b[i][j] = 1;
				else if ( sum > 3 )
					b[i][j] = 0;
			
			}
			else if ( our_index == 0 ){
				if ( sum == 3 )
					b[i][j] = 1;
				else
					b[i][j] = 0;
			}
			sum = 0;
		}

	}
	cout << "{"  << "{" << b[0][0] <<"," << b[0][1] <<"," << b[0][2] <<"}" <<endl 
				<< "{"  << b[1][0] <<"," << b[1][1] <<"," << b[1][2] <<"}" <<endl
				<< "{"  << b[2][0] <<"," << b[2][1] <<"," << b[2][2] <<"}" <<endl
				<< "{"  << b[3][0] <<"," << b[3][1] <<"," << b[3][2] <<"}" <<endl
				<<"}" <<endl;
	
}

int main(){
	int x[4][3] = {                 //multidimensional array must have bounds except the first one
				{0, 1, 0},
				{0, 0, 1},
				{1, 1, 1},
				{0, 0, 0}
			     };
	game_of_life( x );
	return 0;
}