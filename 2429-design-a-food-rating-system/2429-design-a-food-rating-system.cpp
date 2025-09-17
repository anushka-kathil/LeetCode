#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
    unordered_map<string, pair<int, string>> foodMap;
    unordered_map<string, set<pair<int, string>>> cuisineMap;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            foodMap[foods[i]] = {ratings[i], cuisines[i]};
            cuisineMap[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        auto [oldRating, cuisine] = foodMap[food];
        cuisineMap[cuisine].erase({-oldRating, food});
        cuisineMap[cuisine].insert({-newRating, food});
        foodMap[food] = {newRating, cuisine};
    }

    string highestRated(string cuisine) {
        return cuisineMap[cuisine].begin()->second;
    }
};
