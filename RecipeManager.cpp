#include "RecipeManager.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include<string>

using namespace std;

// Constructor
RecipeManager::RecipeManager()
{
    loadRecipes();
}

// Return recipe list
vector<Recipe>& RecipeManager::getRecipes()
{
    return recipes;
}

// Display all recipes
void RecipeManager::displayAllRecipes() const
{
    if (recipes.empty())
    {
        cout << "\nNo recipes available.\n";
        return;
    }

    cout << "\n========== ALL RECIPES ==========\n";

    for (const Recipe &recipe : recipes)
    {
        recipe.displayRecipe();
    }
}

// Add Recipe
void RecipeManager::addRecipe()
{
    int id;
    string name;
    string category;
    string diet;

    int cookingTime;
    int calories;

    float rating;

    int ingredientCount;
    int stepCount;

    vector<string> ingredients;
    vector<string> instructions;

    cout << "\nRecipe ID : ";
    cin >> id;
    cin.ignore();

    cout << "Recipe Name : ";
    getline(cin, name);

    cout << "Category : ";
    getline(cin, category);

    cout << "Diet Type : ";
    getline(cin, diet);

    cout << "Cooking Time (minutes) : ";
    cin >> cookingTime;

    cout << "Calories : ";
    cin >> calories;

    cout << "Rating : ";
    cin >> rating;

    cout << "Number of Ingredients : ";
    cin >> ingredientCount;
    cin.ignore();

    for (int i = 0; i < ingredientCount; i++)
    {
        string ingredient;

        cout << "Ingredient " << i + 1 << " : ";
        getline(cin, ingredient);

        ingredients.push_back(ingredient);
    }

    cout << "Number of Steps : ";
    cin >> stepCount;
    cin.ignore();

    for (int i = 0; i < stepCount; i++)
    {
        string step;

        cout << "Step " << i + 1 << " : ";
        getline(cin, step);

        instructions.push_back(step);
    }

    Recipe newRecipe(
        id,
        name,
        category,
        diet,
        cookingTime,
        ingredients,
        instructions,
        rating,
        calories
    );

    recipes.push_back(newRecipe);

    saveRecipes();

    cout << "\nRecipe added successfully.\n";
}

// Delete Recipe
void RecipeManager::deleteRecipe(int recipeID)
{
    for (auto it = recipes.begin(); it != recipes.end(); ++it)
    {
        if (it->getRecipeID() == recipeID)
        {
            recipes.erase(it);

            saveRecipes();

            cout << "\nRecipe deleted successfully.\n";
            return;
        }
    }

    cout << "\nRecipe not found.\n";
}

// Update Recipe
void RecipeManager::updateRecipe(int recipeID)
{
    for (Recipe &recipe : recipes)
    {
        if (recipe.getRecipeID() == recipeID)
        {
            int choice;

            cout << "\nUpdate Menu\n";
            cout << "1. Recipe Name\n";
            cout << "2. Category\n";
            cout << "3. Diet Type\n";
            cout << "4. Cooking Time\n";
            cout << "5. Calories\n";
            cout << "6. Rating\n";

            cout << "Enter Choice : ";
            cin >> choice;
            cin.ignore();

            switch (choice)
            {
                case 1:
                {
                    string name;

                    cout << "New Recipe Name : ";
                    getline(cin, name);

                    recipe.setRecipeName(name);
                    break;
                }

                case 2:
                {
                    string category;

                    cout << "New Category : ";
                    getline(cin, category);

                    recipe.setCategory(category);
                    break;
                }

                case 3:
                {
                    string diet;

                    cout << "New Diet Type : ";
                    getline(cin, diet);

                    recipe.setDietType(diet);
                    break;
                }

                case 4:
                {
                    int time;

                    cout << "New Cooking Time : ";
                    cin >> time;

                    recipe.setCookingTime(time);
                    break;
                }

                case 5:
                {
                    int calories;

                    cout << "New Calories : ";
                    cin >> calories;

                    recipe.setCalories(calories);
                    break;
                }

                case 6:
                {
                    float rating;

                    cout << "New Rating : ";
                    cin >> rating;

                    recipe.setRating(rating);
                    break;
                }

                default:
                    cout << "\nInvalid Choice.\n";
                    return;
            }

            saveRecipes();

            cout << "\nRecipe updated successfully.\n";
            return;
        }
    }

    cout << "\nRecipe not found.\n";
}

// Search by Name
void RecipeManager::searchByName(const string &recipeName) const
{
    bool found = false;

    for (const Recipe &recipe : recipes)
    {
        if (recipe.getRecipeName() == recipeName)
        {
            recipe.displayRecipe();
            found = true;
        }
    }

    if (!found)
        cout << "\nRecipe not found.\n";
}

// Search by Ingredient
void RecipeManager::searchByIngredient(const string &ingredient) const
{
    bool found = false;

    for (const Recipe &recipe : recipes)
    {
        vector<string> ingredients = recipe.getIngredients();

        for (const string &item : ingredients)
        {
            if (item == ingredient)
            {
                recipe.displayRecipe();
                found = true;
                break;
            }
        }
    }

    if (!found)
        cout << "\nNo recipes found.\n";
}

// Search by Category
void RecipeManager::searchByCategory(const string &category) const
{
    bool found = false;

    for (const Recipe &recipe : recipes)
    {
        if (recipe.getCategory() == category)
        {
            recipe.displayRecipe();
            found = true;
        }
    }

    if (!found)
        cout << "\nNo recipes found.\n";
}

// Search by Diet
void RecipeManager::searchByDiet(const string &diet) const
{
    bool found = false;

    for (const Recipe &recipe : recipes)
    {
        if (recipe.getDietType() == diet)
        {
            recipe.displayRecipe();
            found = true;
        }
    }

    if (!found)
        cout << "\nNo recipes found.\n";
}

// Search by Cooking Time
void RecipeManager::searchByCookingTime(int &cookingTime) const
{
    bool found = false;

    for (const Recipe &recipe : recipes)
    {
        if (recipe.getCookingTime() <= cookingTime)
        {
            recipe.displayRecipe();
            found = true;
        }
    }

    if (!found)
    {
        cout << "\nNo recipes found.\n";
    }
}

// Split string using delimiter
vector<string> RecipeManager::split(const string &text, char delimiter)
{
    vector<string> result;

    string token;

    stringstream ss(text);

    while(getline(ss, token, delimiter))
    {
        result.push_back(token);
    }

    return result;
}

// Load Recipes
void RecipeManager::loadRecipes()
{
    recipes.clear();

    ifstream file("recipes.csv");

    if (!file.is_open())
    {
        cout << "Unable to open recipes.csv\n";
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
        string name;
        string category;
        string diet;
        string cookingTime;
        string calories;
        string rating;
        string ingredientString;
        string instructionString;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, category, ',');
        getline(ss, diet, ',');
        getline(ss, cookingTime, ',');
        getline(ss, calories, ',');
        getline(ss, rating, ',');
        getline(ss, ingredientString, ',');
        getline(ss, instructionString);

        if (id.empty() || cookingTime.empty() ||
            calories.empty() || rating.empty())
        {
            cout << "Skipping invalid row:\n";
            cout << line << endl;
            continue;
        }

        vector<string> ingredients = split(ingredientString, '|');
        vector<string> instructions = split(instructionString, '|');

        try
        {
            Recipe recipe(
                stoi(id),
                name,
                category,
                diet,
                stoi(cookingTime),
                ingredients,
                instructions,
                stof(rating),
                stoi(calories)
            );

            recipes.push_back(recipe);
        }
        catch (...)
        {
            cout << "\nError while reading row:\n";
            cout << line << endl;
        }
    }

    file.close();
}

// Save Recipes
void RecipeManager::saveRecipes()
{
    ofstream file("recipes.csv");

    if(!file.is_open())
    {
        cout<<"Unable to save file.\n";
        return;
    }

    file<<"RecipeID,RecipeName,Category,Diet,CookingTime,Calories,Rating,Ingredients,Instructions\n";

    for(const Recipe &recipe : recipes)
    {
        file<<recipe.getRecipeID()<<",";

        file<<recipe.getRecipeName()<<",";

        file<<recipe.getCategory()<<",";

        file<<recipe.getDietType()<<",";

        file<<recipe.getCookingTime()<<",";

        file<<recipe.getCalories()<<",";

        file<<recipe.getRating()<<",";

        vector<string> ingredients=
        recipe.getIngredients();

        for(size_t i=0;i<ingredients.size();i++)
        {
            file<<ingredients[i];

            if(i!=ingredients.size()-1)
                file<<"|";
        }

        file<<",";

        vector<string> instructions=
        recipe.getInstructions();

        for(size_t i=0;i<instructions.size();i++)
        {
            file<<instructions[i];

            if(i!=instructions.size()-1)
                file<<"|";
        }

        file<<"\n";
    }

    file.close();
}