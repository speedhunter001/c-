#include <iostream>
using namespace std;

int main(){

string first_name,last_name,email;
string phone_number;

cout<<"First Name : ";
getline(cin,first_name);
if (first_name.length()>=6 && first_name.length()<=20)
	cout<<endl;

else
	cout<<"You entered your first name wrongly"<<endl;


cout<<"Last Name : ";
getline(cin,last_name);
if (last_name.length()>=6 && last_name.length()<=20)
	cout<<endl;
else
	cout<<"You entered your last name wrongly";


cout<<"email address : ";
getline(cin,email);
if (email.find("@"))
	cout<<endl;
else 
	cout<<"You entered wrong email address"<<endl;

cout<<"Phone Number : ";
cin>>phone_number;
if (phone_number.size()==11)
	cout<<endl;
else
	cout<<"You entered wrong standard of number"<<endl;	

	return 0;
}