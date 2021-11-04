#ifndef AVAILABLESPAREPART_H
#define AVAILABLESPAREPART_H

#include <string>
#include "SparePart.h"

class AvailableSparePart : public SparePart
{
    int quantity;
    std::string location;
public:
	AvailableSparePart();
	AvailableSparePart(std::string id,
        std::string name,
        std::string description,
        Vehicle* vehicle,
        double price,
        condition cond,
        float replacementTime,
        double replacementWage,
        std::string instruction,
		int quantity,
		std::string location);



    void setQuantity(int quantity);
    void setLocation(std::string location);

    int getQuantity();
    std::string getLocation();


    //inhertit getTotalPrice from it's parent class as it is the same
    double getDeliveryTime();
    void output();
};


#endif // AVAILABLESPAREPART_H
