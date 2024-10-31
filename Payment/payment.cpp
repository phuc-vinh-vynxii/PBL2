#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include "payment.h"
using namespace std;

Payment::Payment(){}

void Payment::processPayment() {
    if (Order::orderStatus == 0) {
        cout << "| DANG XU LY DON HANG: " << Order::orderID << " | SO TIEN: " << formatNumber(Order::totalPrice) << endl;
        Order::orderStatus = 1;
        cout << "| THANH TOAN THANH CONG CHO DON HANG: " << Order::orderID << endl;
        saveToFile();
    } else {
        cout << "| KHONG THE XU LY THANH TOAN!" << endl;
    }
    ofstream file("Order/orderitem.dat", ios::trunc);
    file.close();
}

void Payment::cancelPayment() {
    if (Order::orderStatus == 0) {
        Order::orderStatus = 2;
        cout << "| DA HUY DON HANG: " << Order::orderID << endl;
        saveToFile();
    } else {
        cout << "| KHONG THE XU LY THANH TOAN!" << endl;
    }
    ofstream file("Order/orderitem.dat", ios::trunc);
    file.close();
}

void Payment::showPaymentStatus() {
    cout << " | MA DON HANG: " << Order::orderID;
    cout << " | SO TIEN: " << formatNumber(Order::totalPrice) << endl;
    switch (Order::orderStatus) {
        case 0: cout << "| TRANG THAI: CHUA THANH TOAN" << endl; break;
        case 1: cout << "| TRANG THAI: DA THANH TOAN" << endl; break;
        case 2: cout << "| TRANG THAI: DA HUY" << endl; break;
    }
}

void Payment::saveToFile() {
    ofstream outFile("Order/order.dat", ios::app);
    if (outFile.is_open()) {
        outFile << "=> " << (Order::orderStatus == 0 ? "Chưa thanh toán" : (Order::orderStatus == 1 ? "Đã thanh toán" : "Đã hủy")) << " cho ID: " << Order::orderID << endl;
        outFile.close();
    } else {
        cerr << "FILE ERROR" << endl;
    }
}
