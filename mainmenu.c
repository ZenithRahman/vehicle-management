#include <stdio.h>
#include <stdlib.h>
#include "mainmenu.h"
#include "vehicle.h"

void returnToMainMenu() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 
    // Wait for key press
    getchar();
    renderMainMenu();
}

void renderMainMenu() {
    system("cls");
    printf("Vehicle Management Program\n");
    printf("Choose Selection (1-6)\n");
    printf("-------------------------\n");
    printf("1.Add a new vehicle\n");
    printf("2.Show all vehicles\n");
    printf("3.Search a vehicle\n");
    printf("4.Update vehicle information\n");
    printf("5.Delete a vehicle\n");
    printf("6.Exit Program\n");
    
    int choice = 0;
    scanf("%d", &choice);
    switch (choice) {
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
    case 5:
        system("cls");
        deleteVehicle();
        break;
    case 6:
        system("cls");
        printf("Exiting program...\n");
        exit(0);
        break;
    default:
        printf("Invalid Choice");
        returnToMainMenu(); 
        break;
    }
}
