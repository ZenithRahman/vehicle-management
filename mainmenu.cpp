#include "mainmenu.h"
#include "vehicle.h"
#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;

void renderMainMenu()
{
	system("cls");
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
	
	
	cin>>choice;
	switch (choice)
	{
	case 1:
		system("cls");
		addNewVehicle();
		break;
	case 2:
		system("cls");
		showAllVehicles();
		break;
	case 3:
		system("cls");
		searchVehicle();
		break;
	case 4:
		system("cls");
		updateInformation();
		break;
	default:
		printf("Invalid Choice");
		break;
	}

}

void returnToMainMenu()
{
	cin.ignore();
	cin.get();
	renderMainMenu();
}
