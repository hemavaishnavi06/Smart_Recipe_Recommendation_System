#include <iostream>
#include <vector>
#include <string>

#include "RecipeManager.h"
#include "RecommendationEngine.h"
#include "MealPlanner.h"
#include "UserManager.h"

using namespace std;

int main()
{
    RecipeManager recipeManager;
    RecommendationEngine recommender(recipeManager);
    MealPlanner mealPlanner;
    UserManager userManager;

    while (true)
    {
        int choice;

        cout << "\n=====================================================\n";
        cout << "      SMART RECIPE RECOMMENDATION SYSTEM\n";
        cout << "=====================================================\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Display Registered Users\n";
        cout << "0. Exit\n";
        cout << "=====================================================\n";

        cout << "Enter Choice : ";
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
            case 1:
            {
                userManager.registerUser();
                break;
            }

            case 2:
            {
                if(!userManager.loginUser())
                    break;

                User *currentUser = userManager.getCurrentUser();

                bool loggedIn = true;

                while(loggedIn)
                {
                    int dashboardChoice;

                    cout << "\n=====================================================\n";
                    cout << "Welcome "
                         << currentUser->getUsername()
                         << endl;
                    cout << "=====================================================\n";

                    cout << "1. Recipe Management\n";
                    cout << "2. Recommendation Engine\n";
                    cout << "3. Meal Planner\n";
                    cout << "4. Favourite Recipes\n";
                    cout << "5. Meal History\n";
                    cout << "6. Logout\n";

                    cout << "\nEnter Choice : ";

                    cin >> dashboardChoice;

                    cin.ignore();

                    switch(dashboardChoice)
                    {
                        case 1:
{
    bool recipeMenu = true;

    while (recipeMenu)
    {
        int recipeChoice;

        cout << "\n=========================================\n";
        cout << "        RECIPE MANAGEMENT MENU\n";
        cout << "=========================================\n";
        cout << "1. Display All Recipes\n";
        cout << "2. Add Recipe\n";
        cout << "3. Delete Recipe\n";
        cout << "4. Update Recipe\n";
        cout << "5. Search By Name\n";
        cout << "6. Search By Ingredient\n";
        cout << "7. Search By Category\n";
        cout << "8. Search By Diet\n";
        cout << "9. Search By Cooking Time\n";
        cout << "0. Back\n";

        cout << "\nEnter Choice : ";
        cin >> recipeChoice;
        cin.ignore();

        switch (recipeChoice)
        {
            case 1:
            {
                recipeManager.displayAllRecipes();
                break;
            }

            case 2:
            {
                recipeManager.addRecipe();
                break;
            }

            case 3:
            {
                int id;

                cout << "Enter Recipe ID : ";
                cin >> id;

                recipeManager.deleteRecipe(id);

                break;
            }

            case 4:
            {
                int id;

                cout << "Enter Recipe ID : ";
                cin >> id;

                recipeManager.updateRecipe(id);

                break;
            }

            case 5:
            {
                string name;

                cin.ignore();

                cout << "Recipe Name : ";
                getline(cin, name);

                recipeManager.searchByName(name);

                break;
            }

            case 6:
            {
                string ingredient;

                cout << "Ingredient : ";
                getline(cin, ingredient);

                recipeManager.searchByIngredient(ingredient);

                break;
            }

            case 7:
            {
                string category;

                cout << "Category : ";
                getline(cin, category);

                recipeManager.searchByCategory(category);

                break;
            }

            case 8:
            {
                string diet;

                cout << "Diet Type : ";
                getline(cin, diet);

                recipeManager.searchByDiet(diet);

                break;
            }

            case 9:
            {
                int time;

                cout << "Maximum Cooking Time : ";
                cin >> time;

                recipeManager.searchByCookingTime(time);

                break;
            }

            case 0:
            {
                recipeMenu = false;
                break;
            }

            default:
            {
                cout << "\nInvalid Choice.\n";
            }
        }
    }

    break;
}

case 2:
{
    bool recommendationMenu = true;

    while (recommendationMenu)
    {
        int recommendationChoice;

        cout << "\n=========================================\n";
        cout << "       RECOMMENDATION ENGINE MENU\n";
        cout << "=========================================\n";
        cout << "1. Recommend By Ingredients\n";
        cout << "2. Recommend By Category\n";
        cout << "3. Recommend By Diet\n";
        cout << "4. Quick Meals\n";
        cout << "5. Top Rated Recipes\n";
        cout << "0. Back\n";

        cout << "\nEnter Choice : ";
        cin >> recommendationChoice;
        cin.ignore();

        switch (recommendationChoice)
        {
            case 1:
            {
                int count;

                cout << "Enter Number of Ingredients : ";
                cin >> count;
                cin.ignore();

                vector<string> ingredients;

                for (int i = 0; i < count; i++)
                {
                    string ingredient;

                    cout << "Ingredient " << i + 1 << " : ";
                    getline(cin, ingredient);

                    ingredients.push_back(ingredient);
                }

                recommender.recommendByIngredients(ingredients);

                break;
            }

            case 2:
            {
                string category;

                cout << "Enter Category : ";
                getline(cin, category);

                recommender.recommendByCategory(category);

                break;
            }

            case 3:
            {
                string diet;

                cout << "Enter Diet Type : ";
                getline(cin, diet);

                recommender.recommendByDiet(diet);

                break;
            }

            case 4:
            {
                int time;

                cout << "Enter Maximum Cooking Time : ";
                cin >> time;

                recommender.recommendQuickMeals(time);

                break;
            }

            case 5:
            {
                recommender.recommendTopRated();

                break;
            }

            case 0:
            {
                recommendationMenu = false;
                break;
            }

            default:
            {
                cout << "\nInvalid Choice.\n";
            }
        }
    }

    break;
}

case 3:
{
    bool mealPlannerMenu = true;

    while (mealPlannerMenu)
    {
        int plannerChoice;

        cout << "\n=========================================\n";
        cout << "            MEAL PLANNER MENU\n";
        cout << "=========================================\n";
        cout << "1. Add Meal\n";
        cout << "2. Update Meal\n";
        cout << "3. Remove Meal\n";
        cout << "4. Display Meal Plan\n";
        cout << "5. Add Recipe To Favourites\n";
        cout << "6. Remove Recipe From Favourites\n";
        cout << "7. Add Recipe To Meal History\n";
        cout << "0. Back\n";

        cout << "\nEnter Choice : ";
        cin >> plannerChoice;
        cin.ignore();

        switch(plannerChoice)
        {
            case 1:
            {
                string day;
                string recipe;

                cout << "Day : ";
                getline(cin, day);

                cout << "Recipe Name : ";
                getline(cin, recipe);

                mealPlanner.addMeal(day, recipe);

                break;
            }

            case 2:
            {
                string day;
                string recipe;

                cout << "Day : ";
                getline(cin, day);

                cout << "New Recipe Name : ";
                getline(cin, recipe);

                mealPlanner.updateMeal(day, recipe);

                break;
            }

            case 3:
            {
                string day;

                cout << "Day : ";
                getline(cin, day);

                mealPlanner.removeMeal(day);

                break;
            }

            case 4:
            {
                mealPlanner.displayMealPlan();

                break;
            }

            case 5:
            {
                int recipeID;

                cout << "Recipe ID : ";
                cin >> recipeID;

                currentUser->addFavorite(recipeID);

                break;
            }

            case 6:
            {
                int recipeID;

                cout << "Recipe ID : ";
                cin >> recipeID;

                currentUser->removeFavorite(recipeID);

                break;
            }

            case 7:
            {
                int recipeID;

                cout << "Recipe ID : ";
                cin >> recipeID;

                currentUser->addMealHistory(recipeID);

                break;
            }

            case 0:
            {
                mealPlannerMenu = false;
                break;
            }

            default:
            {
                cout << "\nInvalid Choice.\n";
            }
        }
    }

    break;
}
                        case 4:
                        {
                            currentUser->displayFavorites();
                            break;
                        }

                        case 5:
                        {
                            currentUser->displayMealHistory();
                            break;
                        }

                        case 6:
                        {
                            loggedIn = false;
                            cout << "\nLogged Out Successfully.\n";
                            break;
                        }

                        default:
                        {
                            cout << "\nInvalid Choice.\n";
                        }
                    }
                }

                break;
            }

            case 3:
            {
                userManager.displayAllUsers();
                break;
            }

            case 0:
            {
                cout << "\nThank You for using the system.\n";
                return 0;
            }

            default:
            {
                cout << "\nInvalid Choice.\n";
            }
        }
    }

    return 0;
}