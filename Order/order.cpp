#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "order.h"
using namespace std;
int Order::orderCount = 0;

//CREATE ORDER
Order::Order(){
    orderCount++;
    string tmp = to_string(orderCount);
    string sub = string(4-tmp.size(), '0') + tmp;
    orderID = "OD" + sub;
    totalPrice = 0;
    orderStatus = 0; // da xac nhan, chua thanh toan
    ifstream fileIn("orderItem(demo).dat");
    if (!fileIn){
		cerr << "Khong the mo danh sach mon an da order!" << endl;
		return;
	}
    
    orderID = orderID + ": ";
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

    string total_price = IntToStr(totalPrice) + ".000";

    fileIn.close();
    ofstream fileOut("order_database.dat", ios::app);
    fileOut << orderID << dishOrder << total_price << endl;
    fileOut.close();
}

double Order::strToDouble(const string& s){
    stringstream ss(s);
    double num;
    ss >> num;
    return num;
}

string Order::IntToStr(int a){
	string tmp=to_string(a);
	int daucham=tmp.size()/3;
	int dem;
	if(tmp.size()%3==0){
		daucham--;
		dem=3;
		while(1){
			tmp.insert(tmp.begin()+dem, '.');
			daucham--;
			dem+=4;
			if(daucham==0){
				break;
			}
		}
	}
	else if(tmp.size()%3==1){
		dem=1;
		while(1){
			tmp.insert(tmp.begin()+dem, '.');
			dem+=4;
			daucham--;
			if(daucham==0){
				break;
			}
		}
	}
	else{
		dem=2;
		while(1){
			tmp.insert(tmp.begin()+dem, '.');
			daucham--;
			dem+=4;
			if(daucham==0){
				break;
			}
		}
	}
	return tmp;	
}
// END CREATE ORDER

//CANCEL ORDER
void Order::cancelOrder(){
	// xoa khi orderStatus = -1;
	// cancel order vua dua vao thi chi can xoa order o cuoi
    ifstream fileIn("order_database.dat");
	vector<string> lines;
	string line;
	while (getline(fileIn, line)){
		lines.push_back(line);
	}
	fileIn.close();
	if (!lines.empty()){
		lines.pop_back();
	}
	ofstream fileOut("order_database.dat");
	for (const auto& item: lines){
		fileOut << item << endl;
	}
	fileOut.close();
	orderCount--;
}
//END CANCEL ORDER

//SHOW

vector<string> Order::split(const string& str, char deli){
	vector<string> tokens;
	stringstream ss(str);
	string token;
	while (getline(ss, token, deli)){
		tokens.push_back(token);
	}
	return tokens;
}

void Order::showList(){
	fstream fileIn("order_database.dat");
	if (!fileIn){
		cerr << "LOI DANH SACH DON HANG!";
		return;
	}
	string line;
	int lineNum = 1;
	while (getline(fileIn, line)){
		if (lineNum == orderCount){
			//ID
			int Pos1 = line.find(':');
			string ID = line.substr(0, Pos1); // lay orderID
			string remaining = line.substr(Pos1+2);//+2 & string con lai

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
			cout << "TRANG THAI DON HANG: ";
			if (orderStatus == 0){
				cout << "CHUA THANH TOAN!" << endl;
			}
			else if(orderStatus == 1){
				cout << "DA THANH TOAN!" << endl;
			}
			else{
				cout << "DA HUY DON HANG!" << endl;
			}
			break;
		}
		lineNum++;
	}
	fileIn.close();
}

// END SHOW