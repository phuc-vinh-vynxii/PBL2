#include <bits/stdc++.h>
using namespace std;
#ifndef DISH_H
#define DISH_H
class Dish{
	private:
		static int Order;
		static int orderAP;
		static int orderMC;
		static int orderDE;
		static int orderBE;
		string dishID;
		string dishName;
		string Price;
	public:
		Dish();
		void Input();
		void Output();
		void outputAP();
		void outputMC();
		void outputDE();
		void outputBE();
		friend void Push_dishID(Dish&);
		static int& getAP();
		static int& getMC();
		static int& getDE();
		static int& getBE();
		void addDish();
		friend void deleteDish();
};
#endif
