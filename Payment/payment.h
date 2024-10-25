#include <iostream>
#include <string>
#include "../Order/order.h"  

using namespace std;
#ifndef PAYMENT_H
#define PAYMENT_H
class Payment : public Order{
private:
    //string orderID;   // Khóa ngoại tham chiếu đến Order: kế thừa từ class Order
    //int orderStatus;  // 0: Chờ thanh toán, 1: Đã thanh toán, 2: Đã hủy : kế thừa từ class Order
    //double totalPrice;    // Số tiền cần thanh toán
    //string orderDetail; // Thông tin đơn hàng

public:
    Payment();
    void processPayment(); // Xử lý thanh toán
    void cancelPayment();  // Hủy thanh toán
    void showPaymentStatus(); // Hiển thị trạng thái thanh toán
    void saveToFile(); // Ghi dữ liệu vào file
    // double getTotalPrice(); // Lấy số tiền
    // kế thừa string getOrderID(); // Lấy order ID
    // kế thừa int getOrderStatus(); // Lấy trạng thái đơn hàng
};

#endif