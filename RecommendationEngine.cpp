#include "RecommendationEngine.h"

#include <iostream>
#include <algorithm>

using namespace std;

// Constructor
RecommendationEngine::RecommendationEngine(RecipeManager &manager)
    : recipeManager(manager)
{
}

// Calculate Ingredient Match Score
int RecommendationEngine::calculateMatchScore(
    const Recipe &recipe,
    const vector<string> &ingredients) const
{
    int score = 0;

    vector<string> recipeIngredients = recipe.getIngredients();

    for (const string &userIngredient : ingredients)
    {
        for (const string &recipeIngredient : recipeIngredients)
        {
            if (userIngredient == recipeIngredient)
            {
                score++;
            }
        }
    }

    return score;
}

// Recommend By Ingredients
void RecommendationEngine::recommendByIngredients(
    const vector<string> &ingredients)
{
    vector<Recipe> recipes = recipeManager.getRecipes();

    vector<pair<double, Recipe>> recommendedRecipes;

    for (const Recipe &recipe : recipes)
    {
        int ingredientMatches =
            calculateMatchScore(recipe, ingredients);

        if (ingredientMatches > 0)
        {
            double recommendationScore =
                (ingredientMatches * 5.0) +
                (recipe.getRating() * 2.0) -
                (recipe.getCookingTime() / 10.0);

            recommendedRecipes.push_back(
                {recommendationScore, recipe});
        }
    }

    sort(
        recommendedRecipes.begin(),
        recommendedRecipes.end(),
        [](const pair<double, Recipe> &a,
           const pair<double, Recipe> &b)
        {
            return a.first > b.first;
        });

    if (recommendedRecipes.empty())
    {
        cout << "\nNo matching recipes found.\n";
        return;
    }

    cout << "\n========== Recommended Recipes ==========\n";

    for (const auto &item : recommendedRecipes)
    {
        cout << "\nRecommendation Score : "
             << item.first << endl;

        item.second.displayRecipe();
    }
}

// Recommend By Category
void RecommendationEngine::recommendByCategory(
    const string &category)
{
    vector<Recipe> recipes = recipeManager.getRecipes();

    bool found = false;

    cout << "\n========== Category Recommendations ==========\n";

    for (const Recipe &recipe : recipes)
    {
        if (recipe.getCategory() == category)
        {
            recipe.displayRecipe();
            found = true;
        }
    }

    if (!found)
    {
        cout << "\nNo recipes found in this category.\n";
    }
}

// Recommend By Diet
void RecommendationEngine::recommendByDiet(
    const string &diet)
{
    vector<Recipe> recipes = recipeManager.getRecipes();

    bool found = false;

    cout << "\n========== Diet Recommendations ==========\n";

    for (const Recipe &recipe : recipes)
    {
        if (recipe.getDietType() == diet)
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

// Recommend Quick Meals
void RecommendationEngine::recommendQuickMeals(
    int maxCookingTime)
{
    vector<Recipe> recipes = recipeManager.getRecipes();

    bool found = false;

    cout << "\n========== Quick Meals ==========\n";

    for (const Recipe &recipe : recipes)
    {
        if (recipe.getCookingTime() <= maxCookingTime)
        {
            recipe.displayRecipe();
            found = true;
        }
    }

    if (!found)
    {
        cout << "\nNo quick meals found.\n";
    }
}

// Recommend Top Rated Recipes
void RecommendationEngine::recommendTopRated()
{
    vector<Recipe> recipes = recipeManager.getRecipes();

    sort(recipes.begin(),
         recipes.end(),
         [](const Recipe &a, const Recipe &b)
         {
             return a.getRating() > b.getRating();
         });

    cout << "\n========== Top Rated Recipes ==========\n";

    int count = 0;

    for (const Recipe &recipe : recipes)
    {
        recipe.displayRecipe();

        count++;

        if (count == 10)
            break;
    }
}