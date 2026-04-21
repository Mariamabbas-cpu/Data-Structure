# Data Structures in C++ 

This repository contains robust implementations of fundamental **Data Structures** in C++. Designed for learning and practice, each structure is built using **Object-Oriented Programming (OOP)** principles.

---

## 📌 Included Data Structures

### 1. Singly Linked List
A simple yet powerful implementation of a Singly Linked List.
* **Features:** `Insert` (Head, Tail, Position), `Delete`, `Search`, `Display`, and `Size`.

### 2. Queue (FIFO)
Implemented using two different approaches:
* **Dynamic Array** & **Linked List**.
* **Operations:** `Enqueue`, `Dequeue`, `Peek`, `Rear`, `Search`, and `Clear`.

### 3. Stack (LIFO)
Implemented using three flexible approaches:
* **Static Stack**, **Dynamic Stack**, and **Linked Stack**.
* **Operations:** `Push`, `Pop`, `Peek`, `Copy`, and `Size`.

### 4. Binary Search Tree (BST)
A full implementation covering advanced tree operations.
* **Features:** `Insert`, `Delete` (all cases), `Search`, and `Min/Max`.
* **Traversals:** Inorder, Preorder, Postorder.
* **Stats:** Total nodes, Leaf nodes, Internal nodes, Height, and Depth.

---

## ⏱️ Time Complexity Analysis

### Linear Structures
| Operation | Linked List | Queue | Stack |
| :--- | :---: | :---: | :---: |
| **Insertion** | $O(1)$ (Head) / $O(n)$ (Tail) | $O(1)$ | $O(1)$ |
| **Deletion** | $O(n)$ | $O(1)$ | $O(1)$ |
| **Search** | $O(n)$ | $O(n)$ | $O(n)$ |
| **Peek/Front** | - | $O(1)$ | $O(1)$ |

### Binary Search Tree (BST)
| Operation | Average Case | Worst Case |
| :--- | :---: | :---: |
| **Insert** | $O(\log n)$ | $O(n)$ |
| **Search** | $O(\log n)$ | $O(n)$ |
| **Delete** | $O(\log n)$ | $O(n)$ |
| **Traversal** | $O(n)$ | $O(n)$ |

> **Note:** All BST complexities assume a balanced tree. In the worst case (skewed tree), it behaves like a linked list.

---

## 🛠️ Technologies Used
* **Language:** C++
* **Concepts:** OOP (Classes, Templates), Pointers, Memory Management.
* **Tools:** CLion / Any C++ IDE.

---

##  How to Use
1. Clone the repo.
2. Open the project in your IDE.
3. Compile the specific `.cpp` file you want to test.
