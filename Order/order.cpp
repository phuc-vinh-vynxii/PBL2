#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "order.h"
#include "../Dish/dish.h"
using namespace std;

// ORDER
int Order::orderCount = 1;

int Order::StrToInt(string tmp){
	int a=0;
	int dem=0;
	int thu=tmp.size();
	while(thu--){
		if(tmp[dem]!='.')
		a=a*10+(tmp[dem++]-'0');
		else dem++;
	}
	return a;    
}

Order::Order(){}

void Order::CreateOrder(){
    string tmp = to_string(orderCount);
    string sub = string(4-tmp.size(), '0') + tmp;
    orderID = "OD" + sub;
    totalPrice = 0;
    orderStatus = 0;
    ifstream fileIn("Order/orderitem.dat");
    if (!fileIn){
		cerr << "ERROR FILE" << endl;
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
            this->totalPrice += StrToInt(Price);
        }
    }
    if (dishOrder.size() > 1){
        dishOrder.erase(dishOrder.size() - 1);
        
    }
    dishOrder += "\"";
    dishOrder += ",	";
    string total_price = formatNumber(totalPrice);
    fileIn.close();
    ofstream fileOut("Order/order.dat", ios::app);
    fileOut << id  << dishOrder << total_price << endl;
    fileOut.close();
    orderCount++;
}

void Order::CreateOrderMedium(){
    ifstream fileIn("Order/orderitem.dat");
    if (!fileIn){
		cerr << "ERROR FILE" << endl;
		return;
	}
    string thu;
    string line;
    while(getline(fileIn,line)){
        thu=line;
    }
    fileIn.clear();
    fileIn.seekg(0, std::ios::beg);
    if(!thu.empty()){
        string tmp = to_string(orderCount);
        string sub = string(4-tmp.size(), '0') + tmp;
        orderID = "OD" + sub;
        totalPrice = 0;
        orderStatus = 0;
        string id = orderID + ": ";
        string line;
        string dishOrder = "\"";
        while (getline(fileIn, line)){
            stringstream ss(line);
            string ID, Name, Price, Quantity;
            while (ss>>ID>>Name>>Price>>Quantity){
                dishOrder = dishOrder + Name + ":" + Quantity + ",";
                this->totalPrice += StrToInt(Price);
            }
        }
        if (dishOrder.size() > 1){
            dishOrder.erase(dishOrder.size() - 1);
            
        }
        dishOrder += "\"";
        dishOrder += ",	";
        string total_price = formatNumber(totalPrice);
        fileIn.close();
        ofstream fileOut("Order/ordermedium.dat", ios::app);
        fileOut << id << dishOrder << total_price<<endl;
        fileOut.close();
    }
    fileIn.close();
}

string Order::formatNumber(int number) {
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
    return formattedNumber; 
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

void Order::showList(){
	fstream fileIn("Order/ordermedium.dat");
	if (!fileIn){
		cerr << "ERROR FILE";
		return;
	}
	string line;
	string tmp;
	while (getline(fileIn, line)){
		tmp = line;
	}

	if (tmp.empty()) {
        cout << "KHONG CO DU LIEU DON HANG!" << endl;
        fileIn.close();
        return;
    }
	int Pos1 = tmp.find(':');
	string ID = tmp.substr(0, Pos1);
	string remaining = tmp.substr(Pos1+2);
	int firstPos2 = remaining.find('"');
	int	lastPos2 = remaining.rfind('"');
	string dishDetails = remaining.substr(firstPos2+1, lastPos2 - firstPos2 - 1);
	string totalCost = remaining.substr(lastPos2 + 3);
	vector<string> dishes = split(dishDetails, ',');
	cout << "ID DON HANG CUA BAN: " << ID << endl;
	cout << "CHI TIET MON AN: " << endl;
	for (int i = 0; i < dishes.size(); i++){
		vector<string> dishAndQuantity = split(dishes[i], ':');
		cout << i+1 << ". " << setw(15) << left << dishAndQuantity[0] << "SL: " << dishAndQuantity[1] << endl;
	}
	cout << "TONG GIA TIEN: " << totalCost << endl;
	fileIn.close();
    ofstream file("Order/ordermedium.dat", ios::trunc);
    file.close();
}

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
// END ORDER

// ORDERITEM
void Order::Item_Output(){
    Dish tmp;
    tmp.Output();
}
void Order::Item_outputAP(){
    Dish tmp;
    tmp.outputAP();   
}
void Order::Item_outputMC(){
    Dish tmp;
    tmp.outputMC();      
}
void Order::Item_outputDE(){
    Dish tmp;
    tmp.outputDE();     
}
void Order::Item_outputBE(){
    Dish tmp;
    tmp.outputBE();   
}

void Order::ChooseDish(){
    cout<<"-------------------------"<<endl;
    cout<<"1. MON KHAI VI (APPETIZER)"<<endl;
    cout<<"2. MON CHINH (MAIN COURSE)"<<endl;
    cout<<"3. MON TRANG MIENG (DESSERT)"<<endl;
    cout<<"4. DO UONG (BEVERAGE)"<<endl;
    cout<<"5. TAT CA MON"<<endl;
    cout<<"-------------------------"<<endl;
    int t;
    cout<<"NHAP LUA CHON: ";
    cin>>t;
    cin.ignore();
    ifstream inputFile ("Dish/dish.dat");
    if(!inputFile.is_open()){
        cerr<<"ERROR FILE"<<endl;
    }
    ofstream outputFile("Order/orderitem.dat", ios::out | ios::app);
    if(!outputFile.is_open()){
        cerr<<"ERROR FILE"<<endl;
    }
    string ketqua;
    string tmp;
    int soluong;
    int sl;
    if(t==1){
        Item_outputAP();
        cout<<"NHAP MON THEO ID: ";
        getline(cin,tmp);
        cout<<"NHAP SO LUONG: ";
        cin>>sl;
        cin.ignore();
    }
    if(t==2){
        Item_outputMC();
        cout<<"NHAP MON THEO ID: ";
        getline(cin,tmp);
        cout<<"NHAP SO LUONG: ";
        cin>>sl;
        cin.ignore();
    }
    if(t==3){
        Item_outputDE();
        cout<<"NHAP MON THEO ID: ";
        getline(cin,tmp);
        cout<<"NHAP SO LUONG: ";
        cin>>sl;
        cin.ignore();
    }
    if(t==4){
        Item_outputBE();
        cout<<"NHAP MON THEO ID: ";
        getline(cin,tmp);
        cout<<"NHAP SO LUONG: ";
        cin>>sl;
        cin.ignore();
    }
    if(t==5){
        Item_Output();
        cout<<"NHAP MON THEO ID: ";
        getline(cin,tmp);
        cout<<"NHAP SO LUONG: ";
        cin>>sl;
        cin.ignore();
    }
    ketqua=tmp;
    soluong=sl;
    string line;
    while(getline(inputFile,line)){
        string id,name,price;
        int dem=1;
        stringstream ss(line);
        string word;
        int check=0;
        while(ss>>word){
            if(word==ketqua){
                check=1;
            }
        }
        if(check==1){
            if(soluong==1){
                outputFile<<line<<"     1"<<endl;
            }
            else{
                stringstream s(line);
                string word;
                while(s>>word){
                    if(dem==1){
                        id=word;
                        dem++;
                    }
                    else if(dem==2 && (word[0]!='1' && word[0]!='2' && word[0]!='3'&& word[0]!='4'&& word[0]!='5'&& word[0]!='6'&& word[0]!='7'&& word[0]!='8' && word[0]!='9' )){
                        name+=word;
                        name+=" ";
                    }
                    else{
                        price=word;
                    }
                }
                int a=StrToInt(price);
                a=a * soluong;
                string b=formatNumber(a);
                outputFile<<id<<"     "<<name<<"     "<<b<<"     "<<soluong<<endl;
            }
            check=0;
        }  
        dem=1;     
    }
    inputFile.close();
    outputFile.close();
}

void Order::outputChange(){
    ifstream File("Order/orderitem.dat");
    string line;
    while(getline(File,line)){
        cout<<line<<endl;
    }
}
// END ORDERITEM