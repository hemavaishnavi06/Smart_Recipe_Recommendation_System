#ifndef RECIPE_H
#define RECIPE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Recipe
{
private:
    int recipeID;
    string recipeName;
    string category;
    string dietType;
    int cookingTime;
    vector<string> ingredients;
    vector<string> instructions;
    float rating;
    int calories;

public:

    // Constructors
    Recipe();

    Recipe(int id,
           string name,
           string category,
           string diet,
           int time,
           vector<string> ingredients,
           vector<string> instructions,
           float rating,
           int calories);

    // Setters
    void setRecipeID(int id);
    void setRecipeName(string name);
    void setCategory(string category);
    void setDietType(string diet);
    void setCookingTime(int time);
    void setIngredients(vector<string> ingredients);
    void setInstructions(vector<string> instructions);
    void setRating(float rating);
    void setCalories(int calories);

    // Getters
    int getRecipeID() const;
    string getRecipeName() const;
    string getCategory() const;
    string getDietType() const;
    int getCookingTime() const;
    vector<string> getIngredients() const;
    vector<string> getInstructions() const;
    float getRating() const;
    int getCalories() const;

    // Display
    void displayRecipe() const;
};

#endif