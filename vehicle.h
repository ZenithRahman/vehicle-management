#ifndef VEHICLE_H
#define VEHICLE_H

#define MAX_VEHICLES 100
#define MAX_STRING_LENGTH 50

typedef enum {
    Car,
    Bus,
    Truck,
    Bike
} VehicleType;

typedef struct {
    char id[MAX_STRING_LENGTH];
    VehicleType type;
    char modelName[MAX_STRING_LENGTH];
    char brand[MAX_STRING_LENGTH];
    int year;
    int capacity;
} Vehicle;

void addNewVehicle();
void showAllVehicles();
void searchVehicle();
void updateInformation();
void deleteVehicle();
int checkIdExists(const char* inputId);
int returnVehicleIndex(const* inputId);
const char* getVehicleTypeName(VehicleType type);

#endif
