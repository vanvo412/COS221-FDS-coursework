#include "Vehicle.h"
#include <iostream>
#include <string>

Vehicle::Vehicle(){
	setYear(0);
	setMake("Unknown");
	setModel("");
}

Vehicle::Vehicle(std::string make, std::string model, int year){
	setYear(year);
	setModel(model);
	setMake(make);
}


void Vehicle::setMake(std::string make){

	//variable to save the status if the maker is in the predefined array
	bool isMake=false;

	//looping to check if the maker is in the predefined array
	for(int i=0; i<(*maker).size();i++){
			if(make==maker[i])
			{
				this->make=make;
				isMake=true;
				break;
			}	
	}

	//check isMake state
	if(!isMake){
		std::cout<<"Vehicle maker should be one of the brands listed!"<<std::endl;
	}	
}

void Vehicle::setYear(int year){
	if (year==0)
		this->year=year;
	else if (year<1950 || year>2030)
		std::cout<<"The year has to be between 1950 and 2030"<<std::endl;
	else
		this->year=year;
}

void Vehicle::setModel(std::string model){
	this->model=model;
}

std::string Vehicle::getMake(){
	return make;
}

int Vehicle::getYear(){
	return year;
}

std::string Vehicle::getModel(){
	return model;
}

