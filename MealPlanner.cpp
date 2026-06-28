#include "MealPlanner.h"

#include <fstream>

using namespace std;

// Constructor
MealPlanner::MealPlanner()
{
    loadMealPlan();
}

// Add Meal
void MealPlanner::addMeal(const string &day,
                          const string &recipeName)
{
    mealPlan[day] = recipeName;

    saveMealPlan();

    cout << "\nMeal added successfully.\n";
}

// Update Meal
void MealPlanner::updateMeal(const string &day,
                             const string &recipeName)
{
    auto it = mealPlan.find(day);

    if(it == mealPlan.end())
    {
        cout << "\nNo meal found for " << day << ".\n";
        return;
    }

    mealPlan[day] = recipeName;

    saveMealPlan();

    cout << "\nMeal updated successfully.\n";
}

// Remove Meal
void MealPlanner::removeMeal(const string &day)
{
    auto it = mealPlan.find(day);

    if(it == mealPlan.end())
    {
        cout << "\nNo meal found.\n";
        return;
    }

    mealPlan.erase(it);

    saveMealPlan();

    cout << "\nMeal removed successfully.\n";
}

// Display Meal Plan
void MealPlanner::displayMealPlan() const
{
    if(mealPlan.empty())
    {
        cout << "\nMeal Planner is empty.\n";
        return;
    }

    cout << "\n========== WEEKLY MEAL PLAN ==========\n";

    for(const auto &meal : mealPlan)
    {
        cout << meal.first
             << " : "
             << meal.second
             << endl;
    }
}

// Save Meal Plan
void MealPlanner::saveMealPlan()
{
    ofstream file("mealplanner.csv");

    if(!file.is_open())
    {
        cout << "\nUnable to save meal planner.\n";
        return;
    }

    file << "Day,Recipe\n";

    for(const auto &meal : mealPlan)
    {
        file << meal.first
             << ","
             << meal.second
             << "\n";
    }

    file.close();
}

// Load Meal Plan
void MealPlanner::loadMealPlan()
{
    mealPlan.clear();

    ifstream file("mealplanner.csv");

    if(!file.is_open())
        return;

    string line;

    getline(file, line);

    while(getline(file, line))
    {
        if(line.empty())
            continue;

        size_t pos = line.find(',');

        if(pos == string::npos)
            continue;

        string day = line.substr(0, pos);

        string recipe = line.substr(pos + 1);

        mealPlan[day] = recipe;
    }

    file.close();
}