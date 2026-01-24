#pragma once
#define VEHICLE_H
#include <string>

void addNewVehicle();
void showAllVehicles();
void searchVehicle();
void updateInformation();
void deleteVehicle();
bool checkIdExists(std::string inputId);