#include<bits/stdc++.h>
using namespace std;
class node {
public:
    int data;
    node *left,*right;
    node(int val) {
        data=val;
        right=left=NULL;
    }
};
class bst {
public:
    node *root;
    bst() {
        root=NULL;
    }
    node *insert(node *r,int val) {
        if (!r) {
            node *newnode =new node(val);
            r=newnode;
        }
        else if (val < r->data) {
            r->left=insert(r->left,val);
        }
        else if (val > r->data) {
            r->right=insert(r->right,val);
        }
        return r;
    }
    void insert(int val) {
        root=insert(root,val);
    }
    bool search(node *r,int val) {
        if (!r) return false;
        if (r->data==val) return true;
        if (r->data > val) return search(r->left,val);
        else return search(r->right,val);
    }
    bool search(int val) {
        return search(root,val);
    }
    node *maxx(node *r) {
        if (!r) return NULL;
        while (r->right!=NULL) r=r->right;
        return r;
    }
    node *min(node *r) {
        if (!r) return NULL;
        while (r->left!=NULL) r=r->left;
        return r;
    }
    void preorder(node *r) {
        if (!r) return;
        cout<<r->data;
        preorder(r->left);
        preorder(r->right);
    }
    void preorder() {
        preorder(root);
    }
    void inorder(node *r) {
        if (!r) return;
        inorder(r->left);
        cout<<r->data<<" ";
        inorder(r->right);
    }
    void inorder() {
        inorder(root);
    }
    void postorder(node *r) {
        if (!r) return;
        postorder(r->left);
        postorder(r->right);
        cout<<r->data<<" ";
    }
    void postorder() {
        postorder(root);
    }
    int countnodes(node *r) {
        if (!r) return 0;
        return 1+countnodes(r->left)+countnodes(r->right);
    }
    int countn() {
        return countnodes(root);
    }
    int countleaves(node *r) {
        if (!r) return 0;
        if (!r->left && !r->right) return 1;
        return countleaves(r->left)+countleaves(r->right);
    }
    int countl() {
        return countleaves(root);
    }
    int heightoftree(node* r) {
        if (!r) return -1;
        return 1 + max(heightoftree(r->left), heightoftree(r->right));
    }

    int height() {
        return heightoftree(root);
    }

    int heightofnode(node *r,int val) {
        if (!r) return -1;
        if (val==r->data) return heightoftree(r);
        if (val<r->data) return heightofnode(r->left,val);
        else return heightofnode(r->right,val);
    }
    int heightofnode(int d) {
        if (!root) return -1;
        return heightofnode(root,d);
    }
    int depthofnode(node *r,int val,int lvl=0) {
        if (!r) return -1;
        if (r->data==val) return lvl;
        if (r->data>val) return depthofnode(r->left,val,lvl+1);
        else return depthofnode(r->right,val,lvl+1);
    }
    int depthofnode(int val) {
        return depthofnode(root,val);
    }
    node* Delete(node* r, int val) {
        if (!r) return NULL;
        if (val < r->data) {
            r->left = Delete(r->left, val);
            return r;
        }
        else if (val > r->data) {
            r->right = Delete(r->right, val);
            return r;
        }
        // Case 1: no children
        if (!r->left && !r->right) {
            delete r;
            return NULL;
        }
        // Case 2: one child (right)
        if (!r->left) {
            node* temp = r->right;
            delete r;
            return temp;
        }
        // Case 2: one child (left)
        if (!r->right) {
            node* temp = r->left;
            delete r;
            return temp;
        }

        // Case 3: two children
        node* maxLeft = maxx(r->left);
        r->data = maxLeft->data;
        r->left = Delete(r->left, maxLeft->data);

        return r;
    }

    void Delete(int key) {
        root = Delete(root, key);
    }

    int sum(node* r) {
        if (!r) return 0;
        return r->data + sum(r->left) + sum(r->right);
    }
    int countInternal(node* r) {
        if (!r || (!r->left && !r->right)) return 0;
        return 1 + countInternal(r->left) + countInternal(r->right);
    }
    void printLeaves(node* r) {
        if (!r) return;
        if (!r->left && !r->right) {
            cout << r->data << " ";
            return;
        }
        printLeaves(r->left);
        printLeaves(r->right);
    }
    void mirror(node* r) {
        if (!r) return;
        swap(r->left, r->right);
        mirror(r->left);
        mirror(r->right);
    }
    void printLevel(node* r, int k) {
        if (!r) return;
        if (k == 0) {
            cout << r->data << " ";
            return;
        }
        printLevel(r->left, k - 1);
        printLevel(r->right, k - 1);
    }
    void printSiblings(node* r, int val) {
        if (!r) return;

        if (r->left && r->right) {
            if (r->left->data == val)
                cout << r->right->data;
            else if (r->right->data == val)
                cout << r->left->data;
        }
        if (val < r->data)
            printSiblings(r->left, val);
        else
            printSiblings(r->right, val);
    }
    int countSiblings(node* r, int val) {
        if (!r) return 0;

        if (r->left && r->right) {
            if (r->left->data == val ||
                r->right->data == val)
                return 1;
        }
        if (val < r->data)
            return countSiblings(r->left, val);
        else
            return countSiblings(r->right, val);
    }

};
int main() {
        bst t;

        // Insert elements
        t.insert(50);
        t.insert(30);
        t.insert(70);
        t.insert(20);
        t.insert(40);
        t.insert(60);
        t.insert(80);

        // Traversals
        cout << "Inorder: ";
        t.inorder();              // 20 30 40 50 60 70 80
        cout << endl;

        cout << "Preorder: ";
        t.preorder();
        cout << endl;

        cout << "Postorder: ";
        t.postorder();
        cout << endl;

        // Search
        cout << "Search 40: " << t.search(40) << endl;
        cout << "Search 100: " << t.search(100) << endl;

        // Min & Max
        cout << "Min: " << t.min(t.root)->data << endl;
        cout << "Max: " << t.maxx(t.root)->data << endl;

        // Count
        cout << "Total nodes: " << t.countn() << endl;
        cout << "Leaf nodes: " << t.countl() << endl;
        cout << "Internal nodes: " << t.countInternal(t.root) << endl;

        // Height & Depth
        cout << "Height of tree: " << t.height() << endl;
        cout << "Height of node 30: " << t.heightofnode(30) << endl;
        cout << "Depth of node 60: " << t.depthofnode(60) << endl;

        // Sum
        cout << "Sum of all nodes: " << t.sum(t.root) << endl;

        // Print leaves
        cout << "Leaves: ";
        t.printLeaves(t.root);
        cout << endl;

        // Print nodes at level k
        cout << "Nodes at level 2: ";
        t.printLevel(t.root, 2);
        cout << endl;

        // Siblings
        cout << "Sibling of 30: ";
        t.printSiblings(t.root, 30);
        cout << endl;

        cout << "Number of siblings of 30: "
             << t.countSiblings(t.root, 30) << endl;

        // Delete
        cout << "Delete 50 (root)" << endl;
        t.Delete(50);

        cout << "Inorder after delete: ";
        t.inorder();
        cout << endl;

        // Mirror
        cout << "Mirror tree inorder: ";
        t.mirror(t.root);
        t.inorder();
        cout << endl;

    return 0;
}
