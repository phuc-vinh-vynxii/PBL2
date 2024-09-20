#include <iostream>
#include "../dish.h"
using namespace std;
#ifndef ORDERITEM_H
#define ORDERITEM_H
class OrderItem : public Dish{
    private:
        string orderItemID; //PK
        string orderID; //FK
        string *dishID;
    public:
        // Order(){
        //     dishID=new string[10];
        // }
        void OrderItem_Output();
        void OrderItem_outputAP();
        void OrderItem_outputMC();
        void OrderItem_outputDE();
        void OrderItem_outputBE();
        void ChooseDish();
        void outputChange();
        friend int StrToInt(string);
        friend string IntToStr(int); 
};
#endif