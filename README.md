# Student Management System

## 📌 Overview
This project is a student management system implemented in C. It allows efficient handling of student records, including adding, searching, displaying, and saving data.

The system combines two data structures:
- Linked List → preserves insertion order
- Binary Search Tree (BST) → enables fast search operations by student ID

This hybrid approach ensures both structured data organization and optimized performance.

---
## 📈Impact

This project demonstrates how combining multiple data structures can significantly improve both performance and usability in real-world applications. It provides fast access to student data while maintaining a clear and organized structure.

---

## 🚀 Features
- Add new student records
- Search students by ID (optimized using BST)
- Display all students (in insertion order)
- Save and load data from files
- Structured and efficient data handling

---

## 🧠 Data Structures Used

### 🔹 Linked List
- Maintains the order of insertion
- Useful for sequential display of students

### 🔹 Binary Search Tree (BST)
- Enables fast lookup operations (O(log n) on average)
- Organized by student ID for efficient searching

---

## ⚙️ How It Works
- Each student is stored in both:
  - A linked list node (for ordering)
  - A BST node (for searching)
- When a student is added:
  - It is appended to the linked list
  - It is inserted into the BST
- Search operations use the BST for speed
- Display operations traverse the linked list

---

## 🛠️ Technologies
- Language: C
- Concepts:
  - Dynamic memory allocation
  - Pointers
  - Data structures (Linked List, BST)
  - File handling

---
## 📂 Project Structure
```
.
├── declarations.h
├── definitions.c
├── main.c     # Entry point
└── Students.txt
```
---
## ▶️ Compilation & Execution

```bash
gcc -c main.c
gcc -c definitions.c
gcc main.o definitions.o -o student_manager
./student_manager
```
---
## 💡 Future Improvements
- Add a graphical user interface (GUI)
- Implement balancing (AVL or Red-Black Tree)
- Add advanced filtering and sorting
- Export data to CSV format
- Integrate with a database

---
## 👤 Author
- Oolahiane karim
