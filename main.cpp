#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct user
{
    int id;
    string name;
    vector<int> borrowed_books;
};

struct book
{
    vector<int> Owners; // store user IDs
    int id;
    string name;
    int quantity;
};

struct library
{
    book book_data[100];
    user users_data[100];
    int current_book_id = 0;
    int current_user_id = 0;

    void menu()
    {
        cout << "==============================" << endl;
        cout << "        MAIN MENU" << endl;
        cout << "==============================" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Search Books By Prefix" << endl;
        cout << "3. Print Who Borrowed Book By Name" << endl;
        cout << "4. Print Library By ID" << endl;
        cout << "5. Print Library By Name" << endl;
        cout << "6. Add User" << endl;
        cout << "7. User Borrow Book" << endl;
        cout << "8. User Return Book" << endl;
        cout << "9. Print Users" << endl;
        cout << "10. Exit" << endl;
        cout << "==============================" << endl;
        cout << "Enter your choice (1-10): ";

        int choice;
        cin >> choice;
        cout << endl << endl;

        switch (choice)
        {
        case 1: add_book(); break;
        case 2: search_for_book(); break;
        case 3: print_borrowers_of_book(); break;
        case 4: list_books(1); break;
        case 5: list_books(0); break;
        case 6: add_user(); break;
        case 7: user_borrow_book(); break;
        case 8: user_return_book(); break;
        case 9: print_users(); break;
        case 10: exit(0);
        default: cout << "Invalid choice!\n"; break;
        }
        cout << endl << endl;
    }

    // ------------------- Book Management -------------------
    void add_book()
    {
        book new_book;
        cout << "Enter book name: ";
        cin >> new_book.name;
        cout << "Enter quantity: ";
        cin >> new_book.quantity;
        new_book.id = current_book_id;
        book_data[current_book_id++] = new_book;
        cout << "✅ Book added successfully with ID: " << new_book.id << endl;
    }

    void search_for_book()
    {
        cout << "Enter book name prefix: ";
        string input;
        cin >> input;
        bool found = false;
        for (int i = 0; i < current_book_id; i++)
        {
            if (book_data[i].name.rfind(input, 0) == 0)
            {
                found = true;
                cout << "📘 " << book_data[i].name << " (ID: " << book_data[i].id << ")\n";
            }
        }
        if (!found)
            cout << "❌ No book found with that prefix.\n";
    }

    void list_books(int sort_by_id)
    {
        vector<book> books(book_data, book_data + current_book_id);
        if (sort_by_id)
            sort(books.begin(), books.end(), [](auto &a, auto &b) { return a.id < b.id; });
        else
            sort(books.begin(), books.end(), [](auto &a, auto &b) { return a.name < b.name; });

        cout << "📚 Library Books:\n";
        for (auto &b : books)
            cout << "ID: " << b.id << ", Name: " << b.name
                 << ", Quantity: " << b.quantity
                 << ", Borrowed by: " << b.Owners.size() << " users\n";
    }

    // ------------------- User Management -------------------
    void add_user()
    {
        user new_user;
        cout << "Enter user name: ";
        cin >> new_user.name;
        new_user.id = current_user_id;
        users_data[current_user_id++] = new_user;
        cout << "✅ User added successfully with ID: " << new_user.id << endl;
    }

    void print_users()
    {
        cout << "👥 Users List:\n";
        for (int i = 0; i < current_user_id; i++)
        {
            cout << "ID: " << users_data[i].id << ", Name: " << users_data[i].name;
            if (!users_data[i].borrowed_books.empty())
            {
                cout << ", Borrowed Books: ";
                for (int bid : users_data[i].borrowed_books)
                    cout << book_data[bid].name << " ";
            }
            cout << endl;
        }
    }

    // ------------------- Borrow / Return -------------------
    void user_borrow_book()
    {
        int user_id, book_id;
        cout << "Enter user ID: ";
        cin >> user_id;
        cout << "Enter book ID: ";
        cin >> book_id;

        if (user_id >= current_user_id || book_id >= current_book_id)
        {
            cout << "❌ Invalid user or book ID.\n";
            return;
        }
        book &b = book_data[book_id];
        user &u = users_data[user_id];

        if (b.quantity == 0)
        {
            cout << "❌ No copies available.\n";
            return;
        }

        b.quantity--;
        b.Owners.push_back(u.id);
        u.borrowed_books.push_back(b.id);
        cout << "✅ " << u.name << " borrowed " << b.name << endl;
    }

    void user_return_book()
    {
        int user_id, book_id;
        cout << "Enter user ID: ";
        cin >> user_id;
        cout << "Enter book ID: ";
        cin >> book_id;

        if (user_id >= current_user_id || book_id >= current_book_id)
        {
            cout << "❌ Invalid user or book ID.\n";
            return;
        }

        book &b = book_data[book_id];
        user &u = users_data[user_id];

        auto it_user = find(u.borrowed_books.begin(), u.borrowed_books.end(), book_id);
        if (it_user == u.borrowed_books.end())
        {
            cout << "❌ This user didn’t borrow this book.\n";
            return;
        }

        u.borrowed_books.erase(it_user);
        auto it_owner = find(b.Owners.begin(), b.Owners.end(), user_id);
        if (it_owner != b.Owners.end())
            b.Owners.erase(it_owner);

        b.quantity++;
        cout << "✅ " << u.name << " returned " << b.name << endl;
    }

    // ------------------- Reports -------------------
    void print_borrowers_of_book()
    {
        cout << "Enter book name: ";
        string book_name;
        cin >> book_name;
        bool found = false;
        for (int i = 0; i < current_book_id; i++)
        {
            if (book_data[i].name == book_name)
            {
                found = true;
                cout << "📘 " << book_name << " borrowed by:\n";
                for (int uid : book_data[i].Owners)
                    cout << " - " << users_data[uid].name << endl;
            }
        }
        if (!found)
            cout << "❌ Book not found.\n";
    }
};

int main()
{
    library lib;
    while (true)
        lib.menu();
    return 0;
}
