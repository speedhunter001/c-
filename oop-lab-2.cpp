#include <iostream>
using namespace std;

int main(){
	//int s=0;
	//for (int i=1; i<=100; i++){
		//if (i%2!=0)
			//s=s+i;
			//cout<<i<<endl;	
	//}
	//cout<<s<<endl;
	
	
	//int i=1;
	//int s=0;
	//while (i<=100){
		//if (i%2==1)
			//s=s+i;
		//i++;   //never forget this bakayaro
	//}
	//cout<<s<<endl;
	

	



	//int number;
	//cout<<"Hey there! Give me a number I will give you its table : ";
	//cin>>number;
	//for (int i=1; i<=10; i++){
		//int j = number * i;
		//cout <<number <<" x " <<i <<" = " <<j <<endl;
	//}


	//int i=1;
	//int number;
	//cout<<"Hey there! Give me a number I will give its table : ";
	//cin>>number;
	//while (i<=10){
		//int j = number * i;
		//cout <<number <<" x " <<i <<" = " <<j <<endl;
		//i++; //I told you to not forrget this you baka
	//}


	

	

	//int factorial=1;
	//int number;
	//cout<<"Hey there! Give me a number and I will give you its facotrial : ";
	//cin>>number;
	//for (int i=1; i<=number; i++){
		//factorial = factorial * i;
	//}
	//cout<<factorial<<endl;
	

	//int factorial=1;
	//int number;
	//int i=1;
	//cout<<"Hey there! Give me a number and I will give you its factorial : ";
	//cin>>number;
	//while (i<=number){
		//factorial = factorial * i;
		//i++;
	//}
	//cout<<factorial<<endl;
	





	//int number;
	//int c=0;
	//cout<<"Hey there! Give me a number and I will tell you that either its a prime number or not : ";
	//cin>>number;
	//for (int i=1; i<=number; i++){
		//if (number%i==0)
			//c=c+1;
	//}
	//if (c==2 || c==1)
		//cout<<"Yay its a optimus prime"<<endl;    //optimus prime means that its a prime number
	//else
		//cout<<"Oh no its not a optimus prime"<<endl;
	





//for (int i=1; i<=5; i++){
	//for (int j=0; j<=10; j++){
		//cout<<" "<<j;
		//}
	//cout<<endl;
	//}






//for (int i=1; i<=5; i++){
	//for (int j=1; j<=i; j++){
		
		//cout<<" "<<j;
		//}
	//cout<<endl;
	//}








//for (int i=1; i<=5; i++){
	//for (int j=0; j<=10; j++){
		
		//cout<<" "<<j;
		//}
	//cout<<endl;
	//}








//for (int i=1; i<=5; i++){

	//for (int j=1; j<=i; j++){
		
		//cout<<" "<<j;
		//}
	//cout<<endl;
	//}






/*
for (int i=1; i<=5; i++){
	for (int j=4; j>=i; j--){
		cout<<" ";
	}
	for (int k=1; k<=i; k++){
		cout <<" " <<"*";
	}
	cout<<endl;
}  */



for (int i = 1; i <= 5; i++){
	if ( i == 1 || i == 5){
		for (int j = 1; j <= 5; j++){
			cout  << "*";
			}
		}
	else{
		for (int k = 1; k <= 5; k++){
			if ( k == 1 || k == 5)
				cout << "*";
			else
				cout << " ";
			}
		}
	
	
}


	return 0;
}