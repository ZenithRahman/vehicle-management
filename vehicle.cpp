#include <iostream>
#include <string>
#include <vector>
#include "vehicle.h"
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

std::vector<vehicle> vehicles;

void addNewVehicle()
{
	printf("=========Add a new vehicle==========\n");
	vehicle v;

	printf("Enter vehicle id: \n");
	cin>>v.id;

    int typeInput;
    printf("Enter vehicle type (0:Car, 1:Bus, 2:Truck, 3:Bike): \n");
    cin >> typeInput;
    v.type = static_cast<vehicleType>(typeInput);
    
	printf("Enter vehicle model: \n");
	cin>>v.modelName;
	printf("Enter vehicle brand: \n");
	cin>>v.brand;
	printf("Enter vehicle year: \n");
	cin>>v.year;
	printf("Enter vehicle capacity: \n");
	cin>>v.capacity;

	vehicles.push_back(v);

	printf("\n\n\n\n\n");

	printf("%s\n",vehicles[0].modelName.c_str() );
	// cout<<vehicles[0].name;
}
