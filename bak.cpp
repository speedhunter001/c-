#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

//int *foo (){

	//int arr[12]={1,2,3,4,5,6,7,8,9,10,11,12};
	//return arr;
//}

bool palindrome_without_pointer(string x,int y);


int main() {

  //int *ptr = 0;
  //ptr=foo();
		//string u = "AnnA";
		
		//cout<<palindrome_without_pointer(u,4)<<endl;
		int array[]={1,2,3,4,5,6};
		cout<<*find(array,array+5,2)<<endl;
	
  return 0;
}

bool palindrome_without_pointer(string x,int y){
	int endindex=y-1;
	for (int i=0; i<ceil(y/2); i++){
		if (x[i] != x[endindex-i])
			return false;
	}
	return true;
}