A simple C++ console-based Library Management System, built and tested in Code::Blocks IDE.
This program allows managing books and users using a clean, menu-driven interface.

------------------------------------------------------------
🚀 Features
------------------------------------------------------------
- Add new books with quantities
- Search books by name prefix
- List all books (by ID or Name)
- Add users to the system
- Borrow and return books
- Show who borrowed each book
- Display all users and their borrowed books

------------------------------------------------------------
🧠 Concepts Demonstrated
------------------------------------------------------------
- Use of struct and vector
- Function modularization and data encapsulation
- Sorting with lambda expressions
- String handling and prefix matching
- Menu-driven console interface
- UTF-8 text encoding for multilingual support

------------------------------------------------------------
🧩 Project Structure
------------------------------------------------------------
LibraryManagementSystem_CodeBlocks/
 ├─ main.cpp
 ├─ README.txt
 └─ LibraryManagementSystem.cbp

------------------------------------------------------------
⚙️ Setup and Run (Code::Blocks)
------------------------------------------------------------
1. Open Code::Blocks
2. Go to File → New → Project → Console Application → C++
3. Name the project: LibraryManagementSystem
4. Replace the generated main.cpp with the provided one
5. Press Build and Run (F9) to start

------------------------------------------------------------
🧾 Example Run
------------------------------------------------------------
==============================
        MAIN MENU
==============================
1. Add Book
2. Search Books By Prefix
3. Print Who Borrowed Book By Name
4. Print Library By ID
5. Print Library By Name
6. Add User
7. User Borrow Book
8. User Return Book
9. Print Users
10. Exit
==============================
Enter your choice (1-10): 1
Enter book name: CppGuide
Enter quantity: 4
Book added successfully with ID: 0

------------------------------------------------------------
💡 Notes
------------------------------------------------------------
- Make sure your console encoding in Code::Blocks is set to UTF-8 to display text properly.
- You can extend this project easily by adding features like:
  * Book deletion
  * User search
  * Data saving to files (text or binary)

------------------------------------------------------------
🧑‍💻 Author
------------------------------------------------------------
Ahmed Gamal
Embedded Engineer at SwiftAct
Cairo, Egypt

------------------------------------------------------------
🪪 License
------------------------------------------------------------
This project is open-source under the MIT License.
"""
