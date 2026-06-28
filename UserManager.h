#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <string>

#include "User.h"

using namespace std;

class UserManager
{
private:
    vector<User> users;
    int currentUserIndex;

public:

    // Constructor
    UserManager();

    // File Handling
    void loadUsers();
    void saveUsers();

    // User Management
    void registerUser();
    bool loginUser();

    // Utility
    User* getCurrentUser();

    void displayAllUsers() const;
};

#endif