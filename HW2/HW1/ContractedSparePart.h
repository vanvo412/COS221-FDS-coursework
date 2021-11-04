#ifndef CONTRACTEDSPAREPART_H
#define CONTRACTEDSPAREPART_H

#include "SparePart.h"
#include <string>

class ContractedSparePart:public SparePart
{
    std::string vendor;
    double deliveryPrice;
    int deliveryTime;

public:

    //constructor
	ContractedSparePart();
	ContractedSparePart(
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
        int deliveryTime);




    //setter
    void setVendor(std::string vendor);
    void setDeliveryPrice(double deliveryPrice);
    void setDeliveryTime(int deliveryTime);

    //getter
    std::string getVendor();
    double getDeliveryPrice();
    int getDeliveryTime();
    //methods
    
    double getTotalPrice() override;
    void output() override;
};


#endif // CONTRACTEDSPAREPART_H
