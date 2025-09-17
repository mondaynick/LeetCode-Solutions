/*
  設計一個食物評價系統，給定三個函式：
    (1) 建構式 FoodRatings 中給定三個陣列 foods 、 cuisines 和 ratings ，其中food[i] 、 cuisine[i]
        和 rating[i] 分別代表第 i 個食物的名稱、類別和評分，並將其加入食物評價系統中
    (2) changeRatings 中給定字串 food 和整數 newRating ，將食物系統中 food 的評分調整成 newRating
    (3) highestRated 中給定字串 cuisine ，回傳類別 cuisine 中評分最高的食物

  利用 sort
 */

class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int len = foods.size();
        for (int i = 0; i < len; ++i) {
            highRated[cuisines[i]].insert({-ratings[i], foods[i]});
            cuisineMp[foods[i]] = {-ratings[i], cuisines[i]};
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = cuisineMp[food].second;
        int prevRating = cuisineMp[food].first;
        highRated[cuisine].erase({prevRating, food});
        highRated[cuisine].insert({-newRating, food});
        cuisineMp[food] = {-newRating, cuisine};
    }
    
    string highestRated(string cuisine) {
        return highRated[cuisine].begin()->second;
    }

private:
    unordered_map<string, set<pair<int, string>>> highRated; // cuisine -> (rating, food)
    unordered_map<string, pair<int, string>> cuisineMp; // food -> (rating, cuisine)
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
