#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include "order.h"
using namespace std;

int Order::orderCount = 0;

//CREATE ORDER
Order::Order(){
	// xử lí orderCount
    orderCount++;
    string tmp = to_string(orderCount);
    string sub = string(4-tmp.size(), '0') + tmp;
    orderID = "OD" + sub;
    totalPrice = 0;
    orderStatus = 0; // da xac nhan, chua thanh toan
    ifstream fileIn("Order/orderItem.dat");
    if (!fileIn){
		cerr << "Khong the mo danh sach mon an da order!" << endl;
		return;
	}
    
    string id = orderID + ": ";
    string line;
    string dishOrder = "\"";
    while (getline(fileIn, line)){
        stringstream ss(line);
        string ID, Name, Price, Quantity;
        while (ss>>ID>>Name>>Price>>Quantity){
            dishOrder = dishOrder + Name + ":" + Quantity + ",";
            this->totalPrice += strToDouble(Price) * stoi(Quantity);
        }
    }

    if (dishOrder.size() > 1){
        dishOrder.erase(dishOrder.size() - 1);
        
    }
    dishOrder += "\"";
    dishOrder += ",	";

    string total_price = formatNumber(totalPrice);

    fileIn.close();

    ofstream fileOut("Order/order_database.dat", ios::app);

    fileOut << id << dishOrder << total_price;
    fileOut.close();
}

double Order::strToDouble(const string& s){
    stringstream ss(s);
    double num;
    ss >> num;
    return num;
}

string Order::formatNumber(int number) {
    // Chuyển số sang chuỗi
    stringstream ss;
    ss << number;

    string strNumber = ss.str();
    string formattedNumber;

    int count = 0;
    
    for (int i = strNumber.length() - 1; i >= 0; i--) {
        formattedNumber = strNumber[i] + formattedNumber; 

        count++;
        
        if (count % 3 == 0 && i != 0) {
            formattedNumber = '.' + formattedNumber;
        }
    }

    return formattedNumber + ".000"; 
}

vector<string> Order::split(const string& str, char deli){
	vector<string> tokens;
	stringstream ss(str);
	string token;
	while (getline(ss, token, deli)){
		tokens.push_back(token);
	}
	return tokens;
}

//SHOW
void Order::showList(){
	fstream fileIn("Order/order_database.dat");
	if (!fileIn){
		cerr << "LOI DANH SACH DON HANG!";
		return;
	}
	string line;
	string tmp;
	while (getline(fileIn, line)){
		tmp = line;
	}

	if (tmp.empty()) {
        cout << "Khong co du lieu don hang." << endl;
        fileIn.close();
        return;
    }

	cout << orderCount << endl;
	//ID
	int Pos1 = tmp.find(':');
	string ID = tmp.substr(0, Pos1); // lay orderID
	string remaining = tmp.substr(Pos1+2);//+2 & string con lai

	//Dish and quantity
	int firstPos2 = remaining.find('"');
	int	lastPos2 = remaining.rfind('"');
	string dishDetails = remaining.substr(firstPos2+1, lastPos2 - firstPos2 - 1);
	string totalCost = remaining.substr(lastPos2 + 3);//+3

	vector<string> dishes = split(dishDetails, ',');

	cout << "ID DON HANG CUA BAN: " << ID << endl;
	cout << "CHI TIET MON AN: " << endl;
	
	for (int i = 0; i < dishes.size(); i++){
		vector<string> dishAndQuantity = split(dishes[i], ':');
		cout << i+1 << ". " << setw(15) << left << dishAndQuantity[0] << "SL: " << dishAndQuantity[1] << endl;
	}
	//Price
	cout << "TONG GIA TIEN: " << totalCost << endl;

	fileIn.close();
}

// END SHOW

int Order::getOrderStatus(){
	return orderStatus;
}
string Order::getOrderID(){
	return orderID;
}
double Order::getTotalPrice(){
	return totalPrice;
}
void Order::setOrderStatus(int x){
	orderStatus = x;
}