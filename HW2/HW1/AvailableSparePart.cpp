#include <iostream>
#include "AvailableSparePart.h" 


AvailableSparePart::AvailableSparePart():SparePart(){
	setQuantity(0);
	setLocation("");	
}

AvailableSparePart::AvailableSparePart(
	std::string id,
        std::string name,
        std::string description,
        Vehicle* vehicle,
        double price,
        condition cond,
        float replacementTime,
        double replacementWage,
        std::string instruction,
		int quantity,
		std::string location) 
		: 
		SparePart(
			id,
			name,
			description, 
			vehicle, 
			price, 
			cond, 
			replacementTime,
			replacementWage,
			instruction)
		{
			
	setQuantity(quantity);
	setLocation(location);
}


void AvailableSparePart::setQuantity(int quantity){
	this->quantity=quantity;
}

void AvailableSparePart::setLocation(std::string location){
	this->location=location;
}

int AvailableSparePart::getQuantity(){
	return quantity;
}

std::string AvailableSparePart::getLocation(){
	return location;
}


double AvailableSparePart::getDeliveryTime(){
	return 0;
}

void AvailableSparePart::output(){
	std::cout<<"Spare part detail:"<<std::endl;
	std::cout<<"Id: "<<getId()<<std::endl;
	std::cout<< "Name :"<<getName()<<std::endl;
	std::cout<<"Description: "<<getDescription() <<std::endl;
	std::cout<< "Price: "<<getPrice()<<std::endl;
	std::cout<< "Vehicle: "<<getVehicle()->getModel()<<std::endl;
	std::cout<< "Condition: "<<getCondition()<<std::endl;
	std::cout<< "Warranty: "<<getWarranty()<<" month"<<std::endl;
	std::cout<< "Total Price: " << getTotalPrice() <<std::endl;
	std::cout<< "Available quantity: "<< getQuantity()<<std::endl;
	std::cout<< "Location: "<<getLocation()<<std::endl;
}

