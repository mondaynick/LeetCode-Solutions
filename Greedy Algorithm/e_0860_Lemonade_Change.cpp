/*
  有個賣檸檬水的攤位，每杯檸檬水賣5元，有一些顧客排隊來買，而他們每次只會點一杯，
  每個顧客點了他們的一杯檸檬水後，會用一枚面額5元、10元或20元的硬幣來結帳，你必須
  正確找零，使得找零後的結果是每個顧客總共只付你5元，假設剛開始無任何硬幣，若從頭
  到尾都可以正確找零回傳true，反之則回傳fale

  假設coin為遍歷到此處客人給予的硬幣面額，紀錄5元和10元硬幣的數量(初始為0)：
  (1) 若coin為5元，則5元硬幣加1
  (2) 若coin為10元且目前有5元硬幣，找他一枚5元，5元硬幣減1，反之則回傳false
  (3) 若coin為20元且目前有5元和10元硬幣，因為5元比較珍貴，找他一枚5元硬幣和一枚10
      元硬幣，5元硬幣和10元硬幣各減1，若10元硬幣不夠但5元硬幣超過3枚，也可以找他三
      枚5元硬幣，5元硬幣減3，反之則回傳false
  成功遍歷完最後一個，回傳true
 */

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        for (int coin: bills) {
            if (coin == 5) {
                five++;
            } else if (coin == 10) {
                if (five) {
                    five--;
                    ten++;
                } else {
                    return false;
                }
            } else if (coin == 20) {
                if (ten && five) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
