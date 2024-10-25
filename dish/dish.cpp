#include <bits/stdc++.h>
#include "dish.h"
using namespace std;
#include <fstream>
// xu li static
string AP,MC,DE,BE;
void docFile(){
	ifstream file("dish_1.dat");
	if(!file.is_open()){
		cerr<<"ERROR FILE"<<endl;
	}
	string tmp;
	while(file>>tmp){
		string sub = tmp.substr(0,2);
		if(sub == "AP"){
			AP=tmp;
		}
		if(sub=="MC"){
			MC = tmp;
		}
		if(sub=="DE"){
			DE=tmp;
		}
		if(sub=="BE"){
			BE=tmp;
		}
	}
	for(int i=0;i<6;i++){
		if(AP[i]=='0' && AP[i+1]!='0'){
			AP=AP.substr(i+1);
			break;
		}
	}	
	for(int i=0;i<6;i++){
		if(MC[i]=='0' && MC[i+1]!='0'){
			MC=MC.substr(i+1);
			break;
		}
	}
	for(int i=0;i<6;i++){
		if(DE[i]=='0' && DE[i+1]!='0'){
			DE=DE.substr(i+1);
			break;
		}
	}
	for(int i=0;i<6;i++){
		if(BE[i]=='0' && BE[i+1]!='0'){
			BE=BE.substr(i+1);
			break;
		}
	}
	file.close();	
}
int Dish::orderAP=0;
int Dish::orderMC=0;
int Dish::orderDE=0;
int Dish::orderBE=0;
int Change(string tmp){
	int size=tmp.size();
	int dem=0;
	while(size--){
		dem=dem*10+(tmp[tmp.size()-size-1]-'0');
	}
	return dem;
}
void Thaydoi(){
	Dish::getAP()=Change(AP);
	Dish::getMC()=Change(MC);
	Dish::getDE()=Change(DE);
	Dish::getBE()=Change(BE);
}
int& Dish::getAP(){
	return orderAP;
}
int& Dish::getMC(){
	return orderMC;
}
int& Dish::getDE(){
	return orderDE;
}
int& Dish::getBE(){
	return orderBE;
}
//
int Dish::Order=orderAP+orderMC+orderDE+orderBE;
Dish::Dish(){
	Order++;
};
//ADD
string name_add,id_add,price_add;
void Dish::addDish(){
	Input();
	fstream file("dish_1.dat", ios::in | ios::out | ios::ate);
	if(!file.is_open()){
		cerr<<"ERROR FILE"<<endl;
	}
	int tmp=17-name_add.size();
	file<<id_add<<"    "<<name_add;
	for(int i=1;i<=tmp;i++){
		file<<" ";
	}
	file<<price_add<<endl;
	file.close();
}

//END ADD
//DELETE
void deleteDish(){
	ifstream fileIn("dish_1.dat");
	if (!fileIn){
		cerr << "Khong the mo danh sach mon an!" << endl;
		return;
	}
	vector<string> dishList;
	string ID_delete;
	cout << "Nhap ID mon an can xoa:";
	getline(cin, ID_delete);
	bool found = false;
	string dish;

	while (getline(fileIn, dish)){
		if (dish.substr(0, ID_delete.size()) != ID_delete){
			dishList.push_back(dish);
		}
		else{
			found = true; 
		}
	}
	fileIn.close();

	if (found){
		ofstream fileOut("dish_1.dat");
		if (!fileOut) {
			cerr << "Khong the mo danh sach mon an!" << endl;
			return;
		}
		else{
			for (const auto &l: dishList){
				fileOut << l << endl;
			}
		}
		fileOut.close();
		cout << "Đã xóa món ăn với ID:" << ID_delete << endl;
	}
	else{
		cout << "Không tìm thấy món ăn với ID:" << ID_delete << endl;
	}
}
//END DELETE
void Dish::Input(){
	cout << "-------------------------" << endl;
	cout << "1. ADD APPETIZER" << endl;		
	cout << "2. ADD MAIN COURSE" << endl;
	cout << "3. ADD DESSERT" << endl;
	cout << "4. ADD BEVERAGE" << endl;
	cout << "5. RETURN" << endl;
	cout << "-------------------------" << endl;
	int t;
	cout << "ENTER THE OPTION: ";
	cin >> t;
	cin.ignore();
	if(t==1){
		orderAP++;
		string tmp=to_string(orderAP);
		string sub=string(4-tmp.size(),'0')+tmp;
		dishID=sub;
		string thu=dishID;
		dishID="AP";
		dishID+=thu;
	}
	if(t==2){
		orderMC++;
		string tmp=to_string(orderMC);
		string sub=string(4-tmp.size(),'0')+tmp;
		dishID=sub;
		string thu=dishID;
		dishID="MC";
		dishID+=thu;
	}
	if(t==3){
		orderDE++;
		string tmp=to_string(orderDE);
		string sub=string(4-tmp.size(),'0')+tmp;
		dishID=sub;
		string thu=dishID;
		dishID="DE";
		dishID+=thu;
	}
	if(t==4){
		orderBE++;
		string tmp=to_string(orderBE);
		string sub=string(4-tmp.size(),'0')+tmp;
		dishID=sub;
		string thu=dishID;
		dishID="BE";
		dishID+=thu;
	}
	if(t==5){
		return;
	}
	id_add=dishID;
	cout<<"DISH NAME: ";
	getline(cin,dishName);
	name_add=dishName;
	cout<<"PRICE: ";
	getline(cin,Price);	
	price_add=Price;

}
//OUTPUT
void Dish::Output(){
	ifstream file("dish_1.dat");
	if(!file.is_open()){
		cerr<<"ERROR FILE"<<endl;
	}
	string line;
	while(getline(file,line)){
		cout<<line<<endl;
	}
	file.close();
}
void Dish::outputAP(){
	ifstream inputFile("dish_1.dat");
	if(!inputFile.is_open()){
		cerr<<"ERROR FILE"<<endl;
	}
	// ofstream outputFile(dish_2.dat,ios::out | ios::app);
	// if(!outputFile(dish_2.dat)){
	// 	cerr<<"ERROR FILE"<<endl;
	// }
	vector<string> dishList;
	string line;
	// outputFile<<"dishID    dishName         PRICE"<<endl;
	dishList.push_back("dishID    dishName         PRICE");
	while(getline(inputFile,line)){
		string tmp=line.substr(0,2);
		if(tmp=="AP"){
			//outputFile<<line<<endl;
			dishList.push_back(line);
		}
	}
	inputFile.close();
	// outputFile.close();
	for(int i=0;i<dishList.size();i++){
		cout<<dishList[i]<<endl;
	}
}
void Dish::outputMC(){
	ifstream inputFile("dish_1.dat");
	if(!inputFile.is_open()){
		cerr<<"ERROR FILE"<<endl;
	}
	// ofstream outputFile(dish_2.dat,ios::out | ios::app);
	// if(!outputFile(dish_2.dat)){
	// 	cerr<<"ERROR FILE"<<endl;
	// }
	vector<string> dishList;
	string line;
	// outputFile<<"dishID    dishName         PRICE"<<endl;
	dishList.push_back("dishID    dishName         PRICE");
	while(getline(inputFile,line)){
		string tmp=line.substr(0,2);
		if(tmp=="MC"){
			//outputFile<<line<<endl;
			dishList.push_back(line);
		}
	}
	inputFile.close();
	// outputFile.close();
	for(int i=0;i<dishList.size();i++){
		cout<<dishList[i]<<endl;
	}
}
void Dish::outputDE(){
	ifstream inputFile("dish_1.dat");
	if(!inputFile.is_open()){
		cerr<<"ERROR FILE"<<endl;
	}
	// ofstream outputFile(dish_2.dat,ios::out | ios::app);
	// if(!outputFile(dish_2.dat)){
	// 	cerr<<"ERROR FILE"<<endl;
	// }
	vector<string> dishList;
	string line;
	// outputFile<<"dishID    dishName         PRICE"<<endl;
	dishList.push_back("dishID    dishName         PRICE");
	while(getline(inputFile,line)){
		string tmp=line.substr(0,2);
		if(tmp=="DE"){
			//outputFile<<line<<endl;
			dishList.push_back(line);
		}
	}
	inputFile.close();
	// outputFile.close();
	for(int i=0;i<dishList.size();i++){
		cout<<dishList[i]<<endl;
	}
}
void Dish::outputBE(){
	ifstream inputFile("dish_1.dat");
	if(!inputFile.is_open()){
		cerr<<"ERROR FILE"<<endl;
	}
	// ofstream outputFile(dish_2.dat,ios::out | ios::app);
	// if(!outputFile(dish_2.dat)){
	// 	cerr<<"ERROR FILE"<<endl;
	// }
	vector<string> dishList;
	string line;
	// outputFile<<"dishID    dishName         PRICE"<<endl;
	dishList.push_back("dishID    dishName         PRICE");
	while(getline(inputFile,line)){
		string tmp=line.substr(0,2);
		if(tmp=="BE"){
			//outputFile<<line<<endl;
			dishList.push_back(line);
		}
	}
	inputFile.close();
	// outputFile.close();
	for(int i=0;i<dishList.size();i++){
		cout<<dishList[i]<<endl;
	}
}
//END OUTPUT

