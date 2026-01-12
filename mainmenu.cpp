#include "mainmenu.h"
#include "vehicle.h"
#include <cstdlib>
#include <iostream>

void renderMainMenu()
{
	printf("Vehicle Management Program\n");
	printf("Choose Selection (1-5)\n");
	printf("-------------------------\n");
	printf("1.Add a new vehicle\n");
	printf("2.Show all vehicles\n");
	printf("3.Search a vehicle\n");
	printf("4.Update vehicle information\n");
	printf("5.Delete a vehicle\n");
	printf("6.Exit Program\n");
	int choice =0;
	std::cin>>choice;
	if (choice==1)
	{
		std::system("clear");
		addNewVehicle();
	}
}
