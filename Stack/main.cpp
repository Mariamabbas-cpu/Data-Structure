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
class Stack {
public:
    node *top;
    Stack() {
        top=NULL;
    }
    bool isempty() {
        return top==NULL;
    }
    void push(int val) {
        node *newnode=new node(val);
        newnode->next=top;
        top=newnode;
    }
    int pop() {
        if (isempty()) return -1;
        int delval=top->data;
        node *tmp=top;
        top=top->next;
        delete tmp;
        return delval;
    }
    int Max() {
        if (isempty()) return -1;
        int mx=top->data;
        node *tmp=top;
        while (tmp!=NULL) {
            if (tmp->data>mx) {
                mx=tmp->data;
            }
            tmp=tmp->next;
        }
        return mx;
    }
    int Min() {
        if (isempty()) return -1;
        int mn=top->data;
        node *tmp=top;
        while (tmp!=NULL) {
            if (tmp->data<mn) {
                mn=tmp->data;
            }
            tmp=tmp->next;
        }
        return mn;
    }
    int Avg() {
        if (isempty()) return -1;
        node *tmp=top;
        int cnt=0;
        int sum=0;
        while (tmp!=NULL) {
            sum+=tmp->data;
            cnt++;
            tmp=tmp->next;
        }
        return sum/cnt;
    }
    void Copy(Stack &s,Stack &s2) {
        if (isempty()) return;
        Stack tmp;
        while (!s.isempty()) {
            tmp.push(s.pop());
        }
        while (!tmp.isempty()) {
            int x=tmp.pop();
            s.push(x);
            s2.push(x);
        }
    }
    void Reverse(Stack &s) {
        if (isempty()) return;
        Stack temp;
        while (!s.isempty()) {
            temp.push(s.pop());
        }
        s = temp;
    }
    int middle() {
        node *slow=top;
        node *fast=top->next;
        while (fast!=NULL&&fast->next!=NULL) {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow->data;
    }
    void display() {
        if (isempty()) {
            cout<<"Stack is empty"<<endl;
            return ;
        }
        node *tmp=top;
        while (tmp!=NULL) {
            cout<<tmp->data<<" ";
            tmp=tmp->next;
        }
    }
};
int main(){

    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.display();
    cout<<endl;
    s.pop();
    s.display();
    cout<<endl;
    cout<<"Maximum number is = "<<s.Max()<<endl;
    cout<<"Minimum number is = "<<s.Min()<<endl;
    cout<<"Average is = "<<s.Avg()<<endl;
    Stack s2;
    s.Copy(s,s2);
    s2.display();
    cout<<endl;
    s.Reverse(s);
    s.display();
    cout<<endl;
    cout<<"middle element is = "<<s.middle()<<endl;

    return 0;
}
