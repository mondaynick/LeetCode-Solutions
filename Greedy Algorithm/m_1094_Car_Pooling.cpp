/*
  有一輛共可搭載capacity位乘客的車，這輛車只會往東邊開(不會轉彎也不會往西邊開)，
  給定一個陣列trips，其中trips[i]=[num_passengers, start_loc, end_loc]
    num_passengers：這個接駁處共有幾位乘客
    start_loc：這些乘客的上車地點
    end_loc：這些乘客的下車地點
  若可以成功搭載所有乘客並讓他們都在目的地下車則回傳true，否則回傳false

  先紀錄每站增減的人數，遍歷每站，若該站已客滿則回傳false，反之最後則回傳true
 */

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> arr(1001, 0);
        for (vector<int> ite: trips) {
            arr[ite[1]] += ite[0]; // get on
            arr[ite[2]] -= ite[0]; // get off
        }
        for (int i = 0 ; i < 1001 ; i++) {
            capacity -= arr[i];
            if (capacity < 0) return false;
        }
        return true;
    }
};
