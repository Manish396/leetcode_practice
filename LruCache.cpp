class LRUCache {
public:
    list<int> dll;
    unordered_map<int, pair<list<int>::iterator, int>> A;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    void shift(int key)
    {
        dll.erase(A[key].first);
        dll.push_front(key);
        A[key].first = dll.begin();
    }
    
    int get(int key) {
        if(A.find(key)==A.end())
            return -1;
        shift(key);
        return A[key].second;
    }
    
    void put(int key, int value) {
        if(A.find(key)!=A.end())
        {
            shift(key);
            A[key].second = value;
        }
        else
        {
            dll.push_front(key);
            A[key].first = dll.begin();
            A[key].second = value;
            cap--;
        }
        if(cap < 0)
        {
            A.erase(dll.back());
            dll.pop_back();
            cap++;
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
