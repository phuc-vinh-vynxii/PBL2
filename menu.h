#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Dish/dish.cpp"
#include "Order/order.cpp"
#include "Payment/payment.cpp"
using namespace std;
#ifndef MENU
#define MENU
void Menu(){
    read_File();
    Change();
    while(1){
        cout<<"-------------------------"<<endl;
        cout<<"1. DON HANG MOI"<<endl;
        cout<<"2. DIEU CHINH THUC DON"<<endl;
        cout<<"3. KET THUC DAT HANG"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<"| NHAP LUA CHON: ";
        int t;
        cin>>t;
        int check=0;
        if(t==1){
            Payment items;
            while(1){
                cout<<"------------------------"<<endl;
                cout<<"1. CHON MON"<<endl;
                cout<<"2. XEM DON HANG"<<endl;
                if(check==1){
                    cout<<"3. THANH TOAN DON HANG"<<endl;
                    cout<<"4. HUY DON HANG"<<endl;
                }
                cout<<"------------------------"<<endl;
                cout<<"| NHAP LUA CHON: ";
                int choose;
                cin>>choose;
                if(choose==1){
                    items.ChooseDish();
                    check=1;
                }
                if(choose==2){
                    items.CreateOrderMedium();
                    items.showList();
                }
                if(choose==3){
                    items.CreateOrder();
                    items.processPayment();
                    break;
                }
                if(choose==4){
                    items.CreateOrder();
                    items.cancelPayment();
                    break;
                }
                if(choose>4){
                    cout<<"LUA CHON KHONG HOP LE. VUI LONG NHAP LAI"<<endl;
                }
            }
        }
        if(t==2){
            Dish dish;
            while(1){
                cout<<"------------------------"<<endl;
                cout<<"1. THEM MON AN"<<endl;
                cout<<"2. XOA MON AN"<<endl;
                cout<<"3. THOAT"<<endl;
                cout<<"------------------------"<<endl;
                cout<<"| NHAP LUA CHON: ";
                int choose; cin >> choose;
                cin.ignore();
                if(choose==1){
                    dish.addDish();
                }
                if(choose==2){
                    dish.deleteDish();
                }
                if(choose>2){
                    cout<<"LUA CHON KHONG HOP LE. VUI LONG NHAP LAI"<<endl;
                }
            }
        }
        if(t==3){
            break;
        }
    }
}
#endif