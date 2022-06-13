class LRUCache {
public:
    
    class Node{
        public:
            int val;
            int key;
            Node* prev;
            Node* next;
        
        Node(int v,int k){
            val = v;
            key = k;
        }
    };
    
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    
    
    int cap;
    unordered_map<int,Node*> mp;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    
    void addNode(Node* newNode){
        Node* next  = head->next;
        head->next = newNode;
        newNode->next = next;
        newNode->prev = head;
        next->prev = newNode;
    }
    
    
    void deleteNode(Node* delNode){
        Node* prev = delNode->prev;
        Node* next = delNode->next;
        
        prev->next = next;
        next->prev = prev;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* resNode = mp[key];
            int res = resNode->val;
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* existNode = mp[key];
            mp.erase(key);
            deleteNode(existNode);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(value,key));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
