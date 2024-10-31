#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "../Order/order.h"  
using namespace std;
#ifndef PAYMENT_H
#define PAYMENT_H
class Payment : public Order{
    public:
        Payment();
        void processPayment(); // Xử lý thanh toán
        void cancelPayment();  // Hủy thanh toán
        void showPaymentStatus(); // Hiển thị trạng thái thanh toán
        void saveToFile(); // Ghi dữ liệu vào file
};
#endif