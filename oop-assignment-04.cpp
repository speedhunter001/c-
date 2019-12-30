#include <iostream>
using namespace std;

class database_manager{
	private:
	string database_username;
	string database_password;
	string database_server_location;
		
	public:
	virtual void set_database_username(string database_username_to_be_set) = 0;
	virtual void set_database_password(string database_password_to_be_set) = 0;
	virtual void set_database_server_location(string database_server_location_to_be_set) = 0;

	database_manager();
	databse_manager(string which_database);               //this constructor lets you choose which database you want to work on
	~database_manager();
}

class MariaDB : public database_manager{
	void set_database_username(string database_username_to_be_set);
	void set_database_password(string database_password_to_be_set);
	void set_database_server_location(string database_server_location_to_be_set);
};

class Postgres : public database_manager{
	void set_database_username(string database_username_to_be_set);
	void set_database_password(string database_password_to_be_set);
	void set_database_server_location(string database_password_to_be_set);	
};

class housing_sale_and_rental_website{
	protected:
    static int identifier;
    string password;

	public:
	void set_password(string password);
	// void show_identifier_and_password(){
	// 	cout << "identifier id : " << identifier << endl;
	// 	cout << "password is : " << password << endl;
	// }

	housing_sale_and_rental_website();
	
};

void housing_sale_and_rental_website::set_password(string password){
	this->password = password;
}

	housing_sale_and_rental_website::housing_sale_and_rental_website(){
		identifier++;
}

int housing_sale_and_rental_website::identifier = 0; 



class properties_types{
	protected:
	int area_of_the_property;
	string status;
	long cost;
	string detailed_description;
	
	public:
	virtual void set_area_of_the_property(int area) = 0;
	virtual void set_status(string s) = 0;
	virtual void set_cost(long c) = 0;
	virtual void detailed_description(string detailed_description_to_be_set) = 0;

	//virtual int no_of_rooms_each_furnished_or_not() = 0;
};

class apartment : public properties_types{
	private:
	int rooms;
	int how_many_furnished;
	int how_many_not_furnished;
	
	public:
	void set_area_of_the_property(int area);
	void set_status(string s);
	void set_cost(long c);
	void detailed_description(string detailed_description);

	void set_rooms_and_furnished_and_not_furnished(int rooms_to_be_set, int furnished_to_be_set, int not_furnished_to_be_set);
	void show_rooms_and_furnished_and_not_furnished();
};

class house : public properties_types{
	private:
	int rooms;
	int how_many_furnished;
	int how_many_not_furnished;
	
	public:
	void set_area_of_the_property(int area);
	void set_status(string s);
	void set_cost(long c);
	void detailed_description(string detailed_description);	

	void set_rooms_and_furnished_and_not_furnished(int rooms_to_be_set, int furnished_to_be_set, int not_furnished_to_be_set);
	void show_rooms_and_furnished_and_not_furnished();
};

class condo : public properties_types{
	private:
	int rooms;
	int how_many_furnished;
	int how_many_not_furnished;
	string amenities;
	
	public:
	void set_area_of_the_property(int area);
	void set_status(string s);
	void set_cost(long c);
	void detailed_description(string detailed_description);

	void set_rooms_and_furnished_and_not_furnished(int rooms_to_be_set, int furnished_to_be_set, int not_furnished_to_be_set);
	void set_amenities(string s);    //s will be gym,pool etc
	void show_rooms_and_furnished_and_not_furnished();
	void show_amenities();

};

class single_room : public properties_types{
	private:
	string shared_or_not;
	int room_sharing_limit;
	
	public:
	void set_area_of_the_property(int area);
	void set_status(string s);
	void set_cost(long c);
	void detailed_description(string detailed_description);

	void set_room_shared_or_not(string shared_or_not_to_be_set);
	void set_room_sharing_limit(int limit_to_be_set);
	void show_room_shared_or_not();
	void show_room_sharing_limit();
};



class sellers : public housing_sale_and_rental_website{
	private:
	string image_path;
	int image_height;
	int image_width;
	string properties;
	string sell_property = "available";
	long earnings;

	public:
	friend class buyers;

	void set_path_and_size(string path_to_be_set, int image_height_to_be_set, int image_width_to_be_set);
	void image_post(string image_path,int image_width,int image_height);
	void which_properties(string properties_to_be_set);
	void set_earnings(long earnings_to_be_set);
	void earnings_verification();
};

class buyers : public housing_sale_and_rental_website{
	private:
	property_being_rated;
	rating;

	public:
	void add_credit_to_account();
	void buy_property();        //changes the sell_property to sold

	void set_property_being_rated(string property_being_rated_to_be_set);
	void show_property_being_rated_and_buyer_identification();
	void rating_system(int num_of_stars);     //sets rating    
};

class website_administrators : public housing_sale_and_rental_website{
	
};

int main(){
	buyers u1;
	u1.set_password("yousuck");
	//u1.show_identifier_and_password();
	
	sellers u2;
	u2.set_password("ihateu");
	//u2.show_identifier_and_password();

	website_administrators u3;
	u3.set_password("life");
	//u3.show_identifier_and_password();

	properties * p;
	p = new apartment;
	cout << p->area_of_the_property;
	return 0;
}