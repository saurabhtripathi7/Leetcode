class BrowserHistory {
public:
    class Node{
    public:
        string url;
        Node* prev;
        Node* next;
    
        Node(string u) : url(u), prev(NULL), next(NULL) {}
    };

    Node* curr;
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
                
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode;
        curr->next = NULL;
    }
    
    string back(int steps) {
        while(steps > 0 && curr->prev != NULL){
            curr = curr->prev;
            steps--;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(steps && curr->next){
            curr = curr->next;
            steps--;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
