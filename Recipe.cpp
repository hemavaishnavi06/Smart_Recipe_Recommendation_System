#include "Recipe.h"
using namespace std;

// Default Constructor
Recipe::Recipe()
{
    recipeID = 0;
    recipeName = "";
    category = "";
    dietType = "";
    cookingTime = 0;
    rating = 0.0;
    calories = 0;
}

// Parameterized Constructor
Recipe::Recipe(int id,
               string name,
               string category,
               string diet,
               int time,
               vector<string> ingredients,
               vector<string> instructions,
               float rating,
               int calories)
{
    recipeID = id;
    recipeName = name;
    this->category = category;
    dietType = diet;
    cookingTime = time;
    this->ingredients = ingredients;
    this->instructions = instructions;
    this->rating = rating;
    this->calories = calories;
}


void Recipe::setRecipeID(int id)
{
    recipeID = id;
}

void Recipe::setRecipeName(string name)
{
    recipeName = name;
}

void Recipe::setCategory(string category)
{
    this->category = category;
}

void Recipe::setDietType(string diet)
{
    dietType = diet;
}

void Recipe::setCookingTime(int time)
{
    cookingTime = time;
}

void Recipe::setIngredients(vector<string> ingredients)
{
    this->ingredients = ingredients;
}

void Recipe::setInstructions(vector<string> instructions)
{
    this->instructions = instructions;
}

void Recipe::setRating(float rating)
{
    this->rating = rating;
}

void Recipe::setCalories(int calories)
{
    this->calories = calories;
}


int Recipe::getRecipeID() const
{
    return recipeID;
}

string Recipe::getRecipeName() const
{
    return recipeName;
}

string Recipe::getCategory() const
{
    return category;
}

string Recipe::getDietType() const
{
    return dietType;
}

int Recipe::getCookingTime() const
{
    return cookingTime;
}

vector<string> Recipe::getIngredients() const
{
    return ingredients;
}

vector<string> Recipe::getInstructions() const
{
    return instructions;
}

float Recipe::getRating() const
{
    return rating;
}

int Recipe::getCalories() const
{
    return calories;
}

// Display Recipe
void Recipe::displayRecipe() const
{
    cout << "\n=========================================\n";
    cout << "Recipe ID      : " << recipeID << endl;
    cout << "Recipe Name    : " << recipeName << endl;
    cout << "Category       : " << category << endl;
    cout << "Diet Type      : " << dietType << endl;
    cout << "Cooking Time   : " << cookingTime << " minutes" << endl;
    cout << "Calories       : " << calories << " kcal" << endl;
    cout << "Rating         : " << rating << endl;

    cout << "\nIngredients:\n";
    for (const string &ingredient : ingredients)
    {
        cout << " - " << ingredient << endl;
    }

    cout << "\nInstructions:\n";
    for (size_t i = 0; i < instructions.size(); i++)
    {
        cout << i + 1 << ". " << instructions[i] << endl;
    }

    cout << "=========================================\n";
}