/*
  給定一個整數陣列 nums ，設計以下函式 sumRange(left, right) ，回傳陣列 nums 索引從 left 到 right 的和

  Segment tree設計如下：
    (1) 建構式 NumArray(vector<int>& nums)
          創建一個新的陣列 nodes 且其長度為原 nums 陣列長度的兩倍，並記錄 offset 等於原先 nums 陣列的長度，
          將原先陣列 nums 的數值放置nodes 的後半部，並更新前半部為計算的和，如下：
                            19
                    /                \
                  11                  8
               /      \           /      \
              6         5       12        -4
            /  \      /  \     /  \      /  \
           5     1   3     2  8     4   1    -5
    (2) 範圍求和 sumRange(int left, int right)
          如果我們查找的範圍會涵蓋完整區間則往上找區間值，反之則取得當下的值並往下一個區間邁進，分為以下四種情況
            1. left 指向偶數：要取出整個區間
            2. left 指向奇數：直接取值
            3. right 指向偶數：直接取值
            4. right 指向奇數：要取出整個區間
    (3) 修改陣列 updata(int index, int val)
          更新時要更新所有的 parent
 */

class NumArray {
public:
    NumArray(vector<int>& nums) {
        offset = nums.size();
        nodes.resize(offset * 2, 0);
        for (int i = 0; i < offset; ++i) {
            nodes[i + offset] = nums[i];
        }
        for (int i = offset - 1; i > 0; --i) {
            nodes[i] = nodes[i * 2] + nodes[i * 2 + 1];
        }
    }
    
    void update(int index, int val) {
        index += offset;
        int diff = val - nodes[index];
        while (index > 0) {
            nodes[index] += diff;
            index /= 2;
        }
    }
    
    int sumRange(int left, int right) {
        int count = 0;
        left += offset;
        right += offset;
        while (left <= right) {
            if ((left & 1) == 1) {
                count += nodes[left];
                ++left;
            }
            if ((right & 1) == 0) {
                count += nodes[right];
                --right;
            }
            left /= 2;
            right /= 2;
        }
        return count;
    }
private:
    int offset;
    vector<int> nodes;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
