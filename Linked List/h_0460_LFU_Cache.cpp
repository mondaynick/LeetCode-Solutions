/*
  設計一個採用LRU(Least Recently Used)策略的快取，其中提供三個API，分別是實例化、getter和setter

  利用Hash Table加上Linked List，詳細說明在以下程式碼註解
 */

class DoublyLinkedNode {
public:
    int key, val;
    DoublyLinkedNode *prev, *next;
    DoublyLinkedNode (int key, int val) {
        this->key = key;
        this->val = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    DoublyLinkedNode *head, *tail;
    int size;
public:
    DoublyLinkedList() {
        this->head = new DoublyLinkedNode(0, 0);
        this->tail = new DoublyLinkedNode(0, 0);
        this->head->next = this->tail;
        this->tail->prev = this->head;
        this->size = 0;
    }

    void addLast(DoublyLinkedNode* node) {
        node->prev = this->tail->prev;
        node->next = this->tail;
        this->tail->prev->next = node;
        this->tail->prev = node;
        this->size++;
    }

    void remove(DoublyLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        this->size--;
    }

    DoublyLinkedNode* removeFirst() {
        if (this->head->next == this->tail) return nullptr;

        DoublyLinkedNode* node = this->head->next;
        remove(node);
        return node;
    }

    int getSize() {
        return this->size;
    }
};

class LFUCache {
private:
    int usedSize, capacity, minFreq;
    unordered_map<int, DoublyLinkedList*> cache;
    unordered_map<int, int> keyToFreq;
    unordered_map<int, DoublyLinkedNode*> keyToNode;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
        this->usedSize = 0;
    }
    
    int get(int key) {
        if (!this->keyToNode.count(key)) return -1;

        // Find where is the node
        DoublyLinkedNode* node = this->keyToNode[key];
        int freq = this->keyToFreq[key];

        // Delete in linked list of old frequency
        DoublyLinkedList* list = this->cache[this->keyToFreq[key]];
        list->remove(node);

        // Check the minimum frequency
        if (list->getSize() == 0 && freq == this->minFreq) this->minFreq++;

        // Put in linked list of new frequency
        freq++;
        if (!this->cache.count(freq)) this->cache[freq] = new DoublyLinkedList();
        this->cache[freq]->addLast(node);

        // Update mapping table
        this->keyToFreq[key] = freq;

        return node->val;
    }
    
    void put(int key, int value) {

        // If the node exists
        if (keyToNode.count(key)) {

            // Find where is the node
            DoublyLinkedNode* node = this->keyToNode[key];
            int freq = this->keyToFreq[key];

            // Update its value
            node->val = value;

            // Delete in linked list of old frequency
            DoublyLinkedList* list = this->cache[this->keyToFreq[key]];
            list->remove(node);

            // Check the minimum frequency
            if (list->getSize() == 0 && freq == this->minFreq) this->minFreq++;
            // Put in linked list of new frequency
            freq++;
            if (!this->cache.count(freq)) this->cache[freq] = new DoublyLinkedList();
            this->cache[freq]->addLast(node);

            // Update mapping table
            this->keyToFreq[key] = freq;
            return;
        }

        // Check whether the cache is full
        if (this->usedSize == this->capacity) { // if full then delete the node of minimum frequency

            // Delete in linked list of old frequency
            DoublyLinkedNode* node = this->cache[this->minFreq]->removeFirst();

            // Update mapping table
            this->keyToNode.erase(node->key);
            this->keyToFreq.erase(node->key);
        }

        // Insert a new node into linked list
        DoublyLinkedNode* node = new DoublyLinkedNode(key, value);
        if (!this->cache.count(1)) this->cache[1] = new DoublyLinkedList();
        this->cache[1]->addLast(node);
        this->minFreq = 1;
        if (this->usedSize != this->capacity) this->usedSize++;

        // Update mapping table
        this->keyToNode[key] = node;
        this->keyToFreq[key] = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
