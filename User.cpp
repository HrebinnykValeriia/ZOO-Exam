#include "User.h"
#include <fstream>

admin::admin() {
}
admin::admin(string login, string password) {
    this->login = login;
    this->password = password;
}
bool admin::validatePassword(string password) {
    if (password.length() < 8) {
        return false;
    }
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;
    for (char c : password) {
        if (c >= 'A' && c <= 'Z') {
            hasUpper = true;
            continue;
        }
        if (c >= 'a' && c <= 'z') {
            hasLower = true;
            continue;
        }
        if (c >= '0' && c <= '9') {
            hasDigit = true;
            continue;
        }
        hasSpecial = true;
    }
    return hasUpper && hasLower && hasDigit && hasSpecial;
}
bool admin::userExists() {
    ifstream file(folderPath + "users.dat", ios::binary);
    if (!file.is_open()) {
        return false;
    }
    string savedLogin;
    string savedPassword;
    getline(file, savedLogin, '\0');
    getline(file, savedPassword, '\0');
    file.close();
    return !savedLogin.empty();
}
void admin::saveUser() {
    ofstream file(folderPath + "users.dat", ios::binary);
    if (!file.is_open()) {
        cout << "Cannot open users.dat" << endl;
        return;
    }
    file.write(login.c_str(), login.length() + 1);
    file.write(password.c_str(), password.length() + 1);
    file.close();
}
bool admin::registerAdmin() {
    if (userExists()) {
        cout << "Admin already exists" << endl;
        return false;
    }
    cout << "There is no acc. First of all, you must create new acc" << endl;
    cout << "Enter login: ";
    cin >> login;
    do {
        cout << "Enter password: ";
        cin >> password;
        if (!validatePassword(password)) {
            cout << endl;
            cout << "Password must contain:" << endl;
            cout << "- at least 8 characters" << endl;
            cout << "- digit" << endl;
            cout << "- uppercase letter" << endl;
            cout << "- lowercase letter" << endl;
            cout << "- special character" << endl;
            cout << endl;
        }
    } while (!validatePassword(password));
    saveUser();
    cout << "Admin registered successfully" << endl;
    return true;
}
bool admin::checkPassword(string password) {
    ifstream file(folderPath + "users.dat", ios::binary);
    if (!file.is_open()) {
        return false;
    }
    string savedLogin;
    string savedPassword;
    getline(file, savedLogin, '\0');
    getline(file, savedPassword, '\0');
    file.close();
    return login == savedLogin && password == savedPassword;
}
bool admin::loginAdmin() {
    if (!userExists()) {
        cout << "There is no admin yet" << endl;
        return false;
    }
    cout << "LOGIN" << endl;
    cout << "Login: ";
    cin >> login;
    cout << "Password: ";
    cin >> password;
    if (checkPassword(password)) {
        cout << "Login successful" << endl;
        return true;
    }
    cout << "Incorrect login or password" << endl;
    return false;
}
bool admin::exists() {
    return userExists();
}