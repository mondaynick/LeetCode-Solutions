/*
  設計一個採用LRU(Least Recently Used)策略的快取，其中提供三個API，分別是實例化、getter和setter

  利用雜湊表加上雙向鏈結串列，以下先介紹getter：
    若雜湊表不存在該key，則回傳-1，
    否則回傳該key的value並將其移動到linked list最後端(假設越後端代表越常使用)
  以下介紹setter：
    若雜湊表存在，則將該key的value改寫並將其移動到linked list最後端
    若雜湊表不存在，若快取又已滿，將linked list最前端移除，最後新增節點至linked list最後端
 */

class DoublyLinkedNode {
public:
    int key, val;
    DoublyLinkedNode *prev = nullptr, *next = nullptr;
    DoublyLinkedNode(int k, int v): key(k), val(v) {}
};

class DoublyLinkedList {
private:
    DoublyLinkedNode *head = nullptr, *tail = nullptr;
    int size;
public:
    DoublyLinkedList() {
        head = new DoublyLinkedNode(0, 0);
        tail = new DoublyLinkedNode(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addLast(DoublyLinkedNode* node) {
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
        size++;
    }

    void remove(DoublyLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }

    DoublyLinkedNode* removeFirst() {
        if (head->next == tail) return nullptr;
        DoublyLinkedNode* delNode = head->next;
        remove(delNode);
        return delNode;
    }

    int getSize() {
        return size;
    }
};

class LRUCache {
private:
    unordered_map<int, DoublyLinkedNode*> dict;
    DoublyLinkedList* cache = nullptr;
    int capacity;
public:
    LRUCache(int capacity): capacity(capacity) {
        cache = new DoublyLinkedList();
    }
    
    int get(int key) {
        if (!dict.count(key)) return -1;
        
        DoublyLinkedNode* node = dict[key];
        cache->remove(node);
        cache->addLast(node);
        return dict[key]->val;
    }
    
    void put(int key, int value) {
        if (dict.count(key)) {
            DoublyLinkedNode* node = dict[key];
            cache->remove(node);
            node->val = value;
            cache->addLast(node);
            return;
        }
        if (cache->getSize() == capacity) {
            DoublyLinkedNode* node = cache->removeFirst();
            dict.erase(node->key);
        }
        DoublyLinkedNode* newNode = new DoublyLinkedNode(key, value);
        cache->addLast(newNode);
        dict[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
