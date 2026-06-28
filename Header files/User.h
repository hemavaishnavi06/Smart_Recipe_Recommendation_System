#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User
{
private:

    int userID;
    string username;
    string password;

    vector<int> favoriteRecipes;
    vector<int> mealHistory;

public:

    // Constructors
    User();
    User(int id, string name, string pass);

    // Setters
    void setUserID(int id);
    void setUsername(const string &name);
    void setPassword(const string &pass);

    // Getters
    int getUserID() const;
    string getUsername() const;
    string getPassword() const;
    vector<int> getFavoriteRecipes() const;
    vector<int> getMealHistory() const;

    // Login
    bool login(const string &name, const string &pass) const;

    // Favourite Recipes
    void addFavorite(int recipeID);
    void removeFavorite(int recipeID);
    void displayFavorites() const;

    // Meal History
    void addMealHistory(int recipeID);
    void displayMealHistory() const;
};

#endif