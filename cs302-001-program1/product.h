//*************************************************************************************************
//Billy Rodriguez  CS302  1/14/2025  PROGRAM_1
//
//This is the header of the program which will include all the classes, library calls, prototypes
//*************************************************************************************************

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#pragma once

//Base Class
class Product
{
	public:
		Product();					//default constructor
		Product(const char * a_name, float a_price);	//passed-in variables constructor
		Product(const Product &to_copy);		//copy constructor
		Product& operator=(const Product &source);	//assignment operator
		~Product();					//destructor
		bool display() const;				//display products
		bool compare_name(const char * &a_name);	//compare product names
		float compare_price(const float a_price);	//compare product prices
		bool apply_discount(float discount_percentage);	//apply discount
		bool setName(const char * a_name);		//input a name for product
		bool setPrice(float a_price);			//input a price for product
		const char *getName() const;			//get name
		

	protected:
		char * name;					//product name
		float price;					//product price
};

//Derived Class
class Food: public Product
{
	public:
		Food();						//default constructor
		Food(const char * a_name, float a_price, int a_expirationdays, float a_weight);	//passed-in variables constructor
		~Food();					//destructor
		bool display() const;				//display food products
		bool checkExpiration() const;			//check if the food product is expired
		float calculatedDiscount() const;		//calculate discount depending on the expiration date
		bool foodType() const;				//guess what type of food the food product is (snack, fruit, pastry, medium-sized meat product, bulk item)
		bool setWeight(float a_weight);			//input a weight for food product
		bool setExpiration(int a_expirationdays);	//input a expiration days for food product
		
		
	protected:
		int expiration_days;				//expiration date for food product
		float weight;					//weight of the food in lbs
};
					
//Derived Class	
class Clothing: public Product
{
	public:
		Clothing();					//default constructor
		Clothing(const char * a_name, float a_price, const string &a_size, const string &a_color);	//passed-in variables constructor
		~Clothing();					//destructor
		bool display() const;				//display clothing products
		bool applyDiscount(float discount_percentage);	//apply discount to clothing product
		bool fits();					//check if size fits for clothing product
		bool recommendSeason() const;			//suggest best season to wear clothing product	
		bool setSize(const string &a_size);		//input a size for clothing product
		bool setColor(const string &a_color);		//input a color for clothing product
	
	protected:	
		string size;					//size for clothing product
		string color;					//color for clothing product
};

//Derived Class
class Tech: public Product
{
	public:
		Tech();						//default constructor
		Tech(const char * a_name, float a_price, const char * a_model, int a_ram, int a_warranty);	//passed-in variables constructor
		Tech(const Tech &to_copy);			//copy constructor
		Tech& operator=(const Tech & source);		//assignment operator
		~Tech();					//destructor
		bool display() const;				//display tech products
		bool checkWarranty() const;			//check warrenty validation for tech product
		bool addDiscount(float discount_percentage);	//apply discount to tech product
		bool checkRAM(int requiredRAM) const;		//check if RAM is enough for task
		bool setModel(const char * a_model);		//input a model for tech product
		bool setRAM(int a_ram);				//input RAM for tech product
		bool setWarranty(int a_warranty);		//input warranty(in months) for tech product
		const char *getModel() const;			//get model
		
	protected:
		char * model;					//model for tech product
		int ram;					//RAM for tech product
		int warranty;					//warranty(in months) for tech product

};
