#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

const std::string maker[6]= {"Toyota", "Honda", "Ford", "Skoda", "Kia", "Unknown"};   

class Vehicle
{
    int year;
    std::string make;
    std::string model;

public:
    //constructor
	Vehicle();
	Vehicle(std::string make, std::string model, int year);

    //setter
    void setMake(std::string make);
    void setYear(int year);
    void setModel(std::string model);


    //getter
    std::string getMake();
    int getYear();
    std::string getModel();
};


#endif // VEHICLE_H