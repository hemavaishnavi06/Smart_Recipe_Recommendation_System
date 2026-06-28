#ifndef MEALPLANNER_H
#define MEALPLANNER_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

class MealPlanner
{
private:
    map<string, string> mealPlan;

public:

    MealPlanner();

    void addMeal(const string &day, const string &recipeName);

    void updateMeal(const string &day, const string &recipeName);

    void removeMeal(const string &day);

    void displayMealPlan() const;

    void saveMealPlan();

    void loadMealPlan();
};

#endif