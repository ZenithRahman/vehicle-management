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

const struct vehicle
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


	printf("vehicle saved. Going back to main menu.\n");
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
	const string typesOfVehicles[] = { "Car","Bus","Truck","Bike" };
	if (vehicles.empty())
	{
		printf("No vehicle found");
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
}
