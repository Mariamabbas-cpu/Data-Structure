#include<iostream>
using namespace std;
 
class node {
public:
    int data;
    node *next;
    node(int val) {
        data=val;
        next=NULL;
    }
};

class Queue {
public:
    node *front;
    node *rear;

    Queue() {
        front=rear=NULL;
    }

    bool isempty() {
        return front==NULL&&rear==NULL;
    }

    void enq(int val) {
        node *newnode=new node(val);
        if (isempty()) {
            front=rear=newnode;
            return;
        }
        rear->next=newnode;
        rear=newnode;
    }

    int deq() {
        if (isempty()) return -1;
        int delval=front->data;
        node *tmp=front;
        if (front==rear) {
            delete front;
            front=rear=NULL;
        }
        else {
            front=front->next;
            delete tmp;
        }
        return delval;
    }

    int Max() {
        if (isempty()) return -1;
        int mx=front->data;
        node *tmp=front;
        while (tmp!=NULL) {
            if (tmp->data>mx) mx=tmp->data;
            tmp=tmp->next;
        }
        return mx;
    }

    int Min() {
        if (isempty()) return -1;
        int mn=front->data;
        node *tmp=front;
        while (tmp!=NULL) {
            if (tmp->data<mn) mn=tmp->data;
            tmp=tmp->next;
        }
        return mn;
    }

    int Middle() {
        if (isempty()) return -1;
        node *slow=front;
        node *fast=front;
        while (fast!=NULL && fast->next!=NULL) {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow->data;
    }

    int size() {
        int cnt=0;
        node *tmp=front;
        while (tmp!=NULL) {
            cnt++;
            tmp=tmp->next;
        }
        return cnt;
    }

    bool search(int val) {
        node *tmp=front;
        while (tmp!=NULL) {
            if (tmp->data==val) return true;
            tmp=tmp->next;
        }
        return false;
    }

    void clear() {
        while (!isempty()) {
            deq();
        }
    }

    void Reverse() {
        if (isempty()) return;
        node *cur = front;
        node *prev = NULL;
        node *next = NULL;
        rear = front;
        while (cur != NULL) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        front = prev;
    }

    void display() {
        node *tmp=front;
        while (tmp!=NULL) {
            cout<<tmp->data<<" ";
            tmp=tmp->next;
        }
        cout<<endl;
    }
};

int main(){
    Queue q;

    q.enq(10);
    q.enq(3);
    q.enq(7);
    q.enq(1);
    q.enq(8);

    q.display();

    cout<<"Size: "<<q.size()<<endl;
    cout<<"Max: "<<q.Max()<<endl;
    cout<<"Min: "<<q.Min()<<endl;
    cout<<"Middle: "<<q.Middle()<<endl;

    cout<<"Search 7: "<<q.search(7)<<endl;
    cout<<"Search 100: "<<q.search(100)<<endl;

    q.Reverse();
    q.display();

    q.clear();
    q.display();

    return 0;
}
