#include <iostream>
#include <string>
using namespace std;
#ifndef ORDER_H
#define OREDR_H
class Order{
    private:
        string orderID; // PK
        string orderTime;
        int orderStatus;
        int quantity;
        int totalPrice;
        static int orderCount;
    public:
        Order(); //create order ID
        void cancelOrder();
        void showList();
        double strToDouble(const string&); // giong ham friend ben class OrderItem
        string IntToStr(int a);
        vector<string> split(const string&, char);
};
#endif