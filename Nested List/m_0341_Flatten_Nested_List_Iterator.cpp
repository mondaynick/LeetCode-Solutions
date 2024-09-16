/*
  給定一nested list串列，其中每個元素可能是整數也可能是串列並嵌套下去，將其打平
  題目提供的API：isInteger(), getInteger(), getList()
  需要時做的API：constructor, next(), hasNext()

  一般的迭代器求值應該要是惰性的，當要求下一個值的時候再去解套nested list
 */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    stack<NestedInteger> stk;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (vector<NestedInteger>::reverse_iterator ite = nestedList.rbegin() ; ite != nestedList.rend() ; ite++) {
            stk.push(*ite);
        }
    }
    
    int next() {
        if (hasNext()) {
            NestedInteger top = stk.top();
            stk.pop();
            return top.getInteger();
        } else {
            return -1;
        }
    }
    
    bool hasNext() {
        while (!stk.empty()) {
            NestedInteger top = stk.top();
            if (top.isInteger()) {
                return true;
            } else {
                stk.pop();
                vector<NestedInteger> nestedList = top.getList();
                for (vector<NestedInteger>::reverse_iterator ite = nestedList.rbegin() ; ite != nestedList.rend() ; ite++) {
                    stk.push(*ite);
                }
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
