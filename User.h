#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

class User {
protected:
    int id;
    std::string name;
    std::string password;

public:
    User(int id, std::string name, std::string password);
    virtual ~User() {}

    bool login(std::string pass);
    std::string getName();

    virtual void displayMenu() = 0;
    virtual std::string getType() = 0;
};

class Admin : public User {
public:
    Admin(int id, std::string name, std::string password);
    void displayMenu() override;
    std::string getType() override;
};

class Customer : public User {
public:
    Customer(int id, std::string name, std::string password);
    void displayMenu() override;
    std::string getType() override;
};

#endif