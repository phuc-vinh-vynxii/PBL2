#include <iostream>
#include <fstream>
#include "orderItem.h"
#include "../dish.h"
using namespace std;
void OrderItem::OrderItem_Output(){
    Dish tmp;
    tmp.Output();
}
void OrderItem::OrderItem_outputAP(){
    Dish tmp;
    tmp.outputAP();   
}
void OrderItem::OrderItem_outputMC(){
    Dish tmp;
    tmp.outputMC();      
}
void OrderItem::OrderItem_outputDE(){
    Dish tmp;
    tmp.outputDE();     
}
void OrderItem::OrderItem_outputBE(){
    Dish tmp;
    tmp.outputBE();   
}
int StrToInt(string tmp){
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
string IntToStr(int a){
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
void OrderItem::ChooseDish(){
    cout<<"-------------------------"<<endl;
    cout<<"1. APPETIZER"<<endl;
    cout<<"2. MAIN COURSE"<<endl;
    cout<<"3. DESSERT"<<endl;
    cout<<"4. BEVERAGE"<<endl;
    cout<<"5. FULL MENU"<<endl;
    cout<<"-------------------------"<<endl;
    int t;
    cout<<"NHAP LUA CHON: ";
    cin>>t;
    cin.ignore();
    ifstream inputFile ("dish_1.dat");
    if(!inputFile.is_open()){
        cerr<<"ERROR FILE"<<endl;
    }
    ofstream outputFile("orderItem.dat", ios::out | ios::app);
    if(!outputFile.is_open()){
        cerr<<"ERROR FILE"<<endl;
    }
    string ketqua;
    string tmp;
    int soluong;
    int sl;
    if(t==1){
        OrderItem_outputAP();
        cout<<"NHAP MON THEO ID: ";
        getline(cin,tmp);
        cout<<"NHAP SO LUONG: ";
        cin>>sl;
        cin.ignore();
    }
    if(t==2){
        OrderItem_outputMC();
        cout<<"NHAP MON THEO ID: ";
        getline(cin,tmp);
        cout<<"NHAP SO LUONG: ";
        cin>>sl;
        cin.ignore();
    }
    if(t==3){
        OrderItem_outputDE();
        cout<<"NHAP MON THEO ID: ";
        getline(cin,tmp);
        cout<<"NHAP SO LUONG: ";
        cin>>sl;
        cin.ignore();
    }
    if(t==4){
        OrderItem_outputBE();
        cout<<"NHAP MON THEO ID: ";
        getline(cin,tmp);
        cout<<"NHAP SO LUONG: ";
        cin>>sl;
        cin.ignore();
    }
    if(t==5){
        OrderItem_Output();
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
                string b=IntToStr(a);
                outputFile<<id<<"     "<<name<<"     "<<b<<"     "<<soluong<<endl;
            }
            check=0;
        }  
        dem=1;     
    }
    inputFile.close();
    outputFile.close();
}
void OrderItem::outputChange(){
    ifstream File("orderItem.dat");
    string line;
    while(getline(File,line)){
        cout<<line<<endl;
    }
}