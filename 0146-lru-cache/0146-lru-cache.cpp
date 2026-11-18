

class LRUCache {
    class Node {
    public:
        int key, val;
        Node* next;
        Node* prev;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
            next = NULL;
            prev = NULL;
        }
    };

    Node* head;
    Node* tail;
    int cap;
    unordered_map<int, Node*> mpp;

    void addNode(Node* newnode) {
        newnode->next = head->next;
        newnode->prev = head;
        head->next->prev = newnode;
        head->next = newnode;
    }

    void deleteNode(Node* delnode) {
        delnode->prev->next = delnode->next;
        delnode->next->prev = delnode->prev;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key_) {
        if (mpp.find(key_) != mpp.end()) {
            Node* resNode = mpp[key_];
            int res = resNode->val;
            
            deleteNode(resNode);
            addNode(resNode);
            
            mpp[key_] = head->next; // points to the new head
            return res;
        }
        return -1;
    }

    void put(int key_, int value) {
        if (mpp.find(key_) != mpp.end()) {
            Node* existingNode = mpp[key_];
            mpp.erase(key_);
            deleteNode(existingNode);
        }
        
        if (mpp.size() == cap) {
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        addNode(new Node(key_, value));
        
        mpp[key_] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */