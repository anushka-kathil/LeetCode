struct Node{
    string url;
    Node* prev = nullptr;
    Node* next = nullptr;

    Node(string url1){
        url=url1;
        prev=nullptr;
        next=nullptr;
    }

};


class BrowserHistory {
    Node* current;
public:
    BrowserHistory(string homepage) {
       current = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        newNode->prev= current;
        current->next=newNode;
        current=current->next;
    }


    string back(int steps) {
        while(steps--){
            if(current->prev != nullptr)
            current=current->prev;

            else
            break;
        } 
        return current->url; 
    }
    
    string forward(int steps) {
         while(steps--){
            if(current->next != nullptr)
            current=current->next;

            else
            break;
        } 
        return current->url; 
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */