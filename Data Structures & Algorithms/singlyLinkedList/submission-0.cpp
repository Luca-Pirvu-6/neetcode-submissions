#include <vector>

class LinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int v = 0, Node* n = nullptr) : val(v), next(n) {}
    };

    Node* first;
    Node* last;
    int size;

public:
    LinkedList() : first(nullptr), last(nullptr), size(0) {}

    ~LinkedList() {
        Node* curr = first;
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }

        Node* curr = first;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->val;
    }

    void insertHead(int val) {
        Node* nou = new Node(val, first);
        first = nou;
        if (size == 0) {
            last = nou;
        }
        size++;
    }

    void insertTail(int val) {
        Node* nou = new Node(val, nullptr);
        if (size == 0) {
            first = last = nou;
        } else {
            last->next = nou;
            last = nou;
        }
        size++;
    }

    bool remove(int index) {
        if (index < 0 || index >= size) {
            return false;
        }

        if (index == 0) {
            Node* del = first;
            first = first->next;
            delete del;
            size--;
            if (size == 0) {
                last = nullptr;
            }
            return true;
        }

        Node* p = first;
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        }

        Node* del = p->next;
        p->next = del->next;

        if (index == size - 1) {
            last = p;
        }

        delete del;
        size--;
        return true;
    }

    std::vector<int> getValues() {
        std::vector<int> res;
        Node* p = first;
        while (p != nullptr) {
            res.push_back(p->val);
            p = p->next;
        }
        return res;
    }
};