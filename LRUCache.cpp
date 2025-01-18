class LRUCache {
public:
    struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v):key(k), val(v), prev(nullptr), next(nullptr){}
    };
    unordered_map<int, Node*>mpp;
    int capacity=0;
    Node* head;
    Node* tail;
    LRUCache(int cap) {
        capacity=cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next=tail;
        tail->prev=head;
    }
    void deleteNode(Node* node){
        Node* prevNode=node->prev;
        Node* afterNode=node->next;
        prevNode->next=afterNode;
        afterNode->prev=prevNode;
    }
    void insertAfterHead(Node* node){
        Node* currafterHead=head->next;
        head->next=node;
        node->next=currafterHead;
        node->prev=head;
        currafterHead->prev = node;
    }
    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        int val=mpp[key]->val;
        Node* node=mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            node->val=value;
            deleteNode(node);
            insertAfterHead(node);
        } else{
            if(mpp.size()==capacity){
                Node* node=tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
                delete(node);
            }
            Node* node=new Node(key, value);
            mpp[key]=node;
            insertAfterHead(node);
        }
        
    }
    //  ~LRUCache() { 
    //     Node* current = head;
    //     while (current != nullptr) {
    //         Node* next = current->next;
    //         delete current;
    //         current = next;
    //     }
    // }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
