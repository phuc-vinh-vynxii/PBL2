#include <bits/stdc++.h>
#include "order.cpp"
using namespace std;

int main(){
    int t = 4;
    while (t--){
        Order od;
        od.showList();
        if (t == 1){
            od.cancelOrder();
        }
    }
}