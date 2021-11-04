#ifndef SPAREPART_H
#define SPAREPART_H

#include <string>
#include "Vehicle.h"

enum condition {New, Refurbished};

class SparePart
{
    private:

    std::string id;
    std::string name;
    std::string description; //long
    Vehicle* vehicle;
    double price;
    condition cond;
    float replacementTime;
    double replacementWage;
    std::string instruction;



public:

    //constructor
	SparePart();
	SparePart(
        std::string id,
        std::string name,
        std::string description,
        Vehicle* vehicle,
        double price,
        condition cond,
        float replacementTime,
        double replacementWage,
        std::string instruction
       );

    //setter
    void setId(std::string id);
    void setName(std::string name);
    void setDescription(std::string description);
    void setVehicle(Vehicle* vehicle);
    void setPrice(double price);
    void setCondition(condition cond);
    void setReplacementTime (float replacementTime);
    void setReplacementWage (double replacementWage);
    void setInstruction(std::string instruction);
    

    //getter
    std::string getId();
    std::string getName();
    std::string getDescription();
    Vehicle* getVehicle();
    double getPrice();
    condition getCondition();
    float getReplacementTime();
    double getReplacementWage();
    std::string getInstruction();

    //speacial getter
    int getWarranty();
    virtual double getTotalPrice();
    virtual void output() = 0;
};


#endif // SPAREPART_H
