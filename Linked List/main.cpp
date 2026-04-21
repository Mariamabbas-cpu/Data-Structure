#include<iostream>
using namespace std;

class node {
public:
    int data;
    node *next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

class lk {
public:
    node *head;

    lk() {
        head = NULL;
    }

    bool isempty() {
        return head == NULL;
    }

    void insertatbeg(int val) {
        node *newnode = new node(val);
        newnode->next = head;
        head = newnode;
    }

    void insertatend(int val) {
        if (isempty()) {
            insertatbeg(val);
            return;
        }
        node *tmp = head;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new node(val);
    }

    void display() {
        if (isempty()) {
            cout << "list is empty" << endl;
            return;
        }

        node *tmp = head;
        while (tmp != NULL) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    int size() {
        int cnt = 0;
        node *tmp = head;
        while (tmp != NULL) {
            cnt++;
            tmp = tmp->next;
        }
        return cnt;
    }

    void clear() {
        while (head != NULL) {
            node *tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    bool isSorted() {
        if (isempty() || head->next == NULL)
            return true;

        node *tmp = head;
        while (tmp->next != NULL) {
            if (tmp->data > tmp->next->data)
                return false;
            tmp = tmp->next;
        }
        return true;
    }

    void updateByIndex(int pos, int val) {
        if (pos < 0 || isempty()) {
            cout << "invalid index" << endl;
            return;
        }

        node *tmp = head;
        for (int i = 0; i < pos && tmp != NULL; i++) {
            tmp = tmp->next;
        }

        if (tmp != NULL)
            tmp->data = val;
        else
            cout << "index out of range" << endl;
    }

    bool updateByValue(int oldVal, int newVal) {
        node *tmp = head;

        while (tmp != NULL) {
            if (tmp->data == oldVal) {
                tmp->data = newVal;
                return true;
            }
            tmp = tmp->next;
        }
        return false;
    }

    void reverse() {
        node *cur = head;
        node *prev = NULL;
        node *next = NULL;

        while (cur != NULL) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        head = prev;
    }

    int middle_node() {
        if (isempty())
            return -1;

        node *slow = head;
        node *fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }
};

int main() {
    lk l;

    l.insertatend(10);
    l.insertatend(20);
    l.insertatend(20);
    l.insertatend(30);
    l.insertatend(40);
    l.insertatend(40);

    l.display();

    cout << "Size: " << l.size() << endl;
    cout << "Middle: " << l.middle_node() << endl;

    cout << "Is Sorted: " << l.isSorted() << endl;

    l.updateByIndex(2, 99);
    l.display();

    if (!l.updateByValue(40, 80))
        cout << "value not found" << endl;

    l.display();

    l.reverse();
    l.display();

    l.clear();
    l.display();

    return 0;
}
