#include <iostream>
#include "SparePart.h" 



SparePart::SparePart(){
	setId("");
    		 setName("");
    		 setDescription("");
   			 setVehicle(new Vehicle());
    		 setPrice(0);
    		 setCondition(New);
    		 setReplacementTime (0);
    		 setReplacementWage (0);
    		 setInstruction("");
}


SparePart::SparePart(
	std::string id,
        std::string name,
        std::string description,
        Vehicle* vehicle,
        double price,
        condition cond,
        float replacementTime,
        double replacementWage,
        std::string instruction){
			 setId(id);
    		 setName(name);
    		 setDescription(description);
   			 setVehicle(vehicle);
    		 setPrice(price);
    		 setCondition(cond);
    		 setReplacementTime (replacementTime);
    		 setReplacementWage (replacementWage);
    		 setInstruction(instruction);
}



void SparePart::setId(std::string id){
	this->id=id;
}

void SparePart::setName(std::string name){
	this->name=name;
}

void SparePart::setDescription(std::string description){
	this->description=description;
}

void SparePart::setVehicle(Vehicle* vehicle){
	this->vehicle=vehicle;
}

void SparePart::setPrice(double price){
	this->price=price;
}

void SparePart::setCondition(condition cond){
	this->cond=cond;
}

void SparePart::setReplacementTime(float replacementTime){
	this->replacementTime=replacementTime;
}

void SparePart::setReplacementWage(double replacementWage){
	this->replacementWage=replacementWage;
}

void SparePart::setInstruction(std::string instruction){
	this->instruction=instruction;
}

std::string SparePart::getId(){
	return id;
}

std::string SparePart::getName(){
	return name;
}

std::string SparePart::getDescription(){
	return description;
}

Vehicle* SparePart::getVehicle(){
	return vehicle;
}

double SparePart::getPrice(){
	return price;
}

condition SparePart::getCondition(){
	return cond;
}

float SparePart::getReplacementTime(){
	return replacementTime;
}

double SparePart::getReplacementWage(){
	return replacementWage;
}

std::string SparePart::getInstruction(){
	return instruction;
}

int SparePart::getWarranty(){
	//new is 3 years or 36 months
	return cond==New ? 36 : 3;
}

double SparePart::getTotalPrice(){
	return price+replacementTime*replacementWage;
}
