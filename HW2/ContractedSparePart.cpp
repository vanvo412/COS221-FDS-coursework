#include <iostream>
#include "ContractedSparePart.h" 

ContractedSparePart::ContractedSparePart():SparePart(){
	setVendor("");
	setDeliveryPrice(0);
	setDeliveryTime(0);
}

ContractedSparePart::ContractedSparePart(
	std::string id,
        std::string name,
        std::string description,
        Vehicle* vehicle,
        double price,
        condition cond,
        float replacementTime,
        double replacementWage,
        std::string instruction,
        std::string vendor,
        double deliveryPrice,
        int deliveryTime
) : SparePart(
			id,
			name,
			description, 
			vehicle, 
			price, 
			cond, 
			replacementTime,
			replacementWage,
			instruction ){
	setVendor(vendor);
	setDeliveryPrice(deliveryPrice);
	setDeliveryTime(deliveryTime);
}

void ContractedSparePart::setVendor(std::string vendor){
	this->vendor=vendor;
}

void ContractedSparePart::setDeliveryPrice(double deliveryPrice){
	this->deliveryPrice=deliveryPrice;
}

void ContractedSparePart::setDeliveryTime(int deliveryTime){
	this->deliveryTime=deliveryTime;

}

std::string ContractedSparePart::getVendor(){
	return vendor;
}

double ContractedSparePart::getDeliveryPrice(){
	return deliveryPrice;
}

int ContractedSparePart::getDeliveryTime(){
	return deliveryTime;
}

double ContractedSparePart::getTotalPrice(){
	return getPrice()+getReplacementTime()*getReplacementWage()+getDeliveryPrice();
}

void ContractedSparePart::output(){
	std::cout<<"Spare part detail:"<<std::endl;
	std::cout<<"Id: "<<getId()<<std::endl;
	std::cout<< "Name :"<<getName()<<std::endl;
	std::cout<<"Description: "<<getDescription() <<std::endl;
	std::cout<< "Price: "<<getPrice()<<std::endl;
	std::cout<< "Vehicle: "<<getVehicle()->getModel()<<std::endl;
	std::cout<< "Condition: "<<getCondition()<<std::endl;
	std::cout<< "Warranty: "<<getWarranty()<<" month"<<std::endl;
	std::cout<< "Delivery Time: " << getDeliveryTime() <<std::endl;
	std::cout<< "Vendor: "<< getVendor()<<std::endl;
	std::cout<< "Total Price: "<<getTotalPrice()<<std::endl;
}

