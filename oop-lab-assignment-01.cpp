#include <iostream>
using namespace std;





int main(){
	cout<<"**PERSONAL INFORMATION**"<<endl;
	string first_name,middle_name,last_name,gender,marital_status,birth_month,country,city,religion,id,other,disability;
	string father,father_status,mother,mother_status,current_country,postal_code,phone_home,mobile_phone,school,shcool_status,school_start,school_end,native_language,how_long;
	string new_language,turkish,work_country,company,position,employment_status,employment_start,employment_end,responsibilities,exam,exam_date,exam_country,a_p_c,ngo,turkey,how_scholarship,turkey_relative,relatives_living,num_relatives;
	int birth_date,birth_year,siblings,street,building_number,door_number,school_marks,num_language,a_p_c_num;
	
	cout<<"First Name : ";
	cin>>first_name;
	if (first_name.length()>=3 && first_name.length()<=20)
		cout<<endl;
	else
		cout<<"You inputted your first name wrongly"<<endl;
	
	
	cout<<"Middle Name : ";
	cin>>middle_name;
	if (middle_name.length()>=3 && middle_name.length()<=20)
		cout<<endl;
	else
		cout<<"You inputted your middle_name wrongly"<<endl;

	
	cout<<"Surname : ";
	cin>>last_name;
	if (last_name.length()>=3 && last_name.length()<=20)
		cout<<endl;
	else
		cout<<"You inputted your last name wrongly"<<endl;
	

	cout<<"Gender : ";
	cin>>gender;
	if (gender=="Male" || gender=="male" || gender=="Female" || gender=="female" || gender=="third gender" )
		cout<<endl;
	else
		cout<<"You inputted wrong info related to gender"<<endl;


	cout<<"Marital Status : ";
	cin>>marital_status;
	if (marital_status=="Single" || marital_status=="single" || marital_status=="Divorced" || marital_status=="divorced" || marital_status!="Married" || marital_status!="married")
		cout<<endl;
	else	
		cout<<"You entered wrong info about your marital stauts"<<endl;


	cout<<"Your Birth Info: "<<endl;
	cout<<"Your Birth Year : ";
	cin>>birth_year;
	if (birth_year>=1910 && birth_year<=2018)
		cout<<endl;
	else
		cout<<"You inputted wrong year"<<endl;
	cout<<"Your Birth Month : ";
	cin>>birth_month;
	if (birth_month=="January" || birth_month=="February" || birth_month=="March" || birth_month=="April" || birth_month=="May" || birth_month=="June" || birth_month=="July" || birth_month=="August" || birth_month=="September" || birth_month=="October" || birth_month=="November" || birth_month=="December")
		cout<<endl;
	else	
		cout<<"You entered wrong info about birth month"<<endl;
	cout<<"Your Birth Date : ";
	cin>>birth_date;
	if (birth_date>=1 && birth_date<=31)
		cout<<endl;
	else
		cout<<"You entered wrong info about your birth date"<<endl;

	
	cout<<"Country of Birth : ";
	cin>>country;
	if (country.length()>=3)
		cout<<endl;
	else
		cout<<"You inputted your country name wrongly"<<endl;

	
	cout<<"City : ";
	cin>>city;
	if (city.length()>=3)
		cout<<endl;
	else
		cout<<"You inputted your city wrongly"<<endl;

	
	cout<<"ID number : ";
	cin>>id;
	if (id.length()==15) // 15 is because 2 hyphens are included
		cout<<endl;
	else
		cout<<"You inputted your id wrongly"<<endl;

	
	cout<<"Other citizenship : ";
	cin>>other;
	if (other=="Yes" || other=="yes" || other=="No" || other=="no" || other=="none")
		cout<<endl;
	else
		cout<<"You should either say yes or no"<<endl;;

	
	cout<<"Religion : ";
	cin>>religion;
	if (religion=="Islam" || religion=="Christianity" || religion=="Hinduism" || religion=="Buddhism" || religion=="islam" || religion=="hinduism" || religion=="christianity" || religion=="buddhism")
		cout<<endl;
	else
		cout<<"You inputted your religion wrongly"<<endl;

	
	cout<<"Disability status : ";
	cin>>disability;
	if (disability=="Blind" || disability=="blind" || disability=="Deaf" || disability=="deaf" || disability=="mentally ill" || disability=="Mental ill" || disability=="None" || disability=="none" || disability=="no")
		cout<<endl;
	else
		cout<<"You inputted your disability status wrongly"<<endl;



	
	cout<<"**Family information**"<<endl;
	cout<<"Father Name : ";
	cin.ignore();
	getline(cin,father);
	if (father.length()>=8 && father.length()<=40)
		cout<<endl;
	else
		cout<<"You inputted your father's name wrongly"<<endl;

	
	cout<<"Father status(Alive or Dead) : ";
	cin>>father_status;
	if(father_status=="Alive" || father_status=="alive" || father_status=="Dead" || father_status=="dead")
		cout<<endl;
	else
		cout<<"You inputted your father's status wrongly"<<endl;

	
	cout<<"Mother Name : ";
	cin.ignore();
	getline(cin,mother);
	if (mother.length()>=8 && mother.length()<=40)
		cout<<endl;
	else
		cout<<"You inputted your mother's name wrongly"<<endl;


	cout<<"Mother status(Alive or Dead) : ";
	cin>>mother_status;
	if (mother_status=="Alive" || mother_status=="alive" || mother_status=="Dead" || mother_status=="dead")
		cout<<endl;
	else
		cout<<"You inputted your mother's status wrongly"<<endl;


	cout<<"Number of siblings : ";
	cin>>siblings;
	if (siblings<=30)
		cout<<endl;
	else
		cout<<"You inputted your number of siblings wrongly"<<endl;


	cout<<"**Contact Info**"<<endl;
	cout<<"Current Country : ";
	cin>>current_country;
	if (current_country.length()>6)
		cout<<endl;
	else
		cout<<"You inputted your current country wrongly"<<endl;

	cout<<"Postal Code : ";
	cin>>postal_code;
	if (postal_code.size()>1)
		cout<<endl;
	else
		cout<<"You inputted your postal code wrongly"<<endl;

	cout<<"Phone(Home) : ";
	cin>>phone_home;
	if (phone_home.size()>=10)
		cout<<endl;
	else
		cout<<"You inputted your home phone number wrongly"<<endl;


	cout<<"Mobile Phone : ";
	cin>>mobile_phone;
	if (mobile_phone.size()==11)
		cout<<endl;
	else
		cout<<"You inputted your mobile phone wrongly"<<endl;


	cout<<"Street : ";
	cin>>street;
	if (street<1000)
		cout<<endl;
	else
		cout<<"You inputted your street wrongly"<<endl;


	cout<<"Building number : ";
	cin>>building_number;
	if (building_number<1000)
		cout<<endl;
	else
		cout<<"You inputted your building jnumber wrongly"<<endl;

	cout<<"Door number : ";
	cin>>door_number;
	if (door_number<1000)
		cout<<endl;
	else
		cout<<"You inputted your door number wrongly"<<endl;


	cout<<"How long have you been staying in your current address? : ";
	cin>>how_long;
	if (how_long.length()<100)
		cout<<endl;
	else
		cout<<"You inputted your stay time long"<<endl;


	cout<<"**Education Information**"<<endl;
	cout<<"Middle School Information :- "<<endl;
	cout<<"School : ";
	cin>>school;
	if (school.length()>50)
		cout<<endl;
	else
		cout<<"You inputted wrong info about your school"<<endl;


	cout<<"status(Graduated or Continueing) : ";
	cin>>shcool_status;
	if (shcool_status=="Graduated" || shcool_status=="graduated"){
		cout<<endl;
		cout<<"start date : "<<endl;
		cin>>school_start;
		cout<<"end date : ";
		cin>>school_end;
	}

	else if (shcool_status=="Continueing" || shcool_status=="continueing")
		cout<<endl;
	else
		cout<<"You inputted your wrong status about school"<<endl;


	cout<<"Your High School Marks or Grade : ";
	cin>>school_marks;
	if (school_marks<=1100)
		cout<<endl;
	else
		cout<<"You inputted your school marks wrongly"<<endl;
    //The website does not let me allow to click the bachelors degree option thats why I am not making a code for it

	cout<<"**Language Details**"<<endl;
	cout<<"Native Language : ";
	cin>>native_language;
	if (native_language.length()<20)
		cout<<endl;
	else
		cout<<"You inputted your native language wrongly"<<endl;


	cout<<" Number of Other language skills : ";
	cin>>num_language;
	if (num_language==0)
		cout<<endl;
	else if (num_language > 0 && num_language < 10){
		for (int i=1; i<=num_language; i++){
			cout<<":Your extra language number "<<i<<endl;;
			cin>>new_language;
		}
	}
	else if (num_language > 10)
		cout<<"You inputted wrong amount of languages"<<endl;


	cout<<"Do you have Turkish language skills or do you speak Turkish? : ";
	cin>>turkish;
	if (turkish=="yes" || turkish=="Yes" || turkish=="No" || turkish=="no")
		cout<<endl;
	else
		cout<<"You can only answer in yes or no"<<endl;



	cout<<"**Work Experience**"<<endl;
	cout<<"Your Work country where you are employed or were employed : ";
	cin>>work_country;
	if (work_country.length()<20)
		cout<<endl;
	else
		cout<<"You inputted wrong info about your country in which you worked or currently working"<<endl;


	cout<<"Company/Institution name : ";
	cin.ignore();
	getline(cin,company);
	if (company.length()<30)
		cout<<endl;
	else
		cout<<"You inputted your Company/Institution name wrongly"<<endl;


	cout<<"Your position : ";
	cin>>position;
	if (position.length() > 20)
		cout<<endl;
	else
		cout<<"You inputted wrong info about your position"<<endl;


	cout<<"Employment status(left or currently employed) : ";
	cin>>employment_status;
	if (employment_status=="left" || employment_status=="currently employed")
		cout<<endl;
	else
		cout<<"You inputted wrong info about your employment status"<<endl;


	cout<<"Employment start date : ";
	cin>>employment_start;
	if (employment_start.length()<15)
		cout<<endl;
	else
		cout<<"You inputted wrong info about your start date"<<endl;
	cout<<"Employment end date : ";
	cin>>employment_end;
	if (employment_end.length()<15)
		cout<<endl;
	else
		cout<<"You inputted wrong info about you end date"<<endl;


	cout<<"Please write five details about your responsibilities at this job : "<<endl;
	cin>>responsibilities;
	if (responsibilities.length()<50)
		cout<<endl;
	else
		cout<<"You inputted wrong info about your responsibilities"<<endl;


	cout<<"**Academic Qualification**"<<endl;
	cout<<"Given Exam : ";
	cin.ignore();
	getline(cin,exam);
	if (exam.length() <20)
		cout<<endl;
	else
		cout<<"You inputted wrong info about the exam you gave"<<endl;


	cout<<"Exam date : ";
	cin.ignore();
	getline(cin,exam_date);
	if (exam_date.length()<50)
		cout<<endl;
	else
		cout<<"You gave wrong info about the date"<<endl;


	cout<<"Country in which you gave exam : ";
	cin>>exam_country;
	if (exam_country.length()<20)
		cout<<endl;
	else
		cout<<"You gave wrong info about the country in which you gave exam"<<endl;


	

	cout<<"**Social Activities**"<<endl;
	cout<<"Any Award,Project or Certificate you ever received(Enter the numbers of these things) : ";
	cin>>a_p_c_num;
	for (int i=1; i<=a_p_c_num; i++){
		cout<<"Your received award,project or certificate number"<<i<<" : ";
		cin>>a_p_c;
		if (a_p_c.length()>30)
			cout<<"You inputted something wrong about your received award,project or certificate"<<endl;
	}


	cout<<"Any voluntary activities like any institution or NGO you served at : ";
	cin>>ngo;
	if (ngo.length()>30)
		cout<<"You inputted something wrong about your voluntary activities";




	cout<<"**Turkiye Experience**"<<endl;
	cout<<"Are you in Turkey now or have you ever been to Turkey? : ";
	cin>>turkey;
	if (turkey=="Yes" || turkey=="No" || turkey=="yes" || turkey=="no")
		cout<<endl;
	else
		cout<<"You have to answer only in yes or no"<<endl;
	cout<<"Please specify how you learned about this scholarship? : ";
	cin>>how_scholarship;
	if (how_scholarship.length()<50)
		cout<<endl;
	else
		cout<<"You iputted your answer long by exceeding the maximum limit of the answer"<<endl;
	cout<<"Do you have a relative who is currently or who is currently or was previously a holder of Turkiye Scholarship? : ";
	cin>>turkey_relative;
	if (turkey_relative=="Yes" || turkey_relative=="No" || turkey_relative=="yes" || turkey_relative=="no")
		cout<<endl;
	else
		cout<<"You are supposed to answer in yes or no"<<endl;
	cout<<"Do you have any relatives living in Turkey?";
	cin>>relatives_living;
	if (relatives_living=="Yes" || relatives_living=="yes"){
		cout<<"Please specify how may of your relatives are living in Turkey ? : ";
		cin>>num_relatives;
	}
	else if (relatives_living=="No" || relatives_living=="no")
	cout<<endl; 
	else 
		cout<<"You are only supposed to answer in yes or no"<<endl;

	return 0;
}