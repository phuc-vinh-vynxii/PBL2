#include <iostream>
#include "../dish/dish.h"
using namespace std;
#ifndef ORDERITEM_H
#define ORDERITEM_H
class OrderItem{
    public:
        void OrderItem_Output();
        void OrderItem_outputAP();
        void OrderItem_outputMC();
        void OrderItem_outputDE();
        void OrderItem_outputBE();
        friend int StrToInt(string);
        friend string IntToStr(int);
        void ChooseDish();
        void outputChange();
};
#endif