#include "User.h"

#include <iostream>
#include <algorithm>

using namespace std;

// Constructor
User::User()
{
    userID = 0;
    username = "";
    password = "";
}

// Parameterized Constructor
User::User(int id, string name, string pass)
{
    userID = id;
    username = name;
    password = pass;
}

// Setters
void User::setUserID(int id)
{
    userID = id;
}

void User::setUsername(const string &name)
{
    username = name;
}

void User::setPassword(const string &pass)
{
    password = pass;
}

// Getters
int User::getUserID() const
{
    return userID;
}

string User::getUsername() const
{
    return username;
}

string User::getPassword() const
{
    return password;
}

vector<int> User::getFavoriteRecipes() const
{
    return favoriteRecipes;
}

vector<int> User::getMealHistory() const
{
    return mealHistory;
}

// Login
bool User::login(const string &name, const string &pass) const
{
    return (username == name && password == pass);
}

// Favourite Recipes
void User::addFavorite(int recipeID)
{
    for(int id : favoriteRecipes)
    {
        if(id == recipeID)
        {
            cout << "\nRecipe already exists in favourites.\n";
            return;
        }
    }

    favoriteRecipes.push_back(recipeID);

    cout << "\nRecipe added to favourites.\n";
}

void User::removeFavorite(int recipeID)
{
    for(auto it = favoriteRecipes.begin(); it != favoriteRecipes.end(); it++)
    {
        if(*it == recipeID)
        {
            favoriteRecipes.erase(it);

            cout << "\nRecipe removed from favourites.\n";
            return;
        }
    }

    cout << "\nRecipe not found in favourites.\n";
}

void User::displayFavorites() const
{
    if(favoriteRecipes.empty())
    {
        cout << "\nNo favourite recipes.\n";
        return;
    }

    cout << "\nFavourite Recipe IDs\n";

    for(int id : favoriteRecipes)
    {
        cout << id << endl;
    }
}

// Meal History
void User::addMealHistory(int recipeID)
{
    mealHistory.push_back(recipeID);

    cout << "\nMeal added to history.\n";
}

void User::displayMealHistory() const
{
    if(mealHistory.empty())
    {
        cout << "\nMeal history is empty.\n";
        return;
    }

    cout << "\nMeal History\n";

    for(int id : mealHistory)
    {
        cout << id << endl;
    }
}