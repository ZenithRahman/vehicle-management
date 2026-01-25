#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vehicle.h"
#include "mainmenu.h"

Vehicle vehicles[MAX_VEHICLES];
int vehicleCount = 0;

const char* getVehicleTypeName(VehicleType type) {
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

int checkIdExists(const char* inputId) {
    for (int i = 0; i < vehicleCount; ++i) {
        if (strcmp(vehicles[i].id, inputId) == 0) {
            return 1;
        }
    }
    return 0;
}

int returnVehicleIndex(const* inputId)
{
	for (int i = 0; i < vehicleCount; ++i) {
		if (strcmp(vehicles[i].id, inputId) == 0) {
			return i;
		}
	}
	return -1;
}

void addNewVehicle() {
    int finished = 0;

    printf("=========Add a new vehicle==========\n");
    Vehicle v;
    while (!finished) {
        printf("Enter vehicle id: (example: V001)\n");
        char inputId[MAX_STRING_LENGTH];
        scanf("%s", inputId);
        
        while (checkIdExists(inputId)) {
            printf("ID already exists . please type another one:\n");
            scanf("%s", inputId);
        }
        strcpy(v.id, inputId);

        int typeInput;
        printf("Enter vehicle type (0:Car, 1:Bus, 2:Truck, 3:Bike): \n");
        scanf("%d", &typeInput);
        v.type = (VehicleType) typeInput;

        printf("Enter vehicle brand: \n");
        scanf("%s", v.brand);

        printf("Enter vehicle model: \n");
        scanf("%s", v.modelName);

        printf("Enter vehicle year: \n");
        scanf("%d", &v.year);

        printf("Enter vehicle capacity: (in CC) \n");
        scanf("%d", &v.capacity);

        if (vehicleCount < MAX_VEHICLES) {
            vehicles[vehicleCount++] = v;
        } else {
            printf("Error: storage full!\n");
        }
        finished = 1;
    }

    printf("\n--- Vehicle Saved Successfully ---\n");
    // Clear buffer and wait
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Flush stdin
    getchar(); // Wait for key
    renderMainMenu();
}

void showAllVehicles() {
    if (vehicleCount == 0) {
        printf("No vehicle found. Press any key to return");
        returnToMainMenu();
        return;
    }
    for (int i = 0; i < vehicleCount; ++i) 
    {
        Vehicle v = vehicles[i];
        printf("----------------------------\n");
        printf("%d. Vehicle ID : %s\n", i + 1, v.id);
        printf("Vehicle Type : %s\n", getVehicleTypeName(v.type));
        printf("Vehicle Brand: %s\n", v.brand);
        printf("Vehicle Model: %s\n", v.modelName);
        printf("Vehicle Year: %d\n", v.year);
        printf("Vehicle Capacity %d CC\n", v.capacity);
    }
    returnToMainMenu();
}

void searchVehicle() {
    char vehicleId[MAX_STRING_LENGTH];
    printf("Enter Vehicle ID:\n");
    scanf("%s", vehicleId);
	int found = returnVehicleIndex(vehicleId);

    if (found==-1)
    {
		printf("Not found ! Press any key to return.\n");
    }
    else
    {
		Vehicle v = vehicles[found];
		        printf("Vehicle found ! Press any key to return.\n");
		        printf("----------------------------\n");
		        printf("ID : %s\n", v.id);
		        printf("Vehicle Type : %s\n", getVehicleTypeName(v.type));
		        printf("Vehicle Brand: %s\n", v.brand);
		        printf("Vehicle Model: %s\n", v.modelName);
		        printf("Vehicle Year: %d\n", v.year);
		        printf("Vehicle Capacity: %d CC\n", v.capacity);
    }

    //for (int i = 0; i < vehicleCount; ++i) {
    //    Vehicle v = vehicles[i];
    //    if (strcmp(v.id, vehicleId) == 0) {
    //        printf("Vehicle found ! Press any key to return.\n");
    //        printf("----------------------------\n");
    //        printf("ID : %s\n", v.id);
    //        printf("Vehicle Type : %s\n", getVehicleTypeName(v.type));
    //        printf("Vehicle Brand: %s\n", v.brand);
    //        printf("Vehicle Model: %s\n", v.modelName);
    //        printf("Vehicle Year: %d\n", v.year);
    //        printf("Vehicle Capacity: %d CC\n", v.capacity);
    //        found = 1;
    //        break;
    //    }
    //}
   /* if (!found) {
        printf("Not found ! Press any key to return.\n");
    }*/
    returnToMainMenu();
}

void updateInformation() {
    char vehicleId[MAX_STRING_LENGTH];
    printf("Enter Vehicle ID: ");
    scanf("%s", vehicleId);

    int found = 0;
    for (int i = 0; i < vehicleCount; ++i) {
        if (strcmp(vehicles[i].id, vehicleId) == 0) {
            found = 1;
            Vehicle v = vehicles[i];
            int choice;
				printf("\nVehicle found.:\n");
			printf("Vehicle ID: %s\n", v.id);
			printf("Vehicle Brand: %s\n", v.brand);
			printf("Vehicle Model: %s\n", v.modelName);
			printf("Vehicle Type: %s\n", getVehicleTypeName(v.type));
			printf("Vehicle Year: %d\n", v.year);
			printf("Vehicle Engine Capacity: %d CC\n",v.capacity);
            do {
     
                printf("1. Change Type\n");
                printf("2. Change Brand\n");
                printf("3. Change Model\n");
                printf("4. Change Year\n");
                printf("5. Change Capacity\n");
                printf("6. Exit\n");
                printf("Enter choice: (1-6) : ");
                scanf("%d", &choice);

                switch (choice) {
                case 1: {
                    int newType;
                    printf("Enter new type: ");
                    scanf("%d", &newType);
                    vehicles[i].type = (VehicleType)newType;
                    printf("Successfully changed!\n");
                    break;
                }
                case 2: {
                    printf("Enter new Brand name: ");
                    scanf("%s", vehicles[i].brand);
                    printf("Successfully changed!\n");
                    break;
                }
                case 3: {
                    printf("Enter new Model name: ");
                    scanf("%s", vehicles[i].modelName);
                    printf("Successfully changed!\n");
                    break;
                }
                case 4: {
                    int newYear;
                    printf("Enter new Year: ");
                    scanf("%d", &newYear);
                    vehicles[i].year = newYear;
                    printf("Successfully changed!\n");
                    break;
                }
                case 5: {
                    int newCapacity;
                    printf("Enter new capacity: ");
                    scanf("%d", &newCapacity);
                    vehicles[i].capacity = newCapacity;
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

void deleteVehicle() {
	char inputId[MAX_STRING_LENGTH];
	printf("Enter Vehicle ID: \n");
    scanf("%s", inputId);
	for (int i = 0; i < vehicleCount; ++i) {
		if (strcmp(vehicles[i].id, inputId) == 0) {
			for (int j = i; j < vehicleCount - 1; ++j) {
				vehicles[j] = vehicles[j + 1];
			}
			vehicleCount--;
			printf("Successfully deleted id : %s\n", inputId);
			returnToMainMenu();
			return;
		}
	}
}
