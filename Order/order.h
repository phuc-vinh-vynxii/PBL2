#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef ORDER_H
#define ORDER_H

class Order{
    protected:
        string orderID; // PK
        string orderTime;
        int orderStatus;
        int quantity;
        double totalPrice;
        static int orderCount;
    public:
        Order(); //create order ID
        //void cancelOrder();
        void showList();
        double strToDouble(const string&); // giong ham friend ben class OrderItem
        string IntToStr(double a);
        string formatNumber(int number);
        vector<string> split(const string&, char);
        int getOrderStatus();
        string getOrderID();
        double getTotalPrice();
        void setOrderStatus(int);
        //virtual void abstractclass() = 0;
};
#endif