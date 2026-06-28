# 🍽️ Smart Recipe Recommendation System

A console-based **Smart Recipe Recommendation System** developed in **C++** using **Object-Oriented Programming (OOP)**, **Standard Template Library (STL)**, and **CSV-based file handling**. The application recommends recipes based on ingredients, dietary preferences, cooking time, and meal categories while providing user authentication, recipe management, and meal planning features.

---

## 📖 Overview

This project helps users discover suitable recipes based on their available ingredients and preferences. It also allows users to manage recipes, create weekly meal plans, maintain favourite recipes, and track meal history.

The project follows a modular OOP architecture with separate classes for recipe management, user management, recommendation logic, and meal planning.

---

## ✨ Features

### 👤 User Management

* User Registration
* User Login
* Display Registered Users
* CSV-based User Storage

### 🍲 Recipe Management

* Add Recipe
* Update Recipe
* Delete Recipe
* Display All Recipes
* Search by Recipe Name
* Search by Ingredient
* Search by Category
* Search by Diet Type
* Search by Cooking Time

### ⭐ Recommendation Engine

* Recommend Recipes by Ingredients
* Recommend Recipes by Category
* Recommend Recipes by Diet
* Recommend Quick Meals
* Recommend Top Rated Recipes
* Ingredient Match Scoring

### 📅 Meal Planner

* Add Weekly Meal Plan
* Update Meal Plan
* Remove Meal Plan
* Display Weekly Meal Plan

### ❤️ User Features

* Favourite Recipes
* Meal History

### 💾 Data Storage

* Recipes stored in CSV
* Users stored in CSV
* Meal Planner stored in CSV

---

## 🛠 Technologies Used

* C++
* Object-Oriented Programming (OOP)
* Standard Template Library (STL)
* File Handling
* CSV Files
* Visual Studio Code
* Git
* GitHub

---

## 📂 Project Structure

```text
Smart-Recipe-Recommendation-System/
│
├── include/
│   ├── Recipe.h
│   ├── RecipeManager.h
│   ├── RecommendationEngine.h
│   ├── MealPlanner.h
│   ├── User.h
│   └── UserManager.h
│
├── src/
│   ├── main.cpp
│   ├── Recipe.cpp
│   ├── RecipeManager.cpp
│   ├── RecommendationEngine.cpp
│   ├── MealPlanner.cpp
│   ├── User.cpp
│   └── UserManager.cpp
│
├── data/
│   ├── recipes.csv
│   ├── users.csv
│   └── mealplanner.csv
│
├── screenshots/
│
├── README.md
├── LICENSE
└── .gitignore
```

---

## 🧩 Modules

* Recipe
* Recipe Manager
* User
* User Manager
* Recommendation Engine
* Meal Planner

---

## 🧠 Recommendation Algorithm

The recommendation engine ranks recipes using a custom scoring mechanism based on:

* Ingredient Match Score
* Recipe Rating
* Cooking Time

Recipes with higher scores are displayed first, providing personalized recommendations to the user.

---

## 🚀 How to Compile

```bash
g++ main.cpp Recipe.cpp RecipeManager.cpp User.cpp UserManager.cpp RecommendationEngine.cpp MealPlanner.cpp -o recipe
```

## ▶️ Run

Windows:

```bash
recipe.exe
```

Linux/macOS:

```bash
./recipe
```

---

## 📸 Screenshots

Add screenshots of the application in the `screenshots` folder.

Example:

* Main Menu
* User Login
* Recipe Management
* Recommendation Engine
* Meal Planner

---

## 🔮 Future Improvements

* GUI Version
* Web-Based Version
* AI-powered Recipe Recommendation
* Nutritional Analysis
* Recipe Images
* Database Integration (MySQL/PostgreSQL)
* User Profile Management

---

## 🎯 Learning Outcomes

This project demonstrates:

* Object-Oriented Programming
* Modular Software Design
* File Handling
* CSV Data Management
* STL Containers (`vector`, `map`)
* Searching Algorithms
* Sorting Algorithms
* User Authentication
* Recommendation System Design

---

## 👩‍💻 Author

**Vaishnavi**

B.Tech – Electronics and Communication Engineering

Interested in Software Development, Data Structures & Algorithms, and VLSI Design.

---

## 📄 License

This project is intended for educational and learning purposes.
