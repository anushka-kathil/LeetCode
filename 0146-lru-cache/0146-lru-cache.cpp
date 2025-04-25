struct Node{
    int val,key;
    Node* next;
    Node* prev;
    Node(int key1,int val1){
        val=val1;
        key=key1;
        next = nullptr;
        prev = nullptr;;
    }
};

// public:
// Node* insertionAfterHead(Node* node){
    
// }

class LRUCache {
    unordered_map<int, Node*> mpp;
    int cap;
    Node* head; 
    Node* tail; 
    void deleteNode(Node* temp){
        // tail->prev = temp->prev;
        // temp->prev->next=tail;
        // temp->next=nullptr;
        // temp->prev=nullptr;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->next = nullptr;
    temp->prev = nullptr;
    }

    void insertAfterHead(Node* temp){
        Node* temp1=head->next;
        head->next=temp;
        temp->prev=head;
        temp->next=temp1;
        temp1->prev=temp;

    }
    
public:
    LRUCache(int capacity) {
        cap=capacity;
        mpp.clear();
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;

        Node* node=mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val; 
        // Node  
    }
    
    void put(int key, int value) {
        // Node* temp = new Node(key,value);
        if(mpp.find(key) != mpp.end()){
            Node* temp=mpp[key];
            deleteNode(temp);
            // insertAfterHead(mpp[key])
            mpp.erase(key);
        }

        if(mpp.size() == cap){
            Node* lru=tail->prev;
            deleteNode(lru);
            mpp.erase(lru->key);
        }

        Node* newNode= new Node(key,value);
        insertAfterHead(newNode);
        mpp[key]=newNode;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */