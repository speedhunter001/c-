#include <iostream>
using namespace std;

int main(){
	string s1,s2,s3;

	cout<<"Enter the first value : "<<endl;
	cin>>s1;

	cout<<"Enter the second vale : "<<endl;
	cin>>s2;

	cout<<"Enter the third value : "<<endl;
	cin>>s3;

	
	if (s1!="a1" || s1!="a2" || s1!="a3" || s1!="a4" || s1!="a5" || s1!="a6"|| s1!="a7"|| s1!="a8" || s1!="a9"){
		cout<<"Enter the correct first value : "<<endl;
		cin>>s1;
	}

	if (s2!="a1" || s2!="a2" || s2!="a3" || s2!="a4" || s2!="a5" || s2!="a6" || s2!="a7"|| s2!="a8" || s2!="a9"){
		cout<<"Enter the second correct value : "<<endl;
		cin>>s2;
	}

	if (s3!="a1" || s3!="a2" || s3!="a3" || s3!="a4" || s3!="a5" || s3!="a6" || s3!="a7"|| s3!="a8" || s3!="a9"){
		cout<<"Enter the third correct value : "<<endl;
		cin>>s3;
	}


	if (s1=="a1" || s1=="a2" || s1=="a3"   &&   s2=="a1" || s2=="a2" || s2=="a3"   &&   s3=="a1" || s3=="a2" || s3=="a3"){
		cout<<"Congratulations YOU WON"<<endl;

	} 

	else if (s1=="a4" || s1=="a5" || s1=="a6"   &&   s2=="a4" || s2=="a5" || s2=="a6"   &&   s3=="a4" || s3=="a5" || s3=="a6"){
		cout<<"Congratulations YOU WON"<<endl;
	}

	else if (s1=="a7" || s1=="a8" || s1=="a9"   &&   s2=="a7" || s2=="a8" || s2=="a9"   &&   s3=="a7" || s3=="a8" || s3=="a9"){
		cout<<"Congratulations yOU WON"<<endl;
	}



	else if (s1=="a1" || s2=="a1" || s3=="a1" &&  s1=="a4" || s2=="a4" || s3="a4" && s1=="a7" || s2=="a7" || s3=="a7"){
		cout<<"Congratulations yOU WON"<<endl;
	}

	else if ()


	return 0;
}