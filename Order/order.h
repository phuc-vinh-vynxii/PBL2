#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
#ifndef ORDER_H
#define ORDER_H
class Order{
    protected:
        string orderID;
        int orderStatus;
        int quantity;
        int totalPrice;
        static int orderCount;

    public:
        // ORDER
        Order();
        void CreateOrder(const string& StaffID);
        void CreateOrderMedium();
        void showList();
        string formatNumber(int number);
        vector<string> split(const string&, char);
        int getOrderStatus();
        string getOrderID();
        double getTotalPrice();
        void setOrderStatus(int);
        static int ShiftTotalPrice;
        static string shifttotalprice;
        // END ORDER
        // ORDERITEM
        void Item_Output();
        void Item_outputAP();
        void Item_outputMC();
        void Item_outputDE();
        void Item_outputBE();
        int StrToInt(string);
        void ChooseDish();
        void outputChange();
        // END ORDERITEM
};
#endif