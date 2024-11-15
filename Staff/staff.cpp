#include "staff.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

Staff::Staff() : isLoggedIn(false) {}

bool Staff::login(const string& inputId, const string& inputPassword) {
    ifstream file("Staff/staff.dat");
    if (!file) {
        cerr << "ERROR FILE";
        return false;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string fileId, fileName, filePassword, fileShift;
        if (iss >> fileId >> fileName >> filePassword >> fileShift) {
            if (fileId == inputId && filePassword == inputPassword) {
                id = fileId;
                name = fileName;
                password = filePassword;
                shiftDetails = fileShift;
                isLoggedIn = true;
                cout << "DANG NHAP THANH CONG, CHAO MUNG: " << name << ".\n";
                string fileName="Staff/staff_info/Staff_"+id;
                ofstream fileOut(fileName);
                fileOut<<"MA NHAN VIEN: "<<id<<" | "<<"TEN NHAN VIEN: "<<name<<endl;
                fileOut.close();
                return true;
            }
        }
    }
    cout << "ID HOAC MAT KHAU KHONG HOP LE! VUI LONG DANG NHAP LAI!\n";
    return false;
}



void Staff::addNewStaff() {
    string newId = generateNewId();
    if (newId.empty()) {
        cerr << "ERROR FILE";
        return;
    }
    ofstream file("Staff/staff.dat", ios::app);
    if (!file) {
        cerr << "ERROR FILE";
        return;
    }

    string newName, newPassword, newShift;
    cout << "ID CUA BAN: " << newId << "\n";
    cout << "NHAP TEN CUA BAN: ";
    cin >> newName;
    cout << "NHAP MAT KHAU CUA BAN: ";
    cin >> newPassword;
    cout << "NHAP CA LAM CUA BAN: ";
    cin >> newShift;

    file << newId << " " << newName << " " << newPassword << " " << newShift << "\n";
    cout << "BAN DA DUOC THEM THANH CONG!\n";
}

void Staff::logout(string const& StaffID) {
    if (isLoggedIn) {
        cout << "DANG DANG XUAT...\n";
        isLoggedIn = false;
    } else {
        cout << "KET THUC CA LAM!\n";
    }
    string fileName="Staff/staff_info/Staff_"+StaffID;
    ofstream file(fileName, ios::app);
    if (!file) {
        cerr << "ERROR FILE";
        return;
    }
    file<<"TONG TIEN TRONG MOT CA LAM LA: "<<Order::shifttotalprice<<endl;
}

string Staff::generateNewId() {
    ifstream file("staff.dat");
    if (!file) {
        cerr << "ERROR FILE";
        return "";
    }

    string line;
    int maxId = 0;
    while (getline(file, line)) {
        istringstream iss(line);
        string fileId;
        if (iss >> fileId) {
            try {
                int numericId = stoi(fileId);
                maxId = max(maxId, numericId);
            } catch (const invalid_argument& e) {
                continue;
            }
        }
    }
    return to_string(maxId + 1);
}
