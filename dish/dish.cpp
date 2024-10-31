#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "dish.h"
using namespace std;
#include <fstream>

string AP,MC,DE,BE;

void read_File(){
	ifstream file("Dish/dish.dat");
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

int ConvertString(string tmp){
	int size=tmp.size();
	int dem=0;
	while(size--){
		dem=dem*10+(tmp[tmp.size()-size-1]-'0');
	}
	return dem;
}

void Change(){
	Dish::getAP()=ConvertString(AP);
	Dish::getMC()=ConvertString(MC);
	Dish::getDE()=ConvertString(DE);
	Dish::getBE()=ConvertString(BE);
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

int Dish::Order=orderAP+orderMC+orderDE+orderBE;
Dish::Dish(){
	Order++;
};

string name_add,id_add,price_add;

void Dish::addDish(){
	Input();
	fstream file("Dish/dish.dat", ios::in | ios::out | ios::ate);
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

void Dish::deleteDish(){
	Output();
	ifstream fileIn("Dish/dish.dat");
	if (!fileIn){
		cerr << "ERROR FILE" << endl;
		return;
	}
	vector<string> dishList;
	string ID_delete;
	cout << "NHAP ID MON AN CAN XOA:";
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
		ofstream fileOut("Dish/dish.dat");
		if (!fileOut) {
			cerr << "ERROR FILE" << endl;
			return;
		}
		else{
			for (const auto &l: dishList){
				fileOut << l << endl;
			}
		}
		fileOut.close();
		cout << "DA XOA MON CO ID:" << ID_delete << endl;
	}
	else{
		cout << "KHONG TIM THAY MON AN VOI ID:" << ID_delete << endl;
	}
}

void Dish::Input(){
	cout << "-------------------------" << endl;
	cout << "1. THEM MON KHAI VI (APPETIZER)" << endl;		
	cout << "2. THEM MON CHINH (MAIN COURSE)" << endl;
	cout << "3. THEM MON TRANG MIENG (DESSERT)" << endl;
	cout << "4. THEM DO UONG (BEVERAGE)" << endl;
	cout << "5. KET THUC" << endl;
	cout << "-------------------------" << endl;
	int t;
	cout << "| NHAP LUA CHON: ";
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

void Dish::Output(){
	ifstream file("Dish/dish.dat");
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
	ifstream inputFile("Dish/dish.dat");
	if(!inputFile.is_open()){
		cerr<<"ERROR FILE"<<endl;
	}
	vector<string> dishList;
	string line;
	dishList.push_back("dishID    dishName         PRICE");
	while(getline(inputFile,line)){
		string tmp=line.substr(0,2);
		if(tmp=="AP"){
			dishList.push_back(line);
		}
	}
	inputFile.close();
	for(int i=0;i<dishList.size();i++){
		cout<<dishList[i]<<endl;
	}
}

void Dish::outputMC(){
	ifstream inputFile("Dish/dish.dat");
	if(!inputFile.is_open()){
		cerr<<"ERROR FILE"<<endl;
	}
	vector<string> dishList;
	string line;
	dishList.push_back("dishID    dishName         PRICE");
	while(getline(inputFile,line)){
		string tmp=line.substr(0,2);
		if(tmp=="MC"){
			dishList.push_back(line);
		}
	}
	inputFile.close();
	for(int i=0;i<dishList.size();i++){
		cout<<dishList[i]<<endl;
	}
}

void Dish::outputDE(){
	ifstream inputFile("Dish/dish.dat");
	if(!inputFile.is_open()){
		cerr<<"ERROR FILE"<<endl;
	}
	vector<string> dishList;
	string line;
	dishList.push_back("dishID    dishName         PRICE");
	while(getline(inputFile,line)){
		string tmp=line.substr(0,2);
		if(tmp=="DE"){
			dishList.push_back(line);
		}
	}
	inputFile.close();
	for(int i=0;i<dishList.size();i++){
		cout<<dishList[i]<<endl;
	}
}

void Dish::outputBE(){
	ifstream inputFile("Dish/dish.dat");
	if(!inputFile.is_open()){
		cerr<<"ERROR FILE"<<endl;
	}
	vector<string> dishList;
	string line;
	dishList.push_back("dishID    dishName         PRICE");
	while(getline(inputFile,line)){
		string tmp=line.substr(0,2);
		if(tmp=="BE"){
			dishList.push_back(line);
		}
	}
	inputFile.close();
	for(int i=0;i<dishList.size();i++){
		cout<<dishList[i]<<endl;
	}
}

