//*************************************************************************************************
//Billy Rodriguez  CS302  1/14/2025  PROGRAM_1
//
//These are the functions for the program
//*************************************************************************************************

#include "product.h"

//Base Class functions
Product::Product(): name(nullptr), price(0.0)
{}

Product::Product(const Product &to_copy): name(nullptr), price(to_copy.price)
{
	//allocate dynamic memory for name
	if(to_copy.name)
	{
		name = new char[strlen(to_copy.name) + 1];
		strcpy(name, to_copy.name);			//copy name
	}
}

Product::Product(const char * a_name, float a_price)
{
		name = new char[strlen(a_name) + 1];
		strcpy(name, a_name);				//copy name
		price = a_price;
}

//asssignment operator
Product& Product::operator=(const Product &source)
{
	//same object
	if(this == &source)
		return *this;
	
	//deallocate
	delete [] name;

	//valid name
	if(source.name)
	{
		name = new char[strlen(source.name) + 1];
		strcpy(name, source.name);
	}

	//empty name
	else
		name = nullptr;

	//set price	
	price = source.price;
	
	//return assigned object
	return *this;
}

//destructor
Product::~Product()
{
	delete [] name;
}

//display products
bool Product::display() const
{
	if(name)
		cout << "Product Name: " << name << endl;
	else
		cout << "Product Name: N/A " << endl;
	cout << "Price: $" << price << endl;	
		
	return true;
}

//compare names
bool Product::compare_name(const char * &a_name)
{
	//comparing original object name with passed in name
	if(this->name && a_name)
	{
		return (strcmp(this->name, a_name) == 0);
	}
	
	return false;
}

//compare prices
float Product::compare_price(const float a_price)
{
	//return the difference in price
	return this->price - a_price;
}
		
//discount any product
bool Product::apply_discount(float discount_percentage)
{
	if(discount_percentage > 0 && discount_percentage <= 100)
	{
		price -= price * (discount_percentage / 100);
		return true;
	}

	return false;
}

//apply name
bool Product::setName(const char * a_name)
{
	//deallocate existing name
	if(name)
		delete [] name;

	//allocate dynamic memory
	name = new char[strlen(a_name) + 1];
	strcpy(name, a_name);
	return true;
}

//apply price
bool Product::setPrice(float a_price)
{
	if(a_price > 0)
	{
		price = a_price;
		return true;
	}
	return false;
}

const char* Product::getName() const
{
	return name;
}	


//Derived Class functions
Food::Food(): expiration_days(0), weight(0.0)
{
}

Food::Food(const char * a_name, float a_price, int a_expirationdays, float a_weight): Product(a_name, a_price), expiration_days(a_expirationdays), weight(a_weight)
{
}

Food::~Food()
{}

//display food products
bool Food::display() const
{
	cout << "Food Product: " << name << endl;
	cout << "Price: $" << price << endl;
	cout << "Expiration Days: " << expiration_days << " days" << endl;
	cout << "Weight: " << weight << " lbs" << endl;

	return true;
}

bool Food::checkExpiration() const
{
	return expiration_days <= 0;
}

//calculated discount
float Food::calculatedDiscount() const
{
	//if food product is expiring within 5 days, offer 50% discount
	if(expiration_days < 5)
	{
		return 0.50f;
	}	
	//if food product is expiring within 10 days, offer 50% discount
	else if(expiration_days < 10)
	{
		return 0.30f;
	}
	
	//no discount
	return 0.0f;
}

//determine type of food
bool Food::foodType() const
{
	if(weight < 1.0f)
		cout << "This food is likely a fruit or a small snack." << endl;
	else if(weight < 5.0f)
		cout << "This food is likely a pastry, bread or small loaf." << endl;
	else
		cout << "This food is likely a large food, such as meat, vegetables or cheese." << endl;
	
	return true;
}

//apply weight
bool Food::setWeight(float a_weight)
{
	if(a_weight > 0)
	{
		weight = a_weight;
		return true;
	}
	return false;
}

//apply expiration days
bool Food::setExpiration(int a_expirationdays)
{
	if(a_expirationdays >= 0)
	{
		expiration_days = a_expirationdays;
		return true;
	}
	return false;
}



//Derived Class functions

//default constructor
Clothing::Clothing(): size(""), color("")
{}

//passed in variables from base class + this class
Clothing::Clothing(const char * a_name, float a_price, const string &a_size, const string &a_color): Product(a_name, a_price), size(a_size), color(a_color)
{}

Clothing::~Clothing()
{}

//display clothing products
bool Clothing::display() const
{
	cout << "Clothing Name: " << name << endl;
	cout << "Price: " << price << endl;
	cout << "Size: " << size << endl;
	cout << "Color: " << color << endl;

	return true;
}	

//apply discount
bool Clothing::applyDiscount(float discount_percentage)
{
	price -= price * (discount_percentage / 100);
	return true;
}

//check if clothing fits
bool Clothing::fits()
{
	if(size == "S" || size == "M" || size == "L")
		return true;
	
	return false;
}

bool Clothing::recommendSeason() const
{
	if(color == "Pink" || color == "Green" || color == "Yellow" || color == "Teal")
		cout << "This clothing is suitable for spring." << endl;

	else if(color == "Blue" || color == "Teal" || color == "White")
		cout << "This clothing is suitable for summer." << endl;

	else if(color == "Red" || color == "Orange" || color == "Brown" || color == "Yellow")
		cout << "This clothing is suitable for Fall." << endl;

	else if(color == "Black" || color == "Gray" || color == "White" || color == "purple")
		cout << "This clothing is suitable for Winter." << endl;
	else
		cout << "clothing is suitable for any season!" << endl;
	return true;
}

//apply size
bool Clothing::setSize(const string &a_size)
{
	size = a_size;
	return true;
}

//apply color
bool Clothing::setColor(const string &a_color)
{
	color = a_color;
	return true;
}




//Derived Class functions
Tech::Tech(): model(nullptr), ram(0), warranty(0)
{}

Tech::Tech(const char * a_name, float a_price, const char * a_model, int a_ram, int a_warranty): Product(a_name, a_price), ram(a_ram), warranty(a_warranty)
{
	model = new char[strlen(a_model) + 1];
	strcpy(model, a_model);	
}

Tech::Tech(const Tech &to_copy): Product(to_copy), ram(to_copy.ram), warranty(to_copy.warranty)
{
	if(to_copy.model)
	{
		model = new char[strlen(to_copy.model) + 1];
		strcpy(model, to_copy.model);	
	}
	else
		model = nullptr;
}

//assignment operator (copy = object1)
Tech & Tech::operator=(const Tech & source)
{
	//self assignment check
	if(this == &source)
		return *this;

	//call base operator
	Product::operator=(source);
	
	
	delete [] model;

	//check if object model is present
	if(source.model)
	{
		model = new char[strlen(source.model) + 1];
		strcpy(model, source.model);
	}
	else
		model = nullptr;
	ram = source.ram;
	warranty = source.warranty;

	return *this;
}	

Tech::~Tech()
{
	delete [] model;
}

//display tech products
bool Tech::display() const
{
	cout << "Product Name: " << name << endl;
	cout << "Price: " << price << endl;
	cout << "Model: " << model << endl;
	cout << "RAM: " << ram << " GB" << endl;
	cout << "Warrant: " << warranty << " months" << endl;
	return true;
}

//check tech product warranty validation
bool Tech::checkWarranty() const
{
	if(warranty > 0)
	{
		cout << "Warranty is valid for " << warranty << " months." << endl;
		return true;
	}
	else
	{
		cout << "Warranty is expired." << endl;
		return false;
	}

}

//add a desired discount percentage to tech product
bool Tech::addDiscount(float discount_percentage)
{
	if(discount_percentage <= 0 || discount_percentage >= 100)
		return false;
	price = price - (price * (discount_percentage / 100));
	return true;

}

//check if tech product has enough ram
bool Tech::checkRAM(int requiredRAM) const
{
	//is true if ram is plenty enough for required ram
	return ram >= requiredRAM;
}

//set tech product's model
bool Tech::setModel(const char * a_model)
{
	if(a_model)
	{
		delete [] model;
		model = new char[strlen(a_model) + 1];
		strcpy(model, a_model);
		return true;
	}
	return false;

}

bool Tech::setRAM(int a_ram)
{
	if(a_ram > 0)
	{
		ram = a_ram;
		return true;
	}
	return false;
}

bool Tech::setWarranty(int a_warranty)
{
	if(a_warranty >= 0)
	{
		warranty = a_warranty;
		return true;
	}
	return false;	

}

//get model
const char* Tech::getModel() const
{
	return model;
}
