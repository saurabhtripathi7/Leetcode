



class LRUCache {
public:

    class Node{
    public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int key1, int val1){
        key = key1;
        val = val1;
    }
};
    void insertAfterHead(Node* node){
        Node* currAfterHead = head->next;
        head->next = node;
        node->next = currAfterHead;
        node->prev = head;
        currAfterHead->prev = node;
        
    }

    void deleteNode(Node* node){
        if (!node) return;  // Edge case: if node is nullptr
        Node* prevNode = node->prev;
        Node* afterNode = node->next;
        if (prevNode != nullptr) prevNode->next = afterNode;  // If it's not head
        if (afterNode != nullptr) afterNode->prev = prevNode;  // If it's not tail
    }


    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*>mpp;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        mpp.clear();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key) != mpp.end()){ //if found returs its value
        Node* node = mpp[key];
        // since we've touched this node, we have to put it after head
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
        }
        return -1; //else return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()) //if found update its value and shift it next to head
        {
            Node* node = mpp[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else{
            if(mpp.size() == cap){
                Node* node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }
            Node* node = new Node(key, value);
            mpp[key] = node;
            insertAfterHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
