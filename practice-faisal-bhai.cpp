#include <iostream>
using namespace std;

void fun(int x[],int y){
	
	int p=0 ;
	int q=0 ;
	int c=0 ;
	
	for (int i=0;i<6;i++){
		
		if (x[i]==y && c==0){
			p=i;
			c=c+1;
			}

		else if (x[i]==y && c!=0){
			q=i;
			c=c+1;
			}
		

		else if (i==5 && c==0){
			p=-1;
			q=-1;
			}

		else if (i==5 and q==0){
			q=p;
			}
		}
	int a[]={p,q};
	cout<<"{" <<p <<"," <<q <<"}" <<endl;

	}


void fun2(int s,int t,int a,int b,int m,int n,int apples[],int oranges []){
	
	int x[]={};
	int fallen=0;
	int c_a=0;
	int sum=0;
	int y[]={};
	int c_o=0;

	
	for (int i=0;i<m;i++){     //sums the distance and size of apples
		fallen=apples[i];  
		x[i]=fallen+a;
		}
	
	
	for (int i=0;i<m;i++){     //gives us the apples in the range of s and t
		sum=x[i];
		if (sum >= s && sum <= t){
			c_a= c_a + 1;
			}
		}

	
	for (int i=0; i<n; i++){ 	   //sums the distance and size of oranges
		fallen=oranges[i];
		y[i]=fallen+b;
		}
	

	for (int i=0;i<n;i++){    //gives us the oranges in the range of s and t
		sum=y[i];
		if (sum >= s && sum <= t){
			c_o = c_o + 1;
			}
		}

	cout<<c_a<<endl;
	cout<<c_o<<endl;
}

void fun3(string string_numbers){
	int c=0;
	int end_index = string_numbers.length()-1;
	char x[] = {}
	

	for (int i=0; i<end_inddex; i++){

	}
}
int main() {
	int x[]={2,3,-4};
	int y[]={3,-2,-4};
	//fun2(7,10,4,12,3,3,x,y);
	
	int a[] = {5,7,7,8,8,10};
	int b[] = {1,7,7,1,8,1};
	

	fun( b,8);
	return 0; 
}

