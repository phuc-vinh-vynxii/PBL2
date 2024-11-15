#ifndef STAFF_H
#define STAFF_H
#include "../Order/order.h"
#include <string>
using namespace std;

class Staff {
private:
    string id;
    string name;
    string password;
    string shiftDetails;
    bool isLoggedIn;
    string generateNewId();

public:
    Staff();
    bool login(const string& inputId, const string& inputPassword);
    void addNewStaff();
    void logout(string const& StaffID);
};

#endif