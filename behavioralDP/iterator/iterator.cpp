#include <iostream>
#include <memory>
using namespace std;

class Iterator {
public:
    virtual int next() = 0;
    virtual bool hasNext() = 0;
    virtual ~Iterator() = default;
};

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedListIterator : public Iterator {
private:
    Node* current;

public:
    LinkedListIterator(Node* head)
        : current(head) {}

    bool hasNext() override {
        return current != nullptr;
    }

    int next() override {
        int value = current->data;
        current = current->next;
        return value;
    }
};

class LinkedList {
private:
    Node* head = nullptr;

public:
    void add(int data) {
        if (head == nullptr) {
            head = new Node(data);
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = new Node(data);
    }

    unique_ptr<Iterator> createIterator() {
        return make_unique<LinkedListIterator>(head);
    }
};

int main() {

    LinkedList list;

    list.add(24);
    list.add(32);
    list.add(54);

    unique_ptr<Iterator> iterator = list.createIterator();

    while (iterator->hasNext()) {
        cout << iterator->next() << endl;
    }
    
    return 0;
}