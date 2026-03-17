//*************************************************************************************************
//Billy Rodriguez  CS302  1/14/2025  PROGRAM_1
//
//This is the client of the program
//*************************************************************************************************

#include "product.h"
#include "datastructure.h"


void displayMainMenu();
void handleFoodMenu(FoodCLL &foodInventory);
void handleTechMenu(TechInventory &techInventory);
void handleClothingMenu(ClothingInventory &clothingInventory);

int main()
{
	int choice = 0;
	FoodCLL foodInventory;      			//Circular Linked List for Food
	TechInventory techInventory; 			//Vector for Tech
	ClothingInventory clothingInventory;		//Array of LLL for another product category (initialize here)

	do
	{
		displayMainMenu();
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore(); 				//Ignore newline characters from input buffer

		switch (choice)
		{
			case 1:
				handleFoodMenu(foodInventory);
				break;
			case 2:
				handleTechMenu(techInventory);
				break;
			case 3:
				handleClothingMenu(clothingInventory);
				break;
			case 4:
				cout << "Exiting the program. Thank you for shopping!\n";
				break;
			default:
				cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 4);

	return 0;
}

void displayMainMenu()
{
	cout << "\n=== Main Menu ===\n";
	cout << "1. Food Inventory (CLL)\n";
	cout << "2. Tech Inventory (Vector)\n";
	cout << "3. Clothing Inventory (ARR)\n";
	cout << "4. Exit\n";
}

void handleFoodMenu(FoodCLL &foodInventory)
{
	int choice = 0;
	do
	{
		cout << "\n--- Food Inventory Menu (CLL) ---\n";
		cout << "1. Add Food Item\n";
		cout << "2. Display Food Inventory\n";
		cout << "3. Remove Food Item\n";
		cout << "4. Back to Main Menu\n";
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();

		switch (choice)
		{
			case 1:
				{
					char name[100];
					float price;
					int expirationDays;
					float weight;

					cout << "Enter food name: ";
					cin.getline(name, 100);
					cout << "Enter price: ";
					cin >> price;
					cout << "Enter expiration days: ";
					cin >> expirationDays;
					cout << "Enter weight: ";
					cin >> weight;

					foodInventory.insert(name, price, expirationDays, weight);
					break;
				}
			case 2:
				cout << "\n--- Food Inventory ---\n";
				foodInventory.display();
				break;
			case 3:
				{
					char name[100];
					cout << "Enter food name to remove: ";
					cin.ignore();
					cin.getline(name, 100);

					foodInventory.remove(name);
					break;
				}
			case 4:
				cout << "Returning to the main menu.\n";
				break;
			default:
				cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 4);
}

void handleTechMenu(TechInventory &techInventory)
{
	int choice = 0;
	do
	{
		cout << "\n--- Tech Inventory Menu (Vector) ---\n";
		cout << "1. Add Tech Item\n";
		cout << "2. Display Tech Inventory\n";
		cout << "3. Remove Tech Item\n";
		cout << "4. Back to Main Menu\n";
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();

		switch (choice)
		{
			case 1:
				{
					char name[100];
					float price;
					char model[100];
					int ram;
					int warranty;

					cout << "Enter tech name: ";
					cin.getline(name, 100);
					cout << "Enter price: ";
					cin >> price;
					cin.ignore();
					cout << "Enter model: ";
					cin.getline(model, 100);
					std::cout << "Enter RAM: ";
					cin >> ram;
					cout << "Enter warranty period (in years): ";
					cin >> warranty;

					Tech newTech(name, price, model, ram, warranty);
					techInventory.add(newTech);
					break;
				}
			case 2:
				cout << "\n--- Tech Inventory ---\n";
				techInventory.display();
				break;
			case 3:
				{
					char model[100];
					cout << "Enter tech model to remove: ";
					cin.ignore();
					cin.getline(model, 100);

					techInventory.remove(model);
					break;
				}
			case 4:
				cout << "Returning to the main menu.\n";
				break;
			default:
				cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 4);
}

void handleClothingMenu(ClothingInventory &clothingInventory) 
{
	int choice = 0;

	do 
	{
		cout << "\n--- Clothing Inventory Menu (Array of Categories) ---\n";
		cout << "1. Add Clothing Item\n";
		cout << "2. Display Clothing Inventory\n";
		cout << "3. Clear All Clothing Inventory\n";
		cout << "4. Back to Main Menu\n";
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();

		switch (choice) 
		{
			case 1: 
			{
					int category;
					char name[100];
					float price;
					string size, color;

					//Select category
					cout << "Select category:\n";
					cout << "0. Men\n1. Women\n2. Children\n";
					cout << "Enter category (0-2): ";
					cin >> category;
					cin.ignore();

					//Get clothing item details
					cout << "Enter clothing name: ";
					cin.getline(name, 100);
					cout << "Enter price: ";
					cin >> price;
					cin.ignore();
					cout << "Enter size: ";
					getline(cin, size);
					cout << "Enter color: ";
					getline(cin, color);

					//Insert into inventory
					clothingInventory.insert(category, name, price, size, color);
					break;
			}
			case 2:
				cout << "\n--- Displaying Clothing Inventory ---\n";
				clothingInventory.display();
				break;
			case 3:
				cout << "\nClearing all clothing inventory...\n";
				clothingInventory.clear();
				cout << "All categories cleared.\n";
				break;
			case 4:
				cout << "Returning to the main menu.\n";
				break;
			default:
				cout << "Invalid choice. Please try again.\n";
		}
	}while (choice != 4);
}
