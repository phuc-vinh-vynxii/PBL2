#include <bits/stdc++.h>
#include "Payment/payment.cpp"
#include "Order/Order.cpp"

using namespace std;

int main(){
    int t = 2;
    while(t--){
        Payment a;
        a.showList();
        a.processPayment();
    }
}