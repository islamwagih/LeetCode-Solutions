//only using STLs
class LRUCache
{
    map<int, int> timeToKey; //time -> key
    unordered_map<int, int> keyToTime; //key -> time
    unordered_map<int, int> cache; //key -> value
    int cap, time;
public:
    LRUCache(int capacity)
    {
        cap = capacity;
        time = 1;
    }

    int get(int key)
    {
        auto it = cache.find(key);
        if(it == cache.end())
        {
            return -1;
        }
        int oldTime = keyToTime[key];
        keyToTime[key] = time;
        timeToKey.erase(oldTime);
        timeToKey[time++] = key;
        return it->second;
    }
    
    void put(int key, int value)
    {
        if(cache.find(key) != cache.end())
        {
            //key already exit upate times and exit
            int oldTime = keyToTime[key];
            timeToKey.erase(oldTime);
        }else if(cache.size() == cap){
            //delete a victim
            auto it = timeToKey.begin();
            int leastTime = it->first, keyOfIt = it->second;
            timeToKey.erase(leastTime);
            keyToTime.erase(keyOfIt);
            cache.erase(keyOfIt);
        }
        cache[key] = value;
        keyToTime[key] = time;
        timeToKey[time++] = key;
    }
};

/*
class LRUCache
{
    class Node
    {
    public:
        int key, value;
        Node* nxt = nullptr;
        Node* prv = nullptr;
        Node(int key=-1, int value=-1):key(key), value(value){}
    };
    //LRU will always be the left->nxt node and MRU will always be right->prv
    int cap;
    unordered_map<int, Node*> cache; //key to pointer to value in linked list
    Node* left;
    Node* right;

    void remove(Node* curr)
    {
        if(curr == nullptr) return;
        // p -> C -> N
        // O -> O -> O
        Node* prv = curr->prv;
        Node* nxt = curr->nxt;
        if(prv != nullptr) prv->nxt = curr->nxt;
        if(nxt != nullptr) nxt->prv = curr->prv;
        cache.erase(curr->key);
    }

    void insert(Node* curr)
    {
        // P -> N ===> P -> C -> N
        Node* prv = right->prv;
        curr->nxt = right;
        curr->prv = prv;
        if(prv != nullptr) prv->nxt = curr;
        right->prv = curr;
    }

public:

    LRUCache(int _capacity)
    {
        this->cap = _capacity;
        left = new Node();
        right = new Node();
        left->nxt = right;
        right->prv = left;
    }

    int get(int key)
    {
        if(cache.find(key) != cache.end()) //key in cahce
        {
            //make it LRU;
            Node* curr = cache[key];
            remove(curr);
            insert(curr);
            return curr->value;
        }
        return -1;
    }
    
    void put(int key, int value)
    {
        if(cache.find(key) != cache.end()) //key in cahce
        {
            //make it LRU;
            Node* curr = cache[key];
            remove(curr);
            curr->value = value;
            insert(curr);
        }else
        {
            Node* node = new Node(key, value);
            cache[key] = node;
            insert(node);
            if(cache.size() > cap)
            {
                Node* lru = left->nxt;
                remove(lru);
                if(lru != nullptr) cache.erase(lru->key);
            }
        }
    }
};
*/
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
