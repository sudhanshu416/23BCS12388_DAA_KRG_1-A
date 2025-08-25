#include <iostream>
using namespace std;

class DNode {
public:
    int value;
    DNode* prev;
    DNode* next;
    DNode(int v) : value(v), prev(nullptr), next(nullptr) {}
};

class DLinkedList {
    DNode* start;
    DNode* end;
public:
    DLinkedList() : start(nullptr), end(nullptr) {}

    void addFront(int v) {
        DNode* node = new DNode(v);
        if (start == nullptr) {
            start = end = node;
        } else {
            node->next = start;
            start->prev = node;
            start = node;
        }
    }

    void addBack(int v) {
        DNode* node = new DNode(v);
        if (end == nullptr) {
            start = end = node;
        } else {
            end->next = node;
            node->prev = end;
            end = node;
        }
    }

    void removeFront() {
        if (start == nullptr) return;
        DNode* temp = start;
        if (start == end) {
            start = end = nullptr;
        } else {
            start = start->next;
            start->prev = nullptr;
        }
        delete temp;
    }

    void removeBack() {
        if (end == nullptr) return;
        DNode* temp = end;
        if (start == end) {
            start = end = nullptr;
        } else {
            end = end->prev;
            end->next = nullptr;
        }
        delete temp;
    }

    void printList() {
        DNode* cur = start;
        while (cur) {
            cout << cur->value << " ";
            cur = cur->next;
        }
        cout << "\n";
    }
};

class CNode {
public:
    int val;
    CNode* next;
    CNode(int v) : val(v), next(nullptr) {}
};

class CLinkedList {
    CNode* rear;
public:
    CLinkedList() : rear(nullptr) {}

    void addFront(int v) {
        CNode* node = new CNode(v);
        if (rear == nullptr) {
            rear = node;
            rear->next = rear;
        } else {
            node->next = rear->next;
            rear->next = node;
        }
    }

    void addBack(int v) {
        CNode* node = new CNode(v);
        if (rear == nullptr) {
            rear = node;
            rear->next = rear;
        } else {
            node->next = rear->next;
            rear->next = node;
            rear = node;
        }
    }

    void removeFront() {
        if (rear == nullptr) return;
        CNode* head = rear->next;
        if (rear == head) {
            delete head;
            rear = nullptr;
        } else {
            rear->next = head->next;
            delete head;
        }
    }

    void removeBack() {
        if (rear == nullptr) return;
        CNode* cur = rear->next;
        if (cur == rear) {
            delete rear;
            rear = nullptr;
        } else {
            while (cur->next != rear) {
                cur = cur->next;
            }
            cur->next = rear->next;
            delete rear;
            rear = cur;
        }
    }

    void show() {
        if (rear == nullptr) {
            cout << "List is empty\n";
            return;
        }
        CNode* head = rear->next;
        CNode* cur = head;
        do {
            cout << cur->val << " ";
            cur = cur->next;
        } while (cur != head);
        cout << "\n";
    }
};

int main() {
    cout << "=== Doubly Linked List Demo ===\n";
    DLinkedList dl;
    dl.addFront(1);
    dl.addBack(2);
    dl.addFront(3);
    dl.printList();
    dl.removeFront();
    dl.removeBack();
    dl.printList();

    cout << "\n=== Circular Linked List Demo ===\n";
    CLinkedList cl;
    cl.addFront(1);
    cl.addBack(2);
    cl.addFront(3);
    cl.show();
    cl.removeFront();
    cl.removeBack();
    cl.show();

    return 0;
}
