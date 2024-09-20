#include <bits/stdc++.h>
#include "dish.cpp"
#include "orderitem/orderItem.cpp"

using namespace std;
int main() {
	docFile();
	Thaydoi();
	// Dish b;
	// b.Output();
	OrderItem a;
	while(1){
		cout<<"----------------------------"<<endl;
		cout<<"1.Chon mon"<<endl;
		cout<<"2.In cac mon da chon"<<endl;
		cout<<"3.Thoat"<<endl;
		cout<<"----------------------------"<<endl;
		int t;
		cin>>t;
		if(t==1){
			a.ChooseDish();

		}
		if(t==2){
			a.outputChange();
		}
		if(t==3){
			break;
		}
	}
}

