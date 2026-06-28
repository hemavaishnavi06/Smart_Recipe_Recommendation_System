#ifndef RECOMMENDATIONENGINE_H
#define RECOMMENDATIONENGINE_H

#include <iostream>
#include <vector>
#include <string>

#include "Recipe.h"
#include "RecipeManager.h"

using namespace std;

class RecommendationEngine
{
private:
    RecipeManager &recipeManager;

public:
    // Constructor
    RecommendationEngine(RecipeManager &manager);

    // Recommendation Functions
    void recommendByIngredients(const vector<string> &ingredients);
    void recommendByCategory(const string &category);
    void recommendByDiet(const string &diet);
    void recommendQuickMeals(int maxCookingTime);
    void recommendTopRated();

    // Utility
    int calculateMatchScore(
        const Recipe &recipe,
        const vector<string> &ingredients) const;
};

#endif