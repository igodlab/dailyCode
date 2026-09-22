class Node {
public: 
    int val;
    Node* next;
    
    Node(int val) : val(val), next(nullptr) {}
    Node(int val, Node* next) : val(val), next(next) {}
};

class LinkedList {
private: 
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = new Node(-1);
        tail = head;
    }

    int get(int index) {
        Node* current = head->next;
        int i = 0;
        while (current != nullptr) {
            if (i == index) {
                return current->val;
            }
            ++i;
            current = current->next;
        }
        return -1;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head->next;
        head->next = newNode;
        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }
    
    void insertTail(int val) {
        Node* newNode = new Node(val);
        tail->next = newNode;
        tail = tail->next;
    }

    bool remove(int index) {
        if (head == nullptr || index < 0) return false;

        Node* current = head;
        int i = 0;
        while (i < index && current != nullptr) {
            ++i;
            current = current->next;
        }

        if (current != nullptr && current->next != nullptr) {
            if (current->next == tail) tail = current;
            Node* nodeRemove = current->next;
            current->next = nodeRemove->next;
            if (nodeRemove == tail) tail = current;  
            delete nodeRemove;
            return true;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> collect;
        Node* current = head->next;
        while (current != nullptr) {
            collect.push_back(current->val);
            current = current->next;
        }
        return collect;
    }
};
