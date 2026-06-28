#ifndef RECIPE_MANAGER_H
#define RECIPE_MANAGER_H

#include <iostream>
#include <vector>
#include <string>

#include "Recipe.h"
using namespace std;

class RecipeManager
{
private:
    vector<Recipe> recipes;
    vector<string> split(const string &text, char delimiter);

public:

    // Constructor
    RecipeManager();

    // Recipe Management
    void addRecipe();
    void deleteRecipe(int recipeID);
    void updateRecipe(int recipeID);

    // Display
    void displayAllRecipes() const;

    // Search
   void searchByName(const string &recipeName) const;
   void searchByIngredient(const string &ingredient) const;
   void searchByCategory(const string &category) const;
   void searchByDiet(const string &diet) const;
   void searchByCookingTime(int &cookingTime) const;

    // File Handling
    void loadRecipes();
    void saveRecipes();

    // Utility
    vector<Recipe>& getRecipes();
};

#endif