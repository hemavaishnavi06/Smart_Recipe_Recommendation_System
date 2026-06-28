#include "UserManager.h"

#include <fstream>
#include <sstream>

using namespace std;

// Constructor
UserManager::UserManager()
{
    currentUserIndex = -1;
    loadUsers();
}

//Load Users
void UserManager::loadUsers()
{
    users.clear();

    ifstream file("users.csv");

    if (!file.is_open())
    {
        cout << "\nUnable to open users.csv\n";
        return;
    }

    string line;

    // Skip header
    getline(file, line);

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        stringstream ss(line);

        string id;
        string username;
        string password;

        getline(ss, id, ',');
        getline(ss, username, ',');
        getline(ss, password);

        if (id.empty())
            continue;

        User user(
            stoi(id),
            username,
            password
        );

        users.push_back(user);
    }

    file.close();

    // Debug Output
    cout << "\n========== USERS LOADED ==========\n";

    if(users.empty())
    {
        cout << "No Users Found.\n";
    }
    else
    {
        for(const User &user : users)
        {
            cout << "ID : " << user.getUserID()
                 << "  Username : " << user.getUsername()
                 << "  Password : " << user.getPassword()
                 << endl;
        }
    }

    cout << "==================================\n";
}

// Save Users
void UserManager::saveUsers()
{
    ofstream file("users.csv");

    if (!file.is_open())
    {
        cout << "Unable to save users.csv\n";
        return;
    }

    file << "UserID,Username,Password\n";

    for (const User &user : users)
    {
        file
            << user.getUserID() << ","
            << user.getUsername() << ","
            << user.getPassword()
            << "\n";
    }

    file.close();
}

// Register User
void UserManager::registerUser()
{
    int id;
    string username;
    string password;

    cout << "\nUser ID : ";
    cin >> id;
    cin.ignore();

    // Check duplicate ID
    for (const User &user : users)
    {
        if (user.getUserID() == id)
        {
            cout << "\nUser ID already exists.\n";
            return;
        }
    }

    cout << "Username : ";
    getline(cin, username);

    // Check duplicate username
    for (const User &user : users)
    {
        if (user.getUsername() == username)
        {
            cout << "\nUsername already exists.\n";
            return;
        }
    }

    cout << "Password : ";
    getline(cin, password);

    User newUser(id, username, password);

    users.push_back(newUser);

    saveUsers();

    cout << "\nRegistration Successful.\n";
}

// Login User
bool UserManager::loginUser()
{
    string username;
    string password;

    cout << "\nUsername : ";
    getline(cin, username);

    cout << "Password : ";
    getline(cin, password);

    cout << "\nEntered Username : " << username << endl;
    cout << "Entered Password : " << password << endl;

    cout << "\nChecking Users...\n";

    for (size_t i = 0; i < users.size(); i++)
    {
        cout << "\nStored Username : "
             << users[i].getUsername() << endl;

        cout << "Stored Password : "
             << users[i].getPassword() << endl;

        if (users[i].login(username, password))
        {
            currentUserIndex = i;

            cout << "\nLogin Successful.\n";

            return true;
        }
    }

    cout << "\nInvalid Username or Password.\n";

    return false;
}

// Return Current User
User* UserManager::getCurrentUser()
{
    if (currentUserIndex == -1)
        return nullptr;

    return &users[currentUserIndex];
}

// Display All Users
void UserManager::displayAllUsers() const
{
    if (users.empty())
    {
        cout << "\nNo Users Registered.\n";
        return;
    }

    cout << "\n========== REGISTERED USERS ==========\n";

    for (const User &user : users)
    {
        cout
            << "ID : "
            << user.getUserID()
            << "   Username : "
            << user.getUsername()
            << endl;
    }
}