class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int key, int value){
        this->key = key;
        this->value = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class LRUCache {
public:
    int capacity;
    unordered_map<int,Node*>mp;
    Node* head;
    Node* tail;

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
    }

    void insertAtHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = new Node(-1,-1);
        this->tail = new Node(-1,-1);
        mp.clear();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!mp.contains(key)) return -1;
        Node* node = mp[key];
        deleteNode(node);
        insertAtHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(mp.contains(key)) {
            Node* node = mp[key];
            node->value = value;
            deleteNode(node);
            insertAtHead(node);
        }else {
            if(mp.size() == capacity) {
                mp.erase(tail->prev->key);
                deleteNode(tail->prev);
            }
            Node* new_node = new Node(key, value);
            mp[key] = new_node;
            insertAtHead(new_node);
        }
    }
};
