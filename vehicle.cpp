#include <iostream>
#include <string>
#include <vector>
#include "vehicle.h"
#include "mainmenu.h"
using namespace std;

enum vehicleType
{
	Car,
	Bus,
	Truck,
	Bike
};

struct vehicle
{
	string id;
	vehicleType type;
	string modelName;
	string brand;
	int year;
	int capacity;
};

vector<vehicle> vehicles;

void addNewVehicle()
{
	int finished = false;

	printf("=========Add a new vehicle==========\n");
	vehicle v;
	while (!finished)
	{
		printf("Enter vehicle id: (example: V001)\n");
		cin >> v.id;

		int typeInput;
		printf("Enter vehicle type (0:Car, 1:Bus, 2:Truck, 3:Bike): \n");
		cin >> typeInput;
		v.type = static_cast<vehicleType>(typeInput);

		printf("Enter vehicle model: \n");
		cin >> v.modelName;
		printf("Enter vehicle brand: \n");
		cin >> v.brand;
		printf("Enter vehicle year: \n");
		cin >> v.year;
		printf("Enter vehicle capacity: (in CC) \n");
		cin >> v.capacity;

		vehicles.push_back(v);
		finished = true;

	}


	printf("\n--- Vehicle Saved Successfully ---\n");
	cin.get();
	renderMainMenu();
}

const char* getVehicleTypeName(vehicleType type) {
	switch (type) {
	case Car:   
		return "Car";
	case Bus:   
		return "Bus";
	case Truck: 
		return "Truck";
	case Bike:  
		return "Bike";
	default:    
		return "Unknown";
	}
}

void showAllVehicles()
{
	//const string typesOfVehicles[] = { "Car","Bus","Truck","Bike" };
	if (vehicles.empty())
	{
		printf("No vehicle found. Press any key to return");
		returnToMainMenu();
		return;
	}
	for (int i=0 ; i<vehicles.size();++i)
	{
		const vehicle v = vehicles[i];
		printf("----------------------------\n");
		printf("%d. Vehicle ID : %s\n",i+1, v.id.c_str());
		printf("Vehicle Type : %s\n", getVehicleTypeName(v.type));
		printf("Vehicle Model: %s\n", v.modelName.c_str());
		printf("Vehicle Brand: %s\n", v.brand.c_str());
		printf("Vehicle Year: %d\n", v.year);
		printf("Vehicle Capacity %d CC\n", v.capacity);

	}
	returnToMainMenu();
}

void searchVehicle()
{
	bool found = false;
	string vehicleId;
	printf("Enter Vehicle ID:\n");
	cin >> vehicleId;
	//printf("\n");
	for (vehicle v : vehicles)
	{
		if (v.id==vehicleId)
		{
			printf("Vehicle found ! Press any key to return.\n");
			printf("----------------------------\n");
			printf("%ID : %s\n", v.id.c_str());
			printf("Vehicle Type : %s\n", getVehicleTypeName(v.type));
			printf("Vehicle Model: %s\n", v.modelName.c_str());
			printf("Vehicle Brand: %s\n", v.brand.c_str());
			printf("Vehicle Year: %d\n", v.year);
			printf("Vehicle Capacity %d CC\n", v.capacity);
			found = true;
			break;

		}
	}
	if (!found)
	{
	
		printf("Not found ! Press any key to return.\n");
	}
	returnToMainMenu();
	return;

}

void updateInformation() {
    string vehicleId;
    printf("Enter Vehicle ID: ");
    cin >> vehicleId;

    bool found = false;
    for (vehicle &v : vehicles) {
        if (v.id == vehicleId) {
            found = true;
            int choice;
            do {
                printf("\nVehicle found.:\n");
                printf("1. Change Type\n");
                printf("2. Change Brand\n");
                printf("3. Change Model\n");
                printf("4. Change Year\n");
                printf("5. Change Capacity\n");
                printf("6. Exit\n");
                printf("Enter choice: (1-6)");
                cin >> choice;

                switch (choice) 
                {
                    case 1: 
                        {
                        int newType;
                        printf("Enter new type: ");
                        cin >> newType;
                        v.type = static_cast<vehicleType>(newType);
                        printf("Successfully changed!\n");
                        break;
                        }

					case 2: 
                       {
                       	 string newBrand;
                        printf("Enter new Brand name: ");
                        cin >> newBrand;
                        v.brand = newBrand;
                        printf("Successfully changed!\n");
                        break; 
                       }

					case 3: 
                        {
                        	string newModel;
                        printf("Enter new Model name: ");
                        cin >> newModel;
                        v.modelName = newModel;
                        printf("Successfully changed!\n");
                        break; 
                        } 
					case 4: 
                        {
                        	int newYear;
                        printf("Enter new Year: ");
                        cin >> newYear;
                        v.year = newYear;
                        printf("Successfully changed!\n");
                        break; 
                        } 
                    case 5: 
                        {
                        	int newCapacity;
                        printf("Enter new capacity: ");
                        cin >> newCapacity;
                        v.capacity = newCapacity;
                        printf("Successfully changed!\n");
                        break; 
                        }                      
                    case 6:
                        printf("Exiting menu.Press any key to continue\n");
                        break;

                    default:
                        printf("Invalid choice.\n");
                        break;
                }
            } while (choice != 6);
            
            break; 
        }
    }

    if (!found) {
        printf("Vehicle ID not found.\n");
    }
            returnToMainMenu();

}
