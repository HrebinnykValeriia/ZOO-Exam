#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include "File.h"
using namespace std;

class admin {
private:
    string login;
    string password;
    bool userExists();
    void saveUser();
    bool checkPassword(string password);
public:
    admin();
    admin(string login, string password);
    bool registerAdmin();
    bool loginAdmin();
    bool validatePassword(string password);
    bool exists();
};
#endif