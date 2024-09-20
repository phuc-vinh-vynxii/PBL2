#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "order.h"
using namespace std;
int Order::orderCount = 0;

Order::Order(){
    orderCount++;
    string tmp = to_string(orderCount);
    string sub = string(4-tmp.size(), '0') + tmp;
    orderID = "OD" + sub;
    totalPrice = 0;
    orderStatus = 0; // da xac nhan, chua thanh toan
    vector<string> order;
    ifstream fileIn("orderItem(demo).dat");
    if (!fileIn){
		cerr << "Khong the mo danh sach mon an da order!" << endl;
		return;
	}
    
    orderID = orderID + ": ";
    order.push_back(orderID);
    string line;
    string dishOrder = "\"";
    while (getline(fileIn, line)){
        stringstream ss(line);
        string ID, Name, Price, Quantity;
        while (ss>>ID>>Name>>Price>>Quantity){
            dishOrder = dishOrder + Name + ":" + Quantity + ", ";
            this->totalPrice += strToDouble(Price) * stoi(Quantity);
        }
    }

    if (dishOrder.size() > 2){
        dishOrder.erase(dishOrder.size() - 2);
        
    }
    dishOrder += "\"";
    dishOrder += ", ";

    // order.push_back(dishOrder);
    // order.push_back(to_string(this->totalPrice));
    
    // stringstream ss;
    // ss << fixed << setprecision(3) << totalPrice;
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

// string Order::numToStr(int num){
//     if (num == 0) return "0";
//     string tmp = "";
//     while (num > 0){
//         string digit = "0" + (num%10);
//         tmp = digit + tmp;
//         num /= 10;
//     }
//     int cnt = 0;
//     string res = "";
//     for (int i = tmp.size()-1; i >= 0; i--){
//         cnt++;
//         res = tmp[i] + res;
//         if (i != 0 && cnt % 3 == 0){
//             res = "." + res;
//         }
//     }
//     return res;
// }

void Order::deleteOrder(){
    
}

void Order::showList(){

}