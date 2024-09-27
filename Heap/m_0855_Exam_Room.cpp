/*
  給定n個座位，設計以下API：
  seat代表規劃一個考生入座，並且該考生須保持和其他學生最大距離，回傳索引，leave代表該考生以完試離開原座位

  每次規劃座位時，取所有區間段最大的中點作為新考生的座位
 */

class ExamRoom {
private:
    int seats;
    set<int> record;
public:
    ExamRoom(int n) {
        seats = n;
    }
    
    int seat() {
        if (record.size() == 0) {
            record.insert(0);
            return 0;
        } else {
            int maxDistance = *record.begin();
            int index = 0;
            set<int>::iterator it1 = record.begin();
            set<int>::iterator it2 = record.begin();
            for (it2++ ; it2 != record.end() ; it1++, it2++) {
                int dist = (*it2 - *it1) / 2;
                if (dist > maxDistance) {
                    maxDistance = dist;
                    index = *it1 + (*it2 - *it1) / 2;
                }
            }
            if ((seats - 1) - *it1 > maxDistance) {
                index = seats - 1;
            }
            record.insert(index);
            return index;
        }
        return 0;
    }
    
    void leave(int p) {
        record.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
