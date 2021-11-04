//
//  main.cpp
//  HW1
//
//  Created by Van Vo on 19.09.21.
//

#include <iostream>
#include <string>
#include<vector>
#include <math.h>
#include <map>
#include <cstring>

//include classes
#include "Vehicle.h"
#include "SparePart.h"
#include "AvailableSparePart.h"
#include "ContractedSparePart.h"

using namespace std;

//HW3 Quicksort

void quickSort(vector<SparePart*>& arr, int low, int high){
    if(low<high){
    
    //find middle index
    int mid=(low+high)/2;
    
    //sorting the first, mid and last
    if(arr[low]->getTotalPrice()>arr[mid]->getTotalPrice())
        swap(arr[low], arr[mid]);
    if(arr[low]->getTotalPrice()>arr[high]->getTotalPrice()) swap(arr[low], arr[mid]);
    if(arr[mid]->getTotalPrice()>arr[high]->getTotalPrice()) swap(arr[mid],arr[high]);
    
    //make the middle element as pivot
    auto pivot=arr[mid]->getTotalPrice();
    swap(arr[mid], arr[high-1]);
    
    //partition
    auto i = low;
    int j=high-1;
    
    //infinite loop till break
    while(true){
        //increase until i larger than pivot or j smaller than pivot
        while(arr[++i]->getTotalPrice()<pivot){}
        while(arr[--j]->getTotalPrice()>pivot){}
        
        if(i < j) swap(arr[i], arr[j]);
        else break;
    }
    
    swap(arr[i], arr[high - 1]);
    
    quickSort(arr,low,i-1);
    quickSort(arr,i+1,high);
}
}


//end Quicksort


//HW4
//prefix table
void computeLPSArray(char* pat, int M, int* lps)
{
  // length of the previous longest prefix suffix
    int len = 0;
    int i = 1;
    
    lps[0] = 0; // first letter in the array is always 0
    
    
  while (i < M) {
      if (pat[i] == pat[len]) {
          len++;
          lps[i] = len;
          i++;
      }
      else
      {
          if (len != 0) {
              len = lps[len - 1];
          }
          else
          {
              lps[i] = 0;
              i++;
          }
      }
  }
}


//return an interger as the times that the pattern being recognized
int KMPSearch(char* pat, char* txt)
{
    //couting the amount of times pattern are being repeated
    int count=0;
    
    int M = (int)strlen(pat);
    int N = (int)strlen(txt);
  
    // create lps[] that will hold the longest prefix suffix
    int lps[M];
    computeLPSArray(pat, M, lps);
    
  
    int i = 0;
    int j = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
  
        if (j == M) {
            count+=1;
            j = lps[j - 1];
        }
  
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return count;
}
  


int main() {
    vector<Vehicle*> vehicle;
    vector<SparePart*> spareParts;
    
    //remove Contracted and Available Parts vectors
//        vector<ContractedSparePart*> contractedPart;
//        vector<AvailableSparePart*> availablePart;

        //adding 3 vehicle to the vector
       Vehicle* vehicle1= new Vehicle("Toyota", "Civic", 2003);
        Vehicle* vehicle2= new Vehicle("Toyota", "Civic", 2007);
        Vehicle* vehicle3= new Vehicle("Toyota", "Civic", 2008);

        vehicle.push_back(vehicle1);
        vehicle.push_back(vehicle2);
        vehicle.push_back(vehicle3);

        //adding 3 parts to available parts
        AvailableSparePart* availablePart1 = new AvailableSparePart(
            "000",
            "new shield",
            "a windshield",
            vehicle.at(1),
            400,
            New,
            1,
            50,
            "don't break it",
            100,
            "Storage"
            );

        AvailableSparePart* availablePart2=new AvailableSparePart(
            "001",
            "winter wheel",
            "some winter wheels",
            vehicle.at(0),
            50,
            New,
            1,
            10,
            "for winter",
            1000,
            "Store"
            );

        AvailableSparePart* availablePart3 = new AvailableSparePart(
            "002",
            "summer wheel",
            "some summer wheels",
            vehicle.at(0),
            50,
            New,
            1,
            10,
            "for summer",
            1000,
            "Store"
            );
    
    AvailableSparePart* availablePart4 = new AvailableSparePart(
        "000",
        "shield",
        "a very used windshield",
        vehicle.at(1),
        10,
        New,
        1,
        30,
        "don't break it",
        100,
        "Storage"
        );

//        availablePart.push_back(availablePart1);
//        availablePart.push_back(availablePart2);
//        availablePart.push_back(availablePart3);
    
    spareParts.push_back(availablePart1);
    spareParts.push_back(availablePart2);
    spareParts.push_back(availablePart3);
    spareParts.push_back(availablePart4);
    

        //adding 3 parts to contracted parts
        ContractedSparePart* contractedPart1= new ContractedSparePart(
                "100",
                "air bag",
                "extra air bag",
                vehicle.at(1),
                300,
                New,
                4,
                15,
                "in case someone broke it",
                "Authorized reseller",
                20,
                2
        );
        ContractedSparePart* contractedPart2= new ContractedSparePart(
                "102",
                "used air conditioner",
                "AC",
                vehicle.at(1),
                200,
                Refurbished,
                4,
                40,
                "in case someone broke it",
                "Athony",
                30,
                2
        );
      ContractedSparePart* contractedPart3= new ContractedSparePart(
                "101",
                "new air conditioner",
                "AC",
                vehicle.at(1),
                500,
                New,
                4,
                40,
                "in case someone broke it",
                "Athony",
                30,
                2
        );

//        contractedPart.push_back(contractedPart1);
//        contractedPart.push_back(contractedPart2);
//        contractedPart.push_back(contractedPart3);

    
    spareParts.push_back(contractedPart1);
    spareParts.push_back(contractedPart2);
    spareParts.push_back(contractedPart3);
    
    //HW3
    
    int size=(int)spareParts.size()-1;
    
    
//    implement quicksort
    quickSort(spareParts,0,size);
    

    double totPrice=0;
    
    vector<double> priceArray;

        //display info
    cout<<"*** Spare Parts: ***"<<endl;
        for(SparePart* c : spareParts){
            
            priceArray.push_back(c->getTotalPrice());
            totPrice+=c->getTotalPrice();
            cout<<"Name: "<<c->getName()<<endl;
            cout<<"Total Price: "<<c->getTotalPrice()<<endl;
            cout<<endl<<endl<<endl;
            
        }

    cout<<"----------------------"<<endl;;
    cout<<"TOTAL PRICE OF ALL PARTS: "<<totPrice<<endl<<endl;

    
    
    
    
    
    
    //making a map to store the amount of repeated pattern to the spare parts
    multimap<int, SparePart*, greater <int>> sortMap;
    
    bool cont=true;
    string input;

    while (cont) {
        sortMap.clear();
        
        cout<<"Enter the phrase you want to search: ";
        cin>>input;
        
        for(SparePart* c : spareParts){
            char* des= &c->getDescription()[0];
            char* inp= &input[0];
            int i = KMPSearch(inp, des);
            sortMap.insert(make_pair(i, c));
        }
            
        
        

            //display info HW4
            cout<<"***All Spare Parts: ***"<<endl
        <<"(sorted based on the presence of the pattern being searched)"<<endl<<endl;
            for(pair <int, SparePart*> s : sortMap){
                cout<<"Name: "<<s.second->getName()<<endl;
                cout<<"Descriptions: "<<s.second->getDescription()<<endl;
                cout<<"Total Price: "<<s.second->getTotalPrice()<<endl;
                cout<<"Times that the pattern appear: "<<s.first<<endl;
                cout<<"---"<<endl<<endl<<endl;
            }
        
        cout<<endl<<endl<<"Do you want to continue?(Y/N)";
        cin>>input;

        input=="Y" || input=="y" ? cont=true : cont=false;

    }
    
    return 0;
}



