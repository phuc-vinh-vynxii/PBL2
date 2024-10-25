#include <bits/stdc++.h>
#include "payment.h"
using namespace std;

Payment::Payment(){

}

void Payment::processPayment() {
    // xai ham setorderStatus
    if (Order::orderStatus == 0) { // Nếu trạng thái là 'Chờ thanh toán'
        cout << "Đang xử lý thanh toán cho đơn hàng: " << Order::orderID << " | Số tiền: " << formatNumber(Order::totalPrice) << endl;
        Order::orderStatus = 1; // Cập nhật trạng thái thành 'Đã thanh toán'
        cout << "Thanh toán thành công cho đơn hàng: " << Order::orderID << endl;
        saveToFile(); // Ghi dữ liệu vào file khi thanh toán thành công
    } else {
        cout << "Không thể xử lý thanh toán. Trạng thái hiện tại: " << Order::orderStatus << endl;
    }
}

void Payment::cancelPayment() {
    if (Order::orderStatus == 0) { // Nếu trạng thái là 'Chờ thanh toán'
        Order::orderStatus = 2; // Cập nhật trạng thái thành 'Đã hủy'
        cout << "Thanh toán đã bị hủy cho đơn hàng: " << Order::orderID << endl;
        saveToFile(); // Ghi dữ liệu vào file khi thanh toán bị hủy
    } else {
        cout << "Không thể hủy thanh toán. Trạng thái hiện tại: " << Order::orderStatus << endl;
    }
}
void Payment::showPaymentStatus() {
    cout << " | Order ID: " << Order::orderID << " | Trạng thái: ";
    cout << " | Số tiền: " << formatNumber(Order::totalPrice) << endl;
    switch (Order::orderStatus) {
        case 0: cout << "Chưa thanh toán"; break;
        case 1: cout << "Đã thanh toán"; break;
        case 2: cout << "Đã hủy"; break;
    }
}

void Payment::saveToFile() {
    ofstream outFile("Order/order_database.dat", ios::app); // Mở file để ghi thêm
    if (outFile.is_open()) {
        outFile << ", Trạng thái: " << (Order::orderStatus == 0 ? "Chưa thanh toán" : (Order::orderStatus == 1 ? "Đã thanh toán" : "Đã hủy")) 
                << endl;
        outFile.close(); // Đóng file
    } else {
        cerr << "Không thể mở file để ghi." << endl;
    }
}
