/*
  給定一陣列，每次只能翻轉前幾項元素，其陣列該如何翻轉才能從小排到大

  在前n塊中找到最大塊的將其放到最下面，再遞迴解決前n - 1塊，當只有1塊時則不用翻轉
  在前n塊中找到最大塊的鬆餅索引k時，先翻轉前k塊把最大的鬆餅移來最上面，在翻轉全部共n塊鬆餅把最大的鬆餅移來最下面
 */

class Solution {
public:
    void rev(vector<int>& arr, int start, int end) {
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

    void handler(vector<int>& res, vector<int>& arr, int size) {
        if (size == 1) return;

        int maxCake = 0;
        int maxIndex = 0;
        for (int i = 0 ; i < size ; i++) {
            if (arr[i] > maxCake) {
                maxCake = arr[i];
                maxIndex = i;
            }
        }
        rev(arr, 0, maxIndex);
        res.push_back(maxIndex + 1);
        rev(arr, 0, size - 1);
        res.push_back(size);
        handler(res, arr, size - 1);
    }

    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        handler(res, arr, arr.size());
        return res;
    }
};
